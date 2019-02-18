//
// Created by Rabia on 15/02/2019.
//

#include "EmptyImage.h"


EmptyImage::
EmptyImage(char const *const message)
        : runtime_error(message) {}


char const *EmptyImage::what() const noexcept
{
    return std::runtime_error::what();
}