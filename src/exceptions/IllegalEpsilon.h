//
// Created by Rabia on 15/02/2019.
//

#ifndef HOLEFILLING_NEGATIVEEPSILON_H
#define HOLEFILLING_NEGATIVEEPSILON_H

#include <stdexcept>


class IllegalEpsilon : public std::runtime_error
{

public:
    explicit IllegalEpsilon(char const *message);

    char const *what() const noexcept override;
};


#endif //HOLEFILLING_NEGATIVEEPSILON_H
