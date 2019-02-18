//
// Created by Rabia on 15/02/2019.
//

#include "FillerTest.h"

#include <iostream>

#include "opencv2/core/core.hpp"

#include "../../src/filler/HoleFiller.h"
#include "../../src/filler/DefaultFillingStrategy.h"
#include "../../src/image/GrayscaleImage.h"
#include "../../src/image/HoleFillingImage.h"
#include "../../src/image/pixel/PixelConnectivity.h"
#include "../../src/weightfunction/EuclideanDistance.h"
#include "../../src/image/HoleFillingImage.h"
#include "../../src/utils/ImageUtil.h"



void FillerTest::testFill()
{
    cv::Mat image;
    image = (cv::Mat_<float>(3, 3) << 0.f, 0.f, 0.f,
                        0.1f, 0.4f, 0.8f,
                        0.8f, 0.2f, -1.f);

    shared_ptr <HoleFillingImage> hfImage =
            std::make_shared<GrayscaleImage>(make_shared<Mat>(image),
                                             PixelConnectivity::FOUR, -1);

    shared_ptr <WeightFunction> weightFuncton = make_shared<EuclideanDistance>(0.001f, 2.f);

    unique_ptr <HoleFiller> filler = make_unique<HoleFiller>(hfImage, weightFuncton);

    filler->fill();

    ImageUtil::saveImageTo(ImageUtil::normalizeToGrayscale(image), "../sample_images", "test_filler.jpg");

    cv::Mat openResult = cv::imread("../sample_images/test_filler.jpg", cv::IMREAD_GRAYSCALE);

    cv::Mat floatConverted;
    openResult.convertTo(floatConverted, CV_32F, 1.0 / 255, 0);

    float fillIntensity = floatConverted.at<float>(2, 2);

    assert(fillIntensity < 0.7 && fillIntensity > 0.6);
}
