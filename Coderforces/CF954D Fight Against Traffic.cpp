#include<bits/stdc++.h>
#define int long long
#define maxn 1005
using namespace std;
int n,m,s,t;
int dis[maxn][2];
bool bj[maxn][maxn],vis[maxn];
vector<int> g[maxn];
void bfs(int s,int k) {
    queue<int> q;
    memset(vis,0,sizeof(vis));
    q.push(s);
	vis[s] = 1;
    while(!q.empty()) {
        int fr = q.front(); 
		q.pop();
        for(int v : g[fr]) {
            if(!vis[v]) {
                vis[v] = 1;
                q.push(v);
                dis[v][k] = dis[fr][k] + 1;
            }
        }
    } 
}
signed main() {
    scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
    memset(dis,0x3f,sizeof(dis)); // dis[u][0] æ‡∆µ„£¨ dis[u][1] æ‡÷’µ„
    dis[s][0] = dis[t][1] = 0;
//    for(int i = 1; i <= n; i ++) bj[i][i] = 1;
    for(int i = 1; i <= m; i ++) {
        int a,b;
        scanf("%lld%lld",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        bj[a][b] = bj[b][a] = 1;
    }
    bfs(s,0);
    bfs(t,1);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = i+1; j <= n; j ++) {
            if(bj[i][j]) continue;
            int d1 = dis[i][0] + dis[j][1] + 1, d2 = dis[i][1] + dis[j][0] + 1;
            if(min(d1,d2) >= dis[s][1]) ans ++;
        }
    }
    cout << ans;
    return 0;
}
