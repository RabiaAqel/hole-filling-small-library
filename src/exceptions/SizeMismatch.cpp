//
// Created by Rabia on 15/02/2019.
//

#include "SizeMismatch.h"

SizeMismatch::
SizeMismatch(char const *const message)
        : runtime_error(message) {}


char const* SizeMismatch::what() const noexcept
{
    return std::runtime_error::what();
}
