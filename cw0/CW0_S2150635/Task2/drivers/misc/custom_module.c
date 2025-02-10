#include <linux/module.h>
#include <linux/kernel.h>
static int __init my_module_init(void) {
    printk(KERN_INFO "Load Message from S2150635.\n");
    return 0;
}

static void __exit my_module_exit(void) {
    printk(KERN_INFO "Unload Message from S2150635.\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
