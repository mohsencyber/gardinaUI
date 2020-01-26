#ifndef FORMVACCUM_H
#define FORMVACCUM_H

#include <QWidget>

namespace Ui {
class FormVaccum;
}

class FormVaccum : public QWidget
{
    Q_OBJECT

public:
    explicit FormVaccum(QWidget *parent = nullptr);
    ~FormVaccum();

    void paintEvent(QPaintEvent *event) ;

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormVaccum *ui;
};

#endif // FORMVACCUM_H
