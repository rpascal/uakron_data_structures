/*
    Ryan Pascal
    Data Structures
    Project 2
*/

#include "./Employee/Employee.h"
#include "./empmaps/empmaps.h"
#include <unordered_map>
#include <ctime>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::unordered_map;
using std::vector;

int main()
{
    // Define clock variable which will be used for timing
    clock_t start, stop;

    // Get employees from data file
    vector<Employee> emps = employees();
    cout << "Number of employees: " << emps.size() << endl;

    // Start the clock, build the map of employees, output time taken
    start = clock();
    map<int, vector<Employee>> mapEmps = mapEmpDept(emps);
    stop = clock();
    cout << "ORDERED Map creation with department as key clock ticks: " << double(stop - start) << endl;
    cout << "ORDERED Map number of departments: " << mapEmps.size() << endl;

    // Start the clock, build the map of employees by salary, output time taken
    start = clock();
    map<int, vector<Employee>> mapEmpsSalRange = mapSalRange(emps);
    stop = clock();
    cout << "ORDERED Map creation with salary as key clock ticks: " << double(stop - start) << endl;
    cout << "ORDERED Map number of salary ranges: " << mapEmpsSalRange.size() << endl;

    // Print salary ranges and emps in ranges
    printSalRange(mapEmpsSalRange);
    
    cout << endl;

    // Start the clock, build the unordered map of employees, output time taken
    start = clock();
    unordered_map<int, vector<Employee>> unOrderedMapEmps = umapEmpDept(emps);
    stop = clock();
    cout << "UNORDERED Map creation with department as key clock ticks:" << double(stop - start) << endl;
    cout << "UNORDERED Map number of departments: " << unOrderedMapEmps.size() << endl;

    // Start the clock, build the unordered map of employees by salary, output time taken
    start = clock();
    unordered_map<int, vector<Employee>> unOrderedMapEmpsRange = umapSalRange(emps);
    stop = clock();
    cout << "UNORDERED Map creation with salary as key clock ticks: " << double(stop - start) << endl;
    cout << "UNORDERED Map number of salary ranges: " << unOrderedMapEmpsRange.size() << endl;

    // Print salary ranges and emps in ranges
    uprintSalRange(unOrderedMapEmpsRange);
}
