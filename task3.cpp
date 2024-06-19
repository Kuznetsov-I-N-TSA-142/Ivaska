#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * @brief считывает число с проверкой
 * @return число
 */
int getValue();

int main()

{

    int a = getValue();
    int b = getValue();
    double avg = (a+b)/2.0;
    cout << "1) Среднее арифметическое чисел " << a << " и " << b << " = " << avg << " - "<<endl;
    if (avg-(int)avg > 0)
    {
    cout << " НЕ"<< endl;
    }
    cout << "целое число" << endl;
    return 0;

}

int getValue()
{
    int a;
        if (!(cin>>a))
    {
        cout<<"error"<<endl;
        abort();
    }
    return a;

}
