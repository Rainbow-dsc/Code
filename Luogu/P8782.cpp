#include<bits/stdc++.h>
#define int long long
using namespace std;
int Q,mod;
int jie(int x){
	int ans=1;
	for(int i=2;i<=x%mod;i++){
		ans*=i;
	}
	return ans;
}
signed main(){
	scanf("%d%d",&Q,&mod);
	for(int i=1;i<=Q;i++){
		int n,r;
		scanf("%d%d",&n,&r);
		int sum=jie(n)/jie(r)%mod;
		if(sum==0) printf("%d\n",0);
		else printf("%d\n",sum);
	}
	return 0;
}
