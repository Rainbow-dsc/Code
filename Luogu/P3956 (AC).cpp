#include <bits/stdc++.h>
#define maxn 1100
using namespace std;
int m,n,ans=0x7fffffff;
int a[maxn][maxn],dis[maxn][maxn],bj[maxn][maxn];
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
void cr(int x,int y,int ansn,int color) {
	if((x==n)&&(y==n)) {
		ans=min(ansn,ans);
		return;
	}
	for(int i=0; i<4; i++) {
		int tx=x+dx[i];
		int ty=y+dy[i];
//		if(tx<=0||ty<=0||tx>n||ty>n||bj[tx][ty])
		if(a[x][y]||a[tx][ty]) {
			if(a[tx][ty]==0) {
				if(ansn+2<dis[tx][ty]) {
					bj[tx][ty]=0;
					dis[tx][ty]=ansn+2,cr(tx,ty,ansn+2,color);
					bj[tx][ty]=1;
				}
			} else {
				if((color==a[tx][ty])&&(ansn<dis[tx][ty])) {
					bj[tx][ty]=0;
					dis[tx][ty]=ansn,cr(tx,ty,ansn,color);
					bj[tx][ty]=1;
				} else if((ansn+1<ans)&&(ansn+1<dis[tx][ty])) {
					bj[tx][ty]=0;
					dis[tx][ty]=ansn+1,cr(tx,ty,ansn+1,a[tx][ty]);
					bj[tx][ty]=1;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			dis[i][j]=0x7fffffff,a[i][j]=0,bj[i][j]=1;
	for(int i=1; i<=m; i++) {
		int q,w,p;
		scanf("%d%d%d",&q,&p,&w);
		a[q][p]=w+1;
	}
	bj[1][1]=0;
	cr(1,1,0,a[1][1]);
	if(ans==0x7fffffff) printf("-1");
	else printf("%d",ans);
	return 0;
}
