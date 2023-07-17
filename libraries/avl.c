#include <stdio.h>
#include <stdlib.h>
#include "arvore-binaria.h"
#include "abb.h"
#include "aux.h"
#include "avl.h"


// FUNÇÕES AVL
void insertAVL(NodeBT **T, int v) {
	insertBST(T, v);                               // Insere na árvore
	balanceTree(T);                                // Balanceia a árvore
}


int balanceFactor(NodeBT *T) {
	int bf = 0;

	// Fator de balanceamento = (altura da sub-árvore direita) - (altura da sub-árvore esquerda)
	if (T -> dir) bf += getHeight(T -> dir);
	if (T -> esq) bf -= getHeight(T -> esq);

	return bf;
}


void rotateL(NodeBT **T) {
	NodeBT *q, *aux;

	q = (*T) -> dir;
	aux = q -> esq;

	q -> esq = *T;
	(*T) -> dir = aux;

	*T = q;
}


void rotateR(NodeBT **T) {
	NodeBT *q, *aux;

	q = (*T) -> esq;
	aux = q -> dir;

	q -> dir = *T;
	(*T) -> esq = aux;

	*T = q;
}


void rotateLR(NodeBT **T) {
	rotateL(&((*T) -> esq));
	rotateR(T);
}


void rotateRL(NodeBT **T) {
	rotateR(&((*T) -> dir));
	rotateL(T);
}


void balance(NodeBT **T) {
	int bf = balanceFactor(*T);

	// Casos de balanceamento
	if (bf == 2) {
		if (balanceFactor((*T) -> dir) > 0) rotateL(T);
		else rotateRL(T);
	}
	else if (bf == -2) {
		if (balanceFactor((*T) -> esq) < 0) rotateR(T);
		else rotateLR(T);
	}
}


void balanceTree(NodeBT **T) {
	// Balanceia toda a árvore em percurso pós-ordem (de baixo para cima)
	if ((*T) -> esq) balanceTree(&((*T) -> esq));
	if ((*T) -> dir) balanceTree(&((*T) -> dir));
	balance(T);
}
