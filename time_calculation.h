#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void time(int mins)
{
    int seconds, hours, days;

    int minutes = mins;
    hours = minutes / 60;
    days = hours / 24;
    if (hours < 24)

    {
        cout << "Time for delivery is : " << endl;
        cout << int(hours) << " hours: " << int(minutes % 60) << "  minutes " << endl;
    }
    else if (hours >= 24 && hours < 48)
    {
        cout << "Time for delivery is : " << endl;
        cout << days << " day " << int(hours % 24) << " hours " << int(minutes % 60) << " minutes " << endl;
    }
    else if (hours > 24)
    {
        cout << "Timefor delivery is: " << endl;
        cout << days << " days " << int(hours % 24) << " hours " << int(minutes % 60) << " minutes " << endl;
    }
}

int minutes = 0, count_of_orders = 0;
void time_updation()
{
    ifstream time_file("time.csv");
    if (time_file.is_open())
    {
        time_file >> minutes;
        string temp;
        getline(time_file, temp, ',');
        time_file >> count_of_orders;
        if (minutes == 0 && count_of_orders == 0)
        {
            minutes = 30;
            count_of_orders = 1;
        }
        else if (minutes > 0 && (count_of_orders % 100) == 0)
        {
            minutes = minutes + 30;
            count_of_orders++;
        }
        else if (minutes > 0 && count_of_orders > 0)
        {
            count_of_orders++;
        }
        time_file.close();
        ofstream file("time.csv", ios ::out | ios::trunc);
        file << minutes << "," << count_of_orders;
        file.close();
    }
}