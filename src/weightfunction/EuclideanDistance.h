//
// Created by Rabia on 13/02/2019.
//

#ifndef HOLEFILLING_EUCLIDEANDISTANCE_H
#define HOLEFILLING_EUCLIDEANDISTANCE_H

#include "WeightFunction.h"

#include <string>



class EuclideanDistance : public WeightFunction
{
public:

    EuclideanDistance(float epsilon, float z);

    ~EuclideanDistance() = default;

    double getWeight(const Pixel &u, const Pixel &v) const override;

private:

    double calculateDistance(const Pixel &u, const Pixel &v) const;

    float       epsilon_;
    float       z_;

    static constexpr char ILLEGAL_Z_ERROR[] =
            "z value must be > 0";
    static constexpr char ILLEGAL_EPSILON_ERROR[] =
            "epsilon value must be > 0";
};


#endif //HOLEFILLING_EUCLIDEANDISTANCE_H
