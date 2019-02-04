#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

string eightTotwo(string s)
{
	if (s == "0") return "0";
	string ans, eight[8] = { "000","001","010","011","100","101","110","111" };;

	for (int i = 0; i < s.size(); i++)
		ans.append(eight[s[i] - '0']);

	for (int i = 0; i < ans.size(); i++)
		if (ans[i] != '0') return ans.substr(i);
}

int main()
{
	string s;
	cin >> s;
	
	cout << eightTotwo(s) << endl;
}