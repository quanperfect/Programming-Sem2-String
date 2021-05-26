#ifndef __STROKA__
#define __STROKA__

class Stroka
{
protected:
	int len;
	char* pCh;
public:
	Stroka(int = 0); // конструктор без параметров
	Stroka(char); // конструктор, принимающий в качестве параметра символ
	Stroka(const char*); //конструктор, принимающий в качестве параметра си-строку
	Stroka(const Stroka&); // конструктор копирования
	~Stroka(); //деструктор

	char* GetStr(void) const
	{
		return pCh;
	}

	int Getline(void) const
	{
		return len;
	}

	void Show(void);
};
#endif