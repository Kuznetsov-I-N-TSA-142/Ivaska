#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum FillMethod { RANDOM, MANUAL };

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void validateArraySize(int size);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
int getArraySize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getInteger();

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* array, int size);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandomly(int* array, int size, int min, int max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void validateRange(int min, int max);

/**
 * @brief находит сумму элементов массива, имеющих нечетное значение.
 * @param arr Массив целых чисел.
 * @param n Размер массива.
 * @return Сумма элементов массива с нечетными значениями.
 */
int sumOddElements(const int array[], int size);

/**
 * @brief заменяет второй элемент массива на максимальный среди отрицательных.
 * Если в массиве нет отрицательных чисел, второй элемент остается без изменений.
 * @param arr Массив целых чисел.
 * @param n Размер массива.
 */
void replaceSecondWithMaxNegative(int array[], int size);

/**
 * @brief  выводит индексы элементов массива, значения которых больше заданного числа A.
 * @param arr Массив целых чисел.
 * @param n Размер массива.
 * @param a Заданное число a.
 */
void printIndexesGreaterThan(const int array[], int size, int threshold);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayManually(int* array, int size, int min, int max);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main() {
    setlocale(LC_ALL, "Russian");
    int size = getArraySize();
    int* array = new int[size];

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int min = getInteger();
    int max = getInteger();
    validateRange(min, max);

    cout << "Выберите способ заполнения массива:" << endl;
    cout << "0 - Случайное заполнение" << endl;
    cout << "1 - Ручное заполнение" << endl;

    int choice = getInteger();
    switch (choice) {
    case RANDOM:
        fillArrayRandomly(array, size, min, max);
        break;
    case MANUAL:
        fillArrayManually(array, size, min, max);
        break;
    default:
        cout << "Некорректный выбор. " << endl;
        delete[] array;
        return -1;
    }

    printArray(array, size);

    cout << "Сумма нечетных элементов: " << sumOddElements(array, size) << endl;

    int threshold = getInteger();
    cout << "Введите значение для сравнения: ";
    printIndexesGreaterThan(array, size, threshold);

    replaceSecondWithMaxNegative(array, size);

    cout << "Массив после замены второго элемента: " << endl;
    printArray(array, size);

    delete[] array; // Освобождение памяти массива
    return 0;
}
// Проверка размера массива
void validateArraySize(int size) {
    if (size <= 0) {
        cout << "Неправильный размер массива. Введите положительное число." << endl;
        exit(1);
    }
}
// Считывание размера массива от пользователя
int getArraySize() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    validateArraySize(size);
    return size;
}
// Считывание целого числа от пользователя
int getInteger() {
    int number;
    cin >> number;
    if (cin.fail()) {
        cout << "Неправильный ввод данных"<<endl;
        abort();
    }
    return number;
}
// Вывод массива на экран
void printArray(const int* array, int size) {
    cout << "Элементы массива:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
// Заполнение массива случайными числами в заданном диапазоне
void fillArrayRandomly(int* array, int size, int min, int max) {
    srand(time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % (max - min + 1) + min;
    }
}
    //Проверка диапазона значений
void validateRange(int min, int max) {
    if (min >= max) {
        cout << "Неверный диапазон. Минимальное значение должно быть меньше максимального." << endl;
        exit(1);
    }
}
// Нахождение суммы элементов массива с нечетными значениями
int sumOddElements(const int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] % 2 != 0) {
            sum += array[i];
        }
    }
    return sum;
}
// Замена второго элемента массива на максимальный среди отрицательных
void replaceSecondWithMaxNegative(int array[], int size) {
    int maxNegative = INT_MIN;
    bool foundNegative = false;

    for (int i = 0; i < size; ++i) {
        if (array[i] < 0 && array[i] > maxNegative) {
            maxNegative = array[i];
            foundNegative = true;
        }
    }

    if (foundNegative) {
        array[1] = maxNegative;
    }
}
// Вывод индексов элементов массива, значения которых больше заданного числа
void printIndexesGreaterThan(const int array[], int size, int threshold) {
    cout << "Индексы элементов, больших " << threshold << ":" << endl;
    for (int i = 0; i < size; ++i) {
        if (array[i] > threshold) {
            cout << i << " ";
        }
    }
    cout << endl;
}
// Заполнение массива вручную
void fillArrayManually(int* array, int size, int min, int max) {
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; ++i) {
        int number;
        do {
            number = getInteger();
            if (number < min || number > max) {
                cout << "Число должно быть в диапазоне [" << min << ", " << max << "]. Повторите ввод." << endl;
            }
        } while (number < min || number > max);
        array[i] = number;
    }
}
