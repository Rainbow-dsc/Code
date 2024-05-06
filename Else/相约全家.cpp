#include<bits/stdc++.h>
using namespace std;
int n,m;
char p[205][205];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
bool bj[205][205];
int c[205][205],r[205][205];
queue<int> pc;
bool check(int x,int y){
	if(x<=0||y<=0||x>n||y>m||bj[x][y]==true||p[x][y]=='#') return false;
	else return true;
}
void bfs1(int x,int y){
	pc.push(x);
	pc.push(y);
	while(!pc.empty()){
		int cx=pc.front();
		pc.pop();
		int cy=pc.front();
		pc.pop();
		for(int i=0;i<4;i++){
			int tx=dx[i]+cx;
			int ty=dy[i]+cy;
			if(check(tx,ty)==false) continue;
			c[tx][ty]=c[cx][cy]+1;
			bj[tx][ty]=true;
			pc.push(tx);
			pc.push(ty);
		}
	}
}
void bfs2(int x,int y){
	pc.push(x);
	pc.push(y);
	while(!pc.empty()){
		int cx=pc.front();
		pc.pop();
		int cy=pc.front();
		pc.pop();
		for(int i=0;i<4;i++){
			int tx=dx[i]+cx;
			int ty=dy[i]+cy;
			if(check(tx,ty)==false) continue;
			r[tx][ty]=r[cx][cy]+1;
			bj[tx][ty]=true;
			pc.push(tx);
			pc.push(ty);
		}
	}
}
int main() {
    scanf("%d%d",&n,&m);
    int mx,my,px,py;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>p[i][j];
    		if(p[i][j]=='@'){
    			mx=i;
    			my=j;
			}
			if(p[i][j]=='&'){
				px=i;
				py=j;
			}
		}
	}
	memset(bj,false,sizeof(bj));
	memset(c,0,sizeof(c));
	bj[mx][my]=true;
	bfs1(mx,my);
	memset(bj,false,sizeof(bj));
	memset(r,0,sizeof(r));
	bj[px][py]=true;
	bfs2(px,py);
	int ans=1e9;
	bool cr=false;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(p[i][j]=='F'&&c[i][j]!=0&&r[i][j]!=0) {
				ans=min(ans,c[i][j]+r[i][j]);
				cr=true;
			}
	if(cr==true) printf("%d",ans);
	else printf("Meeting cancelled");
    return 0;
}
