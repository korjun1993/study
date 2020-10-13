#include <stdio.h>

int dy[][4] = { {0,0,0,0},{0,0,1,1},{0,1,2,2},{0,1,1,2},{0,0,0,1},{0,1,1,2},{0,1,2,2} };
int dx[][4] = { {0,1,2,3},{0,1,0,1},{0,0,0,1},{0,0,1,1},{0,1,2,1},{1,0,1,0},{1,1,0,1} };

int answer;
int n, m;
int map[500][500];

void dfs(int y, int x, int row_size, int col_size) {
	int ny, nx;
	bool flag;

	for (int i = 0; i < 7; i++) {
		flag = true;
		for (int j = 0; j < 4; j++) {
			ny = y + dy[i][j];
			nx = x + dx[i][j];
			if (ny < 0 || ny >= row_size || nx < 0 || nx >= col_size) {
				flag = false;
				break;
			}
		}
		
		if (flag) {
			int sum = 0;
			for (int j = 0; j < 4; j++) {
				ny = y + dy[i][j];
				nx = x + dx[i][j];
				sum += map[ny][nx];
			}
			if (answer < sum) {
				answer = sum;
			}
		}
	}
}

void rotate(){
	int tmp[500][500];

	int temp = n;
	n = m;
	m = temp;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			tmp[y][x] = map[m - 1 - x][y];
		}
	}

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			map[y][x] = 0;
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			map[y][x] = tmp[y][x];
		}
	}
}

int main()
{
	answer = 0;
	scanf("%d %d", &n, &m);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				dfs(y, x, n, m);
			}
		}
		if (i == 3) continue;
		rotate();
	}

	printf("%d", answer);
	return 0;
}