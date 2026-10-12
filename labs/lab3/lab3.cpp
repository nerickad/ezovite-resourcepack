// Лабораторная работа №3.
// Программирование циклических вычислительных процессов
// Задание 1: вывод на экран ромба из символов '*'
// Задание 2: разность между наименьшим среди положительных
//            и наибольшим среди отрицательных чисел последовательности
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // ---------------- Задание 1 ----------------
    cout << "Задание 1. Ромб из символов '*'" << endl << endl;

    // число строк в верхней половине ромба (включая самую широкую)
    const int ROWS = 4;

    // Верхняя половина: 1, 3, 5, 7 звёздочек
    for (int i = 1; i <= ROWS; i++)
    {
        for (int j = 0; j < ROWS - i; j++)
            cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << endl;
    }
    // Нижняя половина: 5, 3, 1 звёздочка
    for (int i = ROWS - 1; i >= 1; i--)
    {
        for (int j = 0; j < ROWS - i; j++)
            cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << endl;
    }

    // ---------------- Задание 2 ----------------
    cout << endl << "Задание 2. Разность между наименьшим положительным "
         << "и наибольшим отрицательным числом" << endl << endl;

    int n;
    cout << "Введите количество чисел N: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "N должно быть больше нуля. Повторите ввод: ";
        cin >> n;
    }

    bool hasPositive = false, hasNegative = false;
    int minPositive = 0, maxNegative = 0;

    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x > 0 && (!hasPositive || x < minPositive))
        {
            minPositive = x;
            hasPositive = true;
        }
        if (x < 0 && (!hasNegative || x > maxNegative))
        {
            maxNegative = x;
            hasNegative = true;
        }
    }

    if (!hasPositive)
        cout << "В последовательности нет положительных чисел." << endl;
    if (!hasNegative)
        cout << "В последовательности нет отрицательных чисел." << endl;

    if (hasPositive && hasNegative)
    {
        cout << "Наименьшее среди положительных: " << minPositive << endl;
        cout << "Наибольшее среди отрицательных: " << maxNegative << endl;
        cout << "Разность: " << minPositive << " - (" << maxNegative << ") = "
             << minPositive - maxNegative << endl;
    }
    else
        cout << "Разность вычислить невозможно." << endl;

    return 0;
}
