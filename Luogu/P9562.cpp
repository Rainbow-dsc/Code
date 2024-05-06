#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],s[1001][1001],ans;
int m,n;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
int dfs(int x,int y) {
    if(s[x][y]==1) return s[x][y];
    s[x][y]=1;
    for(int i=0; i<4; i++) {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>0&&yy>0&&xx<=n&&yy<=m&&a[x][y]>a[xx][yy]) {
            dfs(xx,yy);
            s[x][y]=max(s[x][y],s[xx][yy]+1);
        }
         
    }
    return s[x][y];
}
int main() {
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            ans=max(ans,dfs(i,j));
    cout<<ans;
    return 0;
}
