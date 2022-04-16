#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

/********************************************
* Begin Authentication & Login Methodologies*
*********************************************/

string user;
string password;

/*
* Old method of storing usernames and passwords.  Insecure.
* Allows users and passwords to be found easily
* Entries of information not bound to each other
* 
string approvedUsers[] = {"User","user","", " "};
string approvedPasswords[] = {"123"};
*/

//Defines pair type for authentication
//Allows us to connect usernames and passwords together
pair<string, int> user_1 = make_pair("Admin", 141);

//Method to decrypt a password from a string text to an integer value
int Decryption(string password) {
    string dPass = password;
    char letter[52] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
        'p','q','r','s','t','u','v','w','x','y','z',
        'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    
    int num[52] = { 1,2,3,4,5,6,7,8,9,10,
        11,12,13,14,15,16,17,18,19,20,
        21,22,23,24,25,26,
        101,102,103,104,105,106,107,108,109,110,
        111,112,113,114,115,116,117,118,119,120,
        121,122,123,124,125,126 };

    int decVal = 0;

    int size = dPass.size();
    for (int i = 0; i < size; i++) 
    {
        char pLetter = dPass.at(i);

        int j = 0;
        while (j < 52) 
        {
            if (letter[j] == pLetter) 
            {
                break;
            }
            j++;
        }
        if (j < 52) 
        {
            decVal = decVal + num[j];
        }


    }
    return decVal;
    
}

int AuthenticateUser(string user, int pass)
{
    string username = user;
    int passcode = pass;
    if (user_1.first == username && user_1.second == passcode)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int CheckUserPermissionAccess()
{
    cout << "Enter Your Username: ";
    cin >> user;
    cout << endl << "Enter Your Password: ";
    cin >> password;
    cout << endl;

    //Method to decrypt password to saved value
    int pVal = Decryption(password);

    /*
    * Old method of checking user names and passwords
    * Deperecating as it does not connect them to each other
    *
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
    */

    int authenticateCode = AuthenticateUser(user, pVal);

    if (authenticateCode == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }


}

/*********************************
* Begin Client Data Methodologies*
**********************************/


//clientNum was the arbitrary method of which to identify clients numerically
// //To be replaced by an account id
//ORIGINAL - NOT USED: int clientNum;
//UPDATED - NOT USED AS ARRAY: long clientAccountID[] = {89871234, 89871235, 89871236, 89871237, 89871238};

//List clients in basic text easily accessible personal information
//ORIGINAL - NOT USED: string clientList[] = {"Bob Jones","Sarah Davis","Amy Friendly","Johnny Smith","Carol Spears"};
//Utilizing a cipher shift, the names are scrambled to present as unidentifiable array n20
//Also Store as lastname, first format
//UPDATED - NOT USED AS ARRAY: string clientList[] = {"Dihym, Viv","Xupcm, Mulub","Zlcyhxfs, Ugs","Mgcnb, Dibhhs","Mjyulm, Wulif" };

//method to uncipher the client name for displaying information
string DecipherClientName(string name) 
{
    char alphaLow[28] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
        'i', 'j', 'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', ','};
    
    char alphaCap[28] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
        'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', ',' };
    
    char dAlphaLow[28] = { 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't' , 
        'u','v', 'w', 'x', 'y', 'z','a', 'b', 'c',
        'd', 'e', 'f', ' ', ',' };
    
    char dAlpahaCap[28] = { 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z','A', 'B',
        'C', 'D', 'E', 'F', ' ', ',' };

    string eName = name;
    string dName = "";

    for (int i = 0; i < eName.size(); i++)
    {
        char eLetter = eName.at(i);

        int j = 0;
        while (j < 28)
        {
            if (alphaLow[j] == eLetter) 
            {
                dName = dName + dAlphaLow[j];
                break;
            }
            else if (alphaCap[j] == eLetter)
            {
                dName = dName + dAlpahaCap[j];
                break;
            }
            j++;
        };
    };
    return dName;
}

//Client choices are arbitrary numbers not allowing for variance of programs
//ORIGINAL -- NOT USED: int clientChoice[] = { 1,1,2,1,2 };
//Resolve to storing the program choice as names to prevent issues if numbers change
//UPDATED NOT USED AS ARRAY: string clientProgram[] = { "Brokerage","Brokerage","Retirement","Brokerage","Retirement","Retirement" };

string ReturnService(int choiceNum)
{
    int num = choiceNum;
    string choice = "";
    if (num == 1)
    {
        choice = "Brokerage";
    }
    else if (num == 2)
    {
        choice = "Retirement";
    }

    return choice;

}

