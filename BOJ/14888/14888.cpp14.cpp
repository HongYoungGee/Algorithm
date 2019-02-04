#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std; 

int N, arr[13], command[4] = { 0 }; //+ - * /
int vmin = 1000000000, vmax = -1000000000;

void incommand(int num,int sum) //
{
	if (num >= N)
	{
		vmin = min(vmin, sum);
		vmax = max(vmax, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
		if (command[i] > 0)
		{
			command[i]--;
			if (i == 0) incommand(num + 1, sum + arr[num]);
			else if(i==1) incommand(num + 1, sum - arr[num]);
			else if(i==2) incommand(num + 1, sum * arr[num]);
			else if(i==3) incommand(num + 1, sum / arr[num]);
			command[i]++;
		}
}

int main()
{
	scanf("%d", &N); //입력
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < 4; i++) scanf("%d", &command[i]);

	incommand(1, arr[0]);

	printf("%d\n%d\n", vmax,vmin);
}