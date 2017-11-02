#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {

	string s;
	cin >> s;

	stack<int> s1;
	int check1 = 0, check2 = 0, sum = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			check1++;
		else if (s[i] == ')')
			check1--;
		else if (s[i] == '[')
			check2++;
		else if (s[i] == ']')
			check2--;

		if (check1 < 0 || check2<0)
			break;
	}

	while (!s.empty() && check1==0 && check2==0)
	{
		s1.push(s.back());
		s.pop_back();


		if (s1.top() == '(')
		{
			s1.pop();
			if (s1.top() == ')')
			{
				s1.pop();
				s1.push(2);
			}
			else
			{
				int temp = 0;
				while (s1.top() != ')')
				{
					if (s1.top() == ']')
					{
						check1 = -1;
						break;
					}
					temp += s1.top();
					s1.pop();
				}
				temp *= 2;
				s1.pop();
				s1.push(temp);
			}
		}
		else if (s1.top() == '[')
		{
			s1.pop();
			if (s1.top() == ']')
			{
				s1.pop();
				s1.push(3);
			}
			else
			{
				int temp = 0;
				while (s1.top() != ']')
				{
					if (s1.top() == ')')
					{
						check1 = -1;
						break;
					}
					temp += s1.top();
					s1.pop();
				}
				temp *= 3;
				s1.pop();
				s1.push(temp);
			}
		}
	}
	
	while (!s1.empty() && check1 == 0 && check2 == 0)
	{
		sum += s1.top();
		s1.pop();
	}

	cout << sum << endl;
}