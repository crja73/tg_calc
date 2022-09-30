#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>
#include <QDesktopServices>
#include <QUrl>
#include <math.h>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox_2->hide();
    ui->rb_summ->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_get_res_clicked()
{
    bool flag;
        if(ui->rb_summ->isChecked()) // если выбрано сложение
        {
            double num1, num2, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    res=num1+num2;
                    if(qIsInf(res))
                    {
                        ui->res->setText("Получилось бесконечность! измените введённые значения");
                    }
                    else
                    {
                        ui->res->setText(QString("%1").arg(res, 0, 'f', 1));
                    }
                }
                else
                {
                    ui->res->setText("Некорректный ввод 2 числа");
                }
            }
            else
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    ui->res->setText("Некорректный ввод 1 числа");
                }
                else
                {
                    ui->res->setText("Некорректный ввод чисел");
                }

            }
        }
        if(ui->rb_sub->isChecked()) // если выбрано вычитание
        {
            double num1, num2, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    res=num1-num2;
                    if(qIsInf(res))
                    {
                        ui->res->setText("Получилось бесконечность! измените введённые значения");
                    }
                    else
                    {
                        if(qIsNaN(res))
                        {
                            ui->res->setText("Невозможно вычислить");
                        }
                        else
                        {
                            ui->res->setText(QString("%1").arg(res, 0, 'f', 1));
                        }
                    }
                }
                else
                {
                    ui->res->setText("Некорректный ввод 2 числа");
                }
            }
            else
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    ui->res->setText("Некорректный ввод 1 числа");
                }
                else
                {
                    ui->res->setText("Некорректный ввод чисел");
                }

            }
        }
        if(ui->rb_mul->isChecked()) // если выбрано умножение
        {
            double num1, num2, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    res=num1*num2;
                    if(num1 == 0.0 || num2 == 0.0)
                    {
                        ui->res->setText("0");
                    }
                    else
                    {
                        if(res/num1==num1)
                        {
                            if(qIsInf(res))
                            {
                                ui->res->setText("Получилось бесконечность! измените введённые значения");
                            }
                            else
                            {
                                ui->res->setText(QString("%1").arg(res, 0, 'f', 1));
                            }
                        }
                        else
                        {
                            ui->res->setText("Произошло переполнение");
                        }
                    }
                }
                else
                {
                    ui->res->setText("Некорректный ввод 2 числа");
                }
            }
            else
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    ui->res->setText("Некорректный ввод 1 числа");
                }
                else
                {
                    ui->res->setText("Некорректный ввод чисел");
                }

            }
        }
        if(ui->rb_div->isChecked()) // если выбрано деление
        {
            double num1, num2, res;

            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    if(num2!=0.0)
                    {
                        res=num1/num2;
                        if(qIsNaN(res))
                        {
                            ui->res->setText("Невозможно вычислить");
                        }
                        else
                        {
                            if(qIsInf(res))
                            {
                                ui->res->setText("Невозможно вычислить");
                            }
                            else
                            {
                                ui->res->setText(QString("%1").arg(res, 0, 'f', 3));
                            }

                        }
                    }
                    else
                    {
                        ui->res->setText("Делить на 0 нельзя");
                        QDesktopServices::openUrl(QUrl("https://youtu.be/dQw4w9WgXcQ"));
                    }
                }
                else
                {
                    ui->res->setText("Некорректный ввод 2 числа");
                }
            }
            else
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    ui->res->setText("Некорректный ввод 1 числа");
                }
                else
                {
                    ui->res->setText("Некорректный ввод чисел");
                }

            }
        }
        if(ui->rb_pow->isChecked()) // если выбрано возведение в степень
        {
            double num1, num2, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    res=pow(num1, num2);
                    if(qIsInf(res))
                    {
                        ui->res->setText("Получилось бесконечность! измените введённые значения");
                    }
                    else
                    {
                        if(num1 == 0.0 || num2 == 0.0)
                        {
                            ui->res->setText("Ошибка");
                        }
                        else
                        {
                            ui->res->setText(QString("%1").arg(res, 0, 'f', 1));
                        }

                    }
                }
                else
                {
                    ui->res->setText("Некорректный ввод 2 числа");
                }
            }
            else
            {
                num2=ui->l_num2->text().toDouble(&flag); // присвоили значение 2 числа
                if(flag)
                {
                    ui->res->setText("Некорректный ввод 1 числа");
                }
                else
                {
                    ui->res->setText("Некорректный ввод чисел");
                }

            }
        }
        if(ui->rb_sqrt->isChecked()) // если выбрано извлечения корня
        {
            double num1, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                if(num1 >= 0.0)
                {
                    res=sqrt(num1);
                    if(qIsInf(res))
                    {
                        ui->res->setText("Нельзя корень из бесконечности извлечь");
                    }
                    else
                    {
                        ui->res->setText(QString("%1").arg(res, 0, 'f', 1));
                    }

                }
                else
                {
                    ui->res->setText("Невозможно извлечь корень отрицательного числа");
                }
            }
            else
            {
                ui->res->setText("Некорректный ввод 1 числа");
            }
        }
        if(ui->rb_trig->isChecked()) // если выбрано возведение в степень
        {
            double num1, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                //ui->res->setText(QString("%1").arg(res, 0, 'f', 1));

            }
            else
            {
                ui->res->setText("Некорректный ввод 1 числа");
            }
        }
        if(ui->rb_sin_2->isChecked() && ui->rb_trig->isChecked())
        {
            double num1, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                num1 = num1*(3.1415/180);
                res = sin(num1);
                if(qIsNaN(res))
                {
                    ui->res->setText("Невозможно вычислить");
                }
                else
                {
                    ui->res->setText(QString("%1").arg(res, 0, 'f', 4));
                }


            }
            else
            {
                ui->res->setText("Некорректный ввод 1 числа");
            }
        }

        if(ui->rb_cos_2->isChecked() && ui->rb_trig->isChecked())
        {
            double num1, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                num1 = num1*(3.1415/180);
                res = cos(num1);
                if(qIsNaN(res))
                {
                    ui->res->setText("Невозможно вычислить");
                }
                else
                {
                    ui->res->setText(QString("%1").arg(res, 0, 'f', 4));
                }

            }
            else
            {
                ui->res->setText("Некорректный ввод 1 числа");
            }
        }

        if(ui->rb_tg_2->isChecked() && ui->rb_trig->isChecked())
        {
            double num1, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                if (num1 != 90.0)
                {
                    num1 = num1*(3.1415/180);
                    res = tan(num1);
                    if(qIsNaN(res))
                    {
                        ui->res->setText("Невозможно вычислить");
                    }
                    else
                    {
                        ui->res->setText(QString("%1").arg(res, 0, 'f', 4));
                    }
                }
                else
                {
                    ui->res->setText("Ты че в школе не учился?");
                }
            }
            else
            {
                ui->res->setText("Некорректный ввод 1 числа");
            }
        }

        if(ui->rb_ctg_2->isChecked() && ui->rb_trig->isChecked())
        {
            double num1, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {

                    num1 = qDegreesToRadians(num1);
                    res = 1/qTan(num1);
                    if(abs(res)>10e3 or abs(res)< -10e3)
                    {
                        ui->res->setText("Ошибка");
                    }
                    else {
                        if(qIsNaN(res))
                        {
                            ui->res->setText("Невозможно вычислить");
                        }
                        else
                        {
                            ui->res->setText(QString("%1").arg(res, 0, 'f', 4));
                        }
                    }
                }
            }
            else
            {
                ui->res->setText("Некорректный ввод 1 числа");
            }

        if(ui->rb_asin_2->isChecked() && ui->rb_trig->isChecked())
        {
            double num1, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                if(num1<=1.0 && num1>=-1.0)
                {
                    res = asin(num1);
                    res = (res * 180) / 3.1415;
                    ui->res->setText(QString("%1").arg(res, 0, 'f', 1));
                }
                else
                {
                    ui->res->setText("Неверное введённое значение");
                }
            }
            else
            {
                ui->res->setText("Некорректный ввод 1 числа");
            }
        }

        if(ui->rb_acos_2->isChecked() && ui->rb_trig->isChecked())
        {
            double num1, res;
            num1=ui->l_num1->text().toDouble(&flag); // присвоили значение 1 числа
            if(flag)
            {
                if(num1<=1.0 && num1>=-1.0)
                {
                    res = acos(num1);
                    res = (res * 180) / 3.1415;
                    ui->res->setText(QString("%1").arg(res, 0, 'f', 1));
                }
                else
                {
                    ui->res->setText("Неверное введённое значение");
                }

            }
            else
            {
                ui->res->setText("Некорректный ввод 1 числа");
            }
        }
}




