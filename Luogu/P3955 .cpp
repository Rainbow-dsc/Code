#include<bits/stdc++.h>
using namespace std;
long long b[1005],x[1005],xc[1005],tmp[1005];
int n,q;
int main() {
	cin>>n>>q;
	memset(tmp,1,sizeof(tmp));
	for(int i=1; i<=n; i++) cin>>b[i];
	sort(b,b+n+1);
	for(int i=1; i<=q; i++) {
		cin>>xc[i]>>x[i];
		tmp[i]=pow(10,xc[i]);
	}
	for(int i=1; i<=q; i++) {
		for(int j=1; j<=n; j++) 
			if(b[j]%tmp[i]==x[i]) {
				cout<<b[j]<<endl;
				break;
			} else if(j==n) {
				cout<<-1<<endl;
				break;
			}
	}
	return 0;
}
