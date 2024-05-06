#include <bits/stdc++.h>
using namespace std;

const int maxn=250005;

typedef pair<long long,int> pii;

long long a[maxn],b[maxn];
bool vis[maxn];//��¼�Ƿ�����ÿһλ�˿�

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
		{//���޷����㵱ǰ�˿Ͳ��ҶѶ���������
			vis[que.top().second]=false;
			tot+=que.top().first;//ɾ���Ѷ�
			que.pop();
			cnt--;
		}
		if(tot>=b[i])
		{
			tot-=b[i];
			que.push((pii){b[i],i});
			vis[i]=true;//���뵱ǰ��
			cnt++;
		}
	}
	printf("%lld\n",cnt);
	for(int i=1;i<=n;i++)
		if(vis[i]) printf("%d ",i);
	puts("");
	return 0;
}
