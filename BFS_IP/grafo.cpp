#include "grafo.h"
grafo::grafo(std::string *elementos,int tam)
{
    this->N=tam;
    this->lista_de_elementos=elementos;
    lista_de_adjacencia=new std::list<int>[N];
}

void grafo::BFS(int *pai, int *distancia, std::string chave)
{
    int u,v;
    char color[N];
    for(int i=0;i<N;i++){
        pai[i]=-1;
        distancia[i]=INT_MAX;
        color[i]='w';
    }

    int ind_chave=-2;
    for(int i=0;i<N && ind_chave!=i-1;i++){
        if(lista_de_elementos[i]==chave){
            ind_chave=i;
        }
    }
    distancia[ind_chave]=0;
    color[ind_chave]='g';
    std::queue<int> Q;
    Q.push(ind_chave);
    std::list<int>::iterator i;
    while(!Q.empty()){
        u=Q.front();
        for(i=lista_de_adjacencia[u].begin();i!=lista_de_adjacencia[u].end();i++){
            v=*i;
            if(color[v]=='w'){
                Q.push(v);
                color[v]='g';
                pai[v]=u;
                distancia[v]=distancia[u]+1;
            }
        }
        color[u]='b';
        Q.pop();
    }
}


void grafo::insert_aresta(std::string u, std::string v)
{
    int ind_u=-2,ind_v=-2;
    for(int i=0;i<N && ind_u!=i-1;i++){
        if(lista_de_elementos[i]==u){
            ind_u=i;
        }
    }
    for(int i=0;i<N && ind_v!=i-1;i++){
        if(lista_de_elementos[i]==v){
            ind_v=i;
        }
    }

    if(((ind_u!=-2)||(ind_v!=-2))&&!search(ind_u,ind_v)){
        lista_de_adjacencia[ind_u].push_back(ind_v);
        //lista_de_adjacencia[ind_v].push_back(ind_u);
    }
}

bool grafo::search(int u, int v)
{
    std::list<int>::iterator i;
    for(i=lista_de_adjacencia[u].begin();i!=lista_de_adjacencia[u].end();i++){
        if(*i==v){return true;}
    }
    return false;
}