//Define pairing to connect user and account ID
pair<long, string> accUsr1 = make_pair(89871234, "Dihym, Viv");
pair<long, string> accUsr2 = make_pair(89871235, "Xupcm, Mulub");
pair<long, string> accUsr3 = make_pair(89871236, "Zlcyhxfs, Ugs");
pair<long, string> accUsr4 = make_pair(89871237, "Mgcnb, Dibhhs");
pair<long, string> accUsr5 = make_pair(89871238, "Mjyulm, Wulif");

//Define pair of user with choice
pair<string, string> choice1234 = make_pair("Brokerage", "Dihym, Viv");
pair<string, string> choice1235 = make_pair("Brokerage", "Xupcm, Mulub");
pair<string, string> choice1236 = make_pair("Retirement", "Zlcyhxfs, Ugs");
pair<string, string> choice1237 = make_pair("Brokerage", "Mgcnb, Dibhhs");
pair<string, string> choice1238 = make_pair("Retirement", "Mjyulm, Wulif");

string GetClientFromID(long idNum)
{
    long id = idNum;
    string name = "";
    
    if (id == accUsr1.first)
    {
        name = accUsr1.second;
    }
    else if (id == accUsr2.first)
    {
        name = accUsr2.second;
    }
    else if (id == accUsr3.first)
    {
        name = accUsr3.second;
    }
    else if (id == accUsr4.first)
    {
        name = accUsr4.second;
    }
    else if (id == accUsr5.first)
    {
        name = accUsr5.second;
    }
    else
    {
        name = "ERROR";
    }
    return name;
}

int UpdateClientChoice(string clientName, string newChoice)
{
    string name = clientName;
    string choice = newChoice;

    if (name == choice1234.second)
    {
        pair<string, string> choice1234 = make_pair(choice, name);
        return 0;
    }
    else if (name == choice1235.second)
    {
        pair<string, string> choice1235 = make_pair(choice, name);
        return 0;
    }
    else if (name == choice1236.second)
    {
        pair<string, string> choice1236 = make_pair(choice, name);
        return 0;
    }
    else if (name == choice1237.second)
    {
        pair<string, string> choice1237 = make_pair(choice, name);
        return 0;
    }
    else if (name == choice1238.second)
    {
        pair<string, string> choice1238 = make_pair(choice, name);
        return 0;
    }
    else
    {
        return 1;
    }
    

}

long clientAccountID;

int errorValue = 1;
int menuChoice;
int newChoice;

//int arrSizeClientList = sizeof(clientList) / sizeof(clientList[0]);

int ChangeCustomerChoice() 
{
    //Format to read to enter the account number
    //cout << "Enter the number of the client you want to change" << endl;
    cout << "Enter the Account Number of the Client you want to change" << endl;
    cin >> clientAccountID;
    // NO Longer needed: clientNum = clientNum - 1;
    cout << endl;

    string name = GetClientFromID(clientAccountID);
    if (name != "ERROR")
    {
        //Correct the wording for clarity
        //cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
        cout << "Please enter a number for the new service to be assigned to the client:  " << endl
            << "1 = Brokerage" << endl
            << "2 = Retirement" << endl;
        cin >> newChoice;

        //Deprecated: clientChoice[clientNum] = newChoice;
        //Method to convert choice integer to string
        string choice = ReturnService(newChoice);
        int code = UpdateClientChoice(name, choice);
        if (code == 0)
        {
            cout << "Update Successful" << endl;
        }
        else if (code == 1)
        {
            cout << "Update Error. Try Again" << endl;
        }

    }
    else
    {
        cout << "ID Not Found. Please Try Again." << endl;
    }
    
    return 0;
}



int DisplayInfo()
{   
    //No longer using 1 & 2 to identify service
    //cout << "     Client's Name              Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
    
    //New Prnt title

    cout << "     Client's Name     Service Selected     " << endl;

    /*
    * Deprecated method from origional code
    * Data no longer in array
    * 
    for (int i = 0; i < arrSizeClientList; i++) {
        cout << (i + 1) << ". " << clientList[i] << " selected " << clientChoice[i] << endl;
    }
    */

    //Deciphers client name from pair in print statement and what their choice is
    //Avoids variable storage of clients deciphered name
    cout << DecipherClientName(choice1234.second) << " " << choice1234.first << endl;
    cout << DecipherClientName(choice1235.second) << " " << choice1235.first << endl;
    cout << DecipherClientName(choice1236.second) << " " << choice1236.first << endl;
    cout << DecipherClientName(choice1237.second) << " " << choice1237.first << endl;
    cout << DecipherClientName(choice1238.second) << " " << choice1238.first << endl;


    return 0;

}


int main()
{
    cout << "Created By: Chris Gollnick" << endl << endl;
    while (errorValue > 0) {
        errorValue = CheckUserPermissionAccess();
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