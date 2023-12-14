#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
    int fd, retval; // file descriptor, return value
    char buffer[] = "Hapi hapi hapi"; // buffer to store the data
    
    fflush(stdin); 
    retval = mkfifo("/tmp/myfifo", 0666); // create the fifo file
    fd = open("/tmp/myfifo", O_WRONLY); // open the fifo file in write only mode
    write(fd, buffer, sizeof(buffer)); // write the data to the fifo file
    close(fd); // close the fifo file

    return 0;
}