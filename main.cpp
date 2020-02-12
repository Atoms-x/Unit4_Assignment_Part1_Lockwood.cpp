/*
	Input Validation with Ref Functions 
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c

	Teacher: Dr. Tyson McMillan, Ph.D. COSC 1436 
  STUDENT (McMillanite): Chet Lockwood
  Purpose: Math program and for loops
  IDE: Repl.it
*/

#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
#include <string> //for string manipulation
#include <sstream> //for string manipulation and comparison
#include <cmath> //for exponents (pow) and pi constant

//Main Function **********************************************************************************************
int main() 
{
  int counter = 0; //Accumulator variable
  double userInput = 0.0; //User input number

  //Color code variables, reset, and clear
  string cRed = "\x1b[1;91m";
  string cGreen = "\x1b[1;32m";
  string cYellow = "\x1b[1;93m";
  string cBlue = "\x1b[1;34m";
  string cOrange = "\x1b[1;33m";
  string cCyan = "\x1b[1;36m";
  string cPurple = "\x1b[1;35m";
  string cBGreen = "\x1b[1;102m\x1b[30m";
  string cBCyan = "\x1b[1;106m\x1b[30m";
  string cBYellow = "\x1b[1;103m\x1b[30m";
  string cItalic = "\x1b[3m";
  string cUnderL = "\x1b[4m";
  string cReset = "\x1b[0m";
  string cClear = "\033[2J\033[1;1H";

  //while loop to pretest for -1 to zero count iterations *****************************************************
  while (userInput != -1)
  {
    //Propmt user for input and give exit code
    cout << cUnderL << "\nInput a number for output and processing (-1 to exit)\n" 
    << cReset << endl;

    //Input and input validation
    validateDouble(userInput);

    //If statment to prevent division by 0   
    if (userInput == 0.0)
    {
      cout << cRed <<  "\nYou cannot divide by 0" << cReset << endl;
    }
    
    //Processing and Output for the input number
    else if (userInput != -1)
    {
      cout << cGreen << "\nYour number is " << cReset << userInput << endl;
      cout << cBlue << "\nYour number squared is " << cReset << pow(userInput, 2) << endl;
      cout << cYellow << "\nYour number divided by itself is " << cReset << (userInput / userInput) << endl;
      cout << cOrange << "\nAlso (" << userInput << " + 3)/5 = " << cReset << ((userInput +3)/5) <<endl;
      cout << cCyan << "\nAlso ((" << userInput << " + 3)/5) + (( " << userInput << " + 7)/2) = ";
      cout << cReset << (((userInput + 3.0)/5.0) + ((userInput + 7.0)/2.0)) << endl;
    }
    
    //An if rather than an else so that -1 does not trigger the statemnt
    if (userInput != -1)
    {
      cout << cItalic << "\nPress any key to repeat..." << cReset;
      cin.ignore(10000, '\n');
      cout << cClear;
      counter++;
    }
  }

  //Iteration counter if, else if, else chain to determine proper english **************************************
  if (counter == 0)
  cout << "\nThere was " << counter << " iterations"<< endl;
  
  else if (counter > 0 && counter < 2)
  cout << "\nThere was " << counter << " iteration"<< endl;

  else 
  cout << "\nThere were " << counter << " iterations"<< endl; 

  return 0;
}