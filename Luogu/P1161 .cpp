#include <bits/stdc++.h>
using namespace std;
int n,t[2000001];
double a[2000001];
int kg[2000001];
signed main() {
	scanf("%d",&n);
	memset(kg,0,sizeof(kg));
	for(int i=1; i<=n; i++) cin>>a[i]>>t[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=t[i]; j++) {
			kg[int(a[i]*j)]^=1;
		}
//	for(int i=1;i<=100;i++) cout<<kg[i]<<" ";
	for(int i=1; i<=2000001; i++)
		if(kg[i]==1) {
			cout<<i;
			return 0;
		}
	return 0;
}

