#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define maxnum 1000

int cache1[maxnum + 3]; //증가하는 부분수열
int cache2[maxnum + 3]; //감소하는 부분수열
int longestSumSequence(int n, int arr[])
{
	for (int i = 0; i < n; i++) //초기화
		cache1[i] = cache2[i] = 1; 

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++) //자기보다 작은수 찾고
			if (arr[j] < arr[i] && cache1[j] + 1 > cache1[i]) // 이었을때 더 큰 값이면 
				cache1[i] = cache1[j] + 1;


	for (int i = n-1; i >=0; i--)
		for (int j = i; j < n; j++) //뒤로 가면서 자기보다 작은 수
			if (arr[j] < arr[i] && cache2[j] + 1 > cache2[i]) // 이었을때 더 큰 값이면 
				cache2[i] = cache2[j] + 1;

	for (int i = 0; i < n; i++) cache2[i] += cache1[i] - 1;

	return *max_element(&cache2[0], &cache2[n]);
}

int main()
{
	int arr[maxnum + 3], n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << longestSumSequence(n, arr) << endl;
}