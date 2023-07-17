#include <stdio.h>
#include <stdlib.h>
#include "arvore-binaria.h"
#include "abb.h"
#include "aux.h"


// FUNÇÕES ABB
void insertBST(NodeBT **T, int v) {
	if (*T == NULL) {
		*T = createNode(v, NULL, NULL);                             // Se o ponteiro for nulo, então cria-se uma raíz
		return;
	}

	NodeBT *newNode = (NodeBT *) malloc(sizeof(NodeBT));            // Novo nó a ser inserido
	NodeBT *aux = *T;

	newNode -> val = v;
	newNode -> esq = NULL;
	newNode -> dir = NULL;

	// Percorre a árvore até encontrar um lugar de inserção
	while (aux -> esq || aux -> dir) {
		if (v < aux -> val && aux -> esq) aux = aux -> esq;         // Se 'v' for menor, vai para a esquerda
		else if (v > aux -> val && aux -> dir) aux = aux -> dir;    // Se 'v' for maior, vai para a direita
		else break;
	}

	if (v > aux -> val) aux -> dir = newNode;                       // Se 'v' for maior, insere à direita
	else aux -> esq = newNode;                                      // Se 'v' for menor, insere à esquerda
}
