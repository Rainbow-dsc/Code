#include<bits/stdc++.h>
using namespace std;
int n,a,m,r;
int h[1000001],sum[1000001];
int main(){
	scanf("%d%d%d%d",&n,&a,&r,&m);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	sort(h+1,h+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+h[i];
	int l=h[1],r=h[n],ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		for(int i=1;i<=n;i++) {
		for(int i=1;i<=n;i++) {
			if(h[i]<mid) ans+=(mid-h[i])*a;
			if(h[i]>mid) ans+=(h[i]-mid)*a;
		}
		
	}
	return 0;
}
