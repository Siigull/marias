#include "random.h"

namespace Random {
    void seed_random(uint64_t seed) {
        gen.seed(seed);
    }

    uint32_t get_random(uint32_t min, uint32_t max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }
};
