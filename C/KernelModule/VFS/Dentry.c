#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/list.h>
#include <linux/dcache.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("mudongliangabcd@gmail.com");
MODULE_DESCRIPTION("HelloWorld Module Template");
MODULE_VERSION("0.1");

static char *systype = "ext4";
module_param(systype,charp,0);

static int __init moduletest_init(void)
{
	// copy from /proc/filesystems
	struct file_system_type *file_sys;
	struct super_block *ssb;
	struct inode *ino;
	struct dentry *dty;
	file_sys = get_fs_type(systype);
	hlist_for_each_entry(ssb, &(file_sys->fs_supers), s_instances){
		printk(KERN_ALERT "dev_t = %d, %d\n", MAJOR(ssb->s_dev), MINOR(ssb->s_dev));
		printk(KERN_ALERT "name = %s\n", ssb->s_type->name);
		list_for_each_entry(ino, &(ssb->s_inodes), i_sb_list){
			if ( ino->i_nlink >= 5 ){
				printk(KERN_ALERT "ino = %ld, nlink = %d\n", ino->i_ino, ino->i_nlink);
				hlist_for_each_entry(dty, &(ino->i_dentry), d_u.d_alias){
					printk(KERN_ALERT "dentry name = %s inode = %ld\n", dty->d_name.name, dty->d_inode->i_ino);
				}
				break;
			}
		}
	}
    return 0;
}

static void __exit moduletest_exit(void)
{
    printk(KERN_ALERT "Goodbye,World!");
}

module_init(moduletest_init);
module_exit(moduletest_exit);
