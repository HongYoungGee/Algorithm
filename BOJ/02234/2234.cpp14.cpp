#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool isWall(int num, int way) // 방향에 벽이 있으면 treu, 1서, 2북, 4동, 8남
{
	return num & way;
}

bool canVisit(int n, int m, int x, int y, int arr[][51], int way) //방문할수 있으면 true
{
	if (way == 1 && y != 0 && arr[x][y -1] == 0) return true; //서쪽
	else if (way == 2 && x != 0 && arr[x-1][y] == 0) return true; //북쪽
	else if (way == 4 && y != n-1 && arr[x][y+1] == 0) return true; //동쪽
	else if (way == 8 && x != m-1 && arr[x+1][y] == 0) return true;

	return false;
}

void insert_arr(int n, int m, int wall[][51]) //배열 입력
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> wall[i][j];
}

int fillRoom(int n, int m, int x, int y, int wall[][51], int arr[][51], int count) //x,y 좌표에서 순회하며 방 채우기
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	int room_size = 0;
	arr[x][y] = count;

	while (!q.empty())
	{
		room_size++;	

		if (!isWall(wall[q.front().first][q.front().second], 1) && canVisit(n, m, q.front().first, q.front().second, arr, 1)) //서쪽에 벽이 없다면
		{
			q.push(make_pair(q.front().first, q.front().second - 1));
			arr[q.front().first][q.front().second-1] = count;
		}
		if (!isWall(wall[q.front().first][q.front().second], 2) && canVisit(n, m, q.front().first, q.front().second, arr, 2)) //북쪽에 벽이 없다면
		{
			q.push(make_pair(q.front().first - 1, q.front().second));
			arr[q.front().first-1][q.front().second] = count;
		}
		if (!isWall(wall[q.front().first][q.front().second], 4) && canVisit(n, m, q.front().first, q.front().second, arr, 4)) //동쪽에 벽이 없다면
		{
			q.push(make_pair(q.front().first, q.front().second + 1));
			arr[q.front().first][q.front().second+1] = count;
		}
		if (!isWall(wall[q.front().first][q.front().second], 8) && canVisit(n, m, q.front().first, q.front().second, arr, 8)) //남쪽에 벽이 없다면
		{
			q.push(make_pair(q.front().first + 1, q.front().second));
			arr[q.front().first+1][q.front().second] = count;
		}

		q.pop();
	}

	return room_size;
}

vector<int> numberOfRomm(int n, int m, int wall[][51], int arr[][51]) //방의 넓이를 벡터에 저장, 같은 방은 같은 번호로 arr배열에 저장
{
	int count=0;
	vector<int> sizeOfRoom; //1번 방 크기 [0], 2번방 크기 [1]...

	for (int i = 0; i < m; i++) //배열을 순회하며 값이 없으면 방크기 탐색
		for (int j = 0; j < n; j++)
			if (arr[i][j] == 0)
				sizeOfRoom.push_back(fillRoom(n, m, i, j, wall, arr, ++count));

	return sizeOfRoom;
}

int removeWall(int n, int m, int arr[][51], vector<int> sizeOfRoom) //인접한 배열을 비교하여 최대값 찾기
{
	int max = sizeOfRoom.front();
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (j != n - 1 && arr[i][j] != arr[i][j + 1]) //오른쪽 비교
				if (sizeOfRoom[arr[i][j] - 1] + sizeOfRoom[arr[i][j + 1] - 1] > max)
					max = sizeOfRoom[arr[i][j] - 1] + sizeOfRoom[arr[i][j + 1] - 1];
			if (i != m - 1 && arr[i][j] != arr[i + 1][j]) //아래 비교
				if (sizeOfRoom[arr[i][j] - 1] + sizeOfRoom[arr[i + 1][j] - 1] > max)
					max = sizeOfRoom[arr[i][j] - 1] + sizeOfRoom[arr[i + 1][j] - 1];
		}

	return max;
}

int main()
{
	int n, m, wall[51][51], arr[51][51] = { 0 }; //wall 벽의정보, arr 방 정보
	cin >> n >> m;
	
	insert_arr(n, m, wall);
	vector<int> sizeOfRoom=numberOfRomm(n, m, wall, arr);
	
	cout << sizeOfRoom.size() << endl; //방의 갯수
	cout << *max_element(sizeOfRoom.begin(), sizeOfRoom.end()) << endl; //가장 넓은 방
	cout << removeWall(n, m, arr, sizeOfRoom) << endl; //하나의 벽 제거 넓은방
}