	#include "matriz-operacoes.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MATRIZ %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int somarIJ (int **mat_a, int **mat_b, int **mat_c, int N, int La, int M, int Lb) {
  if (vldMatriz(La,Lb,N,M,2)){
    // Percorre todas as Linhas da Matriz
    for (int nCntLin=0; nCntLin < N; nCntLin++)
      // Percorre todas as Colunas da Matriz
      for (int nCntCol=0; nCntCol < M; nCntCol++)
        mat_c[nCntLin][nCntCol] = mat_a[nCntLin][nCntCol] + mat_b[nCntLin][nCntCol];
  }else{
    exit(1);
  }
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int somarJI (int **mat_a, int **mat_b, int **mat_c, int N, int La, int M, int Lb) {
  if (vldMatriz(La,Lb,N,M,2)){
    // Percorre todas as Colunas da Matriz
    for (int nCntCol=0; nCntCol < N; nCntCol++)
      // Percorre todas as Linhas da Matriz
      for (int nCntLin=0; nCntLin < M; nCntLin++)
        mat_c[nCntCol][nCntLin] = mat_a[nCntCol][nCntLin] + mat_b[nCntCol][nCntLin];
  }else{
    exit(1);
  }
  return 0;
}
/*
I - Coluna de A (4)
J - Linha de A x Coluna de B (3x3)
K - Linha de B (4)
*/

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarIJK (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
  for (int nCntCA=0; nCntCA < N; nCntCA++ )
    for (int nCntLB=0; nCntLB < M; nCntLB++ )
      for (int nCntLA=0; nCntLA < L; nCntLA++ )
        mat_c[nCntCA][nCntLB] += mat_a[nCntCA][nCntLA] * mat_b[nCntLA][nCntLB];
	
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarIKJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
  for (int nCntCA=0; nCntCA < N; nCntCA++ )
    for (int nCntLA=0; nCntLA < L; nCntLA++ )
      for (int nCntLB=0; nCntLB < M; nCntLB++ )
        mat_c[nCntCA][nCntLB] += mat_a[nCntCA][nCntLA] * mat_b[nCntLA][nCntLB];
	
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarKIJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
  for (int nCntLA=0; nCntLA < L; nCntLA++ )
    for (int nCntCA=0; nCntCA < N; nCntCA++ )
      for (int nCntLB=0; nCntLB < M; nCntLB++ )
        mat_c[nCntCA][nCntLB] += mat_a[nCntCA][nCntLA] * mat_b[nCntLA][nCntLB];
  
  return 0;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarKJI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
  for (int nCntLA=0; nCntLA < L; nCntLA++ )
    for (int nCntLB=0; nCntLB < M; nCntLB++ )
      for (int nCntCA=0; nCntCA < N; nCntCA++ )
        mat_c[nCntCA][nCntLB] += mat_a[nCntCA][nCntLA] * mat_b[nCntLA][nCntLB];
  
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarJIK (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
   for (int nCntLB=0; nCntLB < M; nCntLB++ )
    for (int nCntCA=0; nCntCA < N; nCntCA++ )
      for (int nCntLA=0; nCntLA < L; nCntLA++ )
        mat_c[nCntCA][nCntLB] += mat_a[nCntCA][nCntLA] * mat_b[nCntLA][nCntLB];
  
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarJKI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
  for (int nCntLB=0; nCntLB < M; nCntLB++ )
    for (int nCntLA=0; nCntLA < L; nCntLA++ )
      for (int nCntCA=0; nCntCA < N; nCntCA++ )
        mat_c[nCntCA][nCntLB] += mat_a[nCntCA][nCntLA] * mat_b[nCntLA][nCntLB];
  
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicar_submatriz (matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc) {
  //TODO
	return 0;
}
