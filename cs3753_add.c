
#include <linux/kernel.h>
#include <linux/linkage.h> 
#include <linux/uaccess.h>

asmlinkage long sys_cs3753_add(int a, int b, int *dest)
{
    // use printk() to log the numbers to be added
    printk("Going to add %d and %d", a, b);
    // add those two numbers 
    int sum = a + b;
    // store the result
    put_user(sum, *dest);
    // use printk() to log the result
    printk("Sum: %d", sum);
    // return an appropriate return value
    return 0;
}

