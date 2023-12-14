all: build run clean

build:
	gcc -lpthread -o l1_timed l1_timed.c
	gcc -lpthread -o l2_timed l2_timed.c
	gcc -lpthread -o t5_1 t5_1.c
	gcc -lpthread -o t5_2 t5_2.c

run:
	./l1_timed
	./l2_timed
	./t5_1
	./t5_2

clean:
	rm -f l1_timed l2_timed t5_1 t5_2