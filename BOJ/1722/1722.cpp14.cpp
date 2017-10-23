#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, pro;
	unsigned long long k,ans = 0;
	cin >> n>>pro;
	vector<int> v;

	unsigned long long arr[21] = { 1 };

	for (int i = 1; i <= 20; i++)
		arr[i] = arr[i - 1] * (i);

	for (int i = 1; i <= n; i++)
		v.push_back(i);
	
	if (pro == 1)
	{
		cin >> k;
		int point = n-1;
		while (!v.empty())
		{
			int temp = 0;
			if (k > arr[point])
				temp = (k - 1) / arr[point];	

			cout << v[temp] << " ";
			v.erase(v.begin() + temp);

			k -= temp*arr[point];
			point--;
		}
	}
	else if (pro == 2)
	{
		vector<int> v2;
		vector<int> ::iterator it;
		for (int i = 0; i < n; i++)
		{
			cin >> pro;
			v2.push_back(pro);
		}

		int point = n - 1;
		while (!v.empty())
		{
			it=find(v.begin(), v.end(), v2[n - point - 1]);
			ans += distance(v.begin(), it)*arr[point];

			v.erase(it);
			point--;
		}
		cout << ans + 1 << endl;
	}

}