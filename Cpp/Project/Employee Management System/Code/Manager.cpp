#include "Manager.h"

// Manager constructor
Manager::Manager(int id, string name, int dept)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dept = dept;
}

// Show Manager Information
void Manager::showInfo()
{
    cout << "Employee ID Number: " << m_id << "\t";
    cout << "Employee Name: " << m_name << "\t";
    cout << "Employee Position: Manager" << "\t";
    cout << "Employee Department: " << getDeptName() << "\t";
    cout << "Employee Task: Achieve development goal assigned by CEO" << endl;
};

// Show Department Information
string Manager::getDeptName()
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

Manager::~Manager() {}