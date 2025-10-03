#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv){
    FILE *stream = fopen("processes.dat", "r");
    FILE *stream_hello = fopen("helloworld_test.txt", "a");
    char iD[1024], lname[1024];
    int a; float b; char c;

    while ( fscanf(stream,
                     "%s %s %d %f %c",
                     iD, lname, &a, &b, &c) != EOF)
     {
        fprintf(stream_hello, "ID: %s\n", iD);
        fprintf(stream_hello, "Name: %s\n", lname);
        fprintf(stream_hello, "Marks: %d\n", a);
        fprintf(stream_hello, "GPA: %f\n", b);
        fprintf(stream_hello, "Grade: %c\n", c);
        fprintf(stream_hello, "\n");
     }
    fclose(stream_hello);
    fclose(stream);
    return 0;
}