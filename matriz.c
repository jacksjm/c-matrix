#include "matriz.h"
#include "toolsv2.h"

/*
function gerar_matriz
Gera valores dentro de uma Matriz já alocada

@return int, Sempre 0

@param **aMatriz, pointer, Ponteiro que representa a Matriz
@param nLinha, int, Numero de Linhas da Matriz
@param nColuna, int, Numero de Colunas da Matriz
@param nValor, int, Indica o valor a ser gerado: 
						-9999 	- Aleatório
						-8888 	- Valores crescentes
						-7777 	- Valores decrescentes
						0 		- Valores zerados
*/
int gerar_matriz(int **aMatriz, int nLinha, int nColuna, int nValor){
	
	int nInput = 0;// Controlador de valor

	srand(time(NULL));
	
	if ( aMatriz == NULL ){
		printf("==== Matriz não alocada ====\n");
		exit(1);
	}
	// Percorre todas as Linhas da Matriz
	for (int nCntLin=0; nCntLin < nLinha; nCntLin++) {
		// Percorre todas as Colunas da Matriz
		for (int nCntCol=0; nCntCol < nColuna; nCntCol++) {

			// Verifica o valor passado por parâmetro
			switch (nValor)
			{
				case -9999: // Aleatoriza um valor de 0 a 100
					nInput = rand() % 100;
					break;
				case -8888: // Atribui o valor da linha
					nInput = nCntLin;
					break;
				case -7777: // Atribui um valor decrescente a linha
					nInput = nLinha - nCntLin;
					break;
				case 0: // Zera os valores
					nInput = 0;
					break;
				default:// Define como valor padrão o passado no parâmetro
					nInput = nValor;
					break;
			}
			// Atribui o valor a posição da Matriz
			aMatriz[nCntLin][nCntCol] = nInput;
		}
	}
	return 0;
}

/*
function zerar_matriz
Gera valores zerados em uma Matriz já alocada

@return int, Sempre 0

@param **aMatriz, pointer, Ponteiro que representa a Matriz
@param nLinha, int, Numero de Linhas da Matriz
@param nColuna, int, Numero de Colunas da Matriz
*/
int zerar_matriz (int **aMatriz, int nLinha, int nColuna){
	if ( aMatriz == NULL ){
		printf("==== Matriz não alocada ====\n");
		exit(1);
	}
	// Chama a geração Zerando os valores
	return gerar_matriz(aMatriz,nLinha,nColuna,0);
}

/*
function imprimir_matriz
Imprime os valores da Matriz

@return int, Sempre 0

@param **aMatriz, pointer, Ponteiro que representa a Matriz
@param nLinha, int, Numero de Linhas da Matriz
@param nColuna, int, Numero de Colunas da Matriz
*/
int imprimir_matriz (int **aMatriz, int nLinha, int nColuna){

	if ( aMatriz == NULL ){
		printf("==== Matriz não alocada ====\n");
		exit(1);
	}

	// Realiza uma impressão de primeira linha com posição das colunas
	for (int nCntCol=0; nCntCol < nColuna; nCntCol++)
		printf("\t(%d)", nCntCol);

	// Pula linha
	printf("\n");

	// Percorre as linhas da Matriz
	for (int nCntLin=0; nCntLin < nLinha; nCntLin++) {
		// Imprime no começo da linha a posição
		printf("(%d)", nCntLin);
		// Percorre as colunas da Matriz
	  	for (int nCntCol=0; nCntCol < nColuna; nCntCol++){
			// Imprime os valores contidos na Matriz
			printf("\t%d", aMatriz[nCntLin][nCntCol]);
		}
		printf("\n");
	}
	return 0;
}

/*
function comparar_matriz
Realiza a comparação de duas Matrizes

@return int, Sempre 0

@param **aMatrizA, pointer, Ponteiro que representa a Matriz A
@param **aMatrizB, pointer, Ponteiro que representa a Matriz B
@param nLinha, int, Numero de Linhas da Matriz
@param nColuna, int, Numero de Colunas da Matriz
*/
int comparar_matriz (int **aMatrizA, int **aMatrizB, int nLinha, int nColuna){
	double nStartTime, nEndTime;

	if ( aMatrizA == NULL ){
		printf("==== Matriz A não alocada ====\n");
		exit(1);
	}

	if ( aMatrizB == NULL ){
		printf("==== Matriz B não alocada ====\n");
		exit(1);
	}

	nStartTime = wtime();
	for (int nCntLin=0; nCntLin < nLinha; nCntLin++) {
	  for (int nCntCol=0; nCntCol < nColuna; nCntCol++){
			if (aMatrizA[nCntLin][nCntCol] != aMatrizB[nCntLin][nCntCol]) {
				printf("O elemento [%d,%d] é diferente nas matrizes analisadas!\n", nCntLin,nCntCol);
				return 1;
			}
		}

	}
	nEndTime = wtime();
	printf("VERIFICADO: Matrizes identicas\n");
	printf("Runtime: %f\n", nEndTime - nStartTime);
	return 0;
}

/*
function liberar_matriz
Imprime os valores da Matriz

@return int, Sempre nulo

@param **aMatriz, pointer, Ponteiro que representa a Matriz
@param nLinha, int, Numero de Linhas da Matriz
@param nColuna, int, Numero de Colunas da Matriz
*/
int **liberar_matriz (int **aMatriz, int nLinha, int nColuna) {
	
	// Libera as posições de cada Linha
	for (int i =0; i < nLinha; i++)
		free(aMatriz[i]);
	
	// Libera a Matriz completa
	free(aMatriz);
	return NULL;
}

/*
function alocar_matriz
Realiza a alocação dos espaços de Memória

@return pointer, Ponteiro (Matriz) alocado

@param nLinha, int, Numero de Linhas da Matriz
@param nColuna, int, Numero de Colunas da Matriz
*/
int **alocar_matriz (int nLinha, int nColuna) {
    int **aNovaMatriz = NULL;

	aNovaMatriz = (int **) malloc(nLinha * sizeof(int *));
	if (!aNovaMatriz) {
		printf("ERROR: Out of memory\n");
		return NULL;
	}

  	for (int i =0; i < nLinha; i++) {
			aNovaMatriz[i] = (int *) malloc(sizeof(int)*nColuna);
			if (!aNovaMatriz) {
				printf("ERROR: Out of memory\n");
				return NULL;
			}
	}
	return aNovaMatriz;
}