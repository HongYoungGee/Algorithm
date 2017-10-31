#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	vector<pair<int,string>> s;
	string temp,temp2;
	cin >> T;

	for (int i=0; i<T; i++) { cin >> temp; s.push_back(make_pair(temp.length(),temp )); }

	sort(s.begin(), s.end());


	for (int i = 0; i < T; i++)
		if (s[i].second != temp2)
		{
			cout << s[i].second << endl;
			temp2 = s[i].second;
		}
}

//pair를 sort하면 앞에꺼부터 우선
