#include <cstdio>


int main() {
	int e = 0, s = 0, m = 0;
	int answer = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &e, &s, &m);
	answer = s;
	if (e == 15) e = 0;
	if (s == 28) s = 0;
	if (m == 19) m = 0;
	while (true) {
		if (answer % 15 == e && answer % 19 == m) break;
		answer += 28;
	}

	printf("%d\n", answer);
	return 0;
}