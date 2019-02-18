//
// Created by Rabia on 16/02/2019.
//

#include "DefaultFillingStrategy.h"


DefaultFillingStrategy::
DefaultFillingStrategy(shared_ptr<HoleFillingImage> image,
                       shared_ptr<WeightFunction> weightFunction,
                       const PixelsSet &boundary,
                       const PixelsSet &hole)
        : image_(std::move(image)),
          weightFunction_(std::move(weightFunction)),
          boundary_(boundary),
          hole_(hole) {}


DefaultFillingStrategy::~DefaultFillingStrategy()
{
    boundary_.erase(boundary_.begin(),boundary_.end());
    hole_.erase(hole_.begin(),hole_.end());
}


void DefaultFillingStrategy::fillHole()
{
    for ( auto const &pixel: hole_ )
        image_->setPixelIntensity(pixel->getRow(), pixel->getColumn(), calculateFillIntensity(*pixel));
}


double DefaultFillingStrategy::calculateFillIntensity(Pixel pixel)
{
    double nominator = 0;
    double denominator = 0;

    for ( auto const &boundaryPixel: boundary_ )
    {
        double weight = 0;
        weight = weightFunction_->getWeight(*boundaryPixel, pixel);
        nominator += weight * boundaryPixel->getIntensity();
        denominator += weight;
    }

    return nominator / denominator;
}