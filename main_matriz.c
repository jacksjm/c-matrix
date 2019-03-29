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
	//int **mat_c1 = NULL;
	//int **mat_c2 = NULL;
	//int **mat_final = NULL;
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
	// matriz_bloco_t **vet_submat_a = NULL;
	// matriz_bloco_t **vet_submat_b = NULL;
	// matriz_bloco_t **vet_submat_c1 = NULL;
	// matriz_bloco_t **vet_submat_c2 = NULL;
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	if (argc != 3){
		printf ("ERRO: Numero de parametros %s <matriz_a> <matriz_b>\n", argv[0]);
		exit (1);
	}
	
  // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	fmat_a = fopen(argv[1],"r");
	fmat_b = fopen(argv[2],"r");
  if ((fmat_a == NULL) || (fmat_b == NULL)) {
		printf("Error: Na abertura dos arquivos.");
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
	/*if (La != Lb){
		printf("ERROR: Matriz A vs Matriz B incompatíveis.\n");
		exit (1);
	}else if(N != M || N != La || M != Lb) {
		printf("ERROR: Matriz A vs Matriz B incompatíveis para Soma.\nOperação de Soma não será realizada.\n");
		lSoma = 0;
	}*/
	
	printf("\t\t**** Loaded mat_a NxL(%d,%d) **** \n", N, La);
	imprimir_matriz(mat_a, N, La);
	printf("\t\t**** Loaded mat_b LxM(%d,%d) **** \n", Lb, M);
	imprimir_matriz(mat_b, Lb, N);
	printf("\t\t**** Loaded mat_c NxM(%d,%d) **** \n", N, M);
	imprimir_matriz(mat_c, N, M);
	
	if (lSoma == 1){
		zerar_matriz(mat_c, N, M);
		start_time = wtime();
		somarIJ(mat_a,mat_b,mat_c,N,La,M,Lb);
		end_time = wtime();
		printf("\n ##### Soma de Matrizes (IJ) #####\n");
		imprimir_matriz(mat_c, N, M);
		nSumIJ = end_time - start_time;

		zerar_matriz(mat_c, N, M);
		start_time = wtime();
		somarJI(mat_a,mat_b,mat_c,N,La,M,Lb);
		end_time = wtime();
		printf("\n ##### Soma de Matrizes (JI) #####\n");
		imprimir_matriz(mat_c, N, M);
		nSumJI = end_time - start_time;
	}
	
	zerar_matriz(mat_c, N, M);
	start_time = wtime();
	multiplicarIJK(mat_a,mat_b,mat_c, N, La, M);
	end_time = wtime();
	printf("\n ##### Multiplicação de Matrizes (IJK)  #####\n");
	imprimir_matriz(mat_c, N, M);
	nRunIJK = end_time - start_time;

	zerar_matriz(mat_c, N, M);
	start_time = wtime();
	multiplicarIKJ(mat_a,mat_b,mat_c, N, La, M);
	end_time = wtime();
	printf("\n ##### Multiplicação de Matrizes (IKJ)  #####\n");
	imprimir_matriz(mat_c, N, M);
	nRunIKJ = end_time - start_time;

	zerar_matriz(mat_c, N, M);
	start_time = wtime();
	multiplicarKIJ(mat_a,mat_b,mat_c, N, La, M);
	end_time = wtime();
	printf("\n ##### Multiplicação de Matrizes (KIJ)  #####\n");
	imprimir_matriz(mat_c, N, M);
	nRunKIJ = end_time - start_time;

	zerar_matriz(mat_c, N, M);
	start_time = wtime();
	multiplicarKJI(mat_a,mat_b,mat_c, N, La, M);
	end_time = wtime();
	printf("\n ##### Multiplicação de Matrizes (KJI)  #####\n");
	imprimir_matriz(mat_c, N, M);
	nRunKJI = end_time - start_time;

	zerar_matriz(mat_c, N, M);
	start_time = wtime();
	multiplicarJIK(mat_a,mat_b,mat_c, N, La, M);
	end_time = wtime();
	printf("\n ##### Multiplicação de Matrizes (JIK)  #####\n");
	imprimir_matriz(mat_c, N, M);
	nRunJIK = end_time - start_time;

	zerar_matriz(mat_c, N, M);
	start_time = wtime();
	multiplicarJKI(mat_a,mat_b,mat_c, N, La, M);
	end_time = wtime();
	printf("\n ##### Multiplicação de Matrizes (JKI)  #####\n");
	imprimir_matriz(mat_c, N, M);
	nRunJKI = end_time - start_time;

	// Imprime tempos de execução
	printf("\tRuntime Soma IJ: %f\n", nSumIJ);
	printf("\tRuntime Soma JI: %f\n", nSumJI);

	printf("\tRuntime Multiplicação IJK: %f\n", nRunIJK);
	printf("\tRuntime Multiplicação IKJ: %f\n", nRunIKJ);
	printf("\tRuntime Multiplicação KIJ: %f\n", nRunKIJ);
	printf("\tRuntime Multiplicação KJI: %f\n", nRunKJI);
	printf("\tRuntime Multiplicação JIK: %f\n", nRunJIK);
	printf("\tRuntime Multiplicação JKI: %f\n", nRunJKI);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  // Multiplicação IJK
//	zerar_matriz(mat_c, N, M);
//	start_time = wtime();
//	multiplicarIJK(mat_a,mat_b,mat_c, N, La, M);
//	end_time = wtime();
//	printf("\n ##### Multiplicação de Matrizes (IJK) #####\n");
//	printf("\tRuntime: %f\n", end_time - start_time);
//	fmat_c= fopen("outIJK.map-result","w");
//	printf("\n **** Matriz C	 resultante! **** \n");
//	imprimir_matriz(mat_c, N, M);
//	fileout_matriz(mat_c, N, M, fmat_c);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%


	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  // Multiplicação em Bloco
 // printf(" ##### Multiplicação de Matrizes (bloco) #####\n");
	// start_time = wtime();

	// printf("\n\n**** Matriz A (%p) completa ****\n",mat_a);
	// imprimir_matriz(mat_a, N, La);
	// vet_submat_a = particionar_matriz (mat_a, N, La, 1);
	// imprimir_bloco (vet_submat_a[0]);
	// imprimir_submatriz (vet_submat_a[0]);
	// imprimir_submatriz (vet_submat_a[1]);

	// printf("\n\n**** Matriz B (%p) completa ****\n",mat_b);
	// imprimir_matriz(mat_b, Lb, M);
	// vet_submat_b = particionar_matriz (mat_b, Lb, M, 0);
	// imprimir_bloco (vet_submat_b[0]);
	// imprimir_submatriz (vet_submat_b[0]);
	// imprimir_submatriz (vet_submat_b[1]);

	// mat_c1 = alocar_matriz(N, M);
	// zerar_matriz(mat_c1, N, M);
	// vet_submat_c1 = constroi_submatriz (mat_c1, N, M, 1);

	// mat_c2 = alocar_matriz(N, M);
	// zerar_matriz(mat_c2, N, M);
	// vet_submat_c2 = constroi_submatriz (mat_c2, N, M, 1);

	// mat_final = alocar_matriz(N, M);
	// zerar_matriz(mat_final, N, M);

	// multiplicar_submatriz (vet_submat_a[0], vet_submat_b[0], vet_submat_c1[0]);
	// imprimir_matriz(mat_c1, N, M);
	// multiplicar_submatriz (vet_submat_a[1], vet_submat_b[1], vet_submat_c2[0]);
	// imprimir_matriz(mat_c2, N, M);
	//somarIJ(mat_c1,mat_c2,mat_final, N, N, N);
	// end_time = wtime();

	// printf("\tRuntime: %f\n\n", end_time - start_time);
	// fmatbloco_c = fopen("outBloco.map-result","w");
	// fileout_matriz(mat_final, N, M, fmatbloco_c);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%


	//comparar_matriz (mat_a, mat_b, N, M);
	//comparar_matriz (mat_a, mat_a, N, M);
	//printf("Resultados individuais encontram-se nos arquivos <out*.map-result>.\n");

  // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	// LIBERAR MEMÓRIA
	// vet_submat_a = liberar_submatriz (vet_submat_a);
	// vet_submat_b = liberar_submatriz (vet_submat_b);
	// vet_submat_c1= liberar_submatriz (vet_submat_c1);
	// vet_submat_c2= liberar_submatriz (vet_submat_c2);

	liberar_matriz(mat_a,N,La);
	liberar_matriz(mat_b,Lb,M);
	liberar_matriz(mat_c,N,M);

	fclose(fmat_a);
	fclose(fmat_b);
//	fclose(fmat_c);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	return 0;
}
