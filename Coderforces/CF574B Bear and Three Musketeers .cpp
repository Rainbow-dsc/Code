#include<bits/stdc++.h>
#define maxn 5005
#define int long long
using namespace std;
int n,m;
int mp[maxn][maxn];
int neb[maxn];
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		mp[x][y]=mp[y][x]=1;
		neb[x]++;
		neb[y]++;
	}
	int ans=1e18;
	bool flag=false;
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			if(k==i||mp[i][k]==0) continue; 
			for(int j=1;j<=n;j++) {
				if(i==j||mp[i][j]==0) continue;
				if(mp[i][j]==1&&mp[k][i]==1&&mp[j][k]==1) {
					flag=true;
					ans=min(ans,neb[i]+neb[j]+neb[k]-6);
				}
			}
		}
	}
	if(flag==false) cout<<"-1";
	else cout<<ans;
	return 0;
}

