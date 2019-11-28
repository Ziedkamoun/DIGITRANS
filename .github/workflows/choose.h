#ifndef CHOOSE_H
#define CHOOSE_H
#include "bus.h"
#include "dialog2.h"
#include "connextion.h"
#include <QDialog>
#include "voyage.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
namespace Ui {
class choose;
}

class choose : public QDialog
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = nullptr);
    ~choose();
    void initialiser();
    void initialiser_modifier();

    void initialiser_supp();
    QSqlQueryModel * tri();
    void refresh();


private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

   // void on_comboBox_activated(const QString &arg1);

    //void on_serie_2_activated(const QString &arg1);

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();



    void on_trouver_textChanged(const int &arg1);

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_4_activated(const QString &arg1);



    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::choose *ui;
    bus tmpbus;
    voyage tmpvoyage;
    connextion tmpconnextion;
};

#endif // CHOOSE_H
