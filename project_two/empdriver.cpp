#include <iostream>
#include <fstream>
#include "./Employee/Employee.h"
#include "./empmaps/empmaps.h"
#include <unordered_map>
#include <ctime>
#include <map>
#include <vector>


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::unordered_map;
using std::ifstream;
using std::ofstream;
using std::stringstream;

int main()
{
    Employee e1(101, "Samuel Adams", 1000);  // Samuel made only $1000 a year
    Employee e2(203, "Oprah Winfrey", 80000000);  // Oprah makes $80 million a year
    Employee e3(102, "George Washington", 100);  // George got $100 a year
    Employee e4(202, "George Clooney", 20000000);  // George got $20 million last year
    Employee e5(201, "Denzel Washington", 10000000);  // George got $10 million last year

    e1.print(cout);
    cout << endl;
    e2.print(cout);
    cout << endl;
    e3.print(cout);
    cout<<endl;

    vector<Employee> emp;
    emp.push_back(e1);
    emp.push_back(e2);
    emp.push_back(e3);
    emp.push_back(e4);
    emp.push_back(e5);
    cout << "Number of employees: "  << emp.size()<< endl;

    unordered_map<int,vector<Employee>> uEmp;
    for (int i = 0; i < emp.size(); ++i)
    {
        uEmp[emp[i].id()/100].push_back(emp[i]);
    }

    cout << "Number of buckets in uEmp " << uEmp.size() << endl;

    for (auto i = uEmp.begin(); i != uEmp.end(); ++i)
        cout << "Dept " << i->first << " number of employees is " << i->second.size() << endl;
}
