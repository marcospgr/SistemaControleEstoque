#include "Funcoes.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>

bool lerArquivo(const std::string &input, std::vector<Produto> &produtos) {
    std::ifstream arquivo(input);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return false;
    }

    int quantidadeProdutos;
    arquivo >> quantidadeProdutos;
    arquivo.ignore(); // Ignorar o newline apos a quantidade

    produtos.resize(quantidadeProdutos);

    for (int i = 0; i < quantidadeProdutos; ++i) {
        std::getline(arquivo, produtos[i].codigo);
        std::getline(arquivo, produtos[i].nome);
        arquivo >> produtos[i].quantidade;
        arquivo >> produtos[i].preco;
        arquivo.ignore(); // Ignorar o newline apos o preco
        std::getline(arquivo, produtos[i].estado);
    }

    arquivo.close();
    return true;
}

void gerarRelatorio(const std::string &output, const std::vector<Produto> &produtos) {
    std::ofstream arq(output);
    if (!arq.is_open()) {
        std::cerr << "ERRO: Nao foi possivel abrir o arquivo." << std::endl;
        return;
    }

    std::vector<Produto> produtosOrdenados = produtos;
    std::sort(produtosOrdenados.begin(), produtosOrdenados.end(), [](const Produto &a, const Produto &b) {
        return a.nome < b.nome;
    });

    for (const auto &produto : produtosOrdenados) {
        arq << produto.codigo << "\n";
        arq << produto.nome << "\n";
        arq << produto.quantidade << "\n";
        arq << produto.preco << "\n";
        arq << produto.estado << "\n";
    }

    arq.close();
}

void pesquisarPorCodigo(const std::vector<Produto> &produtos, const std::string &codigo) {
    for (const auto &produto : produtos) {
        if (produto.codigo == codigo) {
            std::cout << produto.codigo << "\n";
            std::cout << produto.nome << "\n";
            std::cout << produto.quantidade << "\n";
            std::cout << produto.preco << "\n";
            std::cout << produto.estado << "\n";
            return;
        }
    }
    std::cerr << "Produto nao encontrado" << std::endl;
}

void listarMenorQuantidade(const std::vector<Produto> &produtos) {
    if (produtos.empty()) {
        std::cerr << "Nenhum produto cadastrado" << std::endl;
        return;
    }

    auto minProduto = std::min_element(produtos.begin(), produtos.end(), [](const Produto &a, const Produto &b) {
        return a.quantidade < b.quantidade;
    });

    std::cout << minProduto->codigo << "\n";
    std::cout << minProduto->nome << "\n";
    std::cout << minProduto->quantidade << "\n";
    std::cout << minProduto->preco << "\n";
    std::cout << minProduto->estado << "\n";
}

void listarPorEstado(const std::vector<Produto> &produtos, const std::string &estado) {
    std::vector<Produto> produtosPorEstado;
    std::copy_if(produtos.begin(), produtos.end(), std::back_inserter(produtosPorEstado), [&estado](const Produto &produto) {
        return produto.estado == estado;
    });

    std::sort(produtosPorEstado.begin(), produtosPorEstado.end(), [](const Produto &a, const Produto &b) {
        return a.nome < b.nome;
    });

    for (const auto &produto : produtosPorEstado) {
        std::cout << produto.codigo << "\n";
        std::cout << produto.nome << "\n";
        std::cout << produto.quantidade << "\n";
        std::cout << produto.preco << "\n";
        std::cout << produto.estado << "\n";
    }
}

void encontrarMenorQuantidadePorEstado(const std::vector<Produto> &produtos, const std::string &estado) {
    std::vector<Produto> produtosPorEstado;
    std::copy_if(produtos.begin(), produtos.end(), std::back_inserter(produtosPorEstado), [&estado](const Produto &produto) {
        return produto.estado == estado;
    });

    if (produtosPorEstado.empty()) {
        std::cerr << "Nenhum produto encontrado para o estado especificado" << std::endl;
        return;
    }

    auto minProduto = std::min_element(produtosPorEstado.begin(), produtosPorEstado.end(), [](const Produto &a, const Produto &b) {
        return a.quantidade < b.quantidade;
    });

    std::cout << minProduto->codigo << "\n";
    std::cout << minProduto->nome << "\n";
    std::cout << minProduto->quantidade << "\n";
    std::cout << minProduto->preco << "\n";
    std::cout << minProduto->estado << "\n";
}

void calcularQuantidadeTotal(const std::vector<Produto> &produtos) {
    int quantidadeTotal = std::accumulate(produtos.begin(), produtos.end(), 0, [](int total, const Produto &produto) {
        return total + produto.quantidade;
    });

    std::cout << quantidadeTotal << "\n";
}
