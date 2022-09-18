#pragma once
#include <iostream>
using namespace std;

// Abstract class of all employees
class Employee
{

public:

    // Show Employee Information
    virtual void showInfo() = 0;

    // Show Department Information
    virtual string getDeptName() = 0;

    // // getter of Employee ID Number
    // int getID() {}

    // // getter of Employee Name
    // string getName() {}

    // // setter of Employee Name
    // void setName(string name) {}

    // // getter of Department Number
    // int getDept() {}

    // // setter of Department Number
    // void setDept(int dept) {}

    virtual ~Employee();

public:
    // Employee ID Number
    int m_id;

    // Employee Name
    string m_name;

    // Department Number
    int m_dept;
};