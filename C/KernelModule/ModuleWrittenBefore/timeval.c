#include<linux/module.h>
#include<linux/init.h>
#include<linux/time.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");

static char modname[] = "time";

extern struct timespec xtime;

static int init_time(void)
{
   struct timeval tv;
   printk("Installing %s module.",modname);
   do_gettimeofday(&tv);
   printk("\njiffies : %lu,tv.tv_sec: %lu,tv_nsec: %lu",jiffies,tv.tv_sec,tv.tv_usec);
   return 0;
}

static void  exit_time(void)
{
   printk("\nRemoving %s module.",modname);
}

module_init(init_time);
module_exit(exit_time);


