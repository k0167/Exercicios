#ifndef THING_H
#define THING_H
#include "documento.h"

class thing
{
public:
    thing(int quantidade,documento *documento,std::string chave,int i);
    int getQtde() const;
    documento *getDoc() const;
    std::string getChave() const;

    void setQtde(int value);
    void setDoc(documento *value);
    void setChave(const std::string &value);
    void operator =(thing item);

    int getIndice() const;

private:
    int indice;
    std::string chave;
    documento * doc;
    int qtde;
};

#endif // THING_H
