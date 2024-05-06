#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
string s;
int T,n;
signed main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>s;
		int res,sum;
		res=sum=0;
		for(int i=0;i<n;i++) {
			sum+=i+1;
			res+=sum;
			if(~s[i]&1) res+=n-i;
			if(i&&s[i]==s[i-1]) res+=i*(n-i);
		}
		cout<<res<<endl;
	}
	return 0;
}

