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
