/* Funções AVL */
void insertAVL(NodeBT **T, int v);                 // Insere um nó em uma árvore AVL
int balanceFactor(NodeBT *T);                      // Fator de balanceamento
void rotateL(NodeBT **T);                          // Rotação Esquerda
void rotateR(NodeBT **T);                          // Rotação Direita
void rotateLR(NodeBT **T);                         // Rotação Esquerda-Direita
void rotateRL(NodeBT **T);                         // Rotação Direita-Esquerda
void balance(NodeBT **T);                          // Balanceia um nó
void balanceTree(NodeBT **T);                      // Balanceia toda a árvore
