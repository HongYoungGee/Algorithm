#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, k = 1;

	cin >> n;

	for (int i = 1; i <=n; i++) // 마지막 분리
	{
		if( !(i%2))
			printf(" ");
		for (int j = 0; j < n; j++)
			printf("* ");
		cout << endl;
	}
}