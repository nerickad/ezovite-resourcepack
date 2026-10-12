// Лабораторная работа №4.
// Программирование циклических процессов с использованием функций
// Задание 1: определить максимальный элемент среди положительных нечётных
// и минимальный среди положительных чётных элементов целочисленного
// массива X. Удалить из массива все нулевые значения, вывести сообщение,
// сколько элементов было удалено.
#include <iostream>
#include <clocale>

using namespace std;

const int MAX_N = 100; // максимальный размер массива

// Ввод размера массива с проверкой корректности
int inputSize()
{
    int n;
    cout << "Введите количество элементов массива (1.." << MAX_N << "): ";
    cin >> n;
    while (n < 1 || n > MAX_N)
    {
        cout << "Некорректный размер. Повторите ввод: ";
        cin >> n;
    }
    return n;
}

// Ввод элементов массива
void inputArray(int x[], int n)
{
    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

// Вывод элементов массива
void printArray(const int x[], int n)
{
    if (n == 0)
    {
        cout << "(массив пуст)";
    }
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    cout << endl;
}

// Поиск максимального среди положительных нечётных элементов.
// Возвращает true, если такой элемент найден; значение записывается в result.
bool maxPositiveOdd(const int x[], int n, int& result)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (x[i] > 0 && x[i] % 2 != 0 && (!found || x[i] > result))
        {
            result = x[i];
            found = true;
        }
    }
    return found;
}

// Поиск минимального среди положительных чётных элементов.
// Возвращает true, если такой элемент найден; значение записывается в result.
bool minPositiveEven(const int x[], int n, int& result)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (x[i] > 0 && x[i] % 2 == 0 && (!found || x[i] < result))
        {
            result = x[i];
            found = true;
        }
    }
    return found;
}

// Удаление всех нулевых элементов массива.
// Размер массива n уменьшается;
// функция возвращает количество удалённых элементов.
int removeZeros(int x[], int& n)
{
    int k = 0; // количество оставшихся (ненулевых) элементов
    for (int i = 0; i < n; i++)
    {
        if (x[i] != 0)
        {
            x[k] = x[i];
            k++;
        }
    }
    int removed = n - k;
    n = k;
    return removed;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int x[MAX_N];
    int n = inputSize();
    inputArray(x, n);

    cout << endl << "Исходный массив: ";
    printArray(x, n);

    int maxOdd, minEven;
    if (maxPositiveOdd(x, n, maxOdd))
        cout << "Максимальный среди положительных нечётных элементов: "
             << maxOdd << endl;
    else
        cout << "Положительных нечётных элементов в массиве нет." << endl;

    if (minPositiveEven(x, n, minEven))
        cout << "Минимальный среди положительных чётных элементов: "
             << minEven << endl;
    else
        cout << "Положительных чётных элементов в массиве нет." << endl;

    int removed = removeZeros(x, n);
    cout << endl << "Удалено нулевых элементов: " << removed << endl;
    cout << "Массив после удаления нулей: ";
    printArray(x, n);

    return 0;
}
