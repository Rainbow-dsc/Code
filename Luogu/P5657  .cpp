#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,k;
int t[100];
int qpow(int x,int y) {
	int ans=1;
	while(y) {
		if(y%2==1) ans*=x;
		x*=x;
		y>>=1;
	}
	return ans;
}
signed main(){
	cin>>n>>k;
	int l=0,tot=qpow(2,n)-1,r=tot;
	int cnt=0;
	while(l<r) {
		int mid=(l+r)>>1;
		if(k>mid) {
			t[++cnt]=1;
			k=tot-k;
		} else t[++cnt]=0; 
		r=mid;
		tot>>=1;
	}
	for(int i=1;i<=n;i++) cout<<t[i];
	return 0;
}
