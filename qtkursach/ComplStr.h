#ifndef __COMPLSTR__
#define __COMPLSTR__
#include "Stroka.h"

class ComplStr : public Stroka
{
public:
	ComplStr(int); //конструктор без параметров
	ComplStr(const char*);//принимает в качестве параметра си-строку
	ComplStr(const ComplStr&);// конструктор копирования
	~ComplStr(); // деструктор

	ComplStr& operator=(const ComplStr&); //конструктор присваивания

	friend ComplStr operator+(const ComplStr&, const ComplStr&); //функция сложения
};
#endif