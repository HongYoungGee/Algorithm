#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, arr[10001] = { 0 },temp;
	
	scanf("%d",&n);

	while (n--)
	{
		scanf("%d",&temp);
		arr[temp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		while (arr[i])
		{
			printf("%d\n", i);
			arr[i]--;
		}
	}
}