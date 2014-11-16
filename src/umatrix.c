#include <umatrix.h>
matrix_t* CreateMatrix(int type);
void MultiplyMatrixbyVector2x2(matrix_t* matrix, vec2* vector);
void MultiplyMatrixbyVector3x3(matrix_t* matrix, vec3* vector);
void MultiplyMatrixbyVector4x4(matrix_t* matrix, vec4* vector);
void PrintMatrix(matrix_t* matrix);
void init_matrix_construct(void)
{
	Matrix.CreateMatrix = &CreateMatrix;
	Matrix.MultiplyMatrixbyVector2x2 = &MultiplyMatrixbyVector2x2;
	Matrix.MultiplyMatrixbyVector3x3 = &MultiplyMatrixbyVector3x3;
	Matrix.MultiplyMatrixbyVector4x4 = &MultiplyMatrixbyVector4x4;
	Matrix.PrintMatrix = &PrintMatrix;
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
void MultiplyMatrixbyVector2x2(matrix_t* matrix, vec2* vector)
{
	if(matrix->type != MATRIX_2x2) { printf("vec2 multiplication not supported with types other than 2x2 (for now)\n");
	return;
	}
	float save_x = vector->x;
	float save_y = vector->y;
	vector->x = save_x * matrix->numbers[0];
	vector->x += save_y * matrix->numbers[1];
	
	vector->y = save_x * matrix->numbers[2];
	vector->y += save_y * matrix->numbers[3];
}
void MultiplyMatrixbyVector3x3(matrix_t* matrix, vec3* vector)
{
	if(matrix->type != MATRIX_3x3) { printf("vec3 multiplication not supported with types other than 2x2 (for now)\n");
	return;
	}
	float save_x = vector->x;
	float save_y = vector->y;
	float save_z = vector->z;
	vector->x = save_x * matrix->numbers[0];
	vector->x += save_y * matrix->numbers[1];
	vector->x += save_z * matrix->numbers[2];
	
	vector->y = save_x * matrix->numbers[3];
	vector->y += save_y * matrix->numbers[4];
	vector->y += save_z * matrix->numbers[5];
	
	vector->z = save_x * matrix->numbers[6];
	vector->z += save_y * matrix->numbers[7];
	vector->z += save_z * matrix->numbers[8];
}
void MultiplyMatrixbyVector4x4(matrix_t* matrix, vec4* vector)
{
	if(matrix->type != MATRIX_4x4) { printf("vec4 multiplication not supported with types other than 2x2 (for now)\n");
	return;
	}
	float save_x = vector->x;
	float save_y = vector->y;
	float save_z = vector->z;
	float save_w = vector->w;
	vector->x = vector->x * matrix->numbers[0];
	vector->x += vector->y * matrix->numbers[1];
	vector->x += vector->z * matrix->numbers[2];
	vector->x += vector->w * matrix->numbers[3];
	
	vector->y = save_x * matrix->numbers[4];
	vector->y += save_y * matrix->numbers[5];
	vector->y += save_z * matrix->numbers[6];
	vector->y += save_w * matrix->numbers[7];
	
	vector->z = save_x * matrix->numbers[8];
	vector->z += save_y * matrix->numbers[9];
	vector->z += save_z * matrix->numbers[10];
	vector->z += save_w * matrix->numbers[11];
	
	vector->w = save_x * matrix->numbers[12];
	vector->w += save_y * matrix->numbers[13];
	vector->w += save_z * matrix->numbers[14];
	vector->w += save_w * matrix->numbers[15];
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
		printf("print_matrix: Unknown Matrix type");
	}
}
