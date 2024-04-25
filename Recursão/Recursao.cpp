#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarMenu();

int somarArrayRecursivo(int *array, int tamanho);
int somarArray(int *array, int tamanho);

void inverterStringRecursivo(char *string, int comeco, int fim);
void inverterString(char *string);

int buscaBinariaRecursiva(int *array, int inicio, int fim, int valor);
int buscaBinaria(int *array, int tamanho, int valor);

int main() {
	int entrada, tamanho, resultado;

	// soma = 55
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	char string[] = "Pesquisa, ordenacao e tecnicas de armazenamento";

	do {
		mostrarMenu();
		scanf("%d", &entrada);

		switch (entrada) {
			case 1:
				tamanho = sizeof(array) / sizeof(int);

				printf("Vetor: [ ");
				for (int i = 0; i < tamanho; i++)
					printf("%d ", array[i]);
				printf("]\n");

				resultado = somarArrayRecursivo(array, tamanho);
				printf("Somatorio com recursao do array: %d\n", resultado);

				resultado = somarArray(array, tamanho);
				printf("Somatorio sem recursao do array: %d\n", resultado);
				break;
			case 2:
				printf("String original: %s\n", string);
				inverterStringRecursivo(string, 0, strlen(string) - 1);
				printf("String invertida com recursao: %s\n", string);

				// Restaura a string original
				inverterStringRecursivo(string, 0, strlen(string) - 1);

				printf("\nString original: %s\n", string);
				inverterString(string);
				printf("String invertida sem recursao: %s\n", string);
				break;
			case 3:
				tamanho = (sizeof(array) / sizeof(int));

				printf("Vetor: [ ");
				for (int i = 0; i < tamanho; i++)
					printf("%d ", array[i]);
				printf("]\n");

				printf("Buscando o valor 7\n");

				resultado = buscaBinariaRecursiva(array, 0, tamanho, 7);
				printf("[Busca binaria com recursao] Indice encontrado [ %d ]\n", resultado);

				resultado = buscaBinaria(array, tamanho, 7);
				printf("[Busca binaria sem recursao] Indice encontrado [ %d ]\n", resultado);
				break;
			case 0:
				break;
			default:
				printf("Opcao invalida\n");
				break;
		}

		printf("\n\n\nAperte qualquer tecla para continuar.\n");
		getch();
	} while (entrada != 0);

	return 0;
}

void mostrarMenu() {
	system("cls");
	printf("==========>Menu<==========\n");
	printf("__________________________\n");
	printf("      1-->Somatorio do array\n");
	printf("      2-->Inversao da string\n");
	printf("      3-->Busca binaria\n");
	printf("      0-->Sair\n");
	printf("__________________________\n");
	printf("\nOpcao: ");
}

int somarArrayRecursivo(int *array, int tamanho) {
	if (tamanho == 0)
		return 0;

	return array[tamanho - 1] + somarArrayRecursivo(array, tamanho - 1);
}

int somarArray(int *array, int tamanho) {
	int soma = 0;

	for (int i = 0; i < tamanho; i++)
		soma += array[i];

	return soma;
}

void inverterStringRecursivo(char *string, int comeco, int fim) {
	if (comeco >= fim)
		return;

	char temp = string[comeco];
	string[comeco] = string[fim];
	string[fim] = temp;

	inverterStringRecursivo(string, comeco + 1, fim - 1);
}

void inverterString(char *string) {
	int comeco = 0;
	int fim = strlen(string) - 1;

	while (comeco < fim) {
		char temp = string[comeco];
		string[comeco] = string[fim];
		string[fim] = temp;

		comeco++;
		fim--;
	}
}

int buscaBinariaRecursiva(int *array, int inicio, int fim, int valor) {
	if (inicio > fim)
		return -1;

	int meio = (inicio + fim) / 2;

	if (array[meio] == valor)
		return meio;

	if (array[meio] < valor)
		return buscaBinariaRecursiva(array, meio + 1, fim, valor);
	else
		return buscaBinariaRecursiva(array, inicio, meio - 1, valor);
}

int buscaBinaria(int *array, int tamanho, int valor) {
	int inicio = 0;
	int fim = tamanho;

	while (inicio <= fim) {
		int meio = (inicio + fim) / 2;

		if (array[meio] == valor)
			return meio;

		if (array[meio] < valor)
			inicio = meio + 1;
		else
			fim = meio - 1;
	}

	return -1;
}