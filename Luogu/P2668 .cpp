#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans;
int sum[20];
void dfs(int x) {//x:出了几次牌
	if(x>=ans) return ;
	//顺子
	int k=0;
	for(int i=3; i<=14; i++) { //要排除2,大小王
		if(sum[i]==0) k=0;//一个顺子
		else {
			k++;//每个顺子个数
			if(k>=5) {//如果大于5个
				for(int j=i; j>=i-k+1; j--) sum[j]--; //搜索
				dfs(x+1);//次数+1
				for(int j=i; j>=i-k+1; j--) sum[j]++; //回溯
			}
		}
	}
	k=0;//双顺子
	for(int i=3; i<=14; i++) {
		if(sum[i]<=1) k=0;
		else {
			k++;
			if(k>=3) {
				for(int j=i; j>=i-k+1; j--) sum[j]-=2;
				dfs(x+1);
				for(int j=i; j>=i-k+1; j--) sum[j]+=2;
			}
		}
	}
	k=0;//三顺子
	for(int i=3; i<=14; i++) {
		if(sum[i]<=2) k=0;
		else {
			k++;
			if(k>=2) {
				for(int j=i; j>=i-k+1; j--) sum[j]-=3;
				dfs(x+1);
				for(int j=i; j>=i-k+1; j--) sum[j]+=3;
			}
		}
	}
	//带牌
	for(int i=2; i<=14; i++) {
		if(sum[i]<=3) {
			if(sum[i]<=2) continue;
			sum[i]-=3;
			for(int j=2; j<=15; j++) {
				if(sum[j]<=0||i==j) continue;
				sum[j]--;
				dfs(x+1);
				sum[j]++;
			}
			for(int j=2; j<=14; j++) {
				if(sum[j]<=1||i==j) continue;
				sum[j]-=2;
				dfs(x+1);
				sum[j]+=2;
			}
			sum[i]+=3;
		} else {
			sum[i]-=3;
			for(int j=2; j<=15; j++) {
				if(sum[j]<=0||i==j) continue;
				sum[j]--;
				dfs(x+1);
				sum[j]++;
			}
			for(int j=2; j<=14; j++) {
				if(sum[j]<=1||i==j) continue;
				sum[j]-=2;
				dfs(x+1);
				sum[j]+=2;
			}
			sum[i]+=3;

			sum[i]-=4;
			for(int j=2; j<=15; j++) {
				if(i==j||sum[j]<=0) continue;
				sum[j]--;
				for(int k=2; k<=15; k++) {
					if(j==k||sum[k]<=0) continue;
					sum[k]--;
					dfs(x+1);
					sum[k]++;
				}
				sum[j]++;
			}
			for(int j=2; j<=14; j++) {
				if(i==j||sum[j]<=1) continue;
				sum[j]-=2;
				for(int k=2; k<=14; k++) {
					if(j==k||sum[k]<=1) continue;
					sum[k]-=2;
					dfs(x+1);
					sum[k]+=2;
				}
				sum[j]+=2;
			}
			sum[i]+=4;
		}
	}
	for(int i=2; i<=15; i++) if(sum[i]) x++;
	ans=min(ans,x);
}
signed main() {
	scanf("%lld%lld",&T,&n);
	while(T--) {
		ans=0x7fffffff;
		memset(sum,0,sizeof(sum));
		for(int i=1; i<=n; i++) {
			int x,y;
			scanf("%lld %lld",&x,&y);
			if(x==0) sum[15]++;
			else if(x==1) sum[14]++;//将1进行特殊处理是为了再求顺子时方便处理
			else sum[x]++;
		}
		dfs(0);
		printf("%lld\n",ans);
	}
	return 0;
}
