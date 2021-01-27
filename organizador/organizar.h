#ifndef ORGANIZAR_H
#define ORGANIZAR_H


class organizar
{
public:
    organizar();
    void static selectionSort(int *vetor,int tam);
    void static insertionSort(int *vetor,int tam);
    void static bubbleSort(int *vetor,int tam);
    void static mergeSort(int *vetor,int inicio,int fim);
    void static quickSort(int *vetor,int inicio,int fim);
    void static heapSort(int *vetor,int tamanho);
    void static radixSort(int *vetor,int tamanho);
private:

    void static merge(int *vetor,int inicio,int meio,int fim);
    int static quick(int *vetor,int inicio,int fim);
    void static maxHeapify(int *vetor,int tamanho,int altura);
    void static buildmaxheap(int *vetor,int tamanho);
    void static countingSort(int *vetor,int tamanho,int K);
};

#endif // ORGANIZAR_H
