#include <bits/stdc++.h>
using namespace std;
long long n,k,b[1000001];
int main(){
    scanf("%lld%lld",&n,&k);
    if(n<=k) {
    	cout<<1;
    	return 0;
	}
	long long l=2,r=k,ans=-1;
	while(l<=r){
		long long mid=(l+r)/2;
		long long check=(2+mid)*(mid-1)/2-mid+2;
		if(check>=n) {
			ans=check;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans;
    return 0;
}
