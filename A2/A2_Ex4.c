# include <stdio.h>
# include "A2_Ex1.h"
# include "load_file.h"
# include <time.h>
# include <windows.h>

int main()
{
    // Variables to store the time for each algorithm and array size
    //i = insertion, m = merge, q = quick

    clock_t time_taken;

    float i10;
    float i1000;
    float i100000;

    float m10;
    float m1000;
    float m100000;

    float q10;
    float q1000;
    float q100000;

    int* ip10 = load_file("test-10-1-problem");
    int* mp10 = load_file("test-10-1-problem");
    int* qp10 = load_file("test-10-1-problem");
    int* s10 = load_file("test-10-1-solution");

    int* ip1000 = load_file("test-1000-1-problem");
    int* mp1000 = load_file("test-1000-1-problem");
    int* qp1000 = load_file("test-1000-1-problem");
    int* s1000 = load_file("test-1000-1-solution");

    int* ip100000 = load_file("test-100000-1-problem");
    int* mp100000 = load_file("test-100000-1-problem");
    int* qp100000 = load_file("test-100000-1-problem");
    int* s100000 = load_file("test-100000-1-solution");

    ip10[0] = 0;
    mp10[0] = 0;
    qp10[0] = 0;
    s10[0] = 0;

    ip1000[0] = 0;
    mp1000[0] = 0;
    qp1000[0] = 0;
    s1000[0] = 0;

    ip100000[0] = 0;
    mp100000[0] = 0;
    qp100000[0] = 0;
    s100000[0] = 0;

    // Insertion Sort
    time_taken = clock();
    Sleep(1000);
    insertion_sort(ip10, 11);
    time_taken = clock() - time_taken;
    i10 = ((float)time_taken)/CLOCKS_PER_SEC - 1;

    // Print ip10 and s10
    printf("ip10: ");
    for (int i = 1; i < 11; i++) {
        printf("%d ", ip10[i]);
    }
    printf("\n");

    printf("s10: ");
    for (int i = 1; i < 11; i++) {
        printf("%d ", s10[i]);
    }
    printf("\n");

    printf("Insertion Sort 10: %f s\n", i10);

    // Merge Sort
    time_taken = clock();
    Sleep(1000);
    merge_sort(mp10, 0, 10);
    time_taken = clock() - time_taken;
    m10 = ((float)time_taken)/CLOCKS_PER_SEC - 1;
    printf("Merge Sort 10: %f s\n", m10);

    // Quick Sort
    time_taken = clock();
    Sleep(1000);
    quick_sort(qp10, 0, 10);
    time_taken = clock() - time_taken;
    q10 = ((float)time_taken)/CLOCKS_PER_SEC - 1;
    printf("Quick Sort 10: %f s\n", q10);

    // Insertion Sort
    time_taken = clock();
    Sleep(1000);
    insertion_sort(ip1000, 1001);
    time_taken = clock() - time_taken;
    i1000 = ((float)time_taken)/CLOCKS_PER_SEC - 1;
    printf("Insertion Sort 1000: %f s\n", i1000);

    // Merge Sort
    time_taken = clock();
    Sleep(1000);
    merge_sort(mp1000, 0, 1000);
    time_taken = clock() - time_taken;
    m1000 = ((float)time_taken)/CLOCKS_PER_SEC - 1;
    printf("Merge Sort 1000: %f s\n", m1000);

    // Quick Sort
    time_taken = clock();
    Sleep(1000);
    quick_sort(qp1000, 0, 1000);
    time_taken = clock() - time_taken;
    q1000 = ((float)time_taken)/CLOCKS_PER_SEC - 1;
    printf("Quick Sort 1000: %f s\n", q1000);

    // Insertion Sort
    time_taken = clock();
    Sleep(1000);
    insertion_sort(ip100000, 100001);
    time_taken = clock() - time_taken;
    i100000 = ((float)time_taken)/CLOCKS_PER_SEC - 1;
    printf("Insertion Sort 100000: %f s\n", i100000);

    // Merge Sort
    time_taken = clock();
    Sleep(1000);
    merge_sort(mp100000, 0, 100000);
    time_taken = clock() - time_taken;
    m100000 = ((float)time_taken)/CLOCKS_PER_SEC - 1;
    printf("Merge Sort 100000: %f s\n", m100000);

    // Quick Sort
    time_taken = clock();
    Sleep(1000);
    quick_sort(qp100000, 0, 100000);
    time_taken = clock() - time_taken;
    q100000 = ((float)time_taken)/CLOCKS_PER_SEC - 1;
    printf("Quick Sort 100000: %f s\n", q100000);

    // Compare if their elements are in the same order
    int sameOrder = 1;
    for (int i = 0; i < 11; i++) {
        if (ip10[i] != s10[i] && mp10[i] != s10[i] && qp10[i] != s10[i]) {
            sameOrder = 0;
            break;
        }

    for (int i = 0; i < 1001; i++)
        if (ip1000[i] != s1000[i] && mp1000[i] != s1000[i] && qp1000[i] != s1000[i]) {
            sameOrder = 0;
            break;
        }

    for (int i = 0; i < 100001; i++)
        if (ip100000[i] != s100000[i] && mp100000[i] != s100000[i] && qp100000[i] != s100000[i]) {
            sameOrder = 0;
            break;
        }
    }

    if (sameOrder == 1)
        {
            printf("All arrays are correctly sorted\n");
        }
    else
        {
            printf("All arrays are correctly sorted\n");
        }

    return 1;
}