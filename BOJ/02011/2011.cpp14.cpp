#include <iostream>
#include <string>

using namespace std;
#define maxnum 5000
#define mod 1000000

int cache[maxnum + 3] = { 1};

bool isDoubleDigit(char c1, char c2)
{
	if (c1 == '1') return true;
	if (c1 == '2' && c2 <= '6') return true;

	return false;
}

int cryptocode(string s)
{
	s = " " + s;
	for (int i = 1; i <= s.size(); i++)
	{
		if ('1' <= s[i] && s[i] <= '9') cache[i] = cache[i - 1];
		if (i == 1 || s[i-1] =='0') continue;

		if(isDoubleDigit(s[i-1],s[i])) cache[i]= (cache[i] + cache[i - 2]) % mod;
	}

	return cache[s.size() - 1];
}

int main()
{
	string s;
	cin >> s;
	
	cout << cryptocode(s) << endl;
}