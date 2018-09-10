#include <cstdio>

int func(int n) {
	if (n < 2) return 0;
	int a = func(n / 2) + n % 2 + 1;
	int b = func(n / 3) + n % 3 + 1;
	return a < b ? a : b;
}

int main() {
	int n = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	printf("%d\n", func(n));
	return 0;
}