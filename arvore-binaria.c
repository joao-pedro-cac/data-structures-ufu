#include <stdio.h>
#include <stdlib.h>
#include "arvore-binaria.h"


// FUNÇÕES GERAIS
NodeBT* createNode(int v, NodeBT *esq, NodeBT *dir) {
	NodeBT *root = (NodeBT *) malloc(sizeof(NodeBT));

	root -> val = v;
	root -> esq = esq;
	root -> dir = dir;

	return root;
}


uint getHeight(NodeBT *root) {
	uint heightEsq = 1, heightDir = 1;                            // Raiz

	if (root -> esq) heightEsq += getHeight(root -> esq);         // Sub-árvore da esquerda
	if (root -> dir) heightDir += getHeight(root -> dir);         // Sub-árvore da direita

	if (heightEsq > heightDir) return heightEsq;
	else return heightDir;
}


uint getAmountNodes(NodeBT *root) {
	uint qntd = 1;                                                // Raiz

	if (root -> esq) qntd += getAmountNodes(root -> esq);         // Sub-árvore da esquerda
	if (root -> dir) qntd += getAmountNodes(root -> dir);         // Sub-árvore da direita

	return qntd;
}


uint getAmountLeaves(NodeBT *root) {
	uint qntd = 0;

	if ((root -> esq == NULL) && (root -> dir == NULL)) qntd++;   // Raiz
	if (root -> esq) qntd += getAmountLeaves(root -> esq);        // Sub-árvore da esquerda
	if (root -> dir) qntd += getAmountLeaves(root -> dir);        // Sub-árvore da direita

	return qntd;
}


char treeEquals(NodeBT *r1, NodeBT *r2) {
	char eq = 1;

	if (r1 -> val != r2 -> val) eq = 0;                           // Raizes

	if (!equiv(r1 -> esq, r2 -> esq)) eq = 0;
	if (!equiv(r1 -> dir, r2 -> dir)) eq = 0;

	if (r1 -> esq) eq = eq && treeEquals(r1 -> esq, r2 -> esq);
	if (r1 -> dir) eq = eq && treeEquals(r1 -> dir, r2 -> dir);

	return eq;
}


void printPreOrder(NodeBT *root) {
	printf("%d ", root -> val);                                   // Raiz
	if (root -> esq) printPreOrder(root -> esq);                  // Sub-árvore da esquerda
	if (root -> dir) printPreOrder(root -> dir);                  // Sub-árvore da direita
}


void printInOrder(NodeBT *root) {
	if (root -> esq) printInOrder(root -> esq);                   // Sub-árvore da esquerda
	printf("%d ", root -> val);                                   // Raiz
	if (root -> dir) printInOrder(root -> dir);                   // Sub-árvore da direita
}


void printPostOrder(NodeBT *root) {
	if (root -> esq) printPostOrder(root -> esq);                 // Sub-árvore da esquerda
	if (root -> dir) printPostOrder(root -> dir);                 // Sub-árvore da direita
	printf("%d ", root -> val);                                   // Raiz
}


void preInToPost(int in[], int pre[], int n) {
	//int *post = (int *) malloc(sizeof(int) * numNodes);
	int root = search(in, pre[0], n);

	// Se a sub-árvore da esquerda não for nula, imprime-a
	if (root != 0)
		preInToPost(in, pre + 1, root);

	// Se a sub-árvore da direita não for nula, imprime-a
	if (root != n - 1)
		preInToPost(in + root + 1, pre + root + 1, n - root - 1);

	// Imprime a raiz
	printf("%d ", pre[0]);
}


void deleteTree(NodeBT **root) {
	if (*root == NULL) return;

	// Percurso em pós-ordem
	deleteTree(&((*root) -> esq));                                // Sub-árvore da esquerda
	deleteTree(&((*root) -> dir));                                // Sub-árvore da direita
	free(*root);                                                  // Raiz

	*root = NULL;
}


// FUNÇÕES AUXILIARES
char equiv(NodeBT *A, NodeBT *B) {
	if (A && B) return 1;
	if (!(A || B)) return 1;

	return 0;
}


int search(int array[], int v, int size) {
	for (int i = 0; i < size; i++)
		if (array[i] == v) return i;
	return -1;
}
