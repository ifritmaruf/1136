/*
 Ifrit Maruf
 CS 1136
 Lab 7 Part 1
 The purpose of this program is to read in sales information from a file and write
 it out a bar chart for each of the stores.
 */

#include <iostream>
#include <fstream>
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
    
    //Declare variavles
    unsigned int storeNum;
    long long int storeData;
    
    //Get the filename from the user
    cin >> filename;
    
    //Open the inputFile the user enters
    inputFile.open (filename);
    //Open the outputFile
    outputFile.open ("saleschart.txt");
    
    //If the input file opens correcly
    if (inputFile)
    {
        //Write the header of the chart to the file
        outputFile << "SALES BAR CHART" << endl;
        outputFile << "(Each X equals 1,000 dollars)" << endl;
        
        while ( inputFile >> storeNum >> storeData)
        {
            //Check if the store number is valid
            if ( (storeNum< 1) || (storeNum > 99))
            {
            cout << "The store number " << storeNum << " is not valid" << endl;
                //Break out of the loop for this iteration
                continue;
            }
            //Check if the stored data is valid
            if ( storeData < 0 )
            {
                cout << "The sales value for store " << storeNum << " is negative" << endl;
                //Break out of the loop for this iteration
                continue;
            }
            //Write the store number to the file
            
            outputFile << "Store" << setw(3) << storeNum << ": ";
            
            for ( int barChart=1; barChart <= (storeData/1000); barChart++)
            {
                //Write an X to the chart for every 1000 store data
                outputFile << "X";
            }
            //Write on a new line after the for loop
            outputFile << endl;
            
        }
        //Close the input file
        inputFile.close();
        //Close the output file
        outputFile.close();
    
    }
    else
    {
        //The file does not open properly
        cout << "File \"" << filename << "\" could not be opened" << endl;
        //End the program
        return 0;
    }

    return 0;
    
}
