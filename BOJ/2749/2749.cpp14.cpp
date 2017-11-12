#include <iostream>
#include <vector>
#include <algorithm>
#define MOF 1000000

using namespace std;

struct matrix
{
	unsigned long long a=1, b=1, c=1, d=0;
};

void matrix_square(matrix *pivo)
{
	matrix temp = *pivo;

	pivo->a = (temp.a*temp.a + temp.b*temp.c) % MOF;
	pivo->b = (temp.a*temp.b+ temp.b*temp.d) % MOF;
	pivo->c = (temp.c*temp.a + temp.d*temp.c) % MOF;
	pivo->d = (temp.c*temp.b + temp.d*temp.d) % MOF;
}

void matrix_mutiply(matrix pivo, matrix *rest)
{
	matrix temp = *rest;


	rest->a = (pivo.a*temp.a + pivo.b*temp.c) % MOF;
	rest->b = (pivo.a*temp.b + pivo.b*temp.d) % MOF;
	rest->c = (pivo.c*temp.a + pivo.d*temp.c) % MOF;
	rest->d = (pivo.c*temp.b + pivo.d*temp.d) % MOF;
}

int main()
{
	unsigned long long n;
	scanf("%llu", &n);

	matrix pivo, rest;
	rest.b = 0, rest.c = 0, rest.d = 1;

	while (n>1)
	{
		if (n % 2 == 1)	matrix_mutiply(pivo, &rest);

		matrix_square(&pivo);
		n /= 2;
	}

	matrix_mutiply(pivo, &rest);
	printf("%d\n", rest.c);
}