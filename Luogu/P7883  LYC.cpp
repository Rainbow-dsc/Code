#include <stdio.h>
#include <algorithm>
struct point {
	int x, y;
	bool operator < (const point p) {
		return x < p.x;
	}
} a[400001], d[200001];
long long CDQ(const int l, const int r) {
	if (l == r) return 8e14;
	const int m(l + r >> 1), mx(a[m].x);
	long long b(std::min(CDQ(l, m), CDQ(m + 1, r)));
	int p1(l), p2(m + 1), c(0);
	while (p1 <= m || p2 <= r) if (p1 <= m && (p2 > r || a[p1].y < a[p2].y)) d[++c] = a[p1++];
		else d[++c] = a[p2++];
	for (int i(1); i <= c; ++i) a[l + i - 1] = d[i];
	c = 0;
	for (int i(l); i <= r; ++i) if ((long long)(a[i].x - mx) * (a[i].x - mx) <= b) d[++c] = a[i];
	for (int i(1); i < c; ++i) for (int j(i + 1); j <= c && (long long)(d[j].y - d[i].y) * (d[j].y - d[i].y) <= b; ++j)
			b = std::min(b, (long long)(d[i].x - d[j].x) * (d[i].x - d[j].x) + (long long)(d[i].y - d[j].y) * (d[i].y - d[j].y));
	return b;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i(1); i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
	std::sort(a + 1, a + n + 1);
	return !printf("%lld\n", CDQ(1, n));
}
