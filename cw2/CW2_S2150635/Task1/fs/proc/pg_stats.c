#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/version.h>

static int pg_stats_show(struct seq_file *m, void *v)
{
    struct task_struct *task;
    
    rcu_read_lock();
    for_each_process(task) {
        // safety check
        if (!task) {
            continue;
        }
        // Print the basic PID info first
        seq_printf(m, "%d: ", task->pid);
                
        // Try to safely access the page operation counters
        seq_printf(m, "[[%u],[%u],[%u]], [[%u],[%u],[%u]], [[%u],[%u],[%u]], [[%u],[%u],[%u]]\n",
            // PGD stats
            task->pgd_ops.allocate, task->pgd_ops.free, task->pgd_ops.set,
            // PUD stats
            task->pud_ops.allocate, task->pud_ops.free, task->pud_ops.set,
            // PMD stats
            task->pmd_ops.allocate, task->pmd_ops.free, task->pmd_ops.set,
            // PTE stats
            task->pte_ops.allocate, task->pte_ops.free, task->pte_ops.set);
    }
    rcu_read_unlock();
    
    return 0;
}

static int pg_stats_open(struct inode *inode, struct file *file)
{
    return single_open(file, pg_stats_show, NULL);
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0)
static const struct proc_ops pg_stats_fops = {
    .proc_open = pg_stats_open,
    .proc_read = seq_read,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};
#else
static const struct file_operations pg_stats_fops = {
    .owner = THIS_MODULE,
    .open = pg_stats_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};
#endif

static int __init pg_stats_init(void)
{
    proc_create("pg_stats", 0444, NULL, &pg_stats_fops);
    return 0;
}

/* Register the initialization function to be called at kernel boot time */
fs_initcall(pg_stats_init);