#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int T = 1;
	cin >> T;
	while (T--)
	{
		int n, k;
		int *num; //건물 건설 시간
		int **arr = NULL; //건설규칙
		int *ans;
		int out;
		int plag = 1;
		vector<pair<int, int>> pv;

		cin >> n >> k; //n 건물개수 k 규칙갯수

		ans = new int[n + 1];
		num = new int[n + 1];          //건설시간 0 비우고 건물번호마다 시간

		for (int i = 1; i <= n; i++)  //건설시간 입력
		{
			cin >> num[i];
			ans[i] = num[i];
		}

		arr = new int*[2];
		for (int i = 0; i < 2; i++)         //2차원배열 동적할당
			arr[i] = new int[k];

		for (int j = 0; j < k; j++)
			for (int i = 0; i < 2; i++) //2차원배열에 규칙들 입력    
				cin >> arr[i][j];

		while (plag)
		{
			plag = 0;
			for (int j = 0; j < k; j++)
			{
				if (ans[arr[0][j]] + num[arr[1][j]] > ans[arr[1][j]])
				{
					ans[arr[1][j]] = ans[arr[0][j]] + num[arr[1][j]];
					plag = 1;
				}
			}
		}
		

		cin >> out;

		cout << ans[out] << endl;
	}
}