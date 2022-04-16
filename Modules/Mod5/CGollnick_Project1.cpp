#include <iostream>

using namespace std;

string user;
string password;

string approvedUsers[] = {"User","user","", " "};
string approvedPasswords[] = {"123"};

int errorValue = 1;

int menuChoice;

string clientList[] = {"Bob Jones","Sarah Davis","Amy Friendly","Johnny Smith","Carol Spears"};
int clientChoice[] = { 1,1,2,1,2 };
int clientNum;
int newChoice;

int arrSizeClientList = sizeof(clientList) / sizeof(clientList[0]);

int ChangeCustomerChoice() 
{
    cout << "Enter the number of the client you want to change" << endl;
    cin >> clientNum;
    clientNum = clientNum - 1;
    cout << endl;
    cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
    cin >> newChoice;

    clientChoice[clientNum] = newChoice;

    return 0;
}

int CheckUserPermissionAccess()
{
    cout << "Enter Your Username: ";
    cin >> user;
    cout << endl << "Enter Your Password: ";
    cin >> password;
    cout << endl;

    if (find(begin(approvedUsers), end(approvedUsers), user) != end(approvedUsers))
    {
        errorValue = 0;
    }
    else 
    {
        errorValue = 1;
    }

    if (find(begin(approvedPasswords), end(approvedPasswords), password) != end(approvedPasswords))
    {
        errorValue = 0;
    }
    else
    {
        errorValue = 1;
    }

    return errorValue;



}

int DisplayInfo()
{   
    
    cout << "     Client's Name              Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
    for (int i = 0; i < arrSizeClientList; i++) {
        cout << (i + 1) << ". " << clientList[i] << " selected " << clientChoice[i] << endl;
    }

    return 0;

}


int main()
{
    cout << "Created By: Chris Gollnick" << endl << endl;
    while (errorValue > 0) {
        CheckUserPermissionAccess();
    }
    while (menuChoice != 3) {
        cout << "What Would You Like To Do?" << endl;
        cout << "DISPLAY the client list (enter 1)" << endl;
        cout << "CHANGE a client's choice (enter 2)" << endl;
        cout << "EXIT the program (enter 3)" << endl;
        cin >> menuChoice;
        cout << endl;
        if (menuChoice == 1) {
            cout << "You Chose 1" << endl;
            DisplayInfo();
        }
        else if (menuChoice == 2) {
            cout << "You Chose 2" << endl;
            ChangeCustomerChoice();
        }
        else if (menuChoice == 3) {
            cout << "You Chose 3" << endl;
        }
        else {
            cout << "Invalid Choice" << endl;
        }
    }

}