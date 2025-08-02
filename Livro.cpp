#include "Livro.h"

Livro::Livro(std::string titulo, std::string autor, int ano)
{
    this->titulo = titulo;
    this->autor = autor;
    this->ano = ano;
}

std::string Livro::getTitulo() { return this->titulo; }
std::string Livro::getAutor() { return this->autor; }
int Livro::getAno() { return this->ano; }