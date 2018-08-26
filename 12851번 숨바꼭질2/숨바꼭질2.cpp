#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int n = 0, k = 0;
	int answer = 0;
	queue<int> q;
	bool visit[100001] = { 0, };
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	q.push(n);
	while (!q.empty()) {
		int size = q.size();
		int way = 0;
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			visit[now] = true;
			if (now == k) {
				way++;
				continue;
			}
			if (now - 1 >= 0 && !visit[now - 1]) {
				q.push(now - 1);
			}
			if (now + 1 <= 100000 && !visit[now + 1]) {
				q.push(now + 1);
			}
			if (now * 2 <= 100000 && !visit[now * 2]) {
				q.push(now * 2);
			}
		}
		if (way) {
			printf("%d\n%d\n", answer, way);
			break;
		}
		answer++;
		way = 0;
	}
	return 0;
}