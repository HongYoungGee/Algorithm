#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std; 

int N, L, arr[103][103];

bool possible(int temp[])
{
	for (int j = 0; j < N; j++)
		if (temp[j] == -1) //낮아졌다 j포함 오른쪽 L개 0 필요
		{
			for (int k = L-1; k >=1 ; k--)
				if (j + k >= N) return false;
				else if (temp[j + k] != 0) return false;

			for (int k = L - 1; k >= 1; k--) temp[j + k] = -1;

			j += (L - 1);
		}
		else if (temp[j] == 1 )  //높아졌다 j미포함 왼쪽 L개 0 필요
		{
			for (int k = L; k >=1; k--)
				if (j - k < 0) return false;
				else if (temp[j - k] != 0) return false;

			for (int k = L; k >= 1; k--) temp[j - k] = 1;
			temp[j] = 0;
		}
		else if (temp[j] != 0) return false;

	return true;
}

int runway()
{
	int ans = 0, temp[103];;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (j == 0) temp[j] = 0;
			else temp[j] = arr[i][j] - arr[i][j - 1];

		if (possible(temp)) ans++; //가로

		for (int j = 0; j < N; j++)
			if (j == 0) temp[j] = 0;
			else temp[j] = arr[j][i] - arr[j - 1][i];

		if (possible(temp)) ans++; //세로
	}

	return ans;
}

int main()
{
	scanf("%d %d", &N, &L); //입력
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);

	printf("%d\n", runway());
}