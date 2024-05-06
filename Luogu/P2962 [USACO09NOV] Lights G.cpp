#include<bits/stdc++.h>
using namespace std;
map<long long,int>mp;
int n,m;
int mid,flag,minn=0x7f7f7f7f;
long long ed,q[41],p[41];
void dfs(int x,long long now,int step) {
	if(x==mid+1) {
		if(now==ed)
			minn=min(step,minn);
		if(!flag) {
			int tmp=mp[now];
			if(!tmp||tmp>step)      
				mp[now]=step;
		} else {
			int tmp=mp[ed-now];     
			if(!tmp) return ;
			minn=min(tmp+step ,minn);  
		}
		return ;
	}
	dfs(x+1,now,step);
	dfs(x+1,now^q[x] ,step+1);      
}
int main() {
	p[1]=1;
	for(int i=2; i<=40; i++)
		p[i]=p[i-1]<<1;       
	scanf("%d%d",&n,&m);
	ed=p[n+1]-1;
	for(int i=1; i<=m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		q[x]+=p[y];
		q[y]+=p[x];
	}
	for(int i=1; i<=n; i++)
		q[i]^=p[i];    
	mid=n/2;
	dfs(1,0,0);
	flag=1;
	mid=n;
	dfs(n/2+1,0,0);    
	cout<<minn;
	return 0;
}
