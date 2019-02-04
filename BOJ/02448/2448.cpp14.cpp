#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;
bool **arr;

void paint(int x, int y, int n)
{
	for (int i = n / 2; i < n; i++)
	{
		for (int j = y-i; j < y+abs(i-y); j++)
			arr[i][j] = arr[i - n / 2][j + n / 2];
		for (int j = y + n-i; j < y+i+1; j++)
			arr[i][j] = arr[i - n / 2][j-n + n / 2];
	}
}

int main() {
	int n;
	cin >> n;

	
	int height = n,width = n*2-1;


	arr = (bool **)malloc(sizeof(bool *) * height); //동적할당 후 초기화
	for (int i = 0; i < height; i++)
	{
		arr[i] = (bool *)malloc(sizeof(bool) * width);
		for (int j = 0; j < width; j++)
			arr[i][j] = { false };
	}

	arr[0][(width - 1)/2] = arr[1][(width - 1) / 2 - 1]= arr[1][(width - 1) / 2 + 1]= arr[2][(width - 1) / 2 - 2]= arr[2][(width - 1) / 2 - 1]= arr[2][(width - 1) / 2]= arr[2][(width - 1) / 2 +1]= arr[2][(width - 1) / 2 + 2]={ true };

	for(int i=6; i <= n; i*=2)
		paint(0, (width - 1) / 2, i);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			if (arr[i][j])
				printf("*");
			else
				printf(" ");
		cout << endl;
	}
}