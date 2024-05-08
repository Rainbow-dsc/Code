#include<bits/stdc++.h>
#define int long long
#define maxn 105
#define mod (int)(1e9+7)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int a,b;
int dp[maxn][maxn];//长度为i,最高位是j
void init() {
    for(int i=0;i<=9;i++) dp[1][i]=1;
    for(int i=2;i<=10;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=9;k++) {
                if(abs(j-k)>=2) dp[i][j]+=dp[i-1][k];
            }
        }
    }
}
int solve(int x) {
    int dig[maxn],len=0,ans=0;
    memset(dig,0,sizeof(dig));
    while(x) {dig[++len]=x%10,x/=10;}    for(int i=1;i<len;i++) {
        for(int j=1;j<=9;j++) {
            ans+=dp[i][j];
        }
    }
    for(int i=1;i<dig[len];i++) ans+=dp[len][i];
    for(int i=len-1;i>=1;i--) {
        for(int j=0;j<dig[i];j++) if(abs(j-dig[i+1])>=2) ans+=dp[i][j];
        if(abs(dig[i+1]-dig[i])<2) break;
    }
    return ans;
}
signed main(){
    init();
    scanf("%lld %lld",&a,&b);
    printf("%lld",solve(b+1)-solve(a));
    return 0;
}