#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int *vetor, int n, int i);

void heapSort(int *vetor, int n);

void bubbleSort(int *vetor, int n);

void lerArquivo(int *vetor);

int main() {
	int n = 5000;

	int vetor_bubble[n];
	int vetor_heap[n];

	lerArquivo(vetor_bubble);
	lerArquivo(vetor_heap);

	// Anotar o tempo de execucao
	clock_t t;
	t = clock();

	bubbleSort(vetor_bubble, n);

	t = clock() - t;
	double tempo = ((double)t) / CLOCKS_PER_SEC;

	printf("Tempo de processamento do BubbleSort: %f segundos\n", tempo);

	t = clock();

	heapSort(vetor_heap, n);

	t = clock() - t;
	tempo = ((double)t) / CLOCKS_PER_SEC;

	printf("\n\nTempo de processamento do Heapsort: %f segundos\n", tempo);

	printf("\nPressione qualquer tecla para sair...\n");
	getch();

	return 0;
}

void lerArquivo(int *vetor) {
	FILE *arquivo;
	int n = sizeof(vetor) / sizeof(int);

	arquivo = fopen("Numeros Aleatorios nao Repetidos.txt", "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	}

	while (!feof(arquivo)) {
		fscanf(arquivo, "%d", &vetor[n]);
		n++;
	}

	fclose(arquivo);
}

/**
 * Algoritmo da aula
 */
void bubbleSort(int *vetor, int n) {
	int i, j, temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (vetor[j] > vetor[j + 1]) {
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
}

void heapify(int *vetor, int n, int i) {
	int maior = i;

	/**
	 * Formula para determinar os filhos de um no em uma arvore heap binaria:
	 * - o no i tera como filhos os nos (2i + 1) e (2i + 2)
	 */
	int esquerda = 2 * i + 1;
	int direita = 2 * i + 2;

	// Se o filho da esquerda for maior que o no raiz, entao o maior eh o filho da esquerda
	if (esquerda < n && vetor[esquerda] > vetor[maior])
		maior = esquerda;

	// Se o filho da direita for maior que o no raiz, entao o maior eh o filho da direita
	if (direita < n && vetor[direita] > vetor[maior])
		maior = direita;

	// Se o maior nao for o no raiz atual, entao troca os valores
	if (maior != i) {
		int temp = vetor[i];
		vetor[i] = vetor[maior];
		vetor[maior] = temp;

		// Chama recursivamente a funcao para o no que foi trocado
		heapify(vetor, n, maior);
	}
}

void heapSort(int *vetor, int n) {
	// Cria a arvore heap binaria
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(vetor, n, i);

	// O elemento inicial eh o maior, entao troca com o ultimo elemento assim ficando ordenado
	for (int i = n - 1; i >= 0; i--) {
		int temp = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = temp;

		// Reorganiza a arvore heap binaria
		heapify(vetor, i, 0);
	}
}
