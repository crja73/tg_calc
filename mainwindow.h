#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_get_res_clicked();

    void on_rb_summ_clicked();

    void on_rb_sub_clicked();

    void on_rb_mul_clicked();

    void on_rb_div_clicked();

    void on_cl_btn_clicked();

    void on_rb_pow_clicked();

    void on_rb_sqrt_clicked();

    void on_rb_trig_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_tg_clicked();

    void on_pushButton_ctg_clicked();

    void on_pushButton_asin_clicked();

    void on_pushButton_acos_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
