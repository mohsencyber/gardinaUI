#include "form2.h"
#include "ui_form2.h"

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    ui->html_button->setToolTip("Hello <font color='red'><b> Set Html style ,</b></font>");
    //ui->pushButton_2->setFlat(true);
    ui->pushButton_2->setStyleSheet("qproperty-icon: url(:/new/prefix1/images/button_ozone_highlight_bg.png);");
    //ui->pushButton_2->setIcon(QIcon("./images/button_ozone_highlight_bg.png"));
    //ui->pushButton_2->setIconSize(QSize(170,60));
}

Form2::~Form2()
{
    delete ui;
}

void Form2::on_pushButton_clicked()
{
    if ( M_parentForm )
         M_parentForm->showNormal();
    this->close();
}

void Form2::on_html_button_clicked()
{
   ui->label->setText("<b>Mohsen Farhadi .....</b>");
}

void Form2::on_css_button_clicked()
{
    ui->label->setStyleSheet("color:#ff0000;");
}

void Form2::setParentForm(QWidget *parent)
{
    M_parentForm = parent;
}
