#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

bool authentication(string name, int pin)
{
    bool yes = false;
    int count2 = 0;
    string username;
    int pin2;
    ifstream file2("accounts.csv");
    if (file2.is_open())
    {

        while (!file2.eof())
        {
            if (count2 == 0)

            {
                string temp;
                getline(file2, temp);
                count2 = 1;
            }
            else
            {
                getline(file2, username, ',');

                file2 >> pin2;
                string temp2;
                getline(file2, temp2, '\n');
                if (name == username && pin == pin2)
                {
                    yes = true;
                }
            }
        }
        return yes;
    }
    else
    {
        cout << "error" << endl;
        return yes;
    }
}