#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int ascending(int n)  //2*n 의 직사각형을 채우는 방법의 수
{
	int arr[10] = { 1,1,1,1,1,1,1,1,1,1 };
	for (int i = 1; i <= n; i++)
		for (int j = 8; j >= 0; j--)
			arr[j] =(arr[j] + arr[j + 1]) % 10007;

	return arr[0];
}

int main()
{
	int n;
	cin >> n;

	cout << ascending(n) << endl;
}