//
// Created by Rabia on 16/02/2019.
//

#ifndef HOLEFILLING_INVALIDPIXELCONNECTIVITY_H
#define HOLEFILLING_INVALIDPIXELCONNECTIVITY_H

#include <stdexcept>


class IllegalPixelConnectivity : public std::runtime_error
{

public:
    explicit IllegalPixelConnectivity(char const *message);

    char const *what() const noexcept override;
};


#endif //HOLEFILLING_INVALIDPIXELCONNECTIVITY_H
