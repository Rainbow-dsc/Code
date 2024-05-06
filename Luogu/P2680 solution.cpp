#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define re register
using namespace std;
typedef long long ll;
const int inf=1e9+7;
inline int read() {
	int p=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		p=p*10+c-'0';
		c=getchar();
	}
	return f*p;
}
const int maxn=300003;
struct Edge {
	int from,to,w,id;
} p[maxn<<1];
struct query {
	int x,y,lca,d;
} A[maxn];
int n,m,cnt,head[maxn<<1],C[maxn],dis[maxn];
int fa[maxn],depth[maxn],top[maxn],heavy[maxn],size[maxn];
int val[maxn],dnf[maxn],tot,R,L;
inline void add_edge(int x,int y,int W) { //�ӱ�
	cnt++;
	p[cnt].from=head[x];
	head[x]=cnt;
	p[cnt].to=y;
	p[cnt].w=W;
}
inline void dfs1(int x,int f)
//����dfs1:����ÿ����ĸ���fa,���depth,������Сsize,dfs��dnf
{
	fa[x]=f,depth[x]=depth[f]+1,size[x]=1,dnf[++tot]=x;
	for(re int i=head[x]; i; i=p[i].from) {
		int y=p[i].to;
		if(y==f)continue;
		val[y]=p[i].w;
		dis[y]=dis[x]+p[i].w;
		dfs1(y,x);
		size[x]+=size[y];
		if(!heavy[x]||size[y]>size[heavy[x]])
			heavy[x]=y;
	}
}
inline void dfs2(int x,int t) { //����dfs2:��������
	top[x]=t;
	if(!heavy[x])return ;
	dfs2(heavy[x],t);
	for(re int i=head[x]; i; i=p[i].from) {
		int y=p[i].to;
		if(y==fa[x]||y==heavy[x])continue;
		dfs2(y,y);
	}
}
inline int LCA(int x,int y) { //������LCA
	while(top[x]!=top[y]) {
		if(depth[top[x]]<depth[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return depth[x]<=depth[y]?x:y;
}
//=================================���������ʳ������
inline int check(int lim,int sum=0) { //���ִ𰸼���,��������
	memset(C,0,sizeof(C));//ע��ÿһ�ζ�Ҫ���C����
	for(re int i=1; i<=m; i++)
		if(A[i].d>lim) { //����(��)���
			C[A[i].x]++,C[A[i].y]++,C[A[i].lca]-=2;
			sum++;
		}
	for(re int i=n; i>=1; i--) {
		C[fa[dnf[i]]]+=C[dnf[i]];//ÿ�β��ֵ���ۼӵ����׽ڵ�
		if(val[dnf[i]]>=R-lim&&C[dnf[i]]==sum)
			//����һ��·�������������������
			return 1;
	}
	return 0;//�����޽�
}
inline int Binary_search(int llim,int rlim,int mid=0) { //���ִ�
	while(llim<rlim) {
		mid=(llim+rlim)>>1;
		if(check(mid))rlim=mid;
		else llim=mid+1;
	}
	return llim;
}
int main() {
//	freopen("transport.in","r",stdin);
//	freopen("transport.out","w",stdout);
	//����У��ģ�����Ŀ�����= =���ٱ���
	n=read(),m=read();
	for(re int i=1; i<n; i++) {
		int x=read(),y=read(),w=read();
		add_edge(x,y,w);
		add_edge(y,x,w);
		L=max(L,w);//ͳ������Ȩ
	}
	dfs1(1,0);
	dfs2(1,1);//����Ԥ����
	for(re int i=1; i<=m; i++) { //Ԥ����ÿһ�������lca�;���
		A[i].x=read(),A[i].y=read();
		A[i].lca=LCA(A[i].x,A[i].y);
		A[i].d=dis[A[i].x]+dis[A[i].y]-2*dis[A[i].lca];
		R=max(R,A[i].d);
	}
	printf("%d\n",Binary_search(R-L,R+1));//���ִ�
	return 0;
}
