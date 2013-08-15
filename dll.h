/*
 * dll.h
 *
 *  Created on: Aug 13, 2013
 *      Author: ravi
 */

#ifndef DLL_H_
#define DLL_H_


#include "mythread.h"
/*Doubly Linked list
 *
 *
 * */

int dll_Init(void);
int dll_addtail(mythread_t *pMythread);
mythread_t *dll_pophead(void);
int dll_DeInit(void);
void dll_printall(void);
#endif /* DLL_H_ */
