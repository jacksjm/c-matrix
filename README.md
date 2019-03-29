# BIBLIOTECA DE MATRIZES 
Criação de uma biblioteca para manipulação de matrizes.

# PASSOS PARA INICIALIZAÇÃO E COMPILAÇÃO
1. Realize a extração dos arquivos MatrizLib.zip em um diretório de sua escolha.
2. Localize o diretório através do Terminal (comando cd)
3. Ao acessar o diretório, execute o comando make (ex.: `~/Documentos/C/PPA$ make`) para compilar os arquivos. Será exibido no terminal algo semelhante a:
```
gcc -Wall -O3  -c matriz.c
gcc -Wall -O3  -c toolsv2.c
gcc -Wall -O3  matriz.o toolsv2.o main_matriz.c -o main_matriz 
gcc -Wall -O3  matriz.o toolsv2.o gera_matriz2.c -o gera_matriz2 


####### Exemplo de Execução #######
./gera_matriz2 10 10
./main_matriz 10x10-mat-1.map 10x10-mat-2.map
```
4. Caso seja necessária uma recompilação, é aconselhavel a utilização do comando make clean para que os arquivos executáveis sejam excluídos. (ex.: `~/Documentos/C/PPA$ make clean`)

# PASSOS PARA GERAÇÃO
1. Para gerar um arquivo, é necessário executar o comando gera_matriz2, passando os parâmetros de linha e coluna. (ex.: `./gera_matriz2 10 10`: Gera um arquivo com uma matriz 10x10 nomeado _10x10-mat.map_)

# PASSOS PARA EXECUÇÃO
1. Para a execução do arquivo main, é necessário executar o camando main_matriz, passandos os parâmetros de 'matriz a' e 'matriz b' que devem indicar o nome dos arquivos. (ex.: `./main_matriz 10x10-mat.map 10x10-mat-out.map`)

# DESCRIÇÃO DAS FUNÇÕES
* `gera_matriz2`: Função responsável por gerar os arquivos .map a serem lidos pela main.
    | Parâmetros  | Descrição     |
    |-|-|
    |linhas|Número de Linhas|
    |colunas|Número de Colunas|
* `main_matriz`: Função principal, responsável por executar a biblioteca criada.
    | Parâmetros  | Descrição     |
    |-|-|
    |matrizA|Matriz gerada|
    |matrizB|Nome do arquivo que será utilizado como auxiliar|
* `simple_matriz`: Função de execução simples, avalia os items da biblioteca com uma matriz simples de 10 x 10.

# EXEMPLO DE EXECUÇÃO
```
user@machine:~/Documentos/C/MatrizLib$ make


####### Exemplo de Execução #######
./gera_matriz2 10 10
./main_matriz 10x10-mat-1.map 10x10-mat-2.map
user@machine:~/Documentos/C/MatrizLib$ ./gera_matriz2 10 10
		**** PRINT mat_c NxM(10,10) **** 
##### Arquivo 10x10-mat.map: VERIFICADO! #####
user@machine:~/Documentos/C/MatrizLib$ ./main_matriz 10x10-mat.map arqout.map
		**** mat_a lida LinhaxColuna(10,10) **** 
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	24	60	26	19	24	18	26	13	35	90
(1)	55	86	54	13	47	72	92	1	20	73
(2)	63	91	54	14	20	87	2	11	64	88
(3)	67	40	48	93	59	24	11	37	90	46
(4)	28	45	84	34	11	31	58	3	84	30
(5)	76	99	21	30	13	93	70	67	57	86
(6)	7	76	26	8	70	37	84	33	74	74
(7)	32	54	72	16	40	83	48	51	86	84
(8)	81	15	84	55	45	49	0	67	17	9
(9)	5	24	86	83	84	8	72	69	93	47
		**** mat_a c/ Zeros LinhaxColuna(10,10) **** 
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	0	0	0	0	0	0	0	0	0	0
(1)	0	0	0	0	0	0	0	0	0	0
(2)	0	0	0	0	0	0	0	0	0	0
(3)	0	0	0	0	0	0	0	0	0	0
(4)	0	0	0	0	0	0	0	0	0	0
(5)	0	0	0	0	0	0	0	0	0	0
(6)	0	0	0	0	0	0	0	0	0	0
(7)	0	0	0	0	0	0	0	0	0	0
(8)	0	0	0	0	0	0	0	0	0	0
(9)	0	0	0	0	0	0	0	0	0	0
		**** mat_b gerada c/ Zeros LinhaxColuna(10,10) **** 
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	0	0	0	0	0	0	0	0	0	0
(1)	0	0	0	0	0	0	0	0	0	0
(2)	0	0	0	0	0	0	0	0	0	0
(3)	0	0	0	0	0	0	0	0	0	0
(4)	0	0	0	0	0	0	0	0	0	0
(5)	0	0	0	0	0	0	0	0	0	0
(6)	0	0	0	0	0	0	0	0	0	0
(7)	0	0	0	0	0	0	0	0	0	0
(8)	0	0	0	0	0	0	0	0	0	0
(9)	0	0	0	0	0	0	0	0	0	0
		**** Comparar mat_a / mat_b LinhaxColuna(10,10) **** 
VERIFICADO: Matrizes identicas
Runtime: 0.000001
		**** Loaded mat_a LinhaxColuna(10,10) **** 
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	24	60	26	19	24	18	26	13	35	90
(1)	55	86	54	13	47	72	92	1	20	73
(2)	63	91	54	14	20	87	2	11	64	88
(3)	67	40	48	93	59	24	11	37	90	46
(4)	28	45	84	34	11	31	58	3	84	30
(5)	76	99	21	30	13	93	70	67	57	86
(6)	7	76	26	8	70	37	84	33	74	74
(7)	32	54	72	16	40	83	48	51	86	84
(8)	81	15	84	55	45	49	0	67	17	9
(9)	5	24	86	83	84	8	72	69	93	47
O elemento [0,0] é diferente nas matrizes analisadas!
```