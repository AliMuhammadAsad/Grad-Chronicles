#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
// #include <asm-generic/signal.h>

volatile sig_atomic_t sigint_rec = 0;

void handle_sigint(int sig){
    if(sig == SIGINT) sigint_rec = 1;
}

int main(){
    struct sigaction sa;
    sigset_t block_mask, og_mask;

    // Signal Handler Init
    sa.sa_handler = handle_sigint; sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask); sigaction(SIGINT, &sa, NULL);

    // Block Mask
    sigemptyset(&block_mask); sigaddset(&block_mask, SIGINT);

    while(1){
        printf("Weeeeeeeeeeeeee.......\n"); sleep(2);

        sigprocmask(SIG_BLOCK, &block_mask, &og_mask);
        printf("Block maar diya, aaaaaaaaaaaaaaaaaaaa\n"); sleep(5);

        if(sigint_rec){
            printf("Koi mil gaya\n"); sleep(2);
            printf("Bohot ho gaya yaar ab\n"); break;
        }

        // Unblock 
        sigprocmask(SIG_SETMASK, &og_mask, NULL);
        printf("Unblock kar diya\n"); sleep(2);

        if(sigint_rec){
            printf("Mujhe ghar jana hai\n"); break;
        }
    }
    return 0;
}