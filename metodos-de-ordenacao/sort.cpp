#include "filme.h"
#include "sort.h"
#include <iostream>
#include <cstring>



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


