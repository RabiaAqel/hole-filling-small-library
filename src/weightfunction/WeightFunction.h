//
// Created by Rabia on 13/02/2019.
//

#ifndef HOLEFILLING_WEIGHTFUNCTION_H
#define HOLEFILLING_WEIGHTFUNCTION_H

#include <utility>
#include "../image/pixel/Pixel.h"


class WeightFunction
{
public:
    /**
     *
     * @param u a pixel
     * @param v a pixel
     * @return weight value on u and v
     */
    virtual double getWeight(const Pixel &u, const Pixel &v) const = 0;

};


#endif //HOLEFILLING_WEIGHTFUNCTION_H
