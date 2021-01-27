#include "thing.h"

thing::thing(int quantidade,documento *documento,std::string chave,int i)
{
    qtde=quantidade;
    doc=documento;
    this->chave=chave;
    indice=i;

}

int thing::getQtde() const
{
    return qtde;
}

void thing::setQtde(int value)
{
    qtde = value;
}

documento *thing::getDoc() const
{
    return doc;
}

void thing::setDoc(documento *value)
{
    doc = value;
}

std::string thing::getChave() const
{
    return chave;
}

void thing::setChave(const std::string &value)
{
    chave = value;
}

void thing::operator =(thing item)
{
    doc=item.getDoc();
    this->qtde=item.getQtde();
    this->chave=item.getChave();
}

int thing::getIndice() const
{
    return indice;
}
