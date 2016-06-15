#include <stdio.h>

typedef unsigned long ULONG;

typedef struct tagMatrix2x2
{
	ULONG data[2][2];
} Matrix2x2;

Matrix2x2 Matrix2x2_Multiply(Matrix2x2 A, Matrix2x2 B)
{
	Matrix2x2 c;

	c.data[0][0] = A.data[0][0] * B.data[0][0] + A.data[0][1] * B.data[1][0];
	c.data[0][1] = A.data[0][0] * B.data[1][0] + A.data[0][1] * B.data[1][1];

	c.data[1][0] = A.data[1][0] * B.data[0][0] + A.data[1][1] * B.data[1][0];
	c.data[1][1] = A.data[1][0] * B.data[1][0] + A.data[1][1] * B.data[1][0];

	return c;
}

Matrix2x2 Matrix2x2_Power(Matrix2x2 A, int n)
{
	if (n > 1)
	{
		A = Matrix2x2_Power(A, n / 2);
		A = Matrix2x2_Multiply(A, A);

		if (n & 1)
		{
			Matrix2x2 B;
			B.data[0][0] = 1; B.data[0][1] = 1;
			B.data[1][0] = 1; B.data[1][1] = 0;

			A = Matrix2x2_Multiply(A, B);
		}
	}

	return A;
}

ULONG Fibonacci(int N)
{
	Matrix2x2 A;

	A.data[0][0] = 1; A.data[0][1] = 1;
	A.data[1][0] = 1; A.data[1][1] = 0;

	A = Matrix2x2_Power(A, N);

	return A.data[0][1];
}

int main()
{
	int N = 46;
	ULONG Result = Fibonacci(N);

	printf("Fibonacci(%d) = %lu\n", N, Result);

	return 0;
}