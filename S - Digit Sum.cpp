#include<bits/stdc++.h>
#define int long long
#define maxn 10005
#define mod (int)(1e9+7)
using namespace std;
string k;
int d,a[maxn];
int dp[maxn][105][2];//还有i位要处理,当前前缀和%d的值是j,判断前缀和是否到达k的值.
int dfs(int pos,int res,int flag) {
    if(pos==0) return (res==0);//当统计到第一位的时候判断统计答案的条件是%d等于0
    if(dp[pos][res][flag]!=-1) return dp[pos][res][flag];//记忆化
    int ans=0,maxx=9;//答案,可以取得最大位数
    if(flag) maxx=a[pos];//如果顶到限制直接选这个数.
    for(int i=0;i<=maxx;i++) ans=(ans+dfs(pos-1,(res+i)%d,flag&&(i==maxx)))%mod;//递归枚举下一位,前缀和更新,判断上界
    dp[pos][res][flag]=ans;
    return ans;
}
signed main(){
    cin>>k>>d;
    int n=k.size();
    for(int i=0;i<n;i++) a[i+1]=k[k.size()-i-1]-'0';//倒序处理,方便处理
    memset(dp,-1,sizeof(dp));
    int ans=dfs(k.size(),0,1);
    printf("%lld",((ans-1)%mod+mod)%mod);//由于0也会被算进去,所以要-1
    return 0;
}