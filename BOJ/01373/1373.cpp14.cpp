#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

char twoToeight2(string s)
{
	int ans = 0;
	for (int i = s.size() - 1; i >= 0; i--)
		ans+= (s[i] - '0')* pow(2, s.size() - i - 1);

	return ans + '0';
}

string twoToeight(string s)
{
	string ans;

	while (!s.empty())
	{
		if (s.size() >= 3)
		{
			ans.push_back(twoToeight2(s.substr(s.size() - 3)));
			s.erase(s.size() - 3, 3);
		}
		else
		{
			ans.push_back(twoToeight2(s));
			s.clear();
		}
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main()
{
	string s;
	cin >> s;
	
	cout << twoToeight(s) << endl;
}