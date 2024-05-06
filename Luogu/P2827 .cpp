#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,m,q,u,v,t;
int a[maxn];
queue<int> P1,P2,P3;
bool cmp(int x,int y) {
	return x>y;
}
int get() {
	int P_max=-1e18,id;
	if(P1.front()>P_max&&P1.size()) id=1,P_max=P1.front();
	if(P2.front()>P_max&&P2.size()) id=2,P_max=P2.front();
	if(P3.front()>P_max&&P3.size()) id=3,P_max=P3.front();
	if(id==1) P1.pop();
	if(id==2) P2.pop();
	if(id==3) P3.pop();
	return P_max;
}
signed main(){
	scanf("%lld %lld %lld %lld %lld %lld",&n,&m,&q,&u,&v,&t);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) P1.push(a[i]);
	for(int i=1;i<=m;i++) {
		int x=get()+(i-1)*q;
		if(i%t==0) printf("%lld ",x);
		int l1=u*1.0/v*1.0*x,l2=x-l1;
		P2.push(l1-i*q);
		P3.push(l2-i*q);
	}
	puts("");
	int cnt=0,x;
	while((x=get()+m*q)>=0) if((++cnt)%t==0) printf("%lld ",x);
	return 0;
}
