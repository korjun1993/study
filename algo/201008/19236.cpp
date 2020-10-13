#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int y, x, d, n;
	bool isAlive;
};

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int map[4][4];
int shark_eat;
node fish[16];

void node_arr_copy(node origin[], node dest[]) {
	for (int i = 0; i < 16; i++) {
		dest[i] = origin[i];
	}
}

void arr_copy(int(*origin)[4], int(*dest)[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dest[i][j] = origin[i][j];
		}
	}
}

bool compare(node n1, node n2)		{ return n1.n < n2.n; }

void dfs(node f[16], int (*_map)[4], int eaten_y, int eaten_x, int ret)
{
	// 상어 물고기 사냥
	int pos = _map[eaten_y][eaten_x] - 1;
	int dir = f[pos].d;
	f[pos].isAlive = false;
	ret += _map[eaten_y][eaten_x];
	_map[eaten_y][eaten_x] = 0;

	// 물고기 이동
	int ny, nx, nd;
	for (int i = 0; i < 16; i++) {
		if (!f[i].isAlive) continue;
		for (int j = 0; j < 8; j++) {
			nd = (f[i].d + j) % 8;
			ny = f[i].y + dy[nd];
			nx = f[i].x + dx[nd];
			if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4 && !(ny == eaten_y && nx == eaten_x)) {
				if (_map[ny][nx] == 0) {
					_map[f[i].y][f[i].x] = 0;
					_map[ny][nx] = f[i].n;
					f[i].y = ny;
					f[i].x = nx;
					f[i].d = nd;
				}
				else {
					int tmp = _map[f[i].y][f[i].x];
					int pos = _map[ny][nx] - 1;
					_map[f[i].y][f[i].x] = _map[ny][nx];
					_map[ny][nx] = tmp;
					f[pos].y = f[i].y;
					f[pos].x = f[i].x;
					f[i].y = ny;
					f[i].x = nx;
					f[i].d = nd;
				}
				break;
			}
		}
	}

	// 먹이 후보 선정
	while (true) {
		eaten_y += dy[dir];
		eaten_x += dx[dir];
		if (eaten_y >= 0 && eaten_y < 4 && eaten_x >= 0 && eaten_x < 4) {
			if (_map[eaten_y][eaten_x] == 0) continue;
			node fish_copy[16];
			node_arr_copy(f, fish_copy);
			int map_copy[4][4];
			arr_copy(_map, map_copy);
			dfs(fish_copy, map_copy, eaten_y, eaten_x, ret);
		}
		else {
			if (ret > shark_eat) shark_eat = ret;
			return;
		}
	}
}

int main()
{
	int n, d, i = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			scanf("%d %d", &n, &d);
			map[y][x] = n;
			fish[i].y = y;
			fish[i].x = x;
			fish[i].n = n;
			fish[i].d = d - 1;
			fish[i].isAlive = true;
			i++;
		}
	}
	sort(fish, fish + 16, compare);
	dfs(fish, map, 0, 0, 0);
	printf("%d", shark_eat);
	return 0;
}