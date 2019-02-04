#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cache[500] = { 0,1,1,2,0 };
int pivonachi(int n)
{
	if (n==0 || cache[n] != 0) return cache[n];

	return cache[n] = pivonachi(n - 1) + pivonachi(n - 2);
}


int main()
{
	int n;
	scanf("%d", &n);

	printf("%d\n", pivonachi(n));
	
}