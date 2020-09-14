
#include <linux/kernel.h>
#include <linux/linkage.h> 
#include <linux/uaccess.h>

asmlinkage long sys_cs3753_add(int a, int b, int *dest)
{
    int sum;
    // use printk() to log the numbers to be added
    printk("Going to add %d and %d\n", a, b);
    // add those two numbers 
    sum = a + b;
    // store the result
    put_user(sum, dest);
    // use printk() to log the result
    printk("Sum: %d\n", sum);
    // return an appropriate return value
    return 0;
}

