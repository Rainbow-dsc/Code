#include<bits/stdc++.h>
using namespace std;
int f[201][201];
bool vis[201][201];
string s;
bool Pair(int l,int r){
    if(s[l]=='('&&s[r]==')') return true;
    if(s[l]=='['&&s[r]==']') return true;
    return false;
}
int dfs(int l,int r){
    if(l>r) return f[l][r]=0;
    if(l==r) return f[l][r]=1;
    if(vis[l][r]) return f[l][r];
    f[l][r]=0x3f3f3f3f;
    vis[l][r]=true;
    if(Pair(l,r))
        f[l][r]=min(f[l][r],dfs(l+1,r-1));
    for(int k=l;k<r;k++){
        f[l][r]=min(f[l][r],dfs(l,k)+dfs(k+1,r));
    }
    return f[l][r];
}
int main(){
    memset(vis,false,sizeof(vis));
    memset(f,0,sizeof(f));
    cin>>s;
    cout<<dfs(0,s.size()-1);
    return 0;
}
