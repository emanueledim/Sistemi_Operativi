programma: main.o prodcons.o
	gcc -o programma  main.o prodcons.o -lpthread

main.o: main.c prodcons.h
	gcc -c -o main.o main.c -lpthread

prodcons.o: prodcons.c prodcons.h
	gcc -c -o prodcons.o prodcons.c -lpthread

clean:
	rm -f *.o
	rm -f programma
