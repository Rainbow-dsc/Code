#include <bits/stdc++.h>
using namespace std;

const int maxn=250005;

typedef pair<long long,int> pii;

long long a[maxn],b[maxn];
bool vis[maxn];//记录是否满足每一位顾客

priority_queue<pii,vector<pii>,less<pii> > que;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;i++) scanf("%lld",b+i);
	long long tot=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		tot+=a[i];
		if(tot<b[i]&&!que.empty()&&que.top().first>b[i])
		{//若无法满足当前顾客并且堆顶更贵的情况
			vis[que.top().second]=false;
			tot+=que.top().first;//删除堆顶
			que.pop();
			cnt--;
		}
		if(tot>=b[i])
		{
			tot-=b[i];
			que.push((pii){b[i],i});
			vis[i]=true;//加入当前点
			cnt++;
		}
	}
	printf("%lld\n",cnt);
	for(int i=1;i<=n;i++)
		if(vis[i]) printf("%d ",i);
	puts("");
	return 0;
}
