
#include <iostream>

using namespace std;

int main()
{
    long binNum;
    long hexNum = 0;
    long count = 1;
    long remainder;

    cout << "Enter a Binary Number: "; 
    cin >> binNum;
    cout << endl;

    while (binNum != 0) {
        remainder = binNum % 10;
        hexNum = hexNum + remainder * count;
        count = count * 2;
        binNum = binNum / 10;
    }
    cout << "The Equivalent Hexadecimal Value is: " << hexNum;

    return 0;
}

