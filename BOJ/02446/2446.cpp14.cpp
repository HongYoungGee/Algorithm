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
		for (int j = 0; j < n-1-abs(i-n); j++)
			printf(" ");
		for (int j = 0; j < abs(n - i)*2+1; j++)
			printf("*");
		printf("\n");
	}

}

