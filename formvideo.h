#ifndef FORMVIDEO_H
#define FORMVIDEO_H

#include <QWidget>
#include "mainwindow.h"
#include <QMediaPlayer>

namespace Ui {
class FormVideo;
}

class FormVideo : public QWidget
{
    Q_OBJECT

public:
    explicit FormVideo(MainWindow *m, QWidget *parent = nullptr);
    ~FormVideo();
    void closeWindow(QMediaPlayer::State state);

private:
    Ui::FormVideo *ui;
    MainWindow    *m_w;

};

#endif // FORMVIDEO_H
