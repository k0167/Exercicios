#include "no.h"
#include <iostream>
No::No(){
    chave=0;
    filhoD=filhoE=pai=nullptr;
}

void No::inserir(No* novo){
        if(novo->getChave()<this->chave){
            if(this->filhoE==nullptr){
                this->filhoE=novo;
                novo->setPai(this);
            }else
                this->filhoE->inserir(novo);
        }else{
            if(this->filhoD==nullptr){
                this->filhoD=novo;
                novo->setPai(this);
            }else
                this->filhoD->inserir(novo);
        }
}

std::string No::ordem(){
    std::string ret="";
    if(this->filhoE!=nullptr)
        ret+=filhoE->ordem();
    ret+=std::to_string(chave)+" ";
    if(this->filhoD!=nullptr)
        ret+=filhoD->ordem();
    return ret;
}

std::string No::preordem(){
    std::string ret="";
    ret+=std::to_string(chave)+" ";
    if(this->filhoE!=nullptr)
        ret+=filhoE->preordem();
    if(this->filhoD!=nullptr)
        ret+=filhoD->preordem();
    return ret;
}

std::string No::posordem(){
    std::string ret="";
    if(this->filhoE!=nullptr)
        ret+=filhoE->posordem();
    if(this->filhoD!=nullptr)
        ret+=filhoD->posordem();
    ret+=std::to_string(chave)+" ";
    return ret;
}

No *No::buscar(int const &valor){
    if(valor==this->chave)
        return this;
    else if(valor<this->chave)
        return filhoE->buscar(valor);
    else
        return filhoD->buscar(valor);
    return nullptr;
}

No *No::minimo()
{
    No *aux=this;
    while (aux->getFilhoE()!=nullptr){
        aux=aux->getFilhoE();
    }
    return aux;
}

No *No::maximo()
{
    No *aux=this;
    while (aux->getFilhoD()!=nullptr){
        aux=aux->getFilhoD();
    }
    return aux;
}

No *No::sucessor()
{
    if(this->filhoD!=nullptr)
        return filhoD->minimo();
    No *aux=this->getPai();
    No *atual=this;
    while((aux!=nullptr)&&(this->getChave()==atual->getChave())){
        atual=aux;
        aux=aux->getPai();
    }
    return aux;
}

No *No::predecessor()
{
    if(this->filhoE!=nullptr)
        return filhoE->maximo();
    No *aux=this->getPai();
    No *atual=this;
    while((aux!=nullptr)&&(this->getChave()==atual->getChave())){
        atual=aux;
        aux=aux->getPai();
    }
    return aux;
}

No *No::remover(){
    if((this->filhoE==nullptr)&&(this->filhoD==nullptr)){
        if(pai==nullptr){
            throw(QString("Arvore vazia"));
        }
        if(pai->getFilhoE()==this)
            pai->setFilhoE(nullptr);
        else
            pai->setFilhoD(nullptr);
        pai=nullptr;
        return this;
    }
    if((this->filhoE!=nullptr)&&(this->filhoD==nullptr)){
        if(pai==nullptr){
            No *ret=new No(chave);
            this->chave=filhoE->getChave();
            filhoE->remover();
            return ret;
        }
        if(pai->getFilhoE()==this)
            pai->setFilhoE(filhoE);
        else
            pai->setFilhoD(filhoE);
        filhoE->setPai(pai);
        pai=filhoE=nullptr;
        return this;
    }
    if((this->filhoE==nullptr)&&(this->filhoD!=nullptr)){
        if(pai==nullptr){
            No *ret=new No(chave);
            this->chave=filhoD->getChave();
            filhoD->remover();
            return ret;
        }
        if(pai->getFilhoE()==this)
            pai->setFilhoE(filhoD);
        else
            pai->setFilhoD(filhoD);
        filhoD->setPai(pai);
        pai=filhoD=nullptr;
        return this;
    }
    if((this->filhoE!=nullptr)&&(this->filhoD!=nullptr)){
            No *aux=filhoD->minimo();
            int chavetemp=chave;
            this->chave=aux->getChave();
            aux->setChave(chavetemp);
            return aux->remover();
    }
    return nullptr;
}
