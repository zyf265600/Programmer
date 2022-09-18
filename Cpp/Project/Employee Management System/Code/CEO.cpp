#include "CEO.h"

// CEO constructor
CEO::CEO(int id, string name)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dept = 0;
}

// Show CEO Information
void CEO::showInfo()
{
    cout << "Employee ID Number: " << m_id << "\t";
    cout << "Employee Name: " << m_name << "\t";
    cout << "Employee Position: CEO" << "\t\t";
    cout << "Employee Task: Managing the overall resources and operations"
         << " of a company, making major corporate decisions" << endl;
}

string CEO::getDeptName() {
    return "0";
}

CEO::~CEO() {}