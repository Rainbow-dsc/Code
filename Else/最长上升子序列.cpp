#include<bits/stdc++.h>
using namespace std;
int n,a[10000001],dp[10000001];
int main(){
	freopen("program2.in","r",stdin);
	freopen("fejwi.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];   
        dp[i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}
