# OPERAÇÕES DE MATRIZES 
Criação de uma biblioteca para operações com matrizes.

# BIBLIOTECA DE MATRIZES 
Utiliza-se uma biblioteca para manipulação de matrizes (`matric.h`).

# PASSOS PARA INICIALIZAÇÃO E COMPILAÇÃO
1. Realize a extração dos arquivos Matriz.zip em um diretório de sua escolha.
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
1. Para a execução do arquivo main, é necessário executar o camando main_matriz, passandos os parâmetros de 'matriz a' e 'matriz b', que devem indicar o nome dos arquivos, e 'operation', que indica a operação que será executada. (ex.: `./main_matriz 10x10-mat-1.map 10x10-mat-2.map 9`)

# DESCRIÇÃO DAS FUNÇÕES
* `gera_matriz2`: Função responsável por gerar os arquivos .map a serem lidos pela main.
    | Parâmetros  | Descrição     |
    |-|-|
    |linhas|Número de Linhas|
    |colunas|Número de Colunas|
* `main_matriz`: Função principal, responsável por executar as operações.
    | Parâmetros  | Descrição     |
    |-|-|
    |matrizA|Matriz A que será utilizada para as operações|
    |matrizB|Matriz B que será utilizada para as operações|
	|operation|Operação a ser executada<li>1 - Soma IJ</li><li>2 - Soma JI</li><li>3 - Multiplicação IJK</li><li>4 - Multiplicação IKJ</li><li>5 - Multiplicação KIJ</li><li>6 - Multiplicação KJI</li><li>7 - Multiplicação JIK</li><li>8 - Multiplicação JKI</li><li>9 - Todas as Operações</li><li>10 - Operações de Multiplicação</li><li>11 - Operações de Soma</li>|
* `simple_matriz`: Função de execução simples, avalia os items da biblioteca com uma matriz simples de 10 x 10.

# OBSERVAÇÕES
* A função `gera_matriz2` gera um arquivo de nome fixo. Caso seja necessária a geração de dois arquivos, deverão ser ajustados manualmente o nome desses arquivos.
* Devido as tratativas realizadas de validação de Alocação de Matriz e de Compatibilidade de Matrizes, tanto o arquivo `main_matriz.c` quando a biblioteca `matriz-operacoes.c` foram ajustados (em específicos os parâmetros a serem passados). Com isso, caso seja necessário a alteração do programa `main_matriz.c` é importante se atentar aos parâmetros e posições dos mesmos.

