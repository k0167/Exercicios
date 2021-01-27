#ifndef ELEMENTO_H
#define ELEMENTO_H


class Elemento
{
public:
    Elemento();
    ~Elemento();
    void setProximo(Elemento *novo);
    Elemento* getProximo();
    void setConteudo(int novo);
    int getConteudo();
    bool estaVazio();


private:
    int conteudo;
    Elemento *proximo;
};

#endif // ELEMENTO_H
