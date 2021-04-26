#include <iostream>
using namespace std;

int countOfMovements = 0;

void switchHanoy(int NumberOfRings, int i, int j)
{
	if (NumberOfRings == 1)
	{
		if (countOfMovements < 10)
		{
			cout << i << "->" << j << endl;
		}
		countOfMovements++;
	}
	else
	{
		switchHanoy(NumberOfRings - 1, i, 6 - i - j);
		if (countOfMovements < 10)
		{
			cout << i << "->" << j << endl;
		}
		countOfMovements++;
		switchHanoy(NumberOfRings - 1, 6 - i - j, i);
	}
}

int main()
{
	int NumberOfRings;
	cout << "Please, enter the number of rings: ";
	cin >> NumberOfRings;
	cout << "First 10 movements:\n";
	switchHanoy(NumberOfRings, 1, 2);
	cout << "Full amount of movements: " << countOfMovements;
	cout << endl;
	return 0;
}