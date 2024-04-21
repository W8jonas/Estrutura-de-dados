#include "filme.h"
#include "sort.h"
#include <iostream>
#include <cstring>


// Implemente aqui as funções declaradas em sort.h

void swap(Filme &a, Filme &b) {
    Filme temp = a;
    a = b;
    b = temp;
}



void bubbleSort(Filme filmes[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (strcmp(filmes[j].movieName, filmes[j + 1].movieName) > 0) {
                swap(filmes[j], filmes[j + 1]);
            }
        }
    }
}



void merge(Filme filmes[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Filme L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = filmes[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = filmes[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i].movieName, R[j].movieName) <= 0) {
            filmes[k] = L[i];
            i++;
        } else {
            filmes[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        filmes[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        filmes[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Filme filmes[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(filmes, left, mid);
        mergeSort(filmes, mid + 1, right);

        merge(filmes, left, mid, right);
    }
}


int divisao(Filme filmes[], int left, int right) {
    Filme pivot = filmes[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (strcmp(filmes[j].movieName, pivot.movieName) < 0) {
            i++;
            swap(filmes[i], filmes[j]);
        }
    }
    swap(filmes[i + 1], filmes[right]);
    return (i + 1);
}

void quickSort(Filme filmes[], int left, int right) {
    if (left < right) {
        int pi = divisao(filmes, left, right);
        quickSort(filmes, left, pi - 1);
        quickSort(filmes, pi + 1, right);
    }
}
