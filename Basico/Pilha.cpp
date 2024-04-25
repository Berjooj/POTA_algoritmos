#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct
{
	int itens[TAMANHO_MAX];
	int topo;
} PILHA;

void mostrarMenu();
void inicializar(PILHA *pilha);
void incluir(PILHA *pilha, int valor);
int buscar(PILHA *pilha, int valor);
void exibir(PILHA *pilha);
void remover(PILHA *pilha);

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
				inicializar(&pilha);
				exibir(&pilha);
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

void remover(PILHA *pilha) {
	if (pilha->topo < 0) {
		printf("Fila esta vazia, nenhum item foi removido\n");
		return;
	}

	printf("Item no topo da pilha foi removido\n");

	pilha->itens[pilha->topo--] = 0;
}

void exibir(PILHA *pilha) {
	int i = 0;
	printf("Topo: %d\n[ ", pilha->topo);

	for (i = 0; i <= pilha->topo; i++)
		printf("%d ", pilha->itens[i]);

	printf("]\n");
}

int buscar(PILHA *pilha, int valor) {
	int i = 0;
	int pos = -1;

	for (i = 0; i <= pilha->topo; i++) {
		if (pilha->itens[i] == valor) {
			pos = i;
			break;
		}
	}

	return pos;
}

void incluir(PILHA *pilha, int valor) {
	if ((pilha->topo + 1) >= TAMANHO_MAX) {
		printf("A pilha esta cheia, item nao inserido\n");
		return;
	}

	pilha->itens[++pilha->topo] = valor;
	printf("Valor %d inserido a pilha\n", valor);
}

void inicializar(PILHA *pilha) {
	int i = 0;

	pilha->topo = -1;

	for (i = 0; i < TAMANHO_MAX; i++)
		pilha->itens[i] = 0;
}

void mostrarMenu() {
	system("cls");
	printf("==========>Menu<==========\n");
	printf("__________________________\n");
	printf("      1-->Incluir\n");
	printf("      2-->Buscar\n");
	printf("      3-->Exibilir lista\n");
	printf("      4-->Excluir\n");
	printf("      5-->Reiniciar pilha\n");
	printf("      0-->Sair\n");
	printf("__________________________\n");
	printf("\nOpcao: ");
}
