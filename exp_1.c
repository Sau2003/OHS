#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> // Include this header for fork()

int main() {
    printf("Before fork : process id is %d\n", getpid());
    pid_t pid = fork(); // Store the return value of fork()
    if (pid < 0) {
        printf("Error");
        return 1;
    }
    if (pid == 0) {
        printf("This is child process\n");
        printf("PID is %d and PPID is %d\n", getpid(), getppid());
    } else {
        printf("This is a parent process\n");
        printf("PID is %d and PPID is %d\n", getpid(), getppid());
    }
    return 0;
}

