#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,ans=1;
signed main(){
	cin>>a;
	for(int i=1;i<=a;i++) ans*=i;
	cout<<ans;
	return 0;
}
