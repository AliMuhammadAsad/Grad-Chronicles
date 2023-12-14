#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/* Example 4 */
int main() {
    // int p = getpid();
    if (kill(339020, SIGUSR1) == -1) {
        perror("Error sending signal");
        return 1;
    }
    return 0;
}