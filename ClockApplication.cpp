/* ClockApplication.cpp : Contains all methods for the Application. *
*  Written by Brian Cherry for SNHU CS-210 Class */

#include <iostream>
//Time functions
#include <time.h>
#include "functions.h"

//Required for Visual Studio to compile using Time functions. 
#pragma warning(disable : 4996) 
//Removes having to namespace the standard functions i.e. std::
using namespace std;

int main()
{
	//Used for the for loop to keep track if the user should still be within a loop.
	bool notDone = true;

	//Used to store the initial time and modified times based on user selections.
	time_t curr_time;
	tm* curr_tm;
	
	//Capturing the time and setting the curr_tm to the local time of the class.
	time(&curr_time);
	curr_tm = localtime(&curr_time);

	//Loops through the methods that hold the logic and actions of the interface.
	while (notDone != false) {
		//Display the Clocks UI.
		printClocks(curr_tm);
		//Display the Menu UI.
		printMenu();
		//Capture the choice and execute logic.
		choiceEntry(curr_tm, notDone);
	}
	return 0;
}

//Basic console print of the menu. Contains options 1-4.
void printMenu()
{
	cout << "\t\t***************************" << endl;
	cout << "\t\t* 1 - Add One Hour \t  *" << endl;
	cout << "\t\t* 2 - Add One Minute \t  *" << endl;
	cout << "\t\t* 3 - Add One Second \t  *" << endl;
	cout << "\t\t* 4 - Exit Progam \t  *" << endl;
	cout << "\t\t***************************" << endl;
	cout << "Choose an Option: ";
}

void printClocks(tm* curr_tm)
{
    //Char variables to capture time strings.
	char military_string[100], time_string[100];
	
	//These format the time object to the HH MM SS format in military and standard.
	strftime(time_string, 50, "%I:%M:%S %p", curr_tm);
	strftime(military_string, 50, "%H:%M:%S", curr_tm);

	//Start the printing of clock.
	cout << "**************************\t**************************" << endl;
	cout << "*\t 12-Hour Clock \t *\t" << "*\t 24-Hour Clock \t *" << endl;
	cout << "*\t   " << time_string << "\t *\t*" << "\t   " << military_string << "\t *" << endl;
	cout << "**************************\t**************************" << endl << endl;

	//Clears the memory of the chars.
	memset(military_string, 0, sizeof(military_string));
	memset(time_string,0, sizeof(time_string));
}

//Used to clear the string. Flushing out the cout then clearing via the system method.
void clear()
{
	cout << flush;
	system("CLS");
}

//This accepts the time object and returns it along with the while loop determining variable of notDone.
void choiceEntry(tm* &curr_tm, bool &notDone)
{
	int choice;
	cin >> choice;

	//Used to check for a valid number to prevent a char from crashing the program.
	while (!cin) 
	{
		// reset failbit
		cin.clear(); 
		//skip bad input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//Now that we have a valid choice, going through switch statement to 
	switch (choice)
	{
    //Choice to Add an hour
	case 1:
		curr_tm->tm_hour += 1;
		mktime(curr_tm);
		clear();
		break;
     //Choice to add a Minute
	case 2:
		curr_tm->tm_min += 1;
		mktime(curr_tm);
		clear();
		break;
	//Choice to add a Second.
	case 3:
		curr_tm->tm_sec += 1;
		mktime(curr_tm);
		clear();
		break;
	//Choice to quit.
	case 4:
		cout << "Goodbye.\n";
		notDone = false;
		break;
	//Invalid number choice,  restart the loop.
	default:
		cout << "Not a Valid Choice. \n";
		cout << "Choose again (Hit Enter to Continue)\n";
		system("PAUSE");
		clear();
		break;
	}
}