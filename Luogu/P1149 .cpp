#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[2005]= {6};
int gs[10]= {6,2,5,5,4,5,6,3,7,6};
int ans=0;
signed main() {
	scanf("%lld",&n);
	for(int i=1; i<=2005; i++) {
		int j=i;
		while(j>=1) {
			a[i]+=gs[j%10];
			j/=10;
		}
	}
	for(int i=0; i<=1000; i++) {
		for(int j=0; j<=1000; j++)
			if(a[i]+a[j]+a[i+j]+4==n) ans++;
	}
	cout<<ans;
	return 0;
}

