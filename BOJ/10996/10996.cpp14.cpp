#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, k = 1;

	cin >> n;

	for (int i = 0; i <n*2; i++) // 마지막 분리
	{
		if (!(i % 2))
		{
			for (int j = 0; j < (n - 1) / 2 + 1; j++)
				printf("* ");
			cout << endl;
		}
		else if(n!=1)
		{
			for (int j = 0; j < n / 2; j++)
				printf(" *");
			cout << endl;
		}	
	}
}