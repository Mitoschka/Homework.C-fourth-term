#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int NumberOfHouses = 0;
    cout << "Please enter the total number of houses: ";
    cin >> NumberOfHouses;
    vector<int> valuesOfHouses;
    int tempValue = 0;
    for (int i = 0; i < NumberOfHouses; i++)
    {
        cout << "Please enter the value of " << i + 1 << " house: ";
        cin >> tempValue;
        valuesOfHouses.push_back(tempValue);
    }
    vector<int> optionalChoices;
    optionalChoices.push_back(0);
    optionalChoices.push_back(valuesOfHouses[0]);
    for (int i = 1; i < NumberOfHouses; i++)
    {
        optionalChoices.push_back(max(valuesOfHouses[i] + optionalChoices[i - 1], optionalChoices[i]));
    }
    cout << "Maximum cost of stolen: " << optionalChoices[optionalChoices.size() - 1];
}