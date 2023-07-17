#include <stdio.h>
#include "libraries/arvore-binaria.h"

int main() {
	int preOrder[] = {3, 4, 1, 6, 5, 7, 8};
	int inOrder[]  = {1, 4, 6, 3, 7, 5, 8};

	preInToPost(inOrder, preOrder, 7);
	printf("\n");

	return 0;
}
