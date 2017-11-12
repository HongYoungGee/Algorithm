#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long cache[118] = { 0,1,1,1,0 };
unsigned long long likePivonachi(int n)
{
	if (cache[n] != 0) return cache[n];

	return cache[n] = likePivonachi(n - 1)  + likePivonachi(n-3);
}


int main()
{
	int n;
	scanf("%d", &n);

	printf("%llu\n", likePivonachi(n));
	
}