#include<bits/stdc++.h>
#define int long long
#define maxn 10000001
using namespace std;
int x,y,ans=0,k=1;
int c[maxn];
void pc(int a,int b){
	int p=a*b;
	for(int i=1;i<=sqrt(p);i++)
		if(p%i==0) c[k++]=i;
}
signed main(){
	scanf("%lld%lld",&x,&y);
	if(x==y){
		cout<<1;
		return 0;
	}
	pc(x,y);
	for(int i=1;i<k;i++) if(__gcd(c[i],(x*y)/c[i])==x) ans++;
	printf("%lld",ans*2);
	return 0;
}
