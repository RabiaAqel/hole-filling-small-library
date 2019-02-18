//
// Created by Rabia on 15/02/2019.
//

#ifndef HOLEFILLING_NEGATIVEZ_H
#define HOLEFILLING_NEGATIVEZ_H

#include <stdexcept>


class IllegalZ : public std::runtime_error
{

public:
    explicit IllegalZ(char const *message);

    char const *what() const noexcept override;
};


#endif //HOLEFILLING_NEGATIVEZ_H
