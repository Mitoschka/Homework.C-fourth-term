#include <iostream>
using namespace std;

int robberyTheory(int valueOfHouse, int* arrayOfValuesOfHouses)
{
    // Максимальное значение ценности
    int maxCostOfStolen = arrayOfValuesOfHouses[0];
    for (int i = 1; i < valueOfHouse; i++)
    {
        // Берём каждый чётный дом
        if (i % 2 == 0)
        {
            maxCostOfStolen += arrayOfValuesOfHouses[i];
        }
    }
    // Возвращаем полученный результат ценности
    return maxCostOfStolen;
}

bool test()
{
    // Булева переменная прохождения теста
    bool isPassed = true;
    // Проверка с нечётным массивом
    int firstTestArrayOfValuesOfHouses[7] = {6, 7, 1, 3, 8, 2, 4};
    if (robberyTheory(7, firstTestArrayOfValuesOfHouses) != 19)
    {
        isPassed = false;
    }
    // Проверка с чётным массивом
    int secondTestArrayOfValuesOfHouses[6] = {6, 1, 3, 8, 2, 4};
    if (robberyTheory(6, secondTestArrayOfValuesOfHouses) != 11)
    {
        isPassed = false;
    }
    // Проверка с массива с нулями
    int thirdTestArrayOfValuesOfHouses[4] = {0, 0, 0, 0};
    if (robberyTheory(4, thirdTestArrayOfValuesOfHouses) != 0)
    {
        isPassed = false;
    }
    // Проверка с массивом из единиц
    int fourthTestArrayOfValuesOfHouses[4] = { 1, 1, 1, 1 };
    if (robberyTheory(4, fourthTestArrayOfValuesOfHouses) != 2)
    {
        isPassed = false;
    }
    return isPassed;
}

int main()
{
    //Unit тесты
    if (!test())
    {
        printf("Some tests failed.");
        return 1;
    }

    // Размер массива
    int valueOfHouse = 0;
    cout << "Please, enter the integer value of houses: ";
    // Получение от пользователя размера массива
    cin >> valueOfHouse;

    // Если домов нет, то ценности нет :)
    if (valueOfHouse <= 0)
    {
        cout << "Max cost of stolen: " << 0;
        return 0;
    }

    // Выделение памяти для массива
    int* arrayOfValuesOfHouses = new int[valueOfHouse];
    cout << "House numbers: ";
    for (int i = 0; i < valueOfHouse; i++)
    {
        // Запись случайного числа, которое вернет rand()
        arrayOfValuesOfHouses[i] = rand() % 100 + 1;
        cout << arrayOfValuesOfHouses[i] << ' ';
    }
    // Вывод результата выполнения функции
    cout << endl << "Max cost of stolen: " << robberyTheory(valueOfHouse, arrayOfValuesOfHouses);
    // Очистка памяти
    delete[] arrayOfValuesOfHouses;
    return 0;
}