# SistemaControleEstoque
Universidade Federal de Minas Gerais 
Departamento de Ciência da Computação 
Programação e Desenvolvimento de Software II

André Vasconcelos Borges Morais 2021073852
Fernanda Lorenza Fernandes Pinto 2022096984
Lucas de Almeida Souza 
Marcos Paulo Gomes Rodrigues 2022080747
Pedro Lopes Ozelin 2020095488
Vitor Coimbra Pontes Maia 2022054622

Trabalho Prático - Sistema para controle de estoque

O trabalho prático consiste na implementação de um sistema de controle de estoque, que receberá como entrada a lista de produtos em um arquivo de extensão TXT.
O programa inicialmente deve ler as entradas contendo informações sobre os produtos, armazenar essas entradas em alguma estrutura interna (em memória) e realizar as operações solicitadas.
Este programa deve ser capaz de receber dados por parâmetro de linha de comando, bem como trabalhar com leitura e gravação de arquivos de texto.

*ENTRADA: 
A primeira linha possui a quantidade (Q) de produtos que constam na lista 
As próximas 5 * Q linhas representam os dados de cada produto
⇢ Código
⇢ Nome
⇢ Quantidade
⇢ Preço
⇢ Estado

*Execução: O programa deve ser executado a partir da linha de comando com os seguintes parâmetros:
.\tp2 [param1] [param2] [param3]

[param1]: Nome do arquivo de entrada.

[param2]: Número correspondente a função a ser executada, a saber:
Gerar relatório de estoque
Pesquisar por produto pelo código
Listar dados do produto com menor quantidade em estoque
Listar produtos por estado
Encontrar produto com menor quantidade em estoque do estado

Calcular a quantidade total de itens no estoque

[param3]: Nome do arquivo de saída (se função 1), código do produto desejado (se função 2), ou sigla do estado desejado (funções 4 e 5).

Exemplo de cada chamada, considerando o arquivo input.txt como arquivo de entrada:
Gerar relatório de estoque: .\tp2 input.txt 1 output.txt
Pesquisar por produto pelo código .\tp2 input.txt 2 0123
Listar dados do produto com menor quantidade em estoque .\tp2 input.txt 3
Listar produtos por estado.\tp2 input.txt 4 MG
Encontrar produto com menor quantidade em estoque do estado.\tp2 input.txt 5 SP
Calcular a quantidade total de itens no estoque: .\tp2 input.txt 6

*SAÍDA: 

Gerar relatório de estoque:
O programa deve gerar um arquivo TXT, com o nome passado pelo param3, salvo no mesmo diretório de execução. Deve-se salvar a lista de todos os produtos COM OS NOMES EM ORDEM ALFABÉTICA, com os mesmos dados da entrada, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
Pesquisar por produto pelo código:
O programa deverá imprimir na saída padrão (tela) todos os dados do produto que tenha o código igual ao informado no param3, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
Listar dados do produto com menor quantidade em estoque:
O programa deverá imprimir na saída padrão (tela) todos os dados do produto que possui a menor quantidade em estoque, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
Pesquisar por produto pelo estado:
O programa deverá imprimir na saída padrão (tela) a lista de produtos do estado informado no param3, EM ORDEM ALFABÉTICA, com todos os dados de cada produto, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
Encontrar produto com menor quantidade em estoque do estado:
O programa deverá imprimir na saída padrão (tela) o produto do estado informado no param3 que possui a menor quantidade em estoque, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
Calcular a quantidade total de itens no estoque:
O programa deverá imprimir na saída padrão (tela) a quantidade total de itens. Para o cálculo da quantidade total de itens do estoque deve-se somar a quantidade de cada produto, recebida no arquivo de entrada.
Cada dado deve ser impresso por linha
