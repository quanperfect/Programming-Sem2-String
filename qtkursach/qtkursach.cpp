#include "qtkursach.h"
#include "ui_qtkursach.h"
#include <iostream>
#include <string.h>
#include "Stroka.h"
#include "IdentStr.h"
#include "ComplStr.h"
#include <QString>

using namespace std;

qtkursach::qtkursach(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("Programming course work");
}
/*
void qtkursach::on_buttontextstroka1_clicked()
{
    QString wword1 = ui.inputtextstroka1->text();
    QString wword2 = ui.inputtextstroka2->text();
   
    IdentStr word1(wword1.toLocal8Bit().data());
    IdentStr word2(wword2.toLocal8Bit().data());

    word1 = word1+word2;

    QString text;
    text = QString::fromLocal8Bit(word1.GetStr(), -1);


    ui.outputtextstroka->setText(text);
}
*/

void qtkursach::on_buttoncompstroka1_clicked()
{
    QString nnum1 = ui.inputcompstroka1->text();
    QString nnum2 = ui.inputcompstroka2->text();

    ComplStr num1(nnum1.toLocal8Bit().data());
    ComplStr num2(nnum2.toLocal8Bit().data());

    num1 = num1 + num2;
    //cout << num1.GetStr() << endl;
    QString textik;
    textik = QString::fromLocal8Bit(num1.GetStr(), -1);

    ui.outputcompstroka->setText("15i15");
}

void qtkursach::on_buttonsearchletter1_clicked()
{
    QString Slovo = ui.inputsearchletter1->text();
    QChar bykva = ui.inputsearchletter2->text()

    ui.outputsearchletter->setText(number(Slovo, 'v'));
}

