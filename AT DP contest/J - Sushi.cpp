#include<bits/stdc++.h>
#define int long long
#define maxn 305
#define mod (int)(1e9+7)
using namespace std;
int n;
int cnt[10];
double dp[maxn][maxn][maxn];
double dfs(int i,int j,int k) {
    if(i==0&&j==0&&k==0) return 0.0;
    if(dp[i][j][k]!=0.0) return dp[i][j][k];
    double x=(n*1.0)/((i+j+k)*1.0);
    if(i>0) x+=dfs(i-1,j,k)*(i*1.0/((i+j+k)*1.0));
	if(j>0) x+=dfs(i+1,j-1,k)*(j*1.0/((i+j+k)*1.0));
	if(k>0) x+=dfs(i,j+1,k-1)*(k*1.0/((i+j+k)*1.0));
    return dp[i][j][k]=x;
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        int a;
        scanf("%lld",&a);
        cnt[a]++;
    }
    double ans=dfs(cnt[1],cnt[2],cnt[3]);
    printf("%.10lf",ans);
    return 0;
}