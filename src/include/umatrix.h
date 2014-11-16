#ifndef __UMATRIX_H
#define __UMATRIX_H
#include <libc.h>
#include <uvector.h>
#define MATRIX_2x2 2
#define MATRIX_3x3 3
#define MATRIX_4x4 4
#define MATRIX_MAX_INT 4 * 4
typedef struct _matrix {
	float numbers[MATRIX_MAX_INT];
	int type;
} matrix_t;
typedef struct __matrix_construct {
	matrix_t* (*CreateMatrix)(int);
	vec2* (*MultiplyMatrixbyVector2x2)(matrix_t*, vec2*);
	vec3* (*MultiplyMatrixbyVector3x3)(matrix_t*, vec3*);
	vec4* (*MultiplyMatrixbyVector4x4)(matrix_t*, vec4*);
	matrix_t* (*MultiplyMatrixbyMatrix2x2)(matrix_t*, matrix_t*);
	matrix_t* (*MultiplyMatrixbyMatrix3x3)(matrix_t*, matrix_t*);
	matrix_t* (*MultiplyMatrixbyMatrix4x4)(matrix_t*, matrix_t*);
	void (*PrintMatrix)(matrix_t*);
	matrix_t IdentityMatrix2x2;
	matrix_t IdentityMatrix3x3;
	matrix_t IdentityMatrix4x4;
} matrix_construct;
matrix_construct Matrix;
void init_matrix_construct(void);
#endif
