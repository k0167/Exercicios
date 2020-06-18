#include <iostream>
#include <QString>
using namespace std;

class Pilha{
private:
    int max;
    int *vet;
    int topo=-1;
public:
    Pilha(int tam){
        int *vet=new int[tam];
        this->max=tam;
        this->vet=vet;
    }
    ~Pilha(){
        delete this->vet;
    }
    void push(int valor){
        if(this->topo==max-1)
            throw(string("Pilha cheia!"));
        this->topo++;
        this->vet[topo]=valor;
    }
    int pop(){
        if(this->topo==-1)
            throw(string("Pilha vazia!"));
        this->topo--;
        return this->vet[topo+1];
    }

};
int ConvToBin(int num, Pilha &a){
    int conta=0;
    do{
        a.push(num%2);
        num=num/2;
        conta++;
    }while(num!=0);
    return conta;
}
int main(){
    Pilha *p=new Pilha(10);
    int num, tam=0;
    while(true){
        cout<<"Digite um numero entre 0 e 1023 :";
        cin>>num;
        if((num>=0)&&(num<=1023)){
            tam=ConvToBin(num,*p);
            cout<<num<<" em binario e: ";
            for(int i=tam;i>0;i--){
                cout<<p->pop();
            }
            cout<<endl;
        }else
            cout<<"Numero fora do intervalo!"<<endl;
    }
}
