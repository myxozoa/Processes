// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    // Your code here
    int child = fork();

    if (child < 0) {
        perror("fork failed\n");
        exit(1);
    }
    else if (child == 0) {
        printf("hello\n");
    }
    else {
        int wc = waitpid(child, NULL, 0);
        printf("goodbye\n");
    }
    return 0;
}
