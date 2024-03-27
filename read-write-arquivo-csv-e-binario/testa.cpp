#include <iostream> 
#include <string>
#include <fstream>

using namespace std;


typedef struct {
    char movieName[51];
    int yearOfRelease;
    int watchTime;
    double movieRating;
    int metascore;
    double gross;
} Filme;

int main(int argc, char* argv[])
{
    // o programa obrigatoriamente recebe dois argumentos por linha de comando
    // argv[1] é o nome do arquivo binário e argv[2] é um inteiro entre 0 e 999.
    if (argc != 3)
    {
        std::cout << "Uso: " << argv[0] << " <arquivo_binário>.csv inteiro" << std::endl;
        return 1;
    }

    std::string nomeArquivoTexto = argv[1];
    int  movie_id = stoi(string(argv[2]));

    if(movie_id < 0 || movie_id > 999){
        std::cout << "O inteiro deve estar entre 0 e 999" << std::endl;
        return 1;
    }

    Filme filme;

    ifstream binFile(nomeArquivoTexto, ios::binary);

    if (!binFile.is_open()) {
        return 1;
    }

    binFile.read((char *)(&filme), sizeof(Filme));
    binFile.seekg(movie_id * sizeof(Filme), ios::beg);

    Filme filmeSelecionado;
    binFile.read((char *)(&filmeSelecionado), sizeof(Filme));

    cout << "Movie Name: " << filmeSelecionado.movieName << endl;
    cout << "Year of Release: " << filmeSelecionado.yearOfRelease << endl;
    cout << "Watch Time: " << filmeSelecionado.watchTime << endl;
    cout << "Movie Rating: " << filmeSelecionado.movieRating << endl;
    cout << "Metascore of Movie: " << filmeSelecionado.metascore << endl;
    cout << "Gross Earnings: " << filmeSelecionado.gross << endl;

    binFile.close();

    return 0;
}
