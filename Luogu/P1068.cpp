#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct aa{
	long long k,s;
}a[10000001];
struct bb{
	long long k,s;
}b[10000001];
bool cmp(aa x,aa y){
	if(x.s!=y.s) return x.s>y.s;
	else return x.k<y.k;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].k,&a[i].s);
	sort(a+1,a+n+1,cmp);
	int i=1,p=m*1.5,c=0,r=1;
//	cout<<p<<endl;
//	for(int i=1;i<=n;i++) cout<<a[i].k<<" "<<a[i].s<<endl;
	int xian=a[p].s;
	while(i<=n){
		if(a[i].s>=a[p].s){
			b[r].k=a[i].k;
			b[r].s=a[i].s;
			c++;
			r++;
		}
		i++;
	}
	cout<<xian<<" "<<c<<endl;
	for(int j=1;j<r;j++) cout<<b[j].k<<" "<<b[j].s<<endl;
	return 0;
}
