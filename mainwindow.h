#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QMessageBox qmsg;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_Ozone_button_clicked();

    void on_Oxygen_button_clicked();

    void on_vacuum_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
