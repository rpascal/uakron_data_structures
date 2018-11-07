#ifndef heapsort_h
#define heapsort_h
#include <vector>
using std::vector;

class HeapSort
{
  public:
    HeapSort(vector<int> a);
    void sort();
    vector<int> &getVec() { return vec; }

  private:
    inline int leftChild(int i);
    void percDown(vector<int> &a, int i, int n);
    vector<int> vec;
};

#endif // heapsort_h
