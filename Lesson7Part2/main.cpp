/*
 Ifrit Maruf
 CS 1136
 Lab 7 Part 2
 The purpose of this program is to read numbers from a file
 */

#include <iostream>
#include <fstream> //Header file for inputFile and outputFile
#include <string>
#include <iomanip>

using namespace std;

int main ()
{
    //Define stream for inputFile
    ifstream inputFile;
    //Define stream for outputFile
    ofstream outputFile;
    //Define the filename the user is entering
    string filename;
    
    //Declare variables
    int validValueCount=0, invalidValueCount=0, totalValueCount=0;
    double num, totalValid=0, avgValid;
    
    //Get the filename from the user
    cin >> filename;
    
    //Open the inputFile the user enters
    inputFile.open (filename);
    //Open the outputFile
    outputFile.open ("invalid-numbers.txt");
    
    //If inputfile correctly opens
    if (inputFile)
    {
        //Display what file this program is reading from
        cout << "Reading from file \"" << filename <<"\""<< endl;
        //Read the data from the file
        while ( inputFile >> num )
        {
            //Every num increases total value count
            totalValueCount++;
            
            //If the num is less than 0 or more than 110 it is invalid value count
            if ( (num <0) || (num > 110))
                {
                    invalidValueCount++;
                    //Write the input values to the file
                    outputFile << fixed << setprecision(4) <<num << endl;
                }
            else
            {
                //Calculate the total of the valid values
                totalValid += num;
                
                //If the num is from 0 to 110 inclusive it is valid value count
                validValueCount++;
            }
        }
            //Calculate the averahe of the valid values
            avgValid= totalValid/validValueCount;
        
            //Display total values
            cout << "Total values: " << totalValueCount << endl;
            //Display invalid values
            cout << "Invalid values: " << invalidValueCount << endl;
            //Display valid values
            cout << "Valid values: " << validValueCount << endl;
        
            //If there are no valid values
            if (validValueCount==0)
                cout << "An average cannot be calculated" << endl;
            //If there are at least one valid value
            else
                cout << fixed <<setprecision(3) << "Average of valid values: " << avgValid << endl;
        }
    //If inputfile does not correctly opens
    else
{
    cout << "File \"" << filename << "\" could not be opened" << endl;
    }
        return 0;
}

