
#include <unistd.h>
// This ^ gives access to syscall()
#include <stdio.h>

const int CS3753_ADD = 548;

int main(int argc, char *argv[]) 
{
    int sum;
    int result = syscall(CS3753_ADD/*, 4, 5, &sum*/);
    printf("Got result: %d\n", sum);
    return result;
}
