#include "empmaps.h"

#include "../Employee/Employee.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <ctime>
#include <map>
#include <vector>
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
using std::map;
using std::ofstream;
using std::string;
using std::stringstream;
using std::unordered_map;
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
        lineCallback(line);
    }
}

vector<Employee> employees()
{
    vector<Employee> emps;

    readData([&](string &line) {
        std::istringstream iss(line);
        string identifier;
        iss >> identifier;
        string last_name;
        iss >> last_name;
        string salary;
        iss >> salary;

        Employee emp(std::stoi(identifier), last_name, std::stoi(salary));
        emps.push_back(emp);
    });
    return emps;
}

map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp){

    map<int, vector<Employee>> empMap;
    for (int i = 0; i < emp.size(); ++i)
    {
        empMap[emp[i].id() / 100].push_back(emp[i]);
    }
    return empMap;

}

// map<int,vector<Employee>> mapSalRange(vector<Employee> & emp);
// void printSalRange(map<int,vector<Employee>> & salRange);
// unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp);
// unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp);
// void uprintSalRange(unordered_map<int,vector<Employee>> & salRange);
