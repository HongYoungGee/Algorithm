#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int euclid(int A, int B)
{
	if (B == 0) return A;
	else euclid(B, A%B);
}

int main()
{
	int A, B,GCD;
	cin >> A >> B;

	GCD = euclid(A, B);

	cout << GCD << endl;
	cout << (GCD*(A / GCD)*(B / GCD)) << endl;
}