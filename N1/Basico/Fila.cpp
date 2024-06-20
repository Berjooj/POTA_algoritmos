#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct
{
	int itens[TAMANHO_MAX];
	int topo;
} FILA;

void mostrarMenu();
void inicializar(FILA *fila);
void incluir(FILA *fila, int valor);
int buscar(FILA *fila, int valor);
void exibir(FILA *fila);
void remover(FILA *fila);

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
				inicializar(&fila);
				exibir(&fila);
				break;
			case 0:
				printf("Finalizando...\n");
				exit(1);
				break;
		}

		printf("\n\n\nAperte qualquer tecla para continuar.\n");
		getch();
	} while (1);
}

void remover(FILA *fila) {
	if (fila->topo < 0) {
		printf("Fila esta vazia, nenhum item foi removido\n");
		return;
	}

	printf("Item no comeco da fila foi removido\n");

	for (int i = 0; i < fila->topo; i++)
		fila->itens[i] = fila->itens[i + 1];

	fila->itens[fila->topo] = 0;
	fila->topo--;
}

void exibir(FILA *fila) {
	int i = 0;
	printf("Topo: %d\n[ ", fila->topo);

	for (i = 0; i <= fila->topo; i++)
		printf("%d ", fila->itens[i]);

	printf("]\n");
}

int buscar(FILA *fila, int valor) {
	int i = 0;
	int pos = -1;

	for (i = 0; i <= fila->topo; i++) {
		if (fila->itens[i] == valor) {
			pos = i;
			break;
		}
	}

	return pos;
}

void incluir(FILA *fila, int valor) {
	if ((fila->topo + 1) >= TAMANHO_MAX) {
		printf("A fila esta cheia, item nao inserido\n");
		return;
	}

	fila->itens[++fila->topo] = valor;
	printf("Valor %d inserido a fila\n", valor);
}

void inicializar(FILA *fila) {
	int i = 0;

	fila->topo = -1;

	for (i = 0; i < TAMANHO_MAX; i++)
		fila->itens[i] = 0;
}

void mostrarMenu() {
	system("cls");
	printf("==========>Menu<==========\n");
	printf("__________________________\n");
	printf("      1-->Incluir\n");
	printf("      2-->Buscar\n");
	printf("      3-->Exibilir lista\n");
	printf("      4-->Excluir\n");
	printf("      5-->Reiniciar fila\n");
	printf("      0-->Sair\n");
	printf("__________________________\n");
	printf("\nOpcao: ");
}
