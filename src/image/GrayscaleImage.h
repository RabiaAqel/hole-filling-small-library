//
// Created by Rabia on 13/02/2019.
//

#ifndef HOLEFILLING_GRAYSCALEIMAGE_H
#define HOLEFILLING_GRAYSCALEIMAGE_H

#include "HoleFillingImage.h"
#include "pixel/PixelConnectivity.h"


class GrayscaleImage : public HoleFillingImage
{


public:
    GrayscaleImage(shared_ptr<Mat> image,
                   PixelConnectivity::Connectivity connectivity,
                   short missingValue);
    GrayscaleImage(const GrayscaleImage& grayscaleImage);

    ~GrayscaleImage() override;

    GrayscaleImage& operator= ( const GrayscaleImage & ) noexcept;

    int getWidth() const override;

    int getHeight() const override;

    PixelsSet findBoundaryPixels() const override;

    PixelsSet findHolePixels() const override;

    void setPixelIntensity(int atRow, int atColumn, float intensity) override;

    short getMissingValue() const;

    void setMissingValue(short missingValue);


private:
    bool isMissing(int atRow, int atColumn) const;

    bool isBoundaryPixel(int atRow, int atColumn) const;

    bool isHoleConnected(int atRow, int atColumn) const;

    short                               missingValue_;
    int                                 width_;
    int                                 height_;

    shared_ptr<Mat>                     image_;
    unique_ptr<PixelConnectivity>       connectivity_;

    static constexpr short              MISSING = -1;

};


inline int GrayscaleImage::getWidth() const
{
    return width_;
}


inline int GrayscaleImage::getHeight() const
{
    return height_;
}


#endif //HOLEFILLING_GRAYSCALEIMAGE_H
