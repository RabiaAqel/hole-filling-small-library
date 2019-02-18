//
// Created by Rabia on 14/02/2019.
//

#include "ImageUtil.h"

#include "../exceptions/EmptyImage.h"
#include "../exceptions/SizeMismatch.h"

constexpr char ImageUtil::EMPTY_IMAGE_ERROR[];
constexpr char ImageUtil::EMPTY_MASK_ERROR[];
constexpr char ImageUtil::SIZE_MISMATCH_ERROR[];


Mat ImageUtil::
toFloatImageWithHole(const string &imagePath, const string &maskPath)
{
    Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    Mat mask = cv::imread(maskPath, cv::IMREAD_GRAYSCALE);

    if ( image.empty())
        throw EmptyImage(EMPTY_IMAGE_ERROR);

    if ( mask.empty())
        throw EmptyImage(EMPTY_MASK_ERROR);

    if ( image.size != mask.size )
        throw SizeMismatch(SIZE_MISMATCH_ERROR);

    Mat floatImage;

    image.convertTo(floatImage, CV_32F, 1.0 / 255, 0);
    floatImage.setTo(-1.f, mask);

    return floatImage;
}


void ImageUtil::saveImageTo(const Mat &image, const std::string& target,
                            const std::string& fileName)
{
    imwrite(target + "/" + fileName, image);
}


Mat ImageUtil::normalizeToGrayscale(const Mat &image)
{
    cv::Mat out;

    cv::normalize(image, out, 255, 0, cv::NORM_MINMAX, CV_8UC1);

    return out;
}
