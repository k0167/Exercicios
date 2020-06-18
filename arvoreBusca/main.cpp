#include <iostream>
#include "no.h"

using namespace std;
int menu(){
    cout<<"0 - Sair"<<endl;
    cout<<"1 - incluir"<<endl;
    cout<<"2 - ordem"<<endl;
    cout<<"3 - preordem"<<endl;
    cout<<"4 - posordem"<<endl;
    cout<<"5 - buscar"<<endl;
    cout<<"6 - minimo"<<endl;
    cout<<"7 - maximo"<<endl;
    cout<<"8 - sucessor"<<endl;
    cout<<"9 - predecessor"<<endl;
    cout<<"10 - remover"<<endl;
    cout<<"Digite a opcao:"<<endl;
    int op;
    cin>>op;
    return op;
}


int main(){
    No* arvore=nullptr, *novo=nullptr;
        int chave, op=1;
        while(op!=0){
                op=menu();
                switch(op){
                    case 1:{
                    cout<<"Digite uma chave para ser inserida: ";
                    cin>>chave;
                    novo = new No(chave);
                    if(arvore==nullptr)
                        arvore=novo;
                    else
                        arvore->inserir(novo);
                    break;
                    }

                    case 2:
                        cout<<arvore->ordem()<<endl;
                    break;

                    case 3:
                        cout<<arvore->preordem()<<endl;
                    break;

                    case 4:
                        cout<<arvore->posordem()<<endl;
                    break;

                    case 5:{
                        cout<<"digite o valor"<<endl;
                        cin>>chave;
                        No* aux=nullptr;
                        aux=arvore->buscar(chave);
                        if(aux!=nullptr)
                            cout<<"buscado o valor "<<aux->getChave()<<endl;
                        else
                            cout<<"nao encontrado"<<endl;
                    break;
                    }
                    case 6:{
                        cout<<arvore->minimo()->getChave()<<endl;
                    break;
                    }
                    case 7:
                        cout<<arvore->maximo()->getChave()<<endl;
                    break;

                    case 8:
                        cout<<arvore->sucessor()->getChave()<<endl;
                    break;
                    case 9:
                        cout<<arvore->predecessor()->getChave()<<endl;
                    break;
                    case 10:{
                        cout<<"digite o valor para remover"<<endl;
                        cin>>chave;
                        No* aux=nullptr;
                        aux=arvore->buscar(chave);
                        try {
                            aux=aux->remover();
                            cout<<"Removido o valor "<<aux->getChave()<<endl;
                        } catch (QString &msg) {
                            cout<<msg.toStdString()<<endl;
                        }
                    break;
                    }
                }
            }
}
