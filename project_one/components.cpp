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
    while (input.fail())
    {
        input.clear();
        cout << "Incorrect filename, please enter again: ";
        cin >> filename;
        input.open(filename.c_str());
    }
    string line;
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
list<int>::iterator gt(list<int>::iterator start, list<int>::iterator stop, int x)
{
    for (list<int>::iterator listElement = start; listElement != stop; ++listElement)
    {
        if (*listElement > x)
        {
            return listElement;
        }
    }
    return stop;
}

/*
    Find element in list that is one size larger than passed in int.
    If no element found passed in int must be smaller than all items in list
    therefore return start.
*/
void print(vector<list<int>> adjList)
{
    cout << "The adjacency list for your graph \n";
    for (vector<list<int>>::iterator vectorListElement = adjList.begin(); vectorListElement != adjList.end(); ++vectorListElement)
    {
        const int index = vectorListElement - adjList.begin();
        cout << "List " << index << ": ";
        for (auto listElement = vectorListElement->begin(); listElement != vectorListElement->end(); ++listElement)
        {
            cout << *listElement << ' ';
        }
        cout << '\n';
    }
}

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
        if (i < aSize)
        {
            const int currentAValue = *aIterator;
            if (m[currentAValue])
            {
                return true;
            }
            m[currentAValue] = true;
            ++aIterator;
        }
        if (i < bSize)
        {
            const int currentBValue = *bIterator;
            if (m[currentBValue])
            {
                return true;
            }
            m[currentBValue] = true;
            ++bIterator;
        }
    }
    return false;
}

bool merge2(list<int> &a, list<int> &b)
{
    if (!connComponent(a, b))
    {
        return false;
    }
    const int aSize = a.size();
    const int bSize = b.size();

    list<int> &listMergingTo = aSize < bSize ? b : a;
    list<int> &listMergingFrom = aSize < bSize ? a : b;

    for (auto from = listMergingFrom.begin(); from != listMergingFrom.end(); ++from)
    {
        const int i = *from;
        list<int>::iterator g = gt(listMergingTo.begin(), listMergingTo.end(), i);
        listMergingTo.insert(g, i);
    }
    listMergingTo.unique();
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
            int i = std::stoi(s);
            if (tempList.size() == 0)
            {
                tempList.push_back(i);
            }
            else
            {
                list<int>::iterator g = gt(tempList.begin(), tempList.end(), i);
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
                for (vector<list<int>>::iterator vectorListElement = adjList.begin(); vectorListElement != adjList.end(); ++vectorListElement)
                {
                    if (vectorListElement->size() == 0)
                    {
                        adjList.erase(vectorListElement);
                        break;
                    }
                }
            }
            print(adjList);
        }
    }
}
