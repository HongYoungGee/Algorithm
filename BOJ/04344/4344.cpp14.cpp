#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int  T, n,temp;
	
	cin >> T;
	while (T--)
	{
		cin >> n;
		vector<int> v;
		double sum = 0, ans = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			v.push_back(temp);
			sum += temp;
		}

		sum /= n;

		for (int i = 0; i < n; i++)	if (sum < v[i])	ans++;

		printf("%0.3lf%%\n", ans / n*100);
	}
}


