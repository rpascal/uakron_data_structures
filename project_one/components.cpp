#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::getline;
using std::ifstream;
using std::list;
using std::string;
using std::vector;

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
list<int>::iterator gt(list<int>::iterator start, list<int>::iterator stop, int x)
{
}

void print(vector<list<int>> adjList)
{
    for (vector<list<int>>::iterator it = adjList.begin(); it != adjList.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            cout << *it2 << ' ';
        }
        cout << '\n';
    }
}


int main()
{
    vector<list<int>> adjList;

    readData([&](string &line) {
        list<int> tempList;
        for (string::iterator it = line.begin(); it != line.end(); ++it)
        {
            const char &c = *it;
            if (!isspace(c))
            {
                int i = c - '0';
                if (tempList.size() == 0)
                {
                    tempList.push_back(i);
                }
                else
                {
                    tempList.push_back(i);
                }
            }
        }
        adjList.push_back(tempList);
    });

    print(adjList);
}

