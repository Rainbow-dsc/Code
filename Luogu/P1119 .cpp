#include<bits/stdc++.h>
#define int long long
#define maxn 310
using namespace std;
int n,m,q;
int t[maxn];
int mp[maxn][maxn];
void flord(int k) {
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
}
signed main(){
	for(int i=1;i<=305;i++) for(int j=1;j<=305;j++) mp[i][j]=1e18;
	for(int i=1;i<=n;i++) mp[i][i]=0;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&t[i]);
	for(int i=1;i<=m;i++) {
		int x,y,w;
		scanf("%lld %lld %lld",&x,&y,&w);
		x++;
		y++;
		mp[x][y]=w;
		mp[y][x]=w;
	}
	scanf("%lld",&q);
	int now=1;
	while(q--) {
		int x,y,p;
		scanf("%lld %lld %lld",&x,&y,&p);
		x++;
		y++;
		while(t[now]<=p&&now<=n) flord(now++);
		if(t[x]>p||t[y]>p||mp[x][y]==1e18) cout<<-1<<endl;
		else cout<<mp[x][y]<<endl;
	}
	return 0;
}

