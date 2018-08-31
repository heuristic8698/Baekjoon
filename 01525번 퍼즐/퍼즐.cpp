#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int bfs(long start) {
	queue<long> q;
	set<long> visited;
	int move[4] = {12, -12, 4, -4};
	int dx[4] = {-1,1,0,0,};
	int dy[4] = {0,0,-1,1};
	int answer = 0;
	long dest = 0;
	for (int i = 1; i < 9; i++) {
		dest = (dest << 4) + i;
	}
	dest <<= 4;

	visited.insert(start);
	q.push(start);

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			long now = q.front(); q.pop();
			if (now == dest) {
				return answer;
			}
			int pos = 0;
			while (now & (15L << pos * 4)){
				pos++;
			}
			int x = pos / 3;
			int y = pos % 3;

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || nx>2 || ny < 0 || ny>2) continue;
				long temp = now & (15L << (nx * 3 + ny) * 4);
				long next = now - temp;
				// pos가 역순으로 계산 되었기 때문에 상하좌우의 위치가 반대
				if (move[d] > 0) temp <<= move[d];
				else temp >>= -move[d];
				next += temp;

				if (visited.find(next) == visited.end()) {
					q.push(next);
					visited.insert(next);
				}

			}
		}
		answer++;
	}
	return -1;
}

int main() {
	long start = 0;
	int a = 0;
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a);
		start = (start << 4) + a;
	}
	printf("%d\n", bfs(start));
	return 0;
}