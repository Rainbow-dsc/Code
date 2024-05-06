#include<bits/stdc++.h>
#define int long long
#define maxn 500009
using namespace std;
int a[maxn],b[maxn],c[maxn],d[maxn];
bool cmp(int a,int b) {
	return a>b;
}
signed main() {
	int n,k,ans=0;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&b[i]);
		c[i]=min(a[i],b[i]);
		d[i]=max(a[i],b[i]);
		ans+=abs(a[i]-b[i]);
	}
	if(n==2) { //n=2的时候特判一下
		if(k%2==0)  printf("%lld",ans);//换偶数次的就不用管了,反正都是换回来
		else printf("%lld",2*abs(a[1]-b[2]));
	} else {
		sort(c+1,c+1+n,cmp);
		sort(d+1,d+1+n);
		for(int i=1; i<=k; i++) {
			if(c[i]<d[i]) break;
			ans+=2*(c[i]-d[i]);
		}
		printf("%lld",ans);
	}
}
