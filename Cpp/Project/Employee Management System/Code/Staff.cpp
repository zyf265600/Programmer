#include "Staff.h"

// Staff constructor
Staff::Staff(int id, string name, int dept)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dept = dept;
}

// Show Staff Information
void Staff::showInfo()
{
    cout << "Employee ID Number: " << m_id << "\t";
    cout << "Employee Name: " << m_name << "\t";
    cout << "Employee Position: Staff" << "\t";
    cout << "Employee Department: " << getDeptName() << "\t";
    cout << "Employee Task: Complete tasks assigned by manager in " << getDeptName() << endl;
};

// Show Department Information
string Staff::getDeptName()
{
    if (m_dept == 1)
    {
        return "Front-End Department";
    }
    else if (m_dept == 2)
    {
        return "Back-End Department";
    }
    else if (m_dept == 3)
    {
        return "Maintenance Department";
    }

    return string("Wrong Department Input!");
};

Staff::~Staff() {}