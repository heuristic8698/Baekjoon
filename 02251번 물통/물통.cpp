#include <cstdio>
#include <queue>
#include <set>

using namespace std;

typedef struct water{
	int a, b, c;
}wt;

void bfs(wt state) {
	queue<wt> q;
	set<int> answer;
	int visited[201][201] = { 0, };
	q.push({ 0,0,state.c });

	while (!q.empty()) {
		wt now = q.front(); q.pop();

		if (visited[now.a][now.b]) continue;
		visited[now.a][now.b] = true;

		if (now.a == 0) {
			answer.insert(now.c);
		}

		// a->b
		if (now.a + now.b > state.b) q.push({ now.a + now.b - state.b, state.b, now.c });
		else q.push({ 0, now.a + now.b, now.c });
		// a<-b
		if (now.a + now.b > state.a) q.push({ state.a, now.a + now.b - state.a, now.c });
		else q.push({ now.a + now.b, 0, now.c });
		// a->c
		if (now.a + now.c > state.c) q.push({ now.a + now.c - state.c, now.b, state.c });
		else q.push({ 0, now.b, now.a + now.c });
		// a<-c
		if (now.a + now.c > state.a) q.push({ state.a, now.b, now.a + now.c - state.a });
		else q.push({ now.a + now.c, now.b, 0 });
		// b->c
		if (now.b + now.c > state.c) q.push({ now.a, now.b + now.c - state.b, state.c });
		else q.push({ now.a, 0, now.b + now.c });
		// b<-c
		if (now.b + now.c > state.b) q.push({ now.a, state.b, now.b + now.c - state.b });
		else q.push({ now.a, now.b + now.c, 0 });
	}

	for (set<int>::iterator iter = answer.begin(); iter != answer.end(); iter++) {
		printf("%d ", *iter);
	}
}

int main() {
	wt state;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &state.a, &state.b, &state.c);
	bfs(state);
	return 0;
}