# EXEMPLO DE EXECUÇÃO
```
user@machine:~/Documentos/C/GitHub/c-matrix$ make
gcc -Wall -O3  -c matriz.c
gcc -Wall -O3  -c toolsv2.c
gcc -Wall -O3  -c matriz-operacoes.c
gcc -Wall -O3  matriz-operacoes.o matriz.o toolsv2.o main_matriz.c -o main_matriz 
gcc -Wall -O3  matriz.o toolsv2.o gera_matriz2.c -o gera_matriz2 
gcc -Wall -O3  matriz.o toolsv2.o simple_matriz.c -o simple_matriz 


####### Exemplo de Execução #######
./gera_matriz2 10 10
./main_matriz 10x10-mat-1.map 10x10-mat-2.map
user@machine:~/Documentos/C/GitHub/c-matrix$ ./gera_matriz2 10 10
		**** PRINT mat_c NxM(10,10) **** 
##### Arquivo 10x10-mat.map: VERIFICADO! #####
user@machine:~/Documentos/C/GitHub/c-matrix$ ./main_matriz 10x10-mat-1.map  10x10-mat-2.map 9
		**** Loaded mat_a NxL(10,10) **** 
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	60	93	50	90	88	46	99	78	99	37
(1)	73	84	26	46	61	74	69	58	70	0
(2)	17	22	35	16	64	87	4	73	91	86
(3)	18	52	31	68	94	19	66	46	98	66
(4)	35	23	2	61	21	63	88	90	73	58
(5)	90	42	32	77	58	49	65	14	22	8
(6)	0	92	60	32	61	7	3	27	53	53
(7)	45	88	28	47	2	49	63	42	39	36
(8)	0	82	79	85	11	37	34	28	52	8
(9)	37	4	1	49	88	62	56	92	41	9
		**** Loaded mat_b LxM(10,10) **** 
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	60	93	50	90	88	46	99	78	99	37
(1)	73	84	26	46	61	74	69	58	70	0
(2)	17	22	35	16	64	87	4	73	91	86
(3)	18	52	31	68	94	19	66	46	98	66
(4)	35	23	2	61	21	63	88	90	73	58
(5)	90	42	32	77	58	49	65	14	22	8
(6)	0	92	60	32	61	7	3	27	53	53
(7)	45	88	28	47	2	49	63	42	39	36
(8)	0	82	79	85	11	37	34	28	52	8
(9)	37	4	1	49	88	62	56	92	41	9
		**** Loaded mat_c NxM(10,10) **** 
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

 ##### Soma de Matrizes (IJ) #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	120	186	100	180	176	92	198	156	198	74
(1)	146	168	52	92	122	148	138	116	140	0
(2)	34	44	70	32	128	174	8	146	182	172
(3)	36	104	62	136	188	38	132	92	196	132
(4)	70	46	4	122	42	126	176	180	146	116
(5)	180	84	64	154	116	98	130	28	44	16
(6)	0	184	120	64	122	14	6	54	106	106
(7)	90	176	56	94	4	98	126	84	78	72
(8)	0	164	158	170	22	74	68	56	104	16
(9)	74	8	2	98	176	124	112	184	82	18
	Runtime Soma IJ: 0.000001

 ##### Soma de Matrizes (JI) #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	120	186	100	180	176	92	198	156	198	74
(1)	146	168	52	92	122	148	138	116	140	0
(2)	34	44	70	32	128	174	8	146	182	172
(3)	36	104	62	136	188	38	132	92	196	132
(4)	70	46	4	122	42	126	176	180	146	116
(5)	180	84	64	154	116	98	130	28	44	16
(6)	0	184	120	64	122	14	6	54	106	106
(7)	90	176	56	94	4	98	126	84	78	72
(8)	0	164	158	170	22	74	68	56	104	16
(9)	74	8	2	98	176	124	112	184	82	18
	Runtime Soma JI: 0.000002

 ##### Multiplicação de Matrizes (IJK)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	24958	47366	27588	42570	37669	33972	39880	38553	48210	27112
(1)	23187	38512	21954	34281	28204	26094	32582	27365	35621	18408
(2)	20046	24755	15614	30301	21931	26358	28205	26505	25879	13445
(3)	16139	31640	19297	32167	27212	25952	29613	31067	35281	19956
(4)	17512	33766	19992	30613	25895	20378	26693	23324	28502	16225
(5)	17762	29046	16821	28091	28767	20001	27580	24935	33083	19117
(6)	14253	19619	11006	20095	19631	23413	21003	24351	25784	12898
(7)	18148	29575	16620	24706	25946	20612	23279	21555	27474	13170
(8)	14130	24741	15678	21552	23831	21092	19039	20227	28802	16636
(9)	16544	27621	14852	27046	18457	18573	26813	21585	25681	16978
	Runtime Multiplicação IJK: 0.000007

 ##### Multiplicação de Matrizes (IKJ)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	24958	47366	27588	42570	37669	33972	39880	38553	48210	27112
(1)	23187	38512	21954	34281	28204	26094	32582	27365	35621	18408
(2)	20046	24755	15614	30301	21931	26358	28205	26505	25879	13445
(3)	16139	31640	19297	32167	27212	25952	29613	31067	35281	19956
(4)	17512	33766	19992	30613	25895	20378	26693	23324	28502	16225
(5)	17762	29046	16821	28091	28767	20001	27580	24935	33083	19117
(6)	14253	19619	11006	20095	19631	23413	21003	24351	25784	12898
(7)	18148	29575	16620	24706	25946	20612	23279	21555	27474	13170
(8)	14130	24741	15678	21552	23831	21092	19039	20227	28802	16636
(9)	16544	27621	14852	27046	18457	18573	26813	21585	25681	16978
	Runtime Multiplicação IKJ: 0.000009

 ##### Multiplicação de Matrizes (KIJ)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	24958	47366	27588	42570	37669	33972	39880	38553	48210	27112
(1)	23187	38512	21954	34281	28204	26094	32582	27365	35621	18408
(2)	20046	24755	15614	30301	21931	26358	28205	26505	25879	13445
(3)	16139	31640	19297	32167	27212	25952	29613	31067	35281	19956
(4)	17512	33766	19992	30613	25895	20378	26693	23324	28502	16225
(5)	17762	29046	16821	28091	28767	20001	27580	24935	33083	19117
(6)	14253	19619	11006	20095	19631	23413	21003	24351	25784	12898
(7)	18148	29575	16620	24706	25946	20612	23279	21555	27474	13170
(8)	14130	24741	15678	21552	23831	21092	19039	20227	28802	16636
(9)	16544	27621	14852	27046	18457	18573	26813	21585	25681	16978
	Runtime Multiplicação KIJ: 0.000013

 ##### Multiplicação de Matrizes (KJI)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	24958	47366	27588	42570	37669	33972	39880	38553	48210	27112
(1)	23187	38512	21954	34281	28204	26094	32582	27365	35621	18408
(2)	20046	24755	15614	30301	21931	26358	28205	26505	25879	13445
(3)	16139	31640	19297	32167	27212	25952	29613	31067	35281	19956
(4)	17512	33766	19992	30613	25895	20378	26693	23324	28502	16225
(5)	17762	29046	16821	28091	28767	20001	27580	24935	33083	19117
(6)	14253	19619	11006	20095	19631	23413	21003	24351	25784	12898
(7)	18148	29575	16620	24706	25946	20612	23279	21555	27474	13170
(8)	14130	24741	15678	21552	23831	21092	19039	20227	28802	16636
(9)	16544	27621	14852	27046	18457	18573	26813	21585	25681	16978
	Runtime Multiplicação KJI: 0.000010

 ##### Multiplicação de Matrizes (JIK)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	24958	47366	27588	42570	37669	33972	39880	38553	48210	27112
(1)	23187	38512	21954	34281	28204	26094	32582	27365	35621	18408
(2)	20046	24755	15614	30301	21931	26358	28205	26505	25879	13445
(3)	16139	31640	19297	32167	27212	25952	29613	31067	35281	19956
(4)	17512	33766	19992	30613	25895	20378	26693	23324	28502	16225
(5)	17762	29046	16821	28091	28767	20001	27580	24935	33083	19117
(6)	14253	19619	11006	20095	19631	23413	21003	24351	25784	12898
(7)	18148	29575	16620	24706	25946	20612	23279	21555	27474	13170
(8)	14130	24741	15678	21552	23831	21092	19039	20227	28802	16636
(9)	16544	27621	14852	27046	18457	18573	26813	21585	25681	16978
	Runtime Multiplicação JIK: 0.000004

 ##### Multiplicação de Matrizes (JKI)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	24958	47366	27588	42570	37669	33972	39880	38553	48210	27112
(1)	23187	38512	21954	34281	28204	26094	32582	27365	35621	18408
(2)	20046	24755	15614	30301	21931	26358	28205	26505	25879	13445
(3)	16139	31640	19297	32167	27212	25952	29613	31067	35281	19956
(4)	17512	33766	19992	30613	25895	20378	26693	23324	28502	16225
(5)	17762	29046	16821	28091	28767	20001	27580	24935	33083	19117
(6)	14253	19619	11006	20095	19631	23413	21003	24351	25784	12898
(7)	18148	29575	16620	24706	25946	20612	23279	21555	27474	13170
(8)	14130	24741	15678	21552	23831	21092	19039	20227	28802	16636
(9)	16544	27621	14852	27046	18457	18573	26813	21585	25681	16978
	Runtime Multiplicação JKI: 0.000012
	==== SUMARIZAÇÃO ====
	Runtime Soma IJ: 0.000001
	Runtime Soma JI: 0.000002
	Runtime Multiplicação IJK: 0.000007
	Runtime Multiplicação IKJ: 0.000009
	Runtime Multiplicação KIJ: 0.000013
	Runtime Multiplicação KJI: 0.000010
	Runtime Multiplicação JIK: 0.000004
	Runtime Multiplicação JKI: 0.000012
```