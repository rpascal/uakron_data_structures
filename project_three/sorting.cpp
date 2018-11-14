/*
    Project 3
    Ryan Pascal
*/

#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "./heapsort/heapsort.h"
#include "./insertsort/insertsort.h"
#include "./mergesort/mergesort.h"
#include "./quicksort/quicksort.h"
#include <ctime>
#include <numeric>
#include <cstdlib>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::getline;
using std::ifstream;
using std::iota;
using std::istringstream;
using std::string;
using std::vector;

/*
    Ask user to load a file and loop over lines.
    Each is passed to callback function.
*/
void readData(function<void(string &)> lineCallback)
{
    ifstream input;
    string filename;
    cout << "Please enter the filename to process: ";
    cin >> filename;
    input.open(filename.c_str());
    // Keep retrying until file could be opened
    while (input.fail())
    {
        input.clear();
        cout << "Incorrect filename, please enter again: ";
        cin >> filename;
        input.open(filename.c_str());
    }
    string line;
    //Loop over each line in input
    while (getline(input, line))
    {
        if (line.length() > 0)
        {
            lineCallback(line);
        }
    }
}

/*
    Print a vector of ints
*/
void print(vector<int> &vec)
{
    for (vector<int>::iterator item = vec.begin(); item != vec.end(); ++item)
    {
        cout << *item << ' ';
    }

    cout << endl;
}

/*
    Generates a dataset of size N
    Depending on type dataset will either be random, desc, or asc
    defaults to asc
*/
vector<int> generateDataSet(int n, string type = "")
{
    if (!type.compare("RANDOM"))
    {
        std::vector<int> ivec;

        for (int i = 1; i < n; ++i)
            ivec.push_back(rand());
        return ivec;
    }
    else if (!type.compare("DESC"))
    {
        std::vector<int> ivec(n);
        iota(ivec.begin(), ivec.end(), 0);
        std::reverse(ivec.begin(), ivec.end());
        return ivec;
    }
    else
    {
        std::vector<int> ivec(n);
        iota(ivec.begin(), ivec.end(), 0);
        return ivec;
    }
}

/*
    Run sorts on smaller inputed dataset
*/
void runSmallDataSet(vector<int> &dataSet)
{
    // Heap Sort
    HeapSort heap(dataSet);
    cout << "vector before heap sort: ";
    print(heap.getVec());
    heap.sort();
    cout << "vector after heap sort: ";
    print(heap.getVec());
    cout << endl;

    // Merge Sort
    MergeSort merg(dataSet);
    cout << "vector before merge sort: ";

    print(merg.getVec());

    merg.sort();
    cout << "vector after merge sort: ";

    print(merg.getVec());
    cout << endl;

    // Quick Sort
    QuickSort quick(dataSet);
    cout << "vector before quick sort: ";

    print(quick.getVec());

    quick.sort();
    cout << "vector after quick sort: ";

    print(quick.getVec());
    cout << endl;

    // Insert Sort
    InsertSort inser(dataSet);
    cout << "vector before insertion sort: ";

    print(inser.getVec());

    inser.sort();
    cout << "vector after insertion sort: ";

    print(inser.getVec());
    cout << endl;
}

/*
    Calculate runtime
*/
double runtime(clock_t start, clock_t stop)
{
    return double(stop - start) / double(CLOCKS_PER_SEC);
}

/*
    Run sorts on larger generated datasets
*/
void runLargeDataSets(int n)
{
    cout << "runtime of algorithms for N = " << n << " items" << endl;

    clock_t start, stop;

    vector<int> randomVec = generateDataSet(n, "RANDOM");
    vector<int> descVec = generateDataSet(n, "DESC");
    vector<int> ascVec = generateDataSet(n);

    // Heap Sort
    HeapSort heapRandom(randomVec);
    start = clock();
    heapRandom.sort();
    stop = clock();
    cout << "heap sort random: " << runtime(start, stop) << endl;

    HeapSort heapAsc(ascVec);
    start = clock();
    heapAsc.sort();
    stop = clock();
    cout << "heap sort ascending: " << runtime(start, stop) << endl;

    HeapSort heapDesc(descVec);
    start = clock();
    heapDesc.sort();
    stop = clock();
    cout << "heap sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Merge Sort
    MergeSort mergeRandom(randomVec);
    start = clock();
    mergeRandom.sort();
    stop = clock();
    cout << "merge sort random: " << runtime(start, stop) << endl;

    MergeSort mergeAsc(ascVec);
    start = clock();
    mergeAsc.sort();
    stop = clock();
    cout << "merge sort ascending: " << runtime(start, stop) << endl;

    MergeSort mergeDesc(descVec);
    start = clock();
    mergeDesc.sort();
    stop = clock();
    cout << "merge sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Quick Sort
    QuickSort quickRandom(randomVec);
    start = clock();
    quickRandom.sort();
    stop = clock();
    cout << "quick sort random: " << runtime(start, stop) << endl;

    QuickSort quickAsc(ascVec);
    start = clock();
    quickAsc.sort();
    stop = clock();
    cout << "quick sort ascending: " << runtime(start, stop) << endl;

    QuickSort quickDesc(descVec);
    start = clock();
    quickDesc.sort();
    stop = clock();
    cout << "quick sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Insert Sort
    InsertSort insertionRandom(randomVec);
    start = clock();
    insertionRandom.sort();
    stop = clock();
    cout << "insertion sort random: " << runtime(start, stop) << endl;

    InsertSort insertionAsc(ascVec);
    start = clock();
    insertionAsc.sort();
    stop = clock();
    cout << "insertion sort ascending: " << runtime(start, stop) << endl;

    InsertSort insertionDesc(descVec);
    start = clock();
    insertionDesc.sort();
    stop = clock();
    cout << "insertion sort descending: " << runtime(start, stop) << endl;

    cout << endl;
}

int main(int argc, const char *argv[])
{

    vector<int> dataSet;

    readData([&](string &line) {
        std::istringstream iss(line);
        for (std::string s; iss >> s;)
        {
            // Convert string to an int
            int i = std::stoi(s);
            dataSet.push_back(i);
        }
    });
    int N = 0;

    cout << "Enter the number of integers to sort: ";
    cin >> N;
    cout << endl;

    runSmallDataSet(dataSet);

    runLargeDataSets(N);

    return 0;
}