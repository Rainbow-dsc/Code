#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int dx[8]= {2,2,-2,-2,1,1,-1,-1};
int dy[8]= {1,-1,1,-1,2,-2,2,-2};
queue<int> pc;
int p[1001][1001];
bool c[1001][1001];
void bfs(int x,int y) {
	pc.push(x);
	pc.push(y);
	while(!pc.empty()) {
		int cx=pc.front();
		pc.pop();
		int cy=pc.front();
		pc.pop();
		for(int i=0; i<8; i++) {
			int tx=cx+dx[i];
			int ty=cy+dy[i];
			if(tx>n||ty>n||tx<=0||ty<=0||c[tx][ty]==true) continue;
			p[tx][ty]=p[cx][cy]+1;
			c[tx][ty]=true;
			pc.push(tx);
			pc.push(ty);
		}
	}
}
int main() {
	memset(c,false,sizeof(c));
	memset(p,0,sizeof(p));
	int q,w;
	scanf("%d%d%d%d%d",&n,&x,&y,&q,&w);
	c[x][y]=true;
	bfs(x,y);
	cout<<p[q][w];
	return 0;
}
