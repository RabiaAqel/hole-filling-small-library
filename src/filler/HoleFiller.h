//
// Created by Rabia on 14/02/2019.
//

#ifndef HOLEFILLING_FILLER_H
#define HOLEFILLING_FILLER_H

#include "../weightfunction/WeightFunction.h"
#include "../image/HoleFillingImage.h"
#include "../image/pixel/Pixel.h"
#include "FillingStrategy.h"
#include "DefaultFillingStrategy.h"

using std::shared_ptr;
using std::make_shared;
using std::move;


class HoleFiller
{
public:
    enum FILL_STRATEGY
    {
        DEFAULT,
    };

    HoleFiller(shared_ptr<HoleFillingImage> image,
           shared_ptr<WeightFunction> weightFunction,
           FILL_STRATEGY = DEFAULT);

    ~HoleFiller() = default;
    HoleFiller(const HoleFiller& holeFiller) = delete;
    HoleFiller& operator= ( const HoleFiller & ) noexcept = delete;


    /**
     * Fills the hole in the image using
     * the fillStrategy and WeightFunciton
     */
    void fill();

private:
    shared_ptr<WeightFunction> weightFunction_;
    shared_ptr<HoleFillingImage> image_;
    shared_ptr<FillingStrategy> fillingStrategy_;

    void configureFillingStrategy(FILL_STRATEGY strategy);

    PixelsSet boundary_;
    PixelsSet hole_;

};


#endif //HOLEFILLING_FILLER_H
