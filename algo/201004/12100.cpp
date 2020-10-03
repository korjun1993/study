/*
 * 구현		: 1시간 
 * 디버깅	: 2시간
 * 
 * 구현 전 순서도 작성,
 * 순서도 바탕으로 시뮬레이션 필요!!!
 */
#include <stdio.h>

#define N 20

using namespace std;

int n, answer = 0;
int map[N][N];

void move(int(*arr)[20], int cnt)
{
	if (cnt >= 5)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (answer < arr[y][x])
					answer = arr[y][x];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int loc = 0;
		int arr_copy[N][N];
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				arr_copy[y][x] = arr[y][x];
			}
		}
		
		if (i == 0) {
			for (int x = 0; x < n; x++)
			{
				// 1. 숫자를 모두 위로 올려줬음.
				loc = 0;
				for (int y = 0; y < n; y++)
				{
					if (arr_copy[y][x] > 0) {
						int tmp = arr_copy[y][x];
						arr_copy[y][x] = 0;
						arr_copy[loc++][x] = tmp;
					}
				}
				loc = 0;
				for (int y = 0; y < n; y++)  
				{
					if (arr_copy[y][x] == 0) continue;
					if (y < n - 1 && arr_copy[y][x] == arr_copy[y + 1][x])
					{
						/* 
						 * 숫자를 arr_copy 에 대입은 했으나, 
						 * 0으로 초기화하지 않아서 계속 틀렸음.
						 */
						int tmp = arr_copy[y][x] * 2;
						arr_copy[y][x] = 0;
						arr_copy[y + 1][x] = 0;
						arr_copy[loc++][x] = tmp;
					}

					else {
						int tmp = arr_copy[y][x];
						arr_copy[y][x] = 0;
						arr_copy[loc++][x] = tmp;
					}
				}
			}
		}
		else if (i == 1) {
			for (int x = 0; x < n; x++)
			{
				// 1. 숫자를 모두 아래로 내려줬음.
				loc = n - 1;
				for (int y = n - 1; y >= 0; y--)
				{
					if (arr_copy[y][x] > 0) {
						int tmp = arr_copy[y][x];
						arr_copy[y][x] = 0;
						arr_copy[loc--][x] = tmp;
					}
				}
				loc = n - 1;
				for (int y = n - 1; y >= 0; y--)
				{
					if (arr_copy[y][x] == 0) continue;
					if (y > 0 && arr_copy[y][x] == arr_copy[y - 1][x])
					{
						int tmp = arr_copy[y][x] * 2;
						arr_copy[y][x] = 0;
						arr_copy[y - 1][x] = 0;
						arr_copy[loc--][x] = tmp;
					}
					else {
						int tmp = arr_copy[y][x];
						arr_copy[y][x] = 0;
						arr_copy[loc--][x] = tmp;
					}
				}
			}
		}
		else if (i == 2) {
			for (int y = 0; y < n; y++)
			{
				loc = 0;
				for (int x = 0; x < n; x++) {
					if (arr_copy[y][x] > 0) {
						int tmp = arr_copy[y][x];
						arr_copy[y][x] = 0;
						arr_copy[y][loc++] = tmp;
					}
				}
				loc = 0;
				for (int x = 0; x < n; x++)
				{
					if (arr_copy[y][x] == 0) continue;
					if (x < n - 1 && arr_copy[y][x] == arr_copy[y][x + 1])
					{
						int tmp = arr_copy[y][x] * 2;
						arr_copy[y][x] = 0;
						arr_copy[y][x + 1] = 0;
						arr_copy[y][loc++] = tmp;
					}
					else {
						int tmp = arr_copy[y][x];
						arr_copy[y][x] = 0;
						arr_copy[y][loc++] = tmp;
					}
				}
			}
		}
		else if (i == 3) {
			for (int y = 0; y < n; y++)
			{
				loc = n - 1;
				for (int x = n - 1; x >= 0; x--)
				{
					if (arr_copy[y][x] > 0) {
						int tmp = arr_copy[y][x];
						arr_copy[y][x] = 0;
						arr_copy[y][loc--] = tmp;
					}
				}
				loc = n - 1;
				for (int x = n - 1; x >= 0; x--)
				{
					if (arr_copy[y][x] == 0) continue;
					if (x > 0 && arr_copy[y][x] == arr_copy[y][x - 1])
					{
						int tmp = arr_copy[y][x] * 2;
						arr_copy[y][x] = 0;
						arr_copy[y][x - 1] = 0;
						arr_copy[y][loc--] = tmp;
					}
					else {
						int tmp = arr_copy[y][x];
						arr_copy[y][x] = 0;
						arr_copy[y][loc--] = tmp;
					}
				}
			}
		}

		move(arr_copy, cnt + 1);
	}
}

int main()
{
	scanf("%d", &n);
	
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			scanf("%d", &map[y][x]);
		}
	}

	move(map, 0);
	printf("%d", answer);
}