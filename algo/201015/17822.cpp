#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct NODE {
	int y, x;
	NODE(int _y, int _x) : y(_y), x(_x) {}
};

int N, M, T;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int board[50][50];

int bfs(NODE node, bool(*visited)[50])
{
	queue<NODE> q;
	vector<NODE> v;
	visited[node.y][node.x] = true;
	q.push(node);
	while (!q.empty()) {
		NODE n = q.front();
		q.pop();
		int ny, nx;
		for (int d = 0; d < 4; d++) {
			ny = n.y + dy[d];
			nx = n.x + dx[d];
			if (nx < 0) {
				nx += M;
			}
			else if (nx >= M) {
				nx -= M;
			}
			if (ny >= N || ny < 0 || visited[ny][nx] || board[n.y][n.x] != board[ny][nx]) {
				continue;
			}
			visited[ny][nx] = true;
			q.push(NODE(ny, nx));
			v.push_back(NODE(ny, nx));
		}
	}

	if (v.size() > 0) {
		board[node.y][node.x] = 0;
		for (int i = 0; i < v.size(); i++) {
			NODE &n = v[i];
			board[n.y][n.x] = 0;
		}
	}

	return v.size();
}

void rotate(int idx, int num)
{
	queue<NODE> tmp;
	vector<NODE> v;
	bool visited[50][50] = { false, };
	int board_copy[50][50] = { 0, };
	int start_y = idx - 1;
	int count_del = 0;
	int count_num = 0;
	int sum = 0;

	for (int y = start_y; y < N; y += idx) {
		for (int x = 0; x < M; x++) {
			int nx = x - num;
			if (nx < 0) {
				nx += M;
			}
			board_copy[y][x] = board[y][nx];
		}
	}
	for (int y = start_y; y < N; y += idx) {
		for (int x = 0; x < M; x++) {
			board[y][x] = board_copy[y][x];
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] > 0) {
				count_del += bfs(NODE(y, x), visited);
				v.push_back(NODE(y,x));
			}
		}
	}

	if (count_del == 0) {
		double sum = 0;
		double avr = 0;
		for (int i = 0; i < v.size(); i++) {
			NODE& n = v[i];
			sum += board[n.y][n.x];
		}
		avr = sum / v.size();
		for (int i = 0; i < v.size(); i++) {
			NODE& n = v[i];
			if (board[n.y][n.x] > avr) {
				board[n.y][n.x]--;
			}
			else if(board[n.y][n.x] < avr){
				board[n.y][n.x]++;
			}
		}
	}
}

int sum() {
	int sum = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			sum += board[y][x];
		}
	}
	return sum;
}

int main()
{
	scanf("%d %d %d", &N, &M, &T);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d", &board[y][x]);
		}
	}
	for (int t = 0; t < T; t++) {
		int idx, dir, num;
		scanf("%d %d %d", &idx, &dir, &num);
		if (dir == 1) {
			num = M - num;
		}
		rotate(idx, num);
	}

	int ret = sum();
	printf("%d", ret);
	
}