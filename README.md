# 📚 Sistema de Gerenciamento de Biblioteca

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-Vector-orange?style=for-the-badge)
![OOP](https://img.shields.io/badge/Paradigm-OOP-green?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**Sistema completo de gerenciamento de biblioteca com persistência de dados**

[🇺🇸 English Version](README.en.md) | [📖 Sobre](#-sobre-o-projeto) | [🚀 Instalação](#-instalação) | [💡 Funcionalidades](#-funcionalidades)

---

</div>

## 📋 Sobre o Projeto

O **Sistema de Gerenciamento de Biblioteca** é uma aplicação desenvolvida em C++ que demonstra os fundamentos da Programação Orientada a Objetos. O sistema permite:

- **Adicionar Livros**: Cadastro com título, autor e ano
- **Listar Livros**: Visualização de todo o acervo
- **Persistência**: Salva e carrega dados automaticamente de arquivo
- **Interface Interativa**: Menu intuitivo no console

### 🎯 Objetivos

- Demonstrar **Programação Orientada a Objetos em C++**
- Implementar **Encapsulamento** com classes bem definidas
- Criar **sistema de persistência** com arquivos de texto
- Aplicar **STL (Standard Template Library)** com `std::vector`
- Desenvolver **interface de usuário** amigável

### ✨ Características Principais

- 📖 **Cadastro de Livros** - Informações completas (título, autor, ano)
- 📋 **Listagem Organizada** - Visualização numerada e formatada
- 💾 **Persistência Automática** - Salva e carrega dados de `biblioteca.txt`
- 🔒 **Encapsulamento** - Classes com getters e setters
- 🛡️ **Validação de Entrada** - Tratamento de erros de input
- 🎨 **Interface Limpa** - Menu organizado e mensagens claras

---

## 🏗️ Arquitetura

### Estrutura do Projeto

```
biblioteca/
├── Livro.h                 # Declaração da classe Livro
├── Livro.cpp               # Implementação da classe Livro
├── Biblioteca.h            # Declaração da classe Biblioteca
├── Biblioteca.cpp          # Implementação da classe Biblioteca
├── main.cpp                # Ponto de entrada
├── biblioteca.txt          # Arquivo de dados (gerado)
└── README.md
```

### 📊 Classes e Responsabilidades

#### Classe `Livro`

```cpp
class Livro {
private:
    std::string titulo;
    std::string autor;
    int ano;

public:
    Livro(std::string titulo, std::string autor, int ano);
    
    // Getters
    std::string getTitulo() const;
    std::string getAutor() const;
    int getAno() const;
    
    // Setters
    void setTitulo(std::string novoTitulo);
    void setAutor(std::string novoAutor);
    void setAno(int novoAno);
};
```

**Responsabilidades**:
- Armazenar dados de um livro
- Fornecer acesso controlado aos dados
- Garantir encapsulamento

**Princípios Aplicados**:
- ✅ Encapsulamento (dados privados)
- ✅ Métodos const para getters
- ✅ Interface clara e intuitiva

#### Classe `Biblioteca`

```cpp
class Biblioteca {
private:
    std::vector<Livro> livros;
    void carregarDados();

public:
    Biblioteca();
    void adicionarLivro();
    void listarLivros() const;
    void salvarDados() const;
    void executar();
};
```

**Responsabilidades**:
- Gerenciar coleção de livros
- Controlar persistência de dados
- Fornecer interface para o usuário
- Orquestrar operações do sistema

**Princípios Aplicados**:
- ✅ Single Responsibility Principle
- ✅ Separação de interface e implementação
- ✅ Construtor inicializa estado

---

## 💡 Funcionalidades

### 🔄 Fluxo do Sistema

```
┌─────────────────────┐
│   Iniciar Programa  │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────────────┐
│   Construtor Biblioteca()   │
│   - Chama carregarDados()   │
│   - Lê biblioteca.txt       │
│   - Popula vector<Livro>    │
└──────────┬──────────────────┘
           │
           ▼
┌─────────────────────────────┐
│   Loop do Menu              │
│   1. Adicionar livro        │
│   2. Listar livros          │
│   0. Salvar e Sair          │
└──────────┬──────────────────┘
           │
           ▼
    ┌──────┴──────┐
    │             │
    ▼             ▼
┌────────┐   ┌─────────┐
│Adicionar│   │ Listar  │
└────┬───┘   └─────────┘
     │
     ▼
┌─────────────────────────────┐
│   Opção 0 - Sair            │
│   - Chama salvarDados()     │
│   - Grava biblioteca.txt    │
│   - Encerra programa        │
└─────────────────────────────┘
```

### 1️⃣ Adicionar Livro

```cpp
void Biblioteca::adicionarLivro() {
    std::string titulo, autor;
    int ano;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Digite o titulo: ";
    std::getline(std::cin, titulo);
    
    std::cout << "Digite o autor: ";
    std::getline(std::cin, autor);
    
    std::cout << "Digite o ano de publicacao: ";
    std::cin >> ano;
    
    this->livros.push_back(Livro(titulo, autor, ano));
    std::cout << "Livro adicionado com sucesso!" << std::endl;
}
```

**Processo**:
1. Limpar buffer de entrada
2. Solicitar dados do livro
3. Criar objeto `Livro`
4. Adicionar ao `vector<Livro>`
5. Confirmar operação

**Características**:
- ✅ Suporta títulos com espaços (`getline`)
- ✅ Validação de ano numérico
- ✅ Feedback imediato ao usuário

### 2️⃣ Listar Livros

```cpp
void Biblioteca::listarLivros() const {
    std::cout << "\n--- Lista de Livros ---" << std::endl;
    
    if (this->livros.empty()) {
        std::cout << "Nenhum livro cadastrado." << std::endl;
        return;
    }
    
    for (size_t i = 0; i < this->livros.size(); ++i) {
        std::cout << "Livro " << i + 1 << ":" << std::endl;
        std::cout << "  Titulo: " << this->livros[i].getTitulo() << std::endl;
        std::cout << "  Autor: " << this->livros[i].getAutor() << std::endl;
        std::cout << "  Ano: " << this->livros[i].getAno() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}
```

**Características**:
- ✅ Método `const` (não modifica estado)
- ✅ Verifica se há livros antes de listar
- ✅ Numeração automática
- ✅ Formatação clara

### 3️⃣ Salvar Dados

```cpp
void Biblioteca::salvarDados() const {
    std::ofstream arquivo_saida("biblioteca.txt");
    
    if (arquivo_saida.is_open()) {
        for (const auto& livro : this->livros) {
            arquivo_saida << livro.getTitulo() << ";" 
                         << livro.getAutor() << ";" 
                         << livro.getAno() << std::endl;
        }
        arquivo_saida.close();
        std::cout << "Dados salvos com sucesso!" << std::endl;
    } else {
        std::cout << "ERRO FATAL: Nao foi possivel abrir o arquivo." << std::endl;
    }
}
```

**Formato do Arquivo**:
```
Dom Casmurro;Machado de Assis;1899
1984;George Orwell;1949
O Cortiço;Aluísio Azevedo;1890
```

**Características**:
- ✅ Formato CSV com ponto-e-vírgula
- ✅ Tratamento de erro de arquivo
- ✅ Feedback ao usuário
- ✅ Arquivo criado automaticamente

### 4️⃣ Carregar Dados

```cpp
void Biblioteca::carregarDados() {
    std::ifstream arquivo_entrada("biblioteca.txt");
    std::string linha;
    
    if (arquivo_entrada.is_open()) {
        while (std::getline(arquivo_entrada, linha)) {
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
    } else {
        std::cout << "Arquivo nao encontrado. Um novo sera criado ao sair." << std::endl;
    }
}
```

**Processo**:
1. Tentar abrir `biblioteca.txt`
2. Se existe, ler linha por linha
3. Fazer parse com `stringstream`
4. Criar objetos `Livro`
5. Adicionar ao vector

**Características**:
- ✅ Chamado automaticamente no construtor
- ✅ Suporta títulos/autores com espaços
- ✅ Tratamento se arquivo não existe
- ✅ Parse robusto com `getline` e delimitador

---

## 🚀 Instalação

### Pré-requisitos

- **Compilador C++11+**: GCC 4.8+, Clang 3.3+, MSVC 2015+
- **Sistema Operacional**: Windows, Linux ou macOS

### Compilação

#### Linux/macOS

```bash
# Clone o repositório
git clone https://github.com/JoaoGuilhermmy/sistema-biblioteca-cpp.git
cd sistema-biblioteca-cpp

# Compile
g++ -std=c++11 -o biblioteca main.cpp Livro.cpp Biblioteca.cpp

# Execute
./biblioteca
```

#### Windows com MinGW

```bash
# Compile
g++ -std=c++11 -o biblioteca.exe main.cpp Livro.cpp Biblioteca.cpp

# Execute
biblioteca.exe
```

#### Windows com Visual Studio

```bash
# Compile
cl /EHsc /std:c++11 main.cpp Livro.cpp Biblioteca.cpp

# Execute
main.exe
```

---

## 💻 Como Usar

### Exemplo Completo de Uso

```
Arquivo de biblioteca nao encontrado. Um novo sera criado ao sair.

--- MENU DA BIBLIOTECA ---
1. Adicionar novo livro
2. Listar todos os livros
0. Salvar e Sair
Escolha uma opcao: 1

--- Adicionar Novo Livro ---
Digite o titulo: Dom Casmurro
Digite o autor: Machado de Assis
Digite o ano de publicacao: 1899
Livro adicionado com sucesso!

--- MENU DA BIBLIOTECA ---
1. Adicionar novo livro
2. Listar todos os livros
0. Salvar e Sair
Escolha uma opcao: 1

--- Adicionar Novo Livro ---
Digite o titulo: 1984
Digite o autor: George Orwell
Digite o ano de publicacao: 1949
Livro adicionado com sucesso!

--- MENU DA BIBLIOTECA ---
1. Adicionar novo livro
2. Listar todos os livros
0. Salvar e Sair
Escolha uma opcao: 2

--- Lista de Livros ---
Livro 1:
  Titulo: Dom Casmurro
  Autor: Machado de Assis
  Ano: 1899
------------------------
Livro 2:
  Titulo: 1984
  Autor: George Orwell
  Ano: 1949
------------------------

--- MENU DA BIBLIOTECA ---
1. Adicionar novo livro
2. Listar todos os livros
0. Salvar e Sair
Escolha uma opcao: 0
Tentando salvar dados em 'biblioteca.txt'...
Dados salvos com sucesso!
Saindo do programa...
```

### Segunda Execução (com dados salvos)

```
Dados carregados com sucesso!

--- MENU DA BIBLIOTECA ---
1. Adicionar novo livro
2. Listar todos os livros
0. Salvar e Sair
Escolha uma opcao: 2

--- Lista de Livros ---
Livro 1:
  Titulo: Dom Casmurro
  Autor: Machado de Assis
  Ano: 1899
------------------------
Livro 2:
  Titulo: 1984
  Autor: George Orwell
  Ano: 1949
------------------------
```

---

## 🔧 Detalhes Técnicos

### Uso de std::vector

```cpp
std::vector<Livro> livros;

// Adicionar livro
livros.push_back(Livro(titulo, autor, ano));

// Verificar se vazio
if (livros.empty()) { ... }

// Iterar
for (size_t i = 0; i < livros.size(); ++i) {
    std::cout << livros[i].getTitulo();
}

// Range-based for loop (C++11)
for (const auto& livro : livros) {
    arquivo << livro.getTitulo();
}
```

**Vantagens**:
- ✅ Tamanho dinâmico
- ✅ Gerenciamento automático de memória
- ✅ Interface rica (push_back, size, empty)
- ✅ Acesso O(1) por índice

### Tratamento de Entrada

```cpp
// Limpar buffer antes de getline
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// Validação de entrada numérica
if (std::cin.fail()) {
    std::cout << "Entrada invalida." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    continue;
}
```

**Problemas Resolvidos**:
- ✅ Buffer residual após `cin >>`
- ✅ Entrada não-numérica causa falha
- ✅ Estado de erro do stream

### Parse de Arquivo com stringstream

```cpp
std::string linha = "Dom Casmurro;Machado de Assis;1899";
std::stringstream ss(linha);

std::string titulo, autor, ano_str;
std::getline(ss, titulo, ';');    // Dom Casmurro
std::getline(ss, autor, ';');     // Machado de Assis
std::getline(ss, ano_str, ';');   // 1899

int ano = std::stoi(ano_str);     // Converte para int
```

**Vantagens**:
- ✅ Suporta delimitadores customizados
- ✅ Funciona com espaços em campos
- ✅ Tipo-seguro com conversões explícitas

### Construtores e Destrutores

```cpp
// Construtor da Biblioteca
Biblioteca::Biblioteca() {
    carregarDados();  // Inicialização automática
}

// Destrutor implícito
// std::vector libera memória automaticamente
// std::string libera memória automaticamente
// Não precisa de destrutor personalizado
```

---

## 📊 Complexidade Computacional

| Operação | Complexidade | Estrutura | Justificativa |
|----------|--------------|-----------|---------------|
| Adicionar livro | O(1) amortizado | Vector | push_back |
| Listar livros | O(n) | Vector | Iteração completa |
| Salvar dados | O(n) | File I/O | Escrever n livros |
| Carregar dados | O(n) | File I/O | Ler n livros |
| Buscar livro* | O(n) | Vector | Busca linear |

*Não implementado, mas seria necessário para remoção/edição.

---

## 🎓 Conceitos de POO Aplicados

### 1. **Encapsulamento**

```cpp
class Livro {
private:
    std::string titulo;  // Dados privados
    std::string autor;
    int ano;

public:
    std::string getTitulo() const { return titulo; }  // Acesso controlado
    void setTitulo(std::string novoTitulo) { titulo = novoTitulo; }
};
```

**Benefícios**:
- ✅ Dados protegidos de acesso direto
- ✅ Validação possível nos setters
- ✅ Interface pública estável

### 2. **Abstração**

```cpp
// O usuário não precisa saber como os dados são salvos
biblioteca.salvarDados();

// Implementação escondida
void Biblioteca::salvarDados() const {
    // Detalhes de formato, streams, etc.
}
```

### 3. **Composição**

```cpp
class Biblioteca {
private:
    std::vector<Livro> livros;  // Biblioteca "tem" livros
};
```

**Relação**: Biblioteca **contém** Livros (has-a).

### 4. **Separação de Interface e Implementação**

```cpp
// Livro.h - Interface (declaração)
class Livro {
public:
    std::string getTitulo() const;
};

// Livro.cpp - Implementação
std::string Livro::getTitulo() const {
    return this->titulo;
}
```

---

## 🐛 Solução de Problemas

### Problema: Erro de compilação "undefined reference"

**Causa**: Arquivos `.cpp` não foram linkados.

**Solução**:
```bash
# Compilar TODOS os .cpp juntos
g++ -o biblioteca main.cpp Livro.cpp Biblioteca.cpp
```

### Problema: Título com espaços não é lido corretamente

**Causa**: Uso de `cin >>` ao invés de `getline`.

**Solução**:
```cpp
// ❌ Errado - para na primeira espaço
std::cin >> titulo;

// ✅ Correto - lê linha inteira
std::getline(std::cin, titulo);
```

### Problema: Dados não são salvos

**Causa**: Programa encerrado sem chamar `salvarDados()`.

**Solução**:
- Sempre escolher opção "0" no menu
- Ou adicionar tratamento de sinais (SIGINT)

### Problema: Arquivo com encoding errado

**Sintomas**: Caracteres especiais aparecem incorretamente.

**Solução**:
```bash
# Linux/macOS
export LANG=pt_BR.UTF-8

# Windows
chcp 65001
```

---

## 📈 Possíveis Melhorias

### Curto Prazo
- [ ] Buscar livro por título/autor
- [ ] Remover livro
- [ ] Editar informações de livro
- [ ] Validar ano (> 0 e <= ano atual)

### Médio Prazo
- [ ] Ordenar livros (por título, autor, ano)
- [ ] Sistema de empréstimos
- [ ] Múltiplos usuários
- [ ] Banco de dados SQLite

### Longo Prazo
- [ ] Interface gráfica (Qt)
- [ ] Sistema web (com backend C++)
- [ ] API REST
- [ ] Autenticação de usuários
- [ ] Relatórios e estatísticas

---

## 📄 Licença

Este projeto está sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## 👨‍💻 Autor

**João Guilhermmy**

- 🔗 GitHub: [https://github.com/JoaoGuilhermmy](https://github.com/JoaoGuilhermmy)
- 💼 LinkedIn: [www.linkedin.com/in/joão-guilhermmy-93661b29b](https://www.linkedin.com/in/joão-guilhermmy-93661b29b)
- 📧 Email: joaoguilhermmy2@gmail.com

---

## 🙏 Agradecimentos

- Comunidade C++ pelos recursos educacionais
- Professores que ensinaram POO
- Desenvolvedores que contribuíram com feedback

---

<div align="center">

### ⭐ Se este projeto foi útil, considere dar uma estrela!

**Desenvolvido com ❤️ e muito ☕**

### 💡 Projeto educacional demonstrando POO em C++

</div>
