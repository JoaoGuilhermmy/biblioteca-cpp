#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include "Livro.h"

class Biblioteca
{
public:
    Biblioteca();

    void adicionarLivro();
    void listarLivros() const;
    void salvarDados() const;
    void executar();

private:
    std::vector<Livro> livros;
    void carregarDados();
};

#endif