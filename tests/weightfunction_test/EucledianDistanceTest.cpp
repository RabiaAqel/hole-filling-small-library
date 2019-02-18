//
// Created by Rabia on 17/02/2019.
//

#include "EucledianDistanceTest.h"

#include <cmath>

#include <iostream>


void EucledianDistanceTest::testGetWeight()
{
    float z = 2.f;
    float epsilon = 0.0001f;

    Pixel u(2, 10, 0.5);
    Pixel v(14, 5, 0.8);

    EuclideanDistance euclideanDistance(epsilon, z);

    double result =  euclideanDistance.getWeight(u, v);

    assert(result < 0.006 && result > 0.005);

}