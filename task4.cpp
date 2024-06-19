#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
@brief Проверяет положительные ли значения
 * @param n-число
 * @return- значение n
*/
void checkN(const double n);

/*
@brief ввод значений с проверкой
 * @return- числа
*/
double getNumber();

/*
@brief табулирует заданную в таблице функцию
 * @param minValue-минимальное значение функции
 * @param maxValue-максимальное значение функции
 * @param step-шаг
 * @return- выводит таблицу
*/
void printTabFunction(const double minValue, const double maxValue, const double step);

/*
 * @brief проверяет что минимум меньше максимума
 * @param min-минимальное значение функции
 * @param max-максимальное значение функции
 * @return- значения
*/
void checkRange(const double min, const double max);

/**
 * @brief Проверяет, является ли переданное целое число большим или равным нулю.
 * @param i Целое число, которое требуется проверить.
 * @return true, если переданное число больше или равно нулю, в противном случае возвращает false.
 */
bool isGreaterThanOrEqualToNegativeZero(int i);

/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1.
*/
int main()
{
    cout << "Введите минимальный предел: ";
    double minValue = getNumber();
    cout << "Введите максимальный предел: ";
    double maxValue = getNumber();
    checkRange(minValue, maxValue);
    cout << "Введите шаг: ";
    double step = getNumber();
    checkN(step);
    printTabFunction(minValue, maxValue, step);

    return 0;
}

void printTabFunction(const double minValue, const double maxValue, const double step)
{
    if (minValue + step > maxValue) {
        cout << "Шаг выходит за пределы максимального значения." << endl;
        return;
    }

    cout << setw(10) << "x" << setw(15) << "y" << endl;
    for (double i = minValue; i <= maxValue; i += step)
    {
        if (i > maxValue)
        {
            cout << "Значение x выходит за пределы максимального значения." << endl;
            break;
        }
        double a = 3 * sin(sqrt(i)) + 0.39 * i - 3.8;
        cout << setw(10) << i << setw(15) << a << endl;
    }
}

double getNumber()
{
    double a;
    cin >> a;
    if (cin.fail())
    {
        cout << "Incorrect input";
        exit(1);
    }
    return a;
}

void checkN(const double n)
{
    if (n <= 0)
    {
        cout << "Wrong value" << endl;
        exit(1);
    }
}

void checkRange(const double min, const double max)
{
    if (min > max)
    {
        cout << "Wrong range entered" << endl;
        exit(1);
    }
}

bool isGreaterThanOrEqualToNegativeZero(int i)
{
    return i >= 0;
}
