#ifndef mergesort_h
#define mergesort_h
#include <vector>
using std::vector;

class MergeSort
{
  public:
    MergeSort(vector<int> a);
    void sort();
    vector<int> &getVec() { return vec; }

  private:
    vector<int> vec;
    void mergeSort(vector<int> &a);
    void mergeSort(vector<int> &a, vector<int> &tmpArray, int left, int right);
    void merge(vector<int> &a, vector<int> &tmpArray, int leftPos, int rightPos, int rightEnd);
};

#endif // mergesort_h

// #ifndef mergesort_h
// #define mergesort_h

// template <typename Comparable>
// void mergeSort(vector<Comparable> &a)
// {

//     vector<Comparable> tmpArray(a.size());

//     mergeSort(a, tmpArray, 0, a.size() - 1);
// }

// /**
//  * Internal method that makes recursive calls.
//  * a is an array of Comparable items.
//  * tmpArray is an array to place the merged result.
//  * left is the left-most index of the subarray.
//  * right is the right-most index of the subarray.
//  */

// template <typename Comparable>
// void mergeSort(vector<Comparable> &a vector<Comparable> &tmpArray, int left, int right)
// {
//     if (left < right)
//     {
//         in center = (left + right) / 2;
//         mergeSort(a, tmpArray, left, center);
//         mergeSort(a, tmpArray, center + 1, right);
//         merge(a, tmpArray, left, center + 1, right);
//     }
// }

// #endif // mergesort_h