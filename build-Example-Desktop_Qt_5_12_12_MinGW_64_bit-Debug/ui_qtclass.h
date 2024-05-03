/********************************************************************************
** Form generated from reading UI file 'qtclass.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCLASS_H
#define UI_QTCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtClass
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_6;
    QMenuBar *menubar;
    QMenu *menuNew_File;
    QMenu *menuSave_File;
    QMenu *menuLoad_File;
    QMenu *menuExport_File;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtClass)
    {
        if (QtClass->objectName().isEmpty())
            QtClass->setObjectName(QString::fromUtf8("QtClass"));
        QtClass->resize(800, 600);
        centralwidget = new QWidget(QtClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 60, 351, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        pushButton->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 20, 171, 31));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 20, 171, 31));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(200, 120, 171, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 160, 351, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(11);
        pushButton_2->setFont(font1);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(20, 120, 171, 31));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(20, 460, 171, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 500, 351, 41));
        pushButton_3->setFont(font1);
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(200, 460, 171, 31));
        QtClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QtClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuNew_File = new QMenu(menubar);
        menuNew_File->setObjectName(QString::fromUtf8("menuNew_File"));
        menuSave_File = new QMenu(menubar);
        menuSave_File->setObjectName(QString::fromUtf8("menuSave_File"));
        menuLoad_File = new QMenu(menubar);
        menuLoad_File->setObjectName(QString::fromUtf8("menuLoad_File"));
        menuExport_File = new QMenu(menubar);
        menuExport_File->setObjectName(QString::fromUtf8("menuExport_File"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        QtClass->setMenuBar(menubar);
        statusbar = new QStatusBar(QtClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QtClass->setStatusBar(statusbar);

        menubar->addAction(menuNew_File->menuAction());
        menubar->addAction(menuSave_File->menuAction());
        menubar->addAction(menuLoad_File->menuAction());
        menubar->addAction(menuExport_File->menuAction());
        menubar->addAction(menuAbout->menuAction());

        retranslateUi(QtClass);

        QMetaObject::connectSlotsByName(QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtClass)
    {
        QtClass->setWindowTitle(QApplication::translate("QtClass", "QtClass", nullptr));
        pushButton->setText(QApplication::translate("QtClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \320\264\320\276\321\205\320\276\320\264\320\276\320\262", nullptr));
        lineEdit->setText(QApplication::translate("QtClass", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272", nullptr));
        lineEdit_2->setText(QApplication::translate("QtClass", "\320\224\320\265\320\275\321\214\320\263\320\270", nullptr));
        lineEdit_3->setText(QApplication::translate("QtClass", "\320\224\320\265\320\275\321\214\320\263\320\270", nullptr));
        pushButton_2->setText(QApplication::translate("QtClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \320\264\320\276\321\205\320\276\320\264\320\276\320\262", nullptr));
        lineEdit_4->setText(QApplication::translate("QtClass", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272", nullptr));
        lineEdit_5->setText(QApplication::translate("QtClass", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272", nullptr));
        pushButton_3->setText(QApplication::translate("QtClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\260\321\201\321\205\320\276\320\264\321\213", nullptr));
        lineEdit_6->setText(QApplication::translate("QtClass", "\320\224\320\265\320\275\321\214\320\263\320\270", nullptr));
        menuNew_File->setTitle(QApplication::translate("QtClass", "New File", nullptr));
        menuSave_File->setTitle(QApplication::translate("QtClass", "Save File", nullptr));
        menuLoad_File->setTitle(QApplication::translate("QtClass", "Load File", nullptr));
        menuExport_File->setTitle(QApplication::translate("QtClass", "Export File", nullptr));
        menuAbout->setTitle(QApplication::translate("QtClass", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtClass: public Ui_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCLASS_H
