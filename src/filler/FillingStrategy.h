//
// Created by Rabia on 16/02/2019.
//

#ifndef HOLEFILLING_FILLINGSTRATEGY_H
#define HOLEFILLING_FILLINGSTRATEGY_H

#include <memory>

#include "opencv2/core/core.hpp"

#include "../image/HoleFillingImage.h"
#include "../image/pixel/Pixel.h"
#include "../weightfunction/WeightFunction.h"

using std::shared_ptr;


class FillingStrategy
{
public:
    virtual void fillHole() = 0;

};


#endif //HOLEFILLING_FILLINGSTRATEGY_H
