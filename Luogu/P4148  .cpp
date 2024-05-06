#include<bits/stdc++.h>
#define maxn 200005
#define lc t[p].c[0]
#define rc t[p].c[1]
#define __ int x1, int y1, int x2, int y2
using namespace std;
int n,e,g,y,q[maxn];
struct Point { int a[2],v; }P[maxn];
struct KDT{ int w,s,c[2],bin[2],bax[2];Point d; }t[maxn];
bool cmp0(Point i,Point j) { return i.a[0]<j.a[0]; }
bool cmp1(Point i,Point j) { return i.a[1]<j.a[1]; }
int newnode() {
	if (e) return q[e--];
	return ++y;
}
void update(int p) {
	for(int i=0;i<2;i++) {
		t[p].bin[i]=t[p].bax[i]=t[p].d.a[i];
		if(lc) {
			t[p].bin[i]=min(t[p].bin[i],t[lc].bin[i]);
			t[p].bax[i]=max(t[p].bax[i],t[lc].bax[i]);
		}
		if (rc) {
			t[p].bin[i]=min(t[p].bin[i],t[rc].bin[i]);
			t[p].bax[i]=max(t[p].bax[i],t[rc].bax[i]);
		}
	}
	t[p].w=t[lc].w+t[p].d.v+t[rc].w;
	t[p].s=t[lc].s+t[rc].s+1;
}
void slap(int p) {
	if(!p) return ;
	P[++g]=t[p].d;
	q[++e]=p;
	slap(lc),slap(rc);
}
int rebuild(int l,int r,bool k) {
	if(l>r) return 0;
	int mid=(l+r)>>1,p=newnode();
    nth_element(P+l,P+mid,P+r+1,k?cmp1:cmp0);
	t[p].d=P[mid];
	lc=rebuild(l,mid-1,!k),rc=rebuild(mid+1,r,!k);
	update(p);
	return p;
}
void check(int &p,bool k) {
	if (t[lc].s>2*t[rc].s||t[rc].s>2*t[lc].s) {
		g=0;
		slap(p);
		p=rebuild(1,t[p].s,k);
	}
}
void insert(int &p, Point x,bool k) {
	if(!p) {
		p=newnode();
		lc=rc=0;
		t[p].d=x;
        update(p);
		return ;
	}
	if(x.a[k]<=t[p].d.a[k]) insert(lc,x,!k);
	else insert(rc,x,!k);
	update(p);
	check(p,k);
} 
bool checkin (__,int X1,int Y1,int X2,int Y2) { return x1<=X1&&x2>=X2&&y1<=Y1&&y2>=Y2; }
bool checkout(__,int X1,int Y1,int X2,int Y2) { return x1>X2||x2<X1||y1>Y2||y2<Y1; }
int query(int p, __) {
	if (!p) return 0;
	int x=0;
	if (checkin (x1,y1,x2,y2,t[p].bin[0],t[p].bin[1],t[p].bax[0],t[p].bax[1])) return t[p].w;
	if (checkout(x1,y1,x2,y2,t[p].bin[0],t[p].bin[1],t[p].bax[0],t[p].bax[1])) return 0;
	if (checkin (x1,y1,x2,y2,t[p].d.a[0],t[p].d.a[1],t[p].d.a[0],t[p].d.a[1])) x=t[p].d.v;
	return x+query(lc,x1,y1,x2,y2)+query(rc,x1,y1,x2,y2);
}
signed main(){
	scanf("%d",&n);
	int rt=0,las=0;
	while(1) {
		int opt;
		scanf("%d",&opt); 
		if(opt==1) {
			Point i;
			scanf("%d %d %d",&i.a[0],&i.a[1],&i.v);
			i.a[0]^=las,i.a[1]^=las,i.v^=las;
			insert(rt,i,0);
		}
		if(opt==2) {
			int x1,y1,x2,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1^=las,y1^=las,x2^=las,y2^=las;
			printf("%d\n",las=query(rt,x1,y1,x2,y2));
		}
		if(opt==3) break;
	}
	return 0;
}
