#include "elemento.h"
#include <QString>
class Lista{
private:
    Elemento* inicio;
    Elemento* fim;
public:
    Lista(){
        this->inicio=this->fim=nullptr;
    }
    ~Lista(){
        if(this->inicio!=nullptr)
            delete this->inicio;
    }
    void inserir(Elemento* novo){
        if(this->inicio==nullptr)
            this->inicio=this->fim=novo;
        else{
            novo->setProximo(this->inicio);
            this->inicio=novo;
        }
    }
    Elemento* retirar(){
        if(this->inicio==nullptr)
            return nullptr;
        else{
            Elemento* aux=this->inicio;
            this->inicio=inicio->getProximo();
            aux->setProximo(nullptr);
            return aux;
        }
    }
    bool estaVazio(){
        if(this->inicio==nullptr)
            return true;
        else
            return false;
    }
    void inserirNoFim(Elemento* novo) {
        fim->setProximo(novo);
        fim=novo;
    }
    QString listar(){

    }

};

int main(){
}
