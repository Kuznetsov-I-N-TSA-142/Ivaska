#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
 * @brief Проверяет, положительное ли значение
 * @param n - число
 */
void checkN(const double n);

/*
 * @brief Ввод значений с проверкой
 * @return Введенное число
 */
double getNumber();

/*
 * @brief Табулирует заданную функцию
 * @param minValue - минимальное значение функции
 * @param maxValue - максимальное значение функции
 * @param step - шаг
 */
void printTabFunction(const double minValue, const double maxValue, const double step);

/*
 * @brief Проверяет, что минимум меньше максимума
 * @param min - минимальное значение функции
 * @param max - максимальное значение функции
 */
void checkRange(const double min, const double max);

/*
 * @brief Главная функция программы
 * @return Возвращает 0, если функция выполнена верно, иначе 1.
 */
int main()
{
    cout << "Введите минимальный предел -> ";
    const double minValue = getNumber();
    cout << "Введите максимальный предел -> ";
    const double maxValue = getNumber();
    checkRange(minValue, maxValue);
    cout << "Введите шаг -> ";
    const double step = getNumber();
    checkN(step);
    printTabFunction(minValue, maxValue, step);

    return 0;
}

void printTabFunction(const double minValue, const double maxValue, const double step) {
    for (double i = minValue; i <= maxValue; i += step) {
        if (i <= 0) {
            cout << setw(10) << i << " Функция неопределена, под корнем отрицательное значение или ноль!" << endl;
        } else {
            const double a = 3 * sin(sqrt(i)) + 0.39 * i - 3.8;
            cout << setw(10) << i << setw(15) << a << endl;
        }
    }
}

double getNumber()
{
    double a;
    cin >> a;
    if (cin.fail())
    {
        cout << "Некорректный ввод" << endl;
        abort();
    }
    return a;
}

void checkN(const double n)
{
    if (n <= 0)
    {
        cout << "Неправильное значение" << endl;
        abort();
    }
}

void checkRange(const double min, const double max)
{
    if (min > max)
    {
        cout << "Неправильный диапазон" << endl;
        abort();
    }
}
