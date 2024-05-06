#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005],ans,s[1005][1005];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dfs(int x,int y){
	if(s[x][y]) return s[x][y];
	s[x][y]=1;
	for(int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx>0&&ty>0&&ty<=m&&tx<=n&&a[x][y]>a[tx][ty]) {
			dfs(tx,ty);
			s[x][y]=max(s[x][y],s[tx][ty]+1);
		}
	}
	return s[x][y];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans,dfs(i,j));
	cout<<ans;
	return 0;
}
