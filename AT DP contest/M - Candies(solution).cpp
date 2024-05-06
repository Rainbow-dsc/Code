#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>

#define int long long
const int mod=1e9+7;
const int MK=1e5+5;
const int MN=105;

using namespace std;

inline int read(){
    int x=0,f=1;char c=getchar();
    for(;(c<'0'||c>'9');c=getchar()){if(c=='-')f=-1;}
    for(;(c>='0'&&c<='9');c=getchar())x=x*10+(c&15);
    return x*f;
}

int a[MN],dp[MN][MK],sum[MN][MK],n,K;
signed main(void){
    n=read(),K=read();
    for(int i=1;i<=n;i++)a[i]=read();
    dp[1][0]=sum[1][0]=1;
    for(int i=1;i<=K;i++) dp[1][i]=(i<=a[1]),sum[1][i]=dp[1][i]+sum[1][i-1];
    for(int i=2;i<=n;i++){
        dp[i][0]=sum[i][0]=1;
        for(int j=1;j<=K;j++){
            if(j<=a[i])dp[i][j]=sum[i-1][j]%mod;
            else dp[i][j]=(sum[i-1][j]-sum[i-1][j-a[i]-1]+mod)%mod;
            sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
        }
    }
    cout<<dp[n][K]<<endl;
    return 0;
}
