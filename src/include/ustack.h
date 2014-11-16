#ifndef __STACK_H
#define __STACK_H
#include <libc.h>
#include <ustring.h>
#define DEFAULT_STACK_SIZE 100 * sizeof(int)
typedef struct __stack {
	int* content;
	int no;
} stack_t;
typedef struct __stack_construct {
	stack_t* (*Create)(void);
	int (*Push)(stack_t*, int);
	int (*Pop)(stack_t*);
	int (*Duplicate)(stack_t*);
	int (*GetItem)(stack_t*, int);
	void (*SetItem)(stack_t*, int, int);
} stack_construct;
stack_construct Stack;
void init_stack_construct(void);
#endif
