#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, a, b;

	cin >> n;

	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < n-i; j++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}

}

