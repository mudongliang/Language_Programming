#include<linux/module.h>
#include<linux/init.h>
#include<linux/time.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");

static char modname[] = "time";
static char *province = "Guangdong";
module_param(province,charp,0);
static int population = 10000;
module_param(population,int,0); 
extern struct timespec xtime;

static int init_time(void)
{
   struct timeval tv;
   printk("Installing %s module.\n",modname);
   do_gettimeofday(&tv);
   printk("jiffies: %lu,tv.tv_sec: %lu,tv_nsec: %lu\n",jiffies,tv.tv_sec,tv.tv_usec);
   printk("Province: %s,Population: %d \n",province,population);
   return 0;
}

static void  exit_time(void)
{
   printk("Removing %s module.\n",modname);
}

module_init(init_time);
module_exit(exit_time);


