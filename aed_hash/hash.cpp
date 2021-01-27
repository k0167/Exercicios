#include "hash.h"
hash::hash(int tam)
{
    N=tam;
    vetor=new thing*[N];
    for(int i=0;i<N;i++){
        vetor[i]=nullptr;
    }
    qtde=0;
}

int hash::hash_key1(std::string chave)
{
    long long k=0;
    long int p=1;
    for(int i=chave.size()-1;i>=0;i--){
        k=k+char(chave[i])*p;
        p*=256;
    }
    double res=k*A;
    int inteiro=res;
    inteiro = N*(res-inteiro);
    return inteiro;
}

int hash::hash_key2(std::string chave)
{
    long long k=0;
    long int p=1;
    for(int i=chave.size()-1;i>=0;i--){
        k=k+char(chave[i])*p;
        p*=256;
    }
    double res=k*B;
    int inteiro=res;
    inteiro = N*(res-inteiro);
    return inteiro;
}

void hash::insert(std::string chave, documento &doc,int indice)
{
    if(qtde!=N){
        int h1=hash_key1(chave);
        int h2=hash_key2(chave);
        thing *aux=new thing(1,&doc,chave,indice);
        for(int x=0;x<N;x++){
            if(vetor[(h1+h2*x)%N]==nullptr){
               vetor[(h1+h2*x)%N]=aux;
               qtde++;
               break;
            }else if((chave==vetor[(h1+h2*x)%N]->getChave())&&(vetor[(h1+h2*x)%N]->getDoc()==&doc)){
                    vetor[(h1+h2*x)%N]->setQtde(vetor[(h1+h2*x)%N]->getQtde()+1);
                    break;
                }
            }
    }else{
        throw("hash Cheia!");
    }
}

std::list<thing> *hash::search(std::string chave){
    int h1=hash_key1(chave);
    int h2=hash_key2(chave);
    std::list<thing> *lista = new std::list<thing>;
    for(int x=0;x<N;x++){
        if(vetor[(h1+h2*x)%N]==nullptr){
           return lista;
        }else{
            if(vetor[(h1+h2*x)%N]->getChave()==chave){
                thing aux=*vetor[(h1+h2*x)%N];//sobrecarga
                lista->push_back(aux);
            }
        }
    }
    return lista;
}
int hash::getQtde() const
{
    return qtde;
}
