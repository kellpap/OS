#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        FILE *fp = fopen("pids.txt", "w");
        if (!fp) {
            perror("File open failed");
            _exit(1);
        }
        fprintf(fp, "Child PID: %d, Parent PID: %d\n", getpid(), getppid());
        fclose(fp);
        _exit(0);
    } else {
        wait(NULL);
    }

    printf("Parent and child PIDs have been written to pids.txt.\n");
    return 0;
}
