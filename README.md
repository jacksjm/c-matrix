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
* Ao final da execução, será questiona se deseja visualizar a sumarização de resultados e comparação das matrizes.

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
(0)	83	53	49	17	54	45	38	8	22	87
(1)	12	95	92	16	78	15	31	1	2	5
(2)	98	83	58	56	62	91	29	5	45	55
(3)	59	80	61	60	49	15	5	39	24	27
(4)	26	88	22	70	4	52	86	88	6	88
(5)	45	4	71	3	12	85	46	93	43	43
(6)	49	2	75	10	62	24	25	19	63	1
(7)	98	42	41	72	12	46	76	98	86	82
(8)	38	31	38	61	86	3	99	85	96	42
(9)	28	97	96	56	7	10	80	85	81	96
		**** Loaded mat_b LxM(10,10) **** 
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	85	15	36	8	9	61	12	63	57	47
(1)	95	67	68	17	26	77	38	45	51	58
(2)	87	77	44	73	76	33	82	93	64	8
(3)	6	1	24	94	61	85	56	25	0	13
(4)	73	95	33	93	65	11	70	3	8	74
(5)	61	96	51	58	21	80	91	3	73	8
(6)	11	79	61	87	26	75	73	82	0	73
(7)	47	73	21	32	18	86	44	89	41	52
(8)	63	54	0	66	64	21	46	8	76	71
(9)	16	88	3	29	27	29	4	0	11	57

 ##### Soma de Matrizes (IJ) #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	168	68	85	25	63	106	50	71	79	134
(1)	107	162	160	33	104	92	69	46	53	63
(2)	185	160	102	129	138	124	111	98	109	63
(3)	65	81	85	154	110	100	61	64	24	40
(4)	99	183	55	163	69	63	156	91	14	162
(5)	106	100	122	61	33	165	137	96	116	51
(6)	60	81	136	97	88	99	98	101	63	74
(7)	145	115	62	104	30	132	120	187	127	134
(8)	101	85	38	127	150	24	145	93	172	113
(9)	44	185	99	85	34	39	84	85	92	153
	Runtime Soma IJ: 0.000002

 ##### Soma de Matrizes (JI) #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	168	68	85	25	63	106	50	71	79	134
(1)	107	162	160	33	104	92	69	46	53	63
(2)	185	160	102	129	138	124	111	98	109	63
(3)	65	81	85	154	110	100	61	64	24	40
(4)	99	183	55	163	69	63	156	91	14	162
(5)	106	100	122	61	33	165	137	96	116	51
(6)	60	81	136	97	88	99	98	101	63	74
(7)	145	115	62	104	30	132	120	187	127	134
(8)	101	85	38	127	150	24	145	93	172	113
(9)	44	185	99	85	34	39	84	85	92	153
	Runtime Soma JI: 0.000002

 ##### Multiplicação de Matrizes (IJK)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	26714	30466	15980	21909	16230	22923	20341	16897	17244	21655
(1)	25348	25565	16590	21061	17018	17099	21438	16913	13384	15652
(2)	35943	36105	21794	29985	22014	32150	29470	20345	24900	24635
(3)	26606	24011	15275	21402	17504	23627	20198	18755	16554	18063
(4)	23236	34708	19710	26524	16396	35938	25170	24494	16238	24420
(5)	24735	32242	14707	23002	15436	26181	24857	22377	21168	18220
(6)	22083	21700	10637	20969	16388	13931	19461	14905	15521	15272
(7)	32173	38087	19598	32845	22686	38809	29336	29493	25262	30986
(8)	28112	36998	17553	36398	24792	30299	30010	25566	18329	31926
(9)	32918	41339	20866	33186	25537	35777	30120	31281	24170	30519
	Runtime Multiplicação IJK: 0.000007

 ##### Multiplicação de Matrizes (IKJ)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	26714	30466	15980	21909	16230	22923	20341	16897	17244	21655
(1)	25348	25565	16590	21061	17018	17099	21438	16913	13384	15652
(2)	35943	36105	21794	29985	22014	32150	29470	20345	24900	24635
(3)	26606	24011	15275	21402	17504	23627	20198	18755	16554	18063
(4)	23236	34708	19710	26524	16396	35938	25170	24494	16238	24420
(5)	24735	32242	14707	23002	15436	26181	24857	22377	21168	18220
(6)	22083	21700	10637	20969	16388	13931	19461	14905	15521	15272
(7)	32173	38087	19598	32845	22686	38809	29336	29493	25262	30986
(8)	28112	36998	17553	36398	24792	30299	30010	25566	18329	31926
(9)	32918	41339	20866	33186	25537	35777	30120	31281	24170	30519
	Runtime Multiplicação IKJ: 0.000013

 ##### Multiplicação de Matrizes (KIJ)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	26714	30466	15980	21909	16230	22923	20341	16897	17244	21655
