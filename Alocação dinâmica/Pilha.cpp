#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Define um tipo de pilha com alocacao dinamica
typedef struct no {
	int valor;
	struct no *proximo;
} NO;

// Define um tipo de pilha com alocacao dinamica
typedef struct {
	NO *inicio;
	NO *fim;
} PILHA;

void mostrarMenu();
void inicializar(PILHA *pilha);
void incluir(PILHA *pilha, int valor);
int buscar(PILHA *pilha, int valor);
void exibir(PILHA *pilha);
void remover(PILHA *pilha);
void limparLista(PILHA *pilha);

int main() {
	int entrada, valor, retorno;
	PILHA pilha;

	inicializar(&pilha);

	do {
		mostrarMenu();
		scanf("%d", &entrada);

		switch (entrada) {
			case 1:
				printf("Digite o valor a ser inserido: ");
				scanf("%d", &valor);

				incluir(&pilha, valor);
				break;
			case 2:
				printf("Digite o valor a ser buscado: ");
				scanf("%d", &valor);

				retorno = buscar(&pilha, valor);
				if (retorno == -1)
					printf("Valor nao encontrado na pilha\n");
				else
					printf("Valor encontrado na pilha na posicao %d\n", retorno);
				break;
			case 3:
				exibir(&pilha);
				break;
			case 4:
				remover(&pilha);
				exibir(&pilha);
				break;
			case 5:
				limparLista(&pilha);
				exibir(&pilha);
				break;
			case 0:
				printf("Finalizando...\n");
				exit(1);
		}

		printf("\n\n\nAperte qualquer tecla para continuar.\n");
		getch();
	} while (entrada != 0);

	// Antes de finalizar, limpa a pilha
	limparLista(&pilha);

	return 0;
}

void mostrarMenu() {
	system("cls");
	printf("==========>Menu<==========\n");
	printf("__________________________\n");
	printf("      1-->Incluir\n");
	printf("      2-->Buscar\n");
	printf("      3-->Exibilir pilha\n");
	printf("      4-->Excluir\n");
	printf("      5-->Limpar pilha\n");
	printf("      0-->Sair\n");
	printf("__________________________\n");
	printf("\nOpcao: ");
}

void inicializar(PILHA *pilha) {
	pilha->inicio = NULL;
	pilha->fim = NULL;
}

void incluir(PILHA *pilha, int valor) {
	NO *novoNo = (NO *) malloc(sizeof(NO));
	novoNo->valor = valor;
	novoNo->proximo = NULL;

	if (pilha->inicio == NULL) {
		pilha->inicio = novoNo;
		pilha->fim = novoNo;
	} else {
		pilha->fim->proximo = novoNo;
		pilha->fim = novoNo;
	}

	printf("Valor %d inserido na pilha\n", valor);
}

int buscar(PILHA *pilha, int valor) {
	NO *noAtual = pilha->inicio;
	int posicao = 0;

	while (noAtual != NULL) {
		if (noAtual->valor == valor)
			return posicao;
		noAtual = noAtual->proximo;
		posicao++;
	}

	return -1;
}

void exibir(PILHA *pilha) {
	NO *noAtual = pilha->inicio;

	printf("\nPilha: ");
	while (noAtual != NULL) {
		printf("%d ", noAtual->valor);
		noAtual = noAtual->proximo;
	}

	printf("\n");
}

void remover(PILHA *pilha) {
	NO *noAtual = pilha->inicio;
	NO *noAnterior = NULL;

	if (noAtual == NULL) {
		printf("Pilha vazia\n");
		return;
	}

	while (noAtual->proximo != NULL) {
		noAnterior = noAtual;
		noAtual = noAtual->proximo;
	}

	if (noAnterior == NULL) {
		printf("Valor %d removido da pilha\n", noAtual->valor);
		free(noAtual);
		pilha->inicio = NULL;
		pilha->fim = NULL;
	} else {
		printf("Valor %d removido da pilha\n", noAtual->valor);
		free(noAtual);
		noAnterior->proximo = NULL;
		pilha->fim = noAnterior;
	}
}

void limparLista(PILHA *pilha) {
	NO *noAtual = pilha->inicio;
	NO *noProximo = NULL;

	while (noAtual != NULL) {
		noProximo = noAtual->proximo;
		free(noAtual);
		noAtual = noProximo;
	}

	pilha->inicio = NULL;
	pilha->fim = NULL;
}