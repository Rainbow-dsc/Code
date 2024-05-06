#include<bits/stdc++.h>
using namespace std;
int n,m,q,u,v,t,a[10000001],p[10000001],c[10000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		p[i]=a[1];
		a[n+i]=a[1]*(1-u/v);
		a[1]*=u/v;\
		for(int j=2;j<=n+i;j++) a[j]+=q;
		sort(a+1,a+n+1+i,cmp);
	}
	for(int i=t;i<=m;i+=t) printf("%d ",p[i]);
	for(int i=t;i<=m+n;i+=t) printf("%d ",a[i]);
	return 0;
}
//3 7 1 1 3 1 3 3 2
//3  4  4 4 5  5  6  6 6 6 5 5 4  4 3 2  2

//3  3  4 4 5  6  6  7 8 7 7 6 5  4 3 2  1
