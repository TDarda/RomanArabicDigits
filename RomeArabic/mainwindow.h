#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_FromEdit_returnPressed();

    void on_TransformButton_clicked();

    void on_RoToAr_clicked();

    void on_ArToRo_clicked();

private:
    Ui::MainWindow *ui;
    QString transform();
};
#endif // MAINWINDOW_H
