#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * @brief Считывает число с проверкой на корректность ввода.
 * 
 * @return Возвращает считанное число.
 */
int getValue();

int main()
{
    int a = getValue(); // Считываем первое число
    int b = getValue(); // Считываем второе число
    double avg = (a + b) / 2.0; // Вычисляем среднее арифметическое

    cout << "1) Среднее арифметическое чисел " << a << " и " << b << " = " << avg << " - " << endl;

    // Проверка, является ли среднее арифметическое целым числом
    if (avg - (int)avg > 0) // Условие: если дробная часть avg больше 0
    {
        cout << " НЕ" << endl; // Если это не целое число
    }

    cout << "целое число" << endl; // Сообщение о целочисленности
    return 0;
}

/**
 * @brief Считывает целое число с проверкой на корректность ввода.
 * 
 * @return Возвращает считанное целое число.
 */
int getValue()
{
    int a;
    if (!(cin >> a)) // Проверка на корректность ввода
    {
        cout << "error" << endl; // Сообщение об ошибке
        abort(); // Завершение программы при ошибке
    }
    return a; // Возвращаем считанное число
}
