//
// Created by Rabia on 17/02/2019.
//

#include "RunTests.h"


#include "filler_test/FillerTest.h"
#include "image_test/GrayscaleImageTest.h"
#include "image_test/PixelConnectivityTest.h"
#include "utils_test/ImageUtilTest.h"
#include "weightfunction_test/EucledianDistanceTest.h"


void RunTests::runFillerTests()
{
    FillerTest fillerTest;

    fillerTest.testFill();
}


void RunTests::runImageTests()
{
    PixelConnectivityTest pixelConnectivityTest;
    GrayscaleImageTest grayscaleImageTest;

    pixelConnectivityTest.testIsFourConnected();
    pixelConnectivityTest.testIsEightConnected();
    pixelConnectivityTest.testIsFourNotConnected();
    pixelConnectivityTest.testIsEightNotConnected();


    grayscaleImageTest.testFindHolePixelsEightConnectivity();
    grayscaleImageTest.testFindHolePixelsFourConnectivity();
    grayscaleImageTest.testFindBoundaryPixelsFourConnectivity();
    grayscaleImageTest.testFindBoundaryPixelsEightConnectivity();
}


void RunTests::runUtilsTests()
{

    ImageUtilTest imageUtilTest;

    imageUtilTest.testToGrayscaleWithHole();
    imageUtilTest.testSaveToImage();
    imageUtilTest.normalizeToGrayScale();
}


void RunTests::runWeightFunctionsTests()
{
    EucledianDistanceTest eucledianDistanceTest;

    eucledianDistanceTest.testGetWeight();
}


void RunTests::runAllTests()
{
    runFillerTests();
    runImageTests();
    runUtilsTests();
    runWeightFunctionsTests();
}