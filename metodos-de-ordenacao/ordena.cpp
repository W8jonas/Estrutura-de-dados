#include <iostream> 
#include <string>
#include <fstream>


using namespace std;


int main(int argc, char* argv[])
{
    cout << "BORA "  << endl;

    // o programa obrigatoriamente recebe dois argumentos por linha de comando
    // argv[1] é o nome do arquivo binário e argv[2] é um inteiro que indica qual método de ordenação será utilizado:
    // 1 - método simples 
    // 2 - merge sort
    // 3 - quick sort
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

    
    // Criar um vetor de n filmes.

    // Ler os filmes do arquivo binário e armazenar no vetor.
    
    // Ordenar o vetor de filmes de acordo com o método escolhido.

    // Escrever o vetor de filmes ordenado em um arquivo texto chamado "filmes_ordenados.txt".'
    
    return 0;
}
