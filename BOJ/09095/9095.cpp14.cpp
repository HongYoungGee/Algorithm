#include <iostream>

using namespace std;

int cache[100] = {1,1,2, 0 };

int add_1_2_3(int n)
{
	if (cache[n] != 0) return cache[n];

	return cache[n] = add_1_2_3(n - 1) + add_1_2_3(n - 2) + add_1_2_3(n - 3);
}

int main() 
{
	int T,n;
	cin >> T;
	while (T--) { cin >> n; printf("%d\n", add_1_2_3(n)); }
}