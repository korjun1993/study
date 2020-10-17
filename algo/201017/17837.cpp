#include <stdio.h>

struct CHESS {
	int y, x, z, d;
};

int N, K;
int color[12][12];
int level[12][12];
int board[12][12][10];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
CHESS chess[11];

bool move(int num, int count) {
	CHESS& now = chess[num];
	int ny, nx;
	ny = now.y + dy[now.d];
	nx = now.x + dx[now.d];
	
	// 맵을 벗어나거나 파란색인 경우
	if (ny < 0 || nx < 0 || ny >= N || nx >= N || color[ny][nx] == 2) {
		if (count == 1) {
			return false;
		}
		if (now.d % 2 == 0) {
			now.d += 1;
		}
		else {
			now.d -= 1;
		}
		return move(num, 1);
	}

	// 흰색인 경우
	else if (color[ny][nx] == 0) {
		int z = now.z;
		int y = now.y;
		int x = now.x;
		int h = level[y][x];
		for (int i = z; i < h; i++) {
			int num = board[y][x][i];
			int idx = level[ny][nx];
			if (idx == 3) {
				return true;
			}
			board[ny][nx][idx] = board[y][x][i];
			board[y][x][i] = 0;
			level[ny][nx]++;
			level[y][x]--;
			chess[num].y = ny;
			chess[num].x = nx;
			chess[num].z = idx;
		}
	}

	// 빨간색인 경우
	else if (color[ny][nx] == 1) {
		int z = now.z;
		int y = now.y;
		int x = now.x;
		int h = level[y][x] - 1;
		for (int i = h; i >= z; i--) {
			int num = board[y][x][i];
			int idx = level[ny][nx];
			if (idx == 3) {
				return true;
			}
			board[ny][nx][idx] = board[y][x][i];
			board[y][x][i] = 0;
			level[ny][nx]++;
			level[y][x]--;
			chess[num].y = ny;
			chess[num].x = nx;
			chess[num].z = idx;
		}
	}

	return false;
}

int solve(){
	bool ret = false;
	int turn = 0;
	while (++turn < 1000){
		for (int n = 1; n <= K; n++) {
			ret = move(n, 0);
			if (ret == true) {
				return turn;
			}
		}
	}
	return turn == 1000 ? -1 : turn;
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &color[y][x]);
		}
	} // 0:흰색, 1:빨간색, 2:파란색

	for (int i = 1; i <= K; i++) {
		int y, x, d;
		scanf("%d %d %d", &y, &x, &d);
		y--, x--, d--;
		board[y][x][0] = i;
		chess[i].y = y;
		chess[i].x = x;
		chess[i].d = d;
		chess[i].z = 0;
		level[y][x]++;
	}

	int ret = solve();
	printf("%d", ret);
}