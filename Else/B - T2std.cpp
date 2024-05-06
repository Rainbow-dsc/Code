#include <cstdio>
#include <algorithm>
#include <queue>
#define N 2005
using namespace std;

priority_queue<int> q;
int a[N],n,m,T;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &a[i]);
			q.push(a[i]);
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j <= n; j++) a[j] = q.top(),q.pop();
			for (int j = 1; j <= n; j++) {
				int x;
				scanf("%d", &x);
				for (int k = 1; k <= n; k++)
					if (q.size() >= n) if (q.top() > a[k] + x) q.pop(),q.push(a[k] + x);
					else q.push(a[k] + x);
			}
		}
		for (int i = 1; i <= n; i++) a[i] = q.top(),q.pop();
		for (int i = n; i >= 1; i--) printf("%d ", a[i]);
		printf("\n");
	}
}
