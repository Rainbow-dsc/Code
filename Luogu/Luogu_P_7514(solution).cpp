#include <bits/stdc++.h>
using namespace std;
struct hehe{
	long long a, num;
	int op;
	bool operator < (hehe b) const
	{
		return a < b.a;
	}
}a[2000001];
bool used[2000001];
int main()
{
	// freopen("card3.in", "r", stdin);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].a);
		a[i].num = i;
		a[i].op = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[n + i].a);
		a[i + n].num = i;
		a[i].op = 1;
	}
	sort(a + 1, a + n * 2 + 1);
	int l = 0, r = n * 2 + 1, now = 0;
	while(!used[a[l + 1].num] && now + a[l + 1].op <= k) now += a[l + 1].op, used[a[l + 1].num] = 1, l++;
	while(!used[a[r - 1].num] && now + a[r - 1].op <= k) now += a[r - 1].op, used[a[r - 1].num] = 1, r--;
	long long ans = 1000000000000;
	while(l >= 0)
	{
		ans = min(a[r - 1].a - a[l + 1].a, ans);
		used[a[l].num] = 0;
		now -= a[l].op;
		l--;
		while(!used[a[r - 1].num] && now + a[r - 1].op <= k) now += a[r - 1].op, used[a[r - 1].num] = 1, r--;

	}
	cout << ans << endl;
}