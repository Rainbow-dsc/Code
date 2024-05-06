#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,ans=0;
int a[1000001];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	sum+=a[i];
    	if(sum>m) break;
    	ans++;
	}
	cout<<ans;
    return 0;
}
