#include<bits/stdc++.h>
#define int long long
#define _ (int)(2e5 + 4)
using namespace std;
int n, m, k, ans;
int a[_];
multiset<int> s1, s2;
multiset<int> :: iterator it1, it2;
signed main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		s2.insert(a[i]);
		while (s1.size() < k && s2.size()) {
			s1.insert(*s2.begin());
			ans += *s2.begin();
			s2.erase(s2.begin());
		}
		while (s2.size() && (*s2.begin()) < (*s1.rbegin())) {
			ans += *s2.begin() - *s1.rbegin();
			int p = *s1.rbegin(), q = *s2.begin();
			s1.erase(s1.find(*s1.rbegin())), s2.erase(s2.begin());
			s1.insert(q), s2.insert(p);
		}
		if (i >= m) {
			cout << ans << " ";
			int p = a[i - m + 1];
			it1 = s1.find(p), it2 = s2.find(p);
			if (it1 != s1.end()) ans -= p, s1.erase(it1);
			else s2.erase(it2);
		}
	}

	return 0;
}
