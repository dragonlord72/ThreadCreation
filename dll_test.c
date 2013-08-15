/*
 * dll_test.c
 *
 *  Created on: Aug 13, 2013
 *      Author: ravi
 */

#include <stdlib.h>
#include <stdio.h>
#include "dll.h"
/*
 * gcc dll_test.c -o dll_test
 *
 * */

int main(int argc, char**argv) {

	printf("Hello World\n");
	dll_Init();
	/*mythread_t threads[10];
	 int i=0;
	 for(i=0;i<10;i++){

	 threads[i].thread_id=10-(i);
	 dll_add(&threads[i]);
	 }
	 */
	int i = 0;
	for (i = 0; i < 10; i++) {
		mythread_t *thread = (mythread_t *) malloc(sizeof(mythread_t));
		thread->thread_id = 10 - (i);
		dll_addtail(thread);
	}

	dll_printall();
//	mythread_t *thread = (mythread_t *) malloc(sizeof(mythread_t));
	mythread_t *thread = dll_pophead();
	dll_printthread(thread);
	dll_addtail(thread);
//	dll_printall();
	thread = dll_pophead();

	dll_printthread(thread);
	dll_addtail(thread);

	thread = dll_pophead();
	thread = dll_pophead();
	thread = dll_pophead();
	thread = dll_pophead();
	dll_printthread(thread);
	dll_printall();

	return 0;

}
