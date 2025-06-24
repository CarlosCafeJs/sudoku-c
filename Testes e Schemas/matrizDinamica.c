#include <stdio.h>
#include <stdlib.h>

#define LIN 9
#define COL 9

int main()
{

  int **mat;
  int i, j;

  mat = malloc(LIN * sizeof(int *));

  for (i = 0; i < LIN; i++)
    mat[i] = malloc(COL * sizeof(int));

  for (i = 0; i < LIN; i++)
    for (j = 0; j < COL; j++)
      mat[i][j] = 0;

  for (i = 0; i < LIN; i++)
    free(mat[i]);
  free(mat);
}
