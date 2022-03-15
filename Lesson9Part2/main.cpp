/*
 Ifrit Maruf
 CS 1136.112
 Lesson 9 Part 2
 The purpose of this program is too create multiple functions to calculate the future value.
 */

#include <iostream>
#include <fstream> //This is for files
#include <cmath> //This is for pow function
#include<iomanip> //This is for set precision
using namespace std;

//This function is for reading in the data
int readIn(ifstream&,double&, double&, int&);
//This function is for calculating future value
double calculateFutureValue(double presentValue, double interestRate, int months);
//This function is to display
void display(ofstream&, double&, double&, double&, int&);

int main()
{
    //Define stream for inputFile
    ifstream inputFile;
    //Define stream for outputFile
    ofstream outputFile;
    //Declare filename
    string filename;
    //Enter in filename
    cin >> filename;
    //Open the inputFile
    inputFile.open (filename);
    if(inputFile){
        outputFile.open("output.xls"); //Open outputFile if inputFile opens properly
        if(outputFile)
        {
            //Declare variables
            double presentValue, interestRate, futureValue;
            int months,val;
            
            //Write to the file
            outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;
            
            //Set precision
            outputFile <<fixed <<setprecision(2);
            cout <<fixed << setprecision(2);
           
            //Call the function
            while( (val = readIn(inputFile,presentValue, interestRate, months)))
            {
                if(val == 1)
                {
                    //Call function and set it to futureValue
                    futureValue=calculateFutureValue(presentValue,interestRate/100.0, months);
                    //Call function
                    display(outputFile,futureValue, presentValue, interestRate, months);
                }
                else if(val == 2)
                {
                    //Negative values
                    cout <<fixed << presentValue << " " << interestRate << " " << months <<endl;
                    cout << "One or more of the above values are not greater than zero" << endl;
                }
            }
            //Close the file
            outputFile.close();
        }
        else
        {
            //File could not be opened
            cout << "File output.xls could not be opened" << endl;
        }
        //Close the file
        inputFile.close();
    }
    else
    {
        //File could not be opened
        cout << "File \"" << filename << "\" could not be opened" << endl;
    }
    //End the program
    return 0;
        
}

//Read in function
    int readIn(ifstream &inputFile, double &presentValue, double &interestRate, int &months)
    {
        //Define and initialize ret
        int ret =0 ;
        if(inputFile >> presentValue >> interestRate >> months){
            if (presentValue <=0.0 || interestRate<=0.0 ||months <=0){
                ret =2; //If any of the values are negative or 0
            }
            else{
                ret = 1; //If all the values are positive
            }
            
        }
        //Return ret
        return ret;
    }
//Calculation function
    double calculateFutureValue(double presentValue, double interestRate, int months)
    {
        //Declare the variable
        double futureValue;
        //Calculate future value
        futureValue = presentValue * pow((1 + interestRate),months);
        //Return future value
        return futureValue;
    }

//Display function
void display(ofstream& outputFile, double &futureValue, double &presentValue, double &interestRate, int &months)
    {
        //Write the future value, present value, interest rate, and months to the outputFile
        outputFile <<fixed << futureValue << "\t" << presentValue << "\t" << interestRate << "\t" << months << endl;
    }

