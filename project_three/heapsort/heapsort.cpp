#include "heapsort.h"

using std::swap;

using std::move;

HeapSort::HeapSort(vector<int> a)
{
    vec = a;
}

void HeapSort::sort()
{
    vector<int> &a = vec;
    for (int i = a.size() / 2 - 1; i >= 0; --i) /*buildHeap*/
        percDown(a, i, a.size());
    for (int j = a.size() - 1; j > 0; --j)
    {
        swap(a[0], a[j]); /* deleteMax */
        percDown(a, 0, j);
    }
}

/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int HeapSort::leftChild(int i)
{
    return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
void HeapSort::percDown(vector<int> &a, int i, int n)
{
    int child;
    int tmp;

    for (tmp = move(a[i]); leftChild(i) < n; i = child)
    {
        child = leftChild(i);
        if (child != n - 1 && a[child] < a[child + 1])
            ++child;
        if (tmp < a[child])
            a[i] = move(a[child]);
        else
            break;
    }
    a[i] = move(tmp);
}
