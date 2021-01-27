#include <iostream>
#include "grafo.h"
#include <iostream>
#include <QStringList>
#include <fstream>
#include <stack>

int main()
{
    int N;
    std::string linha;
    std::ifstream dados;

    dados.open("C:\\Users\\carlos\\Documents\\BFS_IP\\ips.txt");
    if(dados.fail())
        throw("Arquivo não existe!");
    else{
        int cont=0;

        do {
            std::getline(dados,linha);
            cont++;
        } while (linha.size()>1);

        N=cont-1;
        dados.close();

        std::string vetor[N];

        dados.open("C:\\Users\\carlos\\Documents\\BFS_IP\\ips.txt");

        for (int i=0;i<N;i++){
            std::getline(dados,linha);
            vetor[i]=linha;
        }

        grafo G(vetor,N);

        std::getline(dados,linha);
        do {
            std::getline(dados,linha);

            QString aux=QString::fromStdString(linha);
            aux.remove('-');
            aux.remove(',');
            QStringList list=aux.split(' ');

            for (int i=1;i<list.size();i++){
                if(list[i].size()>=7){
                    G.insert_aresta(list[0].toStdString(),list[i].toStdString());
                }
            }

        } while (linha.size()>1);

        do {
            std::getline(dados,linha);

            if(linha.size()>1){
                QString aux=QString::fromStdString(linha);
                aux.remove(',');
                QStringList list=aux.split(' ');
                std::string inicio=list[0].toStdString();
                std::string fim=list[2].toStdString();

                std::cout<<"Rota de: "<<inicio<<" para: "<<fim<<std::endl<<std::endl;

                int pais[N],dist[N];
                std::stack<int> P;//pilha para retornar a ordem do inicio --> fim, pois a BFS retorna do fim para o inicio

                G.BFS(pais,dist,inicio);

                int indice=-2;

                if(fim[fim.length()-1]=='5'&&fim[fim.length()-2]=='5'&&fim[fim.length()-3]=='2'){//broadcast

                    for(int j=0;j<N;j++){
                        indice=j;
                        P.push(indice);
                        for(int i=0;i<N&&indice!=-1;i++){
                            P.push(pais[indice]);
                            indice=pais[indice];
                        }

                        P.pop();//pop no -1 que entra no fim do loop
                        if(P.size()<2){
                            std::cout<<"Sem rota/loopback";
                        }else{
                            while(!P.empty()){
                                std::cout<<vetor[P.top()];
                                if(P.size()>1)std::cout<<" -> ";
                                P.pop();
                            }

                        }
                        std::cout<<std::endl;
                    }
                }else{

                    for(int i=0;i<N && indice!=i-1;i++){
                        if(vetor[i]==fim){
                            indice=i;
                        }
                    }
                    P.push(indice);

                    for(int i=0;i<N&&indice!=-1;i++){
                        P.push(pais[indice]);
                        indice=pais[indice];
                    }
                    P.pop();

                    if(P.size()<2){
                        std::cout<<"Sem rota/loopback";
                    }else{
                        while(!P.empty()){
                            std::cout<<vetor[P.top()];
                            if(P.size()>1)std::cout<<" ----> ";//if so para nao imprimir setinha de mais
                            P.pop();
                        }
                    }
                    std::cout<<std::endl<<std::endl;
                }
            }
        } while (!dados.eof());

    }
    dados.close();// :D
}



