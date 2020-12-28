#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("Malashkin Viacheslav");
MODULE_DESCRIPTION("Hello1 advanced, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

int print_hello(uint count){
	if(count == 0){
		pr_warn("Small value of 'count'!\n");
	}else if(count > 5 && count <= 10){
		pr_warn("Big value of 'count'!\n");
	}else if(count > 0 && count <= 5){
		int i = 0;
		for(; i < count; i++){
			pr_alert("Hello, world!\n");
		}
	}else{
		pr_err("Invalid value of 'count'!\n");
		return -EINVAL;	
	}
	
	return 0;
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void){
	pr_info("hello1 init!");
	return 0;
}

static void __exit hello1_exit(void){}

module_init(hello1_init);
module_exit(hello1_exit);

