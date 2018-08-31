#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define ii pair<int, int>
using namespace std;

int bfs(int s) {
	bool visited[1001][1001] = { 0, };
	int answer = 0;
	queue<ii> q;
	q.push({ 1,0 });
	visited[1][0] = 1;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			ii now = q.front(); q.pop();
			int len = now.first;
			int clip = now.second;
			if (len == s) {
				return answer;
			}
			q.push({ len, len });
			if (clip && len + clip <= 1000 && !visited[len + clip][clip]) {
				q.push({ len + clip, clip });
				visited[len + clip][clip] = true;
			}
			if (len > 0 && !visited[len - 1][clip]) {
				q.push({ len - 1, clip });
				visited[len - 1][clip] = true;;
			}
		}
		answer++;
	}
	return -1;
}

int main() {
	int s = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &s);
	printf("%d\n", bfs(s));
	return 0;
}