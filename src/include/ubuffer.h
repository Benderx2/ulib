#ifndef __BUFFER_H
#define __BUFFER_H
#include <libc.h>
#include <ustring.h>
typedef struct buffer {
	char* content;
	int len;
} buffer_t;
typedef struct __sbuf_construct {
	buffer_t* (*CreateBuffer)(int sz);
	void (*ResizeBuffer)(buffer_t*, int);
	void (*CopyToBuffer)(buffer_t*, char*, int, int);
	char* (*GetBufferPointer)(buffer_t*);
	char (*GetItem)(buffer_t*, int);
	void (*SetItem)(buffer_t*, int, int);
} sbuf_construct;
sbuf_construct Buffer; 
void init_buffer_construct(void);
#endif

