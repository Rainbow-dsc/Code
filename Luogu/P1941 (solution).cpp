#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define int long long
#define maxn 10005
using namespace std;
struct node {
	int id,h,l;
	bool operator <(const node &a) const {
		return id<a.id;
	}
} o[maxn];
int x[maxn],y[maxn],dp[2][maxn],n,m,k,cnt=1,ans;
signed main() {
	memset(dp,inf,sizeof(dp));//�����������ĳ�ʼ��֮һqwq
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1; i<=n; i++) scanf("%lld%lld",&x[i],&y[i]);
	for(int i=1; i<=k; i++) scanf("%lld%lld%lld",&o[i].id,&o[i].l,&o[i].h);
	sort(o+1,o+k+1);//�ܵ�id����!
	for(int i=1; i<=m; i++) dp[0][i]=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) dp[i%2][j]=inf;//ע��Ҫ��ʼ����
		for(int j=x[i]+1; j<=x[i]+m; j++) dp[i%2][j]=min(dp[i%2^1][j-x[i]]+1,dp[i%2][j-x[i]]+1);//p=1����ȫ����
		for(int j=m+1; j<=x[i]+m; j++) dp[i%2][m]=min(dp[i%2][m],dp[i%2][j]);//��m��Ķ���m
		for(int j=1; j<=m-y[i]; j++) dp[i%2][j]=min(dp[i%2][j],dp[i%2^1][j+y[i]]);//p=0��01����
		if(i==o[cnt].id) { //�������ط��йܵ�
			ans=inf;//��Ҫÿ�ζ�Ҫ��ʼ��һ�Σ�
			for(int j=0; j<=o[cnt].l; j++) dp[i%2][j]=inf;
			for(int j=o[cnt].h; j<=m; j++) dp[i%2][j]=inf;
			for(int j=1; j<=m; j++) ans=min(dp[i%2][j],ans);//Ѱ���Ƿ����ͨ��
			if(ans==inf) {
				printf("0\n%lld",cnt-1);
				return 0;
			}
			cnt++;
		}
	}
	ans=inf;//ע��Ҫ��ʼ����
	for(int j=1; j<=m; j++) ans=min(dp[n%2][j],ans);
	printf("1\n%lld",ans);
	return 0;
}
