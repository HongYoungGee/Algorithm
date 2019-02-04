#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

#define maxnum 1000000+3
bool isPrime[maxnum];
vector<int> Prime;

void eratos()
{
	for (int i = 2; i < maxnum; i++)
		isPrime[i] = true;

	for(unsigned long long i = 2; i < maxnum; i++)
		if (isPrime[i])
		{
			Prime.push_back(i);
			for(unsigned long long j= (i*i); j< maxnum; j+=i)
				isPrime[j] = false;
		}
}

void goldbah(int num)
{
	for(int i=0; i<Prime.size(); i++)
		if (isPrime[num - Prime[i]])
		{
			printf("%d = %d + %d\n", num, Prime[i], num - Prime[i]);
			break;
		}
}

int main()
{
	eratos();

	int num;
	scanf("%d", &num);
	while (num != 0)
	{
		goldbah(num);
		scanf("%d", &num);
	}
}