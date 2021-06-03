#pragma once

#include <QtWidgets/QWidget>
#include "ui_qtkursach.h"

class qtkursach : public QWidget
{
    Q_OBJECT

public:
    qtkursach(QWidget *parent = Q_NULLPTR);

private slots:
    void on_buttontextstroka1_clicked();
    void on_buttontextstroka2_clicked();
    void on_buttontextstroka3_clicked();
    void on_buttontextstroka4_clicked();
    void on_buttoncompstroka1_clicked();
    void on_buttoncompstroka2_clicked();
    void on_buttonsearchletter1_clicked();

private:
    Ui::qtkursachClass ui;

};
