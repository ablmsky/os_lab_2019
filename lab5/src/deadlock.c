#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

pthread_mutex_t mut1, mut2, mut3, mut4  = PTHREAD_MUTEX_INITIALIZER;

int globalForSection1, globalForSection2 = 5;

void foo(int* globalS)
{          
    pthread_mutex_lock(&mut1);
    globalS[0]++;
    globalS[1]++;
   // printf("Im %p and im locking foo() now!\nAnd will try launch bar() ...\n", adr);
    printf("Values of Sections is: %d , %d \n", globalS[0],globalS[1]);
    bar(globalS);
}

void bar(int* globalS)
{
   
    pthread_mutex_lock(&mut2);
    globalS[0] --;
    globalS[1] --;
   // printf("Im %p and im locking bar() now!\nAnd will try launch baz()...\n", adr);
    printf("Values of Sections is: %d , %d \n", globalS[0],globalS[1]);
    baz(globalS);
}


void baz(int* globalS)
{
    
    pthread_mutex_lock(&mut3);
    globalS[0] ++;
    globalS[1] --;
    //printf("Im %p and im locking baz() now!\nAnd will try launch foo()...\n", adr);
    printf("Values of Sections is: %d , %d \n", globalS[0],globalS[1]);
    foo(globalS);
}




int main()
{
    int values[2] = {5,5};
    pthread_t thread_1, thread_2, thread_3;
    
    printf("Thread 1 is %p\nThread 2 is %p\nThread 3 is %p\n",
            &thread_1, &thread_2, &thread_3);
    
    
    pthread_create(&thread_1, NULL, foo, (void *)&values);
    pthread_create(&thread_2, NULL, bar, (void *)&values);
    pthread_create(&thread_3, NULL, baz, (void *)&values);
    
    
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    
    
    printf("Done!");
    return 0;
}