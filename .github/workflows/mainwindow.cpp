#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "QPixmap"
#include "QMessageBox"
#include <QSqlQuery>
#include <QSqlQueryModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/Desktop/final/pic.jpg");
ui->label_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    if((ui->lineEdit->text()=="amine")&&(ui->lineEdit_2->text()=="esprit18"))
  { Dialog d;
    hide();
    d.exec();}
    else{    QMessageBox::information(nullptr, QObject::tr("Probleme"),"Verifié username ou password");}

}
