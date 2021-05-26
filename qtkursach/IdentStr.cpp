#include "Stroka.h"
#include "IdentStr.h"
#include <iostream>
#include <string.h>

using namespace std;
extern "C" int sum(int, int);

IdentStr::IdentStr(int val) : Stroka(val)
{
	cout << "IdenStr:: IdentStr(int val): Stroka(val)" << endl;
}

IdentStr::IdentStr(char ch) : Stroka(ch)
{
	// проверка символ(строка) начинается с цифры или нет

	if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z')))
	{
		cout << "Bad Simbol, pCh[0]=" << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}

	cout << "IdentStr::IdentStr(char ch) : Stroka(ch)" << endl;
}

IdentStr::IdentStr(const char* Str) : Stroka(Str)
{
	// определяем массив указателей на ключевые слова
	const char* keyword[] = { "while", "for", "switch", "break", "return", "and", "and_eq", "asm", "auto", "break", "catch", "case", "char", "class", "const", "continue", "default", "delete", "do", "double", "else", "enum", "extern", "float", "for", "friend", "goto", "if", "inline", "int", "long", "new", "operator", "private", "protected", "public", "register", "return", "short", "signed", "sizeof", "static", "struct", "template", "this", "throw", "try", "typedef", "union", "unsigned", "virtual", "void", "volatile" };

	for (int i = 0; i < 53; i++)
	{
		if (strcmp(pCh, keyword[i]) == 0)
		{
			cout << "Bad word, pCh = " << pCh << endl;

			if (pCh) delete[] pCh;
			len = 0;

			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}

	// проверка первого символа

	if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_')))
	{
		cout << "Bad Stroka, pCh[0]=" << pCh[0] << endl;

		if (pCh) delete[] pCh;

		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}

	for (int i = 1; i < len; i++)
	{
		if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] == '_') || (pCh[i] >= '0' && pCh[i] <= '9')))
		{
			cout << "Bad Stroka,pCh[" << i << "]=" << pCh[i] << endl;

			if (pCh) delete[] pCh;

			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}

	cout << "IdentStr::IdentStr(const char* Str) : Stroka(Str)" << endl;
}

IdentStr::IdentStr(const IdentStr& from) : Stroka(from)
{
	cout << "IdentStr::IdentStr(const IdentStr& from) : Stroka(from)" << endl;
}

IdentStr:: ~IdentStr()
{
	cout << "IdentStr:: ~IdentStr()" << endl;
}

IdentStr& IdentStr:: operator=(const IdentStr& S)
{
	if (&S != this)
	{
		delete[] pCh;

		len = strlen(S.pCh);
		pCh = new char[len + 1];

		strcpy_s(pCh, len + 1, S.pCh);
	}

	cout << "IdentStr& IdentStr:: operator=(const IdentStr& S)" << endl;
	return *this;
}

int number(const IdentStr& S, char x)
{
	int i = 0, k = -1;

	while (S.pCh[i++] != '\0')
	{
		if (S.pCh[i] == (int)x)
		{
			k = i;

			cout << "symbol's number is " << endl;
			return k;
		}
	}

	if (k == -1)
	{
		cout << "That symbol doesn't exist" << endl;
	}

	return k;

	cout << "IdentStr number(const char* S, const char x)" << endl;
}

IdentStr operator + (const IdentStr& pobj1, const IdentStr& pobj2)
{
	IdentStr tmp(pobj1.Getline() + pobj2.Getline());

	int i = 0, j = 0;

	while (tmp.pCh[i++] = pobj1.pCh[j++]);
	--i;

	j = 0;

	while (tmp.pCh[i++] = pobj2.pCh[j++]);
	cout << "IdentStr operator + (const IdentStr& pobj1, const IdentStr& pobj2)" << endl;

	return tmp;
}

IdentStr operator < (const IdentStr& pobj1, const IdentStr& pobj2)
{
	int j = 0;

	IdentStr x;

	if (pobj1.len < pobj2.len)
	{
		for (int i = 0; i < pobj1.len; i++)
		{
			if (pobj1.pCh[i] < pobj2.pCh[i]) j++;
		}

		if (j != pobj1.len)
			x = "no";
		else
			x = "yes";
	}

	else
	{
		for (int i = 0; i < pobj2.len; i++)
		{
			if (pobj1.pCh[i] < pobj2.pCh[i]) j++;
		}

		if (j != pobj2.len)
			x = "no";

		else
			x = "yes";
	}

	cout << "IdentStr operator < (const IdentStr& pobj1, const IdentStr& pobj2)" << endl;

	return x;
}