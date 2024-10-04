#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double getValue();
void checkValue(double const value, bool strict);
double getSum(const int n);
double getNext(const double current, const int i);
double getSumE(double const e);

int main()
{
    cout << "Enter the number of elements = ";
    int a = static_cast<int>(getValue());
    checkValue(a, true); // строгое сравнение
    cout << "Enter the element from which the sequence will begin except 0 = ";
    double b = getValue();
    checkValue(b, false); // нестрогое сравнение
    cout << "The sum of the first elements = " << getSum(a) << endl;
    cout << "Sum of elements after tracked number = " << getSumE(b) << endl;
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

void checkValue(double const value, bool strict)
{
    if (strict)
    {
        if (value <= 0) // Проверка на <= 0
        {
            cout << "error" << endl;
            abort();
        }
    }
    else
    {
        if (value < 0) // Проверка на < 0
        {
            cout << "error" << endl;
            abort();
        }
    }
}

double getSum(const int n)
{
    double current = 1;
    double result = current;
    for (int i = 0; i < n; i++)
    {
        current = getNext(current, i);
        result += current;
    }
    return result;
}

double getNext(const double current, const int i)
{
    return ((-1.0) / ((i + 3) * (i + 4))) * current;
}

double getSumE(double const e)
{
    double result = 0;
    double current = 1;
    for (int i = 0; (abs(current) > e - numeric_limits<double>::epsilon()); i++)
    {
        result += current;
        current = getNext(current, i);
    }
    return result;
}
