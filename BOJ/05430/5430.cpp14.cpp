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
		int N, efront = 0, eback = 0; //efront 앞에서 뺴는거, eback 뒤에서 빼는거
		bool isNotReverse = true;

		string s1, s2;
		vector<int> vec;
		int x = 0;

		cin >> s1;
		scanf("%d\n", &N);

		for (int i = 0; i < s1.length(); i++)
			if (s1[i] == 'D')
				(isNotReverse ? efront++ : eback++);
			else if (s1[i] == 'R')
				isNotReverse = !isNotReverse;

		char ch = getchar(); // 입력 받기 시작
		while (1)
		{
			ch = getchar();

			if (ch == ',')
			{
				vec.push_back(x);
				x = 0;
				continue;
			}

			if (ch == ']')
				break;

			x = 10 * x + ch - '0';
		}
		if (x != 0)
			vec.push_back(x);


		if (N < efront + eback) //숫자가 더 길면 바로 에러
		{
			printf("error\n");
			continue;
		}

		
		printf("[");
		if (N > efront + eback)
		{
			if (isNotReverse)
			{
				printf("%d", vec[efront]);
				for (int i = efront + 1; i < vec.size() - eback; i++)
					printf(",%d", vec[i]);
			}
			else
			{
				printf("%d", vec[vec.size() - eback - 1]);
				for (int i = vec.size() - eback - 2; i >= efront; i--)
				{
					printf(",%d", vec[i]);
				}
			}
		}
		printf("]\n");

	}
}


// string은 getline으로 일단 받자