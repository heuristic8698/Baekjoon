#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_NUM 9

using namespace std;

int main() {
	int total = 0;
	int a = 0;
	vector<int> v;
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < MAX_NUM; i++) {
		scanf("%d", &a);
		total += a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < MAX_NUM-1; i++) {
		for (int j = i + 1; j < MAX_NUM; j++) {
			if (total - v[i] - v[j] == 100) {
				v[i] = 0;
				v[j] = 0;
				break;
			}
		}
		if (v[i] == 0)break;
	}

	for (int i = 0; i < MAX_NUM; i++) {
		if (v[i]) printf("%d\n", v[i]);
	}
	return 0;
}