/*
 Ifrit Maruf
 Lesson 10 Part 1
 Due: 12/09/18
 The purpose of the program is tocompare the student's answers with the
 correct answers, and determine if the student passed the quiz or not.
 */

#include <iostream>
#include <fstream> //Header for files
using namespace std;

bool readIn(char [], int, string); //Function for reading in the file
void display(char [], char [], int);

int main()
{
    //Declare array size
    const int SIZE=20;
    //Declare arrays
    char student[SIZE];
    char answers[SIZE];
    //Define the filename the user is entering
    string fileName;
    
    //Get the student filename from the user
    cin >> fileName;
    
    //Call the function for the student answers
    bool readStu = readIn(student, SIZE, fileName);
    
    //Get the answer filename from the user
    cin >> fileName;
    
    //Call the function for the answers
    bool readAns = readIn(answers, SIZE, fileName);
    
    //If both files are read properly
    if (readStu==true && readAns==true)
    {
        //Call the function
        display(student, answers, SIZE);
    }
    
    return 0; //End the program
}

bool readIn(char newarr[], int size, string file)
{
    //Define stream for inputFile
    ifstream inputFile;
    //Open the file
    inputFile.open(file);
    
    //Declare the variable
    bool value;
    //If the file opens
    if(inputFile)
    {
        for (int index = 0; index < size; index++)
        {
            //Enter data into array from the file
            inputFile >> newarr[index];
        }
            
        value = true;
    }
    else //If the file does not open
    {
        cout << "File " << "\"" << file << "\" could not be opened" << endl;
        value = false;
    }
    //Close the file
    inputFile.close();
    
    //Return the value
    return value;
}

void display (char stud[], char ans[], int size)
{
    //Declare variables
    int totalCorrect=0;
    int totalIncorrect=0;
    double grade;
    
    for (int index = 0; index < size; index++)
    {
        if (stud[index]==ans[index])
        {
            totalCorrect++; //If student is correct
        }
        else
        {
            totalIncorrect++; //If student is incorrect
            //Display incorrect answer and correct answer
            cout << "Question " <<(index+1) << " has incorrect answer '" << stud[index];
            cout << "', the correct answer is '" << ans[index] <<"'"<< endl;
        }
    }
    //Calculate grade
    grade = (double)( (20 - totalIncorrect) / (20.0) ) * 100;
   
    //Display how many questions were missed
    cout << totalIncorrect << " questions were missed" << endl;
    if (grade >= 70.0)
    {
        cout << "The student passed" << endl; //If grade is 70 or over
    }
    else
    {
        cout << "The student failed" << endl; //If grade is less than 70
    }
}


    
    


    
    
    
