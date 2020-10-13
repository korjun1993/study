#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// priority queue 와 vector 정렬 기준의 차이점
// vector -> 조건식의 값이 false 이면 순서를 바꿈
// priority queue -> 조건식의 값이 true 이면 순서를 바꿈

struct test {
	int x1, x2;
	test() {};
	test(int _x1, int _x2) : x1(_x1), x2(_x2) {};
	bool operator() (test o1, test o2) {
		return o1.x1 > o2.x1; // true 이면 바꿈...
	}
};

bool compare(test& o1, test& o2) {
	return o1.x1 > o2.x1; // false 이면 바꿈...
}

int main()
{
	priority_queue<test, vector<test>, test> pq;
	
	pq.push(test(1, 2));
	pq.push(test(3, 2));
	pq.push(test(2, 2));
	pq.push(test(7, 2));
	pq.push(test(6, 2));
	pq.push(test(4, 2));
	pq.push(test(5, 2));

	while (!pq.empty()) {
		test t = pq.top();
		pq.pop();
		printf("%d %d\n", t.x1, t.x2);
	}
	printf("\n");
	vector<test> v;
	v.push_back(test(1, 2));
	v.push_back(test(2, 2));
	v.push_back(test(3, 2));
	v.push_back(test(4, 2));
	v.push_back(test(5, 2));
	v.push_back(test(6, 2));
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].x1, v[i].x2);
	}
}