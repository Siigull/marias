#ifndef RANDOM_H
#define RANDOM_H

#include "common.h"

#include <random>

namespace Random {
    inline std::mt19937 gen;

    uint32_t get_random(uint32_t min, uint32_t max);
};

#endif
