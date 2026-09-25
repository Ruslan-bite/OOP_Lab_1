#include "money.h"
#include <iostream>
using namespace std;

void money::Init(int f, int s)
{
    // Перевірка, чи належить номінал до допустимих значень
    if (f != 1 && f != 2 && f != 5 && f != 10 &&
        f != 20 && f != 50 && f != 100 &&
        f != 500 && f != 1000)
    {
        cout << "Неправильний номінал купюри!" << endl;
        this->first = 0;
        this->second = 0;
        return;
    }

    // Перевірка, що кількість купюр є додатною
    if (s < 0)
    {
        cout << "Кількість купюр має бути додатним числом!" << endl;
        this->first = 0;
        this->second = 0;
        return;
    }
   
    // Збереження правильних значень у полях структури
    this->first = f;
    this->second = s;
}

void money::Read()
{
    int f, s;
    bool ok = false;
    
    // Повторюємо введення, доки не будуть отримані правильні дані
    while (!ok)
    {
        cout << "Введіть номінал купюри: ";
        cin >> f;

        cout << "Введіть кількість купюр: ";
        cin >> s;

        this->Init(f, s);

        if (this->first == 0 && this->second == 0)
        {
            cout << "Спробуйте ще раз" << endl << endl;
        }
        else
        {
            ok = true;
        }
    }
}

void money::Display()
{
    cout << "Номінал: " << first
        << " грн, кількість: " << second << " шт." << endl;
}

long long money::summa()
{
    // Обчислення загальної вартості всіх купюр
    return static_cast<long long>(first) * second;
}