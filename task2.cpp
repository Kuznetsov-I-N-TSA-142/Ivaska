#include <iostream>
#include <cstdlib> // для abort
using namespace std;

/**
 * @brief Рассчитывает значение второй стороны прямоугольника на основе первой стороны и процентного соотношения.
 * 
 * @param a Первая сторона прямоугольника (положительное число).
 * @param n Процентное соотношение для расчета второй стороны (положительное число).
 * @return Возвращает значение второй стороны прямоугольника.
 */
double getB(const double a, const double n);

/**
 * @brief Проверяет, является ли значение положительным.
 * 
 * @param n Значение, которое нужно проверить.
 * @throws abort() Если значение не положительное.
 */
void checkN(const double n);

/**
 * @brief Запрашивает у пользователя ввод числа.
 * 
 * @return Возвращает введенное число.
 * @throws abort() Если ввод некорректен.
 */
double getNumber();

/**
 * @brief Рассчитывает площадь прямоугольника.
 * 
 * @param a Первая сторона прямоугольника (положительное число).
 * @param b Вторая сторона прямоугольника (положительное число).
 * @return Возвращает площадь прямоугольника.
 */
double areaRectangle(const double a, const double b);

/**
 * @brief Рассчитывает периметр прямоугольника.
 * 
 * @param a Первая сторона прямоугольника (положительное число).
 * @param b Вторая сторона прямоугольника (положительное число).
 * @return Возвращает периметр прямоугольника.
 */
double perimeterRectangle(const double a, const double b);

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите первую сторону: ";
    const double a = getNumber();
    checkN(a);
    cout << "Введите процентное соотношение для второй стороны: ";
    const double n = getNumber();
    checkN(n);
    const double b = getB(a, n);
    cout << "Площадь = " << areaRectangle(a, b) << endl;
    cout << "Периметр = " << perimeterRectangle(a, b) << endl;
    return 0;
}

double getNumber()
{
    double a;
    cin >> a;
    if (cin.fail())
    {
        cout << "Неправильный ввод данных" << endl;
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

double getB(const double a, const double n)
{
    const double k = a * n / 100; // Вычисляем значение второй стороны
    return k; // Возвращаем рассчитанное значение
}

double areaRectangle(const double a, const double b)
{
    const double area = a * b; // Вычисляем площадь
    return area; // Возвращаем площадь
}

double perimeterRectangle(const double a, const double b)
{
    const double perimeter = 2 * (a + b); // Вычисляем периметр
    return perimeter; // Возвращаем периметр
}
