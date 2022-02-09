#pragma once
#ifndef MATRIX_H
#define MATRIX_H
class MATRIX
{
private:
    int** M; // ìàòðèöà
    int m; // êîëè÷åñòâî ñòðîê
    int n; // êîëè÷åñòâî ñòîëáöîâ
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
    
    MATRIX(unsigned int _m = 1, unsigned int _n = 1);            // êîíñòðóêòîð ñ äâóìÿ ïàðàìåòðàìè - êîíñòðóêòîð óìîë÷àíèÿ
    MATRIX(const MATRIX& _M, int k = 0);                         // êîíñòðóêòîð êîïèðîâàíèÿ
    ~MATRIX();                                                   // äåñòðóêòîð - îñâîáîæäàåò ïàìÿòü, âûäåëåííóþ äëÿ ìàòðèöû

    // ìåòîäû äîñòóïà
    int GetMij(int i, int j);
    void SetMij(int i, int j, int value);

    void Print(const char* ObjName);                             // ìåòîä, âûâîäÿùèé ìàòðèöó

    operator int();                                              // ñðåäíåå àðèôìåòè÷åñêîå ýëåìåíòîâ ìàòðèöû (ïðåîáðàçîâàíèå èç ìàòðèöû â ïåðåìåííóþ òèïà int)
    explicit MATRIX(int k);                                      // ïðåîáðàçîâàíèå ýëåìåíòà òèïà int â ìàòðèöó (1x1)

    // ïåðåãðóçêà îïåðàöèé
    MATRIX operator = (const MATRIX& _M);                        // îïåðàöèÿ ïðèñâàèâàíèÿ (îïåðàòîð êîïèðîâàíèÿ)
    Array operator [] (int i);                                   // îïåðàöèÿ «[ ][ ]» – äîñòóï ê ýëåìåíòó ìàòðèöû
    Array operator [] (int i) const;
    MATRIX operator + (const MATRIX& B);                         // îïåðàöèÿ «+» – ñëîæåíèå ìàòðèö
    MATRIX operator - (const MATRIX& B);                         //îïåðàöèÿ «-» – âû÷èòàíèå ìàòðèö
    MATRIX operator += (const int& k);                           //îïåðàöèÿ « += » – ïðèáàâëåíèå çàäàííîãî çíà÷åíèÿ êî âñåì ýëåìåíòàì ìàòðèöû
    bool operator == (const MATRIX& B) const;                    // îïåðàòîð ñðàâíåíèÿ

    // äðóæåñòâåííûå ôóíêöèè
    friend MATRIX operator +(const MATRIX& A, const MATRIX& B);
    friend MATRIX operator -(const MATRIX& A, const MATRIX& B);
};
#endif

