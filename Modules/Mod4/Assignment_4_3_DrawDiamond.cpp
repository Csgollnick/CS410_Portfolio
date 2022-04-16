
#include <iostream>

using namespace std;

int main()
{
	int rows;
	int stars = 1;

	cout << "Enter number of rows: ";
	cin >> rows;
	cout << endl;

	int spaceRows = rows - 1;

	for (int i = 1; i < rows * 2; i++) {
		for (int j = 1; j <= spaceRows; j++) {
			cout << " ";
		}
		for (int j = 1; j < stars * 2; j++) {
			cout << "*";
		}
		cout << endl;
		if (i < rows) {
			spaceRows--;
			stars++;
		}
		else {
			spaceRows++;
			stars--;

		}
	}
	return 0;
}

