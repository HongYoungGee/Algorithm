#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool check[22] = { false };

int sumOfSubset(int N, int S, vector<int> &vec,int index=0, int sum=0)
{
	int ans = 0;

	for (int i = index; i < N; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			sum += vec[i];
			if (sum == S) ans++;
			ans+=sumOfSubset(N, S, vec, i + 1, sum);
			sum -= vec[i];
			check[i] = false;
		}
	}

	return ans;
}

int main()
{
	int N, S;
	cin >> N >> S;

	vector<int> vec(N);
	for (int i = 0; i < N; i++) scanf("%d",&vec[i]);

	printf("%d\n", sumOfSubset(N, S, vec));
}