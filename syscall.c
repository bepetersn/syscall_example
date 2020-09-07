
#include <linux/kernel.h>
#include <linux/linkage.h> 
#include <include/asm/uaccess.h>

asmlinkage long cs3753_add(int a, int b, int *dest)
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

