#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<string> s;
	vector<int> dp;

	cin >> n;
	dp.assign(n, 1);

	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		s.push_back(temp);
	}

	sort(s.begin(), s.end());

	int ans = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (s[i] == s[i + 1])
			dp[i + 1] += dp[i];
		if (dp[i + 1] > dp[ans])
			ans = i + 1;
	}

	cout << s[ans] << endl;
}

