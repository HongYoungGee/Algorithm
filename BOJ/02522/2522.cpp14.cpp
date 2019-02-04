#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, k = 1;

	cin >> n;

	for (int i = 1; i <= n*2-1; i++)
	{
		for (int j = 0; j < abs(n-i); j++)
			printf(" ");
		for (int j = 0; j < n- abs(n - i); j++)
			printf("*");
		cout << endl;
	}
}