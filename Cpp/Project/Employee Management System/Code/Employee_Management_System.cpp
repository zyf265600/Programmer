#include <iostream>
#include <regex>
#include "EmployeeManager.h"
#include "Input_Tester.h"
#include "Employee.h"
#include "Staff.h"
#include "Manager.h"
#include "CEO.h"

using namespace std;

int main()
{
    Employee * employee1 = NULL;
	employee1 = new Staff(1, "张三", 1);
	employee1->showInfo();
	delete employee1;

    Employee * employee2 = NULL;
	employee2 = new Manager(1, "张四", 1);
	employee2->showInfo();
	delete employee2;

    Employee * employee3 = NULL;
	employee3 = new CEO(1, "张五");
	employee3->showInfo();
	delete employee3;



    // EmpolyeeManager em; // init manager object
    // int choice; // init function choice variable

    // // create and show menu interface until user shut down the system
    // while (true)
    // {
    //     // show menu
    //     em.showMenu();

    //     choice = inputCommandTester(em); //check the invalidation of input from user

    //     // set up all action according to specific command
    //     switch (choice)
    //     {
    //     case 0: // Exit the System
    //         em.exitSystem();
    //         break;

    //     case 1: // Add New Employee

    //         break;

    //     case 2: // Employee Information

    //         break;

    //     case 3: // Delete Employee

    //         break;

    //     case 4: // Motify Employee

    //         break;

    //     case 5: // Find Employee

    //         break;

    //     case 6: // Sort the Employee

    //         break;

    //     case 7: // Clear the System

    //         break;

    //     default: // input must be invalid, ask user try again
    //         cout << "Invalid Command, Please Try AGAIN!" << endl;
    //         cout << endl;
    //         break;
    //     }
    // }

    return 0;
}