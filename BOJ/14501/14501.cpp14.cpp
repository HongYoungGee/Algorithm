#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std; 

int cache[16][2]; //0 일 할때 1 안할때
int N, T[16], P[16]; //T 시간 P 수당
int taesa(int now=0)
{
	if (cache[now][0] == -1 && now + T[now] <= N) cache[now][0] = P[now] + taesa(now + T[now]);
	if (cache[now][1] == -1) cache[now][1] = taesa(now + 1);

	return max(cache[now][0], cache[now][1]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf("%d", &T[i]); scanf("%d", &P[i]); cache[i][0] = cache[i][1] = -1; }

	printf("%d\n", taesa());
}