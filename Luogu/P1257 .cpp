#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int n;
struct aa{ int l,r; }a[maxn];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i].l,&a[i].r);
	double ans=(double)(1e9+7);
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(ans>sqrt((a[i].l-a[j].l)*(a[i].l-a[j].l)+(a[i].r-a[j].r)*(a[i].r-a[j].r))) ans=sqrt((a[i].l-a[j].l)*(a[i].l-a[j].l)+(a[i].r-a[j].r)*(a[i].r-a[j].r));
		}
	} 
	printf("%.4lf",ans);
	return 0;
}
