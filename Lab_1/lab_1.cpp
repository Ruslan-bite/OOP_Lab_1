#include <iostream>
#include <windows.h>
#include "money.h"
using namespace std;

int main()
{
    // Встановлення для коректного відображення тексту українською
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    money A;                    // створення об'єкта структури

    A.Read();                   // введення даних
    A.Display();                // виведення даних
    cout << "Сума: " << A.summa() << " грн" << endl;  // виведення суми

    return 0;
}