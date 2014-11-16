#ifndef __UMESH_H
#define __UMESH_H
#include <libc.h>
#include <math.h>
#include <ustring.h>
#include <uvector.h>
typedef struct _mesh { 
	vec3* vectors;
	int vec_count;
	string name;
} mesh_t;
typedef struct __mesh_construct {
	mesh_t* (*CreateMesh)(string, int);
	vec3 (*GetVector)(mesh_t*, int);
	void (*ModifyVector)(mesh_t*, int, vec3);
	void (*RenameMesh)(mesh_t*, string);
} mesh_construct;
mesh_construct Mesh;
void init_mesh_construct(void);
#endif
