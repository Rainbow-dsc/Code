#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define mem(a,v) memset(a,v,sizeof(a))
#define i128 __int128
using namespace std;
const int INF = 0x7f7f7f7f;
const int MAXN = 1e5+7;
const int MOD = 1e9+7;
inline int read() {
    int x=0, f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*f;
}
inline void write(i128 x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline i128 gcd(i128 x,i128 y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int n,m;
struct Edge{
	int next,to;
}edge[MAXN*2];
struct N{
	i128 p,q;
	N operator +(const N& b){
		N c;
		if(p==0)return b;
		if(b.p==0)return *this;
		c.p=p*b.q+b.p*q;
		c.q=q*b.q;
		i128 g=gcd(c.p,c.q);
		c.p/=g,c.q/=g;
		return c;
	}
};
void print(N a){
	write(a.p);putchar(' ');
	write(a.q);putchar('\n');
}
struct node{
	int ind,oud;
	N val;
}v[MAXN];
int head[MAXN],cnt;
void add(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(int x){
	N qs=v[x].val;
	qs.q*=v[x].oud;
	for(int i=head[x];i;i=edge[i].next){
		int y=edge[i].to;
		v[y].val=v[y].val+qs;
	//	printf("%lld ",y);
		//print(v[y].val);
		dfs(y);
	}
	if(v[x].oud!=0)v[x].val={0,0};
}
signed main() {
//	freopen("P7113_8.in","r",stdin);
//	freopen("P7113_8.ans","w",stdout);
	n=read(),m=read();
	up(i,1,n){
		int d=read();
		v[i].oud=d;
		up(j,1,d){
			int y=read();
			v[y].ind++;
			add(i,y);
		}
	}
	up(i,1,n){
		if(v[i].ind==0){
			v[i].val={1,1};
			dfs(i);
		}
	}
	up(i,1,n){
		if(v[i].oud==0){
			print(v[i].val);
		}
	}
	return 0;
}
