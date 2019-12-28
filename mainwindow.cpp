#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "form2.h"
#include <QSerialPortInfo>
#include <QPropertyAnimation>
#include <QBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myVideoPlayer(new QVideoWidget(this))
    , myMediaPlayer(new QMediaPlayer(this))
    , m_animation(new QPropertyAnimation(this,"windowOpacity"))
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(3);
    addRoot("MYFamily","MyTreeFamily");
    ui->progressBar->setValue(0);
    connect(ui->myHSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
    /*
    this->setStyleSheet(
                "#MainWindow { "
                " border-image: url(:/new/prefix1/images/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                "}");
                */

    const QRect RectWin = this->geometry();
    myVideoPlayer->setGeometry(RectWin.x()+5 ,RectWin.y()+5,RectWin.width()-10,RectWin.height()-10);
    myVideoPlayer->raise();

    myMediaPlayer->setMedia(QUrl("file:///home/farhadi/qt/train/train1/images/gardina_intro_video.mp4"));//":/new/prefix1/images/gardina_intro_video.mp4"));
    myMediaPlayer->setVideoOutput(myVideoPlayer);


    myMediaPlayer->play();
    connect( myMediaPlayer,&QMediaPlayer::stateChanged,this,&MainWindow::closeVideo);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeVideo(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::State::StoppedState)
    {
        disconnect(myMediaPlayer,&QMediaPlayer::stateChanged,this,&MainWindow::closeVideo);
        myVideoPlayer->hide();
    }
}

void MainWindow::addRoot(QString name, QString Desc)
{
    QTreeWidgetItem * MyItem = new  QTreeWidgetItem(ui->treeWidget);
    MyItem->setText(0,name);
    MyItem->setText(1,Desc);
    ui->treeWidget->addTopLevelItem(MyItem);
    addChild(MyItem,"Mohsen","Root");
    addChild(MyItem,"Amin","Child");
}

void MainWindow::addChild(QTreeWidgetItem *parent, QString name, QString Desc)
{
    QTreeWidgetItem * myItem = new QTreeWidgetItem();
    myItem->setText(0,name);
    myItem->setText(1,Desc);
    parent->addChild(myItem);
}
void MainWindow::on_pushButton_clicked()
{
    QMessageBox qmsg;
    QSerialPortInfo * qport = new QSerialPortInfo();
    QString qt=qport->description();
    qt = "("+qt+")";
    qmsg.setText(qt);
    qmsg.setInformativeText("do you want continue ?");
    qmsg.setIcon(QMessageBox::Question);
    qmsg.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
    qmsg.setDefaultButton(QMessageBox::Yes);

    int ret = qmsg.exec();
    switch (ret) {

    case QMessageBox::Yes:
            auto *myform = new Form2();
            myform->show();
            break;
    }
}

void MainWindow::on_closeButton_clicked()
{
   close();
}

void MainWindow::on_actionOpen_triggered()
{
    //QMessageBox qmsg;
    //qmsg.setText("Text Message .... ");
    //qmsg.exec();
    auto *myForm = new Form2();
    //this->setVisible(false);
    this->hide();
    myForm->setParentForm(this);
    myForm->show();
    //this->setVisible(true);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionPlay_triggered()
{
   // myMediaPlayer->play();
}
