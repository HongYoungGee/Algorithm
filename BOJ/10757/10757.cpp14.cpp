#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void add_string(string *s1, string s2) //s1과 s2에 있는 숫자를 더해서 s1에 저장
{
	string temp = *s1;
	int temp_length = temp.length()-1, s2_length = s2.length()-1;
	char up = '0';
	s1->clear();

	while (temp_length >= 0 || s2_length >= 0)
	{
		char a =up;
		up = '0';
		if (temp_length >= 0) a += temp[temp_length--]-'0';
		if (s2_length >= 0)	a += s2[s2_length--]-'0';

		if (a > '9')
		{
			a -= 10;
			up = '1';
		}
		s1->push_back(a);
	}
	if (up == '1')	s1->push_back(up);

	reverse(s1->begin(), s1->end());
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	add_string(&s1, s2);
	
	cout << s1 << endl;
}