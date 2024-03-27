#include <iostream>
#include <fstream>
#include <sstream>

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
    // argv[1] é o nome do arquivo de entrada e argv[2] é o nome do arquivo de saída
    if (argc != 3)
    {
        cout << "Uso: " << argv[0] << " <arquivo_entrada>.csv <arquivo_saida>.dat" << endl;
        return 1;
    }

    string nomeArquivoTexto = argv[1];
    string nomeArquivoBinario = argv[2];

    std::ifstream csvFile;
    csvFile.open(nomeArquivoTexto);

    if (!csvFile) return 0;

    std::ofstream outBinFile;
    outBinFile.open(nomeArquivoBinario, ios::binary | ios::out);
    if (!outBinFile) return 0;
    
    string linha;
    getline(csvFile, linha);

    while (getline(csvFile, linha))
    {
        stringstream ss(linha);
        string index;

        Filme movie;

        getline(ss, index, ',');

        if (index.length() > 0)
        {
            // verifica primeiro caractere de cada linha
            if (ss.peek() == '"')
            {
                // Ignorar a aspa inicial
                ss.ignore();
                // Ler até a próxima aspa
                ss.getline(movie.movieName, 50, '"');
                // Ignorar a aspa final
                ss.ignore();
            } else {
                ss.getline(movie.movieName, 50, ',');
            }

            if (!(ss >> movie.yearOfRelease))
                movie.yearOfRelease = 0;
            
            ss.ignore();
            if (!(ss >> movie.watchTime))
                movie.watchTime = 0;
            
            ss.ignore();
            if (!(ss >> movie.movieRating))
                movie.movieRating = 0.0;
            
            ss.ignore();
            if (!(ss >> movie.metascore))
                movie.metascore = 0;
            
            ss.ignore();
            if (!(ss >> movie.gross))
                movie.gross = 0.0;
            
            outBinFile.write((char *)(&movie), sizeof(movie));
        }
    }

    csvFile.close();
    outBinFile.close();

    return 0;
}
