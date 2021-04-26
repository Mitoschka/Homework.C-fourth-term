#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// The result is a summ from index to another index in array.
/// This result equals the time one molar draws in a row.
/// </summary>
int sumTimeOfPainting(vector<int> arr, int startIndex, int finishIndex)
{
	int sum = 0;
	for (int i = startIndex; i <= finishIndex; i++)
	{
		sum += arr[i];
	}
	return sum;
}

/// <summary>
/// Function for getting result by separation boards for molars.
/// </summary>
int separation(vector<int> arr, int n, int k)
{
	if (k == 1)
	{
		return sumTimeOfPainting(arr, 0, n - 1);
	}
	if (n == 1)
	{
		return arr[0];
	}
	int result = 0;
	result = max(separation(arr, 1, k - 1), sumTimeOfPainting(arr, 1, n - 1));
	for (int i = 2; i <= n; i++)
	{
		result = min(result, max(separation(arr, i, k - 1),
			sumTimeOfPainting(arr, i, n - 1)));
	}
	return result;
}

int main()
{
	int numberOfBoards, numberOfMolars;
	cout << "Please, enter the number of boards: ";
	cin >> numberOfBoards;
	cout << "Please, enter the number of molars: ";
	cin >> numberOfMolars;
	vector<int> arr;
	int temp;
	for (int i = 0; i < numberOfBoards; i++)
	{
		cout << "Please, enter the length of " << i + 1 << " board: ";
		cin >> temp;
		arr.push_back(temp);
	}
	cout << "Minimum time for painting: " << separation(arr, numberOfBoards, numberOfMolars) << endl;
	return 0;
}