//ComplStr.cpp
#include "Stroka.h"
#include "ComplStr.h"
#include <iostream>
#include <string.h>
using namespace std;
extern "C" int sum(int, int);
ComplStr::ComplStr(int val) : Stroka(val)
{
    cout << "ComplStr::ComplStr(int val) : Stroka(val)" << endl;
}
ComplStr::ComplStr(const char* C) : Stroka(C)
{
    int i = -1, p = 0;
    char* a, * b;
    for (int j = 0; j < len - 1; j++)
    {
        if (pCh[j] == 'i')
        {
            i = j;
        }
    }
    if (i == -1)
    {
        cout << "Bad number: i not detected " << C << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    a = new char[i + 1];
    b = new char[len - i + 2];
    for (int j = 0; j < i; j++)
    {
        a[p] = pCh[j];
        p++;
    }
    a[p] = '\0';
    p = 0;
    for (int j = (i + 1); j < len + 1; j++)
    {
        b[p] = pCh[j];
        p++;
    }
    b[p] = '\0';
    if (!((a[0] == '+' || a[0] == '-') || (a[0] >= '1' && a[0] <= '9')))
    {
        cout << "Bad number: " << C << endl;
        if (a) delete[] a;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int j = 1; j < i; j++)
    {
        if (!(a[j] >= '0' && a[j] <= '9'))
        {
            cout << "Bad number: " << C << endl;
            if (a) delete[] a;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    if (!((b[0] == '+' || b[0] == '-') || (b[0] >= '1' && b[0] <= '9')))
    {
        cout << "Bad number: " << C << endl;
        if (b) delete[] b;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int j = 1; j < (len - i - 1); j++)
    {
        if (!(b[j] >= '0' && b[j] <= '9'))
        {
            cout << "Bad number: " << C << endl;
            if (b) delete[] b;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    cout << "ComplStr::ComplStr(const char* S): Stroka(S)" << endl;
}
ComplStr::ComplStr(const ComplStr& C) : Stroka(C)
{
    cout << "ComplStr::ComplStr(const ComplStr& C) : Stroka(C)" << endl;
}
ComplStr::~ComplStr()
{
    cout << "ComplStr::~ComplStr()" << endl;
}
ComplStr& ComplStr:: operator=(const ComplStr& C)
{
    if (&C != this)
    {
        delete[] pCh;
        len = strlen(C.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, C.pCh);
    }
    cout << "IdentStr& IdentStr:: operator=(const IdentStr& C)" << endl;
    return *this;
}
ComplStr operator+(const ComplStr& obj1, const ComplStr& obj2)
{
    if (obj1.pCh[0] == 0 || obj2.pCh[0] == 0)
    {
        cout << "wrong number!" << endl;
        return 0;
    }
    int i = 0, p = 0, nre1, nre2, nim1, nim2;
    char* re1, * re2, * im1, * im2;
    ComplStr i1(obj1), i2(obj2);
    // first number
    for (int j = 0; j < i1.len - 1; j++)
    {
        if (i1.pCh[j] == 'i')
        {
            i = j;
        }
    }
    re1 = new char[i + 1];
    im1 = new char[i1.len - i + 2];
    for (int j = 0; j < i; j++)
    {
        re1[p] = i1.pCh[j];
        p++;
    }
    re1[p] = '\0';
    p = 0;
    for (int j = (i + 1); j < i1.len + 1; j++)
    {
        im1[p] = i1.pCh[j];
        p++;
    }
    im1[p] = '\0';
    //second number
    i = 0;
    p = 0;
    for (int j = 0; j < i2.len - 1; j++)
    {
        if (i2.pCh[j] == 'i')
        {
            i = j;
        }
    }
    re2 = new char[i + 1];
    im2 = new char[i2.len - i + 2];
    for (int j = 0; j < i; j++)
    {
        re2[p] = i2.pCh[j];
        p++;
    }
    re2[p] = '\0';
    p = 0;
    for (int j = (i + 1); j < i2.len + 1; j++)
    {
        im2[p] = i2.pCh[j];
        p++;
    }
    im2[p] = '\0';
    // сложение
    nre1 = atoi(re1);
    nre2 = atoi(re2);
    char* pTmpCh;
    int A = sum(nre1, nre2);
    if (strlen(re1) >= strlen(re2))
    {
        pTmpCh = new char[strlen(re1) + 2];
        _itoa_s(A, pTmpCh, strlen(re1) + 2, 10);
    }
    else
    {
        pTmpCh = new char[strlen(re2) + 2];
        _itoa_s(A, pTmpCh, strlen(re2) + 2, 10);
    }
    if (re1) delete[] re1;
    re1 = pTmpCh;

    /// 
    nim1 = atoi(im1);
    nim2 = atoi(im2);
    char* pTmpCh1;
    int B = sum(nim1, nim2);
    if (strlen(im1) >= strlen(im2))
    {
        pTmpCh1 = new char[strlen(im1) + 2];
        _itoa_s(B, pTmpCh1, strlen(im1) + 2, 10);
    }
    else
    {
        pTmpCh1 = new char[strlen(im2) + 2];
        _itoa_s(B, pTmpCh1, strlen(im2) + 2, 10);
    }

    if (im1) delete[] im1;
    im1 = pTmpCh1;
    if (re2) delete[] re2;
    if (im2) delete[] im2;
    // вывод числа
    ComplStr tmp(strlen(re1) + strlen(im1) + 1);
    int  j = 0;
    i = 0;
    while (tmp.pCh[i++] = re1[j++]);
    --i;
    tmp.pCh[i] = 'i';
    ++i;
    j = 0;
    while (tmp.pCh[i++] = im1[j++]);

    cout << "ComplStr operator+(const ComplStr& obj1, const ComplStr& obj2)" << endl;
    return tmp;
}