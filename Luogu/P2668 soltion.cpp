#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans;
int sum[25];
void dfs(int x) { //xΪ���ƴ���
	if (x>=ans) return;
	//˳��
	int k=0;//��˳��
	for (int i=3; i<=14; i++) { //ע��2�ʹ�С�����ܿ���
		if(sum[i]==0) k=0;//˳�Ӷ���
		else {
			k++;//˳�ӳ�������
			if(k>=5) { //��˳�Ӵﵽ����
				for(int j=i; j>=i-k+1; j--) sum[j]--; //����
				dfs(x+1);//������
				for(int j=i; j>=i-k+1; j--) sum[j]++; //����
			}
		}
	}
	k=0;//˫˳��
	for(int i=3; i<=14; i++) {
		if(sum[i]<=1) k=0;
		else {
			k++;
			if(k>=3) { //˫˳�Ӵﵽ����
				for(int j=i; j>=i-k+1; j--) sum[j]-=2; //����
				dfs(x+1);
				for(int j=i; j>=i-k+1; j--) sum[j]+=2; //����
			}
		}
	}
	k=0;//��˳��    //����ͬ��
	for(int i=3; i<=14; i++) {
		if(sum[i]<=2) k=0;
		else {
			k++;
			if(k>=2) { //��˳�Ӵﵽ����
				for(int j=i; j>=i-k+1; j--) sum[j]-=3;
				dfs(x+1);
				for(int j=i; j>=i-k+1; j--) sum[j]+=3;
			}
		}
	}
	//����
	for(int i=2; i<=14; i++) { //ö����3�Ż�4�ŵ���(�������ܴ���)
		if(sum[i]<=3) {
			if(sum[i]<=2) continue;//��������(��������)���ܴ���
			sum[i]-=3;//�������������˵���
			for(int j=2; j<=15; j++) { //������
				if(sum[j]<=0||j==i) continue;//û������ô��??
				sum[j]--;//���������ĵ���
				dfs(x+1);
				sum[j]++;//����
			}
			for(int j=2; j<=14; j++) { //��һ��
				if(sum[j]<=1||j==i) continue;//û��һ����ô��?
				sum[j]-=2;//����������һ��
				dfs(x+1);
				sum[j]+=2;//����
			}
			sum[i]+=3;//����
		} else { //����3����4�����Ҳ����3�����
			sum[i]-=3;//����3�Ŵ����
			for(int j=2; j<=15; j++) { //������  //����ԭ��ͬ��
				if(sum[j]<=0||j==i) continue;
				sum[j]--;
				dfs(x+1);
				sum[j]++;
			}
			for(int j=2; j<=14; j++) { //��һ��
				if(sum[j]<=1||j==i) continue;
				sum[j]-=2;
				dfs(x+1);
				sum[j]+=2;
			}
			sum[i]+=3;

			sum[i]-=4; //����4�Ŵ����
			for(int j=2; j<=15; j++) { //��2������
				if(sum[j]<=0||j==i) continue;//�Լ����ܴ��Լ��
				sum[j]--;//�������ĵ�һ�ŵ�����
				for (int k=2; k<=15; k++) { //�ҵڶ��ŵ���
					if(sum[k]<=0||j==k) continue;
					sum[k]--;//�������ĵڶ��ŵ�����
					dfs(x+1);
					sum[k]++;//����
				}
				sum[j]++;//����
			}
			for(int j=2; j<=14; j++) { //��2���Զ�
				if(sum[j]<=1||j==i) continue;
				sum[j]-=2;//�������ĵ�һ����
				for(int k=2; k<=14; k++) {
					if(sum[k]<=1||j==k) continue;
					sum[k]-=2;//�������ĵڶ�����
					dfs(x+1);
					sum[k]+=2;//����
				}
				sum[j]+=2;//����
			}
			sum[i]+=4;//����
		}
	}
	//��ʣ�µ��Ƴ���
	for(int i=2; i<=15; i++) if(sum[i]) x++;
	ans=min(ans,x);
}
signed main() {
	scanf("%lld%lld",&T,&n);
	while(T--) {
		ans=0x7fffffff;//���һ��
		int x,y;
		memset(sum,0,sizeof sum);//���ѯ�ʣ��ǵ�����
		for(int i=1; i<=n; i++) {
			scanf("%lld%lld",&x,&y);
			if (x==0) sum[15]++;//������������һ��(���Ǵ��Ƶ�ʱ��ע�ⲻҪ���Զ�)
			else if(x==1) sum[14]++;//����A����ֵ�����������
			else sum[x]++;//�����ƴ�����Ӧλ��
		}
		dfs(0);//��ʼ����
		printf("%lld\n",ans);
	}
}
