/*
 Ifrit Maruf
 CS 1136.112
 Lesson 9 Part 1
 The purpose of this program is to display the status of an order usong at least
 3 functions and main as one of the three and reading in from cin and writing to cout
 */

#include <iostream>
#include<iomanip> //This is for set precision
using namespace std;

int readin(int&, int&, double&); //Prototype for read in function
void display(int&, int&,  double&, double&, double&); //Prototype for void
           
int main()
{
    //Declare variables
    int orderSpools, spoolsStock, backOrder;
    double chargeShipping, subtotal, shippingCost, total;
    
    //Call the function
    readin(orderSpools, spoolsStock, chargeShipping);
    
    if (orderSpools> spoolsStock)
    {
    //Calculate backorder
    backOrder = orderSpools - spoolsStock;
    }
    else
    {
        spoolsStock=orderSpools; //Because then it would be negative
        backOrder = 0;
    }
    //Calculate subtotal
        subtotal = spoolsStock *100;
    //Calculate shipping cost
        shippingCost = spoolsStock * chargeShipping;
    //Calculate total with the shipping
        total= subtotal + shippingCost;
    //Call the function
        display(spoolsStock, backOrder, subtotal, shippingCost, total);
    return 0;
}

int readin(int &orderSpools, int &stockSpools, double &chargeShipping)
{
    //Declare variable
    char shippingDecision;
    
    //Ask user spools to be ordered
    cout << "Spools to be ordered" << endl;
    //Enter in spools needed to be ordered
    cin >> orderSpools;
    //If order of spools is 0 or less
    while (orderSpools <1)
    {
        cout << "Spools order must be 1 or more" << endl;
        //Enter in spools needed to be ordered again
        cout << "Spools to be ordered" << endl;
        //Enter in spools needed to be ordered again
        cin >> orderSpools;
    }
    
    //Ask user the spools in stock
    cout << "Spools in stock" << endl;
    //Enter in spools in stock
    cin >> stockSpools;
    //If spools in stock is negative
    while (stockSpools <0)
    {
        cout << "Spools in stock must be 0 or more" << endl;
         //Ask user the spools in stock again
        cout << "Spools in stock" << endl;
        //Enter in spools in stock again
        cin>> stockSpools;
    }
    
    //Ask user about shipping
    cout << "Special shipping and handling (y or n)" << endl;
    //Enter in shipping decision
    cin >> shippingDecision;
    if(shippingDecision == 'n')
    {
        //If shipping decision is no
        chargeShipping=11.88;
    }
    else if(shippingDecision == 'y')
    {
        //If shipping decision is yes ask user about shipping charge
        cout << "Shipping and handling amount" << endl;
        //Enter in shipping charge
        cin >> chargeShipping;
        //If shipping charge is negative
        while (chargeShipping <0)
        {
            cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
            //Ask user about shipping charge again
            cout << "Shipping and handling amount" << endl;
            //Enter in shipping charge again
            cin>> chargeShipping;
        }
    }
    //Return
    return 0;
}
 //This is the display function and does not return anything
void display(int &spoolsStock, int &backOrder, double &subtotal, double &shippingCost, double &total)
{
    //Display the data
    cout << "Spools ready to ship: " << spoolsStock << endl;
    cout << "Spools on back-order: " << backOrder << endl;
    cout << fixed << setprecision(2) << "Subtotal ready to ship: $ " << setw(9)<< subtotal << endl; 
    cout << "Shipping and handling:  $ " << setw(9) << shippingCost << endl;
    cout << "Total shipping charges: $ " << setw(9) <<  total << endl;
}
