#include <bits/stdc++.h>
#define int long long
using namespace std;
int res=0,n,T;
bool cmp(int a,int b) {
    return (res|a)>(res|b);
}
void solve() {
    res=0;
    cin>>n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++) cin>>a[i];
    int cnt=min((long long)30,n);
    for (int i=1;i<=cnt;i++){
        sort(a.begin()+i,a.end(),cmp);
        res|=a[i];
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
}
signed main() {
    cin>>T;
    while(T--){
    	solve();
    	cout<<endl;
	}
    return 0;
}
