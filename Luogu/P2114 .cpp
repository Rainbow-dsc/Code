#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,m;
int cnt;
int t[maxn];
int ans[40],num[40],opt[maxn];
int solve(int x) {
	for(int i=1;i<=n;i++) {
		if(opt[i]==0) x&=t[i];
		else if(opt[i]==1) x^=t[i];
		else x|=t[i];
	}
	return x;
}
signed main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) {
		string s;
		cin>>s>>t[i];
		if(s=="AND") opt[i]=0;
		else if(s=="XOR") opt[i]=1;
		else opt[i]=2;
	}
	while(m) {
		num[++cnt]=m%2;
		m/=2;
	}
	bool top=true;
	for(int i=cnt; i>=1; i--) {
		if(top==true) {
			if(num[i]==1) {
				int g1=solve(1<<(i-1)),g2=solve(0);
				g1&=(1<<(i-1)),g2&=(1<<(i-1));
				if(g1>g2) ans[i]=true;
				else top=false,ans[i]=false;
			} else ans[i]=false;
		} else {
			int g1=solve(1<<(i-1)),g2=solve(0);
			g1&=(1<<(i-1)),g2&=(1<<(i-1));
			if(g1>g2) ans[i]=true;
			else ans[i]=false;
		}
	}
	int tot=0;
	for(int i=1;i<=cnt;i++) if(ans[i]) tot+=(1<<(i-1));
	printf("%lld",solve(tot));
	return 0; 
}

