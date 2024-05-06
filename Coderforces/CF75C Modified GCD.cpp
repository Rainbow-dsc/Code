#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a,b,T,l,r,maxx=-1;
signed main(){
	scanf("%d %d",&a,&b);
	int gcd=__gcd(a,b);
	cin>>T;
	while(T--){
		maxx=-1;
		scanf("%d %d",&l,&r);
		for(int i=1;i*i<=gcd;i++){
			if(gcd%i==0){
				if(i>=l&&i<=r) maxx=max(maxx,i);
				if(gcd/i>=l&&gcd/i<=r) maxx=max(maxx,gcd/i);
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}
