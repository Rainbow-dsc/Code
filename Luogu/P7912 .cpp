#include<bits/stdc++.h>
using namespace std;
struct kuai {
	int st, ed, th;
} f, x, ad;
int n, cnt, t[200002];
queue<kuai> q, q2;
bool used[200001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &t[i]);
	t[n + 1] = !t[n];
	for (int i = 2, si = 1; i <= n + 1; i ++) {
		if (t[i] != t[i - 1]) q.push((kuai){si, i - 1, t[i - 1]}), si = i;
	}
	cnt = n;
	while (cnt) {
		while (q.size()) {
			f = q.front();
			q.pop();
			while (used[f.st] && f.st <= f.ed) f.st ++;
			if (f.st > f.ed) continue;
			printf("%d ", f.st), cnt --;
			used[f.st] = 1;
			if (f.ed == f.st) continue;
			f.st ++;
			q2.push(f);
		}
		putchar('\n');
		while (q2.size()) {
			ad = q2.front();
			q2.pop();
			while (q2.size()) {
				x = q2.front();
				if (x.th == ad.th) {
					ad.ed = x.ed;
					q2.pop();
				} else break;
			}
			q.push(ad);
		}
	}
	return 0;
}
