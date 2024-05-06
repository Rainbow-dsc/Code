#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000001];
long long solve(long long p){
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r)/2;
		if(p>a[mid]) l=mid+1;
		else r=mid;
	}
	if(a[l]==p) return l;
	else return -1;
}
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	while(m--){
		long long p;
		scanf("%lld",&p);
		long long ans=solve(p);
		cout<<ans<<" ";
	}
	return 0;
}
