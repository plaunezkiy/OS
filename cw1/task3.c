#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>

#define SYSCALL1 463
#define NUM_CHILDREN 3
/*
The kernel should handle /prov/<PID>/schedstat updates
0 0 0 []
[] should print the list of CPUs this process was schedulen on in this epoch

when a process is scheduled on a CPU, set the CPU in used_cpus
*/

int main() {
    pid_t pid = getpid();
    
    {
        // set affinity to a fixed CPU
        // wait for epoch to reset (proc->epoch_ticks == 0)
        // record CPUs
        // wait for epoch to end (proc->epoch_ticks == 0)
        // verify that the CPUs are the same
    }
    
    return 0;
}
