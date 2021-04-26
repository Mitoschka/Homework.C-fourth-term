#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> getCoefficients(string& s)
{
	map<char, int> mapOfCoefficients;
	int counter = 1;
	for (int i = s.size() - 2; i >= 0; i--)
	{
		if (mapOfCoefficients.count(s[i]) == 0)
		{
			mapOfCoefficients[s[i]] = counter;
		}
		counter++;
	}
	if (mapOfCoefficients.count(s[s.size() - 1]) == 0)
	{
		mapOfCoefficients[s[s.size() - 1]] = counter;
	}
	return mapOfCoefficients;
}

pair<int, int> compareStrings(string& searchString, string& initialString)
{
	map<char, int> coefficients = getCoefficients(searchString);
	// First = amount of the number of repetitions of a substring in a string,
	// second - first index;
	pair<int, int> pairToOutput;
	pairToOutput.first = 0;
	pairToOutput.second = -1;
	if (searchString.size() > initialString.size())
	{
		return pairToOutput;
	}
	int i = searchString.size() - 1;
	while (i < initialString.size())
	{
		int j = i;
		char chrToCheck = NULL;
		for (int z = searchString.size() - 1; z >= 0; z--)
		{
			if (searchString[z] != initialString[j])
			{
				chrToCheck = initialString[j];
				break;
			}
			j--;
		}
		if (chrToCheck == NULL)
		{
			pairToOutput.first++;
			if (pairToOutput.second == -1)
			{
				pairToOutput.second = i - searchString.size() + 1;
			}
			i += searchString.size();
		}
		else
		{
			if (coefficients.count(chrToCheck))
			{
				i += coefficients[chrToCheck];
			}
			else
			{
				i += searchString.size();
			}
		}
	}


	return pairToOutput;
}

int main()
{
	string searchString, initialString;
	cout << "Please, enter the string: ";
	cin >> initialString;
	cout << "Please, enter the search string: ";
	cin >> searchString;
	pair<int, int> currentPair = compareStrings(searchString, initialString);
	cout << "The number of repetitions: " << currentPair.first << '\n';
	cout << "Indices of the first element of the substring: " << currentPair.second;
}