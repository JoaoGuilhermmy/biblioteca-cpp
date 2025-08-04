#include "Livro.h"

Livro::Livro(std::string titulo, std::string autor, int ano)
{
    this->titulo = titulo;
    this->autor = autor;
    this->ano = ano;
}

std::string Livro::getTitulo() const
{
    return this->titulo;
}

std::string Livro::getAutor() const
{
    return this->autor;
}

int Livro::getAno() const
{
    return this->ano;
}

void Livro::setTitulo(std::string novoTitulo)
{
    this->titulo = novoTitulo;
}

void Livro::setAutor(std::string novoAutor)
{
    this->autor = novoAutor;
}

void Livro::setAno(int novoAno)
{
    this->ano = novoAno;
}