(1)	25348	25565	16590	21061	17018	17099	21438	16913	13384	15652
(2)	35943	36105	21794	29985	22014	32150	29470	20345	24900	24635
(3)	26606	24011	15275	21402	17504	23627	20198	18755	16554	18063
(4)	23236	34708	19710	26524	16396	35938	25170	24494	16238	24420
(5)	24735	32242	14707	23002	15436	26181	24857	22377	21168	18220
(6)	22083	21700	10637	20969	16388	13931	19461	14905	15521	15272
(7)	32173	38087	19598	32845	22686	38809	29336	29493	25262	30986
(8)	28112	36998	17553	36398	24792	30299	30010	25566	18329	31926
(9)	32918	41339	20866	33186	25537	35777	30120	31281	24170	30519
	Runtime Multiplicação KIJ: 0.000013

 ##### Multiplicação de Matrizes (KJI)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	26714	30466	15980	21909	16230	22923	20341	16897	17244	21655
(1)	25348	25565	16590	21061	17018	17099	21438	16913	13384	15652
(2)	35943	36105	21794	29985	22014	32150	29470	20345	24900	24635
(3)	26606	24011	15275	21402	17504	23627	20198	18755	16554	18063
(4)	23236	34708	19710	26524	16396	35938	25170	24494	16238	24420
(5)	24735	32242	14707	23002	15436	26181	24857	22377	21168	18220
(6)	22083	21700	10637	20969	16388	13931	19461	14905	15521	15272
(7)	32173	38087	19598	32845	22686	38809	29336	29493	25262	30986
(8)	28112	36998	17553	36398	24792	30299	30010	25566	18329	31926
(9)	32918	41339	20866	33186	25537	35777	30120	31281	24170	30519
	Runtime Multiplicação KJI: 0.000013

 ##### Multiplicação de Matrizes (JIK)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	26714	30466	15980	21909	16230	22923	20341	16897	17244	21655
(1)	25348	25565	16590	21061	17018	17099	21438	16913	13384	15652
(2)	35943	36105	21794	29985	22014	32150	29470	20345	24900	24635
(3)	26606	24011	15275	21402	17504	23627	20198	18755	16554	18063
(4)	23236	34708	19710	26524	16396	35938	25170	24494	16238	24420
(5)	24735	32242	14707	23002	15436	26181	24857	22377	21168	18220
(6)	22083	21700	10637	20969	16388	13931	19461	14905	15521	15272
(7)	32173	38087	19598	32845	22686	38809	29336	29493	25262	30986
(8)	28112	36998	17553	36398	24792	30299	30010	25566	18329	31926
(9)	32918	41339	20866	33186	25537	35777	30120	31281	24170	30519
	Runtime Multiplicação JIK: 0.000007

 ##### Multiplicação de Matrizes (JKI)  #####
	(0)	(1)	(2)	(3)	(4)	(5)	(6)	(7)	(8)	(9)
(0)	26714	30466	15980	21909	16230	22923	20341	16897	17244	21655
(1)	25348	25565	16590	21061	17018	17099	21438	16913	13384	15652
(2)	35943	36105	21794	29985	22014	32150	29470	20345	24900	24635
(3)	26606	24011	15275	21402	17504	23627	20198	18755	16554	18063
(4)	23236	34708	19710	26524	16396	35938	25170	24494	16238	24420
(5)	24735	32242	14707	23002	15436	26181	24857	22377	21168	18220
(6)	22083	21700	10637	20969	16388	13931	19461	14905	15521	15272
(7)	32173	38087	19598	32845	22686	38809	29336	29493	25262	30986
(8)	28112	36998	17553	36398	24792	30299	30010	25566	18329	31926
(9)	32918	41339	20866	33186	25537	35777	30120	31281	24170	30519
	Runtime Multiplicação JKI: 0.000007


	==== SUMARIZAÇÃO ====


	Runtime Soma IJ: 0.000002
	Runtime Soma JI: 0.000002
VERIFICADO: Matrizes identicas
Runtime: 0.000000


	Runtime Multiplicação IJK: 0.000007
	Runtime Multiplicação IKJ: 0.000013
	Runtime Multiplicação KIJ: 0.000013
	Runtime Multiplicação KJI: 0.000013
	Runtime Multiplicação JIK: 0.000007
	Runtime Multiplicação JKI: 0.000007


	Comparações IJK: 
	Comparações IKJ: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000
	Comparações KIJ: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000
	Comparações KJI: 
VERIFICADO: Matrizes identicas
Runtime: 0.000001
	Comparações JIK: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000
	Comparações JKI: 
VERIFICADO: Matrizes identicas
Runtime: 0.000001


	Comparações IKJ: 
	Comparações KIJ: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000
	Comparações KJI: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000
	Comparações JIK: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000
	Comparações JKI: 
VERIFICADO: Matrizes identicas
Runtime: 0.000001


	Comparações KIJ: 
	Comparações KJI: 
VERIFICADO: Matrizes identicas
Runtime: 0.000001
	Comparações JIK: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000
	Comparações JKI: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000


	Comparações KJI: 
	Comparações JIK: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000
	Comparações JKI: 
VERIFICADO: Matrizes identicas
Runtime: 0.000001


	Comparações JIK: 
	Comparações JKI: 
VERIFICADO: Matrizes identicas
Runtime: 0.000000
```