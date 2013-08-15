/*
 * mythread_test.c
 *
 *  Created on: Aug 8, 2013
 *      Author: ravi
 */


#include "mythread.h"
#include "list.h"
#include "queue.h"
#include "futex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_KEYS 5
#define MAX_THREADS 5

mythread_key_t keys[MAX_KEYS];
struct threadValues {
	int v1;
	int v2;
};

void getData() {
        int i;
        mythread_t tcb;
        for(i=0; i < MAX_KEYS; i++)
        {
                struct threadValues *value = mythread_getspecific(keys[i]);
                printf("\nmythread_getspecific call for key = %d, values=%d %d\n", keys[i], value->v1, value->v2);
                if (value == NULL)
                        printf("\nmythread_setspecific call error for thread = %d", keys[i]);

                tcb = mythread_self();
        }
}


void * printingfunction (void * argument)
{
mythread_t mythread = mythread_self();
printf("this is printing function %d\n",mythread.tid);
}

void *thread_function(void *arg)
{
	int rc, i;
	mythread_t thread,childthread ;
	struct threadValues *value;
	value = (struct threadValues *)arg;
        thread=mythread_self();
        printf("This is thread %d before yielding\n",thread.tid);

	for(i=0; i < MAX_KEYS; i++)
	{
		printf("\nSettig values %d %d for key %d by thread %d", value->v1, value->v2, i, thread.tid);
		rc = mythread_setspecific(keys[i], value);
		if(rc != 0)
		{
			printf("\nmythread_setspecific call error for thread = %d", keys[i]);
		}
	}
	rc=mythread_create(&childthread,NULL,&printingfunction,NULL);
	rc=mythread_yield();
	printf("this is thread %d after yield\n",thread.tid);
	//rc = mythread_yield();
   	getData();
	return NULL;
}


int main(int argc, char **argv)
{
	mythread_t thread[MAX_THREADS];
	int rc=0, i;
	struct threadValues *value;

	for(i=0; i < MAX_KEYS; i++)
	{
		rc = mythread_key_create(&keys[i], NULL);
  		if(rc != 0)
			write(1,"\nmythread_key_create() failed\n",29);
   	}

  	printf("Create threads\n");

	for (i=0; i < MAX_THREADS; ++i)
	{
       		value = (struct threadValues *)malloc(sizeof(struct threadValues));
     		value->v1 = i;
     		value->v2 = i+10;
     		rc = mythread_create(&thread[i], NULL, thread_function, value);
     		if(rc != 0)
			printf("\nmythread_create() call error");
  	}

  	printf("Wait for half the threads to complete\n");
  	for (i=0; i < MAX_THREADS; ++i) {
  		rc = mythread_join(thread[i], NULL);
		if(rc != 0)
	     		printf("\nmythread_join() call error\n", rc);
  	}

	//delete half the keys
	for(i=0; i < MAX_KEYS; i++)
	{
		rc = mythread_key_delete(keys[i]);
		if(rc != 0)
	     		printf("\nmythread_delete() call error\n", rc);
	}
  	printf("Main before exiting\n");

        mythread_exit(0);

	//delete other half of the keys
	for(i=MAX_KEYS/2; i < MAX_KEYS; i++)
		mythread_key_delete(keys[i]);
  	printf("Main after exiting\n");
}
