#include <stdio.h>
#include "libraries/arvore-binaria.h"

int main() {
	NodeBT *T;

	T = createNode(2,
			createNode(7,
				createNode(1,
					NULL,
					NULL),
				createNode(4,
					NULL,
					NULL)),
			createNode(3,
				NULL,
				createNode(8,
					createNode(9,
						NULL,
						createNode(6,
							NULL,
							NULL)),
					createNode(5,
						NULL,
						NULL))));

	printf("ALTURA: %u\n", getHeight(T));
	printf("QNTD. NOS: %u\n", getAmountNodes(T));
	printf("QNTD. FOLHAS: %u\n", getAmountLeaves(T));

	deleteTree(&T);
	return 0;
}
