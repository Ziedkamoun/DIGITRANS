#include "dialog.h"
#include "ui_dialog.h"
#include "choose.h"
#include "QPixmap"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pix("D:/Desktop/final/pic.jpg");
ui->label_pic->setPixmap(pix);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
   choose c;
    hide();
    c.exec();
}
