#include "qtkursach.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <string.h>
#include "Stroka.h"
#include "IdentStr.h"
#include "ComplStr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	a.setWindowIcon(QIcon("1835942.png"));
    qtkursach w;
    w.show();
	IdentStr Slovo("Kursovaya");
	IdentStr word1("");
	IdentStr word2("abcxyz");
	IdentStr destructortest("destructortest");
	ComplStr num1("-13i356");
	ComplStr num2("15i-156");

	Stroka* pStr[7];

	pStr[0] = new IdentStr(word1 + word2);
	pStr[1] = new IdentStr(word1 < word2);
	pStr[2] = new IdentStr("goto");
	pStr[3] = new ComplStr(num1 + num2);
	pStr[4] = new ComplStr("-14i010");
	num1 = num2;
	pStr[5] = new ComplStr(num1);
	//pStr[6] = new IdentStr(destructortest);
	
	bykva(destructortest, '1', 0);
	destructortest.Show();



	((IdentStr*)pStr[0])->Show();
	((IdentStr*)pStr[1])->Show();
	((IdentStr*)pStr[2])->Show();

	std::cout << number(Slovo, 'v') << std::endl;

	((ComplStr*)pStr[3])->Show();
	((ComplStr*)pStr[4])->Show();
	((ComplStr*)pStr[5])->Show();
	std::cout << "----------test--------------" << std::endl;
//	std::cout << ((IdentStr*)pStr[6])->GetStr() << std::endl;


	
    return a.exec();
}
