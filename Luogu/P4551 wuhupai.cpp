#include<bits/stdc++.h>
using namespace std;
struct edge{ long long to,w; }p;
long long n,x,y,z,tr[4000005][2],cnt=0,maxx=-1;
vector<edge>v[100005];
void insert(long long x){
	long long u=0;
	for(long long i=30;i>=0;i--){
		if(x&(1<<i)){
			if(tr[u][1]) u=tr[u][1];
			else{
				cnt++;
				tr[u][1]=cnt;
				u=cnt;
			}
		}else{
			if(tr[u][0]) u=tr[u][0];
			else{
				cnt++;
				tr[u][0]=cnt;
				u=cnt;
			}
		}
	}
}
void dfs(long long u,long long from,long long sum){
	insert(sum);
	for(long long i=0;i<v[u].size();i++){
		long long to=v[u][i].to;
		if(to!=from){
			dfs(to,u,sum^v[u][i].w);
		}
	}
}
void get(long long u1,long long u2,long long sum,long long dep){
	if(dep==-1) maxx=max(maxx,sum);
	if((tr[u1][0]&&tr[u2][1])||(tr[u1][1]&&tr[u2][0])){
		 if(tr[u1][0]&&tr[u2][1]) get(tr[u1][0],tr[u2][1],sum|(1<<dep),dep-1);
		 if(tr[u1][1]&&tr[u2][0]) get(tr[u1][1],tr[u2][0],sum|(1<<dep),dep-1);
	}else{
		if(tr[u1][0]&&tr[u2][0]) get(tr[u1][0],tr[u2][0],sum,dep-1);
		if(tr[u1][1]&&tr[u2][1]) get(tr[u1][1],tr[u2][1],sum,dep-1);
	}
}
int main(){
	cin>>n;
	for(long long i=1;i<=n-1;i++){
		cin>>x>>y>>z;
		p.to=y;
		p.w=z;
		v[x].push_back(p);
		p.to=x;
		v[y].push_back(p);
	}
	dfs(1,0,0);
	get(0,0,0,30);
	cout<<maxx<<endl;
	return 0;
}