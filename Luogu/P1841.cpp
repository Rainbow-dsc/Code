#include<bits/stdc++.h>
using namespace std;
int c[1001][1001],zy[1001][1001],n,m;
bool bj[10001];
struct p{
	int x,y,w;
}a[1000001];
int main(){
	//memset(zy,0x3f,sizeof(zy));
	memset(c,0x3f,sizeof(c));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
		c[a[i].x][a[i].y]=c[a[i].y][a[i].x]=min(c[a[i].y][a[i].x],a[i].w);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(c[i][j]>c[i][k]+c[k][j]){
					c[i][j]=c[i][k]+c[k][j];
					zy[i][j]=k;
				}
				else if(c[i][j]==c[i][k]+c[k][j]) zy[i][j]=-1;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(zy[i][j]!=-1) bj[zy[i][j]]=1;
		}
	bool flag=0;
	for(int i=1;i<=n;i++) {
		if(bj[i]){
			flag=1; 
			cout<<i<<" ";
		}
	}
	if(!flag) cout<<"No important cities.";
	return 0;
}
