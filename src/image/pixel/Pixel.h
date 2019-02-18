//
// Created by Rabia on 13/02/2019.
//

#ifndef HOLEFILLING_PIXEL_H
#define HOLEFILLING_PIXEL_H

#include <cstddef>
#include <MacTypes.h>


class Pixel
{

public:
    Pixel(size_t atRow, size_t atColumn, float sizeIntensity);
    ~Pixel() = default;

    size_t getRow() const;
    size_t getColumn() const;
    float getIntensity() const;

private:
    size_t row_;
    size_t column_;
    float sizeIntensity_;

};


inline Pixel::Pixel(size_t atRow, size_t atColumn, float sizeIntensity)
        : row_(atRow), column_(atColumn), sizeIntensity_(sizeIntensity) {}


inline size_t Pixel::getRow() const
{
    return row_;
}


inline size_t Pixel::getColumn() const
{
    return column_;
}


inline float Pixel::getIntensity() const
{
    return sizeIntensity_;
}


#endif //HOLEFILLING_PIXEL_H
