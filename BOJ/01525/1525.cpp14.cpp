#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int f[11] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 }; //factorial
int orderOfPermutation(vector<int> vec)
{
	bool c[11] = { false };
	int ans = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 1; j < vec[i]; j++)
			if (c[j] == false)
				ans += f[vec.size() - i - 1];
		c[vec[i]] = true;
	}

	return ans + 1;
}

vector<int> permutationsOfNumbers(int k,int n=9)
{
	bool c[11] = { false };
	vector<int> a(n);

	for (int i = 0; i < n; i++) 
		for (int j = 1; j <= n; j++) 
		{
			if (c[j] == true) continue;

			if (f[n - i - 1] < k) 
			{
				k -= f[n - i - 1];
			}
			else 
			{
				a[i] = j;
				c[j] = true;
				break;
			}
		}

	return a;
}

int puzzle(vector<int> vec)
{
	bool check[362890] = { false };
	int ans = 0;
	queue<int> q;
	vector<vector<int>> v = { {1,3},{0,2,4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7},{4,6,8},{5,7} };
	q.push(orderOfPermutation(vec));
	check[q.front()] = true;

	while (!q.empty())
	{
		int qsize = q.size();
		while (qsize--)
		{
			if (q.front() == 46234) return ans; //(2, 3 ,4, 5, 6, 7, 8, 9, 1)
			vector<int> arr = permutationsOfNumbers(q.front());

			for (int i = 0; i < 9; i++)
				if (arr[i] == 1)
				{
					for (int j = 0; j < v[i].size(); j++) //0의 위치에 따라 가능한 스왑 확인
					{
						swap(arr[i], arr[v[i][j]]);
						int temp = orderOfPermutation(arr);
						if (!check[temp])
						{
							check[temp] = true;
							q.push(temp);
						}
						swap(arr[i], arr[v[i][j]]);
					}
				}
			q.pop();
		}
		ans++;
	}

	return -1;
}

int main()
{
	int temp;
	vector<int> vec;
	for (int i = 0; i < 9; i++)
		cin >> temp, vec.push_back(temp+1);

	cout << puzzle(vec) << endl;
}