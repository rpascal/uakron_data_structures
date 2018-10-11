

/*
    Ryan Pascal
    Data Structures
    Project 2
*/

#ifndef EMPMAPS_H_INCLUDED
#define EMPMAPS_H_INCLUDED
#include <vector>
#include <map>
#include <unordered_map>
#include "../Employee/Employee.h"

using std::vector;
using std::map;
using std::unordered_map;

vector<Employee> employees();
map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp);
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp);
void printSalRange(map<int,vector<Employee>> & salRange);
unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp);
unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp);
void uprintSalRange(unordered_map<int,vector<Employee>> & salRange);


#endif // EMPMAPS_H_INCLUDED

