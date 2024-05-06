#include<bits/stdc++.h>
#define int long long
#define maxn 20
#define mod (int)(1e9+7)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int a,b;
int dp[maxn][maxn][maxn];//表示第i位最高位是j,k有多少个.
int q_pow(int x) {
    int ans=1,a=10;
    while(x) {
        if(x%2==1) ans*=a;
        x>>=1;
        a*=a;
    }
    return ans;
}
void init() {
    for(int i=0;i<=9;i++) dp[1][i][i]=1;
    for(int i=2;i<=13;i++) {//位数
        for(int j=0;j<=9;j++) {//当前位
            for(int k=0;k<=9;k++)/*上一位*/ for(int l=0;l<=9;l++)/*统计的数字*/ dp[i][j][l]+=dp[i-1][k][l];
            dp[i][j][j]+=q_pow(i-1);
        }
    }
}
int solve(int x,int num) {
    int dig[maxn];//拆完位的数组
    int len=0,ans=0;
    memset(dig,0,sizeof(dig));
    while(x) {dig[++len]=x%10; x/=10;}
    for(int i=1;i<len;i++) for(int j=1;j<=9;j++) ans+=dp[i][j][num];//位数小于原数,不含前导0
    for(int i=1;i<dig[len];i++) ans+=dp[len][i][num];//位数等于原来的数,但是最高位小于当前数,且不含前导零
    for(int i=len-1;i>=1;i--) {
        for(int j=0;j<dig[i];j++) ans+=dp[i][j][num];
        for(int j=len;j>i;j--) if(dig[j]==num) ans+=dig[i]*q_pow(i-1);
    }//这个循环是在判断第一位已经顶住的情况下,之后每一位计算如果顶住是的答案和没有顶住的答案
    return ans;
}
signed main(){
    scanf("%lld%lld",&a,&b);
    init();
    for(int i=0;i<=9;i++) printf("%lld ",solve(b+1,i)-solve(a,i));//类似与前缀和的操作
    return 0;
}