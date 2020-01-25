#ifndef FORMOXYGEN_H
#define FORMOXYGEN_H

#include <QWidget>

namespace Ui {
class Formoxygen;
}

class Formoxygen : public QWidget
{
    Q_OBJECT

public:
    explicit Formoxygen(QWidget *parent = nullptr);
    ~Formoxygen();

    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Formoxygen *ui;
};

#endif // FORMOXYGEN_H
