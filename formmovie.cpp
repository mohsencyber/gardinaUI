#include "formmovie.h"
#include "ui_formmovie.h"
#include <QVideoWidget>
#include <QMediaPlayer>
#include "mainwindow.h"

Formmovie::Formmovie(MainWindow *m,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formmovie),
    m_m(m)
{
    ui->setupUi(this);
    QVideoWidget *m_videoWidget = new QVideoWidget(this);
    QMediaPlayer *m_mediaPlayer = new QMediaPlayer(this);

    m_mediaPlayer->setMedia(QUrl::fromLocalFile("E:/Qt/prj/rasberryprj/images/gardina_intro_video.mp4"));
    m_mediaPlayer->setVideoOutput(m_videoWidget);
    //this->(m_videoWidget);
    m_videoWidget->show();
    m_mediaPlayer->play();

    connect(m_mediaPlayer,&QMediaPlayer::stateChanged,this,&Formmovie::closeform);
}

Formmovie::~Formmovie()
{
    delete ui;
}

void Formmovie::on_pushButton_clicked()
{
    this->close();
}

void Formmovie::closeform(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::State::StoppedState){
            m_m->show();
            this->close();
    }
}
