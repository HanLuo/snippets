#include <stdlib.h>
#include <stdio.h>

static void atexitFunc1(void)
{
    printf("atexit function 1 called\n");
}

static void atexitFunc2(void)
{
    printf("atexit function 2 called\n");
}

static void onexitFunc(int exitStatus, void *arg)
{
    printf("on_exit function called: status=%d, arg=%ld\n",
           exitStatus,
           (long) arg);
}

int main()
{
    if (on_exit(onexitFunc, (void *) 10) != 0)
        printf("error on_exit 1");

    if (atexit(atexitFunc1)!= 0)
        printf("error atexit 1");

    if (atexit(atexitFunc2)!= 0)
        printf("error atexit 2");

    if (on_exit(onexitFunc,(void *) 20) != 0)
        printf("error on_exit 2");

    exit(2);
}
