#include "documento.h"
#include "hash.h"
#include <iostream>
#include <iomanip>

int main()
{
    int quantidade=0;
    int pot=1;
    //POR FAVOR ANTES DE EXECUTAR INDIQUE A ENTRADA--------------------------------------------
    std::string path="C:\\Users\\carlos\\Documents\\aed_hash\\";
    //POR FAVOR ANTES DE EXECUTAR INDIQUE A ENTRADA--------------------------------------------
    std::string entrada_path=path+"entrada.txt";
    std::string linha;
    std::ifstream entrada;
    entrada.open(entrada_path);
    if(entrada.fail())
        throw("Arquivo não existe!");
    else{
        getline(entrada,linha);
        for(int i=linha.size()-1;i>=0;i--){
            quantidade+=(linha[i]-48)*pot;
            pot*=10;
        }
        documento **arquivos=new documento*[quantidade];
        for(int i=0;i<quantidade;i++){
            getline(entrada,linha);
            std::string file_path=path+linha;
            documento *doc=new documento(file_path);
            arquivos[i]=doc;
        }
    entrada.close();
    int qtde_de_palavras=0;
    for(int i=0;i<quantidade;i++){
        qtde_de_palavras+=arquivos[i]->getP_dist();
    }

    std::cout<<"Palavras identificadas: "<<qtde_de_palavras<<std::endl;
    hash tabela_hash(qtde_de_palavras);
    for(int i=0;i<quantidade;i++){
        QStringList lista=*arquivos[i]->getPalavras();
        for(int j=0;j<lista.size();j++){
            std::string chave=lista.at(j).toStdString();
            tabela_hash.insert(chave,*arquivos[i],i);
        }
    }
    /*while (true){
        std::cout<<"digite a palavra de busca"<<std::endl;
        std::string pesquisa;
        std::cin>>pesquisa;
        QString palavra=QString::fromStdString(pesquisa);
        palavra=palavra.toLower();
        if((palavra.size()>1)&&((palavra.toStdString())[0]>=97)&&(palavra.toStdString())[0]<=122){
            std::list<thing> *resultado=tabela_hash.search(palavra.toStdString());
                if(resultado->size()!=0){
                    std::list<thing>::iterator it;
                    it=resultado->begin();
                    for(unsigned int i=0;i<resultado->size();i++)
                    {
                        std::cout<<it->getDoc()->getDoc()<<" quantidade: "<<it->getQtde()<<std::endl;;
                        it++;
                    }
                }
            }
        }*/

    while(true){
        std::cout<<"[1] - busca por todos termos\n[2] - busca por pelomenos um termo"<<std::endl;
        char opc;
        std::cin>>opc;
        if(opc!='2'&&opc!='1'){
            std::cout<<"opcao invalida"<<std::endl;
        }else{
            switch (opc) {
                case '1':{
                    std::cout<<"digite os termos de busca"<<std::endl;
                    std::string palavra;
                    getline(std::cin.ignore(),palavra);
                    QString aux=QString::fromStdString(palavra);
                    aux=aux.toLower();
                    QStringList split=aux.split(' ');
                    bool vetor_corresp[quantidade];
                    bool vetor_corresp2[quantidade];
                    for (int j=0;j<quantidade;j++){
                        vetor_corresp[j]=true;
                    }
                    for(int i=0;i<split.size();i++){
                        if((split[i].size()>1)&&(split[i].toStdString()[0]>=97&&split[i].toStdString()[0]<=122)){
                            std::list<thing> *retorno=tabela_hash.search(split[i].toStdString());
                            std::list<thing>::iterator it;
                            it=retorno->begin();
                            for (int j=0;j<quantidade;j++){vetor_corresp2[j]=false;}
                            for(unsigned int k=0;k<retorno->size();k++){
                                vetor_corresp2[it->getIndice()]=true;
                                it++;
                            }
                            for(int j=0;j<quantidade;j++){
                                if(vetor_corresp2[j]&&vetor_corresp[j]){
                                    vetor_corresp[j]=true;
                                }else{
                                    vetor_corresp[j]=false;
                                }
                            }
                        }
                    }
                    std::cout<<"resultados:\n"<<std::endl;
                    for(int j=0;j<quantidade;j++){
                        if(vetor_corresp[j]){
                            std::cout<<arquivos[j]->getDoc()<<std::endl;
                        }
                    }
                    std::cout<<std::endl;
                    break;
                }
                case '2':{
                    std::cout<<"digite os termos de busca"<<std::endl;
                    std::string palavra;
                    getline(std::cin.ignore(),palavra);
                    QString aux=QString::fromStdString(palavra);
                    aux=aux.toLower();
                    QStringList split=aux.split(' ');
                    bool vetor_corresp[quantidade];
                    bool vetor_corresp2[quantidade];
                    for (int j=0;j<quantidade;j++){
                        vetor_corresp[j]=false;
                    }
                    for(int i=0;i<split.size();i++){
                        if((split[i].size()>1)&&(split[i].toStdString()[0]>=97&&split[i].toStdString()[0]<=122)){
                            std::list<thing> *retorno=tabela_hash.search(split[i].toStdString());
                            std::list<thing>::iterator it;
                            it=retorno->begin();
                            for (int j=0;j<quantidade;j++){vetor_corresp2[j]=false;}
                            for(unsigned int k=0;k<retorno->size();k++){
                                vetor_corresp2[it->getIndice()]=true;
                                it++;
                            }
                            for(int j=0;j<quantidade;j++){
                                if(vetor_corresp2[j]||vetor_corresp[j]){
                                    vetor_corresp[j]=true;
                                }else{
                                    vetor_corresp[j]=false;
                                }
                            }
                        }
                    }
                    std::cout<<"resultados:\n"<<std::endl;
                    for(int j=0;j<quantidade;j++){
                        if(vetor_corresp[j]){
                            std::cout<<arquivos[j]->getDoc()<<std::endl;
                        }
                    }
                    std::cout<<std::endl;
                    break;
                }
            }

        }

    }











    }
}
