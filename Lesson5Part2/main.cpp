/*
 Ifrit Maruf
 CS 1136
 Lesson 5 Part 2
 The purpose of this C++ program is to read in the number of seconds and then calculating how far
 sound can travel in a specified medium in that many seconds through if/else/else if statements.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main ()

{
    //Variables
    unsigned int menuNumber;
    double seconds, distance, speedCarbon, speedAir, speedHelium, speedHydrogen;
    
    //Assign values to the variables
    speedCarbon= 258.0;
    speedAir= 331.5;
    speedHelium= 972.0;
    speedHydrogen= 1270.0;
    
    //Display the menu
    cout << "Select the medium that sound is traveling through:" << endl;
    cout << "1 Carbon Dioxide" << endl;
    cout << "2 Air" << endl;
    cout << "3 Helium" << endl;
    cout << "4 Hydrogen" << endl;
    
    //Choose a menu number
    cin >> menuNumber;
    
    //Display the seconds and distance of one of the menu numbers
    if ((menuNumber==0) || (menuNumber>4))
    {
        cout << "The menu value is invalid. Please run the program again." << endl;
    }
    else
    {
        //Since the menu is valid enter the seconds
        cout << "Enter time (in seconds)" << endl;
        cin >> seconds;
    }
    
    if ((seconds < 0) || (seconds > 30))
    {
        //The user did not enter a seconds value from 0-30
        cout << "The time must be between 0.00 and 30.00 (inclusive)" << endl;
    }
    else
    {
        //Since the menu value and the seconds is valid, the user can respond to the menu
        if (menuNumber==1)
        {
            //Calculate the distance for Carbon
            distance= seconds * speedCarbon;
            
            cout << setprecision(2)<< fixed;
            cout << "Carbon Dioxide: " << seconds << " seconds" << endl;
            
            cout << setprecision(3)<< fixed;
            cout << "Traveled " << distance << " meters" << endl;
        }
        else if (menuNumber==2)
        {
            //Calculate the distance for Air
            distance= seconds * speedAir;
            
            cout << setprecision(2)<< fixed;
            cout << "Air: " << seconds << " seconds" << endl;
            
            cout << setprecision(3)<< fixed;
            cout << "Traveled " << distance << " meters" << endl;
        }
        else if (menuNumber==3)
        {
            //Calculate the distance for Helium
            distance= seconds * speedHelium;
            
            cout << setprecision(2)<< fixed;
            cout << "Helium: " << seconds << " seconds" << endl;
            
            cout << setprecision(3)<< fixed;
            cout << "Traveled " << distance << " meters" << endl;
        }
        else if (menuNumber==4)
        {
            //Calculate the distance for Hydrogen
            distance= seconds * speedHydrogen;
            
            cout << setprecision(2)<< fixed;
            cout << "Hydrogen: " << seconds << " seconds" << endl;
            
            cout << setprecision(3)<< fixed;
            cout << "Traveled " << distance << " meters" << endl;
        }
    }
    return 0;
}//End main ()


