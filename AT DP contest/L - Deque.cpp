/*#include<bits/stdc++.h>
#define int long long
#define maxn 3005
#define mod (int)(1e9+7)
using namespace std;
int n;
int a[maxn];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int l=1,r=n;
    int x=0,ans1=0,ans2=0;
    while(x<=n) {
        if(x%2==0) {//1
            if(a[l]>a[r]) ans1+=a[l],l++,x++;
            else ans1+=a[r],x++,r--;
        }
        else {//2
            if(a[l]>a[r]) ans2+=a[l],l++,x++;
            else ans2+=a[r],x++,r--;
        }
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}*/
#include<bits/stdc++.h>
#define int long long
#define maxn 3005
#define mod (int)(1e9+7)
using namespace std;
int n,a[maxn];
int dp[maxn][maxn];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int len=1;len<=n;len++) {
        for(int i=1;i<=n+1-len;i++) {
            int j=i+len-1;
            if((n-len)%2==1) dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
            else dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
        }
    }
    printf("%lld",dp[1][n]);
    return 0;
}