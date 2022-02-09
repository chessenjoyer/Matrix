#pragma once
#ifndef MATRIX_H
#define MATRIX_H
class MATRIX
{
private:
    int** M; // матрица
    int m; // количество строк
    int n; // количество столбцов
    class Array
    {
    private: int* p; int size;
    public:
        Array(int* p, int size) : p(p), size(size) {}
        int& operator [](int j)
        {
            if (0 <= j && j < size)
                return p[j];
        }
        int operator [](int j) const
        {
            if (0 <= j && j < size)
                return p[j];
        }
    };
public:
    
    MATRIX(unsigned int _m = 1, unsigned int _n = 1);            // конструктор с двум€ параметрами - конструктор умолчани€
    MATRIX(const MATRIX& _M, int k = 0);                         // конструктор копировани€
    ~MATRIX();                                                   // деструктор - освобождает пам€ть, выделенную дл€ матрицы

    // методы доступа
    int GetMij(int i, int j);
    void SetMij(int i, int j, int value);

    void Print(const char* ObjName);                             // метод, вывод€щий матрицу

    operator int();                                              // среднее арифметическое элементов матрицы (преобразование из матрицы в переменную типа int)
    explicit MATRIX(int k);                                      // преобразование элемента типа int в матрицу (1x1)

    // перегрузка операций
    MATRIX operator = (const MATRIX& _M);                        // операци€ присваивани€ (оператор копировани€)
    Array operator [] (int i);                                   // операци€ Ђ[ ][ ]ї Ц доступ к элементу матрицы
    Array operator [] (int i) const;
    MATRIX operator + (const MATRIX& B);                         // операци€ Ђ+ї Ц сложение матриц
    MATRIX operator - (const MATRIX& B);                         //операци€ Ђ-ї Ц вычитание матриц
    MATRIX operator += (const int& k);                           //операци€ Ђ += ї Ц прибавление заданного значени€ ко всем элементам матрицы
    bool operator == (const MATRIX& B) const;                    // оператор сравнени€

    // дружественные функции
    friend MATRIX operator +(const MATRIX& A, const MATRIX& B);
    friend MATRIX operator -(const MATRIX& A, const MATRIX& B);
};
#endif

