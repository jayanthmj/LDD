/*Implementing module to  update kernel symbol table
*/

#ifndef MODULE
	#define MODULE
#endif 
#ifndef __KERNEL__
	#define __KERNEL__
#endif


#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/init.h>

void func(void);

//EXPORT_SYMBOL(func);
EXPORT_SYMBOL_GPL(func);

int val=300;

void func()
{
	printk("func invoked\n ");
	printk(" val = %d",val);
}	

int myinit(void)
{
	printk("module inserted\n ");
	func();		//by jk
	return 0;
}

void myexit(void)
{
	printk("module removed\n ");
}

module_init(myinit);
module_exit(myexit);

/*Kernel module Comments*/
MODULE_AUTHOR("TEAMENGINEERS");
MODULE_DESCRIPTION("FIRST MODULE");
MODULE_LICENSE("GPL");
//MODULE_LICENSE("GPL v2");
