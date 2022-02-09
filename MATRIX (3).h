#pragma once
#ifndef MATRIX_H
#define MATRIX_H
class MATRIX
{
private:
    int** M; // �������
    int m; // ���������� �����
    int n; // ���������� ��������
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
    
    MATRIX(unsigned int _m = 1, unsigned int _n = 1);            // ����������� � ����� ����������� - ����������� ���������
    MATRIX(const MATRIX& _M, int k = 0);                         // ����������� �����������
    ~MATRIX();                                                   // ���������� - ����������� ������, ���������� ��� �������

    // ������ �������
    int GetMij(int i, int j);
    void SetMij(int i, int j, int value);

    void Print(const char* ObjName);                             // �����, ��������� �������

    operator int();                                              // ������� �������������� ��������� ������� (�������������� �� ������� � ���������� ���� int)
    explicit MATRIX(int k);                                      // �������������� �������� ���� int � ������� (1x1)

    // ���������� ��������
    MATRIX operator = (const MATRIX& _M);                        // �������� ������������ (�������� �����������)
    Array operator [] (int i);                                   // �������� �[ ][ ]� � ������ � �������� �������
    Array operator [] (int i) const;
    MATRIX operator + (const MATRIX& B);                         // �������� �+� � �������� ������
    MATRIX operator - (const MATRIX& B);                         //�������� �-� � ��������� ������
    MATRIX operator += (const int& k);                           //�������� � += � � ����������� ��������� �������� �� ���� ��������� �������
    bool operator == (const MATRIX& B) const;                    // �������� ���������

    // ������������� �������
    friend MATRIX operator +(const MATRIX& A, const MATRIX& B);
    friend MATRIX operator -(const MATRIX& A, const MATRIX& B);
};
#endif

