
/*
 Ifrit Maruf
 CS 1136.112
 Lesson 8 Part 1
 The purpose of this program is to calculate the distance an object travels (in meters) on
 Earth for a specified number of seconds using the main function and three additional functions.
 */

#include <iostream>
#include <cmath> //Thisis for pow function
#include <iomanip> //This is for set precision

using namespace std;

double readSeconds()
{
    //Declare variable in function
    double seconds;
    cout << "Enter the time (in seconds)" << endl;
    //User enters seconds
    cin >> seconds;
    return seconds;
}

double calculateDistance(double seconds)
{
    //Declare variables for formula to find distance of Earth
    double distanceEarth;
    double GRAVITY= 9.8;
    //Calculate the distance of Earth
    distanceEarth= 0.5 * GRAVITY * pow(seconds,2);
    return distanceEarth;
}

//This does not return anything
void displayResults ( double seconds, double distance)
{
    //Display the distance and seconds the object traveled
    //Use set precision
    cout << "The object traveled " <<fixed << setprecision(3) << distance << " meters in " << fixed << setprecision(2) << seconds << " seconds" << endl;
}


int main ()
{
    //Declare variables
    double sec, distance;
    
    //Call the function
    sec= readSeconds();
    while (sec != 0){
        if (sec < 0)
        {
            //Seconds cannot be negative
            cout << "The time must be zero or more" << endl;
        }
        else if(sec > 0){
            //Call these functions
            distance= calculateDistance(sec);
            displayResults(sec,distance);
        }
        //Call the function again
        sec = readSeconds();
        
    }
    //End the program if user enters 0
    return 0;
    
    
}
