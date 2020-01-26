#ifndef FORM2_H
#define FORM2_H

#include <QWidget>

namespace Ui {
class FormOxygen;
}

class FormOxygen : public QWidget
{
    Q_OBJECT

public:
    explicit FormOxygen(QWidget *parent = nullptr);
    ~FormOxygen();

    void paintEvent(QPaintEvent *event) ;
private slots:
    void on_pushButton_clicked();

private:
    Ui::FormOxygen *ui;
};

#endif // FORM2_H
