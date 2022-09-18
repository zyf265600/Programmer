#pragma once
#include <iostream>
using namespace std;
#include "Employee.h"

class Manager : public Employee
{
public:
    // constructor
    Manager(int id, string name, int dept);

    // Show Manager Information
    virtual void showInfo();

    // Show Department Information
    virtual string getDeptName();

    ~Manager ();
};