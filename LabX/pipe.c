#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) { 
        close(fd[1]); 
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else { 
        close(fd[0]); 
        char message[] = "Hello from parent!";
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    return 0;
}
