#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>

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
    void on_pushButton_clicked();

    void on_Ozone_button_clicked();

    void on_poweroff_button_clicked();

    void on_access_button_clicked();

    void on_Oxygen_button_clicked();

    void on_vacuum_button_clicked();

private:
    Ui::MainWindow *ui;
    //QToolButton *Access_button;
};
#endif // MAINWINDOW_H
