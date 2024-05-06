#include<bits/stdc++.h>
#define int long long
#define maxn 100007
using namespace std;
int n,m,x,y,rx,ry,root,ra,rb;
struct Node{ int val,rd,tag; }p[maxn];
struct Treap{
    int cnt;
    int son[maxn][2],siz[maxn];
    void push_up(int x) { siz[x]=siz[son[x][0]]+siz[son[x][1]]+1; };
    void push_down(int x) {
        if(p[x].tag!=0) {
            p[x].tag=0;
            swap(son[x][0],son[x][1]);
            p[son[x][0]].tag^=1;
            p[son[x][1]].tag^=1;
        }
    }
    int add(int x) {
        p[++cnt].val=x,p[cnt].rd=rand();
        siz[cnt]=1;
        return cnt;
    }
	int merge(int l,int r) {
		if(!l||!r) return l+r;
        push_down(l),push_down(r);
		if(p[l].rd<p[r].rd) {
			son[l][1]=merge(son[l][1],r);
			push_up(l);
			return l;
		} else {
			son[r][0]=merge(l,son[r][0]);
			push_up(r);
			return r;
		}
	}
    void split(int rt,int sizz,int &x,int &y) {
        if(!rt) return (void)(x=y=0);
        push_down(rt);
        if(siz[son[rt][0]]<sizz) {//
            x=rt;
            split(son[rt][1],sizz-(siz[son[rt][0]]+1),son[rt][1],y);
        } else {
            y=rt;
            split(son[rt][0],sizz,x,son[rt][0]);
        } push_up(rt);
    }
    void dfs(int u){
	    push_down(u);
	    if(son[u][0]) dfs(son[u][0]); 
	    cout<<u<<" ";
	    if(son[u][1]) dfs(son[u][1]); 
    }
};
Treap Tr;
signed main(){
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) root=Tr.merge(root,Tr.add(i));
    while(m--) {
        scanf("%ld %lld",&x,&y);
        Tr.split(root,x-1,rx,ry);
        Tr.split(ry,y-x+1,ra,rb);
        p[ra].tag^=1;
        root=Tr.merge(Tr.merge(rx,ra),rb);
    }
    Tr.dfs(root);
    return 0;
}