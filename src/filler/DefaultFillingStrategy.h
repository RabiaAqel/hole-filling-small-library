//
// Created by Rabia on 16/02/2019.
//

#ifndef HOLEFILLING_DEFAULTFILLINGSTRATEGY_H
#define HOLEFILLING_DEFAULTFILLINGSTRATEGY_H

#include "FillingStrategy.h"


class DefaultFillingStrategy : public FillingStrategy
{
public:
    DefaultFillingStrategy(shared_ptr<HoleFillingImage> image,
                           shared_ptr<WeightFunction> weightFunction,
                           const PixelsSet &boundary,
                           const PixelsSet &hole);

    ~DefaultFillingStrategy();

    DefaultFillingStrategy(const DefaultFillingStrategy &) = delete;

    DefaultFillingStrategy &operator=
            (const DefaultFillingStrategy &) noexcept = delete;


    void fillHole() override;

private:
    double calculateFillIntensity(Pixel pixel);


    shared_ptr<WeightFunction>      weightFunction_;
    shared_ptr<HoleFillingImage>    image_;

    PixelsSet                       boundary_;
    PixelsSet                       hole_;
};


#endif //HOLEFILLING_DEFAULTFILLINGSTRATEGY_H
