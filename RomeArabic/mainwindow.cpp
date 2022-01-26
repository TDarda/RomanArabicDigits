#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ArToRo->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::transform()
{
    QString result;
    if(ui->ArToRo->isChecked())
    {
        int topInt = ui->FromEdit->text().toInt();
        if(topInt >= 1000 and topInt < 4000)
        {
            int temp = topInt/1000;
            for(int i = 0; i < temp; ++i)
            {
                result += "M";
            }
            topInt -= (temp*1000);

        }
        if(topInt >= 900 and topInt < 1000)
        {
            result += "CM";
            topInt -= 900;
        }
        if(topInt >= 500 and topInt < 900)
        {
            result += "D";
            topInt -= 500;

        }
        if(topInt >= 400 and topInt < 500)
        {
            result += "CD";
            topInt -= 400;
        }
        if(topInt >= 100 and topInt < 400)
        {
            int temp = topInt/100;
            for(int i = 0; i < temp; ++i)
            {
                result += "C";
            }
            topInt -= (temp*100);
        }
        if(topInt >= 90 and topInt < 100)
        {
            result += "XC";
            topInt -= 90;
        }
        if(topInt >= 50 and topInt < 90)
        {
            result += "L";
            topInt -= 50;
        }
        if(topInt >= 40 and topInt < 50)
        {
            result += "XL";
            topInt -= 40;
        }
        if(topInt >= 10 and topInt < 40)
        {
            int temp = topInt/10;
            for(int i = 0; i < temp; ++i)
            {
                result += "X";
            }
            topInt -= (temp*10);
        }
        if (topInt == 9)
        {
            result += "IX";
            topInt -= 9;
        }
        if (topInt == 4)
        {
            result += "IV";
            topInt -= 4;
        }
        if (topInt >= 5 and topInt < 9 )
        {
            result += "V";
            topInt -= 5;
        }
        if(topInt >= 1 and topInt < 4)
        {
            int temp = topInt;
            for(int i = 0; i < temp; ++i)
            {
                result += "I";
            }
            topInt -= temp;
        }

        return result;

    }
    else if(ui->RoToAr->isChecked())
    {

        int res = 0;
        QString topStr = ui->FromEdit->text();
        if(topStr.contains("CM"))
        {
            res += 900;
            topStr.remove(topStr.toStdString().find("CM"), 2);
        }
        if(topStr.contains("CD"))
        {
            res += 400;
            topStr.remove(topStr.toStdString().find("CD"), 2);
        }
        if(topStr.contains("XC"))
        {
            res += 90;
            topStr.remove(topStr.toStdString().find("XC"), 2);
        }
        if(topStr.contains("XL"))
        {
            res += 40;
            topStr.remove(topStr.toStdString().find("XL"), 2);
        }
        if(topStr.contains("IX"))
        {
            res += 9;
            topStr.remove(topStr.toStdString().find("IX"), 2);
        }
        if(topStr.contains("IV"))
        {
            res += 4;
            topStr.remove(topStr.toStdString().find("IV"), 2);
        }

        if(topStr.contains("V"))
        {
            res += 5;
            topStr.remove(topStr.toStdString().find("V"), 1);
        }

        if(topStr.contains("L"))
        {
            res += 50;
            topStr.remove(topStr.toStdString().find("L"), 1);
        }
        if(topStr.contains("D"))
        {
            res += 500;
            topStr.remove(topStr.toStdString().find("D"), 1);
        }
        for(int i = 0; i < 3; ++i)
        {
            if(topStr.contains("M"))
            {
                res += 1000;
                topStr.remove(topStr.toStdString().find("M"), 1);
            }
            if(topStr.contains("C"))
            {
                res += 100;
                topStr.remove(topStr.toStdString().find("C"), 1);
            }
            if(topStr.contains("X"))
            {
                res += 10;
                topStr.remove(topStr.toStdString().find("X"), 1);
            }
            if(topStr.contains("I"))
            {
                res += 1;
                topStr.remove(topStr.toStdString().find("I"), 1);
            }
        }
        result = QString::number(res);
        return result;
    }
    return "";
}

void MainWindow::on_FromEdit_returnPressed()
{
    QString outcome =transform();
    if(outcome != QString(""))
    {
        ui->ToEdit->setText(outcome);
    }
    else
    {
        ui->ToEdit->setText("wrong data");
    }
}


void MainWindow::on_TransformButton_clicked()
{
    QString outcome =transform();
    if(outcome != QString(""))
    {
        ui->ToEdit->setText(outcome);
    }
    else
    {
        ui->ToEdit->setText("wrong data");
    }

}


void MainWindow::on_RoToAr_clicked()
{
    ui->FromLabel->setText(QString::fromStdString("Roman:"));
    ui->ToLabel->setText(QString::fromStdString("Arabic:"));
}


void MainWindow::on_ArToRo_clicked()
{
    ui->FromLabel->setText(QString::fromStdString("Arabic:"));
    ui->ToLabel->setText(QString::fromStdString("Roman:"));
}

