#include <iostream>
#include <string>																			//Included to use the ability of stoi to convert string to integers

using namespace std;

int main()
{
	int menuChoice = 0;
	string menuChoiceStr;																	//Inserted for the menu choice entered by the user
	string num1;																			//Inserted to be the values for user inputs
	string num2;																			//inserted to be the values for user inputs
	string menu1[] = { "1", "1)","1) Add","Add","add","ADD" };								//Array of possible menu choices for addition	
	string menu2[] = { "2", "2)","2) Subtract","Subtract","subtract","SUBTRACT"};			// array of possible menu choices for subtraction
	string menu3[] = { "3", "3)","3) Multiply","Multiply","multiply","MULTIPLY" };			//Array of possible menu choices for multiplication
	string menu4[] = { "4","4) Exit","Exit","exit","EXIT","4)" };							//Array of possible Exit Choices	
	bool foundChoice = false;
	int firstNumber;
	int secondNumber;
	int answer;

	while (menuChoice != 4)																	//Corrected from menuChoice != 5 since 4 is the proper exit function
	{

		cout << "----------------" << endl;
		cout << "Please type the number of the choice you would like:" << endl;				//add instruction line to avoid overflow error when non-integer entered
		cout << "- 1) Add - " << endl;
		cout << "- 2) Subtract -" << endl;
		cout << "- 3) Multiply -" << endl;
		cout << "- 4) Exit -" << endl;
		cout << "----------------" << endl;

		cin >> menuChoiceStr;																//Store user input as string in case user enters non-integer value
		

		for (int i = 0; i < 7; i++)															//For loop to check if user entered term is in array of acceptable terms, if it is set menuCHoice integer
			{
			if (menu1[i] == menuChoiceStr)
			{
				menuChoice = 1;
			}
			else if (menu2[i] == menuChoiceStr)
			{
				menuChoice = 2;
			}
			else if (menu3[i] == menuChoiceStr)
			{
				menuChoice = 3;
			}
			else if (menu4[i] == menuChoiceStr)
			{
				menuChoice = 4;
			}
		}
		
		if (menuChoice == 0)																//If search terms were not found keeps menuChoice at 0 and prints error
		{
			cout << "Invalid Choice Please Try Again" << endl;
		}
		
		if (menuChoice == 1)
		{
			
			cout << "Enter an Integer: ";													//Insert a prompt statement defining what the user needs to input for the data type
			cin >> num1;																	//store user input as string
			firstNumber = stoi(num1);														//converts user input to an integer to avoid overflows from decimal numbers
			cout << "Enter a second Integer: ";												//Insert a prompt statement defining what the user needs to input for the data type
			cin >> num2;																	//store user input as string
			secondNumber = stoi(num2);														//convert the seciond user input to an integer
			answer = firstNumber + secondNumber;											//corrected to perform addition as is the intention
			cout << firstNumber << " + " << secondNumber << " = " << answer << endl;		//Correct the output to match the function type
		}
		else if (menuChoice == 2)
		{
			cout << "Enter an Integer: ";													//Insert a prompt statement defining what the user needs to input for the data type
			cin >> num1;																	//store user input as string
			firstNumber = stoi(num1);														//converts user input to an integer to avoid overflows from decimal numbers
			cout << "Enter a second Integer: ";												//Insert a prompt statement defining what the user needs to input for the data type
			cin >> num2;																	//store user input as string
			secondNumber = stoi(num2);														//convert the seciond user input to an integer
			answer = firstNumber - secondNumber;											//corrected to perform subtraction as is the intention
			cout << firstNumber << " - " << secondNumber << " = " << answer << endl;		//Correct the output to match the function type
		}
		else if (menuChoice == 3)
		{
			cout << "Enter an Integer: ";													//Insert a prompt statement defining what the user needs to input for the data type
			cin >> num1;																	//store user input as string
			firstNumber = stoi(num1);														//converts user input to an integer to avoid overflows from decimal numbers
			cout << "Enter a second Integer: ";												//Insert a prompt statement defining what the user needs to input for the data type
			cin >> num2;																	//store user input as string
			secondNumber = stoi(num2);														//convert the seciond user input to an integer
			answer = firstNumber * secondNumber;											//corrected to perform multiplication as is the intention
			cout << firstNumber << " * " << secondNumber << " = " << answer << endl;		//Correct the output to match the function type
		}
		else if (menuChoice == 4)
		{
			cout << "Goodbye" << endl;														//Add prompt for menu 4 on exit
		}
		else
		{
			cout << "Invalid Choice. Please Read the Menu and Try Again." << endl;			//Added condtional line when user enters an invalid menu choice
		}

	}


	return 0;
}


/******************************
*****ORIGIONAL LEGACY CODE*****
*******************************/



/*
#include <iostream>

using namespace std;

int main()
{
	int menuChoice = 0;
	int firstNumber;
	int secondNumber;
	int answer;

	while (menuChoice != 5)  //Loop exits on choice 5, menu says 4 to exit
	{

		cout << "----------------" << endl; //No prompts to clarify input formats
		cout << "- 1) Add - " << endl;
		cout << "- 2) Subtract -" << endl;
		cout << "- 3) Multiply -" << endl;
		cout << "- 4) Exit -" << endl;
		cout << "----------------" << endl;

		cin >> menuChoice;

		if (menuChoice == 1)
		{
			cin >> firstNumber; //No prompt or defintion of type to enter - leads to overflow if not integer
			cin >> secondNumber; //No prompt or defintion of type to enter - leads to overflow if not integer
			answer = firstNumber - secondNumber; //Function is supposed to perform addition not subtraction
			cout << firstNumber << " - " << secondNumber << " = " << answer << endl;  //Outputs incorrectly for an addition function
		}
		else if (menuChoice == 2)
		{
			cin >> firstNumber;  //No prompt or defintion of type to enter - leads to overflow if not integer
			cin >> secondNumber;  //No prompt or defintion of type to enter - leads to overflow if not integer
			answer = firstNumber + secondNumber;  //Function is supposed to perform subtraction not addition
			cout << firstNumber << " - " << secondNumber << " = " << answer << endl;  //Outputs correct for subtraction, but functuion performed addition
		}
		else if (menuChoice == 3)
		{
			cin >> firstNumber;  //No prompt or defintion of type to enter - leads to overflow if not integer
			cin >> secondNumber;  //No prompt or defintion of type to enter - leads to overflow if not integer
			answer = firstNumber / secondNumber; //Function is supposed to perform multiplication not division
			cout << firstNumber << " - " << secondNumber << " = " << answer << endl; //Incorrect output for desired or actual output of what this function does
		}

	}


	return 0;
}



*/




