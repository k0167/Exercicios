#ifndef HASH_H
#define HASH_H
#include <utility>
#include <string>
#include "thing.h"
class hash
{
public:
    hash(int tam);
    int hash_key1(std::string chave);
    int hash_key2(std::string chave);
    void insert(std::string chave, documento &doc,int indice);
    std::list<thing> *search(std::string chave);
    int getQtde() const;

private:
    double A=0.3591409142295225; //  e/2-1
    double B=0.5707963267948966;   //  pi/2-1
    thing **vetor;
    int N;
    int qtde;
};

#endif // HASH_H
