CFLAGS = -Wno-implicit-function-declaration

main.o: main.c
	echo "Compile main.c"
	gcc $(CFLAGS) -c main.c

clean:
	rm -rf *o main

debug:
	gcc -g main.c -o main

