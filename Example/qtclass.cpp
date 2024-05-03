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

