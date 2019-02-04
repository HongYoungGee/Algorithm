#include <iostream>
using namespace std;

int serch(int *arr,int b,int num)
{
	for (int i = 0; i <num; i++) //n이 최대 1000
	{
		if (arr[i] == b)
			return i;
	}
	return 0;
}

void Postorder(int *arr1, int *arr2,int *ans, int start,int length,int num)
{
	int left = 0, right = 0;
	static int len = 0;
	int temp = serch(arr2, arr1[len],num);
	
	for (int i = temp - 1; i >= 0; i--)
	{
		if (arr2[i] > 0)
			left++;
		else
			break;
	}

	for (int i = temp + 1; i < num; i++)
	{
		if (arr2[i] > 0)
			right++;
		else
			break;
	}

	ans[start + length - 1] = arr1[len];
	arr2[temp] = 0;

	if (left > 0)
	{
		len++;
		Postorder(arr1, arr2, ans, start, left,num);
	}
	if (right > 0)
	{
		len++;
		Postorder(arr1, arr2, ans, start + left, right,num);
	}

	if (len == num-1)
		len = 0;
}

int main()
{
	int T, num, *arr1, *arr2,*ans;
	cin >> T;  //문제의 갯수
	
	while (T--)
	{
		cin >> num;
		arr1 = new int[num]; //전위순회
		arr2 = new int[num]; //중위순회
		ans = new int[num];

		for (int i = 0; i < num; i++)
			cin >> arr1[i];
		
		for (int i = 0; i < num; i++)
			cin >> arr2[i];
		for (int i = 0; i < num; i++)
			ans[i] = 0;

		Postorder(arr1, arr2, ans, 0, num,num);

		for (int i = 0; i < num; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}