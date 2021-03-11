#include <iostream>
using namespace std;

int robberyTheory(int valueOfHouse, int* arrayOfValuesOfHouses)
{
    // Allocating memory for an array + 1
    int* arrayOfHousesToBeRobbed = new int[valueOfHouse + 1];
    arrayOfHousesToBeRobbed[0] = 0;
    // Rewriting an old array into a new one
    for (int i = 0; i < valueOfHouse; i++)
    {
        arrayOfHousesToBeRobbed[i + 1] = arrayOfValuesOfHouses[i];
    }
    // Dynamic approach
    for (int i = 3; i <= valueOfHouse; i++)
    {
        arrayOfHousesToBeRobbed[i] += max(arrayOfHousesToBeRobbed[i - 2], arrayOfHousesToBeRobbed[i - 3]);
    }
    // The resulting value
    int maximumValue = 0;
    // Search the maximum in the array
    for (int i = 0; i <= valueOfHouse; i++)
    {
        if (arrayOfHousesToBeRobbed[i] > maximumValue)
        {
            maximumValue = arrayOfHousesToBeRobbed[i];
        }
    }
    // Clearing memory
    delete[] arrayOfHousesToBeRobbed;
    // Returning the resulting value
    return maximumValue;
}

bool test()
{
    // Boolean variable passing the test
    bool isPassed = true;
    int firstTestArrayOfValuesOfHouses[7] = {6, 7, 1, 3, 8, 2, 4};
    if (robberyTheory(7, firstTestArrayOfValuesOfHouses) != 19)
    {
        isPassed = false;
    }
    int secondTestArrayOfValuesOfHouses[6] = {1, 100, 1, 100, 1, 100};
    if (robberyTheory(6, secondTestArrayOfValuesOfHouses) != 300)
    {
        isPassed = false;
    }
    int thirdTestArrayOfValuesOfHouses[5] = {100, 1, 100, 1, 100};
    if (robberyTheory(5, thirdTestArrayOfValuesOfHouses) != 300)
    {
        isPassed = false;
    }
    int fourthTestArrayOfValuesOfHouses[5] = {1, 1, 1, 1, 1};
    if (robberyTheory(5, fourthTestArrayOfValuesOfHouses) != 3)
    {
        isPassed = false;
    }
    return isPassed;
}

int main()
{
    // Unit tests
    if (!test())
    {
        printf("Some tests failed.");
        return 1;
    }

    // Array size
    int valueOfHouse = 0;
    cout << "Please, enter the integer value of houses: ";
    // Getting the size of an array from the user
    cin >> valueOfHouse;

    // If there are no houses, then there is no value :)
    if (valueOfHouse <= 0)
    {
        cout << "Max cost of stolen: " << 0;
        return 0;
    }

    // Allocating memory for an array
    int* arrayOfValuesOfHouses = new int[valueOfHouse];
    cout << "House numbers: ";
    for (int i = 0; i < valueOfHouse; i++)
    {
        // Writing a random number that rand () will return in the range 1 - 100
        arrayOfValuesOfHouses[i] = rand() % 100 + 1;
        cout << arrayOfValuesOfHouses[i] << ' ';
    }
    // Outputting the result of a function execution
    cout << endl << "Max cost of stolen: " << robberyTheory(valueOfHouse, arrayOfValuesOfHouses);
    // Clearing memory
    delete[] arrayOfValuesOfHouses;
    return 0;
}