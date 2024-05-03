#include "qtclass.h"
#include "ui_qtclass.h"

QtClass::QtClass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtClass)
{
    ui->setupUi(this);
}

QtClass::~QtClass()
{
    delete ui;
}


void QtClass::on_pushButton_clicked()
{
    QVector<int> vec;
    QString str = ui->lineEdit_2->text();
    QString strneg = "-"+str;
    QString str1 = ui->lineEdit_4->text();
    QString str2 = ui->lineEdit_7->text();
    QTableWidgetItem *tbl = new QTableWidgetItem(str);
    QTableWidgetItem *tblneg = new QTableWidgetItem(strneg);
    QTableWidgetItem *tbl1 = new QTableWidgetItem(str1);
    ui->tableWidget->insertRow(0);
    if(ui->comboBox->currentText() == "Доход")
    {
        ui->tableWidget->setVerticalHeaderLabels(QStringList() << "Доход (" + str2 + ")");
        ui->tableWidget->setItem(0,0,tbl);
        ui->tableWidget->setItem(0,1,tbl1);
        vec.push_back(str.toInt());

    }
    else
    {
        ui->tableWidget->setVerticalHeaderLabels(QStringList() << "Расход (" + str2 + ")");
        ui->tableWidget->setItem(0,0,tblneg);
        ui->tableWidget->setItem(0,1,tbl1);
        vec.push_back(strneg.toInt());

    }
    ui->lineEdit_2->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_7->clear();



}


void QtClass::on_pushButton_3_clicked()
{
    ui->tableWidget->removeRow(0);
}

