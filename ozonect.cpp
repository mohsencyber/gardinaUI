#include "ozonect.h"
#include "ui_ozonect.h"
#include <QButtonGroup>

OzoneCT::OzoneCT(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OzoneCT)
{
    ui->setupUi(this);
    this->setStyleSheet( " #OzoneCT { "
                         " border:none;border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");
    ui->pauseButton->setDisabled(true);
    isPause = false;
    enter = "Con";
    ConcenVal = DoseVal = 0;

    radioButtons = new QButtonGroup();
    radioButtons->addButton(ui->Button_0,0);
    radioButtons->addButton(ui->Button_1,1);
    radioButtons->addButton(ui->Button_2,2);
    radioButtons->addButton(ui->Button_3,3);
    radioButtons->addButton(ui->Button_4,4);
    radioButtons->addButton(ui->Button_5,5);
    radioButtons->addButton(ui->Button_6,6);
    radioButtons->addButton(ui->Button_7,7);
    radioButtons->addButton(ui->Button_8,8);
    radioButtons->addButton(ui->Button_9,9);
    radioButtons->setExclusive(true);

    connect(radioButtons, QOverload<int>::of(&QButtonGroup::buttonClicked),
        [=](int id){
            if ( enter == "Con" ){
                if ( id == 0 ) {
                    if ( ConcenVal < 9 )
                        ConcenVal = ConcenVal*10 + id;
                }else{
                    if ( ConcenVal < 8 )
                        ConcenVal = ConcenVal*10 + id;
                }
                ui->label_Con->setText(QString::number(ConcenVal).rightJustified(2,'0'));
            }else{
                if ( DoseVal < 1000 )
                    DoseVal = DoseVal*10 + id;
                ui->label_Dose->setText(QString::number(DoseVal).rightJustified(4,'0'));
            }
        });
    timer = new  QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
}

OzoneCT::~OzoneCT()
{
    delete ui;
}

void OzoneCT::updateTimer()
{
    SecVal --;
    if ( SecVal == -1 )
    {
        MinVal --;
        SecVal = 59;
    }
    if ( MinVal == -1 )
        MinVal = SecVal = 0;

    ui->label_Min->setText(QString::number(MinVal).rightJustified(2,'0'));
    ui->label_Sec->setText(QString::number(SecVal).rightJustified(2,'0'));

    if ( SecVal == 0 &&
         MinVal == 0 )
    {
        stop();
        end();
        timer->stop();
        ui->startButton->setDisabled(false);
        ui->pushButton->setDisabled(false);
        ui->pauseButton->setDisabled(true);
    }else{
        start();
    }
}

void OzoneCT::on_pushButton_clicked()
{
    close();
}

void OzoneCT::on_startButton_clicked()
{
    timeToSeconds();
    ui->label_Min->setText(QString::number(MinVal).rightJustified(2,'0'));
    ui->label_Sec->setText(QString::number(SecVal).rightJustified(2,'0'));
    if ( MinVal > 0 &&
         SecVal > 0 ){
        ui->startButton->setDisabled(true);
        ui->pushButton->setDisabled(true);
        ui->pauseButton->setDisabled(false);
        start();
        timer->setInterval(1000);
        timer->start();
        isPause = false;
    }
}

void OzoneCT::on_pauseButton_clicked()
{
    if ( !isPause )
    {
        timer->stop();
        ui->pauseButton->setText("Continue        ");
        ui->pauseButton->setStyleSheet("QPushButton#pauseButton:hover{"
                                    "border:none;"
                                    "border-image: url(:/button_actions_continue_highlight_bg.png);"
                                    "}"
                                    ""
                                    "QPushButton#pauseButton{"
                                    "border:none;"
                                    "border-image: url(:/button_actions_continue_bg.png);"
                                    "}");
        isPause = true;
        stop();

    }else
    {
        start();
        ui->pauseButton->setText("Pause           ");
        ui->pauseButton->setStyleSheet("QPushButton#pauseButton:hover{"
                                    "border:none;"
                                    "border-image: url(:/button_actions_pause_highlight_bg.png);"
                                    "}"
                                    ""
                                    "QPushButton#pauseButton{"
                                    "border:none;"
                                    "border-image: url(:/button_actions_pause_bg.png);"
                                    "}");
        isPause = false;
        timer->setInterval(1000);
        timer->start();
    }

}

void OzoneCT::on_stopButton_clicked()
{
    ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    ui->pauseButton->setDisabled(true);
    stop();
    timer->stop();
}

void OzoneCT::setSerialport(MySerialPort *serialport)
{
    m_serialport = serialport;
}

void OzoneCT::start()
{
    QString strStart=QString::number(300+ConcenVal)+"\n";
    int interval=0;
    m_serialport->open();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStart.toUtf8(),interval);
    }

}

void OzoneCT::stop()
{
    QString strStop = "300\n";
    int interval = 0;
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStop.toUtf8(),interval);
    }
}

void OzoneCT::end()
{
    QString end = "500\n";
    int interval= 0;
    stop();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(end.toUtf8(),interval);
    }

}

void OzoneCT::timeToSeconds()
{
    int dur=0;
    if ( ConcenVal > 0 )
    {
        dur = DoseVal /12;
    }
    SecVal = dur%60;
    MinVal = (dur-SecVal) / 60;
    return;
}
void OzoneCT::on_Button_Enter_clicked()
{
    if ( enter == "Con" ){
        enter = "Dos";
    }else {
        enter = "Con";
        timeToSeconds();
        ui->label_Min->setText(QString::number(MinVal).rightJustified(2,'0'));
        ui->label_Sec->setText(QString::number(SecVal).rightJustified(2,'0'));
    }
}

void OzoneCT::on_Button_Delete_clicked()
{
    if ( enter == "Con" )
    {
        ConcenVal = (ConcenVal - (ConcenVal%10))/10;
        ui->label_Con->setText(QString::number(ConcenVal).rightJustified(2,'0'));
    }else{
        DoseVal = (DoseVal - (DoseVal%10))/10;
        ui->label_Dose->setText(QString::number(DoseVal).rightJustified(4,'0'));
    }
}


void OzoneCT::on_Button_Reset_clicked()
{
    ui->label_Con->setText("00");
    ui->label_Dose->setText("0000");
    ui->label_Min->setText("00");
    ui->label_Sec->setText("00");
    ConcenVal = DoseVal = MinVal = SecVal = 0;
    enter = "Con";
}
