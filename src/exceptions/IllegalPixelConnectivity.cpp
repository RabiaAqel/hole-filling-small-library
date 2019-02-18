//
// Created by Rabia on 16/02/2019.
//

#include "IllegalPixelConnectivity.h"


IllegalPixelConnectivity::
IllegalPixelConnectivity(char const *const message)
        : runtime_error(message) {}


char const* IllegalPixelConnectivity::what() const noexcept
{
    return std::runtime_error::what();
}