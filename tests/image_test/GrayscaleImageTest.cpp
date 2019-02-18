//
// Created by Rabia on 15/02/2019.
//

#include "GrayscaleImageTest.h"

#include <iostream>
#include <vector>

#include "opencv2/core/core.hpp"
#include "../../src/image/GrayscaleImage.h"
#include "../../src/image/pixel/Pixel.h"



void GrayscaleImageTest::testFindBoundaryPixelsFourConnectivity()
{
    cv::Mat image =
            (cv::Mat_<float>(3, 3) << 0, 0, 0,
                    0, 5, -1,
                    0, 0, 0);

    GrayscaleImage grayscaleImage(std::make_shared<cv::Mat>(image),
                                  PixelConnectivity::FOUR,
                                  -1);

    std::vector<std::shared_ptr<Pixel>>  boundarySet =
            grayscaleImage.findBoundaryPixels();


    assert(boundarySet.at(0)->getRow() == 0 && boundarySet.at(0)->getColumn() == 2);
    assert(boundarySet.at(1)->getRow() == 1 && boundarySet.at(1)->getColumn() == 1);
    assert(boundarySet.at(2)->getRow() == 2 && boundarySet.at(2)->getColumn() == 2);

}


void GrayscaleImageTest::testFindBoundaryPixelsEightConnectivity()
{
    cv::Mat image =
            (cv::Mat_<float>(3, 3) << 0, 0, 0,
                    0, 5, -0,
                    0, 0, -1);

    GrayscaleImage grayscaleImage(std::make_shared<cv::Mat>(image),
                                  PixelConnectivity::EIGHT,
                                  -1);

    std::vector<std::shared_ptr<Pixel>>  boundarySet =
            grayscaleImage.findBoundaryPixels();

    assert(boundarySet.at(0)->getRow() == 1 && boundarySet.at(0)->getColumn() == 1);
    assert(boundarySet.at(1)->getRow() == 1 && boundarySet.at(1)->getColumn() == 2);
    assert(boundarySet.at(2)->getRow() == 2 && boundarySet.at(2)->getColumn() == 1);

}


void GrayscaleImageTest::testFindHolePixelsFourConnectivity()
{
    cv::Mat image =
            (cv::Mat_<float>(3, 3) << 0, 0, 0,
                    0, 5, -0,
                    0, 0, -1);

    GrayscaleImage grayscaleImage(std::make_shared<cv::Mat>(image),
                                  PixelConnectivity::FOUR,
                                  -1);

    std::vector<std::shared_ptr<Pixel>>  holeSet =
            grayscaleImage.findHolePixels();

    assert(holeSet.at(0)->getRow() == 2 && holeSet.at(0)->getColumn() == 2);
}


void GrayscaleImageTest::testFindHolePixelsEightConnectivity()
{
    cv::Mat image =
            (cv::Mat_<float>(3, 3) << 0, 0, 0,
                    0, 5, -0,
                    0, -1, 0);

    GrayscaleImage grayscaleImage(std::make_shared<cv::Mat>(image),
                                  PixelConnectivity::EIGHT,
                                  -1);

    std::vector<std::shared_ptr<Pixel>>  holeSet =
            grayscaleImage.findHolePixels();

    assert(holeSet.at(0)->getRow() == 2 && holeSet.at(0)->getColumn() == 1);
}
