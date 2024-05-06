#include<bits/stdc++.h>
using namespace std;
int n,a[55],dp[55];
int main() {
    cin>>n;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    if(a[2]-a[1]>1) {
        cout<<-1;
        return 0;
    }
    dp[1]=0;
    for(int i=2; i<=n; i++) {
        if(a[i]-a[i-1]==1) dp[i]=min(dp[i],dp[i-1]+1);
        for(int j=i-1; j>=1; j--) {
            for(int l=i+1; l<=n; l++) {
                if(a[l]-a[j]<=pow(2,i-j)) dp[l]=min(dp[l],dp[i]+i-j+1);
            }
        }
    }
    if(dp[n]!=1061109567)
        cout<<dp[n];
    else cout<<-1;
    return 0;
}
