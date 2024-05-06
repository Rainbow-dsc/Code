#include <math.h>
#include <stdio.h>
#include <algorithm>
struct point {
    int x, y;
    bool operator < (const point p) { return x < p.x; }
} a[200001];
int main()
{
    int n; scanf("%d", &n);
    for (int i(1); i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
    std::sort(a + 1, a + n + 1);
    double w(2e9);
    for (int i(1); i < n; ++i)
        for (int j(i + 1); j <= n; ++j)
        {
            double dx(std::abs(a[i].x - a[j].x)), dy(std::abs(a[i].y - a[j].y));
            if ((double)dx > w) break;
            w = std::min(w, sqrt(dx * dx + dy * dy));
        }
    return !printf("%.4f\n", w);
}
