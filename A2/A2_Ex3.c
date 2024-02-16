#include <stdio.h>
#include "A2_Ex1.h" 

int main()
{
    // Sort 1
    int A1[] = {3, 1, 5, 10, 8, 7, 5, 2, 9, 6, 1, 2};
    int A2[] = {3, 1, 5, 10, 8, 7, 5, 2, 9, 6, 1, 2};
    int A3[] = {3, 1, 5, 10, 8, 7, 5, 2, 9, 6, 1, 2};

    insertion_sort(A1, 12);
    merge_sort(A2, 0, 11);
    quick_sort(A3, 0, 11);

    int i = 0;

    printf("Sort 1 using Insertion Sort: \n");
    for(i = 0; i < 12; i++) {
        printf("%d ", A1[i]);
    }
    printf("\n");
    
    printf("Sort 1 using Merge Sort: \n");
    for(i = 0; i < 12; i++) {
        printf("%d ", A2[i]);
    }
    printf("\n");

    printf("Sort 1 using Quick Sort: \n");
    for(i = 0; i < 12; i++) {
        printf("%d ", A3[i]);
    }
    printf("\n");

    // Sort 2
    int A4[] = {2, 0, 0, 4, 0, 5, 0, 8, 1, 2, 3, 4};
    int A5[] = {2, 0, 0, 4, 0, 5, 0, 8, 1, 2, 3, 4};
    int A6[] = {2, 0, 0, 4, 0, 5, 0, 8, 1, 2, 3, 4};

    insertion_sort(A4, 12);
    merge_sort(A5, 0, 11);
    quick_sort(A6, 0, 11);

    printf("Sort 2 using Insertion Sort: \n");
    for(i = 0; i < 12; i++) {
        printf("%d ", A4[i]);
    }
    printf("\n");

    printf("Sort 2 using Merge Sort: \n");
    for(i = 0; i < 12; i++) {
        printf("%d ", A5[i]);
    }
    printf("\n");

    printf("Sort 2 using Quick Sort: \n");
    for(i = 0; i < 12; i++) {
        printf("%d ", A6[i]);
    }

    return 1;
}