void MainWindow::on_rb_summ_clicked()
{
    ui->label->setText("Слагаемое 1");
    ui->label_2->setText("Слагаемое 2");
    ui->get_res->setText("Сумма");
    ui->res->clear();
    ui->groupBox_2->hide();
    ui->l_num2->show();
    ui->get_res->show();
    ui->label_2->show();
//    ui->l_num1->setMaxLength(9);
//    ui->l_num2->setMaxLength(9);
}

void MainWindow::on_rb_sub_clicked()
{
    ui->label->setText("Уменьшаемое ");
    ui->label_2->setText("Вычитаемое ");
    ui->get_res->setText("Разность");
    ui->res->clear();
    ui->groupBox_2->hide();
    ui->l_num2->show();
    ui->get_res->show();
    ui->label_2->show();
//    ui->l_num1->setMaxLength(9);
//    ui->l_num2->setMaxLength(9);
}

void MainWindow::on_rb_mul_clicked()
{
    ui->label->setText("Множитель 1");
    ui->label_2->setText("Множитель 2");
    ui->get_res->setText("Произведение");
    ui->res->clear();
    ui->groupBox_2->hide();
    ui->l_num2->show();
    ui->get_res->show();
    ui->label_2->show();
//    ui->l_num1->setMaxLength(9);
//    ui->l_num2->setMaxLength(9);
}

