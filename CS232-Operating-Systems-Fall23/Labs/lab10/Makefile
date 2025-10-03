all: build run clean

build:
	gcc -lpthread -o t_31 t_3.1.c
	gcc -lpthread -o t_41 t_4.1.c
	gcc -lpthread -o t_5.1.1 t_5.1.1.c
	gcc -lpthread -o t_5.1.2 t_5.1.2.c
	gcc -lpthread -o t_6.1.1 t_6.1.1.c
	gcc -lpthread -o t_6.1.2 t_6.1.2.c

run:
	./t_31
	./t_41
	./t_5.1.1
	./t_5.1.2
	./t_6.1.1
	./t_6.1.2

clean:
	rm -f t_31 t_41 t_5.1.1 t_5.1.2 t_6.1.1 t_6.1.2