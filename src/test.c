#include <libc.h>
#include <umain.h>
#include <uvector.h>
#include <umatrix.h>
int main(void)
{
	init_ulib();
	matrix_t* mat2 = Matrix.CreateMatrix(MATRIX_2x2);
	mat2->numbers[0] = 1;
	mat2->numbers[1] = 2;
	mat2->numbers[2] = 3;
	mat2->numbers[3] = 7;
	matrix_t* mat1 = Matrix.CreateMatrix(MATRIX_2x2);
	mat1->numbers[0] = 4;
	mat1->numbers[1] = 7;
	mat1->numbers[2] = 5;
	mat1->numbers[3] = 8;
	vec2 vector1;
	vector1.x = 12;
	vector1.y = 15;
	printf("matrix * vec2, vec2 = .x %f, .y %f\n", vector1.x, vector1.y);
	printf("Matrix (2x2) : \n");
	Matrix.PrintMatrix(mat2);
	vec2* vectorr = Matrix.MultiplyMatrixbyVector2x2(mat2, &vector1);
	printf("Result: vec2 : .x %f, .y %f\n", vectorr->x, vectorr->y);
	matrix_t* mat2_r = Matrix.MultiplyMatrixbyMatrix2x2(mat2, mat1);
	Matrix.PrintMatrix(mat2_r);
	matrix_t* mat3_1 = Matrix.CreateMatrix(MATRIX_3x3);
	matrix_t* mat3_2 = Matrix.CreateMatrix(MATRIX_3x3);
	mat3_1->numbers[0] = 4;	
	mat3_1->numbers[1] = 5;
	mat3_1->numbers[2] = 23;
	mat3_1->numbers[3] = 1;
	mat3_1->numbers[4] = 4;	
	mat3_1->numbers[5] = 6;
	mat3_1->numbers[6] = 12;
	mat3_1->numbers[7] = 0;
	mat3_1->numbers[8] = 11;
	
	mat3_2->numbers[0] = 4;	
	mat3_2->numbers[1] = 5;
	mat3_2->numbers[2] = 23;
	mat3_2->numbers[3] = 1;
	mat3_2->numbers[4] = 4;	
	mat3_2->numbers[5] = 6;
	mat3_2->numbers[6] = 12;
	mat3_2->numbers[7] = 0;
	mat3_2->numbers[8] = 11;
	
	matrix_t* mat3_r = Matrix.MultiplyMatrixbyMatrix3x3(mat3_1, mat3_2);
	Matrix.PrintMatrix(mat3_r);
}
