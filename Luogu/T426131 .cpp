#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, v=0, w=0;
	scanf("%d%d", &n, &m);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a & 1) v += b;
		w += b;
	}
	printf("%.3f\n", (double)m * v / w);
	return 0;
}
