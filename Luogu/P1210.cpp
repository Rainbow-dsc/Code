#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,p,q;
int a[32][10002];
signed main() {
	cin>>n;
	if(n==0) {
		cout<<"(a+b)^0 = 1";
		return 0;
	} else if(n==1) {
		cout<<"(a+b)^1 = a + b";
		return 0;
	}
	a[1][1]=1;
	for(int i=2; i<=n+1; i++) {
		for(int j=2; j<=i-1; j++) {
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
		a[i][1]=a[i][i]=1;
	}
	p=n;
	cout<<"(a+b)^"<<n<<" = ";
	for(int i=1; i<=n+1; i++) {
		if(a[n+1][i]!=0&&a[n+1][i]!=1) cout<<a[n+1][i]<<"*";
		if(p!=1&&p!=0) {
			cout<<"a^"<<p;
			if(i!=1) cout<<"*";
		} else if(p==1) cout<<"a*";
		if(q!=1&&q!=0) cout<<"b^"<<q;
		else if(q==1) cout<<"b";
		if(i!=n+1)cout<<" + ";
		p--,q++;
	}
	return 0;
}
