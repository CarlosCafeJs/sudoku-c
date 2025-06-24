#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Define o número de submatrizes e suas dimensões
  int numSubMatrices = 2;
  int rows = 3;
  int cols = 4;

  // Aloca dinamicamente o array de ponteiros para as submatrizes
  int **matrizPrincipal = (int **)malloc(numSubMatrices * sizeof(int *));

  // Verifica se a alocação foi bem-sucedida
  if (matrizPrincipal == NULL)
  {
    fprintf(stderr, "Erro ao alocar memória para a matriz principal.\n");
    return 1;
  }

  // Aloca cada submatriz e preenche com valores
  for (int i = 0; i < numSubMatrices; i++)
  {
    matrizPrincipal[i] = (int *)malloc(rows * cols * sizeof(int));
    if (matrizPrincipal[i] == NULL)
    {
      fprintf(stderr, "Erro ao alocar memória para a submatriz %d.\n", i);
      // Libera a memória já alocada antes de sair
      for (int j = 0; j < i; j++)
      {
        free(matrizPrincipal[j]);
      }
      free(matrizPrincipal);
      return 1;
    }
    // Preenche a submatriz com valores de exemplo
    for (int j = 0; j < rows * cols; j++)
    {
      matrizPrincipal[i][j] = i * (rows * cols) + j; // Exemplo: valores sequenciais
    }
  }

  // Imprime os elementos da matriz principal e suas submatrizes
  printf("Matriz Principal:\n");
  for (int i = 0; i < numSubMatrices; i++)
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

  // Libera a memória alocada
  for (int i = 0; i < numSubMatrices; i++)
  {
    free(matrizPrincipal[i]);
  }
  free(matrizPrincipal);

  return 0;
}