#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool **arr;

void paint(int x, int y, int width,int height)
{
	for (int i = x; i < x+ height; i++)
	{
		for (int j = y; j < y+ width; j++)
		{
			if (i == x || i == x+ height - 1)
				arr[i][j] = true;
			if ( (j ==y || j== y + width -1))
				arr[i][j] = true;
		}
	}
	if (width != 1)
		paint(x + 2, y + 2, width - 4, height - 4);
}


int main()
{
	int n,x=0,y=0;
	int width, height;

	cin >> n;
	width = 1 + (n - 1) * 4;
	height = 1 + (n - 1) * 4;
	
	arr = (bool **)malloc(sizeof(bool *) * height); //동적할당 후 초기화
	for (int i = 0; i < height; i++)
	{
		arr[i] = (bool *)malloc(sizeof(bool) * width);
		for (int j = 0; j < width; j++)
		{
			arr[i][j] = { false };
		}
	}

	paint(x, y, width, height);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (arr[i][j])
				printf("*");
			else
				printf(" ");
		}
		cout << endl;
	}
}
