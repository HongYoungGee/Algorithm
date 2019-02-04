#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

int returnBlock(int num)
{
	if (num >= 6) return 6;
	else if (num >= 3) return 3;
	else return 0;
}

vector<int> changeSdoqu(int i, int j, int arr[][9])
{
	bool check[10] = { false };

	for (int x = i, y = 0; y < 9; y++) check[arr[x][y]] = true; //i행 확인
	for (int x = 0, y = j; x < 9; x++) check[arr[x][y]] = true; //j열 확인

	for(int x=returnBlock(i); x< returnBlock(i)+3; x++)
		for (int y = returnBlock(j); y < returnBlock(j) + 3; y++)
			check[arr[x][y]] = true; //블럭안

	vector<int> vec;
	for (int z = 1; z < 10; z++)
		if (check[z] == false) vec.push_back(z);

	return vec;
}

void printArray(int arr[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

bool turnAround(int arr[][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (arr[i][j] == 0)
			{
				vector<int> vec = changeSdoqu(i, j, arr);
				if(vec.size()==1)
				{
					arr[i][j] = vec[0];
					i = 0, j = 0;
				}
				else if (vec.size() == 0) return false;
			}

	return true;
}

void copyArray(int arr[][9], int temp[][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			temp[i][j] = arr[i][j];
}


bool sdoqu(int arr[][9])
{
	if (!turnAround(arr)) return false; //채울수 있는거 채우고, 채울수 없는 칸 있으면 false;

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (arr[i][j] == 0)
			{
				vector<int> vec = changeSdoqu(i, j, arr);
				for (int z = 0; z < vec.size(); z++) //가능한 숫자 vec.size개를 다 해본다.
				{
					int temp[9][9];
					copyArray(arr, temp);
					temp[i][j] = vec[z];

					if (sdoqu(temp) == true) //true일 경우 모든 칸을 채운것.
					{
						copyArray(temp, arr);
						return true;
					}
					if (z == vec.size() - 1) return false;
				}
			}

	return true;
}



int main()
{
	int arr[9][9];

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];

	if(sdoqu(arr)) printArray(arr);
}