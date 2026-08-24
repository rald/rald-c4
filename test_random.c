#include "random.h"

int main() {
    // Set an initial seed
    srand(time(0));

    // Generate and print a few pseudo-random numbers
    printf("Random numbers:\n");
    printf("%011d\n", rand());
    printf("%011d\n", rand());
    printf("%011d\n", rand());

    return 0;
}
