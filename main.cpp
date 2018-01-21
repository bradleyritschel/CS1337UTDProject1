//
//  main.cpp
//  CS 1337 Project 1 V2
//
//  Created by Bradley Ritschel on 9/7/17.
//  Copyright © 2017 Bradley Ritschel. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
    char again = 'y'; // set initial value to 'y' to satisfy while loop condition
    while (toupper(again) == 'Y') // accept lowercase 'y' and uppercase 'Y' from user if they perform another calculation
    {
        
        //ask the user for the month, year, and total collected
        
        string month;
        cout << "Please enter the month: ";
        cin >> month;
        cout << "The month you entered is " << month << endl;
        
        int year;
        cout << "Please enter the year: ";
        cin >> year;
        while(!cin) // or if(cin.fail())
        {
            // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            // next, request user reinput
            cout << "Please enter a number: ";
            cin >> year;
        }
        cout << "The year you entered is " << year << endl;
        
        double totalCollected;
        cout << "Please enter the total collected: $";
        cin >> totalCollected;
        while(!cin) // or if(cin.fail())
        {
            // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            // next, request user reinput
            cout << "Please enter a number: ";
            cin >> totalCollected;
        }

        cout << "The total collected you entered is $" << setprecision(2) << fixed << totalCollected << endl;
        
        //calculate values
        
        double sales = totalCollected/1.0925;
        double countySalesTax = sales*0.0275;
        double stateSalesTax = sales*0.065;
        double totalSalesTax = countySalesTax + stateSalesTax;
        
        //display values
        
        cout << month << " " << year << "\n"
        << "Total Collected: $" << setprecision(2) << fixed << totalCollected << "\n"
        << "Sales: $" << setprecision(2) << fixed << sales << "\n"
        << "County Sales Tax: $" << setprecision(2) << fixed << countySalesTax << "\n"
        << "State Sales Tax: $" << setprecision(2) << fixed << stateSalesTax << "\n"
        << "Total Sales Tax: $" << setprecision(2) << fixed << totalSalesTax << "\n";
        
        //perform another calculation?
        
        cout << "Do you want to perform another calculation? (Y/N) ";
        cin >> again;
    }
    return 0;
};
