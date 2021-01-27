#include<cstdlib>
#include<iostream>
#include "organizar.h"
#include <ctime>
#include <iomanip>
#include <time.h>


using namespace std;

void copiar(int* vetor,int* copia,long tam){
    for(long i=0;i<tam;i++){
        copia[i]=vetor[i];
    }
}
void copiarInverso(int* vetor,int* copia,long tam){
    for(long i=tam-1;i>=0;i--){
        copia[tam-i-1]=vetor[i];
    }
}

void printar(int* vetor,long tam){
    for(long i=0;i<tam;i++){
        cout<<vetor[i]<<" ";
    }
}
int precisao(int valor){
    int count=0;
    while(valor>10){
        valor=valor/10;
        count++;
    }
    return count;
}
int main()
{
    int *cresvet,*randomvet,*vetorcopia,tamanho=100;
    cresvet=new int[10000000];randomvet=new int[10000000];vetorcopia=new int[10000000];
    clock_t delta;
    double tempo;

    //cout<<fixed;cout<<setprecision(10);
    cout<<"Inicializando variaveis"<<endl;
    //-----------POPULANDO OS VETORES-------------------
    for(int i=0;i<10000000;i++){
        cresvet[i]=i;
    }
    cout<<"Vetor crescente/decrescente OK"<<endl;
    for(int i=0;i<10000000;i++){
        randomvet[i]=rand()%10000000;
    }
    cout<<"Vetor randomico OK\n"
       "Valor expresso em segundos"<<endl;
    cout<<endl;

    cout<<"                                                       Vetor Randomico\n  Tamanho |"
          "   Insertion  |   Selection  |    Bubble    |     Merge    |    Quick     "
          "|     Heap     |     Radix    |"<<endl;
    for (int i=0;i<6;i++){
        cout<<tamanho;
        for (int j=6;j>=i;j--){cout<<" ";}
        cout<<"| ";

        if(tamanho<=100000){
            copiar(randomvet,vetorcopia,tamanho);
            delta=clock();
            organizar::insertionSort(vetorcopia,tamanho);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";

            copiar(randomvet,vetorcopia,tamanho);
            delta=clock();
            organizar::selectionSort(vetorcopia,tamanho);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";

            copiar(randomvet,vetorcopia,tamanho);
            delta=clock();
            organizar::bubbleSort(vetorcopia,tamanho);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";
        }else{
            cout<<"      -      |       -      |       -      | ";
        }

        copiar(randomvet,vetorcopia,tamanho);
        delta=clock();
        organizar::mergeSort(vetorcopia,0,tamanho-1);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";

        copiar(randomvet,vetorcopia,tamanho);
        delta=clock();
        organizar::quickSort(vetorcopia,0,tamanho-1);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";

        copiar(randomvet,vetorcopia,tamanho);
        delta=clock();
        organizar::heapSort(vetorcopia,tamanho);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";

        copiar(randomvet,vetorcopia,tamanho);
        delta=clock();
        organizar::radixSort(vetorcopia,tamanho);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";
        cout<<endl;
        tamanho*=10;
    }

    cout<<endl;
    tamanho=100;
    cout<<"                                                       Vetor Crescente\n  Tamanho |   Insertion  |   Selection  |"
          "    Bubble    |     Merge    |    Quick     |     Heap     |     Radix    |"<<endl;
    for (int i=0;i<6;i++){
        cout<<tamanho;
        for (int j=6;j>=i;j--){cout<<" ";}
        cout<<"| ";

        if(tamanho<=100000){
            copiar(cresvet,vetorcopia,tamanho);
            delta=clock();
            organizar::insertionSort(vetorcopia,tamanho);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";

            copiar(cresvet,vetorcopia,tamanho);
            delta=clock();
            organizar::selectionSort(vetorcopia,tamanho);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";

            copiar(cresvet,vetorcopia,tamanho);
            delta=clock();
            organizar::bubbleSort(vetorcopia,tamanho);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";
        }else{
            cout<<"      -      |       -      |       -      | ";
        }

        copiar(cresvet,vetorcopia,tamanho);
        delta=clock();
        organizar::mergeSort(vetorcopia,0,tamanho-1);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";

        if(tamanho<1000000){
            copiar(cresvet,vetorcopia,tamanho);
            delta=clock();
            organizar::quickSort(vetorcopia,0,tamanho-1);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";
        }else{
            cout<<"      -      | ";
        }

        copiar(cresvet,vetorcopia,tamanho);
        delta=clock();
        organizar::heapSort(vetorcopia,tamanho);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";

        copiar(cresvet,vetorcopia,tamanho);
        delta=clock();
        organizar::radixSort(vetorcopia,tamanho);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";
        cout<<endl;
        tamanho*=10;
    }
    cout<<endl;

    tamanho=100;
    cout<<"                                                     Vetor Decrescente\n  Tamanho |   Insertion  |   Selection  |"
          "    Bubble    |     Merge    |    Quick     |     Heap     |     Radix    |"<<endl;
    for (int i=0;i<6;i++){
        cout<<tamanho;
        for (int j=6;j>=i;j--){cout<<" ";}
        cout<<"| ";

        if(tamanho<=100000){
            copiarInverso(cresvet,vetorcopia,tamanho);
            delta=clock();
            organizar::insertionSort(vetorcopia,tamanho);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";

            copiarInverso(cresvet,vetorcopia,tamanho);
            delta=clock();
            organizar::selectionSort(vetorcopia,tamanho);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";

            copiarInverso(cresvet,vetorcopia,tamanho);
            delta=clock();
            organizar::bubbleSort(vetorcopia,tamanho);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";
        }else{
            cout<<"      -      |       -      |       -      | ";
        }

        copiarInverso(cresvet,vetorcopia,tamanho);
        delta=clock();
        organizar::mergeSort(vetorcopia,0,tamanho-1);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";

        if(tamanho<1000000){
            copiarInverso(cresvet,vetorcopia,tamanho);
            delta=clock();
            organizar::quickSort(vetorcopia,0,tamanho-1);
            delta=clock() - delta;
            tempo=((double)delta)/(CLOCKS_PER_SEC);
            cout<<fixed<<setprecision(10-precisao((int)tempo));
            cout<<tempo<<" | ";
        }else{
                cout<<"      -      | ";
            }

        copiarInverso(cresvet,vetorcopia,tamanho);
        delta=clock();
        organizar::heapSort(vetorcopia,tamanho);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";

        copiarInverso(cresvet,vetorcopia,tamanho);
        delta=clock();
        organizar::radixSort(vetorcopia,tamanho);
        delta=clock() - delta;
        tempo=((double)delta)/(CLOCKS_PER_SEC);
        cout<<fixed<<setprecision(10-precisao((int)tempo));
        cout<<tempo<<" | ";
        cout<<endl;
        tamanho*=10;
    }

}
