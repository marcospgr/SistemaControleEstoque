#include "Funcoes.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " [nomeArquivo] [opcao] [parametro]" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    int opcao;
    opcao = std::stoi(argv[2]);
    std::vector<Produto> produtos;

    if (!lerArquivo(input, produtos)) {
        return 1;
    }

    switch (opcao) {
        case 1:
            if (argc < 4) {
                std::cerr << "Parametro faltando para gerar relatrio" << std::endl;
                return 1;
            }
            gerarRelatorio(argv[3], produtos);
            break;
        case 2:
            if (argc < 4) {
                std::cerr << "Parametro faltando para pesquisa por codigo" << std::endl;
                return 1;
            }
            pesquisarPorCodigo(produtos, argv[3]);
            break;
        case 3:
            listarMenorQuantidade(produtos);
            break;
        case 4:
            if (argc < 4) {
                std::cerr << "Parametro faltando para listar por estado" << std::endl;
                return 1;
            }
            listarPorEstado(produtos, argv[3]);
            break;
        case 5:
            if (argc < 4) {
                std::cerr << "Parametro faltando para encontrar menor quantidade por estado" << std::endl;
                return 1;
            }
            encontrarMenorQuantidadePorEstado(produtos, argv[3]);
            break;
        case 6:
            calcularQuantidadeTotal(produtos);
            break;
        default:
            std::cerr << "Opcao invalida" << std::endl;
    }

    return 0;
}
