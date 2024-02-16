# include <stdio.h>
# include "A2_Ex1.h"

void insertion_sort(int A[], int n) // n = length of array A
{
    for (int i = 1; i < n; i++) // Start at second element
    {
        int key = A[i]; // Key is the current element
        int j = i - 1;  // j is the previous element
        while(j >= 0 && A[j] > key) // While the previous element is greater than the current element
        {
            A[j+1] = A[j]; // Move the previous element to the right
            j = j - 1;  // Move to the next previous element
        }
        A[j+1] = key; // Insert the current element in the correct position
    }
}

void merge(int A[], int p, int q, int r)
{
    int nl = q - p + 1; // Length of left subarray
    int nr = r - q; // Length of right subarray
    int L[nl], R[nr]; // Create left and right subarrays

    for (int i = 0; i < nl; i++) {
        L[i] = A[p + i]; // Copy + fill left subarray
    }

    for (int j = 0; j < nr; j++) {
        R[j] = A[q + j + 1]; // Copy + fill right subarray
    }

    int i = 0;
    int j = 0; // i = index of left subarray, j = index of right subarray
    int k = p; // k = index of merged subarray

    while (i < nl && j < nr) // While both subarrays have elements
    {
        if (L[i] <= R[j]) // If left subarray element is less than or equal to right subarray element
        {
            A[k] = L[i]; // Add left subarray element to merged subarray
            i++;
        }

        else
        {
            A[k] = R[j]; // Add right subarray element to merged subarray
            j++;
        }
        k++;
    }

    while (i < nl) // While only left subarray has elements
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < nr) // While only right subarray has elements
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int A[], int p, int r)
{
    if (p >= r) // If array has max one element
    {
        return;
    }

    int q = (p + r) / 2; // Middle index of array

    merge_sort(A, p, q); // Sort left subarray
    merge_sort(A, q + 1, r); // Sort right subarray
    merge(A, p, q, r); // Merge sorted subarrays
}

int partition(int A[], int p, int r)
{
    int x = A[r]; // Pivot element
    int i = p - 1; // Index of smaller element

    for (int j = p; j < r; j++)
    {
        if (A[j] <= x) // If current element is less than or equal to pivot
        {
            i++; // Increment index of smaller element
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp; // Swap A[i] and A[j]
        }
    }

    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i + 1; // Return index of pivot element    
}

void quick_sort(int A[], int p, int r)
{
    if (p < r) // If array has more than one element
    {
        int q = partition(A, p, r); // q is the index of pivot element
        quick_sort(A, p, q - 1); // Sort left subarray
        quick_sort(A, q + 1, r); // Sort right subarray
    }
}
