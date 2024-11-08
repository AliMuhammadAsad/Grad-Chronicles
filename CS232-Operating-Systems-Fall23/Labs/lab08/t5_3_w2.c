#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
    int fd1, fd2, retval; // file descriptors for the fifo files, return value
    char buff1[] = "Hello from the other side"; // buffer to store the data that is written to the fifo file
    char buff2[19]; // buffer to store the data that is read from the fifo file

    fflush(stdin);
    retval = mkfifo("/tmp/myfifo1", 0666); // create the first fifo file
    retval = mkfifo("/tmp/myfifo2", 0666); // create the second fifo file

    fd1 = open("/tmp/myfifo1", O_WRONLY); // open the first fifo file in write only mode
    write(fd1, buff1, sizeof(buff1)); // write the data to the fifo file
    close(fd1); // close the first fifo file

    fd2 = open("/tmp/myfifo2", O_RDONLY); // open the second fifo file in read only mode
    read(fd2, buff2, sizeof(buff2)); // read the data from the fifo file
    write(1, buff2, sizeof(buff2)); // write the data to the stdout
    printf("\n");
    close(fd2); // close the second fifo file
    
    return 0;
}