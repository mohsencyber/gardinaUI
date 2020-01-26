#include "formaccess.h"
#include "ui_formaccess.h"
#include <QStyleOption>
#include <QPainter>
#include <frameabout.h>
#include <framecontact.h>

formAccess::formAccess(QWidget *parent):
    QWidget(parent),
    ui(new Ui::formAccess)
{
    ui->setupUi(this);

    ui->media_button->setDisabled(true);
    this->setStyleSheet( " #formAccess { "
                         " border:none;border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");
}

formAccess::~formAccess()
{
    delete ui;
}

void formAccess::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void formAccess::on_back_button_clicked()
{
    close();
}

void formAccess::on_about_button_clicked()
{
    FrameAbout  *about = new FrameAbout();
    about->showFullScreen();
}

void formAccess::on_contact_button_clicked()
{
    FrameContact *contact = new FrameContact();
    contact->showFullScreen();
}
