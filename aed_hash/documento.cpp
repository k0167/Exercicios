#include "documento.h"

documento::documento(std::string arquivo)
{
    this->doc=arquivo;
    this->palavras=*setPalavras();
    QStringList lista_sem_duplicatas=palavras;
    lista_sem_duplicatas.removeDuplicates();
    p_dist=lista_sem_duplicatas.size();
}

QStringList *documento::setPalavras()
{
    std::string linha;
    std::ifstream dados;
    dados.open(this->doc);
    if(dados.fail())
        throw("Arquivo não existe!");
    else{
        do{
            std::getline(dados,linha);
            QString aux=QString::fromStdString(linha);
            QStringList list=aux.split(' ');
            for (int i=0; i<list.size();i++){
                list[i]=list[i].toLower();
                QString palavra=list[i];
                if(((palavra.toStdString())[palavra.size()-1]<97)&&!(((palavra.toStdString())[palavra.size()-1]>47)&&((palavra.toStdString())[palavra.size()-1]<57))){
                    palavra.remove(palavra.size()-1,1);
                }
                if(((palavra.toStdString())[0]==34)||((palavra.toStdString())[0]==39)){
                    palavra.remove(0,1);
                }
                if((palavra.size()>1)&&((palavra.toStdString())[0]>=97)&&(palavra.toStdString())[0]<=122){
                    palavras<<palavra;
                }
            }
        }
        while(!dados.eof());
        return &palavras;

    }
    dados.close();
}
int documento::getP_dist()
{
    return p_dist;
}

QStringList *documento::getPalavras()
{
    return &palavras;
}

std::string documento::getDoc() const
{
    return doc;
}


