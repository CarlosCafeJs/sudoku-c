#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool unicidadeMatriz(int matrizz[3][3], int numAleatorio)
{

  bool existe;

  for (int i = 0; i <= 2; i++)
  {

    for (int j = 0; j <= 2; j++)
    {

      if (matrizz[i][j] == numAleatorio)
      {

        return true;
      }
    }
  }

  return false;
}

int gerarNum(int matrizz[3][3])
{

  int novoNumumGen;

  do
  {
    novoNumumGen = (rand() % 9) + 1;

    // printf("Novo num gerado : %d", novoNumumGen);
  } while (unicidadeMatriz(matrizz, novoNumumGen));

  return novoNumumGen;
}
int main()
{
  // const int LINHAS = 9;
  // const int COLUNAS = 9;
  srand(time(NULL));

  int subMatrizes[8][8];
  int rows = 2;
  int cols = 2;

  int **matrizPrincipal = (int **)malloc(subMatrizes[8][8] * sizeof(int *));

  if (matrizPrincipal == NULL)
  {
    fprintf(stderr, "Erro ao alocar memória para a matriz principal.\n");
    return 1;
  }

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      matrizPrincipal[i][j] = (int *)malloc(rows * cols * sizeof(int));
      if (matrizPrincipal[i] == NULL)
      {
        fprintf(stderr, "Erro ao alocar memória para a submatriz %d.\n", i);

        for (int j = 0; j < i; j++)
        {
          free(matrizPrincipal[j]);
        }
        free(matrizPrincipal);
        return 1;
      }

      for (int j = 0; j < rows * cols; j++)
      {
        matrizPrincipal[i][j] = i * (rows * cols) + j;
      }
    }
  }

  printf("Matriz Principal:\n");
  for (int i = 0; i < 9; i++)
  {
    printf("Submatriz %d:\n", i);
    for (int j = 0; j < rows; j++)
    {
      for (int k = 0; k < cols; k++)
      {
        printf("%d ", matrizPrincipal[i][j * cols + k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  for (int i = 0; i < 9; i++)
  {
    free(matrizPrincipal[i]);
  }
  free(matrizPrincipal);

  // for (linhas = 0; linhas <= 2; linhas++)
  // {
  //   for (colunas = 0; colunas <= 2; colunas++)
  //   {
  //     for (lin = 0; lin <= 2; lin++)
  //     {
  //       for (col = 0; col <= 2; col++)
  //       {
  //         numGerado = (rand() % 9) + 1;

  //         bool existe = unicidadeMatriz(matrizMenor, numGerado);

  //         if (existe == false)
  //         {

  //           matrizMenor[lin][col] = numGerado;
  //           // printf("Entrou, %d", matrizMenor[lin][col]);
  //         }
  //         else
  //         {

  //           int novoNumGenFunc = gerarNum(matrizMenor);
  //           // printf(" T %d ", novoNumGenFunc);
  //           matrizMenor[lin][col] = novoNumGenFunc;
  //         }

  //         printf("| %d ", matrizMenor[lin][col]);
  //       }
  //       printf(" - ");
  //     }
  //     printf("\n");
  //   }
  //   printf("oi \n");
  // }
  return (0);
}
