/*
 * dll.c
 *
 *  Created on: Aug 13, 2013
 *      Author: ravi
 */
#include <stdlib.h>
#include <stdio.h>
#include "dll.h"

#ifndef NULL
#define NULL 0
#endif

#define DEBUG1

typedef struct dll {
	mythread_t *head;
	mythread_t *tail;
	uint size;
} tDll;
static tDll dll;


int dll_Init(void) {

#ifdef DEBUG1
	printf("dll initialized\n");

#endif
	int retStatus = 0;
	dll.head = NULL;
	dll.tail = NULL;
	dll.size = 0;

	return retStatus;
}

int dll_addtail(mythread_t *pMythread) {

#ifdef DEBUG1
	printf("dll add called\n");
#endif

	int retStatus = 0;

	if (dll.size) {
		(dll.tail)->nextptr = pMythread;
		pMythread->prevptr = dll.tail;
		dll.tail = pMythread;
		dll.tail->nextptr = NULL;

	} else { //size==0
		dll.head = pMythread;
		dll.head->nextptr = NULL;
		dll.head->prevptr = NULL;
		dll.tail = dll.head;

	}
	//increse size of dll
	dll.size++;

#ifdef DEBUG1
	printf("dll.size=%u\n", dll.size);
	if (dll.head != NULL) {
		printf("dll head ID %u\n", dll.head->thread_id);
	} else {
		printf("dll head NULL\n");
	}

	if (dll.tail != NULL) {
		printf("dll tail ID %u\n", dll.tail->thread_id);
	} else {
		printf("dll tail NULL\n");
	}

#endif

	return retStatus;
}
mythread_t * dll_pophead() {

	mythread_t *temp = 0;
	if (dll.size) {
		temp = dll.head;
		dll.head = dll.head->nextptr;
		dll.head->prevptr = NULL;
		temp->nextptr = NULL;
		temp->prevptr = NULL;
		dll.size--;
	} else {
		return 0;
	}

#ifdef DEBUG1
	if (temp != NULL) {
		printf("%s: THread ID %u \n", __FUNCTION__, temp->thread_id);
	} else {
		printf("TEMP NUILL\n");
	}
#endif

	return temp;
}


int dll_DeInit(void) {
	int retStatus = 0;
	return retStatus;
}

void dll_printall(void) {
	int i = 0;
	mythread_t *pthread = dll.head;
	for (i = 0; i < dll.size; i++) {
		if (pthread != NULL) {
			printf("i=%d pthread ID %u\n", i, pthread->thread_id);
			pthread = pthread->nextptr;
		} else {
			printf("i=%d pthread NULL\n", i);
		}
	}
	printf("dll reverse\n");
	pthread = dll.tail;
	for (i = 0; i < dll.size; i++) {
		if (pthread != NULL) {
			printf("i=%d pthread ID %u\n", i, pthread->thread_id);
			pthread = pthread->prevptr;
		} else {
			printf("i=%d pthread NULL\n", i);
		}
	}
}
void dll_printthread(mythread_t *pthread) {
	if (pthread != NULL) {
		printf("%s :pthread ID %u\n", __FUNCTION__, pthread->thread_id);
	} else {
		printf("pthread NULL\n");
	}
}
