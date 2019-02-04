#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define maxnum 10000+3

int D(int Num) { return (Num * 2) % 10000; }
int S(int Num) { return (Num + 9999) % 10000; }
int L(int Num) { int n = Num / 1000; return (Num -n*1000) * 10 + n; }
int R(int Num) { int n = Num % 10; return (Num / 10) + n * 1000; }

string DSLR(int A, int B)
{
	string cache[maxnum];
	queue<int> q;
	q.push(A);
	cache[A] = " ";
	while (!q.empty())
	{
		if (q.front() == B) break;

		if (cache[D(q.front())].empty()) cache[D(q.front())] = cache[q.front()] + "D", q.push(D(q.front()));
		if (cache[S(q.front())].empty()) cache[S(q.front())] = cache[q.front()] + "S", q.push(S(q.front()));
		if (cache[L(q.front())].empty()) cache[L(q.front())] = cache[q.front()] + "L", q.push(L(q.front()));
		if (cache[R(q.front())].empty()) cache[R(q.front())] = cache[q.front()] + "R", q.push(R(q.front()));

		q.pop();
	}

	return cache[q.front()].substr(1);
}

int main()
{
	int T,A,B;
	cin >> T;

	while (T--)
	{
		cin >> A >> B;
		cout << DSLR(A, B) << endl;
	}
}