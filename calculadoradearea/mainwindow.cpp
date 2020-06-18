#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
    ui->pushButton->click();
    ui->lineEdit->selectAll();
}

void MainWindow::on_pushButton_clicked()
{
    float valor;
    valor=ui->lineEdit->text().toFloat();
    if(ui->radioButton->isChecked()){
        ui->lineEdit_2->setText(QString::number(valor*valor*valor));
    } else{
        ui->lineEdit_2->setText(QString::number((4/3)*3.1415*valor*valor*valor));
    }

}

void MainWindow::on_radioButton_clicked()
{
    ui->label->setText("Valor do lado");
    ui->label_2->setText("Area do Cubo");
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->label->setText("Valor do raio");
    ui->label_2->setText("Area da Esfera");
}
