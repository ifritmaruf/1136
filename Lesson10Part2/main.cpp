/*
 Ifrit Maruf
 Lesson 10 Part 2
 Due:12/9/18
 This purpose of this program will read the contents of a file into an array and calculate various values
 like average for each column and the lowest value in each row based on the contents of the file.
*/

#include <iostream>
#include <fstream> //Header for files
#include<iomanip> //Header for set precision
using namespace std;

//Declare global variable for column
const int MAX_COLUMNS=5;

//read input file and populate the array
int readFile(double values[][MAX_COLUMNS], int , string );

//for the array to calculate average of all values
double average(double values[][MAX_COLUMNS], int );

//for a array to calculate average for a specified column
double columnAverage(double values[][MAX_COLUMNS], int , int );

//for a arrat to find the smallest value in a specified row
double rowSmall(double values[][MAX_COLUMNS], int, int);

int main()
{
    //Declare variables
    const int rows=20;
    //Declare array
    double arr[rows][MAX_COLUMNS];
    
    //Define the filename the user is entering
    string fileName;
    
    //Get the student filename from the user
    cin >> fileName;
    
    //Call function of the readFile
    int actualRows= readFile(arr, rows, fileName);
    
   
    if (actualRows==-1)
    {
         //When value returns a -1
        cout << "File" <<"\"" << fileName << "\"could not be opened" << endl;
    }
    else if (actualRows==0)
    {
        //When value returns a 0
        cout <<"The input file" << "\"" << fileName<< "\" did not contain any data" << endl;
    }
    else
    {
         //When value returns anything but a 0 or a -1
        
        //Call the average function
        double avgerageAll = average(arr,actualRows);
        
        //Display how many rows and columns are in the file
        cout <<"Processing " << actualRows << " rows, and " << MAX_COLUMNS << " columns" << endl;
        //Set precision
        cout << fixed << showpoint << setprecision(2);
        //Display average for all values
        cout << "Average for all values is " << avgerageAll << endl;
        
        for (int col=0; col < MAX_COLUMNS; col++)
        {
            //Call columnAverage function for every column
            double avgCol= columnAverage(arr,col,actualRows);
            cout << fixed << showpoint << setprecision(2);
            //Display average for every column
            cout << "Average for column " << col << " is " << avgCol << endl;
        }
        for (int rowUsing=0; rowUsing < actualRows; rowUsing++)
        {
            //Call rowSmall function for every row
            double smallRow= rowSmall(arr, rowUsing, actualRows);
            //Set precision
            cout << fixed << showpoint << setprecision(2);
             //Display the smallest value for every row
            cout << "Smallest value for row " << rowUsing << " is " << smallRow << endl;
        }
            
    }
    //End the program
    return 0;
}

int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName)
{
    int value;
    
    //Define stream for inputFile
    ifstream inputFile;
    //Open the inputFile
    inputFile.open(inputFileName);
    
    //Declare variables
    int i =0, j = 0;
    
    if(inputFile)
    {
        //If the inputFile opens
        while( i < maxRows && j < MAX_COLUMNS && inputFile >>  values[i][j]){
            j++;
            if(j == 5){
                j = 0;
                i++;
            }
        }
        //Get i which is the rows from the for loop and set it to value
        value = i;
    }
    else
    {
        //If inputFile does not open
        value = -1;
    }
    //Close the inputFile
    inputFile.close();
    //Return value variable
    return value;
}

double average(double values[][MAX_COLUMNS], int numberRows)
    {
        //Declare variables
        double avg, total=0;
        int count = 0;
        for (int i = 0; i < numberRows; i++)
        {
            for ( int j=0; j< MAX_COLUMNS; j++)
            {
            total += values[i][j]; //Add to total
            count++; //Increment count
            }
        }
        //Calculate average for all values
        avg= total/count;
        //Return average for all values
        return avg;
    }

double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows)
{
    //Declare variable
    double colTotal=0;
    double colAvg;
    
    for (int row=0; row < numberRows; row++)
    {
        {
            colTotal += values[row][column]; //Add to the total for the specificed column
        }
    }
    //Calculate the specific columns average
    colAvg= (colTotal / numberRows);
    //Return the specific columns average
    return colAvg;
            
}

double rowSmall(double values[][MAX_COLUMNS], int rowEach, int numberRows)
{
    //Declare the small variable as the first element in the specified row
    double small= values[rowEach][0];
    
    for (int col=0; col < MAX_COLUMNS; col++)
    {
        if ( values[rowEach][col] < small)
        {
            //If the next element in the row is smaller set that to small variable
            small= values[rowEach][col];
        }
    }
    //Return small
    return small;
}

