#ifndef OZONEGENERAL_H
#define OZONEGENERAL_H

#include <QFrame>

namespace Ui {
class OzoneGeneral;
}

class OzoneGeneral : public QFrame
{
    Q_OBJECT

public:
    explicit OzoneGeneral(QWidget *parent = nullptr);
    ~OzoneGeneral();

private slots:
    void on_pushButton_clicked();

    void on_secSpin_valueChanged(int arg1);

private:
    Ui::OzoneGeneral *ui;
};

#endif // OZONEGENERAL_H
