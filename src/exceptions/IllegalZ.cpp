//
// Created by Rabia on 15/02/2019.
//

#include "IllegalZ.h"


IllegalZ::
IllegalZ(char const *const message)
        : runtime_error(message) {}


char const* IllegalZ::what() const noexcept
{
    return std::runtime_error::what();
}