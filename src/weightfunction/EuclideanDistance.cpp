//
// Created by Rabia on 13/02/2019.
//

#include "EuclideanDistance.h"

#include <cmath>

#include "../exceptions/IllegalEpsilon.h"
#include "../exceptions/IllegalZ.h"


constexpr char EuclideanDistance::ILLEGAL_Z_ERROR[];
constexpr char EuclideanDistance::ILLEGAL_EPSILON_ERROR[];



EuclideanDistance::EuclideanDistance(float epsilon, float z)
        : epsilon_(epsilon), z_(z)
{
    if ( epsilon_ <= 0 )
        throw IllegalEpsilon(ILLEGAL_EPSILON_ERROR);

    if ( z_ <= 0 )
        throw IllegalZ(ILLEGAL_Z_ERROR);
}


double EuclideanDistance::getWeight(const Pixel &u, const Pixel &v) const
{
    return calculateDistance(u, v);
}

double EuclideanDistance::calculateDistance(const Pixel &u, const Pixel &v) const
{

    double x = (int) u.getColumn() - (int) v.getColumn();
    double y = (int) u.getRow() - (int) v.getRow();
    double dist = 0;


    dist = pow(x, 2.) + pow(y, 2.);
    dist = sqrt(dist);
    dist = pow(dist, z_);
    dist += epsilon_;

    return 1 / dist;
}