#include <iostream>
#include <algorithm>
#include <vector>

#define maxNum 10+3

using namespace std;

int load(int arr[][maxNum], vector<int> vec)
{
	int sum = 0;
	for (int i = 0; i < vec.size() - 1; i++)
		if (arr[vec[i]][vec[i + 1]] == 0) return 0;
		else sum += arr[vec[i]][vec[i + 1]];

	if (arr[vec[vec.size() - 1]][vec[0]] == 0) return 0;
	sum += arr[vec[vec.size() - 1]][vec[0]];

	return sum;
}

int TSP(int N, int arr[][maxNum])
{
	vector<int> vec;
	vec.push_back(0);
	for (int i = N-1; i >0; i--) vec.push_back(i);
	int ans = 1000000 * 11;

	do {
		int temp = load(arr, vec);
		if (temp>0) ans = min(ans, temp);
	} while (prev_permutation(vec.begin(), vec.end()));

	return ans;
}

int main()
{
	int N, arr[maxNum][maxNum] = { 0 };

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	cout << TSP(N, arr) << endl;
}