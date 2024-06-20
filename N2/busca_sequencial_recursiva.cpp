#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Define um tipo de lista com alocacao dinamica
typedef struct no {
	int valor;
	int chave;
	struct no *proximo;
} NO;

// Define um tipo de lista com alocacao dinamica
typedef struct {
	NO *inicio;
	NO *fim;
} LISTA;

void inicializar(LISTA *lista);

void incluir(LISTA *lista, int chave);

void exibirLista(LISTA *lista);

NO *buscaSequencialRecursiva(LISTA *lista, int valor);

int main() {
	LISTA lista;
	inicializar(&lista);

	int valor = 25;
	NO *noComValorInformado = buscaSequencialRecursiva(&lista, valor);

	exibirLista(&lista);

	printf("\nBuscando valor %d...\n", valor);

	if (noComValorInformado != NULL)
		printf("Valor %d encontrado na chave %d\n", noComValorInformado->valor, noComValorInformado->chave);
	else
		printf("Valor %d nao encontrado\n", valor);

	printf("\nPressione qualquer tecla para sair...\n");
	getch();

	return 0;
}

void exibirLista(LISTA *lista) {
	NO *no = lista->inicio;

	while (no != NULL) {
		printf("Chave: %d, valor: %d\n", no->chave, no->valor);
		no = no->proximo;
	}
}

void inicializar(LISTA *lista) {
	lista->inicio = NULL;
	lista->fim = NULL;

	for (int i = 0; i < 15; i++)
		incluir(lista, i * i);
}

void incluir(LISTA *lista, int valor) {
	NO *novoNo = (NO *)malloc(sizeof(NO));
	novoNo->valor = valor;
	novoNo->proximo = NULL;

	if (lista->inicio == NULL) {
		novoNo->chave = 0;
		lista->inicio = novoNo;
		lista->fim = novoNo;
	} else {
		novoNo->chave = lista->fim->chave + 1;
		lista->fim->proximo = novoNo;
		lista->fim = novoNo;
	}
}

NO *buscaSequencialRecursiva(LISTA *lista, int valor) {
	NO *noAtual = lista->inicio;

	if (noAtual == NULL)
		return NULL;

	if (noAtual->valor == valor)
		return noAtual;

	lista->inicio = noAtual->proximo;

	return buscaSequencialRecursiva(lista, valor);
}
