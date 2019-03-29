#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int gerar_matriz(int **matriz, int linha, int coluna, int valor);
int zerar_matriz (int **matriz, int linha, int coluna);
int imprimir_matriz (int **matriz, int linha, int coluna);
int comparar_matriz (int **matriza, int **matrizb, int linha, int coluna);
int **liberar_matriz (int **matriz, int linha, int coluna);
int **alocar_matriz (int linha, int coluna);
int vldMatriz(int nLa, int nLb, int nN, int nM, int nOperation);
