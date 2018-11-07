#ifndef insertsort_h
#define insertsort_h
#include <vector>
using std::vector;

class InsertSort
{
  public:
    InsertSort(vector<int> a);
    void sort();
    vector<int> &getVec() { return vec; }

  private:
    vector<int> vec;
};

#endif // insertsort_h
