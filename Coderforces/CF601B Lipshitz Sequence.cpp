#include<bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;
int n,q,l,r;
int pre[maxn],las[maxn];
int h[maxn],a[maxn];
int stk[maxn];
signed main(){
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
	for(int i=1;i< n;i++) a[i]=abs(h[i]-h[i+1]);
	while(q--) {
		scanf("%lld %lld",&l,&r);r--;
		memset(pre,0,sizeof(pre)),memset(las,0,sizeof(las));
		int top=0,ans=0,len=r-l+1;
		for(int i=l,j=1;i<=r;j++,i++) a[j]=abs(h[i]-h[i+1]);
		for(int i=1;i<=len;i++) {
			while(top&&a[stk[top]]<a[i]) las[stk[top]]=i-stk[top],top--;
			pre[i]=i-stk[top],stk[++top]=i;
		}
		while(top) las[stk[top]]=len+1-stk[top],top--;
		for(int i=1;i<=len;i++) ans+=a[i]*pre[i]*las[i];
		printf("%lld\n",ans); 
	}
	return 0;
}
