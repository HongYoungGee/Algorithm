#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define maxnum 10000+3
bool isPrime[maxnum];

void eratos()
{
	for (int i = 2; i < maxnum; i++)
		isPrime[i] = true;

	for (int i = 2; i < maxnum; i++)
		if (isPrime[i])
		{
			for (int j = (i*i); j < maxnum; j += i)
				isPrime[j] = false;
		}
}

int primeRoute(int A, int B)
{
	bool check[maxnum] = { false };
	queue<int> q;
	q.push(A);
	eratos();
	int count = 0;
	check[A] = true;
	while (!q.empty())
	{
		int qsize = q.size();
		while (qsize--)
		{
			if (q.front() == B) return count;

			int num4 = -q.front() % 10;
			int num3 = -(q.front() / 10 % 10) * 10;
			int num2 = -(q.front() / 100 % 10) * 100;
			int num1 = 1000 - (q.front() / 1000 % 10) * 1000;
			for (int i = num4; i <= 9 + num4; i++) if (isPrime[q.front() + i] && !check[q.front() + i]) check[q.front() + i] = true, q.push(q.front() + i);
			for (int i = num3; i <= 90 + num3; i += 10) if (isPrime[q.front() + i] && !check[q.front() + i]) check[q.front() + i] = true, q.push(q.front() + i);
			for (int i = num2; i <= 900 + num2; i += 100) if (isPrime[q.front() + i] && !check[q.front() + i]) check[q.front() + i] = true, q.push(q.front() + i);
			for (int i = num1; i <= 8000 + num1; i += 1000) if (isPrime[q.front() + i] && !check[q.front() + i]) check[q.front() + i] = true, q.push(q.front() + i);

			q.pop();
		}
		count++;
	}

	return -1;

}

int main()
{
	int T,A,B;
	cin >> T;

	while (T--)
	{
		cin >> A >> B;
		cout<<primeRoute(A, B)<<endl;
	}

}