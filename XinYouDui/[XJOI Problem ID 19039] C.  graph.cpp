#include<bits/stdc++.h>
#define Maxn 1000007
const int L = 2700;
using namespace std;
int p, k, Q, s, f[407][407], from[Maxn], dis[Maxn], T, ans, cnt = -1;
bool vis[Maxn];
deque<int> q;
void solve() {
	cin >> p >> k >> Q;
	if(k <= 1) {
		for(int i = 1, u, v; i <= Q; i ++) {
			cin >> u >> v;
			cout << ((u == v) ? 0 : -1) << "\n";
		}
		return;
	}
	for(int i = 1, res = 1; ; i ++) {
		res = 1ll * res * k % p;
		if(res ^ 1) continue;
		s = i;
		break;
	}
	auto work1 = [&]() {
		memset(vis, 0, sizeof vis);
		memset(dis, 0x3f, sizeof dis);
		dis[0] = 0;
		q.push_front(0);
		while(q.size()) {
			int temp = q.front();
			q.pop_front();
			if(vis[temp]) continue;
			vis[temp] = 1;
			int nxt = 1ll * k * temp % p;
			if(dis[nxt] > dis[temp]) {
				dis[nxt] = dis[temp];
				q.push_front(nxt);
			}
			nxt = (temp + 1) % p;
			if(dis[nxt] > dis[temp] + 1) {
				dis[nxt] = dis[temp] + 1;
				q.push_back(nxt);
			}
		}
		for(int i = 1, u, v; i <= Q; i ++) {
			cin >> u >> v;
			ans = p + 1;
			int res = 1, temp;
			for(int j = 0; j <= s; j ++) {
				temp = 1ll * res * u % p;
				temp = (v - temp + p) % p;
				res = 1ll * res * k % p;
				ans = min(ans, dis[temp]);
			}
			if(ans != p + 1) cout << ans << "\n";
			else cout << "-1\n";
		}
	};
	auto work2 = [&]() {
		memset(from, 0x3f, sizeof from);
		memset(f, 0x3f, sizeof f);
		for(int i = 0; i < p; i ++) {
			if(from[i] > p) from[i] = ++ cnt;
			else continue;
			for(int j = 1ll * i * k % p; from[j] > p; j = 1ll * j * k % p) from[j] = cnt;
		}
		for(int i = 0; i < p; i ++) f[from[i]][from[(i + 1) % p]] = 1;
		for(int i = 0; i <= cnt; i ++) f[i][i] = 0;
		for(int k = 0; k <= cnt; k ++) for(int i = 0; i <= cnt; i ++) for(int j = 0; j <= cnt; j ++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		for(int i = 1, u, v; i <= Q; i ++) {
			cin >> u >> v;
			if(f[from[u]][from[v]] < p + 1) cout << f[from[u]][from[v]] << "\n";
			else cout << "-1\n";
		}
	};
	if(s <= L) work1();
	else work2();
}
int main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	cin >> T;
	while(T --) solve();
}
