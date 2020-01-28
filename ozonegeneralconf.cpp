#include "ozonegeneralconf.h"
#include "ui_ozonegeneralconf.h"
#include "QFile"
#include <QJsonObject>


ozoneGeneralConf::ozoneGeneralConf(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ozoneGeneralConf)
{
    ui->setupUi(this);
    this->setStyleSheet( " #ozoneGeneralConf { "
                         " border:none;border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");

    //connect( ui->secSpin,SIGNAL(valueChanged(int)),ui->secNumber,SLOT(display(int)));
    //connect( ui->minSpin,SIGNAL(valueChanged(int)),ui->minNumber,SLOT(display(int)));
    //connect( ui->hourSpin,SIGNAL(valueChanged(int)),ui->hourNumber,SLOT(display(int)));
    ui->secSpin->setDisabled(true);
    ui->minSpin->setDisabled(true);
    ui->hourSpin->setDisabled(true);
    ui->mlSpin->setDisabled(true);

    radioButtons = new QButtonGroup();
    radioButtons->addButton(ui->mg1Button,0);
    ui->mg1Button->setChecked(true);
    radioButtons->addButton(ui->mg2Button,1);
    radioButtons->addButton(ui->mg3Button,2);
    radioButtons->addButton(ui->mg4Button,3);
    radioButtons->addButton(ui->mg5Button,4);
    radioButtons->addButton(ui->mg6Button,5);
    radioButtons->addButton(ui->mg7Button,6);
    radioButtons->addButton(ui->mg8Button,7);
    radioButtons->addButton(ui->mg9Button,8);
    radioButtons->addButton(ui->mg10Button,9);
    radioButtons->setExclusive(true);

    QString valfile;
    QFile memoryFile("memoryfile.dat");
    memoryFile.open(QIODevice::ReadOnly | QIODevice::Text);
    valfile = memoryFile.readAll();
    memoryFile.close();
    memoryDoc = QJsonDocument::fromJson(valfile.toUtf8());
    QJsonObject memdocObj = memoryDoc.object();
    //QJsonValue values = memdocObj.value("memory");
    memoryArr = memdocObj["memory"].toArray();

    connect(radioButtons, QOverload<int>::of(&QButtonGroup::buttonClicked),
        [=](int id){ QJsonObject memValues = memoryArr[id].toObject();
            ui->hourNumber->display(memValues["hour"].toInt());
            ui->minNumber->display(memValues["min"].toInt());
            ui->secNumber->display(memValues["sec"].toInt());
            ui->mlNumber->display(memValues["ml"].toInt());
        });
}

ozoneGeneralConf::~ozoneGeneralConf()
{
    delete ui;
}

void ozoneGeneralConf::setValues(int hour, int min, int sec, int ml)
{
    this->hour=hour;
    this->min=min;
    this->sec=sec;
    this->ml=ml;
}
void ozoneGeneralConf::on_mconfigButton_clicked()
{

}

void ozoneGeneralConf::on_pushButton_clicked()
{
    close();
}

void ozoneGeneralConf::on_hourSpin_valueChanged(int arg1)
{
    if ( arg1 == 25 ){
        ui->hourSpin->setValue(0);
    }
    if ( arg1 == -1){
        ui->hourSpin->setValue(24);
    }

    ui->hourNumber->display(ui->hourSpin->value());
}

void ozoneGeneralConf::on_minSpin_valueChanged(int arg1)
{
    if ( arg1 == 60 ) {
        ui->minSpin->setValue(0);
        ui->hourSpin->stepUp();
    }
    if ( arg1 == -1 ){
        ui->minSpin->setValue(59);
        ui->hourSpin->stepDown();
    }

    ui->minNumber->display(ui->minSpin->value());
}

void ozoneGeneralConf::on_secSpin_valueChanged(int arg1)
{
    if ( arg1 == 60 ) {
        ui->secSpin->setValue(0);
        ui->minSpin->stepUp();
    }
    if ( arg1 == -1 ) {
        ui->secSpin->setValue(59);
        ui->minSpin->stepDown();
    }

    ui->secNumber->display(ui->secSpin->value());
}

void ozoneGeneralConf::on_setCurrentButton_clicked()
{
    ui->hourNumber->display(hour);
    ui->minNumber->display(min);
    ui->secNumber->display(sec);
    ui->mlNumber->display(ml);

    int idButton = radioButtons->checkedId();
    QJsonObject  datas ;
    datas.insert("hour",hour);
    datas.insert("min",QJsonValue::fromVariant(min));
    datas.insert("sec",QJsonValue::fromVariant(sec));
    datas.insert("ml",QJsonValue::fromVariant(ml));

    memoryArr[idButton] = datas;
    QJsonObject JsonObject;
    JsonObject.insert("memory",memoryArr);
    memoryDoc.setObject(JsonObject);

    QFile memoryFile("memoryfile.dat");
    memoryFile.open( QIODevice::WriteOnly | QIODevice::Text);
    memoryFile.write( memoryDoc.toJson());

    memoryFile.close();
    //tr("Save paramter in memory " );//+QString::number(idButton));
}

void ozoneGeneralConf::on_pushButton_2_clicked()
{

}
