#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Random(int min, int max)
{
    double uniform; // Declare a double to hold a random value between 0 and 1
    int ret; // Declare an integer to hold the final random value between min and max
    srandom((unsigned int)clock()); // Seed the random number generator with the current time

    uniform = random() / (double)RAND_MAX; // Generate a random double between 0 and 1
    ret = (int)(uniform * (double)(max - min)) + min; // Scale and shift the random double to the range [min, max], then cast to an integer

    return ret; // Return the random integer
}

int* generateRandomArray(int n) {
    int* array = (int*)malloc(n * sizeof(int)); // Allocate memory for an array of n integers

    for (int i = 0; i < n; ++i) {
        array[i] = Random(1, n); // Fill each element of the array with a random integer between 0 and n
    }

    return array; // Return the array
}