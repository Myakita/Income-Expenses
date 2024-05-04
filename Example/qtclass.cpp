#include "qtclass.h"
#include "ui_qtclass.h"
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>

QtClass::QtClass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtClass)
{
    // Первая диаграмма (Доходы)
    ui->setupUi(this);
    series = new QPieSeries();
    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Доходы");
    chartview = new QChartView(chart);
    chartview->setMinimumSize(200, 200);

    // Вторая диаграмма (Расходы)
    series2 = new QPieSeries();
    chart2 = new QChart();
    chart2->addSeries(series2);
    chart2->setTitle("Расходы");
    chartview2 = new QChartView(chart2);
    chartview2->setMinimumSize(200, 200);

    QHBoxLayout *layout = static_cast<QHBoxLayout*>(ui->horizontalFrame->layout());
    layout->addWidget(chartview);
    layout->addWidget(chartview2);

    // Получаем указатель на действие "Save File"
    QAction *exportAction = ui->menuExport_File->actions().at(0);  // Предполагаем, что это первое действие в меню

    // Подключаем сигнал triggered() к слоту saveToPdf()
    connect(exportAction, &QAction::triggered, this, &QtClass::saveToPdf);





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

        bool ok;
        int value = str.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Ошибка", "Некорректный ввод данных");
            return;
        }
        series->append(str2, value);
        chart->update();

    }
    else
    {
        ui->tableWidget->setVerticalHeaderLabels(QStringList() << "Расход (" + str2 + ")");
        ui->tableWidget->setItem(0,0,tblneg);
        ui->tableWidget->setItem(0,1,tbl1);
        vec.push_back(strneg.toInt());

        bool ok;
        int value = str.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Ошибка", "Некорректный ввод данных");
            return;
        }
        series2->append(str2, value);

        chart2->update();

    }
    ui->lineEdit_2->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_7->clear();

}


void QtClass::on_pushButton_3_clicked()
{
    ui->tableWidget->removeRow(0);
}

void QtClass::saveToPdf()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить как PDF", QDir::homePath(), "PDF (*.pdf)");
    if (!fileName.isEmpty()) {
        QPdfWriter writer(fileName);
        writer.setPageSize(QPagedPaintDevice::A4);

        QPainter painter(&writer);

        // Сохраняем таблицу в QPixmap и масштабируем
        QPixmap tablePixmap = ui->tableWidget->grab();
        tablePixmap = tablePixmap.scaledToWidth(writer.width() * 0.8, Qt::SmoothTransformation);
        painter.drawPixmap(10, 10, tablePixmap);

        // Сохраняем диаграммы в QPixmap и масштабируем
        QPixmap chartPixmap1 = chartview->grab();
        chartPixmap1 = chartPixmap1.scaledToWidth(writer.width() * 0.4, Qt::SmoothTransformation);
        QPixmap chartPixmap2 = chartview2->grab();
        chartPixmap2 = chartPixmap2.scaledToWidth(writer.width() * 0.4, Qt::SmoothTransformation);

        // Рисуем диаграммы под таблицей
        painter.drawPixmap(10, tablePixmap.height() + 20, chartPixmap1);
        painter.drawPixmap(chartPixmap1.width() + 20, tablePixmap.height() + 20, chartPixmap2);

        painter.end();
    }
}

