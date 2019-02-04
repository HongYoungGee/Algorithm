#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;


int main()
{
	int T;
    scanf("%d",&T);

	priority_queue<int, vector<int>, greater<int>> min_heap;

	while (T--)
	{
		int temp;
        scanf("%d",&temp);

		if (temp != 0)
			min_heap.push(temp);
		else if (min_heap.empty())
            printf("0\n");
		else
		{
            printf("%d\n",min_heap.top());
			min_heap.pop();
		}
	}
	

}
