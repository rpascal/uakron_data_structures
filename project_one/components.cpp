#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <functional>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::list;
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
}
