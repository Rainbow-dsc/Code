#include<bits/stdc++.h>
#define maxn 110
#define int  long long
using namespace std;
string a,b;
int cnt,d,cnt_for,vis[27],g[27],h,k,l[100],m,n,T;
//d����Ŀ���ĸ��Ӷ��Ƕ���
//g[]�Ǵ���ÿ��ѭ���ı���,h�ǵ�ǰ���Ӷ��Ƕ���(��e��ͬ)
//k���ж���������Ƿ����,l[]�Ǵ����ļ���ѭ�����˸��Ӷ�
//m�ǵ�ǰ����Ӷȣ�n�Ǵ���k=1ʱ��ѭ����
signed main() {
	scanf("%lld",&T);
	while(T--) {
		cnt=0,d=0,m=0,n=0,cnt_for=0,h=0,k=0;
		memset(vis,0,sizeof(vis));
		memset(l,0,sizeof(l));
		do {
			a=b;
			cin>>b;
		} while(b[0]!='O');     //���룬��b[0]='O'ʱͣ�£���֤ERRʱ��һ����������
		for(int i=0; i<a.size(); i++) cnt=cnt*10+a[i]-'0'; //ȡ����Ŀ���ľ�������
		for(int i=4; i<b.size()-1; i++) d=d*10+b[i]-'0'; //ȡ����Ŀ����ʱ�临�Ӷ� O(1)��Ӱ��
		while(cnt>0) {
			cnt--;
			cin>>a;   //����F �� E ,������-1
			if(a[0]=='F') { //�����F
				cnt_for++;
				cin>>a;   //��ǰѭ����+1���������
				if(vis[a[0]-96]) cnt_for=-1;    //������ù������ERR
				else vis[a[0]-96]=1,g[cnt_for]=a[0]-96;    //û�ù��ͱ���ù�����������
				cin>>a>>b;      //���������ֵ��ĩֵ
				if(a[0]!='n'&&b[0]=='n'&&k==0) h++,l[cnt_for]=1;   //���a�����֣�b��n�����ҿ������У���ô��ǰ���Ӷ�+1������ѭ����
				else if(((a.size()==b.size()&&a>b)||(a.size()>b.size())||(a[0]=='n'&&b[0]!='n'))&&k==0) k=1,n=cnt_for;
				//���a>b(n 4,45 12,24 9),���ҿ������У���ô�������Ķ��������У����µ�ǰѭ��
				//��5 8��76 78, n n ֮��Ĳ�Ӱ�죬����Ҫ����
			} else {
				//�����E
				m=max(m,h);
				vis[g[cnt_for]]=0;     //������Ӷȸ��� ���������û�ù�
				if(l[cnt_for]==1) h--,l[cnt_for]=0;    //�����ǰѭ�����˸��Ӷȣ���ǰ���Ӷ�-1��������
				cnt_for--;    //��ǰѭ����-1
				if(n>0&&cnt_for<n) k=0,n=0;   //���������n��ǵ��Ǹ�ѭ������ô��������ѭ���������У�������
			}
			if(cnt_for==-1) printf("ERR\n"),cnt=-1;   //���e<0(�����ù�����E����)����ô���ERR������ѭ��
		}
		if(cnt_for>0) printf("ERR\n");    //���e>0(F����)����ô���ERR������ѭ��
		if(cnt_for==0&&m==d) printf("Yes\n");   //���F,E��ͬ��������Ӷȵ�����Ŀ���ĸ��Ӷȣ����Yes
		if(cnt_for==0&&m!=d) printf("No\n");    //���F,E��ͬ��������ӶȲ�������Ŀ���ĸ��Ӷȣ����No
	}
	return 0;
}
