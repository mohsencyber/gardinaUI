#ifndef FORM2_H
#define FORM2_H

#include <QWidget>

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();
    void setParentForm(QWidget *parent);

private slots:
    void on_pushButton_clicked();

    void on_html_button_clicked();

    void on_css_button_clicked();

private:
    Ui::Form2 *ui;
    QWidget *M_parentForm;
};

#endif // FORM2_H
