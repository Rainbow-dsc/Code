#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
string s;
int num=0,ans=0;
inline int qpow(int a,int b) {
	if (b==0) return 1;
	int res=qpow(a,b/2);
	if (b%2) return res*res*a;
	else return res*res;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>s;
	for(register int i=s.size()-1;i>=0;i--) num+=(s[i]-'0')*qpow(2,s.size()-i-1);
	for(register int i=0;i<num;i++) {
		for(register int j=0;j<num;j++) {
			int sum=i+j;
			int cnt=0;
			for(register int k=1;k<=qpow(2,s.size()+1);k+=qpow(2,cnt++)) {
				if(((i+k)^(j+k))==sum) {
					ans=(ans+k)%mod;
					break;
				}
			}
		}
	}
	printf("%lld",ans%mod);
	return 0;
}
