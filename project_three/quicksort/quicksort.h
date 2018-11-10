#ifndef quicksort_h
#define quicksort_h
#include <vector>
using std::vector;

class QuickSort
{
public:
  QuickSort(vector<int> a);
  void sort();
  vector<int> &getVec() { return vec; }

private:
  vector<int> vec;
  void quicksort(vector<int> &a);
  const int &median3(vector<int> &a, int left, int right);
  void quicksort(vector<int> &a, int left, int right);
};

#endif // quicksort_h
