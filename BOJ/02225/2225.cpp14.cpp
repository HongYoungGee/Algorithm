#include <iostream>
#define maxNum 200

using namespace std;

int cache[maxNum + 3][maxNum + 3] = { 0 };
int sumDisassembly(int N, int K)
{
	if (N == 0 || K==1) return 1; // 초기 조건
	if (cache[N][K] != 0) return cache[N][K]; // DP

	int sum = 0;
	for (int i = 0; i <= N; i++)
		sum = (sum + sumDisassembly(N - i, K - 1)) % 1000000000;

	return cache[N][K] = sum;
}

int main()
{
	int N, K;

	cin >> N>>K;
	cout << sumDisassembly(N,K) << endl;
}