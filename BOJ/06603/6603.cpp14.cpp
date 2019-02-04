#include <iostream>
#include <algorithm>
#include <vector>

#define maxNum 49+3

using namespace std;

bool nextComb(int k, vector<int> &vec) //다음 번호
{
	for(int i=5; i>=0; i--)
		if (vec[i] < k - 1 - (5 - i))
		{
			vec[i]++;
			for (int j = i + 1; j < vec.size(); j++)
				vec[j] = vec[j - 1] + 1;
			return true;
		}

	return false;
}

void germanLotto(int k, int arr[]) //가능한 로또 조합 출력
{
	vector<int> vec = { 0,1,2,3,4,4 };

	while (nextComb(k, vec))
		printf("%d %d %d %d %d %d\n", arr[vec[0]], arr[vec[1]], arr[vec[2]], arr[vec[3]], arr[vec[4]], arr[vec[5]]);
	printf("\n");
}

int main()
{
	int k, arr[maxNum] = { 0 };

	scanf("%d", &k);
	while (k != 0)
	{
		for (int i = 0; i < k; i++)
			cin >> arr[i];

		germanLotto(k, arr);
		scanf("%d", &k);
	}
}