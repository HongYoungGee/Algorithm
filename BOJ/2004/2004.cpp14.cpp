#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, M, count_2 = 0,count_5=0;
	cin >> N>>M;
	
	for (long long i = 2; i <= N; i *= 2) count_2 += N / i;
	for (long long i = 5; i <= N; i *= 5) count_5 += N / i;

	for (long long i = 2; i <= N-M; i *= 2) count_2 -= (N-M) / i;
	for (long long i = 5; i <= N-M; i *= 5) count_5 -= (N-M) / i;

	for (long long i = 2; i <= M; i *= 2) count_2 -= M/ i;
	for (long long i = 5; i <= M; i *= 5) count_5 -= M / i;

	printf("%d\n", (count_2 > count_5 ? count_5 : count_2));
}

// 문제를 두번 reduction 한다.
// 1. 문제의 곱 결과에 2와 5가 몇번 곱해졌는지 센다.
// 2. n!에 2와 5가 몇번곱해졌는지 센다.