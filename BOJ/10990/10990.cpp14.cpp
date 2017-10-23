#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, k = 1;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < abs(n - i); j++)
			printf(" ");
		printf("*");
		if (i != 1 && i != n * 2 - 1)
		{
			for (int j = 0; j < (n-2-abs(i-n))*2+1; j++)
				printf(" ");
			printf("*");
		}
		cout << endl;
	}
}