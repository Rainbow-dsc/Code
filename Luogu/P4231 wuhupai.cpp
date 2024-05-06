#include<bits/stdc++.h>
using namespace std;
long long n,T,d[10000005],l,r,s,e,maxx=-1,ans;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>T;
	while(T--){
		cin>>l>>r>>s>>e;
		long long x=(e-s)/(r-l);
		d[l]+=s;
		d[l+1]-=s;
		d[l+1]+=x;
		d[r+1]-=x;
		d[r+1]-=e;
		d[r+2]+=e;
	}
	for(long long i=1;i<=n;i++){
		d[i]+=d[i-1];
	}for(long long i=1;i<=n;i++){
		d[i]+=d[i-1];
		maxx=max(maxx,d[i]);
		ans^=d[i];
	}
	cout<<ans<<" "<<maxx<<"\n";
	return 0;
}