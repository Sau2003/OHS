#include <iostream>
#include <cstring>
#include <unistd.h>

#define BUFFER_SIZE 25
#define Read_end 0
#define write_end  1
using namespace std; // Adding namespace std

int main(void){
    char write_msg[BUFFER_SIZE] = "greet";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    // Creating a pipe
    if (pipe(fd) == -1) {
        cerr << "Pipe failed" << endl;
        return 1;
    }

    // Creating a child process
    pid = fork();
    if (pid < 0) {
        cerr << "Fork failed" << endl;
        return 1;
    }
    // Parent process
    if (pid > 0) {
        close(fd[Read_end]); // Close the read end of the pipe in the parent
        // Writing message to the pipe
        write(fd[write_end], write_msg, strlen(write_msg) + 1);
        close(fd[write_end]); // Close the write end of the pipe in the parent
    }
    // Child process
    else {
        close(fd[write_end]); // Close the write end of the pipe in the child
        // Reading message from the pipe
        read(fd[Read_end], read_msg, BUFFER_SIZE);
        cout << "Read: " << read_msg << endl;
        close(fd[Read_end]); // Close the read end of the pipe in the child
    }
    return 0;
}

