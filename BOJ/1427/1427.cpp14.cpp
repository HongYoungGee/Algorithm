#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, arr[10] = { 0 },temp;
	
	cin >> n;

	while (n>0)
	{
		arr[n%10]++;
		n /= 10;
	}

	for (int i = 9; i >= 0; i--)
	{
		while (arr[i])
		{
			printf("%d", i);
			arr[i]--;
		}
	}
}