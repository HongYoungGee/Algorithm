#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	int N, Number_of_complex = 0;
	bool graph[26][26] = { false };
	vector <int> vec;

	cin >> N;

	for (int i = 0; i < N; i++) //그래프 연결 입력
	{
		string s;
		cin >> s;
		for(int j=0; j<N; j++)
			graph[i][j] = (s[j] =='1' ? true : false);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j]) //1인거 찾은경우
			{
				Number_of_complex++;
				int Number_of_apartment = 0;

				queue <pair<int,int>> q;
				q.push(make_pair(i, j));
				graph[i][j] = false;
				while (!q.empty())
				{
					if (q.front().first > 0 && graph[q.front().first - 1][q.front().second] == 1) // 위에 비교
					{
						graph[q.front().first - 1][q.front().second] = false;
						q.push(make_pair(q.front().first - 1, q.front().second));						
					}
					if (q.front().second > 0 && graph[q.front().first][q.front().second - 1] == 1) // 왼쪽 비교
					{
						graph[q.front().first][q.front().second - 1] = false;
						q.push(make_pair(q.front().first, q.front().second - 1));						
					}
					if (q.front().second < N - 1 && graph[q.front().first][q.front().second + 1] == 1) // 오른쪽 비교
					{
						graph[q.front().first][q.front().second + 1] = false;
						q.push(make_pair(q.front().first, q.front().second + 1));
					}
					if (q.front().first < N - 1 && graph[q.front().first + 1][q.front().second] == 1) // 아래 비교
					{
						graph[q.front().first + 1][q.front().second] = false;
						q.push(make_pair(q.front().first + 1, q.front().second));
					}

					q.pop();
					Number_of_apartment++;
				}

				vec.push_back(Number_of_apartment);
			}

		}
	}

	sort(vec.begin(), vec.end());

	cout << Number_of_complex << '\n';
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << '\n';
}