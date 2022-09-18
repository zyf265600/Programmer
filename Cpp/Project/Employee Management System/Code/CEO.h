#pragma once
#include <iostream>
using namespace std;
#include "Employee.h"

class CEO : public Employee
{
public:
    // constructor
    CEO(int id, string name);

    // Show Staff Information
    virtual void showInfo();

    // Show Department Information
    virtual string getDeptName();

    ~CEO ();
};