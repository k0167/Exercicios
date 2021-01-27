#include "organizar.h"
organizar::organizar()
{

}

void organizar::selectionSort(int *vetor,int tam)
{
    int menor;
    for(int i=0;i<tam;i++){
        menor=i;
        for(int j=i+1;j<tam;j++){
            if(vetor[menor]>vetor[j])
                menor=j;
        }
        int aux=vetor[i];
        vetor[i]=vetor[menor];
        vetor[menor]=aux;
    }
}

void organizar::insertionSort(int *vetor, int tam)
{
    int atual;
    for(int i=1;i<tam;i++){
        atual=vetor[i];
        for(int j=i-1;j>=0;j--){
            if(atual<vetor[j]){
                vetor[j+1]=vetor[j];
                vetor[j]=atual;
            }
        }
    }
}

void organizar::bubbleSort(int *vetor, int tam)
{
    int aux;
    bool troca=true;
    for(int j=0;j<tam&&troca;j++){
        troca=false;
        for(int i=1;i<tam-j;i++){
            if(vetor[i-1]>vetor[i]){
                aux=vetor[i-1];
                vetor[i-1]=vetor[i];
                vetor[i]=aux;
                troca=true;
            }
        }
    }
}

void organizar::mergeSort(int *vetor, int inicio, int fim)
{
    if(inicio<fim){
        int meio=(inicio+fim)/2;
        mergeSort(vetor,inicio,meio);
        mergeSort(vetor,meio+1,fim);
        merge(vetor,inicio,meio,fim);
    }
}

void organizar::merge(int *vetor, int inicio, int meio, int fim)
{
    int tam=fim-inicio+1;
    int *aux,i,j,k;
    aux=new int[tam];
    for(i=inicio,j=meio+1,k=0;(i<=meio)&&(j<=fim);k++){
        if(vetor[i]<vetor[j]){
            aux[k]=vetor[i];
            i++;
        }else{
            aux[k]=vetor[j];
            j++;
        }
    }
    for(;i<=meio;i++,k++){
        aux[k]=vetor[i];
    }
    for(;j<=fim;j++,k++){
        aux[k]=vetor[j];
    }
    for(i=0;i<tam;i++,inicio++){
        vetor[inicio]=aux[i];
    }
}

void organizar::quickSort(int *vetor, int inicio, int fim)
{
    /*if (inicio<fim){
        int pivo=quick(vetor,inicio,fim);
        quickSort(vetor,inicio,pivo-1);
        quickSort(vetor,pivo+1,fim);
    }*/
    while (inicio < fim) {
        int j = quick(vetor, inicio, fim);
        if (j - inicio < fim - j) {
            quickSort(vetor, inicio, j - 1);
            inicio = j + 1;
        }
        else {
            quickSort(vetor, j + 1, fim);
            fim = j - 1;
        }
    }
}



int organizar::quick(int *vetor, int inicio, int fim)
{
    int tam=fim-inicio+1;
    int pivo=vetor[inicio];
    int menor=fim,maior=fim;

    for(int i=tam-1;i>0;i--){
        if(vetor[menor]<pivo){
            menor--;
        }else{
            int aux=vetor[menor];
            vetor[menor]=vetor[maior];
            vetor[maior]=aux;
            maior--;
            menor--;
        }
    }
    vetor[inicio]=vetor[maior];
    vetor[maior]=pivo;
    return maior;
}

void organizar::maxHeapify(int *vetor, int tamanho, int raiz)
{
    int filhoE=2*raiz;
    int filhoD=2*raiz+1;
    int maior=raiz;
    if(filhoE<=tamanho&&vetor[filhoE]>vetor[maior]){
        maior=filhoE;
    }
    if(filhoD<=tamanho&&vetor[filhoD]>vetor[maior]){
        maior=filhoD;
    }
    if(maior!=raiz){
        int aux = vetor[raiz];
        vetor[raiz]=vetor[maior];
        vetor[maior]=aux;
        maxHeapify(vetor,tamanho,maior);
    }
}

void organizar::buildmaxheap(int *vetor, int tamanho)
{
    for(int i=tamanho/2;i>=1;i--){
        maxHeapify(vetor,tamanho,i);
    }
}


void organizar::heapSort(int *vetor, int tamanho)
{
    buildmaxheap(vetor,tamanho);
    for(int i=tamanho;i>1;i--){
        int aux = vetor[i];
        vetor[i]=vetor[1];
        vetor[1]=aux;
        maxHeapify(vetor,i-1,1);
    }
}

void organizar::countingSort(int *vetor, int tamanho, int K)
{
    int *B;
    B=new int[K+1];
    int *C;
    C=new int[tamanho+1];
    for(int i=0;i<=K;i++){
        B[i]=0;
    }
    for(int i=0;i<tamanho;i++){
        B[vetor[i]]++;
    }
    for(int i=tamanho-1;i>=0;i--){
        C[B[vetor[i]]]=vetor[i];
        B[vetor[i]]--;
    }
    for(int i=1;i<=tamanho;i++){
        vetor[i-1]=C[i];
    }
}

void organizar::radixSort(int *vetor,int tamanho)
{
    int K=vetor[0];
    for(int i=1;i<tamanho;i++){
        if(vetor[i]>K)
            K=vetor[i];
    }
    countingSort(vetor,tamanho,K);
}
