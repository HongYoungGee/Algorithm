#include <string>
#include <deque>
#include <iostream>

using namespace std;

int main() 
{
	int sum = 0, x = 0; //활성 쇠막대기 수
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
		if (s[i] == '(' && s[i + 1] != ')')
			x++;
		else if (s[i] == ')')
		{
			if (s[i - 1] != '(')
			{
				x--;
				sum++;
			}
			else
				sum += x;
		}

	cout << sum << endl;
}