#include <stdio.h>

using namespace std;

struct shark {
	bool isDead;
	int y, x, d;
	int p[5][5];
};
int dy[] = { 0, -1, 1, 0, 0 };
int dx[] = { 0, 0, 0, -1, 1 };
int N, M, K;
int map[21][21];
int smell[21][21];
int time[21][21];
shark sharks[401];

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] > 0) {
				int &n = map[y][x];
				shark& s = sharks[n];
				s.y = y;
				s.x = x;
				time[y][x] = K;
				smell[y][x] = n;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &sharks[i].d);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			scanf("%d %d %d %d", &sharks[i].p[j][1], &sharks[i].p[j][2], &sharks[i].p[j][3], &sharks[i].p[j][4]);
		}
	}
	shark ss[10];
	int to = 0, answer = -1;
	int ny, nx, nd;
	bool isMove, isAlive;
	while (to++ < 1000)
	{
		for (int i = 1; i <= M; i++)
		{
			shark& s = sharks[i];
			if (s.isDead) continue;
			isMove = false;
			for (int j = 1; j <= 4; j++) {
				nd = s.p[s.d][j];
				ny = s.y + dy[nd];
				nx = s.x + dx[nd];
				if (ny > 0 && nx > 0 && ny <= N && nx <= N && !smell[ny][nx]) {
					if (map[ny][nx] > 0) {
						s.isDead = true;
						map[s.y][s.x] = 0;
						isMove = true;
						break;
					}
					else {
						map[s.y][s.x] = 0;
						map[ny][nx] = i;
						s.y = ny;
						s.x = nx;
						s.d = nd;
						isMove = true;
						break;
					}
				}
			}

			if (isMove) continue;

			for (int j = 1; j <= 4; j++) {
				nd = s.p[s.d][j];
				ny = s.y + dy[nd];
				nx = s.x + dx[nd];
				if (ny > 0 && nx > 0 && ny <= N && nx <= N && smell[ny][nx] == i) {
					map[s.y][s.x] = 0;
					map[ny][nx] = i;
					s.y = ny;
					s.x = nx;
					s.d = nd;
					break;
				}
			}
		}
		for (int i = 1; i <= M; i++) {
			shark& s = sharks[i];
			if (s.isDead) continue;
			smell[s.y][s.x] = i;
			time[s.y][s.x] = K + 1;
		}
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (time[y][x] > 0) {
					time[y][x]--;
					if (time[y][x] == 0) {
						smell[y][x] = 0;
					}
				}
			}
		}

		isAlive = false;
		for (int i = 2; i <= M; i++) {
			if (!sharks[i].isDead) {
				isAlive = true;
				break;
			}
		}
		if (!isAlive) {
			answer = to;
			break;
		}
	}
	printf("%d", answer);
	return 0;
}