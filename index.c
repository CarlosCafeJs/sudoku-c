#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
  // const int LINHAS = 9;
  // const int COLUNAS = 9;

  int linhas, colunas, lin, col, numGerado;
  int matrizPrincipal[3][3] = {};
  int matrizMenor[3][3] = {};

  srand(time(NULL));

  for (linhas = 0; linhas <= 2; linhas++)
  {
    for (colunas = 0; colunas <= 2; colunas++)
    {
      for (lin = 0; lin <= 2; lin++)
      {
        for (col = 0; col <= 2; col++)
        {
          numGerado = rand() % 10;

          bool existe = unicidadeMatriz(matrizMenor, numGerado);

          if (existe == false)
          {

            matrizMenor[lin][col] = numGerado;
            // printf("Entrou, %d", matrizMenor[lin][col]);
          }
          else
          {

            int novoNumGenFunc = gerarNum(matrizMenor, lin, col);
            // printf(" T %d ", novoNumGenFunc);
            matrizMenor[lin][col] = novoNumGenFunc;
          }

          printf("| %d ", matrizMenor[lin][col]);
        }
        printf(" - ");
      }
      printf("\n");
    }
    printf("oi \n");
  }
  return (0);
}
