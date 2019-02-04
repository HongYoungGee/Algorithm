#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;


int d(int n)
{
	int temp = n;

	for (int i = 0; i < (int)log10((double)n) + 1; i++)
		temp += n/(int)(pow((double)10, i)) % 10;

	return temp;
}

int main()
{
    bool arr[10001] = { false };
    
	for (int i = 0; i < 10000; i++)
	{
		int temp = d(i);
		if (temp <= 10000)
			arr[temp] = { true };
	}

	for (int i = 1; i < 10001; i++)
	{
		if (!arr[i])
			printf("%d\n", i);
			
	}
}