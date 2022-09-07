#include "EmployeeManager.h"

// constructor definition
EmpolyeeManager::EmpolyeeManager()
{
}

// show menu
void EmpolyeeManager::showMenu()
{
    cout << "***************************************************" << endl;
    cout << "----   Welcome to Employee Management System   ----" << endl;
    cout << "**************  0. Exit the System       **********" << endl;
    cout << "**************  1. Add New Employee      **********" << endl;
    cout << "**************  2. Employee Information  **********" << endl;
    cout << "**************  3. Delete Employee       **********" << endl;
    cout << "**************  4. Motify Employee       **********" << endl;
    cout << "**************  5. Find Employee         **********" << endl;
    cout << "**************  6. Sort the Employee     **********" << endl;
    cout << "**************  7. Clear the System      **********" << endl;
    cout << "***************************************************" << endl;
    cout << endl;
}

// destructor definition
EmpolyeeManager::~EmpolyeeManager()
{
}
