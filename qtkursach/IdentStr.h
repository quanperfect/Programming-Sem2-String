#include "Stroka.h"
#ifndef __IDENTSTR__
#define __IDENTSTR__
class IdentStr : public Stroka
{
public:
	IdentStr(int = 0); // конструктор без параметров
	IdentStr(char);// конструктор, принимающий в качестве параметра символ
	IdentStr(const char*);// конструктор, принимающий в качестве параметра си-строку
	IdentStr(const IdentStr&);// конструктор копирования
	~IdentStr(); // деструктор
	IdentStr& operator=(const IdentStr&); // конструктор присваивания

	friend int number(const IdentStr&, char); // поиск первого вхождения символа в строку

	friend IdentStr operator + (const IdentStr&, const IdentStr&); //конкатенация строк
	friend IdentStr operator< (const IdentStr&, const IdentStr&); //сравнение строк
};

#endif