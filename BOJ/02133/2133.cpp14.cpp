#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;
#define maxnum 30

int cache[maxnum + 3] = { 1,0,3};
int tileFill(int n)
{
	//f(n) = f(n-2) * 3           이전 조합에서 2줄로 만들수 있는 3개의 경우의수 곱
	//		+f(n-2) - f(n-4)      이전 조합에서 三 으로 끝나지 않는 모형의 갯수 = f(n-4)에서 三을 붙이는것 갯수

	for (int i = 4; i <= n; i += 2)
		cache[i] = cache[i - 2] * 4 - cache[i - 4];

	return cache[n];
}

int main()
{
	int n;
	cin >> n;

	cout << tileFill(n) << endl;
}