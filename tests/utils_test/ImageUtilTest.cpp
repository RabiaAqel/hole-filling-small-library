//
// Created by Rabia on 15/02/2019.
//

#include "ImageUtilTest.h"

#include <iostream>

#include "../../src/utils/ImageUtil.h"
#include "../../src/image/pixel/Pixel.h"

#include "opencv2/core/core.hpp"


void ImageUtilTest::testToGrayscaleWithHole()
{

    std::string image = "/Users/rabiaabuaqel/CLionProjects/Projects/HoleFilling/sample_images/test_image.jpg";
    std::string mask = "/Users/rabiaabuaqel/CLionProjects/Projects/HoleFilling/sample_images/test_mask.jpg";

    cv::Mat res = ImageUtil::toFloatImageWithHole(image, mask);

    // expected curved out hole pixels
    std::vector<Pixel> holeSet;

    holeSet.emplace_back(1, 1, res.at<float>(1, 1));
    holeSet.emplace_back(1, 2, res.at<float>(1, 2));
    holeSet.emplace_back(1, 3, res.at<float>(1, 3));
    holeSet.emplace_back(2, 1, res.at<float>(2, 1));
    holeSet.emplace_back(2, 2, res.at<float>(2, 2));
    holeSet.emplace_back(2, 3, res.at<float>(2, 3));
    holeSet.emplace_back(3, 1, res.at<float>(3, 1));
    holeSet.emplace_back(3, 2, res.at<float>(3, 2));
    holeSet.emplace_back(3, 3, res.at<float>(3, 3));
    holeSet.emplace_back(4, 1, res.at<float>(4, 1));
    holeSet.emplace_back(4, 2, res.at<float>(4, 2));
    holeSet.emplace_back(4, 3, res.at<float>(4, 3));
    holeSet.emplace_back(5, 1, res.at<float>(5, 1));


    for ( auto const &pixel: holeSet )
        assert(pixel.getIntensity() == -1);
}


void ImageUtilTest::testSaveToImage()
{
    std::string image = "/Users/rabiaabuaqel/CLionProjects/Projects/HoleFilling/sample_images/test_image.jpg";
    std::string mask = "/Users/rabiaabuaqel/CLionProjects/Projects/HoleFilling/sample_images/test_mask.jpg";

    cv::Mat res = ImageUtil::toFloatImageWithHole(image, mask);

    ImageUtil::saveImageTo(res, "/Users/rabiaabuaqel/Desktop", "hole_filled.jpg");

    Mat openImage = cv::imread("/Users/rabiaabuaqel/Desktop/hole_filled.jpg", cv::IMREAD_GRAYSCALE);

    assert(!openImage.empty());
}


void ImageUtilTest::normalizeToGrayScale()
{

}
