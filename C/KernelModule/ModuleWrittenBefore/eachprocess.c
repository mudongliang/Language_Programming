#include<linux/module.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/kernel.h>
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a template of driver program!");
static char modname[] = "process";
static int init_process(void)
{
   printk("Installing %s module.",modname);
   struct task_struct *task1;
   task1 = &init_task;
   do{
		printk(KERN_INFO "***%s[%d]parent %s\n",task1->comm,task1->pid,task1->parent->comm);
   }while((task1=next_task(task1))!=&init_task);
   printk(KERN_INFO "========================\n");
   printk(KERN_INFO "this process is %s[%d]\n",current->comm,current->pid);
   printk(KERN_INFO "========================\n");
   return 0;
}

static void  exit_process(void)
{
   printk("\nRemoving %s module.",modname);
}

module_init(init_process);
module_exit(exit_process);


