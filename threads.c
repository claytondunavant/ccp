#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;

void * increment(void * vmax) {
    
    int * max;
    max = (int *) vmax;
    
    int tmp;
    for (int i = 0; i < *max; i++) {
        //tmp = counter;
        //tmp++;
        //counter = tmp;
        counter++;
    }

    // return values
    int * ret = calloc(1, sizeof(int *));
    *ret = 10;
    pthread_exit(ret); 
}

int main(int argc, char * argv[]) {
    
    /*
    each thread has its own
    - stack
    - program counter
    - set of registers
    - state
    */
    
    pthread_t t1, t2;
    
    // TODO how to turn non-pointer into pointer and back

    int * vmax = calloc(1, sizeof(int *));
    *vmax = 1000000;
    pthread_create(&t1, NULL, increment, (void *) vmax);
    pthread_create(&t2, NULL, increment, (void *) vmax);
    
    // int pthread_join(pthread_t thread, void **retval);
    int * t1Ret;
    int * t2Ret;
    pthread_join(t1, (void **) &t1Ret);
    pthread_join(t2, (void **) &t2Ret);

    printf("counter total=%d\nt1Ret= %d\nt2Ret= %d\n", counter, *t1Ret, *t2Ret);

    return 0;
}