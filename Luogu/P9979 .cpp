#include<bits/stdc++.h>
using namespace std;
int n,ans,sum[1002][1002];
string k[10002];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool check(int x,int y){
    if(x<0||y<0||y>=k[x].size()||x>=n||k[x][y]>'z'||k[x][y]<'a'||sum[x][y]==1) return 0;
    return 1;
}
void dfs(int x,int y){ 
    sum[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(check(tx,ty)) dfs(tx,ty);
    }
}
int main() {
    cin>>n;
    string p;
    getline(cin,p);
    for(int i=0;i<n;i++) getline(cin,k[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<k[i].size();j++)
            if(sum[i][j]==0&&k[i][j]<='z'&&k[i][j]>='a'){
                dfs(i,j);
                ans++;
            }
    cout<<ans;
    return 0;
}
