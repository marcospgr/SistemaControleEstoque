#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto {
public:
    std::string codigo;
    std::string nome;
    int quantidade;
    float preco;
    std::string estado;

    Produto() : quantidade(0), preco(0.0f) {}
};

#endif // PRODUTO_HPP
