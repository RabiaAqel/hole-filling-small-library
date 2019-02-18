//
// Created by Rabia on 16/02/2019.
//

#include "CmdUtility.h"

#include <iostream>
#include <stdexcept>

#include "opencv2/core/core.hpp"
#include "src/weightfunction/EuclideanDistance.h"
#include "src/image/GrayscaleImage.h"
#include "src/filler/HoleFiller.h"
#include "src/utils/ImageUtil.h"


constexpr char CmdUtility::USAGE[];
constexpr char CmdUtility::PROMPT[];
constexpr char CmdUtility::EXIT[];
constexpr char CmdUtility::HELP[];
constexpr char CmdUtility::USAGE_REGEX[];
constexpr char CmdUtility::TARGET_PATH[];
constexpr char CmdUtility::DEFAULT_FILE_NAME[];


CmdUtility::CmdUtility()
{
    rgx_ = std::regex(USAGE_REGEX);
}


void CmdUtility::run()
{
    std::string input;

    do
    {

        input = prompt();

        if ( input.find(EXIT) != -1 )
            break;

        else if ( input.find(HELP) != -1 )
            renderHelp();

        else if ( checkInput(input))
        {
            try
            {
                executeCommand();
            }
            catch(const std::runtime_error& error)
            {
                renderError(error.what());
            }

        }
        else
        {
            renderError(input);
            renderHelp();
        }

    } while ( true );
}


std::string CmdUtility::prompt()
{
    std::string input;

    for ( ; std::cout << PROMPT && std::getline(std::cin, input) && input.empty(); );

    return input;
}


void CmdUtility::render(const std::string &out)
{
    std::cout << out << std::endl;
}


void CmdUtility::renderError(const std::string &out)
{
    std::cerr << "HoleFilling error: " << out << std::endl;
}


bool CmdUtility::checkInput(const std::string &input)
{
    return std::regex_search(input, matches_, rgx_);
}


void CmdUtility::executeCommand()
{
    std::string imagePath = matches_[1].str();
    std::string maskPath = matches_[2].str();

    float z = std::stof(matches_[3].str());
    float epsilon = std::stof(matches_[4].str());
    int connectivity = std::stoi(matches_[5].str());

    PixelConnectivity::Connectivity pixelConnectivity;

    if (connectivity == 4)
        pixelConnectivity = PixelConnectivity::FOUR;
    else if(connectivity == 8)
        pixelConnectivity = PixelConnectivity::EIGHT;

    Mat floatImage = ImageUtil::toFloatImageWithHole(imagePath, maskPath);


    shared_ptr<HoleFillingImage> hfImage =
            std::make_shared<GrayscaleImage>(make_shared<Mat>(floatImage),
                                             pixelConnectivity,
                                             -1);

    shared_ptr<WeightFunction> weightFuncton = make_shared<EuclideanDistance>(epsilon, z);

    unique_ptr<HoleFiller> filler = make_unique<HoleFiller>(hfImage, weightFuncton);

    filler->fill();

    floatImage = ImageUtil::normalizeToGrayscale(floatImage);

    ImageUtil::saveImageTo(floatImage, TARGET_PATH, DEFAULT_FILE_NAME);
}


void CmdUtility::renderHelp()
{
    std::cout << "\t" << USAGE << "\n" << std::endl;
}

