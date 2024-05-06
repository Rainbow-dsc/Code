#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
string a,b;
signed main() {
	scanf("%lld",&t);
	while(t--) {
		bool flag=false;
		cin>>a;
		cin>>b;
		for(int i=0;i<a.size();i++) 
			if(a[i]=='0'&&b[i]=='0'&&a[i+1]=='1'&&b[i+1]=='1') 
				flag=true;
		if(flag==true) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

