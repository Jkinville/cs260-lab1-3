//============================================================================
// Name        : Lab1-3.cpp
// Author      : Johnathon Kinville
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>



using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================
//I needed to put the function signature here so it can be used before another function later on.
double strToDouble(string str, char ch);

// Since we only need the data for our data structure and not the related functions I used a struct containing the data
struct bidInformation{
	string name;
	string fund;
	string vechicleID;
	double bidAmnt;

	//constructor for bidInformation
	bidInformation(){
		bidAmnt = 0;
	}
};

/**
 * Display the bid information
 *
 * @param ?type? data structure containing the bid info
 */
//I simply passed the bidInformation object from main and used its fields to get the desired output
void displayBid(bidInformation currentBid){
    cout << "Title: " << currentBid.name << endl;
    cout << "Fund: " << currentBid.fund << endl;
    cout << "Vehicle: " << currentBid.vechicleID << endl;
    cout << "Bid Amount: " << currentBid.bidAmnt << endl;

    return;
}

/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
/*Since I want this to set the values for a bidInformation object I set the return type as that, instantiated it
and set the correct fields for the values to be entered into*/
bidInformation getBid() {

	bidInformation currentBid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, currentBid.name);

    cout << "Enter fund: ";
    cin >> currentBid.fund;

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, currentBid.vechicleID);

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    currentBid.bidAmnt = strToDouble(strAmount, '$');

    return currentBid;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


/**
 * The one and only main() method
 */
int main() {

    //create an instanced of bidInformation to hold the data returned from the setter functions.
	bidInformation currentBid;

    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // FIXME (5): Complete the method calls then test the program
        switch (choice) {
            case 1:
            	currentBid = getBid();
                break;
            case 2:
                displayBid(currentBid);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
