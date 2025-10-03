#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		fprintf(stderr, "usage: mem <value>\n"); exit(1);
	}
	int* p;
	p = malloc(sizeof(int));
	assert(p != NULL);
	printf("(%d) addr pointed to by p: %p\n", (int) getpid(), p);
	*p = atoi(argv[1]);
	while(1){
		sleep(1);
		*p = *p + 1;
		printf("(%d) value of p: %d\n", (int) getpid(), *p);
	}
	return 0;
}
