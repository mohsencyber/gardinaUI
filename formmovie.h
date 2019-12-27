#ifndef FORMMOVIE_H
#define FORMMOVIE_H

#include <QWidget>
#include <QMediaPlayer>
#include "mainwindow.h"

namespace Ui {
class Formmovie;
}

class Formmovie : public QWidget
{
    Q_OBJECT

public:
    explicit Formmovie(MainWindow *m, QWidget *parent = nullptr);
    ~Formmovie();
    void closeform(QMediaPlayer::State state);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Formmovie *ui;
    MainWindow *m_m;
};

#endif // FORMMOVIE_H
