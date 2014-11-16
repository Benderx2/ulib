#include <umatrix.h>
matrix_t* CreateMatrix(int type);
vec2* MultiplyMatrixbyVector2x2(matrix_t* matrix, vec2* vector);
vec3* MultiplyMatrixbyVector3x3(matrix_t* matrix, vec3* vector);
vec4* MultiplyMatrixbyVector4x4(matrix_t* matrix, vec4* vector);
matrix_t* MultiplyMatrixbyMatrix2x2(matrix_t* matrix1, matrix_t* matrix2);
matrix_t* MultiplyMatrixbyMatrix3x3(matrix_t* matrix1, matrix_t* matrix2);
void PrintMatrix(matrix_t* matrix);
void init_matrix_construct(void)
{
	Matrix.CreateMatrix = &CreateMatrix;
	Matrix.MultiplyMatrixbyVector2x2 = &MultiplyMatrixbyVector2x2;
	Matrix.MultiplyMatrixbyVector3x3 = &MultiplyMatrixbyVector3x3;
	Matrix.MultiplyMatrixbyVector4x4 = &MultiplyMatrixbyVector4x4;
	Matrix.PrintMatrix = &PrintMatrix;	
	Matrix.MultiplyMatrixbyMatrix2x2 = &MultiplyMatrixbyMatrix2x2;
	Matrix.MultiplyMatrixbyMatrix3x3 = &MultiplyMatrixbyMatrix3x3;
	// Create identity matrices
	// 2x2 :
	// 1 0 
	// 0 1
	// 3x3 :
	// 1 0 0
	// 0 1 0
	// 0 0 1
	// 4x4 :
	// 1 0 0 0 
	// 0 1 0 0
	// 0 0 1 0 
	// 0 0 0 1 
	// 2x2
	Matrix.IdentityMatrix2x2.numbers[0] = 1;
	Matrix.IdentityMatrix2x2.numbers[1] = 0;

	Matrix.IdentityMatrix2x2.numbers[2] = 0;
	Matrix.IdentityMatrix2x2.numbers[3] = 1;
	
	Matrix.IdentityMatrix2x2.type = MATRIX_2x2;
	// 3x3
	Matrix.IdentityMatrix3x3.numbers[0] = 1;
	Matrix.IdentityMatrix3x3.numbers[1] = 0;
	Matrix.IdentityMatrix3x3.numbers[2] = 0;

	Matrix.IdentityMatrix3x3.numbers[3] = 0;
	Matrix.IdentityMatrix3x3.numbers[4] = 1;
	Matrix.IdentityMatrix3x3.numbers[5] = 0;
	
	Matrix.IdentityMatrix3x3.numbers[6] = 0;
	Matrix.IdentityMatrix3x3.numbers[7] = 0;
	Matrix.IdentityMatrix3x3.numbers[8] = 1;

	Matrix.IdentityMatrix3x3.type = MATRIX_3x3;
	// 4x4
	Matrix.IdentityMatrix4x4.numbers[0] = 1;
	Matrix.IdentityMatrix4x4.numbers[1] = 0;
	Matrix.IdentityMatrix4x4.numbers[2] = 0;
	Matrix.IdentityMatrix4x4.numbers[3] = 0;
	
	Matrix.IdentityMatrix4x4.numbers[4] = 0;
	Matrix.IdentityMatrix4x4.numbers[5] = 1;
	Matrix.IdentityMatrix4x4.numbers[6] = 0;
	Matrix.IdentityMatrix4x4.numbers[7] = 0;
	
	Matrix.IdentityMatrix4x4.numbers[8] = 0;
	Matrix.IdentityMatrix4x4.numbers[9] = 0;
	Matrix.IdentityMatrix4x4.numbers[10] = 1;
	Matrix.IdentityMatrix4x4.numbers[11] = 0;
	
	Matrix.IdentityMatrix4x4.numbers[12] = 0;
	Matrix.IdentityMatrix4x4.numbers[13] = 0;
	Matrix.IdentityMatrix4x4.numbers[14] = 0;
	Matrix.IdentityMatrix4x4.numbers[15] = 1;

	Matrix.IdentityMatrix4x4.type = MATRIX_4x4;
}
matrix_t* CreateMatrix(int type)
{
	printf("sizeof(matrix_t) = %d\n", (int)sizeof(matrix_t));
	matrix_t* new_matrix = (matrix_t*)malloc(sizeof(matrix_t));
	switch(type)
	{
		case MATRIX_2x2:
			new_matrix->type = MATRIX_2x2;
			break;
		case MATRIX_3x3:
			new_matrix->type = MATRIX_3x3;
			break;
		case MATRIX_4x4:
			new_matrix->type = MATRIX_4x4;
			break;
		default:
			printf("Error : Unknown matrix type -> %x", type);
			free(new_matrix);
			return NULL;
	}
	return new_matrix;
}
vec2* MultiplyMatrixbyVector2x2(matrix_t* matrix, vec2* vector)
{
	if(matrix->type != MATRIX_2x2) { printf("vec2 multiplication not supported with types other than 2x2 (for now)\n");
	return NULL;
	}
	vec2* vector1 = (vec2*)malloc(sizeof(vec2));
	float save_x = vector->x;
	float save_y = vector->y;
	vector1->x = save_x * matrix->numbers[0];
	vector1->x += save_y * matrix->numbers[1];
	
	vector1->y = save_x * matrix->numbers[2];
	vector1->y += save_y * matrix->numbers[3];
	return vector1;
}
vec3* MultiplyMatrixbyVector3x3(matrix_t* matrix, vec3* vector)
{
	if(matrix->type != MATRIX_3x3) { printf("vec3 multiplication not supported with types other than 3x3 (for now)\n");
	return NULL;
	}
	vec3* vector1 = (vec3*)malloc(sizeof(vec3));
	float save_x = vector->x;
	float save_y = vector->y;
	float save_z = vector->z;
	vector1->x = save_x * matrix->numbers[0];
	vector1->x += save_y * matrix->numbers[1];
	vector1->x += save_z * matrix->numbers[2];
	
	vector1->y = save_x * matrix->numbers[3];
	vector1->y += save_y * matrix->numbers[4];
	vector1->y += save_z * matrix->numbers[5];
	
	vector1->z = save_x * matrix->numbers[6];
	vector1->z += save_y * matrix->numbers[7];
	vector1->z += save_z * matrix->numbers[8];
	return vector1;
}
vec4* MultiplyMatrixbyVector4x4(matrix_t* matrix, vec4* vector)
{
	if(matrix->type != MATRIX_4x4) { printf("vec4 multiplication not supported with types other than 4x4 (for now)\n");
	return NULL;
	}
	vec4* vector1 = (vec4*)malloc(sizeof(vec4));
	float save_x = vector->x;
	float save_y = vector->y;
	float save_z = vector->z;
	float save_w = vector->w;
	vector1->x = vector->x * matrix->numbers[0];
	vector1->x += vector->y * matrix->numbers[1];
	vector1->x += vector->z * matrix->numbers[2];
	vector1->x += vector->w * matrix->numbers[3];
	
	vector1->y = save_x * matrix->numbers[4];
	vector1->y += save_y * matrix->numbers[5];
	vector1->y += save_z * matrix->numbers[6];
	vector1->y += save_w * matrix->numbers[7];
	
	vector1->z = save_x * matrix->numbers[8];
	vector1->z += save_y * matrix->numbers[9];
	vector1->z += save_z * matrix->numbers[10];
	vector1->z += save_w * matrix->numbers[11];
	
	vector1->w = save_x * matrix->numbers[12];
	vector1->w += save_y * matrix->numbers[13];
	vector1->w += save_z * matrix->numbers[14];
	vector1->w += save_w * matrix->numbers[15];
	
	return vector1;
}
matrix_t* MultiplyMatrixbyMatrix2x2(matrix_t* matrix1, matrix_t* matrix2)
{
	if(matrix1->type == MATRIX_2x2 && matrix2->type == MATRIX_2x2)
	{
		matrix_t* matrix3 = (matrix_t*)malloc(sizeof(matrix_t));
		float a1 = matrix1->numbers[0];
		float b1 = matrix1->numbers[1];
		float c1 = matrix1->numbers[2];
		float d1 = matrix1->numbers[3];
		float a2 = matrix2->numbers[0];
		float b2 = matrix2->numbers[1];
		float c2 = matrix2->numbers[2];
		float d2 = matrix2->numbers[3];
		/*
		a1 b1       a2 b2      (a1*a2)+(b1*c2) (a1*b2)+(b1*c2)
			x          =
		c1 d1	    c2 d2      (c1*a2)+(d1*c2) (c1*b2)+(d1*d2)
		*/
		matrix3->numbers[0] = a1 * a2 + b1 * c2;
		matrix3->numbers[1] = a1 * b2 + b1 * d2;
		matrix3->numbers[2] = c1 * a2 + d1 * c2;
		matrix3->numbers[3] = c1 * b2 + d1 * d2;
		matrix3->type = MATRIX_2x2;
		return matrix3;
	}
	else {
		printf("multiply_matrix_2x2: One matrix isn't a 2x2 matrix!\n");
		return NULL;
	}
}
matrix_t* MultiplyMatrixbyMatrix3x3(matrix_t* matrix1, matrix_t* matrix2)
{
	if(matrix1->type == MATRIX_3x3 && matrix2->type == MATRIX_3x3)
	{
		/*
		a1 b1 c1   a2 b2 c2    (a1*a2)+(b1*d2)+(c1*g2) (a1*b2)+(b1*e2)+(c1*h2) (a1*c2)+(b1*f2)+(c1*i2)
		d1 e1 f1 x d2 e2 f2 =  (d1*a2)+(e1*d2)+(f1*g2) (d1*b2)+(e1*e2)+(f1*h2) (d1*c2)+(e1*f2)+(f1*i2)
		g1 h1 i1   g2 h2 i2    (g1*a2)+(h1*d2)+(i1*g2) (g1*b2)+(h1*e2)+(i1*h2) (g1*c2)+(h1*f2)+(i1*i2)
		*/
		matrix_t* matrix3 = (matrix_t*)malloc(sizeof(matrix_t));
		
		float a1 = matrix1->numbers[0];
		float b1 = matrix1->numbers[1];
		float c1 = matrix1->numbers[2];
		float d1 = matrix1->numbers[3];
		float e1 = matrix1->numbers[4];
		float f1 = matrix1->numbers[5];
		float g1 = matrix1->numbers[6];
		float h1 = matrix1->numbers[7];
		float i1 = matrix1->numbers[8];

		float a2 = matrix2->numbers[0];
		float b2 = matrix2->numbers[1];
		float c2 = matrix2->numbers[2];
		float d2 = matrix2->numbers[3];
		float e2 = matrix2->numbers[4];
		float f2 = matrix2->numbers[5];
		float g2 = matrix2->numbers[6];
		float h2 = matrix2->numbers[7];
		float i2 = matrix2->numbers[8];

		matrix3->numbers[0] = (a1*a2)+(b1*d2)+(c1*g2);
		matrix3->numbers[1] = (a1*b2)+(b1*e2)+(c1*h2);
		matrix3->numbers[2] = (a1*c2)+(b1*f2)+(c1*i2);
		matrix3->numbers[3] = (d1*a2)+(e1*d2)+(f1*g2);
		matrix3->numbers[4] = (d1*b2)+(e1*e2)+(f1*h2);
		matrix3->numbers[5] = (d1*c2)+(e1*f2)+(f1*i2);
		matrix3->numbers[6] = (g1*a2)+(h1*d2)+(i1*g2);
		matrix3->numbers[7] = (g1*b2)+(h1*e2)+(i1*h2);
		matrix3->numbers[8] = (g1*c2)+(h1*f2)+(i1*i2);
		matrix3->type = MATRIX_3x3;
		return matrix3;
	} 
	else {
		printf("multiply_matrix_3x3: One matrix isn't a 3x3 matrix!\n");
		return NULL;
	}
}
void PrintMatrix(matrix_t* matrix)
{
	if(matrix->type == MATRIX_2x2)
	{
		printf("%f ", matrix->numbers[0]);
		printf("%f\n", matrix->numbers[1]);
		printf("%f ", matrix->numbers[2]);
		printf("%f\n", matrix->numbers[3]);
	}
	else if(matrix->type == MATRIX_3x3)
	{
		printf("%f ", matrix->numbers[0]);
		printf("%f ", matrix->numbers[1]);
		printf("%f\n", matrix->numbers[2]);
		printf("%f ", matrix->numbers[3]);
		printf("%f ", matrix->numbers[4]);
		printf("%f\n", matrix->numbers[5]);
		printf("%f ", matrix->numbers[6]);
		printf("%f ", matrix->numbers[7]);
		printf("%f\n", matrix->numbers[8]);
	}
	else if(matrix->type == MATRIX_4x4)
	{
		printf("%f ", matrix->numbers[0]);
		printf("%f ", matrix->numbers[1]);
		printf("%f ", matrix->numbers[2]);
		printf("%f\n", matrix->numbers[3]);
		printf("%f ", matrix->numbers[4]);
		printf("%f ", matrix->numbers[5]);
		printf("%f ", matrix->numbers[6]);
		printf("%f\n", matrix->numbers[7]);
		printf("%f ", matrix->numbers[8]);
		printf("%f ", matrix->numbers[9]);
		printf("%f ", matrix->numbers[10]);
		printf("%f\n", matrix->numbers[11]);
		printf("%f ", matrix->numbers[12]);
		printf("%f ", matrix->numbers[13]);
		printf("%f ", matrix->numbers[14]);
		printf("%f\n", matrix->numbers[15]);
	}
	else {
		printf("print_matrix: Unknown Matrix type\n");
	}
}
