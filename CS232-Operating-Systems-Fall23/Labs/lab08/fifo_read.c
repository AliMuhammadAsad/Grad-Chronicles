#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
    int fd, retval; // file descriptor, return value
    char buffer[100]; // buffer to store the data

    for(int i = 0; i < 3; i++){
        fd = open("/tmp/myfifo", O_RDONLY); // open the fifo file in read only mode
        retval = read(fd, buffer, sizeof(buffer)); // read the data from the fifo file
        fflush(stdin); 
        write(1, buffer, sizeof(buffer)); // write the data to the stdout
        printf("\n");
        close(fd); // close the fifo file
        sleep(1);
    }

    return 0;
}