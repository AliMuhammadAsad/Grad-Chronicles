build:
	gcc task5_1.c -o task5_1.out
	gcc task5_2.c -o task5_2.out
	gcc task5_3.c -o task5_3.out
	gcc task5_4.c -o task5_4.out
	gcc task6_1.c -o task6_1.out
	gcc task6_2.c -o task6_2.out

run: build
	./task5_1.out
	./task5_2.out 
	./task5_3.out helloworld.txt
	./task5_4.out helloworld.txt copied.txt
	./task6_1.out 
	./task6_2.out

clean:
	rm -v task5_1.out
	rm -v task5_2.out
	rm -v task5_3.out
	rm -v task5_4.out
	rm -v task6_1.out
	rm -v task6_2.out

# CXX = gcc
# SRC = task5_1.c
# TARGET = task5_1
# CFLAGS = -Wall

# build:
# 	$(CXX) $(SRC) -o $(TARGET) 

# run: build
# 	./$(TARGET)

# clean:
# 	rm -v $(TARGET)