#include "elemento.h"

Elemento::Elemento(){
    this->proximo=nullptr;
    this->conteudo=0;
}
Elemento::~Elemento(){
    if(this->proximo==nullptr)
        delete proximo;
}
void Elemento::setProximo(Elemento *novo){
    this->proximo=novo;
}
Elemento* Elemento::getProximo(){
    return this->proximo;
}
void Elemento::setConteudo(int novo){
    this->conteudo=novo;
}
int Elemento::getConteudo(){
    return this->conteudo;
}
