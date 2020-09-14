
/* Be sure to call the built version of this
   file with two small-ish integer arguments,
   or the behavior is undefined. Thanks, sorry! */

#include <unistd.h>
// This ^ gives access to syscall()
#include <stdio.h>
// ^ For printf()
#include <stdlib.h>
// ^ For atoi()

const int CS3753_ADD = 548;

int main(int argc, char *argv[]) 
{
    int a;
    int b;
    int sum;
    int result;

    // NOTE: SIG_SEGV on not enough arguments
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if(a && b) {
        result = syscall(CS3753_ADD, a, b, &sum);
        printf("Got result: %d\n", sum);
        return result;
    } else {
        printf("Something went wrong.\n");
    }
}
