#ifndef __VECTOR_H
#define __VECTOR_H
#include <libc.h>
// Vector Implementation 
typedef struct _vec3 {
	float x, y, z;
} vec3;
typedef struct _vec2 {
	float x, y;
} vec2;
typedef struct _vec4 {
	float x, y, z, w;
} vec4;
typedef struct __vector_construct {
	vec2* (*CreateVector2)(float, float);
	vec3* (*CreateVector3)(float, float, float);
	vec4* (*CreateVector4)(float, float, float, float);
	vec2* (*SubtractVector2)(vec2*, vec2*);
	vec3* (*SubtractVector3)(vec3*, vec3*);
} vector_construct;
vector_construct Vector;
#endif
