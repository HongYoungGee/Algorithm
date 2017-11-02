#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool Is_prime_number(int n)
{
	if (n <= 1) return false;

	for (int i = 2; (i*i) <= n; i++)
		if (n%i == 0)
			return false;

	return true;
}

int main()
{
	int N,  sum = 0,temp;
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		scanf("%d",&temp);  
		
		if (Is_prime_number(temp))
			sum++;
	}
	
	printf("%d\n", sum);
}