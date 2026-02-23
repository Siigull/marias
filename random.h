#ifndef RANDOM_H
#define RANDOM_H

#include <random>

namespace Random {
    inline std::mt19937 gen;

    void get_random();
};

#endif
