#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "Biblioteca.h"

// O construtor chama carregarDados() assim que um objeto Biblioteca é criado.
Biblioteca::Biblioteca()
{
    carregarDados();
}

void Biblioteca::executar()
{
    int opcao;
    while (true)
    {
        std::cout << "\n--- MENU DA BIBLIOTECA ---" << std::endl;
        std::cout << "1. Adicionar novo livro" << std::endl;
        std::cout << "2. Listar todos os livros" << std::endl;
        std::cout << "0. Salvar e Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";

        std::cin >> opcao;

        if (std::cin.fail())
        {
            std::cout << "Entrada invalida. Por favor, digite um numero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (opcao)
        {
        case 1:
            adicionarLivro();
            break;
        case 2:
            listarLivros();
            break;
        case 0:
            salvarDados();
            std::cout << "Saindo do programa..." << std::endl;
            return;
        default:
            std::cout << "Opcao invalida! Tente novamente." << std::endl;
            break;
        }
    }
}

void Biblioteca::adicionarLivro()
{
    std::string titulo, autor;
    int ano;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n--- Adicionar Novo Livro ---" << std::endl;
    std::cout << "Digite o titulo: ";
    std::getline(std::cin, titulo);
    std::cout << "Digite o autor: ";
    std::getline(std::cin, autor);
    std::cout << "Digite o ano de publicacao: ";
    std::cin >> ano;

    this->livros.push_back(Livro(titulo, autor, ano));
    std::cout << "Livro adicionado com sucesso!" << std::endl;
}

void Biblioteca::listarLivros() const
{
    std::cout << "\n--- Lista de Livros ---" << std::endl;
    if (this->livros.empty())
    {
        std::cout << "Nenhum livro cadastrado." << std::endl;
        return;
    }
    for (size_t i = 0; i < this->livros.size(); ++i)
    {
        std::cout << "Livro " << i + 1 << ":" << std::endl;
        std::cout << "  Titulo: " << this->livros[i].getTitulo() << std::endl;
        std::cout << "  Autor: " << this->livros[i].getAutor() << std::endl;
        std::cout << "  Ano: " << this->livros[i].getAno() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

void Biblioteca::salvarDados() const
{
    std::ofstream arquivo_saida("biblioteca.txt");
    std::cout << "Tentando salvar dados em 'biblioteca.txt'..." << std::endl;
    if (arquivo_saida.is_open())
    {
        for (const auto &livro : this->livros)
        {
            arquivo_saida << livro.getTitulo() << ";" << livro.getAutor() << ";" << livro.getAno() << std::endl;
        }
        arquivo_saida.close();
        std::cout << "Dados salvos com sucesso!" << std::endl;
    }
    else
    {
        std::cout << "ERRO FATAL: Nao foi possivel abrir o arquivo para salvar." << std::endl;
    }
}

void Biblioteca::carregarDados()
{
    std::ifstream arquivo_entrada("biblioteca.txt");
    std::string linha;
    if (arquivo_entrada.is_open())
    {
        while (std::getline(arquivo_entrada, linha))
        {
            std::stringstream ss(linha);
            std::string titulo, autor, ano_str;
            std::getline(ss, titulo, ';');
            std::getline(ss, autor, ';');
            std::getline(ss, ano_str, ';');
            int ano = std::stoi(ano_str);
            this->livros.push_back(Livro(titulo, autor, ano));
        }
        arquivo_entrada.close();
        std::cout << "Dados carregados com sucesso!" << std::endl;
    }
    else
    {
        std::cout << "Arquivo de biblioteca nao encontrado. Um novo sera criado ao sair." << std::endl;
    }
}