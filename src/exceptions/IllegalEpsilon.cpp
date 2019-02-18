//
// Created by Rabia on 15/02/2019.
//

#include "IllegalEpsilon.h"


IllegalEpsilon::
IllegalEpsilon(char const *const message)
        : runtime_error(message) {}


char const *IllegalEpsilon::what() const noexcept
{
    return std::runtime_error::what();
}