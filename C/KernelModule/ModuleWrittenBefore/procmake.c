/*********create ,read and write a /proc file based on linux******/
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/uaccess.h>

#define PROCFS_NAME "myprocfile"
#define PROCFS_MAX_SIZE 1024

char proc_buffer[PROCFS_MAX_SIZE];
static long int proc_buffer_size=0;
struct proc_dir_entry *MY_PROC_FILE;

int procfile_read(char*buffer, char**buffer_localation, off_t offset,\
                               int buffer_length,int* eof, void *data )
{
      int ret;
      printk(KERN_INFO "procfile_read(/proc/%s) called\n",PROCFS_NAME);
      if(offset>0)
      {
          printk(KERN_INFO "file /porc/%s has been finished to read\n",PROCFS_NAME);
          return 0;
      }else
      {
          memcpy(buffer,proc_buffer,proc_buffer_size);
          ret=proc_buffer_size;
      }
      return ret;
}
                  
int procfile_write(struct file *filp, const char *buffer,unsigned long count,void *data)
{
     proc_buffer_size=count;
     if(proc_buffer_size > PROCFS_MAX_SIZE)
     { 
         proc_buffer_size = PROCFS_MAX_SIZE;
     }
     if(copy_from_user(proc_buffer, buffer, proc_buffer_size));
     {
         return -EFAULT;
     }
     return proc_buffer_size;     
}
    
static int __init procfs_init(void)
{
    MY_PROC_FILE = create_proc_entry(PROCFS_NAME,0644,NULL);
    if(MY_PROC_FILE == NULL)
    {
    remove_proc_entry(PROCFS_NAME, &proc_root);
    printk(KERN_INFO "Error:could not initialize /proc/%s\n",PROCFS_NAME);
    return -ENOMEM;
    }
    MY_PROC_FILE->read_proc = procfile_read;
    MY_PROC_FILE->write_proc = procfile_write;
    MY_PROC_FILE->owner = THIS_MODULE;
    MY_PROC_FILE->mode = S_IFREG | S_IRUGO;
    MY_PROC_FILE->uid = 0;
    MY_PROC_FILE->gid =0;
    MY_PROC_FILE->size=37;
      
    printk(KERN_INFO "/proc/%s is created\n",PROCFS_NAME);
    return 0;
}


static void __exit procfs_exit(void)
{
     remove_proc_entry(PROCFS_NAME, &proc_root);
     printk(KERN_INFO "/proc/%s has been removed\n",PROCFS_NAME);
}


module_init(procfs_init);
module_exit(procfs_exit);
