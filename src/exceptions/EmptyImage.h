//
// Created by Rabia on 15/02/2019.
//

#ifndef HOLEFILLING_EMPTYIMAGE_H
#define HOLEFILLING_EMPTYIMAGE_H

#include <stdexcept>


class EmptyImage : public std::runtime_error
{

public:
    explicit EmptyImage(char const *message);

    char const *what() const noexcept override;
};


#endif //HOLEFILLING_EMPTYIMAGE_H
