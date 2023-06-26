# EXECUÇÃO TOTAL
all: execs clean

execs: exe.q123 exe.q4 exe.q5


# EXECUTÁVEIS
exe.q123: obj.q123 obj.arvore-binaria
	gcc q123.o arvore-binaria.o -o q123

exe.q4: obj.q4 obj.arvore-binaria
	gcc q4.o arvore-binaria.o -o q4

exe.q5: obj.q5 obj.arvore-binaria
	gcc q5.o arvore-binaria.o -o q5


# OBJETOS
obj.arvore-binaria:
	gcc -std=c99 -pedantic-errors -c arvore-binaria.c

obj.q123:
	gcc -std=c99 -pedantic-errors -c q123.c

obj.q4:
	gcc -std=c99 -pedantic-errors -c q4.c

obj.q5:
	gcc -std=c99 -pedantic-errors -c q5.c


# AUXILIAR
clean:
	rm *.o
