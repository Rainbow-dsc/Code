#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool cmp(string x,string y) {
	return x+y>y+x;
}
signed main() {
	cin>>n;
	string a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) cout<<a[i];
	return 0;
}
//6
//321 32 407 135 13 217
