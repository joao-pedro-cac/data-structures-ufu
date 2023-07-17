#include <stdio.h>
#include "arvore-binaria.h"

int main() {
	NodeBT *T1, *T2;

	T1 = createNode(3, createNode(4, NULL, NULL), createNode(5, NULL, NULL));
	T2 = createNode(3, createNode(4, NULL, NULL), createNode(5, createNode(7, NULL, NULL), NULL));

	printf("IGUAIS: %s\n", treeEquals(T1, T2) ? "SIM" : "NAO");

	deleteTree(&T1);
	deleteTree(&T2);
	return 0;
}
