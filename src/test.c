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
	mat2->numbers[2] = 5;
	mat2->numbers[3] = 7;
	vec2 vector1;
	vector1.x = 12;
	vector1.y = 15;
	printf("matrix * vec2, vec2 = .x %f, .y %f\n", vector1.x, vector1.y);
	printf("Matrix (2x2) : \n");
	Matrix.PrintMatrix(mat2);
	Matrix.MultiplyMatrixbyVector2x2(mat2, &vector1);
	printf("Result: vec2 : .x %f, .y %f\n", vector1.x, vector1.y);
}
