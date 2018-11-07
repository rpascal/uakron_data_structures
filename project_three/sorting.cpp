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


using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::getline;
using std::ifstream;
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

void print(vector<int> vec)
{
    for (vector<int>::iterator item = vec.begin(); item != vec.end(); ++item)
    {
        cout << *item << ' ';
    }

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

    HeapSort heap(dataSet);
    print(heap.getVec());

    heap.sort();
    print(heap.getVec());

    InsertSort inser(dataSet);
    print(inser.getVec());

    inser.sort();
    print(inser.getVec());

    std::cout << "Hello, World!\n";
    return 0;
}