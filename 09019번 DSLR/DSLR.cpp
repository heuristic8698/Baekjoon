#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

char op[4] = { 'D', 'S', 'L', 'R' };

int op_d(int x) {
	return (x * 2) % 10000;
}

int op_s(int x) {
	return (x + 9999) % 10000;
}

int op_l(int x) {
	int a = x / 1000;
	x %= 1000;
	return (x * 10) + a;
}

int op_r(int x) {
	int a = x % 10;
	x /= 10;
	return (a * 1000) + x;
}

void bfs(int a, int b) {
	bool visit[10001] = { 0, };
	char ops[10001] = { 0, };
	int back[10001] = { 0, };
	vector<char> answer;
	queue<int> q;
	q.push(a);
	visit[a] = true;
	int dslr[4];
	while (q.front() != b && !q.empty()) {
		int now = q.front(); q.pop();
		dslr[0] = op_d(now);
		dslr[1] = op_s(now);
		dslr[2] = op_l(now);
		dslr[3] = op_r(now);
		for (int i = 0; i < 4; i++) {
			if (!visit[dslr[i]]) {
				q.push(dslr[i]);
				visit[dslr[i]] = true;
				ops[dslr[i]] = op[i];	// 연산에 사용된 명령 문자
				back[dslr[i]] = now;		// 연산하기 이전 숫자 저장
			}
		}
	}

	while (a != b) {
		answer.push_back(ops[b]);
		b = back[b];
	}
	for (int i = answer.size() - 1; i >= 0; i--) {
		printf("%c", answer[i]);
	}
	printf("\n");
}

int main() {
	int t = 0;
	int a = 0, b = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		bfs(a, b);
	}
	return 0;
}