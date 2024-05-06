#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
inline void read(int &x) {
	char c=getchar();
	int p=1;
	x=0;
	while(!isdigit(c)) {
		if(c=='-')p=-1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	x*=p;
}
const int maxn=1000005;
int minn[maxn<<2],tag[maxn<<2],n,m;
inline int _min(int a,int b) {
	return a>b?b:a;
}
void push_up(int rt) {
	minn[rt]=_min(minn[rt<<1],minn[rt<<1|1]);
}
void build(int rt,int l,int r) {
	if(l==r) read(minn[rt]);
	else {
		build(lson);
		build(rson);
		push_up(rt);
	}
}
void push_down(int rt) {
	minn[rt<<1]-=tag[rt];
	minn[rt<<1|1]-=tag[rt];
	tag[rt<<1]+=tag[rt];
	tag[rt<<1|1]+=tag[rt];
	tag[rt]=0;
}
void update(int rt,int l,int r,int L,int R,int num) {
	if(l>=L&&r<=R) {
		minn[rt]-=num;
		tag[rt]+=num;
	} else {
		if(tag[rt])push_down(rt);
		if(L<=mid)update(lson,L,R,num);
		if(R>mid)update(rson,L,R,num);
		push_up(rt);
	}
}
int main() {
	read(n);
	read(m);
	build(1,1,n);
	for(register int i=1; i<=m; ++i) {
		int d,s,j;
		read(d);
		read(s);
		read(j);
		update(1,1,n,s,j,d);//区间修改min值
		if(minn[1]<0) { //如果全部的minn小于0就不行了
			printf("-1\n%d\n",i);
			return 0;
		}
	}
	puts("0");
	return 0;
}
