cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 14)

project(HoleFilling)

find_package(OpenCV REQUIRED)




add_executable(HoleFilling main.cpp src/image/pixel/Pixel.h src/image/GrayscaleImage.h src/image/GrayscaleImage.cpp src/weightfunction/WeightFunction.h
        src/weightfunction/EuclideanDistance.h src/weightfunction/EuclideanDistance.cpp src/filler/HoleFiller.h src/filler/HoleFiller.cpp
        src/utils/ImageUtil.h src/utils/ImageUtil.cpp src/exceptions/SizeMismatch.h src/exceptions/SizeMismatch.cpp
        src/exceptions/EmptyImage.cpp src/exceptions/EmptyImage.h src/exceptions/IllegalEpsilon.h
        src/exceptions/IllegalEpsilon.cpp src/exceptions/IllegalZ.h src/exceptions/IllegalZ.cpp
        src/filler/FillingStrategy.h src/filler/DefaultFillingStrategy.cpp src/filler/DefaultFillingStrategy.h
        src/image/pixel/PixelConnectivity.cpp src/image/pixel/PixelConnectivity.h
        src/exceptions/IllegalPixelConnectivity.h src/exceptions/IllegalPixelConnectivity.cpp
        CmdUtility.h CmdUtility.cpp
        tests/weightfunction_test/EucledianDistanceTest.h tests/weightfunction_test/EucledianDistanceTest.cpp
        tests/utils_test/ImageUtilTest.h tests/utils_test/ImageUtilTest.cpp
        tests/image_test/GrayscaleImageTest.h tests/image_test/GrayscaleImageTest.cpp
        tests/image_test/PixelConnectivityTest.h tests/image_test/PixelConnectivityTest.cpp
        tests/filler_test/FillerTest.h tests/filler_test/FillerTest.cpp
        tests/RunTests.h tests/RunTests.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})

link_directories(/Users/rabiaabuaqel/Downloads/googletest-master/googletest/include/)

target_link_libraries(HoleFilling ${OpenCV_LIBS} )