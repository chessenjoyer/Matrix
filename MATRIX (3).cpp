#include <iostream>
using namespace std;
#include "MATRIX.h"

    // конструктор с двумя параметрами - конструктор умолчания
MATRIX::MATRIX(unsigned int _m, unsigned int _n)
{
        m = _m;
        n = _n;

        // Выделить память для матрицы
        // Выделить память для массива указателей
        M = (int**) new int* [m]; // количество строк, количество указателей

        // Выделить память для каждого указателя
        for (int i = 0; i < m; i++)
            M[i] = (int*)new int[n];

        // заполнить массив M нулями
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
}

    // конструктор копирования
MATRIX::MATRIX(const MATRIX& _M, int k)
{
        // Создается новый объект для которого выделяется память
        m = _M.m;
        n = _M.n;

        // Выделить память для M
        M = (int**) new int* [m]; // количество строк, количество указателей

        for (int i = 0; i < m; i++)
            M[i] = (int*) new int[n];

        // заполнить значениями
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j] + k;
}

    // деструктор - освобождает память, выделенную для матрицы
MATRIX::~MATRIX()
{
        if (n > 0)
        {
            // освободить выделенную память для каждой строки
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
            delete[] M;
}

    // методы доступа
int MATRIX::GetMij(int i, int j)
{
        if ((m > 0) && (n > 0))
            return M[i][j];
        else
            return 0;
}

void MATRIX::SetMij(int i, int j, int value)
{
        if ((i < 0) || (i >= m))
            return;
        if ((j < 0) || (j >= n))
            return;
        M[i][j] = value;
}

    // метод, выводящий матрицу
void MATRIX::Print(const char* ObjName)
{
        cout << "Object: " << ObjName << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << "---------------------" << endl << endl;
}

    // среднее арифметическое элементов матрицы (преобразование из матрицы в переменную типа int)
MATRIX::operator int() 
{
        int sum = 0;
        int k = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) 
            {
                k++;
                sum += M[i][j];
            }
        return sum / k;
}

    // преобразование элемента типа int в матрицу (1x1)
MATRIX::MATRIX(int k) 
{
        m = 1; n = 1;
        M = (int**) new int* [1];
        M[0] = (int*)new int[n];
        M[0][0] = k;
}

// Операция присваивания (оператор копирования)
MATRIX MATRIX::operator = (const MATRIX& _M)
{
    if (this == &_M)
        return *this;
    if (n > 0)
    {
        // освободить память, выделенную ранее для объекта *this
        for (int i = 0; i < m; i++)
            delete[] M[i];
    }

    if (m > 0)
    {
        delete[] M;
    }

    // Копирование данных M <= _M
    m = _M.m;
    n = _M.n;

    // Выделить память для M опять
    M = (int**) new int* [m]; // количество строк, количество указателей
    for (int i = 0; i < m; i++)
        M[i] = (int*) new int[n];

    // заполнить значениями
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = _M.M[i][j];
    return *this;
}

//  операция «[ ][ ]» – доступ к элементу матрицы
MATRIX::Array MATRIX::operator [](int i)
{
    if (0 <= i && i < m)
        return Array(M[i], n);
}
MATRIX::Array MATRIX::operator [](int i) const
{
    if (0 <= i && i < m)
        return Array(M[i], n);
}

// операция «+» – сложение матриц
MATRIX MATRIX::operator + (const MATRIX& B)
{
    if (m == B.m && n == B.n) {
        unsigned int _m, _n;
        _m = m, _n = n;
        MATRIX C(_m, _n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] = M[i][j] + B[i][j];
            }
        }
        return C;
    }
}

//операция «-» – вычитание матриц
MATRIX MATRIX::operator - (const MATRIX& B)
{
    if (m == B.m && n == B.n) {
        unsigned int _m, _n;
        _m = m, _n = n;
        MATRIX C(_m, _n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] = M[i][j] - B[i][j];
            }
        }
        return C;
    }
    else exit(1);
}

//операция « += » – прибавление заданного значения ко всем элементам матрицы
MATRIX MATRIX::operator += (const int& k)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = M[i][j] + k;
        }
    }
    return *this;
}

// оператор сравнения
bool MATRIX::operator == (const MATRIX& B) const
{
    if (m != B.m && n != B.n)
        return false; // матрицы с разным количеством элементов

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (M[i][j] != B.M[i][j])
                return false; // матрицы не равны

    return true; // матрицы равны
}

// дружественные функции
MATRIX operator +(const MATRIX& A, const MATRIX& B) {
    if (A.m == B.m && A.n == B.n) {
        unsigned int _m, _n;
        _m = A.m, _n = A.n;
        MATRIX C(_m, _n);
        for (int i = 0; i < A.m; i++)
        {
            for (int j = 0; j < A.n; j++)
            {
                C.M[i][j] = A.M[i][j] + B.M[i][j];
            }
        }
        return C;
    }
}
MATRIX operator -(const MATRIX& A, const MATRIX& B) {
    if (A.m == B.m && A.n == B.n) {
        unsigned int _m, _n;
        _m = A.m, _n = A.n;
        MATRIX C(_m, _n);
        for (int i = 0; i < A.m; i++)
        {
            for (int j = 0; j < A.n; j++)
            {
                C.M[i][j] = A.M[i][j] - B.M[i][j];
            }
        }
        return C;
    }
}