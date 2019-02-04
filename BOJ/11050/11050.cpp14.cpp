#include <iostream>
#include <vector>

using namespace std;

#define Max_size 105 // The maximum size of a.
int cache[Max_size][Max_size] = { 0 };

int combination(int a, int b) // Compute aCb
{
	if (cache[a][b] != 0) return cache[a][b]; //cache hit

	if (a == b || b == 0) return cache[a][b] = 1; // nCn or nC0 = 1
	if (b == 1) return cache[a][b] = a;  // nC1 = n

	return cache[a][b] = (combination(a - 1, b) + combination(a - 1, b - 1));
}

int main()
{
	int n, m;
	cin >> n >> m;

	printf("%d\n", combination(n, m));

}