#include <iostream>
using namespace std;
#include "MATRIX.h"

    // ����������� � ����� ����������� - ����������� ���������
MATRIX::MATRIX(unsigned int _m, unsigned int _n)
{
        m = _m;
        n = _n;

        // �������� ������ ��� �������
        // �������� ������ ��� ������� ����������
        M = (int**) new int* [m]; // ���������� �����, ���������� ����������

        // �������� ������ ��� ������� ���������
        for (int i = 0; i < m; i++)
            M[i] = (int*)new int[n];

        // ��������� ������ M ������
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
}

    // ����������� �����������
MATRIX::MATRIX(const MATRIX& _M, int k)
{
        // ��������� ����� ������ ��� �������� ���������� ������
        m = _M.m;
        n = _M.n;

        // �������� ������ ��� M
        M = (int**) new int* [m]; // ���������� �����, ���������� ����������

        for (int i = 0; i < m; i++)
            M[i] = (int*) new int[n];

        // ��������� ����������
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j] + k;
}

    // ���������� - ����������� ������, ���������� ��� �������
MATRIX::~MATRIX()
{
        if (n > 0)
        {
            // ���������� ���������� ������ ��� ������ ������
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
            delete[] M;
}

    // ������ �������
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

    // �����, ��������� �������
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

    // ������� �������������� ��������� ������� (�������������� �� ������� � ���������� ���� int)
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

    // �������������� �������� ���� int � ������� (1x1)
MATRIX::MATRIX(int k) 
{
        m = 1; n = 1;
        M = (int**) new int* [1];
        M[0] = (int*)new int[n];
        M[0][0] = k;
}

// �������� ������������ (�������� �����������)
MATRIX MATRIX::operator = (const MATRIX& _M)
{
    if (this == &_M)
        return *this;
    if (n > 0)
    {
        // ���������� ������, ���������� ����� ��� ������� *this
        for (int i = 0; i < m; i++)
            delete[] M[i];
    }

    if (m > 0)
    {
        delete[] M;
    }

    // ����������� ������ M <= _M
    m = _M.m;
    n = _M.n;

    // �������� ������ ��� M �����
    M = (int**) new int* [m]; // ���������� �����, ���������� ����������
    for (int i = 0; i < m; i++)
        M[i] = (int*) new int[n];

    // ��������� ����������
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = _M.M[i][j];
    return *this;
}

//  �������� �[ ][ ]� � ������ � �������� �������
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

// �������� �+� � �������� ������
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

//�������� �-� � ��������� ������
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

//�������� � += � � ����������� ��������� �������� �� ���� ��������� �������
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

// �������� ���������
bool MATRIX::operator == (const MATRIX& B) const
{
    if (m != B.m && n != B.n)
        return false; // ������� � ������ ����������� ���������

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (M[i][j] != B.M[i][j])
                return false; // ������� �� �����

    return true; // ������� �����
}

// ������������� �������
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