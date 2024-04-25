#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Define um tipo de lista com alocacao dinamica
typedef struct no {
	int valor;
	struct no *proximo;
} NO;

// Define um tipo de lista com alocacao dinamica
typedef struct {
	NO *inicio;
	NO *fim;
} FILA;

void mostrarMenu();
void inicializar(FILA *fila);
void incluir(FILA *fila, int valor);
int buscar(FILA *fila, int valor);
void exibir(FILA *fila);
void remover(FILA *fila);
void limparLista(FILA *fila);

int main() {
	int entrada, valor, retorno;
	FILA fila;

	inicializar(&fila);

	do {
		mostrarMenu();
		scanf("%d", &entrada);

		switch (entrada) {
			case 1:
				printf("Digite o valor a ser inserido: ");
				scanf("%d", &valor);

				incluir(&fila, valor);
				break;
			case 2:
				printf("Digite o valor a ser buscado: ");
				scanf("%d", &valor);

				retorno = buscar(&fila, valor);
				if (retorno == -1)
					printf("Valor nao encontrado na fila\n");
				else
					printf("Valor encontrado na fila na posicao %d\n", retorno);
				break;
			case 3:
				exibir(&fila);
				break;
			case 4:
				remover(&fila);
				exibir(&fila);
				break;
			case 5:
				limparLista(&fila);
				exibir(&fila);
				break;
			case 0:
				printf("Finalizando...\n");
				exit(1);
		}

		printf("\n\n\nAperte qualquer tecla para continuar.\n");
		getch();
	} while (entrada != 0);

	// Antes de finalizar, limpa a lista
	limparLista(&fila);

	return 0;
}

void mostrarMenu() {
	system("cls");
	printf("==========>Menu<==========\n");
	printf("__________________________\n");
	printf("      1-->Incluir\n");
	printf("      2-->Buscar\n");
	printf("      3-->Exibilir lista\n");
	printf("      4-->Excluir\n");
	printf("      5-->Limpar lista\n");
	printf("      0-->Sair\n");
	printf("__________________________\n");
	printf("\nOpcao: ");
}

void inicializar(FILA *fila) {
	fila->inicio = NULL;
	fila->fim = NULL;
}

void incluir(FILA *fila, int valor) {
	NO *novoNo = (NO *) malloc(sizeof(NO));
	novoNo->valor = valor;
	novoNo->proximo = NULL;

	if (fila->inicio == NULL) {
		fila->inicio = novoNo;
		fila->fim = novoNo;
	} else {
		fila->fim->proximo = novoNo;
		fila->fim = novoNo;
	}

	printf("Valor %d inserido na fila\n", valor);
}

int buscar(FILA *fila, int valor) {
	NO *noAtual = fila->inicio;
	int posicao = 0;

	while (noAtual != NULL) {
		if (noAtual->valor == valor)
			return posicao;
		noAtual = noAtual->proximo;
		posicao++;
	}

	return -1;
}

void exibir(FILA *fila) {
	NO *noAtual = fila->inicio;

	printf("\nFila: ");
	while (noAtual != NULL) {
		printf("%d ", noAtual->valor);
		noAtual = noAtual->proximo;
	}

	printf("\n");
}

void remover(FILA *fila) {
	NO *noAtual = fila->inicio;

	if (noAtual != NULL) {
		fila->inicio = noAtual->proximo;

		printf("Valor %d removido da fila\n", noAtual->valor);

		free(noAtual);
	}
}

void limparLista(FILA *fila) {
	NO *noAtual = fila->inicio;
	NO *noProximo = NULL;

	while (noAtual != NULL) {
		noProximo = noAtual->proximo;
		free(noAtual);
		noAtual = noProximo;
	}

	fila->inicio = NULL;
	fila->fim = NULL;
}