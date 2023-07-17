#include <stdio.h>
#include "arvore-binaria.h"
#include "avl.h"

int main() {
	NodeBT *T = NULL;
	int nums[] = {27, 12, 13, 21, 8, 10, 4, 18, 1, 7, 19, 20, 14, 5, 3, 2, 0};
	const uint N = sizeof(nums) / sizeof(int);

	for (int i = 0; i < N; i++) insertAVL(&T, nums[i]);

	printf("PRE-ORDEM: ");
	printPreOrder(T);
	printf("\n");

	printf("EM-ORDEM:  ");
	printInOrder(T);
	printf("\n");

	printf("POS-ORDEM: ");
	printPostOrder(T);
	printf("\n");

	printf("FATOR DE BALANCEAMENTO = %d\n", balanceFactor(T));

	deleteTree(&T);
	return 0;
}
