#include <iostream>
#include <cmath>
/**
 * @brief Рассчитывает значение А
 * @param x-константа
 * @param y-константа
 * @param z-константа
 * @return- значение функции А
*/
double getA(double const x, double const y, double const z);
/**
 * @brief Рассчитывает значение B
 * @param x-константа
 * @param y-константа
 * @param z-константа
  * @return- значение функции В 
*/
double getB(double const x, double const y, double const z);
/**
 * @brief Точка входа в функцию
  * @return- 0 иначе 1 
*/
int main()
{
    double const x = 1.426;
    double const y = -1.22;
    double const z =3.5;
    std::cout <<"a= "<<getA(x,y,z)<<"; b= "<<getB(x,y,z);
    return 0;
}
double getA(double const x, double const y, double const z)
{
    return  2*cos(x-M_PI/6)/(1/2+(sin(y)*sin(y)));
}
double getB(double const x, double const y, double const z)
{
   return 1+(z*z)/(3+(z*z)/5); 
