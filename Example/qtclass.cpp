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

QVector<int> vec;
QVector<QString> vec1;
QVector<QString> vec2;
QVector<QString> vec3;

int QtClass::get_clicked_row_index() {
    return ui->tableWidget->currentRow();
}

int sum_vec(QVector<int> vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i) {
        sum+=vec[i];
    }
    return sum;
}

void QtClass::updateChartsAndLabel() {
    ui->label->setText("Семейные сбережения: " + QString::number(sum_vec(vec)));

    series->clear();
    series2->clear();

    for (int i = 0; i < vec1.size(); ++i) {
        bool ok;
        int value = vec1[i].toInt(&ok);
        if (!ok) {
            continue;
        }

        if (vec2[i].startsWith("Доход")) {
            series->append(vec2[i], value);
        } else if (vec2[i].startsWith("Расход")) {
            series2->append(vec2[i], value);
        }
    }

    chart->update();
    chart2->update();
}

void QtClass::on_pushButton_clicked()
{
    QString str = ui->lineEdit_2->text();
        QString strneg = "-" + str;
        QString str1 = ui->lineEdit_4->text();
        QString str2 = ui->lineEdit_7->text();

        QTableWidgetItem *tbl = new QTableWidgetItem(str);
        QTableWidgetItem *tblneg = new QTableWidgetItem(strneg);
        QTableWidgetItem *tbl1 = new QTableWidgetItem(str1);
        ui->tableWidget->insertRow(0);
        if (ui->comboBox->currentText() == "Доход") {
            ui->tableWidget->setVerticalHeaderLabels(QStringList() << "Доход (" + str2 + ")");
            ui->tableWidget->setItem(0,0,tbl);
            ui->tableWidget->setItem(0,1,tbl1);
            vec.push_front(str.toInt());
            vec1.push_front(str);
            vec2.push_front("Доход (" + str2 + ")");
            vec3.push_front(str1);
        }
        else {
            ui->tableWidget->setVerticalHeaderLabels(QStringList() << "Расход (" + str2 + ")");
            ui->tableWidget->setItem(0,0,tblneg);
            ui->tableWidget->setItem(0,1,tbl1);
            vec.push_front(-str.toInt());
            vec1.push_front(strneg);
            vec2.push_front("Расход (" + str2 + ")");
            vec3.push_front(str1);
        }

        updateChartsAndLabel();

        ui->lineEdit_2->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_7->clear();

}


void QtClass::on_pushButton_3_clicked()
{
    int clickedRow = get_clicked_row_index();
    if (clickedRow != -1) {
        vec.remove(clickedRow);
        vec1.remove(clickedRow);
        vec2.remove(clickedRow);
        vec3.remove(clickedRow);
        ui->label->setText("Семейные сбережения: " + QString::number(sum_vec(vec)));

        updateChartsAndLabel();
        ui->tableWidget->removeRow(clickedRow);
    }
}


void QtClass::saveToPdf()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить как PDF", QDir::homePath(), "PDF (*.pdf)");
    if (!fileName.isEmpty()) {
        QPdfWriter writer(fileName);
        writer.setPageSize(QPagedPaintDevice::A4);

        QPainter painter(&writer);

        QPixmap tablePixmap = ui->tableWidget->grab();
        tablePixmap = tablePixmap.scaledToWidth(writer.width() * 0.8, Qt::SmoothTransformation);
        painter.drawPixmap(10, 10, tablePixmap);

        QPixmap chartPixmap1 = chartview->grab();
        chartPixmap1 = chartPixmap1.scaledToWidth(writer.width() * 0.4, Qt::SmoothTransformation);
        QPixmap chartPixmap2 = chartview2->grab();
        chartPixmap2 = chartPixmap2.scaledToWidth(writer.width() * 0.4, Qt::SmoothTransformation);

        painter.drawPixmap(10, tablePixmap.height() + 20, chartPixmap1);
        painter.drawPixmap(chartPixmap1.width() + 20, tablePixmap.height() + 20, chartPixmap2);

        painter.end();
    }
}


void QtClass::on_actionSave_to_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), tr("Имя файла"), tr("Файлы данных (*.dat)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream writeStream(&file);

            // Save vec2 data
            for (const QString& label : vec2) {
                writeStream << label << "\n";
            }
            // Save vec1 data
            for (const QString& value : vec1) {
                writeStream << value << "\n";
            }
            // Save vec3 data
            for (const QString& value : vec3) {
                writeStream << value << "\n";
            }
            file.close();
        }
    }
}


void QtClass::on_actionLoad_from_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), tr("Имя файла"), tr("Файлы данных (*.dat)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            vec2.clear();
            vec1.clear();
            vec3.clear();
            QTextStream in(&file);
            QString line;
            while (!(line = in.readLine()).isNull()) {
                if (!line.isEmpty()) { // Check for empty lines
                    if (line.startsWith("Доход") || line.startsWith("Расход")) {
                        vec2.push_back(line);
                    } else {
                        vec1.push_back(line);
                        if (!(line = in.readLine()).isNull()) {
                            vec3.push_back(line);
                        }
                    }
                }
            }
            vec.clear();
            for (int i = 0; i < vec1.size(); ++i) {
                bool ok;
                int value = vec1[i].toInt(&ok);
                if (!ok) {
                    continue;
                }
                vec.push_back(value);
            }
            file.close();

            // Clear table before loading new data
            ui->tableWidget->clear();
            ui->tableWidget->setRowCount(vec1.size());
            QStringList headerLabels;
            for(const QString& label : vec2) {
                headerLabels.append(label);
            }
            ui->tableWidget->setVerticalHeaderLabels(headerLabels);
            for (int i = 0; i < vec1.size(); ++i) {
                QTableWidgetItem *item = new QTableWidgetItem(vec1[i]);
                QTableWidgetItem *item2 = new QTableWidgetItem(vec3.value(i));
                ui->tableWidget->setItem(i, 0, item);
                ui->tableWidget->setItem(i, 1, item2);
            }
            updateChartsAndLabel();
            ui->label->setText("Семейные сбережения: " + QString::number(sum_vec(vec)));
        }
    }
}
