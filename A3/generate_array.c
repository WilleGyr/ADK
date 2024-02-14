#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateRandomArray(int n) {
    srandom((unsigned int)clock()); // Changed from time(NULL) to clock()

    int* array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }

    for (int i = n - 1; i > 0; --i) {
        int j = random() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    return array;
}
