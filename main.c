#include "stdio.h"
#include "stdint.h"

int main() {
    uint32_t a = 0xFF << 24;
    uint32_t b = 0xFF000000;
    printf("%d, %d", a, b);
}
