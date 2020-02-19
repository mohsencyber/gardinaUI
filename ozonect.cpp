#include "ozonect.h"
#include "ui_ozonect.h"

OzoneCT::OzoneCT(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OzoneCT)
{
    ui->setupUi(this);
    this->setStyleSheet( " #OzoneCT { "
                         " border:none;border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");
    ui->pauseButton->setDisabled(true);
    isPause = true;
}

OzoneCT::~OzoneCT()
{
    delete ui;
}

void OzoneCT::on_pushButton_clicked()
{
    close();
}

void OzoneCT::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    ui->pushButton->setDisabled(true);
    ui->pauseButton->setDisabled(false);
}

void OzoneCT::on_pauseButton_clicked()
{
    if ( isPause )
    {
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
        isPause = false;
    }else
    {
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
        isPause = true;
    }

}

void OzoneCT::on_stopButton_clicked()
{
    ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    ui->pauseButton->setDisabled(true);
}
