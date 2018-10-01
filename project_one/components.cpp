// Ryan Pascal
// Data Structures
// Project 1 
// 10/1/2018

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <functional>
#include <string>
#include <sstream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::list;
using std::map;
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
    cout << "Please enter the graph filename to process: ";
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
        lineCallback(line);
    }
}

/*
    Find element in list that is one size larger than passed in int.
    If no element found passed in int must be larger than all items in list
    therefore return stop.
*/
list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x)
{
    for (list<int>::iterator currentIterator = start; currentIterator != stop; ++currentIterator)
    {
        if (*currentIterator > x)
        {
            return currentIterator;
        }
    }
    return stop;
}

/*
    Find element in list that is one size larger than passed in int.
    If no element found passed in int must be smaller than all items in list
    therefore return start.
*/
void print(vector<list<int>> &adjList)
{
    cout << "The adjacency list for your graph \n";
    for (vector<list<int>>::iterator vectorListElement = adjList.begin(); vectorListElement != adjList.end(); ++vectorListElement)
    {
        const int index = vectorListElement - adjList.begin();
        cout << "List " << index << ": ";
        for (auto currentIterator = vectorListElement->begin(); currentIterator != vectorListElement->end(); ++currentIterator)
        {
            cout << *currentIterator << ' ';
        }
        cout << '\n';
    }
}

/*
    Compare 2 lists to determine if there is shared element
    between the two lists. 
    Returns a boolean, true if element shared, false otherwise.
*/
bool connComponent(const list<int> &a, const list<int> &b)
{
    const int aSize = a.size();
    const int bSize = b.size();
    map<int, bool> m;
    const int upperBound = (aSize < bSize ? bSize : aSize);

    list<int>::const_iterator aIterator = a.begin();
    list<int>::const_iterator bIterator = b.begin();

    for (int i = 0; i < upperBound; i++)
    {
        // Make sure we do not try to access element beyond bounds of A
        if (i < aSize)
        {
            const int currentAValue = *aIterator;
            // Test if value is already in map, if yes return true
            if (m[currentAValue])
            {
                return true;
            }
            // Add new value to map
            m[currentAValue] = true;
            ++aIterator;
        }
        // Make sure we do not try to access element beyond bounds of B
        if (i < bSize)
        {
            const int currentBValue = *bIterator;
            // Test if value is already in map, if yes return true
            if (m[currentBValue])
            {
                return true;
            }
            // Add new value to map
            m[currentBValue] = true;
            ++bIterator;
        }
    }
    return false;
}

/*
    Take two lists and merge the smaller one into the bigger one. 
    Returns a boolean, true if merge successful, false if merge could not be completed
*/
bool merge2(list<int> &a, list<int> &b)
{
    if (!connComponent(a, b))
    {
        return false;
    }
    const int aSize = a.size();
    const int bSize = b.size();

    // Determine which list we will merge into
    list<int> &listMergingTo = aSize < bSize ? b : a;
    list<int> &listMergingFrom = aSize < bSize ? a : b;

    for (auto from = listMergingFrom.begin(); from != listMergingFrom.end(); ++from)
    {
        const int i = *from;
        list<int>::iterator g = find_gt(listMergingTo.begin(), listMergingTo.end(), i);
        listMergingTo.insert(g, i);
    }
    // Make the merged list unique
    listMergingTo.unique();
    // Clear out old list
    listMergingFrom.clear();
    return true;
}

int main()
{
    vector<list<int>> adjList;

    readData([&](string &line) {
        list<int> tempList;

        std::istringstream iss(line);
        for (std::string s; iss >> s;)
        {
            // Convert string to an int
            int i = std::stoi(s);
            if (tempList.size() == 0)
            {
                tempList.push_back(i);
            }
            else
            {
                list<int>::iterator g = find_gt(tempList.begin(), tempList.end(), i);
                tempList.insert(g, i);
            }
        }
        adjList.push_back(tempList);
    });

    print(adjList);

    int inId1 = -2;
    int inId2 = -2;

    while (true)
    {
        cout << "Enter two list ids to potentially merge together or -1 to quit:";
        cin >> inId1;
        if (inId1 == -1)
        {
            break;
        }
        cin >> inId2;
        if (inId2 == -1)
        {
            break;
        }
        const int adjListSize = adjList.size();
        if (inId1 > adjListSize - 1 || inId2 > adjListSize - 1)
        {
            cout << "One of the inputed ids is larger than allowed. Max input: " << adjListSize - 1 << "\n";
        }
        else
        {
            list<int> &list1 = adjList.at(inId1);
            list<int> &list2 = adjList.at(inId2);
            const bool merged = merge2(list1, list2);
            cout << "The lists are " << (merged ? "" : "not ") << "merged."
                 << "\n";
            if (merged)
            {
                // Loop over the adjList to remove any list elements that no longer have any values
                for (vector<list<int>>::iterator vectorListElement = adjList.begin(); vectorListElement != adjList.end(); ++vectorListElement)
                {
                    if (vectorListElement->size() == 0)
                    {
                        // Remove from adjList
                        adjList.erase(vectorListElement);
                        break;
                    }
                }
            }
            print(adjList);
        }
    }
}
