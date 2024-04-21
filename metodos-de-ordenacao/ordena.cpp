#include <iostream> 
#include <string>
#include <fstream>
#include "sort.h"
#include "filme.h"

using namespace std;

int obter_lista_de_filmes(const std::string& nomeArquivoBinario, Filme filmes[])
{
    ifstream binFile(nomeArquivoBinario, ios::binary);

    if (!binFile.is_open()) {
        cout << "Erro ao abrir o arquivo de filmes." << endl;
        return 0;
    }

    int count = 0;
    while (binFile.read(reinterpret_cast<char*>(&filmes[count]), sizeof(Filme))) {
        count++;
    }

    binFile.close();
    return count;
}

void displayFilmes(Filme filmes[], int tamanho) {
    ofstream outFile("ordena.txt");

    if (!outFile.is_open()) {
        cout << "Erro ao abrir o arquivo de saída." << endl;
        return;
    }

    outFile << setw(50) << left << "NOME" << setw(8) << "Year" << setw(10) << "Metascore" << endl;
    outFile << setfill('-') << setw(68) << "" << setfill(' ') << endl; // Linha separadora

    for (int i = 0; i < tamanho; i++) {
        outFile << setw(50) << left << filmes[i].movieName
                << setw(8) << filmes[i].yearOfRelease
                << setw(10) << filmes[i].metascore << endl;
    }

    outFile.close();
}

int main(int argc, char* argv[])
{

    if (argc != 3)
    {
        std::cout << "Uso: " << argv[0] << " <arquivo_binário>.csv inteiro" << std::endl;
        return 1;
    }

    if(atoi(argv[2]) < 1 || atoi(argv[2]) > 3)
    {
        std::cout << "O inteiro deve ser 1, 2 ou 3, onde  \n 1 - método simples \n 2 - merge sort \n 3 - quick sort" << std::endl;
        return 1;
    }

    Filme filme;
    Filme filmes[500]; // supondo que tenham menos de 500 filmes

    std::string nomeArquivoBinario = argv[1];

    int totalDeFilmes = obter_lista_de_filmes(nomeArquivoBinario, filmes);

    int tipoMetodo = atoi(argv[2]);

    cout << "\tipoMetodo:" << tipoMetodo << endl;

    if (tipoMetodo == 1) {
        bubbleSort(filmes, totalDeFilmes);
        displayFilmes(filmes, totalDeFilmes);
    }
    
    return 0;
}
