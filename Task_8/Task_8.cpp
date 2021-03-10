#include <iostream>
using namespace std;

int robberyTheory(int valueOfHouse, int* arrayOfValuesOfHouses)
{
    // Maximum value of value
    int maxCostOfStolen = arrayOfValuesOfHouses[0];
    for (int i = 1; i < valueOfHouse; i++)
    {
        // Take every even house
        if (i % 2 == 0)
        {
            maxCostOfStolen += arrayOfValuesOfHouses[i];
        }
    }
    // Returning the resulting value
    return maxCostOfStolen;
}

bool test()
{
    // Boolean variable passing the test
    bool isPassed = true;
    // Odd array check
    int firstTestArrayOfValuesOfHouses[7] = {6, 7, 1, 3, 8, 2, 4};
    if (robberyTheory(7, firstTestArrayOfValuesOfHouses) != 19)
    {
        isPassed = false;
    }
    // Even array check
    int secondTestArrayOfValuesOfHouses[6] = {6, 1, 3, 8, 2, 4};
    if (robberyTheory(6, secondTestArrayOfValuesOfHouses) != 11)
    {
        isPassed = false;
    }
    // Checking from an array with zeros
    int thirdTestArrayOfValuesOfHouses[4] = {0, 0, 0, 0};
    if (robberyTheory(4, thirdTestArrayOfValuesOfHouses) != 0)
    {
        isPassed = false;
    }
    // Checking with an array of ones
    int fourthTestArrayOfValuesOfHouses[4] = { 1, 1, 1, 1 };
    if (robberyTheory(4, fourthTestArrayOfValuesOfHouses) != 2)
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