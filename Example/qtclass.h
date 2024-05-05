#ifndef QTCLASS_H
#define QTCLASS_H
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include <QMainWindow>
#include <QPdfWriter>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class QtClass; }
QT_END_NAMESPACE

class QtClass : public QMainWindow
{
    Q_OBJECT

public:
    QtClass(QWidget *parent = nullptr);
    ~QtClass();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void saveToPdf();

    int get_clicked_row_index();

    void on_actionSave_to_triggered();


    void on_actionLoad_from_triggered();
    void updateChartsAndLabel();

private:
    Ui::QtClass *ui;
    QPieSeries *series;
    QChart *chart;
    QChartView *chartview;
    QPieSeries *series2;
    QChart *chart2;
    QChartView *chartview2;

};
#endif // QTCLASS_H
