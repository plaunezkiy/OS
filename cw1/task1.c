#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <sys/wait.h>

#define SYSCALL1 463

int main() {
        pid_t parent = getpid(), gparent = getppid();
        pid_t argpid = 0;
        pid_t pid = fork(); // fork a new one

        printf("PARENT: chld:%d me(par):%d gp:%d\n", pid, parent, gparent);

        if (pid == -1) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            for (unsigned int n = 0; n < 10; ++n) {
                // printf("n: %d\n", n);
                printf("CHILD: %d->%ld\n", n, syscall(SYSCALL1, argpid, n));
                // printf("\n");
            }
            return 0;
        } else {
            wait(NULL);
            printf("PARENT: chld:%d me(par):%d gp:%d\n", pid, parent, gparent);
        }
        
        return 0;
}
