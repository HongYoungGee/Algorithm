#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#pragma warning (disable:4996)

using namespace std;

int N, M, direct[4][2] = { {0,-1},{0,1},{-1,0},{1,0} }, ans = 11; //왼쪽 오른쪽 위 아래
char arr[12][12];
bool goal(int x, int y, int go) //가는 방향에 골이 있다.
{
	while (arr[x][y] != '#')
	{
		x += direct[go][0];
		y += direct[go][1];

		if (arr[x][y] == 'O') return true;
	}

	return false;
}

bool moveball(int redx, int redy, int bluex, int bluey, int &after_redx, int &after_redy, int &after_bluex, int &after_bluey, int go)
{
	for (int x = redx + direct[go][0], y = redy + direct[go][1]; arr[x][y] != '#'; x += direct[go][0], y += direct[go][1]) //빨강
		if (arr[x][y] == '.')
		{
			after_redx = x;
			after_redy = y;
		}

	for (int x = bluex + direct[go][0], y = bluey + direct[go][1]; arr[x][y] != '#'; x += direct[go][0], y += direct[go][1]) //파랑
		if (arr[x][y] == '.')
		{
			after_bluex = x;
			after_bluey = y;
		}

	if (after_redx == -1 && after_bluex == -1) return false; //둘다 이동을 안하면

	if (after_redx == after_bluex && after_redy == after_bluey) //같은곳을 가리키면
	{
		if (go == 0)
		{
			if (redy > bluey) after_redy++;
			else after_bluey++;
		}
		else if (go == 1)
		{
			if (redy > bluey) after_bluey--;
			else after_redy--;
		}
		else if (go == 2)
		{
			if (redx > bluex) after_redx++;
			else after_bluex++;
		}
		else if (go == 3)
		{
			if (redx > bluex) after_bluex--;
			else after_redx--;
		}
	}

	if (after_redx == -1) after_redx = redx, after_redy = redy; //하나만 이동하면
	else if (after_bluex == -1) after_bluex = bluex, after_bluey = bluey;

	return true;
}

void changeball(int redx, int redy, int bluex, int bluey, int after_redx, int after_redy, int after_bluex, int after_bluey, bool check)
{
	if (check)
	{
		if (after_redx != redx || after_redy != redy)
		{
			arr[redx][redy] = '.';
			arr[after_redx][after_redy] = 'R';
		}
		if (after_bluex != bluex || after_bluey != bluey)
		{
			arr[bluex][bluey] = '.';
			arr[after_bluex][after_bluey] = 'B';
		}
	}
	else
	{
		if (after_redx != redx || after_redy != redy)
		{
			arr[redx][redy] = 'R';
			arr[after_redx][after_redy] = '.';
		}
		if (after_bluex != bluex || after_bluey != bluey)
		{
			arr[bluex][bluey] = 'B';
			arr[after_bluex][after_bluey] = '.';
		}
	}
}

void goosle(int redx, int redy, int bluex, int bluey, int count, int before)
{
	if (count >= ans) return;

	for (int i = 0; i < 4; i++)
		if (before+i != 1 && before+i != 7 &&!goal(bluex, bluey, i)) //방향으로 이동해도 파란색이 골인 안함
		{
			if (goal(redx, redy, i))
				ans = min(ans, count + 1);
			else
			{
				int after_redx = -1, after_redy = -1, after_bluex = -1, after_bluey = -1;
				if (moveball(redx, redy, bluex, bluey, after_redx, after_redy, after_bluex, after_bluey, i)) //하나가 움직이면
				{
					changeball(redx, redy, bluex, bluey, after_redx, after_redy, after_bluex, after_bluey, 1);
					goosle(after_redx, after_redy, after_bluex, after_bluey, count + 1,i);
					changeball(redx, redy, bluex, bluey, after_redx, after_redy, after_bluex, after_bluey, 0);
				}
			}
		}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", arr[i]); //입력

	int redx, redy, bluex, bluey; //x좌표 y좌표
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 'R')
			{
				redx = i;
				redy = j;
			}
			else if (arr[i][j] == 'B')
			{
				bluex = i;
				bluey = j;
			}

    goosle(redx, redy, bluex, bluey, 0,100);
    
	printf("%d\n", (ans != 11) ? ans : -1);
}