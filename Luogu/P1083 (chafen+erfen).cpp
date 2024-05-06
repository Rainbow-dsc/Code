#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m;
int diff[1000011],need[1000011],rest[1000011],r[1000011],l[1000011],d[1000011];
bool isok(int x) {
	memset(diff,0,sizeof(diff));
	for(int i=1; i<=x; i++) {
		diff[l[i]]+=d[i];
		diff[r[i]+1]-=d[i];
	}
	for(int i=1; i<=n; i++) {
		need[i]=need[i-1]+diff[i];
		if(need[i]>rest[i])return 0;
	}
	return 1;
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++)scanf("%lld",&rest[i]);
	for(int i=1; i<=m; i++)scanf("%lld%lld%lld",&d[i],&l[i],&r[i]);
	int begin=1,end=m;
	if(isok(m)) {
		cout<<"0";
		return 0;
	}
	while(begin<end) {
		int mid=(begin+end)/2;
		if(isok(mid))begin=mid+1;
		else end=mid;
	}
	cout<<"-1"<<endl<<begin;
}
