#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

// Прототипы функций
void validateArraySize(size_t size);
size_t getArraySize();
int getInteger();
void printArray(const int* array, size_t size);
void fillArrayRandomly(int* array, size_t size, int min, int max);
void validateRange(int min, int max);
int sumOddElements(const int array[], size_t size);
void replaceSecondWithMaxNegative(int array[], size_t size);
void printIndexesGreaterThan(const int array[], size_t size, int threshold);
void fillArrayManually(int* array, size_t size, int min, int max);
int getFirstNegative(const int* array, size_t size);
int getFirstN(const int* array, size_t size, int n);

int main() {
    size_t size = getArraySize(); // Получаем размер массива

    int* array = new int[size]; // Создаем динамический массив

    int min, max;
    cout << "Введите минимальное значение диапазона: ";
    cin >> min;
    cout << "Введите максимальное значение диапазона: ";
    cin >> max;
    validateRange(min, max); // Проверка диапазона значений

    fillArrayRandomly(array, size, min, max); // Заполняем массив случайными числами
    printArray(array, size); // Выводим массив

    cout << "Сумма нечетных элементов: " << sumOddElements(array, size) << endl;

    replaceSecondWithMaxNegative(array, size); // Замена второго элемента на максимальный отрицательный
    printArray(array, size); // Выводим массив после замены

    int threshold;
    cout << "Введите пороговое значение для индексов: ";
    cin >> threshold;
    printIndexesGreaterThan(array, size, threshold); // Вывод индексов элементов, превышающих пороговое значение

    fillArrayManually(array, size, min, max); // Ввод массива вручную
    printArray(array, size); // Выводим массив после ручного ввода

    delete[] array; // Освобождение памяти массива
    return 0;
}

// Проверка размера массива
void validateArraySize(size_t size) {
    if (size <= 0) {
        cout << "Неправильный размер массива. Введите положительное число." << endl;
        exit(1);
    }
}

// Считывание размера массива от пользователя
size_t getArraySize() {
    size_t size;
    cout << "Введите размер массива: ";
    cin >> size;
    validateArraySize(size);
    return size;
}

int getInteger() {
    int number;
    cin >> number;
    if (cin.fail()) {
        cout << "Неправильный ввод данных" << endl;
        abort();
    }
    return number;
}

// Вывод массива на экран
void printArray(const int* array, size_t size) {
    cout << "Элементы массива:" << endl;
    for (size_t i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Заполнение массива случайными числами в заданном диапазоне
void fillArrayRandomly(int* array, size_t size, int min, int max) {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел
    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() % (max - min + 1) + min;
    }
}

// Проверка диапазона значений
void validateRange(int min, int max) {
    if (min >= max) {
        cout << "Неверный диапазон. Минимальное значение должно быть меньше максимального." << endl;
        exit(1);
    }
}

// Нахождение суммы элементов массива с нечетными значениями
int sumOddElements(const int array[], size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] % 2 != 0) {
            sum += array[i];
        }
    }
    return sum;
}

// Поиск первого отрицательного числа в массиве
int getFirstNegative(const int* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] < 0) {
            return array[i];
        }
    }
    return 0; // Если отрицательных чисел нет, возвращаем 0
}


// Замена второго элемента массива на максимальный среди отрицательных
void replaceSecondWithMaxNegative(int array[], size_t size) {
    if (size < 2) return; // Если размер меньше 2, ничего не делаем

    int maxNegative = getFirstNegative(array, size); // Используем первое отрицательное число 
    bool foundNegative = false;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] < 0 && array[i] > maxNegative) {
            maxNegative = array[i];
            foundNegative = true;
        }
    }

    if (foundNegative) {
        array[1] = maxNegative; // Заменяем второй элемент массива на максимальное отрицательное число
    }
}

// Вывод индексов элементов массива, больших заданного значения
void printIndexesGreaterThan(const int array[], size_t size, int threshold) {
    cout << "Индексы элементов, больших " << threshold << ":" << endl;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] > threshold) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Заполнение массива вручную пользователем
void fillArrayManually(int* array, size_t size, int min, int max) {
    cout << "Введите " << size << " элементов массива в диапазоне от " << min << " до " << max << ":" << endl;
    for (size_t i = 0; i < size; ++i) {
        int element;
        do {
            cin >> element;
            if (element < min || element > max) {
                cout << "Введите число в диапазоне от " << min << " до " << max << ": ";
            }
        } while (element < min || element > max);
        array[i] = element;
    }
}

// Поиск первого элемента массива, большего или равного заданному значению
int getFirstN(const int* array, size_t size, int n) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] >= n) {
            return array[i];
        }
    }
    return -1; // Значение не найдено
}
