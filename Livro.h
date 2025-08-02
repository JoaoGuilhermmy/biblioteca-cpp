#ifndef LIVRO_H
#define LIVRO_H

#include <string>

class Livro
{
public:
    Livro(std::string titulo, std::string autor, int ano);

    std::string getTitulo();
    std::string getAutor();
    int getAno();

private:
    std::string titulo;
    std::string autor;
    int ano;
};

#endif