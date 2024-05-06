#include<bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n,k,cnt=0;
int t[maxn];
vector <int> P[maxn];
vector <int> ans;
int vis[maxn];
bool flag=false;
void dfs(int x){
	if(vis[x]==2) return ;
	if(vis[x]==1) {
		flag=true;
		return ;
	} 
	vis[x]=1;
	for(int i=0;i<P[x].size();i++) {
		int t=P[x][i];
		dfs(t);
	}
	if(x!=0) {
		ans.push_back(x);
		vis[x]=2;
	}
}
signed main(){
	memset(vis,0,sizeof(vis));
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++) {
		scanf("%lld",&t[i]);
		P[0].push_back(t[i]);
	}
	for(int i=1;i<=n;i++) {
		int x;
		scanf("%lld",&x);
		for(int j=1;j<=x;j++) {
			int p;
			scanf("%lld",&p);
			P[i].push_back(p);
		}
	}
	dfs(0);
	if(flag==true) {
		cout<<-1;
		return 0;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	return 0;
}

