build:
	gcc -Wall -fPIC -c node.c
	gcc -Wall -fPIC -c my_stack.c
	gcc -Wall -fPIC -c dynamic_list.c
	gcc -shared -o mylib.so my_stack.o dynamic_list.o node.o
	cp mylib.so /usr/lib
	ldconfig
	gcc -Wall -c main.c
	gcc -Wall -o a.out main.o mylib.so
	ldd a.out

run:
	./a.out

clean:
	rm -f *.o *.so a.out