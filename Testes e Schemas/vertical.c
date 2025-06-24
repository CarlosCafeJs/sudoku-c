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
        existe = true;
      }
    }
  }

  if (existe == true)
  {
    return true;
  }

  return false;
}

int gerarNum(int matrizz[3][3], int lin, int col)
{

  int novoNumumGen = rand() % 10;

  bool existe = unicidadeMatriz(matrizz, novoNumumGen);

  if (existe == false)
  {
    return novoNumumGen;
  }
  else
  {
    gerarNum(matrizz, lin, col);
  }
}
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
