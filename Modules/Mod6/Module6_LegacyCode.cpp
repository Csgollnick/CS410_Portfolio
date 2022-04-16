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

		cout << "----------------" << endl;
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

