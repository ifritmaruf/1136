
//
//  main.cpp
//  part 2 lab 4
//
//  Created by Ifrit Maruf on 10/6/18.
//  Copyright © 2018 Ifrit Maruf. All rights reserved.
//
// The purpose of this C++ program is to convert secondsto days, hours, minutes and remaining seconds.
#include <iostream>

using namespace std;

int main ()
{
    //These are the variables you are converting
    long long int second, minute, hour, day, remainder;
    
    //Enter in the seconds
    cin >> second;
    
    //Display the amount of seconds
    cout << "Total seconds: " << second << endl;
    cout << endl;
    
    if (second>0)
    {
        day= (second / 86400);
        remainder= (second % 86400);
        
        if ( day > 0)
        {
            cout << day << " day(s)" << endl;
        }
        if ((remainder / 3600) > 0)
        {
            hour = remainder / 3600;
            remainder = remainder % 3600;
            cout << hour << " hour(s)" << endl;
        }
        if ((remainder / 60) > 0 )
        {
            minute = remainder / 60;
            remainder = remainder % 60;
            cout << minute << " minute(s)" << endl;
        }
        if (remainder > 0)
        {
            second= remainder;
            cout << second << " second(s)" << endl;
        }
    }
    else
    {
        cout << "Total seconds must be greater than zero" << endl;
    }
    return 0;
}
