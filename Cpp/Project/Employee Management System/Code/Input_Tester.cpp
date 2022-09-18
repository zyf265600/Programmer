#include "Input_Tester.h"

// input format tester
bool integerTester(string str)
{
    regex r("[[:digit:]]{1}"); // check if the input command only contain one int number
    if ((regex_match(str, r)))
    {
        return true;
    }
    return false;
}

int inputCommandTester(EmpolyeeManager em)
{
    int choice = 0; // init function choice variable
    string sChoice; // init function choice variable in string

    // input command tester - only one int number is allowed
    while (true)
    {
        cout << "Please make your function choice: " << endl;
        cin >> sChoice; // get user's command number
        if (integerTester(sChoice))
        {
            choice = stoi(sChoice);
            return choice;
        }
        else
        {
            cout << "Invalid Command, Please Try AGAIN!" << endl;
            cout << endl;
            em.showMenu();
        }
    }
}
