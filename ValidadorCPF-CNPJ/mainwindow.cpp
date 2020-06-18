#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QMessageBox>
int vet[12];
std::string entrada;

void zerar(){// zera o vetor inteiro do cpf
    for(int i=0;i<12;i++){
        vet[i]=-1;
    }
}
std::string gerador(int *vet) {
    std::string retorno="";
    if(vet[9]==-1){//calculo do cpf
        int aux=0,multi=10;
        for(int i=0;i<9;i++){
            aux+=vet[i]*multi;
            multi--;
        }
        if(aux%11<2){
            retorno=retorno+"0";
            vet[9]=0;
        }else{
            retorno=retorno+std::to_string(11-(aux%11));
            vet[9]=11-(aux%11);
        }
        aux=0,multi=11;
        for(int i=0;i<10;i++){
            aux+=vet[i]*multi;
            multi--;
        }
        if(aux%11<2){
            retorno=retorno+"0";
        }else{
            retorno=retorno+std::to_string(11-(aux%11));
        }
    }else{//calculo do cnpj
        int aux=0,multi=5;
        for(int i=0;i<12;i++){
            aux+=vet[i]*multi;
            multi--;
            if(multi==1)
                multi=9;
        }
        if(aux%11<2){
            retorno=retorno+"0";
            vet[12]=0;
        }else{
            retorno=retorno+std::to_string(11-(aux%11));
            vet[12]=11-(aux%11);
        }
        aux=0,multi=6;
        for(int i=0;i<13;i++){
            aux+=vet[i]*multi;
            multi--;
            if(multi==1)
                multi=9;
        }
        if(aux%11<2){
            retorno=retorno+"0";
        }else{
            retorno=retorno+std::to_string(11-(aux%11));
        }
    }
    return retorno;
}

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
}

void MainWindow::on_lineEdit_selectionChanged()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}

void MainWindow::on_pushButton_clicked()
{
    zerar();
    int cont=0;
    entrada=ui->lineEdit->text().toStdString();
    int max=entrada.length();
    if((max==9)||(max==11)||(max==12)||(max==15)){
        for(int i=0;i<max;i++){
            if((entrada[i]>=48)&&(entrada[i]<=57)){
                vet[cont]=(entrada[i])-48;
                cont++;
            }
        }
        if(ui->lineEdit_2->text()!=""){
            if(ui->lineEdit_2->text()==QString::fromStdString(gerador(vet))){
                ui->lineEdit->setStyleSheet("color: green;");
                ui->lineEdit_2->setStyleSheet("color: green;");
            }
            else{
                ui->lineEdit->setStyleSheet("color: red;");
                ui->lineEdit_2->setStyleSheet("color: red;");
            }

        }else{
            ui->lineEdit->setStyleSheet("color: black;");
            ui->lineEdit_2->setStyleSheet("color: black;");
            ui->lineEdit_2->setText(QString::fromStdString(gerador(vet)));
        }
    }
    else{
        QMessageBox::warning(this,"Erro-01","CPF ou CNPJ faltando digitos");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "Info","Digite o CPF/CNPJ e caso nao tenha nada no\n"
                                          "campo do DV ele gera o DV, caso tenha, ele compara\n"
                                          "(O programa aceita com ou sem os pontos :)\n"
                                          "   Verde = [correto]----VERMELHO = [incorreto]    ");
}

