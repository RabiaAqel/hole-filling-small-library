//
// Created by Rabia on 14/02/2019.
//

#include "HoleFiller.h"


#include <iostream>
HoleFiller::HoleFiller(shared_ptr<HoleFillingImage> image,
               shared_ptr<WeightFunction> weight,
               FILL_STRATEGY strategy)
        : weightFunction_(move(weight)),
          image_(move(image))
{
    boundary_ = image_->findBoundaryPixels();
    hole_ = image_->findHolePixels();

    configureFillingStrategy(strategy);


}


void HoleFiller::fill()
{
    fillingStrategy_->fillHole();
}


void HoleFiller::configureFillingStrategy(FILL_STRATEGY strategy)
{
    switch ( strategy )
    {
        case DEFAULT:
            fillingStrategy_ = make_shared<DefaultFillingStrategy>
                    (image_, weightFunction_, boundary_, hole_);
            break;
    }
}
