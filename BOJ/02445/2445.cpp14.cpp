#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, a, b;

	cin >> n;


	for (int i = 1; i < n*2; i++)
	{
		for (int j = 0; j < n- abs(n - i); j++)
			printf("*");
		for (int j = 0; j < abs(2*n-2*i); j++)
			printf(" ");
		for (int j = 0; j < n - abs(n - i); j++)
			printf("*");
		printf("\n");
	}

}

