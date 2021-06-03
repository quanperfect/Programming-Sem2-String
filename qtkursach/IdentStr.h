#include "Stroka.h"
#ifndef __IDENTSTR__
#define __IDENTSTR__
class IdentStr : public Stroka
{
public:
	IdentStr(int = 0); // ����������� ��� ����������
	IdentStr(char);// �����������, ����������� � �������� ��������� ������
	IdentStr(const char*);// �����������, ����������� � �������� ��������� ��-������
	IdentStr(const IdentStr&);// ����������� �����������
	~IdentStr(); // ����������
	IdentStr& operator=(const IdentStr&); // ����������� ������������

	friend int number(const IdentStr&, char); // ����� ������� ��������� ������� � ������
	IdentStr operator ~();
	friend IdentStr operator + (const IdentStr&, const IdentStr&); //������������ �����
	friend IdentStr operator< (const IdentStr&, const IdentStr&); //��������� �����
	friend IdentStr operator + (const IdentStr&, const char*); //������������ �����
	friend IdentStr bykva(const IdentStr&, char, int); // ����� ������� ��������� ������� � ������
};

#endif