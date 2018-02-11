#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

//printk info level
//KERN_EMERG	  "<0>"  优先级最高的先输出的紧急事件消息，表示操作系统在崩溃之前会进行输出提示信息
//KERN_ALERT	  "<1>"  输出警告消息，通知需要采取措施
//KERN_CRIT       "<2>"  这是一个临界情况，当发生重要的软件或者硬件操作失败时，进行输出信息提示
//KERN_ERR        "<3>"  当系统检测到发生一个错误时，会输出信息，设备驱动程序常用KERN_ERR来报告硬件的错误信息
//KERN_WARNING    "<4>"  提示信息，用于提醒。常用于系统安全相关消息的输出
//KERN_NOTICE     "<5>"  是一个普通的提示，用于系统安全的输出
//KERN_INFO       "<6>"  非正式的消息，可能无关紧要。
//KERN_DEBUG      "<7>"  用于程序开发与调试的信息。完成编码后，这类信息要删除。

static int moduletest_init(void)
{
	printk(KERN_ALERT "Hello module init\n");
    return 0;
}

static void moduletest_exit(void)
{
	printk(KERN_ALERT "Hello module exit\n");
}

module_init(moduletest_init);
module_exit(moduletest_exit);

MODULE_LICENSE("GPL");
