#include <iostream>
using namespace std;
#include "MATRIX.h"

    // êîíñòðóêòîð ñ äâóìÿ ïàðàìåòðàìè - êîíñòðóêòîð óìîë÷àíèÿ
MATRIX::MATRIX(unsigned int _m, unsigned int _n)
{
        m = _m;
        n = _n;

        // Âûäåëèòü ïàìÿòü äëÿ ìàòðèöû
        // Âûäåëèòü ïàìÿòü äëÿ ìàññèâà óêàçàòåëåé
        M = (int**) new int* [m]; // êîëè÷åñòâî ñòðîê, êîëè÷åñòâî óêàçàòåëåé

        // Âûäåëèòü ïàìÿòü äëÿ êàæäîãî óêàçàòåëÿ
        for (int i = 0; i < m; i++)
            M[i] = (int*)new int[n];

        // çàïîëíèòü ìàññèâ M íóëÿìè
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
}

    // êîíñòðóêòîð êîïèðîâàíèÿ
MATRIX::MATRIX(const MATRIX& _M, int k)
{
        // Ñîçäàåòñÿ íîâûé îáúåêò äëÿ êîòîðîãî âûäåëÿåòñÿ ïàìÿòü
        m = _M.m;
        n = _M.n;

        // Âûäåëèòü ïàìÿòü äëÿ M
        M = (int**) new int* [m]; // êîëè÷åñòâî ñòðîê, êîëè÷åñòâî óêàçàòåëåé

        for (int i = 0; i < m; i++)
            M[i] = (int*) new int[n];

        // çàïîëíèòü çíà÷åíèÿìè
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j] + k;
}

    // äåñòðóêòîð - îñâîáîæäàåò ïàìÿòü, âûäåëåííóþ äëÿ ìàòðèöû
MATRIX::~MATRIX()
{
        if (n > 0)
        {
            // îñâîáîäèòü âûäåëåííóþ ïàìÿòü äëÿ êàæäîé ñòðîêè
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
            delete[] M;
}

    // ìåòîäû äîñòóïà
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

    // ìåòîä, âûâîäÿùèé ìàòðèöó
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

    // ñðåäíåå àðèôìåòè÷åñêîå ýëåìåíòîâ ìàòðèöû (ïðåîáðàçîâàíèå èç ìàòðèöû â ïåðåìåííóþ òèïà int)
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

    // ïðåîáðàçîâàíèå ýëåìåíòà òèïà int â ìàòðèöó (1x1)
MATRIX::MATRIX(int k) 
{
        m = 1; n = 1;
        M = (int**) new int* [1];
        M[0] = (int*)new int[n];
        M[0][0] = k;
}

// Îïåðàöèÿ ïðèñâàèâàíèÿ (îïåðàòîð êîïèðîâàíèÿ)
MATRIX MATRIX::operator = (const MATRIX& _M)
{
    if (this == &_M)
        return *this;
    if (n > 0)
    {
        // îñâîáîäèòü ïàìÿòü, âûäåëåííóþ ðàíåå äëÿ îáúåêòà *this
        for (int i = 0; i < m; i++)
            delete[] M[i];
    }

    if (m > 0)
    {
        delete[] M;
    }

    // Êîïèðîâàíèå äàííûõ M <= _M
    m = _M.m;
    n = _M.n;

    // Âûäåëèòü ïàìÿòü äëÿ M îïÿòü
    M = (int**) new int* [m]; // êîëè÷åñòâî ñòðîê, êîëè÷åñòâî óêàçàòåëåé
    for (int i = 0; i < m; i++)
        M[i] = (int*) new int[n];

    // çàïîëíèòü çíà÷åíèÿìè
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = _M.M[i][j];
    return *this;
}

//  îïåðàöèÿ «[ ][ ]» – äîñòóï ê ýëåìåíòó ìàòðèöû
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

// îïåðàöèÿ «+» – ñëîæåíèå ìàòðèö
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

//îïåðàöèÿ «-» – âû÷èòàíèå ìàòðèö
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

//îïåðàöèÿ « += » – ïðèáàâëåíèå çàäàííîãî çíà÷åíèÿ êî âñåì ýëåìåíòàì ìàòðèöû
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

// îïåðàòîð ñðàâíåíèÿ
bool MATRIX::operator == (const MATRIX& B) const
{
    if (m != B.m && n != B.n)
        return false; // ìàòðèöû ñ ðàçíûì êîëè÷åñòâîì ýëåìåíòîâ

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (M[i][j] != B.M[i][j])
                return false; // ìàòðèöû íå ðàâíû

    return true; // ìàòðèöû ðàâíû
}

// äðóæåñòâåííûå ôóíêöèè
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
