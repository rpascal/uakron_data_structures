#include "quicksort.h"
#include <iostream>

QuickSort::QuickSort(vector<int> a)
{
    vec = a;
}

void QuickSort::sort()
{
    vector<int> &a = vec;
    quicksort(a);
}

void QuickSort::quicksort(vector<int> &a)
{
    quicksort(a, 0, a.size() - 1);
}

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
const int &QuickSort::median3(vector<int> &a, int left, int right)
{
    int center = (left + right) / 2;

    if (a[center] < a[left])
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);

    // Place pivot at position right - 1
    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
void QuickSort::quicksort(vector<int> &a, int left, int right)
{
    // if(left > right){
    //     std::swap(a[left], a[right]);
    //     return;
    // }

    std::cout << "Left: "<< left << " Right: "<< right << '\n';
    // if (left + 10 <= right)
    // {
    const int &pivot = median3(a, left, right);

    //begin partitioning
    int i = left, j = right - 1;
    for (;;)
    {
        while (a[++i] < pivot)
        {
        }
        while (pivot < a[--j])
        {
        }
        if (i < j)
            std::swap(a[i], a[j]);
        else
            break;
    }

    std::swap(a[i], a[right - 1]); //restore pivot
    quicksort(a, left, i - 1);
    quicksort(a, i + 1, right);
    // }

    // else //do an insertion sort on the subarray
    //     insertionSort(a, left, right);
}
