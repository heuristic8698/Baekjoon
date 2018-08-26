#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void dfs_rq(int start, vector<int>* edge, bool* visit) {
	visit[start] = true;
	printf("%d ", start);

	for (int i = 0; i < edge[start].size(); i++) {
		if (!visit[edge[start][i]]) {
			dfs_rq(edge[start][i], edge, visit);
		}
	}
}

void dfs(int start, vector<int>* edge, bool* visit) {
	stack<int> s;
	visit[start] = true;
	printf("%d ", start);
	s.push(start);
	while (!s.empty()) {
		int now = s.top();
		s.pop();
		for (int i = 0; i < edge[now].size(); i++) {
			if (!visit[edge[now][i]]) {
				visit[edge[now][i]] = true;
				printf("%d ", edge[now][i]);
				s.push(now);
				s.push(edge[now][i]);
				break;
			}
		}
	}
}

void bfs(int start, vector<int>* edge, bool* visit) {
	queue<int> q;
	visit[start] = true;
	printf("%d ", start);
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < edge[now].size(); i++) {
			if (!visit[edge[now][i]]) {
				visit[edge[now][i]] = true;
				printf("%d ", edge[now][i]);
				q.push(edge[now][i]);
			}
		}
	}
}

// n 정점의 개수, m 간선의 개수, v 시작 정점
int main() {
	int n = 0, m = 0, v = 0;
	int a = 0, b = 0;
	vector<int> edge[1001];
	bool d_visit[1001] = { 0, };
	bool b_visit[1001] = { 0, };
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	// 정점이 작은 것부터 출력하라는 조건이 있기 때문에 
	for (int i = 0; i < n; i++)
	{
		sort(edge[i].begin(), edge[i].end());
		edge[i].erase(unique(edge[i].begin(), edge[i].end()), edge[i].end());
	}

	dfs(v, edge, d_visit);
	printf("\n");
	bfs(v, edge, b_visit);
	printf("\n");
	return 0;
}