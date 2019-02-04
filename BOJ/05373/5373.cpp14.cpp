#include<stdio.h>

using namespace std;

char cube[9][12];

void fill_cube()
{
	for (int x = 0; x < 3; x++) for (int y = 3; y < 6; y++) cube[x][y] = 'w';
	for (int x = 3; x < 6; x++) for (int y = 0; y < 3; y++) cube[x][y] = 'g';
	for (int x = 3; x < 6; x++) for (int y = 3; y < 6; y++) cube[x][y] = 'r';
	for (int x = 3; x < 6; x++) for (int y = 6; y < 9; y++) cube[x][y] = 'b';
	for (int x = 3; x < 6; x++) for (int y = 9; y < 12; y++) cube[x][y] = 'o';
	for (int x = 6; x < 9; x++) for (int y = 3; y < 6; y++) cube[x][y] = 'y';
}

void rotate(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, char direct)
{
	if (direct == '+') //시계
	{
		char temp = cube[x1][y1];
		cube[x1][y1] = cube[x2][y2];
		cube[x2][y2] = cube[x3][y3];
		cube[x3][y3] = cube[x4][y4];
		cube[x4][y4] = temp;
	}
	else if (direct == '-') //반시계
	{
		char temp = cube[x1][y1];
		cube[x1][y1] = cube[x4][y4];
		cube[x4][y4] = cube[x3][y3];
		cube[x3][y3] = cube[x2][y2];
		cube[x2][y2] = temp;
	}
}

void rotate_front(char direct)
{
	rotate(3, 3, 5, 3, 5, 5, 3, 5, direct); //앞면
	rotate(4, 3, 5, 4, 4, 5, 3, 4, direct);

	rotate(3, 2, 6, 3, 5, 6, 2, 5, direct);
	rotate(4, 2, 6, 4, 4, 6, 2, 4, direct);
	rotate(5, 2, 6, 5, 3, 6, 2, 3, direct);
}
void rotate_up(char direct)
{
	rotate(0, 3, 2, 3, 2, 5, 0, 5, direct);
	rotate(1, 3, 2, 4, 1, 5, 0, 4, direct);
	
	rotate(3, 0, 3, 3, 3, 6, 3, 9, direct);
	rotate(3, 1, 3, 4, 3, 7, 3, 10, direct);
	rotate(3, 2, 3, 5, 3, 8, 3, 11, direct);
}
void rotate_down(char direct)
{
	rotate(6, 3, 8, 3, 8, 5, 6, 5, direct);
	rotate(7, 3, 8, 4, 7, 5, 6, 4, direct);

	rotate(5, 2, 5, 11, 5, 8, 5, 5, direct);
	rotate(5, 1, 5, 10, 5, 7, 5, 4, direct);
	rotate(5, 0, 5, 9, 5, 6, 5, 3, direct);
}
void rotate_left(char direct)
{
	rotate(3, 0, 5, 0, 5, 2, 3, 2, direct);
	rotate(4, 0, 5, 1, 4, 2, 3, 1, direct);

	rotate(3, 11, 8, 3, 5, 3, 2, 3, direct);
	rotate(4, 11, 7, 3, 4, 3, 1, 3, direct);
	rotate(5, 11, 6, 3, 3, 3, 0, 3, direct);
}
void rotate_right(char direct)
{
	rotate(3, 6, 5, 6, 5, 8, 3, 8, direct);
	rotate(4, 6, 5, 7, 4, 8, 3, 7, direct);

	rotate(3, 5, 6, 5, 5, 9, 0, 5, direct);
	rotate(4, 5, 7, 5, 4, 9, 1, 5, direct);
	rotate(5, 5, 8, 5, 3, 9, 2, 5, direct);
}
void rotate_back(char direct)
{
	rotate(3, 9, 5, 9, 5, 11, 3, 11, direct);
	rotate(4, 9, 5, 10, 4, 11, 3, 10, direct);

	rotate(3, 8, 8, 5, 5, 0, 0, 3, direct);
	rotate(4, 8, 8, 4, 4, 0, 0, 4, direct);
	rotate(5, 8, 8, 3, 3, 0, 0, 5, direct);
}

void print_cube()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 3; y < 6; y++)
            printf("%c", cube[x][y]);
		printf("\n");
	}
}

int main()
{
	int T,n;
	char command[3];
    scanf("%d", &T);
	while (T--)
	{
        scanf("%d", &n);
		fill_cube();
		while (n--)
		{
            scanf("%s", command);
			if (command[0] == 'U') rotate_up(command[1]);
			else if (command[0] == 'D') rotate_down(command[1]);
			else if (command[0] == 'F') rotate_front(command[1]);
			else if (command[0] == 'B') rotate_back(command[1]);
			else if (command[0] == 'L') rotate_left(command[1]);
			else if (command[0] == 'R') rotate_right(command[1]);
		}
		print_cube();
	}
}