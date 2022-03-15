/*
 Ifrit Maruf
 CS 1136.112
 Lesson 6 Part 2
 The purpose of this C++ program is to convert a set of temperatures from fahrenheit to celsius
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main ()

{
    //Declare variables
    double fahren1, fahren2, increment, celsius;
    
    //Get data by imputting it
    cin >> fahren1;
    cin >> fahren2;
    cin >> increment;
    
    //Diplay 5 digits of precision
    cout << setprecision (5) << fixed;
    
    // Check the input validation
    while ((fahren1 > fahren2) || (increment <= 0))
    {
        //Display the error message until valid values are imputed
        cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl;
        
        //Get data again until valid values are imputed
        cin >> fahren1;
        cin >> fahren2;
        cin >> increment;
    }
    //Display the header for the conversion
    cout << setw(18) << "Fahrenheit" << setw(18) << "Celsius" << endl;
    
    //Display the conversion until it reaches the second fahrenheit value
    while (fahren1 <= fahren2 && (increment > 0.0 ))
    {
        //Calculate the celsius
        celsius = (fahren1-32) / 1.8;
        
        //Display the conversion values for Fahrenheit and Celsius
        cout << setw(18) << fahren1 << setw(18) << celsius << endl;
        
        //Calculate the fahrenheit with the increment value
        fahren1 = fahren1 + increment;
    }
    return 0;
    
}
