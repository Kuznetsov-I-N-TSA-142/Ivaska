#include<iostream>
#include<stdlib.h>
using namespace std;

/*
@brief Рассчитывает значение B
 * @param a-число
 * @param n-число
 * @return- значение функции В
*/
double getB(double a, double n);
/*
@brief Проверяет положительное ли значение n 
 * @param n-число
 * @return- значение n
*/
void checkN(double n);
/*
@brief ввод значений с проверкой
 * @return- числа
*/
double getNumber();
/*
@brief Рассчитывает площадь прямоугольника
 * @param a-число
 * @param b-число
 * @return- площадь прямоугольника
*/
double areaRectangle(double a, double b);
/*
@brief Рассчитывает перимeтр прямоугольника
 * @param a-число
 * @param b-число
 * @return- перимeтр прямоугольника
*/
double perimeterRectangle(double a, double b);

int main()
{
cout << "Введите первую сторону " ;
double a = getNumber();
checkN(a);
cout << "Введите процентнoе соотношение для второй стороны " ;
double n = getNumber();
checkN(n);
double b = getB(a,n);
cout << "Площадь = " << areaRectangle(a, b) << endl;
cout << "Перимeтр = " << perimeterRectangle(a, b);
return 0;
}

double getNumber()
{
double a;
cin >> a;
if (cin.fail())
{
cout<<"Incorrect input";
abort();
}
return a;
}

void checkN(double n)
{
if (n <= 0)
{
cout<<"Wrong value"<<endl;
abort();
}
}

double getB(double a, double n)
{
return a*n/100;
}

double areaRectangle(double a, double b)
{
double area = a * b;
return area;
}

double perimeterRectangle(double a, double b)
{
double perimeter = 2*(a + b);
return perimeter;
}
