#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTreeWidgetItem"
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPropertyAnimation>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void addRoot(QString name, QString Desc);
    void addChild(QTreeWidgetItem * parent,QString name,QString Desc);
    void closeVideo(QMediaPlayer::State state);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_closeButton_clicked();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionPlay_triggered();

private:
    Ui::MainWindow *ui;
    QVideoWidget *myVideoPlayer;
    QMediaPlayer *myMediaPlayer;
    QPropertyAnimation *m_animation;

};
#endif // MAINWINDOW_H
