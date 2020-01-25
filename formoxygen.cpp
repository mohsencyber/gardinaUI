#include "formoxygen.h"
#include "ui_formoxygen.h"
#include <QPainter>
#include <QStyleOption>


Formoxygen::Formoxygen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formoxygen)
{
    ui->setupUi(this);
    this->setStyleSheet( "#Formoxygen { "
                         " border-image: url(:/images/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");
}

Formoxygen::~Formoxygen()
{
    delete ui;
}

void Formoxygen::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Formoxygen::on_pushButton_clicked()
{
    close();
}
