#include<bits/stdc++.h>
#define Inf 0x7f7f7f7f
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define mem(a,v) memset(a,v,sizeof(a))
#define int long long
using namespace std;
const int MAXN = 1e2 + 7;
int MOD;
inline int read(){
	int x=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(48+x%10);
}
int mul(int a,int b){
	return (a*b-(long long)((long double)a/MOD*b)*MOD+MOD)%MOD;
//	return a*b%MOD;
}
struct M {
	int val[MAXN][MAXN];
	int row,col;
	M(int n,int m){row = n,col = m,mem(val,0);}
	M operator * (const M& b)const {
		M c(row,b.col);
		up(i,1,row) {
			up(k,1,col)	{//a.col=b.row
				if(val[i][k])up(j,1,b.col) {
					c.val[i][j]+=mul(val[i][k],b.val[k][j]);
					c.val[i][j]%=MOD;
				}
			}
		}
		return c;
	}
	void print(){
		up(i,1,row){
			up(j,1,col){
				printf("%lld ",val[i][j]);
			}
			putchar('\n');
		}
	}
};

M ksm(M a,int k,M& ans) {
	while(k) {
		if(k&1) {
			ans=a*ans;
		}
		k>>=1;
		a=a*a;
	}
	return ans;
}
int n,g;
signed main(){
	MOD = read();
	M a(2,2);
	a.val[1][1]=read();
	a.val[1][2]=read();
	a.val[2][2]=1;
	M ans(2,1);
	ans.val[1][1]=read();
	ans.val[2][1]=1;
	
	n=read();
	g=read();
	ksm(a,n,ans);
	write(ans.val[1][1]%g);
	return 0;
}
