#include <bits/stdc++.h>
#define int long long
using namespace std;
int k;
signed main() {
	cin>>k;
	bool flag=false;
	for(int i=10000;i<=30000;i++) {
		int a1=i/10000*100+i%10000/1000*10+i%1000/100;
		int a2=i%10000/1000*100+i%1000/100*10+i%100/10;
		int a3=i%1000/100*100+i%100/10*10+i%10;
		if(a1%k==0&&a2%k==0&&a3%k==0) {
			cout<<i<<endl;
			flag=true;
		}
	}
	if(flag==false) cout<<"No";
	return 0;
}

