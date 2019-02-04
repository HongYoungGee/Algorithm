#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int main()
{
	int Number_of_computer, Number_of_connection;

	cin >> Number_of_computer >> Number_of_connection;

	int *check=new int[Number_of_computer];
	int graph[101][101] = { 0 };

	for (int i = 0; i < Number_of_connection; i++) //그래프 연결 입력
	{
		int a, b;
		cin >> a >> b;
		graph[a-1][b-1] = graph[b-1][a-1] = 1;
	}

	queue <int> q;

	q.push(0); //1번 컴퓨터부터 시작
	check[0] = 1;


	while (!q.empty())
	{
		for (int i = 0; i < Number_of_computer; i++)
		{
			if (graph[i][q.front()]==1)
				if (check[i] != 1)
				{
					check[i] = 1;
					q.push(i);
				}
		}

		q.pop();
	}

	int temp = 0; //감염된 PC수 카운팅
	for (int i = 0; i < Number_of_computer; i++)
		if (check[i] == 1)
			temp++;

	cout <<temp-1 << endl;
}