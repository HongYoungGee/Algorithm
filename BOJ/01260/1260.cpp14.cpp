#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int** arr; //연결 정보
int *arr2; // DFS 방문 여부
void DFS(int n, int v)
{
	stack<int> st;
	st.push(v);

	while (!st.empty())
	{
		int temp = st.top();
		st.pop();
		if (arr2[temp] == 0)
		{
			cout << temp << " ";
			arr2[temp] = 1;
			for (int i = n; i > 0; i--)
			{
				if (arr[temp][i] == 1 && arr2[i] == 0) //연결되있고 , 방문한적 없을시
					st.push(i);

			}
		}
	}
}

void BFS(int n, int v)
{
	queue<int> qu;
	qu.push(v);
	arr2[v] = 1;
	while (!qu.empty())
	{
		int temp = qu.front();
		qu.pop();
			cout << temp << " ";
			for (int i = 1; i < n+1; i++)
			{
				if (arr[temp][i] == 1 && arr2[i] == 0) //연결되있고 , 방문한적 없을시
				{
					qu.push(i);
					arr2[i] = 1;
				}
					
			}
	}
}

int main()
{
	
	int n, m, v, temp1, temp2;

	cin >> n >> m >> v;

	arr = new int*[n+1];  //배열 크기가 1000000 크기때문에 동적할당
	for (int i = 0; i < n+1; ++i)
	{
		arr[i] = new int[n+1];
		for (int j = 0; j<n+1; ++j) arr[i][j] = 0;
	}
	
	arr2 = new int[n + 1];
	for (int i = 0; i < n + 1; ++i) arr2[i] = 0;
	//배열 동적할당

	for (int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2;
		arr[temp1][temp2] = arr[temp2][temp1] = 1;
	}
	//입력 끝

	DFS(n, v);
	cout << endl;
	for (int i = 0; i < n + 1; ++i) arr2[i] = 0;
	BFS(n, v);
	cout << endl;
}

