#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, M,temp,sum=0;
	deque<int> deque;
	queue<int> queue;

	cin >> N>>M;
	for (int i = 1; i <= N; i++) deque.push_back(i);
	for (int i = 0; i < M; i++) { cin >> temp;  queue.push(temp); }

	while (!queue.empty())
	{
		int posi;
		for (int i=0; i<deque.size(); i++)
			if (deque[i] == queue.front()) { posi = i;	break;	}

		if (posi > deque.size() - posi)
		{
			for (int i = 0; i<deque.size() - posi; i++) { deque.push_front(deque.back()); deque.pop_back(); }
			sum += deque.size() - posi;
		}
		else 
		{
			sum += posi;
			while (posi--) { deque.push_back(deque.front()); deque.pop_front(); }
		}

		deque.pop_front();
		queue.pop();
	}

	cout << sum << endl;
}