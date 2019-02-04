#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int N, arr[22][22],vmin=100000;
vector<int> A, B;

void soccer(int i, int Asum, int Bsum)
{
	if (i>=N) vmin = min(vmin, (Asum>Bsum) ? Asum-Bsum : Bsum-Asum);

	if (A.size() < N/2)
	{
		int sum = Asum;
		for (int j = 0; j < A.size(); j++)
			sum = sum + arr[i][A[j]] + arr[A[j]][i];
		A.push_back(i);
		soccer(i+1, sum, Bsum);
		A.pop_back();
	}
	if (B.size() < N/2)
	{
		for (int j = 0; j < B.size(); j++)
			Bsum = Bsum + arr[i][B[j]] + arr[B[j]][i];
		B.push_back(i);
		soccer(i+1,Asum, Bsum);
		B.pop_back();
	}
}

int main()
{
	scanf("%d", &N); //입력
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);

	soccer(0, 0, 0);

	printf("%d\n", vmin);
}