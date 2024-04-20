#ifndef FILME_H__
#define FILME_H__

// Coloque aqui aa definição da estrutura que representa o filme.
typedef struct {
    char movieName[51];
    int yearOfRelease;
    int watchTime;
    double movieRating;
    int metascore;
    double gross;
} Filme;


#endif /* FILME_H__ */
