#ifndef FORMACCESS_H
#define FORMACCESS_H

#include <QWidget>

namespace Ui {
class formAccess;
}

class formAccess :public QWidget
{
    Q_OBJECT
public:
    explicit formAccess(QWidget *parent = nullptr);
    ~formAccess();

    void paintEvent(QPaintEvent *);

private slots:
    void on_back_button_clicked();

    void on_about_button_clicked();

    void on_contact_button_clicked();

private:
    Ui::formAccess *ui;
};

#endif // FORMACCESS_H
