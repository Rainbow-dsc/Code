#include<bits/stdc++.h>
#define int long long
#define mod (int)1000000007
#define maxn 105
using namespace std;
int n,m,a[maxn];
vector<int> P;
int read(){
    int sum=0,fg=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') fg=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        sum=((sum*10)+c-'0')%mod;
        c=getchar();
    }
    return sum*fg;
}
bool solve(int x) {
	int sum=0;
	for(int i=n+1;i>=1;i--) sum=(sum*x+a[i])%mod;
	if(sum==0) return true;
	else return false;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n+1;i++) a[i]=read();
	for(int i=1;i<=m;i++) if(solve(i)==true) P.push_back(i);
	printf("%lld\n",P.size());
	for(int i=0;i<P.size();i++) printf("%lld\n",P[i]);
	return 0;
}
