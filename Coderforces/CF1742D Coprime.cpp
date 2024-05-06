#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001];
signed main(){
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			int x;
			cin>>x;
			a[x]=i;
		}
		for(int i=1;i<=1000;i++)
			for(int j=i;j<=1000;j++)
				if(__gcd(i,j)==1&&a[i]&&a[j]) ans=max(ans,a[i]+a[j]);
		if(ans==0) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
