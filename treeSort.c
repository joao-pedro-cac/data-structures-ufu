#include <stdio.h>
#include <stdlib.h>
#include "libraries/arvore-binaria.h"
#include "libraries/abb.h"
#include "libraries/aux.h"

#define N 8

int main() {
	NodeBT *T = NULL;
	int nums[] = {15, 8, -3, 2, 7, 4, 3, 0, 5};

	printf("ORIGINAL:");
	for (int i = 0; i < N; i++) {
		printf(" %d", nums[i]);
		insertBST(&T, nums[i]);
	}

	printf("\nORDENADO: ");
	printInOrder(T);
	printf("\n");

	deleteTree(&T);
	return 0;
}
