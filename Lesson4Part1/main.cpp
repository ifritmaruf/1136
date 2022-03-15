//  main.cpp
//  lesson4part1
//
//  Created by Ifrit Maruf on 10/5/18.
//  Copyright © 2018 Ifrit Maruf. All rights reserved.
//

// The purpose of this program is to create a C++ program that reads the mass of an object

#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    //These are the variables
    const double earthGravity =9.81, moonGravity =1.62, venusGravity=8.87;
    double mass, weightEarth, weightMoon, weightVenus;
    
    cout << setprecision(4) << fixed;
    
    cin >> mass;
    
    //This calculates the weight of Earth, Moon, and Venus
    weightEarth= mass * earthGravity;
    weightMoon= mass * moonGravity;
    weightVenus= mass * venusGravity;
    
    //This is the if else statement that also displays the data
    if (mass > 0)
    {
        if (weightEarth >= 1500)
        {
            cout << "The mass is " << mass << " kg" << endl;
            cout << setw(8) << left << "Location" << setw(14) << right << "Weight (N)" << endl;
            cout << setw(8) << left << "Earth" << setw(14) << right << weightEarth << endl;
            cout << setw(8) << left << "Moon" << setw(14) << right << weightMoon << endl;
            cout << setw(8) << left << "Venus" << setw(14) << right << weightVenus << endl;
            cout << "The object is heavy" << endl;
        }
        else if (weightEarth < 5)
        {
            cout << "The mass is " << mass << " kg" << endl;
            cout << setw(8) << left << "Location" << setw(14) << right << "Weight (N)" << endl;
            cout << setw(8) << left << "Earth" << setw(14) << right << weightEarth << endl;
            cout << setw(8) << left << "Moon" << setw(14) << right << weightMoon << endl;
            cout << setw(8) << left << "Venus" << setw(14) << right << weightVenus << endl;
            cout << "The object is light" << endl;
        }
        else
        {
        cout << "The mass is " << mass << " kg" << endl;
        cout << setw(8) << left << "Location" << setw(14) << right << "Weight (N)" << endl;
        cout << setw(8) << left << "Earth" << setw(14) << right << weightEarth << endl;
        cout << setw(8) << left << "Moon" << setw(14) << right << weightMoon << endl;
        cout << setw(8) << left << "Venus" << setw(14) << right << weightVenus << endl;
        }
    }
    else
        {
            cout << "The mass is " << mass << " kg" << endl;
            cout << "The mass must be greater than zero" << endl;
        }
    return 0;
}
