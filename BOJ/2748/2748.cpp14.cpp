#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long cache[91] = { 0,1,1,2,0 };
unsigned long long pivonachi(int n)
{
	if (n==0 || cache[n] != 0) return cache[n];

	return cache[n] = pivonachi(n - 1) + pivonachi(n - 2);
}


int main()
{
	int n;
	scanf("%d", &n);

	printf("%llu\n", pivonachi(n));
	
}