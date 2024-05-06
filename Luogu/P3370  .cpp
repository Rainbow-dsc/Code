//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define maxn 100005
#define mod 9223372036854775783
using namespace std;
int n,a[maxn];
string s;
int get_hash(string x) {
	int len=x.size();
	int ans=0;
	for(int i=0;i<len;i++) ans=(ans*129+(int)s[i])%mod;
	return ans;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		cin>>s;
		a[i]=get_hash(s);
	}
	int sum=1;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) if(a[i-1]!=a[i]) sum++;
	printf("%lld",sum);
    return 0;
}

