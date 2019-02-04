#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#pragma warning (disable:4996)

using namespace std;

int N, M,ans=100000000;
vector<pair<int, int>> home, chicken;

void chickenRoad(int numChicken, int start=0)
{
	if (M == numChicken) //다쭐임
	{
		int sum = 0;
		for (int i = 0; i < home.size(); i++)
		{
			int distance = 100000000; //각 집에서 제일 가까운 치킨집까지 거리
			for (int j = 0; j < chicken.size(); j++)
			{
				if (chicken[j].first != 100 && chicken[j].second != 100) //0인거 제외
					distance = min(abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second), distance);
			}
			sum += distance;
		}

		ans = min(ans, sum);
	}

	for (int i = start; i < chicken.size(); i++)
	{
		int x = chicken[i].first;
		int y = chicken[i].second;

		chicken[i].first = 100;
		chicken[i].second = 100;

		chickenRoad(numChicken - 1, i + 1);

		chicken[i].first = x;
		chicken[i].second = y;
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for(int j=0; j<N; j++)
		{
			int temp;
			scanf("%d", &temp);
			if (temp == 1) home.push_back(make_pair(i, j));
			else if (temp == 2) chicken.push_back(make_pair(i, j));
		}

	chickenRoad(chicken.size());

	printf("%d\n", ans);
}