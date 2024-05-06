#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[1001][1001],r[1001][1001],cr[100001];
bool c[1001][1001];
queue<int> pc;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void bfs(int x,int y,int k){
	int pp=1;
	c[x][y]=false;
	r[x][y]=k;
	pc.push(x);
	pc.push(y);
	while(!pc.empty()){
		int cx=pc.front();
		pc.pop();
		int cy=pc.front();
		pc.pop();
		for(int i=0;i<4;i++){
			int tx=cx+dx[i];
			int ty=cy+dy[i];
			if(tx<=0||ty<=0||tx>n||ty>n||c[tx][ty]==false||p[tx][ty]!=p[cx][cy]) continue;
			r[cx][cy]=k;
			c[cx][cy]=true;
			pp++;
			pc.push(tx);
			pc.push(ty);
		}
	}
	cr[k]=pp;
}
int main(){
	memset(c,true,sizeof(c));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char k;
			cin>>k;
			p[i][j]=k-'0';
		}
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(c[i][j]==true) {
				sum++;
				bfs(i,j,sum);
			}
	for(int i=1;i<=m;i++){
		int x;
		int y;
		cin>>x>>y;
		cout<<cr[r[x][y]]<<endl;
	}
	return 0;
}
