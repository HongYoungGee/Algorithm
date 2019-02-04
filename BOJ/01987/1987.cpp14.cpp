#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool check[26] = { false };
int arr[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

int alphabet(int R, int C, vector<string> &svec, int x = 0, int y = 0)
{
	int ans = 0;

	for (int i = 0; i < 4; i++)
	{
		int x1 = x + arr[i][0];
		int y1 = y + arr[i][1];
		if (x1 >= 0 && y1 >= 0 && x1 < R && y1 < C && !check[svec[x1][y1] - 'A'])
		{
			check[svec[x1][y1] - 'A'] = true;
			ans = max(alphabet(R,C, svec,x1, y1), ans);
			check[svec[x1][y1] - 'A'] = false;
		}
	}

	return ans+1;
}

int main()
{
	int R, C;
	cin >> R >> C;

	vector<string> svec(R);
	for (int i = 0; i < R; i++) cin >> svec[i];

	check[svec[0][0] - 'A'] = true;
	printf("%d\n", alphabet(R, C, svec));
}