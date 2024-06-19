#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
/**
* @breef Считывает значение с клавиатуры с проверкой ввода
* @return Введённое значение
*/
double getValue();
/**
* @breef Проверяет число на то, чтобы оно не было равно нулю или меньше нуля
* @return Введённое значение
*/
void checkValue(int const value);
/**
* @breef Производит расчёт суммы ряда функции от 1 до n
* @param n - Число ряда, до которого будет посчитана сумма ряда
* @return Сумма ряда функций
*/
double getSum(const int n);
/**
* @breef Подсчёт рекурентной функции
* @param current - прошлое значение функции
* @param i - порядковый номер ряда
* @return Полученное значение функции
*/
double getRek(const double current, const int i);
/**
* @breef Производит расчёт суммы ряда функции от 1 до n
* @param e - Число, до которого будет подсчитываться сумма ряда
* @return Сумма ряда функций до определённого числа
*/
double getSumN(double const e);
/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1.
*/
int main()
{
    cout << "Enter the number of elements = ";
    int a = getValue();
    checkValue(a);
    cout << "Enter the element from which the sequence will begin = ";
    double b = getValue();
    checkValue(b);
    cout << "The sum of the first elements = " << getSum(a) << endl;
    cout << "Sum of elements after tracked number = " << getSumN(b) << endl;
    return 0;
}
double getValue()
{
    double n;
    if (!(cin >> n))
    {
        cout << "error" << endl;
        abort();
    }
    return n;
}
void checkValue(int const value)
{
    if (value < 0)
    {
        cout << "error" << endl;
        abort();
    }
}
double getSum(const int n)
{
    double current = 1;
    double result = current;
    for (int i = 0; i < n; i++)
    {
        current = getRek(current, i);
        result += current;
    }
    return result;
}
double getRek(const double current, const int i)
{
    return ((-1.0)/((i+3)*(i+4))) * current;
}
double getSumN(double const e)
{
    double result = 0;
    double current = 1;
    for (int i = 0; (abs(current) > e - numeric_limits<double>::epsilon()); i++)
    {
        result += current;
        current = getRek(current, i);
    }
    return result;
}  
