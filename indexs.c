#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM 9

bool podeColocar(int matriz[TAM][TAM], int linha, int coluna, int num)
{
  for (int i = 0; i < TAM; i++)
  {
    if (matriz[linha][i] == num || matriz[i][coluna] == num)
    {
      return false;
    }
  }

  int blocoInicioLinha = linha - linha % 3;
  int blocoInicioColuna = coluna - coluna % 3;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (matriz[blocoInicioLinha + i][blocoInicioColuna + j] == num)
      {
        return false;
      }
    }
  }

  return true;
}

void embaralhar(int *numeros)
{
  for (int i = 0; i < TAM; i++)
  {
    numeros[i] = i + 1;
  }
  for (int i = TAM - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);
    int temp = numeros[i];
    numeros[i] = numeros[j];
    numeros[j] = temp;
  }
}

bool preencherSudoku(int matriz[TAM][TAM], int linha, int coluna)
{
  if (linha == TAM)
    return true;
  if (coluna == TAM)
    return preencherSudoku(matriz, linha + 1, 0);

  int numeros[TAM];
  embaralhar(numeros);

  for (int i = 0; i < TAM; i++)
  {
    int num = numeros[i];
    if (podeColocar(matriz, linha, coluna, num))
    {
      matriz[linha][coluna] = num;
      if (preencherSudoku(matriz, linha, coluna + 1))
        return true;
      matriz[linha][coluna] = 0; // backtrack
    }
  }

  return false;
}

// Imprime a matriz
void imprimirMatriz(int matriz[TAM][TAM])
{
  for (int i = 0; i < TAM; i++)
  {
    for (int j = 0; j < TAM; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int matriz[TAM][TAM] = {0};

  srand(time(NULL));

  if (preencherSudoku(matriz, 0, 0))
  {
    printf("gerado :\n\n");
    imprimirMatriz(matriz);
  }
  else
  {
    printf("Erro .\n");
  }

  return 0;
}
