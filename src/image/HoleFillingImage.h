//
// Created by Rabia on 14/02/2019.
//

#ifndef HOLEFILLING_HOLEFILLINGIMAGE_H
#define HOLEFILLING_HOLEFILLINGIMAGE_H

#include <vector>
#include "opencv2/core/core.hpp"
#include "pixel/Pixel.h"

using cv::Mat;
using std::shared_ptr;
using std::unique_ptr;
using std::make_unique;

typedef std::vector<std::shared_ptr<Pixel>> PixelsSet;


class HoleFillingImage
{
public:
    virtual ~HoleFillingImage() = default;

    virtual int getWidth() const = 0;

    virtual int getHeight() const = 0;

    /**
     *
     * @return a set of the hole boundary pixels
     */
    virtual PixelsSet findBoundaryPixels() const = 0;

    /**
     *
     * @return a set of the hole pixels
     */
    virtual PixelsSet findHolePixels() const = 0;

    /**
     *
     * @param atRow position in x axis
     * @param atColumn position in y axis
     * @param intensity the new float color intensity
     */
    virtual void setPixelIntensity(int atRow, int atColumn, float intensity) = 0;

};


#endif //HOLEFILLING_HOLEFILLINGIMAGE_H
