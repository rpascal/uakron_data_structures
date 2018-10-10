#include "./Employee/Employee.h"
#include "./empmaps/empmaps.h"
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
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::list;
using std::map;
using std::ofstream;
using std::string;
using std::unordered_map;
using std::vector;

int main()
{
    vector<Employee> emps = employees();

    cout << "Number of employees: " << emps.size() << endl;

    map<int, vector<Employee>> mapEmps = mapEmpDept(emps);

    unordered_map<int, vector<Employee>> mapEmps = umapEmpDept(emps);

    unordered_map<int, vector<Employee>> uEmp;
    for (int i = 0; i < emps.size(); ++i)
    {
        uEmp[emps[i].id() / 100].push_back(emps[i]);
    }

    cout << "Number of buckets in uEmp " << uEmp.size() << endl;

    for (auto i = uEmp.begin(); i != uEmp.end(); ++i)
        cout << "Dept " << i->first << " number of employees is " << i->second.size() << endl;
}
