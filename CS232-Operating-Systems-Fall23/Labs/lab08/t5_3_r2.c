#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
    int fd1, fd2, retval; // file descriptors for the fifo files, return value
    char buff1[26]; // buffer to store the data that is read from the fifo file
    char buff2[] = "Hello, how are you"; // buffer to store the data that is written to the fifo file

    fd1 = open("/tmp/myfifo1", O_RDONLY); // open the fifo file in read only mode
    retval = read(fd1, buff1, sizeof(buff1)); // read the data from the fifo file
    fflush(stdin);
    write(1, buff1, sizeof(buff1)); // write the data to the stdout
    printf("\n"); 
    close(fd1); // close the first fifo file

    fd2 = open("/tmp/myfifo2", O_WRONLY); // open the second fifo file in write only mode
    write(fd2, buff2, sizeof(buff2)); // write the data to the fifo file
    close(fd2); // close the second fifo file

    return 0;
}