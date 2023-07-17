#include <stdio.h>
#include <stdlib.h>
#include "arvore-binaria.h"
#include "aux.h"


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
