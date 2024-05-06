#include<bits/stdc++.h>
#define int long long
#define maxn 105
using namespace std;
int n,cnt;
int indeg[maxn],ans[maxn];
vector <int> P[maxn];
void tosort() {
	queue <int> C;
	for(int i=1;i<=n;i++) if(indeg[i]==0) C.push(i);
	while(!C.empty()){
		int fro=C.front();
		ans[++cnt]=fro;
		C.pop();
		for(int i=0;i<P[fro].size();i++) {
			int now=P[fro][i];
			indeg[now]--;
			if(indeg[now]==0) C.push(now);
		}
	}
}
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		while(1) {
			int x;
			scanf("%lld",&x);
			if(x==0) break;
			else P[i].push_back(x),indeg[x]++;
		}
	}
	tosort();
	for(int i=1;i<=cnt;i++) printf("%lld ",ans[i]);
	return 0;
}
