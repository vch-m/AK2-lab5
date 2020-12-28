#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/errno.h>
#include "hello1.h"



extern int print_hello(uint);

static uint count = 1;

MODULE_AUTHOR("Malashkin Viacheslav");
MODULE_DESCRIPTION("Hello2 advanced, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

module_param(count, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(count,  "The parameter shows how many times the message will be displayed.");

static int __init hello2_init(void){
	return print_hello(count);
}

static void __exit hello2_exit(void){}

module_init(hello2_init);
module_exit(hello2_exit);

