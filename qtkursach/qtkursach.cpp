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

void qtkursach::on_buttontextstroka2_clicked()
{
    QString wword1 = ui.inputtextstroka1->text();
    QString wword2 = ui.inputtextstroka2->text();

    IdentStr word1(wword1.toLocal8Bit().data());
    IdentStr word2(wword2.toLocal8Bit().data());

    word1 = word1 < word2;

    QString text;
    text = QString::fromLocal8Bit(word1.GetStr(), -1);

    if (text == "yes")
    {
        ui.outputtextstroka->setText("Stroka 1 < Stroka 2");

    }
    if (text == "equal")
    {
        ui.outputtextstroka->setText("Stroka 1 == Stroka 2");

    }
    if (text == "no")
    {
        ui.outputtextstroka->setText("Stroka 1 > Sroka 2");
    }
}

void qtkursach::on_buttontextstroka3_clicked()
{
    QString rrazvorot = ui.outputtextstroka->text();

    IdentStr razvorot(rrazvorot.toLocal8Bit().data());

    razvorot = ~razvorot;

    QString text;
    text = QString::fromLocal8Bit(razvorot.GetStr(), -1);


    ui.outputtextstroka->setText(text);
}

void qtkursach::on_buttontextstroka4_clicked()
{
    QString eequality1 = ui.inputtextstroka1->text();
    
    IdentStr equality1(eequality1.toLocal8Bit().data());
    IdentStr equality2("ravenstvo");
    equality2 = equality1;

    QString text;
    text = QString::fromLocal8Bit(equality2.GetStr(), -1);


    ui.inputtextstroka2->setText(text);
}

void qtkursach::on_buttoncompstroka1_clicked()
{
    QString nnum1 = ui.inputcompstroka1->text();
    QString nnum2 = ui.inputcompstroka2->text();

    ComplStr num1(nnum1.toLocal8Bit().data());
    ComplStr num2(nnum2.toLocal8Bit().data());

    num1 = num1 + num2;
    cout << num1.GetStr() << endl;
    QString text;
    text = QString::fromLocal8Bit(num1.GetStr(), -1);

    ui.outputcompstroka->setText(text);
}

void qtkursach::on_buttoncompstroka2_clicked()
{
    QString nnum1 = ui.inputcompstroka1->text();

    ComplStr num1(nnum1.toLocal8Bit().data());
    ComplStr num2("1i1");

    num2 = num1;
    cout << num2.GetStr() << endl;
    QString text;
    text = QString::fromLocal8Bit(num2.GetStr(), -1);

    ui.inputcompstroka2->setText(text);
}

void qtkursach::on_buttonsearchletter1_clicked()
{
    QString SSlovo = ui.inputsearchletter1->text();
    QString bykva = ui.inputsearchletter2->text();
    QByteArray ba = bykva.toLocal8Bit();
    char* c_str2 = ba.data();
    IdentStr Slovo(SSlovo.toLocal8Bit().data());
    
    int result = number(Slovo, *c_str2);
    if (result == -1)
    {
        ui.inputsearchletter1->setText("No letter or Bad stroka");
        ui.outputsearchletter->setText("-");    

    }
    else 
    {
        QString text = QString::number(result);
        ui.outputsearchletter->setText(text);
    }
}

