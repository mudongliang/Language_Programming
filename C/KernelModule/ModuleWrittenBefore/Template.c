#include<linux/module.h>
#include<linux/init.h>
#include<linux/time.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("mudongliang");
MODULE_DESCRIPTION("This is a template of driver program!");

static char modname[] = "Template";
static int init_time(void)

{
   printk("Installing %s module.", modname);
   return 0;
}

static void  exit_time(void)
{
   printk("\nRemoving %s module.", modname);
}

module_init(init_time);
module_exit(exit_time);


