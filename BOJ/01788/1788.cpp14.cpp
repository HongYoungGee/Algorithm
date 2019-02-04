#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <algorithm>
#define MOF 1000000000

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
	int n,abn;
	scanf("%d", &n);

	matrix pivo, rest;
	rest.b = 0, rest.c = 0, rest.d = 1;

	abn = abs(n);
	while (abn>1)
	{
		if (abn % 2 == 1)	matrix_mutiply(pivo, &rest);

		matrix_square(&pivo);
		abn /= 2;
	}

	matrix_mutiply(pivo, &rest);
	if (n > 0 || abs(n) % 2 == 1)
	{
		printf("%d\n", 1);
		printf("%d\n", rest.c);
	}
	else if (n == 0)
	{
		printf("%d\n", 0);
		printf("%d\n",0);
	}
	else
	{
		printf("%d\n", -1);
		printf("%d\n", rest.c);
	}

}