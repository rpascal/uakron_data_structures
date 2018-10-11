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
    clock_t start, stop;
    vector<Employee> emps = employees();

    cout << "Number of employees: " << emps.size() << endl;

    start = clock();
    map<int, vector<Employee>> mapEmps = mapEmpDept(emps);
    stop = clock();
    cout << "ORDERED Map creation with department as key clock ticks: " << double(stop - start) << endl;
    cout << "ORDERED Map number of departments: " << mapEmps.size() << endl;

    start = clock();
    map<int, vector<Employee>> mapEmpsSalRange = mapSalRange(emps);
    stop = clock();
    cout << "ORDERED Map creation with salary as key clock ticks: " << double(stop - start) << endl;
    cout << "ORDERED Map number of salary ranges: " << mapEmpsSalRange.size() << endl;

    printSalRange(mapEmpsSalRange);
    
    cout << endl;

    start = clock();
    unordered_map<int, vector<Employee>> unOrderedMapEmps = umapEmpDept(emps);
    stop = clock();
    cout << "UNORDERED Map creation with department as key clock ticks:" << double(stop - start) << endl;
    cout << "UNORDERED Map number of departments: " << unOrderedMapEmps.size() << endl;

    start = clock();
    unordered_map<int, vector<Employee>> unOrderedMapEmpsRange = umapSalRange(emps);
    stop = clock();
    cout << "UNORDERED Map creation with salary as key clock ticks: " << double(stop - start) << endl;
    cout << "UNORDERED Map number of salary ranges: " << unOrderedMapEmpsRange.size() << endl;

    uprintSalRange(unOrderedMapEmpsRange);
}
