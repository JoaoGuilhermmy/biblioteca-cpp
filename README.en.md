# 📚 Library Management System

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-Vector-orange?style=for-the-badge)
![OOP](https://img.shields.io/badge/Paradigm-OOP-green?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**Complete library management system with data persistence**

[🇧🇷 Versão em Português](README.md) | [📖 About](#-about-the-project) | [🚀 Installation](#-installation) | [💡 Features](#-features)

---

</div>

## 📋 About the Project

The **Library Management System** is an application developed in C++ that demonstrates the fundamentals of Object-Oriented Programming. The system allows:

- **Add Books**: Registration with title, author and year
- **List Books**: View entire collection
- **Persistence**: Automatically saves and loads data from file
- **Interactive Interface**: Intuitive console menu

### 🎯 Objectives

- Demonstrate **Object-Oriented Programming in C++**
- Implement **Encapsulation** with well-defined classes
- Create **persistence system** with text files
- Apply **STL (Standard Template Library)** with `std::vector`
- Develop **user-friendly interface**

### ✨ Key Features

- 📖 **Book Registration** - Complete information (title, author, year)
- 📋 **Organized Listing** - Numbered and formatted display
- 💾 **Automatic Persistence** - Saves and loads data from `biblioteca.txt`
- 🔒 **Encapsulation** - Classes with getters and setters
- 🛡️ **Input Validation** - Input error handling
- 🎨 **Clean Interface** - Organized menu and clear messages

---

## 🏗️ Architecture

### Project Structure

```
library/
├── Livro.h                 # Book class declaration
├── Livro.cpp               # Book class implementation
├── Biblioteca.h            # Library class declaration
├── Biblioteca.cpp          # Library class implementation
├── main.cpp                # Entry point
├── biblioteca.txt          # Data file (generated)
└── README.md
```

### 📊 Classes and Responsibilities

#### `Livro` Class

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

**Responsibilities**:
- Store book data
- Provide controlled data access
- Ensure encapsulation

**Applied Principles**:
- ✅ Encapsulation (private data)
- ✅ Const methods for getters
- ✅ Clear and intuitive interface

#### `Biblioteca` Class

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

**Responsibilities**:
- Manage book collection
- Control data persistence
- Provide user interface
- Orchestrate system operations

**Applied Principles**:
- ✅ Single Responsibility Principle
- ✅ Separation of interface and implementation
- ✅ Constructor initializes state

---

## 💡 Features

### 🔄 System Flow

```
┌─────────────────────┐
│   Start Program     │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────────────┐
│   Biblioteca() Constructor  │
│   - Calls carregarDados()   │
│   - Reads biblioteca.txt    │
│   - Populates vector<Livro> │
└──────────┬──────────────────┘
           │
           ▼
┌─────────────────────────────┐
│   Menu Loop                 │
│   1. Add book               │
│   2. List books             │
│   0. Save and Exit          │
└──────────┬──────────────────┘
           │
           ▼
    ┌──────┴──────┐
    │             │
    ▼             ▼
┌────────┐   ┌─────────┐
│  Add   │   │  List   │
└────┬───┘   └─────────┘
     │
     ▼
┌─────────────────────────────┐
│   Option 0 - Exit           │
│   - Calls salvarDados()     │
│   - Writes biblioteca.txt   │
│   - Exits program           │
└─────────────────────────────┘
```

### 1️⃣ Add Book

```cpp
void Biblioteca::adicionarLivro() {
    std::string titulo, autor;
    int ano;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Enter title: ";
    std::getline(std::cin, titulo);
    
    std::cout << "Enter author: ";
    std::getline(std::cin, autor);
    
    std::cout << "Enter publication year: ";
    std::cin >> ano;
    
    this->livros.push_back(Livro(titulo, autor, ano));
    std::cout << "Book added successfully!" << std::endl;
}
```

**Process**:
1. Clear input buffer
2. Request book data
3. Create `Livro` object
4. Add to `vector<Livro>`
5. Confirm operation

**Features**:
- ✅ Supports titles with spaces (`getline`)
- ✅ Numeric year validation
- ✅ Immediate user feedback

### 2️⃣ List Books

```cpp
void Biblioteca::listarLivros() const {
    std::cout << "\n--- Book List ---" << std::endl;
    
    if (this->livros.empty()) {
        std::cout << "No books registered." << std::endl;
        return;
    }
    
    for (size_t i = 0; i < this->livros.size(); ++i) {
        std::cout << "Book " << i + 1 << ":" << std::endl;
        std::cout << "  Title: " << this->livros[i].getTitulo() << std::endl;
        std::cout << "  Author: " << this->livros[i].getAutor() << std::endl;
        std::cout << "  Year: " << this->livros[i].getAno() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}
```

**Features**:
- ✅ Const method (doesn't modify state)
- ✅ Checks if there are books before listing
- ✅ Automatic numbering
- ✅ Clear formatting

### 3️⃣ Save Data

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
        std::cout << "Data saved successfully!" << std::endl;
    } else {
        std::cout << "FATAL ERROR: Could not open file." << std::endl;
    }
}
```

**File Format**:
```
To Kill a Mockingbird;Harper Lee;1960
1984;George Orwell;1949
Pride and Prejudice;Jane Austen;1813
```

**Features**:
- ✅ CSV format with semicolon
- ✅ File error handling
- ✅ User feedback
- ✅ File created automatically

### 4️⃣ Load Data

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
        std::cout << "Data loaded successfully!" << std::endl;
    } else {
        std::cout << "File not found. A new one will be created on exit." << std::endl;
    }
}
```

**Process**:
1. Try to open `biblioteca.txt`
2. If exists, read line by line
3. Parse with `stringstream`
4. Create `Livro` objects
5. Add to vector

**Features**:
- ✅ Called automatically in constructor
- ✅ Supports titles/authors with spaces
- ✅ Handling if file doesn't exist
- ✅ Robust parsing with `getline` and delimiter

---

## 🚀 Installation

### Prerequisites

- **C++11+ Compiler**: GCC 4.8+, Clang 3.3+, MSVC 2015+
- **Operating System**: Windows, Linux or macOS

### Compilation

#### Linux/macOS

```bash
# Clone the repository
git clone https://github.com/JoaoGuilhermmy/library-system-cpp.git
cd library-system-cpp

# Compile
g++ -std=c++11 -o biblioteca main.cpp Livro.cpp Biblioteca.cpp

# Run
./biblioteca
```

#### Windows with MinGW

```bash
# Compile
g++ -std=c++11 -o biblioteca.exe main.cpp Livro.cpp Biblioteca.cpp

# Run
biblioteca.exe
```

#### Windows with Visual Studio

```bash
# Compile
cl /EHsc /std:c++11 main.cpp Livro.cpp Biblioteca.cpp

# Run
main.exe
```

---

## 💻 How to Use

### Complete Usage Example

```
Library file not found. A new one will be created on exit.

--- LIBRARY MENU ---
1. Add new book
2. List all books
0. Save and Exit
Choose an option: 1

--- Add New Book ---
Enter title: To Kill a Mockingbird
Enter author: Harper Lee
Enter publication year: 1960
Book added successfully!

--- LIBRARY MENU ---
1. Add new book
2. List all books
0. Save and Exit
Choose an option: 1

--- Add New Book ---
Enter title: 1984
Enter author: George Orwell
Enter publication year: 1949
Book added successfully!

--- LIBRARY MENU ---
1. Add new book
2. List all books
0. Save and Exit
Choose an option: 2

--- Book List ---
Book 1:
  Title: To Kill a Mockingbird
  Author: Harper Lee
  Year: 1960
------------------------
Book 2:
  Title: 1984
  Author: George Orwell
  Year: 1949
------------------------

--- LIBRARY MENU ---
1. Add new book
2. List all books
0. Save and Exit
Choose an option: 0
Trying to save data to 'biblioteca.txt'...
Data saved successfully!
Exiting program...
```

### Second Execution (with saved data)

```
Data loaded successfully!

--- LIBRARY MENU ---
1. Add new book
2. List all books
0. Save and Exit
Choose an option: 2

--- Book List ---
Book 1:
  Title: To Kill a Mockingbird
  Author: Harper Lee
  Year: 1960
------------------------
Book 2:
  Title: 1984
  Author: George Orwell
  Year: 1949
------------------------
```

---

## 🔧 Technical Details

### Using std::vector

```cpp
std::vector<Livro> livros;

// Add book
livros.push_back(Livro(titulo, autor, ano));

// Check if empty
if (livros.empty()) { ... }

// Iterate
for (size_t i = 0; i < livros.size(); ++i) {
    std::cout << livros[i].getTitulo();
}

// Range-based for loop (C++11)
for (const auto& livro : livros) {
    arquivo << livro.getTitulo();
}
```

**Advantages**:
- ✅ Dynamic size
- ✅ Automatic memory management
- ✅ Rich interface (push_back, size, empty)
- ✅ O(1) index access

### Input Handling

```cpp
// Clear buffer before getline
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// Numeric input validation
if (std::cin.fail()) {
    std::cout << "Invalid input." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    continue;
}
```

**Problems Solved**:
- ✅ Residual buffer after `cin >>`
- ✅ Non-numeric input causes failure
- ✅ Stream error state

### File Parsing with stringstream

```cpp
std::string linha = "To Kill a Mockingbird;Harper Lee;1960";
std::stringstream ss(linha);

std::string titulo, autor, ano_str;
std::getline(ss, titulo, ';');    // To Kill a Mockingbird
std::getline(ss, autor, ';');     // Harper Lee
std::getline(ss, ano_str, ';');   // 1960

int ano = std::stoi(ano_str);     // Convert to int
```

**Advantages**:
- ✅ Supports custom delimiters
- ✅ Works with spaces in fields
- ✅ Type-safe with explicit conversions

### Constructors and Destructors

```cpp
// Biblioteca constructor
Biblioteca::Biblioteca() {
    carregarDados();  // Automatic initialization
}

// Implicit destructor
// std::vector frees memory automatically
// std::string frees memory automatically
// No custom destructor needed
```

---

## 📊 Computational Complexity

| Operation | Complexity | Structure | Justification |
|-----------|------------|-----------|---------------|
| Add book | O(1) amortized | Vector | push_back |
| List books | O(n) | Vector | Complete iteration |
| Save data | O(n) | File I/O | Write n books |
| Load data | O(n) | File I/O | Read n books |
| Search book* | O(n) | Vector | Linear search |

*Not implemented, but would be needed for removal/editing.

---

## 🎓 OOP Concepts Applied

### 1. **Encapsulation**

```cpp
class Livro {
private:
    std::string titulo;  // Private data
    std::string autor;
    int ano;

public:
    std::string getTitulo() const { return titulo; }  // Controlled access
    void setTitulo(std::string novoTitulo) { titulo = novoTitulo; }
};
```

**Benefits**:
- ✅ Data protected from direct access
- ✅ Validation possible in setters
- ✅ Stable public interface

### 2. **Abstraction**

```cpp
// User doesn't need to know how data is saved
biblioteca.salvarDados();

// Implementation hidden
void Biblioteca::salvarDados() const {
    // Format details, streams, etc.
}
```

### 3. **Composition**

```cpp
class Biblioteca {
private:
    std::vector<Livro> livros;  // Biblioteca "has" books
};
```

**Relationship**: Biblioteca **contains** Books (has-a).

### 4. **Separation of Interface and Implementation**

```cpp
// Livro.h - Interface (declaration)
class Livro {
public:
    std::string getTitulo() const;
};

// Livro.cpp - Implementation
std::string Livro::getTitulo() const {
    return this->titulo;
}
```

---

## 🐛 Troubleshooting

### Problem: "undefined reference" compilation error

**Cause**: `.cpp` files not linked.

**Solution**:
```bash
# Compile ALL .cpp files together
g++ -o biblioteca main.cpp Livro.cpp Biblioteca.cpp
```

### Problem: Title with spaces not read correctly

**Cause**: Using `cin >>` instead of `getline`.

**Solution**:
```cpp
// ❌ Wrong - stops at first space
std::cin >> titulo;

// ✅ Correct - reads entire line
std::getline(std::cin, titulo);
```

### Problem: Data not saved

**Cause**: Program terminated without calling `salvarDados()`.

**Solution**:
- Always choose option "0" in menu
- Or add signal handling (SIGINT)

### Problem: File with wrong encoding

**Symptoms**: Special characters appear incorrectly.

**Solution**:
```bash
# Linux/macOS
export LANG=en_US.UTF-8

# Windows
chcp 65001
```

---

## 📈 Possible Improvements

### Short Term
- [ ] Search book by title/author
- [ ] Remove book
- [ ] Edit book information
- [ ] Validate year (> 0 and <= current year)

### Medium Term
- [ ] Sort books (by title, author, year)
- [ ] Loan system
- [ ] Multiple users
- [ ] SQLite database

### Long Term
- [ ] Graphical interface (Qt)
- [ ] Web system (with C++ backend)
- [ ] REST API
- [ ] User authentication
- [ ] Reports and statistics

---

## 📄 License

This project is under the MIT license. See the [LICENSE](LICENSE) file for more details.

---

## 👨‍💻 Author

**João Guilhermmy**

- 🔗 GitHub: [https://github.com/JoaoGuilhermmy](https://github.com/JoaoGuilhermmy)
- 💼 LinkedIn: [www.linkedin.com/in/joão-guilhermmy-93661b29b](https://www.linkedin.com/in/joão-guilhermmy-93661b29b)
- 📧 Email: joaoguilhermmy2@gmail.com

---

## 🙏 Acknowledgments

- C++ community for educational resources
- Professors who taught OOP
- Developers who contributed with feedback

---

<div align="center">

### ⭐ If this project was useful, consider giving it a star!

**Developed with ❤️ and lots of ☕**

### 💡 Educational project demonstrating OOP in C++

</div>
