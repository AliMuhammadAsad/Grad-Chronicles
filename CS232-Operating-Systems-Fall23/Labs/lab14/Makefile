.PHONY: build run1 clean ignore

build:
	gcc -Wall -o t1 task1.c
	gcc -Wall -o t2 task2.c
	gcc -Wall -o t3 task3.c

run1:
	./t1 $(filter-out $@,$(MAKECMDGOALS))

run2:
	./t2

run3:
	./t3

clean:
	rm -f t1 t2 t3

ignore:
	@:

%: ignore
	@: