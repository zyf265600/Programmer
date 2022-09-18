#pragma once
#include <iostream>
using namespace std;
#include "Employee.h"

class Staff : public Employee
{
public:
    // constructor
    Staff(int id, string name, int dept);

    // Show Staff Information
    virtual void showInfo();

    // Show Department Information
    virtual string getDeptName();

    ~Staff ();
};