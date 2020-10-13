#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

struct node {
	int y, x, dis;
	node() {}
	node(int _y, int _x, int _dis) : y(_y), x(_x), dis(_dis) {}
	bool operator()(const node& o1, const node& o2) {
		bool ret = true;
		if (o1.dis < o2.dis) ret = false;
		else if (o1.dis == o2.dis) {
			if (o1.y < o2.y) ret = false;
			else if (o1.y == o2.y) {
				if (o1.x < o2.x) ret = false;
			}
		}
		return ret;
	}
};
int N, M, FUEL, CNT;
int map[20][20];
int guests[400][4];
int cy, cx;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main()
{
	scanf("%d %d %d", &N, &M, &FUEL);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	scanf("%d %d", &cy, &cx);
	cy--, cx--;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &guests[i][j]);
			guests[i][j]--;
		}
	}
	priority_queue<node, vector<node>, node> pq;
	queue<node> q;
	bool visit[20][20];
	bool find;
	int target_idx;
	node target_node;
	
	while (CNT < M)
	{
		pq.push(node(cy, cx, 0));
		memset(visit, 0, sizeof(visit));
		visit[cy][cx] = true;
		find = false;
		while (!pq.empty()) {
			node cur = pq.top();
			pq.pop();
			for (int i = 0; i < M; i++) {
				if (guests[i][0] == -1) {
					continue;
				}
				if (guests[i][0] == cur.y && guests[i][1] == cur.x) {
					find = true;
					target_idx = i;
					target_node = cur;
					guests[i][0] = -1;
					while (!pq.empty()) { // size 까지 index로 돌렸는데, 이러면안됌
						pq.pop();
					}
					break;
				}
			}
			if (find) break;

			int ny, nx, nd;
			for (int i = 0; i < 4; i++) {
				ny = cur.y + dy[i];
				nx = cur.x + dx[i];
				nd = cur.dis + 1;

				if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx] || map[ny][nx] > 0) {
					continue;
				}

				visit[ny][nx] = true;
				pq.push(node(ny, nx, nd));
			}
		}
		if (!find || FUEL < target_node.dis) {
			FUEL = -1;
			break;
		}
		else {
			FUEL -= target_node.dis;
		}

		q.push(node(target_node.y, target_node.x, 0));
		memset(visit, 0, sizeof(visit));
		visit[target_node.y][target_node.x] = true;
		find = false;

		while (!q.empty()) {
			node cur = q.front();
			q.pop();

			if (guests[target_idx][2] == cur.y && guests[target_idx][3] == cur.x) {
				target_node = cur;
				find = true;
				while (!q.empty()) { // size 까지 index로 돌렸는데, 이러면안됌
					q.pop();
				}
				break;
			}

			int ny, nx, nd;
			for (int i = 0; i < 4; i++) {
				ny = cur.y + dy[i];
				nx = cur.x + dx[i];
				nd = cur.dis + 1;

				if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx] || map[ny][nx] > 0) {
					continue;
				}

				visit[ny][nx] = true;
				q.push(node(ny, nx, nd));
			}
		}

		if (!find || FUEL < target_node.dis) {
			FUEL = -1;
			break;
		}
		else {
			FUEL += target_node.dis;
			cy = target_node.y;
			cx = target_node.x;
			CNT++;
		}
	}
	printf("%d", FUEL);
}