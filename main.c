#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// **************************************************************************
int *numbers_create(int size); // aloca os espaços para um tamanho fixo
void numbers_read(int *numbers,int size); // ler todos os valores para os espaços
float numbers_average(int *numbers,int size);// calcula a média e retorna o valor
void numbers_show(int *numbers, int size); // exibe os valores alocados
void numbers_destroy(int *numbers); // desaloca a variável alocada
int maior_numero(int *numbers, int size); // encontra o maior número do conjunto de dados
int menor_numero(int *numbers, int size); // encontra o menor número do conjunto de dados
int numeros_pares(int *numbers, int size); // exibi os números pares do conjunto de dados
int numeros_impares(int *numbers, int size); // exibi os números ímpares do conjunto de dados


// **************************************************************************


int main() {
srand(time(NULL));

  int size = (rand() % 10) + 10; // Gera um tamanho entre 10 e 19 para não ser muito grande/pequeno
  int *numbers = numbers_create(size);

  numbers_read(numbers, size);

  printf("Vetor gerado:\n");
  numbers_show(numbers, size);

  float avg = numbers_average(numbers, size);
  printf("Media = %.2f\n", avg);

  int maior = maior_numero(numbers, size);
  printf("Maior Numero = %d\n", maior);

  int menor = menor_numero(numbers, size);
  printf("Menor Numero = %d\n", menor);

  int qtd_pares = numeros_pares(numbers, size);
  printf("--> Total de numeros pares: %d\n", qtd_pares);

  int qtd_impares = numeros_impares(numbers, size);
  printf("--> Total de numeros impares: %d\n", qtd_impares);

  numbers_destroy(numbers);
  return 0;
}

// **************************** Implementação ******************************

int *numbers_create(int size) {
  int *num = NULL;
  num = (int *)malloc(size * sizeof(int));
  if (num == NULL)
    return NULL;
  return num;
}

void numbers_read(int *numbers, int size) {
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      numbers[i] = rand() % 50;
  }
}

float numbers_average(int *numbers, int size) {
  float sum = 0.0;
  if (numbers != NULL)
    for (int i = 0; i < size; i++)
      sum += numbers[i];
  if (sum != 0)
    return sum / (float)size;
  return 0;
}

void numbers_show(int *numbers, int size) {
  printf("[");
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      if (i == (size - 1))
        printf("%d", numbers[i]);
      else
        printf("%d, ", numbers[i]);
  }
  printf("]\n");
}

void numbers_destroy(int *numbers) { free(numbers); }

// *************************************************************************

int main() {
  srand(time(NULL));
  int *numbers; 
  int size=rand() % 100; 
  numbers = numbers_create(size);
  numbers_read(numbers, size);
  float avg = numbers_average(numbers, size); 
  numbers_show (numbers,size);
  printf("Media = %.2f", avg);
  numbers_destroy(numbers);
  return 0;
}