//
// Created by Rabia on 17/02/2019.
//

#include "PixelConnectivityTest.h"

#include "opencv2/core/core.hpp"

#include "../../src/image/pixel/PixelConnectivity.h"


void PixelConnectivityTest::testIsFourConnected()
{
    cv::Mat image;
    image = (cv::Mat_<float>(3, 3) << 0, 0, 0,
                        0, 5, -1,
                        0, 0, 0);


    PixelConnectivity pixelConnectivity(PixelConnectivity::FOUR,
                                        -1,
                                        std::make_shared<cv::Mat>(image));


    assert(pixelConnectivity.isConnected(1, 1));
}


void PixelConnectivityTest::testIsFourNotConnected()
{
    cv::Mat image;
    image = (cv::Mat_<float>(3, 3) << 0, 0, 0,
                        0, 5, -1,
                        0, 0, 0);


    PixelConnectivity pixelConnectivity(PixelConnectivity::FOUR,
                                        -1,
                                        std::make_shared<cv::Mat>(image));


    assert(!pixelConnectivity.isConnected(0, 0));
}


void PixelConnectivityTest::testIsEightConnected()
{
    cv::Mat image;
    image = (cv::Mat_<float>(3, 3) << 0, 0, 0,
                        0, 5, 0,
                        0, 0, -1);


    PixelConnectivity pixelConnectivity(PixelConnectivity::EIGHT,
                                        -1,
                                        std::make_shared<cv::Mat>(image));


    assert(pixelConnectivity.isConnected(1, 1));
}


void PixelConnectivityTest::testIsEightNotConnected()
{
    cv::Mat image;
    image = (cv::Mat_<float>(3, 3) << 0, 0, 0,
                        0, 5, -1,
                        0, 0, 0);


    PixelConnectivity pixelConnectivity(PixelConnectivity::EIGHT,
                                        -1,
                                        std::make_shared<cv::Mat>(image));


    assert(!pixelConnectivity.isConnected(0, 0));
}