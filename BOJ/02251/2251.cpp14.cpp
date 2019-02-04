#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define maxnum (1<<24)

int returnWater(int N, int num)
{
	if (num == 0) return N & ((1 << 8) - 1);
	else if (num == 8) return N >> 8 & ((1 << 8) - 1);
	else return N >> 16 & ((1 << 8) - 1);
}

int waterSwelling(int N, int from, int to, int max_from, int max_to)
{
	int before_from = returnWater(N, from),
		before_to = returnWater(N, to),
		after_from, after_to;

	if (before_from == 0) return 0; //붓는곳이 0임
	if (before_to == max_to) return 0; //부을곳이 꽉참

	if (max_to - before_to >= before_from) //다 부을수 있음
	{
		after_from = 0;
		after_to = before_to + before_from;
	}
	else //다 못부음
	{
		after_from = before_from - (max_to - before_to);
		after_to = before_to + (before_from - after_from);
	}

	return (returnWater(N, 24 - from - to) << (24 - from - to)) | after_from << from | after_to << to;
}

int bitMask(int A, int B, int C)
{
	return (A << 16) + (B << 8) + C;
}

void waterCase(int A, int B, int C)
{
	vector<int> vec;
	bool *check = new bool[maxnum];
	for (int i = 0; i < maxnum; i++) check[i] = false;
	queue<int> que;

	que.push(bitMask(0, 0, C));
	check[que.front()] = true;

	while (!que.empty())
	{
		if (returnWater(que.front(), 16) == 0) vec.push_back(returnWater(que.front(), 0)); //A가 비면 C 넣는다.

		if (waterSwelling(que.front(), 0, 16, C, A) > 0 && !check[waterSwelling(que.front(), 0, 16, C, A)]) //C to A
			check[waterSwelling(que.front(), 0, 16, C, A)] = true, que.push(waterSwelling(que.front(), 0, 16, C, A));
		if (waterSwelling(que.front(), 0, 8, C, B) > 0 && !check[waterSwelling(que.front(), 0, 8, C, B)]) //C to B
			check[waterSwelling(que.front(), 0, 8, C, B)] = true, que.push(waterSwelling(que.front(), 0, 8, C, B));
		if (waterSwelling(que.front(), 8, 16, B, A) > 0 && !check[waterSwelling(que.front(), 8, 16, B, A)]) //B to A
			check[waterSwelling(que.front(), 8, 16, B, A)] = true, que.push(waterSwelling(que.front(), 8, 16, B, A));
		if (waterSwelling(que.front(), 8, 0, B, C) > 0 && !check[waterSwelling(que.front(), 8, 0, B, C)]) //B to C
			check[waterSwelling(que.front(), 8, 0, B, C)] = true, que.push(waterSwelling(que.front(), 8, 0, B, C));
		if (waterSwelling(que.front(), 16, 8, A, B) > 0 && !check[waterSwelling(que.front(), 16, 8, A, B)]) //A to B
			check[waterSwelling(que.front(), 16, 8, A, B)] = true, que.push(waterSwelling(que.front(), 16, 8, A, B));
		if (waterSwelling(que.front(), 16, 0, A, C) > 0 && !check[waterSwelling(que.front(), 16, 0, A, C)]) //A to C
			check[waterSwelling(que.front(), 16, 0, A, C)] = true, que.push(waterSwelling(que.front(), 16, 0, A, C));

		que.pop();
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	waterCase(A, B, C);
}