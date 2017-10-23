#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int  T,num;
	string s;
	
	cin >> T;
	while (T--)
	{
		string ans;
		cin >> num>>s;
		
		for (int i = 0; i < s.size(); i++)
			for(int j=0; j<num; j++)
				ans += s[i];

		cout << ans << endl;
	}
}
