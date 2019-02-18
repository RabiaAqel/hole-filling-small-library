//
// Created by Rabia on 13/02/2019.
//



#include "GrayscaleImage.h"


constexpr short GrayscaleImage::MISSING;


GrayscaleImage::
GrayscaleImage(shared_ptr<Mat> image,
               PixelConnectivity::Connectivity connectivity,
               short missingValue = MISSING)
        : image_(std::move(image))
{
    missingValue_ = missingValue;
    height_ = image_->rows;
    width_ = image_->cols;
    connectivity_ =
            make_unique<PixelConnectivity>(connectivity, MISSING, image_);
}


GrayscaleImage::GrayscaleImage(const GrayscaleImage &grayscaleImage)
{
    image_ = grayscaleImage.image_;
    missingValue_ = grayscaleImage.missingValue_;
    height_ = grayscaleImage.image_->rows;
    width_ = grayscaleImage.image_->cols;
    connectivity_ =
            make_unique<PixelConnectivity>
                    (grayscaleImage.connectivity_->getConnectivity(),
                     MISSING, image_);
}


GrayscaleImage &GrayscaleImage::
operator=(const GrayscaleImage &other) noexcept
{
    if ( this == &other )
        return *this;

    image_ = other.image_;
    missingValue_ = other.missingValue_;
    height_ = other.image_->rows;
    width_ = other.image_->cols;
    connectivity_ =
            make_unique<PixelConnectivity>
                    (other.connectivity_->getConnectivity(),
                     MISSING, image_);

    return *this;
}


GrayscaleImage::~GrayscaleImage()
{
    image_->release();
}


bool GrayscaleImage::isBoundaryPixel(int atRow, int atColumn) const
{
    return !isMissing(atRow, atColumn)
           && isHoleConnected(atRow, atColumn);
}


PixelsSet GrayscaleImage::findBoundaryPixels() const
{

    PixelsSet boundaryPixels;

    for ( int i = 0; i < height_; ++i )
        for ( int j = 0; j < width_; ++j )
            if ( isBoundaryPixel(i, j))
                boundaryPixels.push_back(std::make_shared<Pixel>(i, j, image_->at<float>(i, j)));

    return boundaryPixels;

}


PixelsSet GrayscaleImage::findHolePixels() const
{
    PixelsSet holePixels;

    for ( int i = 0; i < height_; ++i )
        for ( int j = 0; j < width_; ++j )
            if ( isMissing(i, j))
                holePixels.push_back(std::make_shared<Pixel>(i, j, image_->at<float>(i, j)));


    return holePixels;
}


bool GrayscaleImage::isMissing(int atRow, int atColumn) const
{
    return image_->at<float>(atRow, atColumn) == MISSING;
}


bool GrayscaleImage::isHoleConnected(int atRow, int atColumn) const
{
    return connectivity_->isConnected(atRow, atColumn);
}


void GrayscaleImage::setPixelIntensity(int atRow, int atColumn, float intensity)
{
    image_->at<float>(atRow, atColumn) = intensity;
}


short GrayscaleImage::getMissingValue() const
{
    return missingValue_;
}


void GrayscaleImage::setMissingValue(short missingValue)
{
    missingValue_ = missingValue;
}

