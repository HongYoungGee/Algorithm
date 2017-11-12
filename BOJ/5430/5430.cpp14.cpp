#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d\n", &T);

	while (T--)
	{
		int N, efront = 0, eback = 0;
		bool isNotReverse = true;

		string s1, s2;
		vector<int> vec;

		getline(cin, s1);
		scanf("%d\n", &N);
		getline(cin, s2);

		for (int i = 0; i < s1.length(); i++)
			if (s1[i] == 'D')
				(isNotReverse ? efront++ : eback++);
			else if (s1[i] == 'R')
				isNotReverse = !isNotReverse;

		for (int i = 1, x = 0; s2[i] !=']'; i++)
		{
			if (s2[i] == ',')
				continue;

			x = 10 * x + s2[i] - '0';

			if (!('0' <= s2[i + 1] && s2[i + 1] <= '9'))
			{
				vec.push_back(x);
				x = 0;
			}
		}

		if (N < efront + eback)
		{
			printf("error\n");
			continue;
		}

		printf("[");
		if (isNotReverse)
		{
			for (int i = efront; i < vec.size() - eback; i++)
			{
				printf("%d", vec[i]);
				if (i <vec.size() - eback - 1) printf(",");
			}
		}
		else
		{
			for (int i = vec.size() - eback - 1; i >= efront; i--)
			{
				printf("%d", vec[i]);
				if (i > efront) printf(",");
			}
		}
		printf("]\n");
	}
}


// string은 getline으로 일단 받자