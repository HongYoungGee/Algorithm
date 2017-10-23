#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, k = 1;

	cin >> n;

	for (int i = 1; i < n; i++) // 마지막 분리
	{
		for (int j = 0; j < abs(n - i); j++)
			printf(" ");
		printf("*");
		if (i != 1)
		{
			for (int j = 0; j < 2*i-3; j++)
				printf(" ");
			printf("*");
		}
		cout << endl;
	}
	for (int i = 0; i < 2 * n - 1; i++) // 마지막 분리
		printf("*");
	cout << endl;
}