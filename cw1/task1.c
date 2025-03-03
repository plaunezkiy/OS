#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>

#define SYSCALL1 463
#define NUM_CHILDREN 3

int main() {
    pid_t original_parent = getpid();
    pid_t child_pid;
    int i;
    
    printf("Original parent created with PID: %d\n", original_parent);
    
    // Create a chain of processes
    for (i = 0; i < NUM_CHILDREN; i++) {
        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(1);
        }
        if (child_pid > 0) {
            // This is the parent - break out of loop
            break;
        }
        // This is the child - continue to create next generation
        printf("Child %d created with PID: %d, Parent: %d\n", i+1, getpid(), getppid());
    }
    
    if (i == 0) {
        // Original parent
        printf("Original parent (PID: %d) waiting to be killed\n", original_parent);
        sleep(2);
        exit(0);
    } else if (i == NUM_CHILDREN) {
        // Last child in the chain
        sleep(3);  // Wait for the original parent to be killed
        
        // Perform syscalls to the original parent
        for (unsigned int n = 0; n < 10; ++n) {
            long result = syscall(SYSCALL1, getpid(), n);
            printf("Last child (PID: %d) syscall: n=%d, result=%ld\n", 
                   getpid(), n, result);
            
            if (result == -ESRCH) {
                printf("  Received -ESRCH (No such process)\n");
            }
        }
    } else {
        // // Middle children - if first child, kill the original parent
        // if (i == 1) {
        //     sleep(2);  // Give time for all children to spawn
        //     printf("First child (PID: %d) killing original parent (PID: %d)\n", getpid(), original_parent);
        //     kill(original_parent, SIGKILL);
        // }
        
        // All middle children wait for their child
        wait(NULL);
    }
    
    return 0;
}