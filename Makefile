# EXECUÇÃO TOTAL
all: execs clean
execs: exe.infoBase exe.treeEq exe.preInPost exe.treeSort exe.createAVL

###############################################################################

# EXECUTÁVEIS
exe.infoBase: obj.infoBase obj.ab obj.aux
	gcc infoBase.o arvore-binaria.o aux.o -o infoBase

exe.treeEq: obj.treeEq obj.ab obj.aux
	gcc treeEq.o arvore-binaria.o aux.o -o treeEq

exe.preInPost: obj.preInPost obj.ab obj.aux
	gcc preInPost.o arvore-binaria.o aux.o -o preInPost

exe.treeSort: obj.treeSort obj.ab obj.abb obj.aux
	gcc treeSort.o arvore-binaria.o abb.o aux.o -o treeSort

exe.createAVL: obj.createAVL obj.ab obj.abb obj.aux obj.avl
	gcc createAVL.o arvore-binaria.o abb.o aux.o avl.o -o createAVL

###############################################################################

# OBJETOS
obj.ab: obj.abb obj.aux
	gcc -std=c99 -pedantic-errors -c libraries/arvore-binaria.c
obj.abb:
	gcc -std=c99 -pedantic-errors -c libraries/abb.c
obj.aux:
	gcc -std=c99 -pedantic-errors -c libraries/aux.c
obj.avl:
	gcc -std=c99 -pedantic-errors -c libraries/avl.c


obj.infoBase:
	gcc -std=c99 -pedantic-errors -c infoBase.c
obj.treeEq:
	gcc -std=c99 -pedantic-errors -c treeEq.c
obj.preInPost:
	gcc -std=c99 -pedantic-errors -c preInPost.c
obj.treeSort:
	gcc -std=c99 -pedantic-errors -c treeSort.c
obj.createAVL:
	gcc -std=c99 -pedantic-errors -c createAVL.c

###############################################################################

# OUTROS
clean:
	rm *.o
