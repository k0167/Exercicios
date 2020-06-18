#ifndef NO_H
#define NO_H
#include <QString>

class No{
private:
    int chave;
    No *filhoE,*filhoD,*pai;
public:
    No();
    No(int chave):chave(chave),filhoE(nullptr),filhoD(nullptr),pai(nullptr){};
    int getChave() const{return chave;}
    void setChave(int value){chave = value;}
    No *getFilhoE() const{return filhoE;}
    void setFilhoE(No *value){filhoE = value;}
    No *getFilhoD() const{return filhoD;}
    void setFilhoD(No *value){filhoD = value;}
    No *getPai() const{return pai;}
    void setPai(No *value){pai = value;}

    void inserir(No* novo);
    std::string ordem();
    std::string preordem();
    std::string posordem();
    No *buscar(int const &valor);
    No *minimo();
    No *maximo();
    No *sucessor();
    No *predecessor();
    No *remover();
};

#endif // NO_H
