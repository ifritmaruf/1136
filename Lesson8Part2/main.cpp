/*
 Ifrit Maruf
 CS 1136.112
 Lesson 8 Part 1
 The purpose of this program is too create multiple functions to calculate the present value.
 */
#include <iostream>
#include<cmath> //This is for the pow function
#include <iomanip> //This is for set precision

using namespace std;

double calculatePresentValue(double futureValue, double interestRate, int numberYears)
{
    //Declare and calculate present value
    double presentValue= futureValue / (pow(1 + interestRate,numberYears));
    return presentValue;
}

//First read in function
double readFutureValue()
{
    //Declare variable
    double futureWorth;
    //Display asking user to enter future value
    cout << "Enter future value" << endl;
    //User enters future value
    cin >> futureWorth;
    
    return futureWorth;
}

//Second read in function
double readAnnualInterestRate()
{
    //Declare variable
    double yearlyInterestRate;
    //Display asking user to enter annual interest rate
    cout << "Enter annual interest rate" << endl;
    //User enters annual interest rate
    cin >> yearlyInterestRate;
    
    return yearlyInterestRate;
}

//Third read in function
int readYears()
{
    //Declare variable
    int year;
    //Display asking the user to enter in the years
    cout << "Enter number of years" << endl;
    //User enters in the years
    cin >> year;
    
    return year;
}

//Display functipn
void display(double presentValue, double futureValue, double interestRate, int numberYears)
{
    //Display the present value
    cout << "Present value: $" << fixed << setprecision(2)<< presentValue << endl;
    //Display the future value
    cout << "Future value: $" << fixed << setprecision(2) << futureValue << endl;
    //Display the annual interest rate
    cout << "Annual interest rate: " << fixed << setprecision(1) << interestRate << "%" << endl;
    //Display the years
    cout << "Years: " << numberYears << endl;
}

//Main function
int main()
    {
        //Declare variables
        double presentValue, futureValue, yearlyInterestRate;
        int year;
        
        //Call the function
        futureValue = readFutureValue();
        while (futureValue<=0)
        {
            //Future value cannot be negative
            cout << "The future value must be greater than zero" << endl;
            //Call the function again
            futureValue = readFutureValue();
        }
        
        //Call the function
        yearlyInterestRate = readAnnualInterestRate();
        while (yearlyInterestRate <=0)
        {
            //Annual interest rate cannot be negative
            cout << "The annual interest rate must be greater than zero" << endl;
            //Call the function again
            yearlyInterestRate = readAnnualInterestRate();
        }
        
        //Call the function
        year = readYears();
        while (year<=0)
        {
            //Years cannot be negative
            cout << "The number of years must be greater than zero" << endl;
            year=readYears();
        }
        
        presentValue = calculatePresentValue(futureValue, yearlyInterestRate/100, year);
        display(presentValue, futureValue, yearlyInterestRate, year);
        
        //End the program
        return 0;
            }
