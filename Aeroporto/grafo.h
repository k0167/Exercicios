#ifndef GRAFO_H
#define GRAFO_H
#include <list>
#include <utility>
#include <algorithm>
#include <PriorityQueueModificada.h>

#define infinito 100000000;

class grafo
{
public:
    grafo(int tam);
    void caminho(int s, int *d, int *p);
    void insert_aresta(int u, int v, int w);
    std::list<std::pair<int,int>> *adjacentes(int u);
private:
    int N;
    std::list<std::pair<int,int>> *lista_de_adjacencia;
    void relaxacao(int u,int v,int *d,int *p,int w, MyPriorityQueue *Q);
    void inicializar(int s,int *d,int *p);
    bool search(int u,int v);
};

#endif // GRAFO_H
