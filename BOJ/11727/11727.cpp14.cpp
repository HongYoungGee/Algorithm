#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int memo[1003] = { 0,1,3 };
int tilling(int n)  //2*n 의 직사각형을 채우는 방법의 수
{
	if (memo[n] > 0) return memo[n]; //dp

	return memo[n]=(tilling(n - 2)*2 + tilling(n - 1)) % 10007; 
}


int main()
{
	int n;
	cin >> n;

	cout << tilling(n) << endl;
}