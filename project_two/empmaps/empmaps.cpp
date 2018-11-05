/*
    Ryan Pascal
    Data Structures
    Project 2
*/

#include "empmaps.h"

#include "../Employee/Employee.h"
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
using std::map;
using std::string;
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
        if (line.length() > 0)
        {
            lineCallback(line);
        }
    }
}

/*
    Read data file and build a vector of Employees
*/
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
        // Create an employee from the data line
        Employee emp(std::stoi(identifier), last_name, std::stoi(salary));
        emps.push_back(emp);
    });
    return emps;
}

/*
    Build a map of Employees from the vector of employees 
    based on the department id
*/
map<int, vector<Employee>> mapEmpDept(vector<Employee> &emp)
{

    map<int, vector<Employee>> empMap;
    for (int i = 0; i < emp.size(); ++i)
    {
        // Extract out the department id and insert
        empMap[emp[i].id() / 100].push_back(emp[i]);
    }
    return empMap;
}

/*
    Build a map of Employees from the vector of employees 
    based on salary range
*/
map<int, vector<Employee>> mapSalRange(vector<Employee> &emp)
{
    map<int, vector<Employee>> empMap;
    for (int i = 0; i < emp.size(); ++i)
    {
        // Extract the salary range and insert
        int rangeLower = emp[i].sal() / 10000;
        int trueRange = rangeLower * 10000;
        empMap[trueRange].push_back(emp[i]);
    }
    return empMap;
}

/*
    Print the map of salary ranges
    Determine which range has the most employees
*/
void printSalRange(map<int, vector<Employee>> &salRange)
{
    int largestSize = 0;
    int largestGrouping = 0;

    for (auto i = salRange.begin(); i != salRange.end(); ++i)
    {
        int empCount = i->second.size();
        int groupCount = i->first;
        cout << "ORDERED Map Salary Range " << groupCount << " contains " << empCount << endl;
        // Check to see if we found a range with more employees
        if (empCount > largestSize)
        {
            largestGrouping = groupCount;
            largestSize = empCount;
        }
    }

    cout << "ORDERED Map Salary Range with most employees: " << largestGrouping << " containing " << largestSize << " employees" << endl;
}

/*
    Build a unordered map of Employees from the vector of employees 
    based on the department id
*/
unordered_map<int, vector<Employee>> umapEmpDept(vector<Employee> &emp)
{
    unordered_map<int, vector<Employee>> empMap;
    for (int i = 0; i < emp.size(); ++i)
    {
        empMap[emp[i].id() / 100].push_back(emp[i]);
    }
    return empMap;
}

/*
    Build a unordered map of Employees from the vector of employees 
    based on salary range
*/
unordered_map<int, vector<Employee>> umapSalRange(vector<Employee> &emp)
{
    unordered_map<int, vector<Employee>> empMap;
    for (int i = 0; i < emp.size(); ++i)
    {
        int rangeLower = emp[i].sal() / 10000;
        int trueRange = rangeLower * 10000;
        empMap[trueRange].push_back(emp[i]);
    }
    return empMap;
}

/*
    Print the unordered map of salary ranges
    Determine which range has the most employees
*/
void uprintSalRange(unordered_map<int, vector<Employee>> &salRange)
{
    int largestSize = 0;
    int largestGrouping = 0;

    for (auto i = salRange.begin(); i != salRange.end(); ++i)
    {
        int empCount = i->second.size();
        int groupCount = i->first;
        cout << "UNORDERED Map Salary Range " << groupCount << " contains " << empCount << endl;
        // Check to see if we found a range with more employees
        if (empCount > largestSize)
        {
            largestGrouping = groupCount;
            largestSize = empCount;
        }
    }

    cout << "UNORDERED Map Salary Range with most employees: " << largestGrouping << " containing " << largestSize << " employees" << endl;
}
