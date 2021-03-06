#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS     100

void *PrintHello(void *threadid)
{
  long tid;
  tid = (long)threadid;
  for(int i = 0; i<5; i++)
    {
      printf("#%ld=%d\n",tid,i);
    }
  pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0; t<NUM_THREADS; t++){
    printf("creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    if (rc){
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  
    /* Last thing that main() should do */
  pthread_exit(NULL);
}
