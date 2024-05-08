#include<bits/stdc++.h>
#define int long long 
#define maxn 8005
using namespace std;
int n,m;
struct aa{
    struct Node{ int val,rd; }node[maxn];
    int root,siz[maxn],son[maxn][2],cnt=0;
	int rx,ry,rz;
	void update(int rt) {siz[rt]=siz[son[rt][0]]+siz[son[rt][1]]+1; }
	int add(int x) {
		siz[++cnt]=1;
		node[cnt].val=x;
		node[cnt].rd=rand();
		return cnt;
	} 
	void split(int rt,int key,int &x,int &y) {
		if(!rt) return (void)(x=y=0);
		if(node[rt].val<=key) {
			 x=rt;
			 split(son[rt][1],key,son[rt][1],y);
		} else {
			y=rt;
			split(son[rt][0],key,x,son[rt][0]);
		} update(rt);
	}
	void split1(int rt,int sizz,int &x,int &y) {
		if(!rt) return (void)(x=y=0);
		if(siz[son[rt][0]]<sizz) {
			x=rt;
			split(son[rt][1],sizz-(siz[son[rt][0]]+1),son[rt][1],y);
		} else {
			y=rt;
			split(son[rt][0],sizz,x,son[rt][0]);
		} update(rt);
	}
	int merge(int l,int r) {
		if(!l||!r) return l+r;
		if(node[l].rd<node[r].rd) {
			son[l][1]=merge(son[l][1],r);
			update(l);
			return l;
		} else {
			son[r][0]=merge(l,son[r][0]);
			update(r);
			return r;
		}
	}
	int getrank(int x,int k) {
		while(true) {
			if(k<=siz[son[x][0]]) x=son[x][0];
			else if(k>siz[son[x][0]]+1) {
				k-=(siz[son[x][0]]+1);
				x=son[x][1];
			} else return x;
		}
	}
    int getrnk(int x) { return node[getrank(root,x)].val;}
};
signed main(){
    scanf("%lld %lld",&n,&m);
    while(m--) {
        string opt; int s,t;
        cin>>opt;
        if(opt=="Top") {
            scanf("%lld",&s);

        }
        if(opt=="Bottom") {
            scanf("%lld",&s);

        }
        if(opt=="Insert") {
            scanf("%lld %lld",&s,&t);

        }
        if(opt=="Ask") {
            scanf("%lld",&s);

        } 
        if(opt=="Query") {
            scanf("%lld",&s);

        }
    }
    return 0;
}