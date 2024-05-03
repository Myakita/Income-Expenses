#ifndef QTCLASS_H
#define QTCLASS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QtClass; }
QT_END_NAMESPACE

class QtClass : public QMainWindow
{
    Q_OBJECT

public:
    QtClass(QWidget *parent = nullptr);
    ~QtClass();

private:
    Ui::QtClass *ui;
};
#endif // QTCLASS_H
