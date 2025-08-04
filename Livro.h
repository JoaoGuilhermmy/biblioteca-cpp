#ifndef LIVRO_H
#define LIVRO_H
#include <string>

class Livro
{

public:
    Livro(std::string titulo, std::string autor, int ano);

    std::string getTitulo() const;
    std::string getAutor() const;
    int getAno() const;

    void setTitulo(std::string novoTitulo);
    void setAutor(std::string novoAutor);
    void setAno(int novoAno);

private:
    std::string titulo;
    std::string autor;
    int ano;
};

#endif