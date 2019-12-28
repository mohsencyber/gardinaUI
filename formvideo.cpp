#include "formvideo.h"
#include "ui_formvideo.h"
#include "mainwindow.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QBoxLayout>


FormVideo::FormVideo(MainWindow *w, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVideo),
    m_w(w)
{
    ui->setupUi(this);

    QVideoWidget myVideoPlayer(this) ;
    QMediaPlayer myMediaPlayer(this) ;
    const QRect myrect = this->geometry();
    myVideoPlayer.setGeometry(myrect.top()+5,myrect.left()+5,myrect.bottom()-5,myrect.right()-5);
    QBoxLayout myLayout(QBoxLayout::Direction::LeftToRight);

    myLayout.addWidget(&myVideoPlayer);
    setLayout(&myLayout);
    connect(&myMediaPlayer,&QMediaPlayer::stateChanged,this,&FormVideo::closeWindow);

    myMediaPlayer.setMedia(QUrl("file:///home/farhadi/qt/train/train1/images/gardina_intro_video.mp4"));//":/new/prefix1/images/gardina_intro_video.mp4"));
    myMediaPlayer.setVideoOutput(&myVideoPlayer);

    //qDebug() << "Player error state -> " << myMediaPlayer->error(); //this says no error
    //qDebug() << "Media supported state -> " << QMediaPlayer::hasSupport("video/mp4"); // this gives a "1"
    //this->show();

    myMediaPlayer.play();
    //connect(&myMediaPlayer,&QMediaPlayer::stateChanged,this,&FormVideo::closeWindow);
}

FormVideo::~FormVideo()
{
    delete ui;
}

void FormVideo::closeWindow(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::State::StoppedState){
        m_w->show();
        this->close();
    }
}
