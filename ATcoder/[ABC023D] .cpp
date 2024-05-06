#include<bits/stdc++.h>
#define int long long
using namespace std;
struct p{
	int h,s;
}a[100001];
int tim[1000001];
int n;
bool check(int mid){
	for(int i=1;i<=n;i++) {
		if(mid<a[i].h) return false;
		tim[i-1]=(mid-a[i].h)/a[i].s;
	}
	sort(tim,tim+n);
	for(int i=0;i<n;i++) if(tim[i]<i) return false;
	return true;
}
signed main() {
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].h,&a[i].s);
    int ans=0,l=1,r=1e18;
    while(l<r){
    	int mid=(l+r)/2;
    	if(check(mid)){
    		r=mid;
    		ans=mid;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
    return 0;
}
