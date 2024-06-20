#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a estrutura de nó
typedef struct no {
	char *valor;
	char *chave;
	struct no *proximo;
} LISTA;

// Define a tabela de hash
typedef struct {
	LISTA **tabela;
	int tamanho;
} TABELA_HASH;

void inicializar(TABELA_HASH *tabela, int tamanho);

void incluir(TABELA_HASH *tabela, char *chave, char *valor);

void excluir(TABELA_HASH *tabela, char *chave);

void buscar(TABELA_HASH *tabela, char *chave);

void exibirTabela(TABELA_HASH *tabela);

int main() {
	TABELA_HASH tabela;
	inicializar(&tabela, 15);

	printf("Incluindo valores na tabela (hash, chave, valor)...\n");

	incluir(&tabela, (char *)"Brasil", (char *)"Brasilia");
	incluir(&tabela, (char *)"Franca", (char *)"Paris");
	incluir(&tabela, (char *)"Alemanha", (char *)"Berlim");
	incluir(&tabela, (char *)"Argentina", (char *)"Buenos Aires");
	incluir(&tabela, (char *)"Estados Unidos", (char *)"Washington");
	incluir(&tabela, (char *)"Nome muito grande do pais", (char *)"Capital");

	printf("\nExibindo valores da tabela...\n");
	exibirTabela(&tabela);

	printf("\nExcluindo valores da tabela...\n");

	excluir(&tabela, (char *)"Argentina");
	excluir(&tabela, (char *)"Russia");
	excluir(&tabela, (char *)"Brasil");

	printf("\nExibindo valores da tabela...\n");
	exibirTabela(&tabela);

	printf("\nBuscando valores na tabela...\n");
	buscar(&tabela, (char *)"Franca");

	printf("\nPressione qualquer tecla para sair...\n");
	getch();

	return 0;
}

void inicializar(TABELA_HASH *tabela, int tamanho) {
	tabela->tamanho = tamanho;
	tabela->tabela = (LISTA **)malloc(tamanho * sizeof(LISTA *));

	for (int i = 0; i < tamanho; i++)
		tabela->tabela[i] = NULL;
}

void incluir(TABELA_HASH *tabela, char *chave, char *valor) {
	int hashPos = strlen(chave);

	if (hashPos >= tabela->tamanho) {
		printf("Chave muito longa, o valor maximo eh %d\n", tabela->tamanho - 1);
		return;
	}

	LISTA *novo = (LISTA *)malloc(sizeof(LISTA));
	novo->chave = chave;
	novo->valor = valor;
	novo->proximo = NULL;

	// Se não existe nó na posição, insere o novo nó
	if (tabela->tabela[hashPos] == NULL)
		tabela->tabela[hashPos] = novo;
	// Se já existe, insere no final da lista
	else {
		LISTA *ultimo = tabela->tabela[hashPos];

		// Para inserir no final da liste devo percorrer cada nó na sublista até encontrar no->prox == null
		while (ultimo->proximo != NULL)
			ultimo = ultimo->proximo;

		ultimo->proximo = novo;
	}

	printf("Incluido (%d, %s, %s)\n", hashPos, chave, valor);
}

void excluir(TABELA_HASH *tabela, char *chave) {
	int hashPos = strlen(chave);

	LISTA *no = tabela->tabela[hashPos];
	LISTA *anterior = NULL;

	// Percorre cada nó da tabela até encontrar o nó com a chave informada
	while (no != NULL && strcmp(no->chave, chave) != 0) {
		anterior = no;
		no = no->proximo;
	}

	// Se encontrou o nó é só remove-lo
	if (no != NULL) {
		if (anterior == NULL)
			tabela->tabela[hashPos] = no->proximo;
		else
			anterior->proximo = no->proximo;

		free(no);
	}

	printf("Excluido (%d, %s)\n", hashPos, chave);
}

void buscar(TABELA_HASH *tabela, char *chave) {
	int hashPos = strlen(chave);

	LISTA *no = tabela->tabela[hashPos];

	while (no != NULL && strcmp(no->chave, chave) != 0)
		no = no->proximo;

	if (no != NULL)
		printf("Valor encontrado (%d, %s, %s)\n", hashPos, no->chave, no->valor);
	else
		printf("Valor nao encontrado\n");
}

void exibirTabela(TABELA_HASH *tabela) {
	for (int i = 0; i < tabela->tamanho; i++) {
		LISTA *no = tabela->tabela[i];

		while (no != NULL) {
			printf("(%d, '%s', '%s')\n", i, no->chave, no->valor);
			no = no->proximo;
		}
	}
}