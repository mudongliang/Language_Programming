/*****************************************
*����:���ý������������ǰϵͳ�е����н���
*ͬʱ���Դ�ӡ�����̵������Ϣ
*
* ***************************************/

#include <linux/list.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
static int list_init(void)
{
        struct task_struct *task, *p;
        struct list_head *pos;

        int count = 0;
        task = &init_task;

        printk(KERN_ALERT "PID\tCOMM\n");
        list_for_each( pos, &task->tasks ) {
                p = list_entry( pos, struct task_struct, tasks );
                count++;
                printk(KERN_ALERT "%d\t%s\n", p->pid, p->comm );
        }
        printk("System has %d processes", count);
        return 0;
}
static void list_exit(void)
{
        printk( KERN_ALERT "GOOD BYE!!\n");
}
MODULE_AUTHOR("MDL");
MODULE_LICENSE("GPL");

module_init(list_init);
module_exit(list_exit);
