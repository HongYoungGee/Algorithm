#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int T, n, v[5000000];
	cin >> T >> n;

	for (int i = 0; i < T; i++) scanf("%d", v + i);

	nth_element(v, v + n-1, v+T);
	cout << v[n - 1] << endl;
}