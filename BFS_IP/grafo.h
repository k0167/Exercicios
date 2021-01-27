#ifndef GRAFO_H
#define GRAFO_H
#include <list>
#include <string>
#include <algorithm>
#include <queue>

class grafo
{
public:
    grafo(std::string *elementos,int tam);
    void BFS(int *pai,int *distancia,std::string chave);
    void insert_aresta(std::string u,std::string v);
private:
    int N;
    std::string *lista_de_elementos;
    std::list<int> *lista_de_adjacencia;
    bool search(int u,int v);
};

#endif // GRAFO_H
