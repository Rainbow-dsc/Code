#include<bits/stdc++.h>
#define rd(x) x=read()
using namespace std;
int n,k,dis[100005],cnt,ans,vis[100005];
vector<int>E[100005];
void addEdge(int u,int v) {
    E[u].push_back(v);
}
inline int read() {
    int x=0,flag=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') flag=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*flag;
}
 
int dfs(int root,int d) {
    vector<int>a;
    a.clear();
    bool flag=0;
    for(int i=0; i<E[root].size(); i++) {
        int tmp = dfs(E[root][i],d);
        tmp = tmp;
        a.push_back(tmp);
    }
    if(E[root].size()==0) return 1;
    sort(a.begin(),a.end());
    int a1=a[a.size()-1];
    int a2;
    if(E[root].size()<=1)a2=0;
    else a2=a[a.size()-2];
    if(a1+a2>d) {
        cnt++;
        return 0;
    } else return a1+1;
}
 
int main() {
    rd(n),rd(k);
    for(int i=1; i<=n-1; i++) {
        int u,v;
        rd(u),rd(v);
        addEdge(u,v);
    }
    int l=1,r=1e7,mid;
    while(l<=r) {
        memset(dis,-1,sizeof(dis));
        memset(vis,0,sizeof(vis));
        mid=(l+r)>>1;
        cnt=0;
        dfs(1,mid);
        if(cnt<=k)ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
