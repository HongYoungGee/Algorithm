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
		for (int j = 0; j < n; j++)
			printf("*");
		cout << endl;
	}
	
}