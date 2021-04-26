#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int NumberOfGuests = 0;
	cout << "Please, enter the total number of guests: ";
	cin >> NumberOfGuests;
	vector<int> arrivals;
	vector<int> exits;
	int tempToInput = 0;
	// Inputing array of arrivals
	for (int i = 0; i < NumberOfGuests; i++)
	{
		cout << "Please, enter the time when " << i + 1 << " guest arrived: ";
		cin >> tempToInput;
		arrivals.push_back(tempToInput);
	}
	int maximumTimeOfExits = 0;
	// Inputing array of exits
	for (int i = 0; i < NumberOfGuests; i++)
	{
		cout << "Please, enter the time when " << i + 1 << " guest left: ";
		cin >> tempToInput;
		if (maximumTimeOfExits < tempToInput)
		{
			maximumTimeOfExits = tempToInput;
		}
		exits.push_back(tempToInput);
	}
	int maxAmountOfGuests = 0;
	int tempAmountOfGuests = 0;
	int timeToMaxGuests = 0;
	for (int t = 1; t < maximumTimeOfExits; t++)
	{
		tempAmountOfGuests = 0;
		for (int i = 0; i < NumberOfGuests; i++)
		{
			if (arrivals[i] <= t && exits[i] >= t)
			{
				tempAmountOfGuests++;
			}
		}
		if (tempAmountOfGuests > maxAmountOfGuests)
		{
			maxAmountOfGuests = tempAmountOfGuests;
			timeToMaxGuests = t;
		}
	}
	cout << "The time when the party is attended by the maximum number of guests: " << timeToMaxGuests;
	return 0;
}