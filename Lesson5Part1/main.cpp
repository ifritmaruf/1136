/*
 Ifrit Maruf
 Cs 1136
 Lab 5 Part 1
 This C++ program will use switch and if statements to e calculating the
 number of seconds it will take for sound to travel though a medium
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    //This is the menu
    cout << "Select the medium that sound is traveling through:" << endl;
    cout << "1 Air" << endl;
    cout << "2 Water" << endl;
    cout << "3 Steel" << endl;
    
    //These are the variables
    unsigned int mediumChoice ;
    double distance, seconds, airSpeed, waterSpeed, steelSpeed;
    
    //These are the values that are assigned from the instructions
    airSpeed = 1100.0;
    waterSpeed = 4900.0;
    steelSpeed = 16400.0;
    
    //Set the setprecision to 3
    cout << setprecision(3) << fixed;
    
    //Enter the mediumChoice
    cin >> mediumChoice;
    
    //This is the swtich statment that will display the data you choose to display
    switch (mediumChoice)
    {
        case 1 :cout << "Enter distance (in feet)" << endl;
            cin >> distance;
            //Calculate the amount of seconds from distance and speed
            seconds = distance/airSpeed;
            
            if (distance <= 0)
            {
                cout << "The distance must be greater than zero" << endl;
            }
            else if (distance > 0)
            {
                cout << "Air: " << distance << " ft" << endl;
                cout << "Traveled for " << seconds << " seconds" << endl;
            }
            break;
            
        case 2 :cout << "Enter distance (in feet)" << endl;
            cin >> distance;
            //Calculate the amount of seconds from distance and speed
            seconds = distance/ waterSpeed;
            
            if (distance <= 0)
                
            {
                cout << "The distance must be greater than zero" << endl;
            }
            else if (distance > 0)
            {
                cout << "Water: " << distance << " ft" << endl;
                cout << "Traveled for " << seconds << " seconds" << endl;
            }
            break;
            
        case 3 : cout << "Enter distance (in feet)" << endl;
            cin >> distance;
            //Calculate the amount of seconds from distance and speed
            seconds = distance / steelSpeed;
            
            if (distance <= 0)
            {
                cout << "The distance must be greater than zero" << endl;
            }
            else if (distance > 0)
            {
                cout << "Steel: " << distance << " ft" << endl;
                cout << "Traveled for " << seconds << " seconds" << endl;
            }
            break;
            
            //This is if the user inputs 0 or a choice greater than 3
            
        default:
            cout << "The menu value is invalid. Please run the program again." << endl;
            
    }
    return 0;
    
}

