#include <bits/stdc++.h>
#define N 55
#define int long long
using namespace std;
int T,numa[N],numb[N];
void read(int *num) {
	num[0]=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) {
		if(num[0]||ch>'0') num[++num[0]]=ch-'0';
		ch=getchar();
	}
}
bool check(int *num) {
	int w=num[0];
	for(int i=1;i<=w;++i) {
		if(num[i]!=1&&num[i]!=8&&num[i]) return 0;
		if(num[i]!=num[w-i+1]) return 0;
	}
	return 1;
}
const int cnt[10]={1,2,2,2,2,2,2,2,3,3};
int f[N],g[N];
int solve(int *num) {
	int w=num[0];
	bool flg=0;
	int ans=0,mid=(w+1)/2;
	for(int i=1;i<=mid;++i) {
		int lim=num[i];
		if(lim>0) {
			if(i>1) ans+=cnt[lim-1]*f[mid-i];
			else ans+=(cnt[lim-1]-1)*f[mid-i];
		}
		if(num[i]&&num[i]!=1&&num[i]!=8) {
			flg=1;
			break;
		}
		if(num[i]>num[w-i+1]) flg=1;
		if(num[i]<num[w-i+1]) flg=0;
	}
	if(!flg) ans++;
	for(int i=1;i<=w;++i) {
		ans+=g[(w-i+1)/2];
	}
	return ans;
}
signed main() {
//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);
	scanf("%lld",&T);
	f[0]=g[0]=1;
	for(int i=1;i<=25;++i) {
		f[i]=3*f[i-1];
		g[i]=2*f[i-1];
	}
	while(T--) {
		read(numa);
		read(numb);
		printf("%lld\n",solve(numb)+check(numa)-solve(numa));
		for(int i=1;i<=numa[0];i++) printf("%lld ",numa[i]);
		cout<<endl;
	}
	return 0;
}
