#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void heapify(int *vetor, int n, int i);

void heapSort(int *vetor, int n);

int main() {
	int vetor[] = {40, 90, 20, 10, 50, 70, 80};

	int n = sizeof(vetor) / sizeof(vetor[0]);

	printf("Vetor original:\n");

	for (int i = 0; i < n; i++)
		printf("%d ", vetor[i]);

	printf("\n");

	heapSort(vetor, n);

	printf("\n\nVetor ordenado:\n");

	for (int i = 0; i < n; i++)
		printf("%d ", vetor[i]);

	printf("\nPressione qualquer tecla para sair...\n");
	getch();

	return 0;
}

void heapify(int *vetor, int n, int i) {
	int maior = i;

	/**
	 * Fórmula para determinar os filhos de um nó em uma árvore heap binária:
	 * - o nó i terá como filhos os nós (2i + 1) e (2i + 2)
	 */
	int esquerda = 2 * i + 1;
	int direita = 2 * i + 2;

	// Se o filho da esquerda for maior que o nó raiz, então o maior é o filho da esquerda
	if (esquerda < n && vetor[esquerda] > vetor[maior])
		maior = esquerda;

	// Se o filho da direita for maior que o nó raiz, então o maior é o filho da direita
	if (direita < n && vetor[direita] > vetor[maior])
		maior = direita;

	// Se o maior não for o nó raiz atual, então troca os valores
	if (maior != i) {
		int temp = vetor[i];
		vetor[i] = vetor[maior];
		vetor[maior] = temp;

		// Chama recursivamente a função para o nó que foi trocado
		heapify(vetor, n, maior);
	}
}

void heapSort(int *vetor, int n) {
	// Cria a árvore heap binária
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(vetor, n, i);

	printf("\nVetor heapificado:\n");

	for (int i = 0; i < n; i++)
		printf("%d ", vetor[i]);

	// O elemento inicial é o maior, então troca com o último elemento assim ficanod ordenado
	for (int i = n - 1; i >= 0; i--) {
		int temp = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = temp;

		// Reorganiza a árvore heap binária
		heapify(vetor, i, 0);

		printf("\nVetor heapificado:\n");
		for (int i = 0; i < n; i++)
			printf("%d ", vetor[i]);
	}
}
