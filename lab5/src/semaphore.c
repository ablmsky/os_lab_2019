#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; 
int count = 10;
int values[10] = {1,2,3,4,5,6,7,8,9,10};
sem_t sitems, sremains;

void init() {
  sem_init(&sitems, 0, 1);
  sem_init(&sremains, 0, 1); // 10 spaces
}

int pop() {
  // Wait until there's at least one item
  sem_wait(&sitems);
  int v = values[--count];
   
  printf("Thread 1: Element %d was popped\n", v); 
  sem_post(&sitems);
  return v;
}

int pop_2() {
  // Wait until there's at least one item
  sem_wait(&sitems);
  int v = values[--count];
   
  printf("Thread 2: Element %d was popped\n", v); 
  sem_post(&sitems);
  return v;
}


void push(int v) {
  // Wait until there's at least one space
  sem_wait(&sremains);

  pthread_mutex_lock(&m); // CRITICAL SECTION
  values[count++] = v;
  pthread_mutex_unlock(&m);

  sem_post(&sitems); // Hey world, there's at least one item
    printf("Element %d was pushed\n", v); 
}

void print_array(int* array) {
    for(int i = 0; i < 10; i++) 
        printf("%d ", array[i]);
    printf("Counter at %d\n", count);
}

int main(){
    init();
    print_array(values);
    
    pthread_t thread1, thread2;
    
    while (count != 0)
    {
        pthread_create(&thread1, NULL, (void *)pop, (void *)&count);
        pthread_create(&thread2, NULL, (void *)pop_2, (void *)&count);
        
        pthread_join(thread2, NULL);
        pthread_join(thread1, NULL);
    }
    
  print_array(values);
    return 0;
}