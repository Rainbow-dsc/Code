#include<bits/stdc++.h>
using namespace std;
bool vis[10000005];
long long n,x,maxx=-1,len=0,num[5000000],v[10000005];
inline long long read(){
    char c=getchar();
    long long x=0,f=1;
    while(c<48){if(c=='-')f=-1;c=getchar();}
    while(c>47)x=(x*10)+(c^48),c=getchar();
    return x*f;
}
void solve(){
    for(long long i=2;i<=10000000;i++){
        if(vis[i]==false){
            len++;
            num[len]=i;
        }
        for(long long j=1;j<=len&&i*num[j]<=10000000;j++){
            vis[i*num[j]]=true;
            if(i%num[j]==0) break;
        }
    }
}
void dfs(long long from,long long sum){
    v[sum]=num[from];
    for(long long i=from;i<=len&&sum*num[i]<=10000000;i++){
        dfs(i,sum*num[i]);
    }
}
int main(){
    solve();
    dfs(1,1);
    v[1]=1;
    n=read();
    for(long long i=1;i<=n;i++){
        x=read();
        maxx=max(maxx,v[x]);
    }
    cout<<maxx-1;

    return 0;
}