void MainWindow::on_rb_div_clicked()
{
    ui->label->setText("Делимое");
    ui->label_2->setText("Делитель");
    ui->get_res->setText("Частное");
    ui->res->clear();
    ui->groupBox_2->hide();
    ui->l_num2->show();
    ui->get_res->show();
    ui->label_2->show();
//    ui->l_num1->setMaxLength(9);
//    ui->l_num2->setMaxLength(9);
}

void MainWindow::on_cl_btn_clicked()
{
    ui->res->clear();
    ui->l_num1->clear();
    ui->l_num2->clear();
}

void MainWindow::on_rb_pow_clicked()
{
    ui->label->setText("Число");
    ui->label_2->setText("Степень");
    ui->get_res->setText("Результат");
    ui->res->clear();
    ui->groupBox_2->hide();
    ui->l_num2->show();
    ui->get_res->show();
    ui->label_2->show();
}

void MainWindow::on_rb_sqrt_clicked()
{
    ui->label->setText("Число");
    ui->label_2->setText("Степень");
    ui->get_res->setText("Результат");
    ui->res->clear();
    ui->groupBox_2->hide();
    ui->l_num2->hide();
    ui->label_2->hide();
    ui->get_res->show();
}

void MainWindow::on_rb_trig_clicked()
{
    ui->label->setText("Угол или значение");
    ui->label_2->hide();
    ui->get_res->setText("Результат");
    ui->l_num2->hide();
    ui->groupBox_2->show();
}


