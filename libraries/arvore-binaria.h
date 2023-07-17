/* Typedefs */
typedef struct NodeBT NodeBT;
typedef unsigned int uint;

/* Estrutura de nó */
struct NodeBT {
	int val;
	NodeBT *esq, *dir;
};


/* Funções gerais */
NodeBT* createNode(int v, NodeBT *esq, NodeBT *dir);     // Cria um nó
uint getHeight(NodeBT *root);                            // Retorna o tamanho de uma árvore
uint getAmountNodes(NodeBT *root);                       // Retorna a quantidade de nós
uint getAmountLeaves(NodeBT *root);                      // Retorna a quantidade de folhas
char treeEquals(NodeBT *r1, NodeBT *r2);                 // Checa se duas árvores são iguais
void printPreOrder(NodeBT *root);                        // Imprime a árvore no formato pré-ordem
void printInOrder(NodeBT *root);                         // Imprime a árvore no formato em-ordem
void printPostOrder(NodeBT *root);                       // Imprime a árvore no formato pós-ordem
void preInToPost(int in[], int pre[], int N);            // Recebe caminhos pré-ordem e em-ordem e retorna caminho pós-ordem
void deleteTree(NodeBT **root);                          // Deleta a ávore
