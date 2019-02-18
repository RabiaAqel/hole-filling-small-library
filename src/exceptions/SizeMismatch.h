//
// Created by Rabia on 15/02/2019.
//

#ifndef HOLEFILLING_IMAGEANDMASKSIZEMISMATCH_H
#define HOLEFILLING_IMAGEANDMASKSIZEMISMATCH_H

#include <stdexcept>

class SizeMismatch : public std::runtime_error
{

public:
    explicit SizeMismatch(char const *message);

    char const *what() const noexcept override;
};


#endif //HOLEFILLING_IMAGEANDMASKSIZEMISMATCH_H
