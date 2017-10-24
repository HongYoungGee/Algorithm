#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	int T;
	cin >> T;

	priority_queue<int, vector<int>, greater<int>> min_heap;

	while (T--)
	{
		int temp;
		cin >> temp;

		if (temp != 0)
			min_heap.push(temp);
		else if (min_heap.empty())
			cout << 0 << endl;
		else
		{
			cout << min_heap.top() << endl;
			min_heap.pop();
		}
	}
	

}
