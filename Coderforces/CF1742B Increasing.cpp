#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,a[1000001],n;
signed main(){
	cin>>t;
	for(int p=1;p<=t;p++){
		bool flag=false;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=0;i<=n-1;i++) {
			if(a[i]>=a[i+1]) {
				flag=true;
				printf("NO\n");
				break;
			} 
		}
		if(flag==false) printf("YES\n");
	}
	return 0;
}
