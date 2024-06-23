#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include "Produto.hpp"
#include <vector>
#include <string>

bool lerArquivo(const std::string &input, std::vector<Produto> &produtos);
void gerarRelatorio(const std::string &output, const std::vector<Produto> &produtos);
void pesquisarPorCodigo(const std::vector<Produto> &produtos, const std::string &codigo);
void listarMenorQuantidade(const std::vector<Produto> &produtos);
void listarPorEstado(const std::vector<Produto> &produtos, const std::string &estado);
void encontrarMenorQuantidadePorEstado(const std::vector<Produto> &produtos, const std::string &estado);
void calcularQuantidadeTotal(const std::vector<Produto> &produtos);

#endif // FUNCOES_HPP
