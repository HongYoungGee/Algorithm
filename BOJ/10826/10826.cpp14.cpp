#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string add_string2(string s1, string s2) //s1과 s2에 있는 숫자를 더해서 반환
{
	string temp;
	int s1_length = s1.length() - 1, s2_length = s2.length()-1;
	char up = '0';

	while (s1_length >= 0 || s2_length >= 0)
	{
		char a =up;
		up = '0';
		if (s1_length >= 0) a += s1[s1_length--]-'0';
		if (s2_length >= 0)	a += s2[s2_length--]-'0';

		if (a > '9')
		{
			a -= 10;
			up = '1';
		}
		temp.push_back(a);
	}
	if (up == '1')	temp.push_back(up);

	reverse(temp.begin(), temp.end());

	return temp;
}

string cache[10001] = { "0","1","1","2"};
string pivonachi(int n)
{
	if (n == 0 || !cache[n].empty()) return cache[n];

	return cache[n] = add_string2( pivonachi(n - 1), pivonachi(n - 2));
}

int main()
{
	int n;
	scanf("%d", &n);

	cout << pivonachi(n) << endl;
}