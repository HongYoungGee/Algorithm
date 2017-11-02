#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int N ,num = 1,temp;
	stack<int> st;
	vector<char> vec;

	cin >> N;
	while (N--)
	{
		cin >> temp;

		while (num <= temp)
		{
			st.push(num++);
			vec.push_back('+');
		}

		if (st.top() == temp)
		{
			st.pop();
			vec.push_back('-');
		}
		else
		{
			vec.clear();
			break;
		}
	}

	if (vec.empty())
		cout << "NO" << endl;
	else
		for (int i = 0; i < vec.size(); i++)
			printf("%c\n", vec[i]);
}