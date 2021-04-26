#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int numberOfLines, numberOfColumns;
	cout << "Please, enter the number of lines: ";
	cin >> numberOfLines;
	cout << "Please, enter the number of columns: ";
	cin >> numberOfColumns;
	vector<int> str(numberOfColumns);
	vector<vector<int>> inputCost(numberOfLines, str);
	vector<vector<int>> dynamicCost(numberOfLines, str);
	str.clear();
	int tempInput;
	for (int i = 0; i < numberOfLines; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			cout << "Please, enter a value in the position " << i << " " << j << ": ";
			cin >> tempInput;
			inputCost[i][j] = tempInput;
		}
	}
	dynamicCost[0][0] = inputCost[0][0];
	for (int i = 1; i < numberOfLines; i++)
	{
		dynamicCost[i][0] = dynamicCost[i - 1][0] + inputCost[i][0];
	}
	for (int i = 1; i < numberOfColumns; i++)
	{
		dynamicCost[0][i] = dynamicCost[0][i - 1] + inputCost[0][i];
	}
	for (int i = 1; i < numberOfLines; i++)
	{
		for (int j = 1; j < numberOfColumns; j++)
		{
			dynamicCost[i][j] = inputCost[i][j]
				+ min(min(dynamicCost[i - 1][j], dynamicCost[i][j - 1]), dynamicCost[i - 1][j - 1]);
		}
	}
	cout << "Path cost: " << dynamicCost[numberOfLines - 1][numberOfColumns - 1];
}