#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handle_signal(int sig) {
    printf("Child received signal: %d\n", sig);
    exit(0);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        signal(SIGUSR1, handle_signal);
        while (1) {
            pause();
        }
    } else {
        sleep(1);
        printf("Parent sending signal to child\n");
        kill(pid, SIGUSR1);
    }
    return 0;
}
