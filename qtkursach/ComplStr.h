#ifndef __COMPLSTR__
#define __COMPLSTR__
#include "Stroka.h"

class ComplStr : public Stroka
{
public:
	ComplStr(int); //����������� ��� ����������
	ComplStr(const char*);//��������� � �������� ��������� ��-������
	ComplStr(const ComplStr&);// ����������� �����������
	~ComplStr(); // ����������

	ComplStr& operator=(const ComplStr&); //����������� ������������

	friend ComplStr operator+(const ComplStr&, const ComplStr&); //������� ��������
};
#endif