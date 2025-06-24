#include <stdio.h>

int main()
{
  int matriz[9][9] = {
      {1, 1, 1, 2, 2, 2, 3, 3, 3},
      {1, 1, 1, 2, 2, 2, 3, 3, 3},
      {1, 1, 1, 2, 2, 2, 3, 3, 3},
      {4, 4, 4, 5, 5, 5, 6, 6, 6},
      {4, 4, 4, 5, 5, 5, 6, 6, 6},
      {4, 4, 4, 5, 5, 5, 6, 6, 6},
      {7, 7, 7, 8, 8, 8, 9, 9, 9},
      {7, 7, 7, 8, 8, 8, 9, 9, 9},
      {7, 7, 7, 8, 8, 8, 9, 9, 9},
  };

  int submatriz[3][3];

  for (int i = 0; i <= 6; i += 3) // Avança de 3 em 3 linhas
  {
    for (int j = 0; j <= 6; j += 3) // Avança de 3 em 3 colunas
    {
      // Extrair submatriz 3x3 a partir da posição (i,j)
      for (int x = 0; x < 3; x++)
      {
        for (int y = 0; y < 3; y++)
        {
          submatriz[x][y] = matriz[i + x][j + y];
        }
      }

      // Imprimir a submatriz extraída

      for (int x = 0; x < 3; x++)
      {
        for (int y = 0; y < 3; y++)
        {
          printf("%d ", submatriz[x][y]);
        }
        printf("  ");
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
