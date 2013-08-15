/*
 * mythread.c
 *
 *  Created on: Aug 8, 2013
 *      Author: ravi
 */

#include "mythread.h"

#include <sched.h> /*for clone()*/



extern int dll_Init(void);
extern int dll_addtail(void);
extern mythread_t *dll_pophead(void);
extern int dll_DeInit(void);

/*
 * mythread_self - thread id of running thread
 */
mythread_t mythread_self(void) {

}
/*
 * mythread_create - prepares context of new_thread_ID as start_func(arg),
 * attr is ignored right now.
 * Threads are activated (run) according to the number of available LWPs
 * or are marked as ready.
 */
int mythread_create(mythread_t *new_thread_ID, mythread_attr_t *attr,
		void * (*start_func)(void *), void *arg) {

	/*1.do the intialization of doubly linked list
	 * 2.create TCB for Idle thread and get tid<add it to keep tracj of all tid>
	 * 3.create TCB for first thread
	 * 4.create wrapper api with void * (*start_func)(void *),void *arg)
	 * 5.check futex API
	 * */
	if (dll.size) {
	}
	return 0;
}

/*
 * mythread_yield - switch from running thread to the next ready one
 */
int mythread_yield(void) {
	/*
	 * check if head==tail in Doubly Linked List
	 * else do futex up for next 1 and futex down for this.
	 *
	 * */
}

/*
 * mythread_join - suspend calling thread if target_thread has not finished,
 * enqueue on the join Q of the target thread, then dispatch ready thread;
 * once target_thread finishes, it activates the calling thread / marks it
 * as ready.
 */
int mythread_join(mythread_t target_thread, void **status) {

	/*
	 * Leave for now
	 *
	 * */
}

/*
 * mythread_exit - exit thread, awakes joiners on return
 * from thread_func and dequeue itself from run Q before dispatching run->next
 */
void mythread_exit(void *retval) {
	/*
	 * Leave for now
	 *
	 * */
}

/*
 * mythread_key_create - thread-specific data key creation
 * The  mythread_key_create()  function shall create a thread-specific data
 * key visible to all threads in  the  process.  Key  values  provided  by
 * mythread_key_create()  are opaque objects used to locate thread-specific
 * data. Although the same key value may be used by different threads, the
 * values  bound  to  the key by mythread_setspecific() are maintained on a
 *per-thread basis and persist for the life of the calling thread.
 */
int mythread_key_create(mythread_key_t *key, void (*destructor)(void*)) {
}

/*
 * mythread_key_delete - thread-specific data key deletion
 * The  mythread_key_delete()  function shall delete a thread-specific data
 * key previously returned by  mythread_key_create().  The  thread-specific
 * data  values  associated  with  key  need  not  be  NULL  at  the  time
 * mythread_key_delete() is called.  It is the responsibility of the appli‐
 * cation  to  free any application storage or perform any cleanup actions
 * for data structures related to the deleted key  or  associated  thread-
 * specific data in any threads{} this cleanup can be done either before or
 * after mythread_key_delete() is called. Any attempt to use key  following
 * the call to mythread_key_delete() results in undefined behavior.
 */
int mythread_key_delete(mythread_key_t key) {
}

/*
 * mythread_getspecific - thread-specific data management
 * The mythread_getspecific() function shall  return  the  value  currently
 * bound to the specified key on behalf of the calling thread.
 */
void *mythread_getspecific(mythread_key_t key) {
}

/*
 * mythread_setspecific - thread-specific data management
 * The  mythread_setspecific()  function  shall associate a thread-specific
 * value with a key obtained via a previous call to  mythread_key_create().
 * Different threads may bind different values to the same key. These val‐
 * ues are typically pointers to blocks of  dynamically  allocated  memory
 *that have been reserved for use by the calling thread.
 */
int mythread_setspecific(mythread_key_t key, const void *value) {
}

/* Defining Stack Size


 Implementation to be done as per specification in the problem

 */

