#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toolsv2.h"
#include "matriz.h"
#include "matriz-operacoes.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main(int argc, char *argv[]) {

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	// DECLARAÇÃO de VARIÁVEIS
	int **mat_a = NULL;
	int **mat_b = NULL;
	int **mat_c = NULL;
	float nSumIJ = 0.0, nSumJI = 0.0;
	float nRunIJK = 0.0, nRunIKJ = 0.0;
	float nRunJIK = 0.0, nRunJKI = 0.0;
	float nRunKJI = 0.0, nRunKIJ = 0.0;
	FILE *fmat_a, *fmat_b;
	//FILE *fmat_c, *fmatbloco_c;
	int nr_line;
	int *vet_line = NULL;
	int N, M, La, Lb;
	double start_time, end_time;
	int lSoma = 1;
	int nOperation = 0;
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	if (argc != 4){
		printf ("ERRO: Numero de parametros %s <matriz_a> <matriz_b> <operation>\n", argv[0]);
		exit (1);
	}
	
  // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	fmat_a = fopen(argv[1],"r");
	fmat_b = fopen(argv[2],"r");
	if ((fmat_a == NULL) || (fmat_b == NULL)) {
		printf("Error: Na abertura dos arquivos.");
		exit(1);
	}
	nOperation = atoi(argv[3]);
	if (nOperation < 1 || nOperation > 11) {
		printf("Operação Inválida.");
		exit(1);
	}
    // matriz_a N (linha) x La (coluna)
	extrai_parametros_matriz(fmat_a, &N, &La, &vet_line, &nr_line);
	mat_a = alocar_matriz(N, La);
	filein_matriz (mat_a, N, La, fmat_a, vet_line, nr_line);

	// matriz_b Lb (linha) x M (coluna)
	extrai_parametros_matriz(fmat_b, &Lb, &M, &vet_line, &nr_line);
	mat_b = alocar_matriz(Lb, M);
	filein_matriz (mat_b, Lb, M, fmat_b, vet_line, nr_line);

	// matriz_c (resultante) = N (linha) x M(coluna)
	mat_c = alocar_matriz(N, M);
	zerar_matriz(mat_c, N, M);
	
	if ((mat_c == NULL) || (mat_b == NULL) || (mat_a == NULL)) {
		printf("ERROR: Out of memory\n");
	}

	// Restricao da operacao de soma de matrizes
	// Numero de linha de matriz_a deve ser o mesmo de colunas da matriz_b
	if (La != Lb && nOperation >= 3 && nOperation <= 10){
		printf("ERROR: Matriz A vs Matriz B incompatíveis.\n");
		exit (1);
	}else if( (N != M || N != La || M != Lb) && ( nOperation == 2 || nOperation == 1 || nOperation == 9 || nOperation == 11) ) {
		printf("ERROR: Matriz A vs Matriz B incompatíveis para Soma.\nOperação de Soma não será realizada.\n");
		lSoma = 0;
		exit (1);
	}
	
	printf("\t\t**** Loaded mat_a NxL(%d,%d) **** \n", N, La);
	imprimir_matriz(mat_a, N, La);
	printf("\t\t**** Loaded mat_b LxM(%d,%d) **** \n", Lb, M);
	imprimir_matriz(mat_b, Lb, N);
	printf("\t\t**** Loaded mat_c NxM(%d,%d) **** \n", N, M);
	imprimir_matriz(mat_c, N, M);
	
	if (lSoma == 1){
		if (nOperation == 1 || nOperation == 9){
			start_time = wtime();
			somarIJ(mat_a,mat_b,mat_c,N,La,M,Lb);
			end_time = wtime();
			printf("\n ##### Soma de Matrizes (IJ) #####\n");
			imprimir_matriz(mat_c, N, M);
			nSumIJ = end_time - start_time;
			printf("\tRuntime Soma IJ: %f\n", nSumIJ);
		}

		if (nOperation == 2 || nOperation == 9){
			start_time = wtime();
			somarJI(mat_a,mat_b,mat_c,N,La,M,Lb);
			end_time = wtime();
			printf("\n ##### Soma de Matrizes (JI) #####\n");
			imprimir_matriz(mat_c, N, M);
			nSumJI = end_time - start_time;
			printf("\tRuntime Soma JI: %f\n", nSumJI);
		}
	}
	if (nOperation == 3 || nOperation == 9){
		start_time = wtime();
		multiplicarIJK(mat_a,mat_b,mat_c, N, La, M, Lb);
		end_time = wtime();
		printf("\n ##### Multiplicação de Matrizes (IJK)  #####\n");
		imprimir_matriz(mat_c, N, M);
		nRunIJK = end_time - start_time;
		printf("\tRuntime Multiplicação IJK: %f\n", nRunIJK);
	} 
	if (nOperation == 4 || nOperation == 9){
		start_time = wtime();
		zerar_matriz(mat_c, N, M);
		multiplicarIKJ(mat_a,mat_b,mat_c, N, La, M, Lb);
		end_time = wtime();
		printf("\n ##### Multiplicação de Matrizes (IKJ)  #####\n");
		imprimir_matriz(mat_c, N, M);
		nRunIKJ = end_time - start_time;
		printf("\tRuntime Multiplicação IKJ: %f\n", nRunIKJ);
	} 
	if (nOperation == 5 || nOperation == 9){
		start_time = wtime();
		zerar_matriz(mat_c, N, M);
		multiplicarKIJ(mat_a,mat_b,mat_c, N, La, M, Lb);
		end_time = wtime();
		printf("\n ##### Multiplicação de Matrizes (KIJ)  #####\n");
		imprimir_matriz(mat_c, N, M);
		nRunKIJ = end_time - start_time;
		printf("\tRuntime Multiplicação KIJ: %f\n", nRunKIJ);
	}
	if (nOperation == 6 || nOperation == 9){
		start_time = wtime();
		zerar_matriz(mat_c, N, M);
		multiplicarKJI(mat_a,mat_b,mat_c, N, La, M, Lb);
		end_time = wtime();
		printf("\n ##### Multiplicação de Matrizes (KJI)  #####\n");
		imprimir_matriz(mat_c, N, M);
		nRunKJI = end_time - start_time;
		printf("\tRuntime Multiplicação KJI: %f\n", nRunKJI);
	}
	if (nOperation == 7 || nOperation == 9){
		start_time = wtime();
		multiplicarJIK(mat_a,mat_b,mat_c, N, La, M, Lb);
		end_time = wtime();
		printf("\n ##### Multiplicação de Matrizes (JIK)  #####\n");
		imprimir_matriz(mat_c, N, M);
		nRunJIK = end_time - start_time;
		printf("\tRuntime Multiplicação JIK: %f\n", nRunJIK);
	}
	if (nOperation == 8 || nOperation == 9){
		start_time = wtime();
		zerar_matriz(mat_c, N, M);
		multiplicarJKI(mat_a,mat_b,mat_c, N, La, M, Lb);
		end_time = wtime();
		printf("\n ##### Multiplicação de Matrizes (JKI)  #####\n");
		imprimir_matriz(mat_c, N, M);
		nRunJKI = end_time - start_time;
		printf("\tRuntime Multiplicação JKI: %f\n", nRunJKI);
	}
	// Imprime tempos de execução - Sumarização
	if ( nOperation == 9){
		printf("\t==== SUMARIZAÇÃO ====\n");
		printf("\tRuntime Soma IJ: %f\n", nSumIJ);
		printf("\tRuntime Soma JI: %f\n", nSumJI);

		printf("\tRuntime Multiplicação IJK: %f\n", nRunIJK);
		printf("\tRuntime Multiplicação IKJ: %f\n", nRunIKJ);
		printf("\tRuntime Multiplicação KIJ: %f\n", nRunKIJ);
		printf("\tRuntime Multiplicação KJI: %f\n", nRunKJI);
		printf("\tRuntime Multiplicação JIK: %f\n", nRunJIK);
		printf("\tRuntime Multiplicação JKI: %f\n", nRunJKI);
	}
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	liberar_matriz(mat_a,N,La);
	liberar_matriz(mat_b,Lb,M);
	liberar_matriz(mat_c,N,M);

	fclose(fmat_a);
	fclose(fmat_b);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	return 0;
}
