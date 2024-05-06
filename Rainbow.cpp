//Problem ID: 12597 图1-最远节点
//#include<bits/stdc++.h>
//using namespace std;
//vector<int>q[100001];
//int n,m,d[100001];//d[i]表示已i为根的子树能到达的编号最大的点
//void dfs(int now,int ans){
//  d[now]=ans;
//  for(int i=0;i<q[now].size();i++){
//      int t=q[now][i];
//      if(d[t]==-1)
//          dfs(t,ans);
//  }
//}
//int main() {
//  cin>>n>>m;
//  int x,y;
//  for(int i=1;i<=m;i++){
//      scanf("%d%d",&x,&y);
//      q[y].push_back(x);
//  }
//  memset(d,-1,sizeof(d));
//  for(int i=n;i>=1;i--){
//      if(d[i]==-1)
//          dfs(i,i);
//  }
//  for(int i=1;i<=n;i++) printf("%d ",d[i]);
//    return 0;
//}
//
//
//Problem ID: 8260 信息传递 
//#include<bits/stdc++.h>
//using namespace std;
//int a[200001];
//int n;
//int ans=2343252;
//int dfs(int x){
//    int z=a[x],www=1;
//    while(z!=x){
//        www++;
//        z=a[z];
//        if(www==100) return 2000000;
//    }
//    return www;
//}
//int main() {
//    cin>>n;
//    for(int i=1;i<=n;i++) cin>>a[i];
//    for(int i=1;i<=n;i++) ans=min(ans,dfs(i));
//    cout<<ans;
//    return 0;
//}
//
//
//
//
//
//杂物1
//#include<bits/stdc++.h>
//using namespace std;
//struct Chore {
//  int x, y;
//  bool operator < (const Chore &b) const {
//      return y > b.y;
//  }
//};
//Chore mc(int x, int y) {
//  Chore res;
//  res.x = x;
//  res.y = y;
//  return res;
//}
//int n, t[10005], dis[10005], ind[10005], ans;
//vector<int> g[10005];
//priority_queue<Chore> q;
//void topsort() {
//  memset(dis, 0x3f, sizeof(dis));
//  for(int i = 1; i <= n; i++) {
//      if(!ind[i]) q.push(mc(i, t[i])), dis[i] = t[i];
//  }
//  while(!q.empty()) {
//      Chore u = q.top();
//      q.pop();
//      for(int i = 0; i < g[u.x].size(); i++) {
//          int v = g[u.x][i];
//          ind[v]--;
//          if(!ind[v]) q.push(mc(v, dis[u.x] + t[v])), dis[v] = dis[u.x] + t[v];
//      }
//  }
//}
//int main() {
//  cin >> n;
//  for(int i = 1; i <= n; i++) {
//      scanf("%d", &t[i]);
//      while(1) {
//          int x;
//          scanf("%d", &x);
//          if(!x) break;
//          g[x].push_back(i);
//          ind[i]++;
//      }
//  }
//  topsort();
//  for(int i = 1; i <= n; i++) {
//      ans = max(ans, dis[i]);
//  }
//  cout << ans << endl;
//  return 0;
//}
//
//
// 杂物2
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//  int dp[100001],n,k,t;
//  cin>>n;
//  for(int i=1;i<=n;i++){
//      scanf("%d%d",&k,&t);
//计算各项准备工作中最晚结束时间
//因为k一定小于i，所以dp[k]已经计算完毕了
//先计算第i个任务本身时间，即得到第i个任务所有的前序任务所需时间
//      while(scanf("%d",&k),k) dp[i]=max(dp[i],dp[k]);
//加上第i个任务本身的时间，即得到第i个任务最早结束时间
//      dp[i]+=t;
//  }
//输出所以任务的最晚结束时间
//  printf("%d",*max_element(dp+1,dp+1+n));
//}
//
//图2-图的连通块个数
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//vector<int> q[200005];
//struct cinn{
//    int a,b;
//}aa[1000001];
//int bj[1000001];
//int ans=0;
//void dfs(int x){
//    if(bj[x]!=-1) return;
//    bj[x]=ans;
//    for(register int i=0;i<q[x].size();i++) dfs(q[x][i]);
//}
//int main() {
//    memset(bj,-1,sizeof(bj));
//    cin>>n>>m;
//    for(int i=1;i<=m;i++){
//        scanf("%d%d",&aa[i].a,&aa[i].b);
//        if(aa[i].a!=aa[i].b){
//            q[aa[i].a].push_back(aa[i].b);
//            q[aa[i].b].push_back(aa[i].a);
//        }
//    }
//    for(int i=1;i<=n;i++){
//        if(bj[i]==-1){
//            ans++;
//            dfs(i);
//        }
//    }
//    cout<<ans;
//}
//
//
//
//#include<bits/stdc++.h>
//using namespace std;
//struct Edge {
//    int t;
//    int nexty;
//} edge[200000];
//int head[20000];
//int cnt=0;//链式前向星
//void add(int a,int b) { //存边
//    cnt++;
//    edge[cnt].t=b;
//    edge[cnt].nexty=head[a];
//    head[a]=cnt;
//}
//bool used[20000]= {0}; //是否遍历过
//int col[20000]= {0}; //每一个点的染色
//int sum[2];//黑白两种染色各自的点数
//bool dfs(int node,int color) { //染色（返回false即impossible）
//    if(used[node]) { //如果已被染过色
//        if(col[node]==color)return true;//如果仍是原来的颜色，即可行
//        return false;//非原来的颜色，即产生了冲突，不可行
//    }
//    used[node]=true;//记录
//    sum[col[node]=color]++;//这一种颜色的个数加1，且此点的颜色也记录下来
//    bool tf=true;//是否可行
//    for(int i=head[node]; i!=0&&tf; i=edge[i].nexty) { //遍历边
//        tf=tf&&dfs(edge[i].t,1-color);//是否可以继续染色
//    }
//    return tf;//返回是否完成染色
//}
//int main() {
//    int n,m;
//    scanf("%d%d",&n,&m);
//    int a,b;
//    while(m--) {
//        scanf("%d%d",&a,&b);
//        add(a,b);
//        add(b,a);//存的是有向边，所以存两次
//    }
//    int ans=0;
//    for(int i=1; i<=n; i++) {
//        if(used[i])continue;//如果此点已被包含为一个已经被遍历过的子图，则不需重复遍历
//        sum[0]=sum[1]=0;//初始化
//        if(!dfs(i,0)) { //如果不能染色
//            printf("Impossible");
//            return 0;//直接跳出
//        }
//        ans+=min(sum[0],sum[1]);//加上小的一个
//    }
//    printf("%d",ans);//输出答案
//    return 0;
//}
//
//
//
//#include<bits/stdc++.h>
//using namespace std;
//struct Edge {
//    int u,v,w;
//} edge[200005];
//long long fa[5000005],n,m,ans,eu,ev,cnt;
//bool cmp(Edge a,Edge b) {
//    return a.w<b.w;
//}
//long long find(long long x) {
//    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
//    return x;
//}
//void kruskal() {
//    sort(edge,edge+m,cmp);
//    for(long long i=0; i<m; i++) {
//        eu=find(edge[i].u), ev=find(edge[i].v);
//        if(eu==ev) continue;
//        ans+=edge[i].w;
//        fa[ev]=eu;
//    }
//}
//int main() {
//    cin>>n>>m;
//    for(long long i=1; i<=n; i++) fa[i]=i;
//    for(long long i=0; i<m; i++) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
//    kruskal();
//    //for(int i=1;i<=n;i++) cout<<fa[i]<<" ";
//    cout<<ans;
//    return 0;
//}
//
//
//#include<bits/stdc++.h>
//using namespace std;
//struct Edge {
//    int u,v,ww;
//} edge[100000];
//int fa[100],n,m,ans,eu,ev,cnt,jc=0,a,b;
//bool cmp(Edge a,Edge b) {
//    return a.ww<b.ww;
//}
//int find(int x) {
//    while (fa[x]!=x) x=fa[x]=fa[fa[x]];
//    return x;
//}
//int main() {
//    cin>>n;
//    for(int i=1; i<=n; i++) fa[i]=i;
//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<=n; j++) {
//            cin>>edge[++jc].ww;
//            edge[jc].u=i;
//            edge[jc].v=j;
//        }
//    }
//    cin>>m;
//    for(int i=1; i<=m; i++) {
//        cin>>a>>b;
//        for(int j=1; j<=jc; j++) {
//            if((edge[j].u==a&&edge[j].v==b)||(edge[j].v==a&&edge[j].u==b))
//                edge[j].ww=0;
//        }
//    }
//    sort(edge+1,edge+jc+1,cmp);
//    for(int i=1; i<=jc; i++) {
//        eu=find(edge[i].u);
//        ev=find(edge[i].v);
//        if(eu==ev) continue;
//        ans+=edge[i].ww;
//        fa[ev]=eu;
//    }
//    //for(int i=0;i<m;i++)cout<<fa[i]<<' ';
//    cout<<ans;
//    return 0;
//}
//
//Arctic Network
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,cnt=0,fa[500005]= {0},jc=0,xx[500005],yy[500005],jc1=0;
//double ans[500005]= {0};
//int find(int x) {
//    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
//    return x;
//}
//struct node {
//    int u;
//    int v;
//    double w;
//} edge[500005];
//bool comp(node x,node y) {
//    return x.w<y.w;
//}
//int main() {
//    int T;
//    cin>>T;
//    for(int tt=1; tt<=T; tt++) {
//        cin>>m>>n;
//        for(int i=1; i<=n; i++)
//            fa[i]=i;
//        for(int i=1; i<=n; i++) {
//            cin>>xx[i]>>yy[i];
//        }
//        for(int i=1; i<=n; i++) {
//            for(int j=1; j<=n; j++) {
//                if(i!=j) {
//                    edge[++jc1].u=i;
//                    edge[jc1].v=j;
//                    edge[jc1].w=sqrt((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]));
//                }
//            }
//        }
//        sort(edge+1,edge+jc1+1,comp);
//        for(int i=1; i<=jc1; i++) {
//            int u=find(edge[i].u);
//            int v=find(edge[i].v);
//            double w=edge[i].w;
//            if(u!=v) {
//                cnt++;
//                fa[u]=v;
//                ans[++jc]=w;
//            }
//        }
//        if(m<n)
//            printf("%.2lf\n",ans[jc-m+1]);
//        else cout<<0.00;
//        jc=0;
//        jc1=0;
//        cnt=0;
//        memset(fa,0,sizeof(fa));
//        memset(ans,0,sizeof(ans));
//        memset(xx,0,sizeof(xx));
//        memset(yy,0,sizeof(yy));
//        memset(edge,0,sizeof(edge));
//    }
//    return 0;
//}
//
//
//模板Dijkstra算法
//#include <bits/stdc++.h>
//using namespace std;
//struct data{
//  int id;
//  long long w;
//};
//int n,m;
//int vis[100001];
//long long f[100001];
//vector<data> v[100001];
//priority_queue<data> q;
//bool operator < (data x,data y){
//  return x.w>y.w;
//}
//int main(){
//  cin>>n>>m;
//  for(int i=2;i<=n;i++) f[i]=1e8;
//  for(int i=1;i<=m;i++){
//      int x,y;
//      long long z;
//      cin>>x>>y>>z;
//      v[x].push_back(data {y,z});
//  }
//  q.push(data{1,0});
//  while(!q.empty()){
//      int id=q.top().id;
//      long long w=q.top().w;
//      q.pop();
//      if(vis[id]) continue;
//      vis[id]=1;
//      f[id]=w;
//      for(int i=0;i<v[id].size();i++){
//          if(!vis[v[id][i].id])
//              q.push(data{v[id][i].id,w+v[id][i].w});
//      }
//  }
//  for(int i=1;i<=n;i++){
//          if(f[i]==1e8) cout<<"inf ";
//          else cout<<f[i]<<" ";
//  }
//  return 0;
//}
//
//
//[模板]Floyd算法
//#include<bits/stdc++.h>
//using namespace std;
//int f[505][505];
//int main() {
//  int n;
//  cin>>n;
//  for(int i=1; i<=n; i++)
//      for(int j=1; j<=n; j++)
//          cin>>f[i][j];
//  for(int k=1; k<=n; k++)
//      for(int i=1; i<=n; i++)
//          for(int j=1; j<=n; j++)
//              if(f[i][k]+f[k][j]<f[i][j]) {
//                  if(i==j) {
//                      cout<<"No Solution";
//                      return 0;
//                  }
//                  f[i][j]=f[i][k]+f[k][j];
//              }
//  for(int i=1; i<=n; i++) {
//      for(int j=1; j<=n; j++)
//          cout<<f[i][j]<<' ';
//      cout<<endl;
//  }
//  return 0;
//}
//
//
//旅行
//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//#define inf 0x7fffffff
//using namespace std;
//int fa[5050];
//int n,m,s,t;
//struct edge {
//  int f,t,d;
//} es[5050];
//int find(int x) {
//  return fa[x]==x?x:fa[x]=find(fa[x]);
//}
//void init() {
//  for(int i=1; i<=n; i++) fa[i]=i;
//}
//bool cmp(edge a,edge b) {
//  return a.d>b.d;
//}
//int gcd(int a,int b) {
//  return b?gcd(b,a%b):a;
//}
//int main() {
//  int aa,bb;
//  double rate=inf*1.0;
//  scanf("%d%d",&n,&m);
//  for(int i=1; i<=m; i++)
//      scanf("%d%d%d",&es[i].f,&es[i].t,&es[i].d);
//  scanf("%d%d",&s,&t);
//  sort(es+1,es+m+1,cmp);
//  for(int i=1; i<=m; i++) {
//      init();
//      int j;
//      for(j=i; j<=m; j++) {
//          if(find(es[j].f)!=find(es[j].t))
//              fa[find(es[j].f)]=find(es[j].t);
//          if(find(s)==find(t)) break;
//      }
//      int v1=es[i].d,v2=es[j].d;
//      if(v1*1.0/v2<rate) {
//          aa=v1;
//          bb=v2;
//          rate=v1*1.0/v2;
//      }
//  }
//  int g=gcd(aa,bb);
//  if(rate==inf) printf("IMPOSSIBLE\n");
//  else if(aa%bb==0) printf("%d",aa/bb);
//  else printf("%d/%d",aa/g,bb/g);
//  return 0;
//}
//
//懒癌
// #include <bits/stdc++.h>
//using namespace std;
//int n,m,c;
//struct bian {
//  int u,v,w;
//} e[100001];
//struct mu {
//  int a,b;
//} d[1000001];
//int f[1001][1001];
//int f1[1001][1001];
//int main() {
//  cin>>n>>m>>c;
//  for(int i=1;i<=n;i++){
//      for(int j=1;j<=n;j++){
//          f[i][j]=1e9;
//          f1[i][j]=1e9;
//      }
//      f[i][i]=f1[i][i]=0;
//  }
//  for(int i=1; i<=m; i++) {
//      scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
//      if(e[i].u==e[i].v) continue;
//      f[e[i].u][e[i].v]=min(f[e[i].u][e[i].v],e[i].w);
//      f1[e[i].u][e[i].v]=1;
//  }
//
//  for(int k=1; k<=n; k++) {
//      for(int i=1; i<=n; i++) {
//          for(int j=1; j<=n; j++) {
//              if(f[i][k]+f[k][j]<f[i][j]||f[i][j]==f[i][k]+f[k][j]&&f1[i][k]+f1[k][j]<f1[i][j]){
//                  f[i][j]=f[i][k]+f[k][j];
//                  f1[i][j]=f1[i][k]+f1[k][j];
//              }
//          }
//      }
//  }
//  for(int i=1; i<=c; i++) {
//      scanf("%d%d",&d[i].a,&d[i].b);
//      if(f[d[i].a][d[i].b]==1e9) printf("Windows is the best!\n");
//      else printf("%d %d\n",f[d[i].a][d[i].b],f1[d[i].a][d[i].b]);
//  }
//  return 0;
//}
//
//
//P6464
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,sum,ans;
//int f[110][110],g[110][110];
//int main() {
//  cin>>n>>m;
//  for (int i=1; i<=n; i++) //初始化
//      for (int j=1; j<=n; j++)
//          if (i==j) f[i][j]=0;
//          else f[i][j]=1e9;//最大值记得开大一点
//  for (int i=1; i<=m; i++) {
//      int u,v,w;
//      cin>>u>>v>>w;
//      f[u][v]=f[v][u]=w;//双向建边
//  }
//  for (int k=1; k<=n; k++) //无传送门时的最短路f数组
//      for (int i=1; i<=n; i++)
//          for (int j=1; j<=n; j++)
//              f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//  ans=1e9;
//  for (int k=1; k<=n; k++)
//      for (int l=k+1; l<=n; l++) {
//          for (int i=1; i<=n; i++) //注意：每次更新传送门都要重置g数组
//              for (int j=1; j<=n; j++)
//                  g[i][j]=f[i][j];
//          g[k][l]=g[l][k]=0;
//          for (int i=1; i<=n; i++) //k作为中转点
//              for (int j=1; j<=n; j++)
//                  g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
//          for (int i=1; i<=n; i++) //l作为中转点
//              for (int j=1; j<=n; j++)
//                  g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
//          sum=0;
//          for (int i=1; i<=n; i++) //求边和
//              for (int j=i+1; j<=n; j++)
//                  sum+=g[i][j];
//          ans=min(ans,sum);//更新最小值
//      }
//  cout<<ans<<endl;
//  return 0;
//}
//
//
//昂贵的字符串
//#include<bits/stdc++.h>
//using namespace std;
//string s;
//char a,b;
//int c[10001];
//int main() {
//  cin>>s;
//  cin>>a>>b;
//  if(a<'a') a+=32;
//  if(b<'a') b+=32;
//  int len=s.size();
//  int sum=0;
//  for(int i=0;i<len;i++){
//      if(s[i]<'a') s[i]+=32;
//      else continue;
//  }
//  for(int i=0;i<len;i++){
//      if(s[i]==a) s[i]=b;
//      else continue;
//  }
//  for(int i=0;i<len;i++) c[i]=int(s[i]);
//  sort(c,c+len);
//  for(int i=0;i<len;i++){
//      if(c[i]!=c[i+1]) sum++;
//  }
//  cout<<sum*len;
//  return 0;
//}
//
//
//最小差
//#include<bits/stdc++.h>
//using namespace std;
//int n,k,num[1000005],ks[1000005],kb[1000005],ans;
//int main() {
//    scanf("%d%d",&n,&k);
//    for(int i=0; i<n; i++) {
//        scanf("%d",&num[i]);
//    }
//    sort(num,num+n);
//    for(int i=0; i<=k; i++) {
//        ks[i]=num[i]-num[0];
//        kb[i]=num[n-1]-num[n-1-i];
//    }
//    for(int i=0; i<=k; i++) {
//        ans=max(ans,ks[i]+kb[k-i]);
//    }
//    printf("%d",num[n-1]-num[0]-ans);
//    return 0;
//}
//
//
//
//价值不小于k的区间
//#include<bits/stdc++.h>
//using namespace std;
//int a[300010],b[300010];
//int n,k;
//void PUSH(int x,int q1) {
//    int q2=upper_bound(b+1,b+q1,x)-b;
//    for(int i=q1; i>q2; i--) b[i]=b[i-1];
//    b[q2]=x;
//    return;
//}
//void POP(int x,int q1) {
//    int q2=lower_bound(b+1,b+q1,x)-b;
//    for(int i=q2; i<q1-1; i++) b[i]=b[i+1];
//    return;
//}
//long long work() {
//    int Q=1,Q1=1;
//    long long ans=0;
//    b[Q++]=a[1];
//    for(int i=2; i<=n; i++) {
//        PUSH(a[i],Q);
//        Q++;
//        int c=0;
//        for(int j=1; j<=(Q-1)/2; j++)
//            c+=b[Q-j]-b[j];
//        while(c>=k) {
//            ans+=n-i+1;
//            POP(a[Q1],Q);
//            Q--;
//            Q1++;
//            c=0;
//            for(int j=1; j<=(Q-1)/2; j++)
//                c+=b[Q-j]-b[j];
//        }
//    }
//    return ans;
//}
//int main() {
//    scanf("%d%d",&n,&k);
//    for(int i=1; i<=n; i++)
//        scanf("%d",&a[i]);
//    printf("%lld",work());
//    return 0;
//}
//
//函数
//#include<bits/stdc++.h>
//using namespace std;
//typedef __int128 ll;
//const int N=1e5+5;
//int q,n,r,lg[N];
//ll mod,dp[N][20];
//void init(){
//    for(int i=0;i<=100000;i++) dp[i][0]=i%mod;
//    for(int i=1;i<=lg[100000];i++)
//        for(int j=1;j+(1<<(i-1))<=100000;j++)
//            dp[j][i]=dp[j][i-1]*dp[j+(1<<(i-1))][i-1]%mod;
//}
//ll solve(int l,int r){
//     ll ans=1%mod;
//     while(l<=r){
//         ans=ans*dp[l][lg[r-l+1]]%mod;
//         l=l+(1<<lg[r-l+1]);
//     }
//     return ans;
//}
//void print(ll a){
//    if(a>9)print(a/10);
//    cout<<(int)(a%10);
//}
//int main() {
//    scanf("%d%lld", &q, &mod);
//    lg[0]=0;
//    ll count=0;
//    ll p=0;
//    for(int i=1;i<N;i++){
//        lg[i]=p;
//        count++;
//        if(1<<p==count){
//            p++;
//            count=0;
//        }
//    }
//    init();
//    while(q--){
//        int a,b;
//        scanf("%d%d",&a,&b);
//        print(solve(b+1,a));
//        cout<<'\n';
//    }
//    return 0;
//}
//
//巨大的数
//#include<bits/stdc++.h>
//using namespace std;
//long long n,s;
//long long sum=0;
//long long qh(long long x) {
//  sum=0;
//  while(x>0) {
//      sum+=x%10;
//      x/=10;
//  }
//  return sum;
//}
//int main() {
//  cin>>n>>s;
//  long long ansn=0;
//  long long ans=0;
//  if(n<s) {
//      cout<<0;
//      return 0;
//  }
//  for(register long long i=s; i<=n; i++) {
//      ans=qh(i);
//      if(i-sum>=s) {
//          ansn=i;
//          printf("%lld",n-ansn+1);
//          return 0;
//      }
//  }
//  cout<<0;
//  return 0;
//}
//
//
//
//A Single Number
//#include<bits/stdc++.h>
//using namespace std;
//inline int read() {
//  int x=0,f=1;
//  char ch=getchar();
//  while(ch<'0'||ch>'9') {
//      if(ch=='-')
//          f=-1;
//      ch=getchar();
//  }
//  while(ch>='0' && ch<='9')
//      x=x*10+ch-'0',ch=getchar();
//  return x*f;
//}
//int main(){
//    int n;
//    n=read();
//    int *arr=new int[n];
//    int eor1=0;
//    for(int i=0;i<n;i++)
//    {
//        arr[i]=read();
//        eor1^=arr[i];
//    }
//结束后eor1的值就为出现次数为奇数的那两个数的异或
//因为这两个数不一样所以他们的异或肯定不为0，所以二进制形式下肯定不全为0
//    int right=eor1&(~eor1+1);//这个操作为通过位运算提取出一个二进制数在最右边的1（百度）
//所以可以通过right这个数将数组化成两个阵营，一个是和righ相与&为0的，一个是相与&不为0的
//这两个不同的奇数肯定是各自属于不同的阵营，因为他们在right这个位置上的二进制数一个为1另一个肯定为0
//    int eor2=0;
//    for(int i=0;i<n;i++){
//        if((arr[i]&right)==0){//这个相与必须加括号不然过不了，大坑。。。。有大佬知道的解释下
//            eor2^=arr[i];
//        }
//    }
//    eor1=eor1^eor2;
//    cout<<eor1;
//    if(eor1<eor2){
//        cout<<eor1<<" "<<eor2<<endl;
//        return 0;
//    }
//    cout<<eor2<<" "<<eor1<<endl;
//    return 0;
//}
//
//
//可数的数字
//#include<bits/stdc++.h>
//using namespace std;
//int a[27];
//int main(){
//    int n,m,now=0,ans=0;
//    scanf("%d%d",&n,&m);
//    for(int i=1;i<=m;i++){
//        int t=0;
//        while(1){
//            t++; //表示位数（从后往前数）
//            a[t]++;
//            if(a[t]==2) a[t]=0,now--;
//            else break;
//        }
//        now++;
//        //cout<<"i="<<i<<" now="<<now<<endl;
//        if(now<=4&&i>=n) ans++;
//    }
//    printf("%d",ans);
//}
//
//
//质数和分解
//#include<bits/stdc++.h>
//using namespace std;
//int a,s[50]= {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
//int dp[2000]= {1};
//int main()
//{
//    for(int i=1; i<=46; i++)
//        for(int j=s[i]; j<=200; j++)
//            dp[j]+=dp[j-s[i]];
//    while(scanf("%d",&a)!=EOF)
//    {
//        cout<<dp[a]<<endl;
//    }
//}
//
//有趣的游戏
//#include<bits/stdc++.h>
//using namespace std;
//string a;
//int ans6=0;
//int ans1=0;
//int ans0=0;
//int main() {
//  cin>>a;
//  for(int i=0;i<a.size();i++){
//      if(a[i]=='6') ans6++;
//      if(a[i]=='1') ans1++;
//      if(a[i]=='0') ans0++;
//  }
//  if(ans6!=0||ans1<ans0) cout<<"Alice";
//  else cout<<"Bob";
//  return 0;
//}
//
//
//
//幸运数字
//#include<bits/stdc++.h>
//using namespace std;
//const int mod=1e9+7;
//int y,z,ans;
//long long dp[50001][501];//dp[i][j]表示个位数之和i,对z取余结果为j的满足条件的数字总数
//int main() {
//  cin>>y>>z;
//  memset(dp,0,sizeof(dp));
//  dp[0][0]=1;
//  for(int i=0;i<y;i++){//表示当前各位数之和
//      for(int k=0;k<z;k++){
//          for(int j=1;j<=min(9,y);j++){//j表示当前这一位上的数字
//              int a=i+j,b=(k*10+j)%z;//a表示当前的数位和，b表示当前对z的余数
//              dp[a][b]=(dp[a][b]+dp[i][k])%mod;
//          }
//      }
//  }
//  dp[y][0]=max(0LL,dp[y][0]);
//  cout<<dp[y][0];
//  return 0;
//}
//
//
//拯救地球
//#include <bits/stdc++.h>
//using namespace std;
//#define N 200005
//struct node {
//  int x,y,z;
//  bool friend operator < (node A,node B) {
//      return A.z<B.z;
//  }
//} q[N];
//struct Ask {
//  int x,w,id;
//  bool friend operator < (Ask A,Ask B) {
//      return A.w<B.w;
//  }
//} a[N];
//int n,m,Q;
//int in[N],size[N],fa[N],Ans[N];
//int find(int x) {
//  if(x==fa[x])return x;
//  return fa[x]=find(fa[x]);
//}
//int main() {
//  scanf("%d%d",&ns,&m);
//  scanf("%d",&Q);
//  for(int i=1; i<=n; i++)fa[i]=i,size[i]=1;
//  for(int i=1; i<=m; i++) scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].z);
//  sort(q+1,q+m+1);
//  for(int i=1; i<=Q; i++) {
//      scanf("%d%d",&a[i].x,&a[i].w);
//      a[i].id=i;
//  }
//  sort(a+1,a+Q+1);
//  int op=1;
//  for(int i=1; i<=m; i++) {
//      while(a[op].w<q[i].z && op<=Q) {
//          Ans[a[op].id]=size[find(a[op].x)];
//          op++;
//      }
//      if(find(q[i].x)!=find(q[i].y)) {
//          size[fa[q[i].y]]+=size[fa[q[i].x]];
//          fa[fa[q[i].x]]=fa[q[i].y];
//      }
//  }
//  while(op<=Q) {
//      Ans[a[op].id]=size[find(a[op].x)];
//      op++;
//  }
//  for(int i=1; i<=Q; i++) {
//      printf("%d\n",Ans[i]);
//  }
//  return 0;
//}
//
//兔纸的公司
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e5+5;
//int n,cc,tt,fa[maxn],deep[maxn],c[maxn],val[maxn];
//bool flag,vis[maxn];
//long long x[maxn],y[maxn];
//bool cmp(int x,int y) {
//  return x>y;
//}
//void get_deep(int u) {
//  if(!deep[fa[u]]) get_deep(fa[u]);
//  deep[u]=deep[fa[u]]+1;
//}
//void init() {
//  memset(x,0,sizeof(x));
//  memset(y,0,sizeof(y));
//  memset(c,0,sizeof(c));
//  memset(deep,0,sizeof(deep));
//  memset(val,0,sizeof(val));
//  memset(vis,false,sizeof(vis));
//  cc=tt=0;
//  flag=true;
//}
//void read() {
//  scanf("%d",&n);
//  for(int i=1; i<=n; i++) scanf("%lld",&x[i]);
//  for(int i=1; i<=n; i++) {
//      scanf("%d",&fa[i]);
//      vis[fa[i]]=true;
//  }
//}
//void work() {
//  deep[1]=1;
//  y[1]=x[1]-1;
//  for(int i=2; i<=n; i++) {
//      if(!deep[i])
//          get_deep(i);
//      y[i]=x[i]-deep[i];
//  }
//  sort(y+1,y+n+1);
//  if(y[n]==y[n-1]) {
//      printf("So Sad!\n");
//      flag=false;
//      return;
//  }
//  for(int i=1; i<=n-1; i++) {
//      if(y[i]!=y[i-1])
//          tt++;
//      c[tt]++;
//  }
//  sort(c+1,c+tt+1,cmp);
//}
//void solve() {
//  int f;
//  if(!flag) return;
//  priority_queue<int> pq;
//  for(int i=1; i<=n; i++) {
//      if(!vis[i]) {
//          cc++;
//          pq.push(deep[i]-1);
//      }
//  }
//  for(int i=1; i<=tt; i++) {
//      if(cc<c[i]) {
//          printf("So Sad!\n");
//          flag=false;
//          break;
//      }
//      for(int j=1; j<=c[i]; j++) {
//          f=pq.top();
//          pq.pop();
//          val[j]=f-1;
//      }
//      for(int j=1; j<=c[i]; j++) {
//          if(val[j]) pq.push(val[j]);
//          else cc--;
//      }
//  }
//  if(flag) printf("nice Bunny!\n");
//}
//int main() {
//  int t;
//  scanf("%d",&t);
//  while(t--) {
//      init();
//      read();
//      work();
//      solve();
//  }
//  return 0;
//}
//
//
//四面楚歌
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <string>
//#include <cstring>
//#include <cstdio>
//using namespace std;
//const int maxn = 100000;
//struct bigInt{
//    int d[maxn], len;
//
//    void clean() { while(len > 1 && !d[len-1]) len--; }
//
//    bigInt()          { memset(d, 0, sizeof(d)); len = 1; }
//    bigInt(int num)   { *this = num; }
//    bigInt(char* num) { *this = num; }
//    bigInt operator = (const char* num){
//        memset(d, 0, sizeof(d)); len = strlen(num);
//        for(int i = 0; i < len; i++) d[i] = num[len-1-i] - '0';
//        clean();
//        return *this;
//    }
//    bigInt operator = (int num){
//        char s[20]; sprintf(s, "%d", num);
//        *this = s;
//        return *this;
//    }
//    bigInt operator + (const bigInt& b){
//        bigInt c = *this; int i;
//        for (i = 0; i < b.len; i++){
//            c.d[i] += b.d[i];
//            if (c.d[i] > 9) c.d[i]%=10, c.d[i+1]++;
//        }
//        while (c.d[i] > 9) c.d[i++]%=10, c.d[i]++;
//        c.len = max(len, b.len);
//        if (c.d[i] && c.len <= i) c.len = i+1;
//        return c;
//    }
//    //  c=c+b;  c+b;
//
//
//    bigInt operator - (const bigInt& b){
//        bigInt c = *this; int i;
//        for (i = 0; i < b.len; i++){
//            c.d[i] -= b.d[i];
//            if (c.d[i] < 0) c.d[i]+=10, c.d[i+1]--;
//        }
//        while (c.d[i] < 0) c.d[i++]+=10, c.d[i]--;
//        c.clean();
//        return c;
//    }
//    bigInt operator * (const bigInt& b)const{
//        int i, j; bigInt c; c.len = len + b.len;
//        for(j = 0; j < b.len; j++) for(i = 0; i < len; i++)
//            c.d[i+j] += d[i] * b.d[j];
//        for(i = 0; i < c.len-1; i++)
//            c.d[i+1] += c.d[i]/10, c.d[i] %= 10;
//        c.clean();
//        return c;
//    }
//    bigInt operator / (const bigInt& b){
//        int i, j;
//        bigInt c = *this, a = 0;
//        for (i = len - 1; i >= 0; i--)
//        {
//            a = a*10 + d[i];
//            for (j = 0; j < 10; j++) if (a < b*(j+1)) break;
//            c.d[i] = j;
//            a = a - b*j;
//        }
//        c.clean();
//        return c;
//    }
//    bigInt operator % (const bigInt& b){
//        int i, j;
//        bigInt a = 0;
//        for (i = len - 1; i >= 0; i--)
//        {
//            a = a*10 + d[i];
//            for (j = 0; j < 10; j++) if (a < b*(j+1)) break;
//            a = a - b*j;
//        }
//        return a;
//    }
//    bigInt operator += (const bigInt& b){
//        *this = *this + b;
//        return *this;
//    }
//
//    bool operator <(const bigInt& b) const{
//        if(len != b.len) return len < b.len;
//        for(int i = len-1; i >= 0; i--)
//            if(d[i] != b.d[i]) return d[i] < b.d[i];
//        return false;
//    }
//    bool operator >(const bigInt& b) const{return b < *this;}
//    bool operator<=(const bigInt& b) const{return !(b < *this);}
//    bool operator>=(const bigInt& b) const{return !(*this < b);}
//    bool operator!=(const bigInt& b) const{return b < *this || *this < b;}
//    bool operator==(const bigInt& b) const{return !(b < *this) && !(b > *this);}
//
//    string str() const{
//        char s[maxn]={};
//        for(int i = 0; i < len; i++) s[len-1-i] = d[i]+'0';
//        return s;
//    }
//};
//
//istream& operator >> (istream& in, bigInt& x)
//{
//    string s;
//    in >> s;
//    x = s.c_str();
//    return in;
//}
//
//ostream& operator << (ostream& out, const bigInt& x)
//{
//    out << x.str();
//    return out;
//}
//
//
//int main(){
//    bigInt a,b;
//    cin >> a >> b;
//    cout<<a+b+1;
//    return 0;
//}
//
//
//
//方程
//#include<bits/stdc++.h>
//using namespace std;
///*
//令a=n!
//可以得到(x-a)(y-a)=a*a
//所以本题目即求a*a的因数个数
//*/
//const int MAXN=1e5+7;
//int prime[MAXN];//先把10000以内的质数预处理出来
//bool flag[MAXN];
//int a[MAXN];
//int ans[MAXN];
//int n;
//int main(){
//    memset(flag,true,sizeof(flag));
//    int sum=0;
//    for(int i=2;i<=10000;++i){
//        if(flag[i]){
//            sum++;
//            prime[sum]=i;
//            for(int k=2;k*i<=10000;++k){
//                flag[k*i]=false;
//            }
//        }
//    }
//    int len=0;
//    int tmp=0;
//    while(scanf("%d",&n),n){
//        memset(ans,0,sizeof(ans));
//        ans[0]=1;
//        len=0;
//        memset(a,0,sizeof(a));
//        for(int i=2;i<=n;++i){
//            int k=i;
//            for(int j=1;j<=sum&&prime[j]<=i;++j){
//                while(k%prime[j]==0){
//                    a[prime[j]]++;
//                    k/=prime[j];
//                }
//            }
//        }
//        for(int i=1;i<=sum&&prime[i]<=n;++i){
//            for(int j=0;j<=len;j++){
//                ans[j]*=(a[prime[i]]*2+1);
//            }
//            for(int j=0;j<=len;++j){
//                if(ans[j]>=10){
//                    ans[j+1]+=ans[j]/10;
//                    ans[j]=ans[j]%10;
//                    if(j==len) len++;
//                }
//            }
//        }
//        for(int i=0;i<=len;++i) printf("%d",ans[len-i]);
//        puts("");
//    }
//}
//
//棋子
//#include <bits/stdc++.h>
//using namespace std;
//char ta[40],tb[40];
//int first[4],second[4],a[4];
//bool f[35][35][35][35],ok=0;
//void dfs(int w,int x,int y,int z) {
//    if(ok==1) return;
//    if(f[w][x][y][z]==1) return;
//    f[w][x][y][z]=1;
//    if(f[second[0]][second[1]][second[2]][second[3]]==1) {
//        ok=1;
//        return;
//    }
//    a[0]=w;
//    a[1]=x;
//    a[2]=y;
//    a[3]=z;
//    for(int i=0; i<=3; i++) {//四个为一组，直接包含操作一
//        if(a[i]>0 && a[(i+2)%4]>0) {//操作二
//            a[i]--;
//            a[(i+2)%4]--;
//            a[(i+1)%4]++;
//            a[(i+3)%4]++;
//            dfs(a[0],a[1],a[2],a[3]);
//            //回溯
//            a[i]++;
//            a[(i+2)%4]++;
//            a[(i+1)%4]--;
//            a[(i+3)%4]--;
//        }
//        if(a[i]>0 && a[(i+1)%4]>0) {//操作三
//            a[i]--;
//            a[(i+1)%4]--;
//            a[(i+2)%4]++;
//            dfs(a[0],a[1],a[2],a[3]);
//            //回溯
//            a[i]++;
//            a[(i+1)%4]++;
//            a[(i+2)%4]--;
//        }
//    }
//}
//int main() {
//    int T;
//    cin>>T;
//    while(T--) {
//        memset(first,0,sizeof(first));
//        memset(second,0,sizeof(second));
//        memset(f,0,sizeof(f));
//        ok=0;
//        scanf("%s%s",ta,tb);
//        for(int i=0; i<strlen(ta); i++){
//            if(ta[i]=='*')
//                first[i%4]++;
//        }
//        for(int i=0; i<strlen(tb); i++){
//            if(tb[i]=='*')
//                second[i%4]++;
//        }
//        dfs(first[0],first[1],first[2],first[3]);
//        if(ok) cout<<"YES"<<endl;
//        else cout<<"NO"<<endl;
//    }
//    return 0;
//}
///*
//1．将一个棋子移动到它左边或右边第4个格子（如果那个格子为空）。
//例如：
//...*........
//=>
//.......*....
//
//...****.....
//=>
//....****....
//
//....*.**....
//=>
//...**.*.....
//
//2．将一个棋子移动到它右边第3个格子（如果右边第1和3个格子为空，且它右边第2个格子不为空），
//移动之后，原先它右边第1个格子将会放上一个棋子，右边第2个格子上的棋子将会被拿走。
//例如：
//...*.*.....
//=>
//....*.*....
//
//3．将一个棋子移动到它右边第2个格子（如果右边第1个格子不为空，且它右边第2个格子为空），
//移动之后，原先它右边第1个格子上的棋子将会被拿走。
//例如：
//...**.....
//=>
//.....*....
//*/
//
//
//路线
//#include <bits/stdc++.h>
//#define xxx 13
//#define yyy 111
//using namespace std;
//int n,m,p,x[xxx],y[xxx],f[xxx][xxx];
//int used[yyy][yyy],d[yyy][yyy],h[yyy][yyy],ans,inf;
//int dx[4]= {1,-1,0,0},dy[4]= {0,0,1,-1};
//struct haha {
//    int x,y,d;
//} U,V;
//struct cmp {
//    bool operator()(haha &h1,haha &h2) {
//        return h1.d>h2.d;
//    }
//};
//priority_queue<haha,vector<haha>,cmp>q;
//int distan(haha a,haha b) {
//    return (h[a.x][a.y]-h[b.x][b.y])*(h[a.x][a.y]-h[b.x][b.y])+1;
//}
//void Dj(int stx,int sty) {
//    memset(used,0,sizeof(used));
//    memset(d,127,sizeof(d));
//    inf=d[0][0];
//    d[stx][sty]=0;
//    q.push((haha) {
//        stx,sty,0
//    });
//    while (!q.empty()) {
//        U=q.top();
//        q.pop();
//        if (used[U.x][U.y]) continue;
//        used[U.x][U.y]=1;
//        for (int dir=0; dir<4; dir++) {
//            V.x=U.x+dx[dir];
//            V.y=U.y+dy[dir];
//            V.d=U.d+distan(U,V);
//            if (V.x<1||V.x>n||V.y<1||V.y>m||V.d>=d[V.x][V.y]) continue;
//            d[V.x][V.y]=V.d;
//            q.push(V);
//        }
//    }
//}
//int us[13];
//void dfs(int w,int pre,int an) {
//    if (w>p) {
//        ans=min(ans,an);
//        return;
//    }
//    for (int i=1; i<=p; i++) {
//        if (!us[i]) {
//            us[i]=1;
//            dfs(w+1,i,an+f[pre][i]);
//            us[i]=0;
//        }
//    }
//}
//int main() {
//    scanf("%d%d",&n,&m);
//    for (int i=1; i<=n; i++)
//        for (int j=1; j<=m; j++)
//            scanf("%d",&h[i][j]);
//    scanf("%d",&p);
//    for (int i=1; i<=p; i++)
//        scanf("%d%d",&x[i],&y[i]);
//    x[0]=y[0]=1;
//    for (int i=0; i<=p; i++) {
//        Dj(x[i],y[i]);
//        for (int j=0; j<=p; j++)
//            f[i][j]=d[x[j]][y[j]];
//    }
//    ans=inf;
//    dfs(1,0,0);
//    printf("%d",ans);
//}
//
//字符统计
//#include<bits/stdc++.h>
//using namespace std;
//string s;
//int maxn=0;
//int ans[1001000];
//int main() {
//    getline(cin,s);
//    int len=s.size();
//    for(int i=0;i<len;i++) if(s[i]!=' ') ans[s[i]-'a']++;
//    for(int i=0;i<26;i++) maxn=max(maxn,ans[i]);
//    for(int i=0;i<26;i++) if(maxn==ans[i]) cout<<char(i+'a');
//    return 0;
//}
//
//
//填数游戏
//#include<bits/stdc++.h>
//using namespace std;
//long long n,m;
//long long a[1000001];
//long long b[1000001];
//long long sum=0;
//int main() {
//    cin>>n>>m;
//    for(long long i=1; i<=n; i++) cin>>a[i];
//    for(long long i=1; i<=m; i++) cin>>b[i];
//    sort(a+1,a+n+1);
//    sort(b+1,b+m+1);
//    int j=1;
//    while(n!=0) {
//        if(a[n]>=0) {
//            sum+=a[n]*b[m];
//            n--,m--;
//        } else {
//            for(int i=1; i<=n; i++) {
//                sum+=a[i]*b[j];
//                j++;
//            }
//            break;
//        }
//    }
//    cout<<sum;
//    return 0;
//}
//
//夹道之樱
//#include<bits/stdc++.h>
//using namespace std;
//long long n,m;
//struct aa {
//    long long aa,b,c;
//} a[1000001];
//int fa[100001];
//bool cmp(aa a,aa b) {
//    return a.c>b.c;
//}
//int find(int x) {
//    return fa[x]==x?x:fa[x]=find(fa[x]);
//}
//void fk() {
//    for(int i=1; i<=n; i++) fa[i]=i;
//}
//int main() {
//    long long ans=1e9;
//    cin>>n>>m;
//    for(long long i=1; i<=m; i++) cin>>a[i].aa>>a[i].b>>a[i].c;
//    sort(a+1,a+m+1,cmp);
//    for(long long i=1; i<=m; i++) {
//        fk();
//        for(long long j=i; j<=m; j++) {
//            if(find(a[j].aa)!=find(a[j].b))
//                fa[find(a[j].aa)]=find(a[j].b);
//            if(fa[find(1)]==fa[find(n)])
//                ans=min(ans,abs(a[j].c-a[i].c));
//        }
//    }
//    cout<<ans;
//    return 0;
//}
//
//终焉之理
/*
	思路：l表示原先初始下标，t表示排序后目标的下标
	l和t差的绝对值表示第i个数要移到目标位置的单位长度
	而每次排序最多可以移(y-1)个单位长度
	abs(l-t)取最大值再除以(y-1)向上取整即可
	注意：求目标位置时一定要用稳定的排序，不然会使原先下标变乱
*/
//#include<bits/stdc++.h>
//using namespace std;
//struct node {
//    int k,l,t;
//};
//node a[100001];
//bool cmp(node x,node y) {
//    return x.k<y.k;
//}//对原先数值进行排序
//int n,x,o=0;
//double y;
//int main() {
//    cin>>n;
//    for(int i=1; i<=n; i++) {
//        cin>>x>>y;
//        for(int j=1; j<=x; j++) {
//            cin>>a[j].k;
//            a[j].l=j;//记录以前的下标
//        }
//        stable_sort(a+1,a+x+1,cmp);//基于归并的稳定排序，相同数值不改变原有位置
//        for(int j=1; j<=x; j++)
//            a[j].t =j;//记录现在的下标
//        o=0;
//        for(int j=1; j<=x; j++)
//            if(a[j].l-a[j].t>o)
//                o=a[j].l-a[j].t;
//        int t=ceil(o/(y-1));//ceil向上取整，表示最少次数
//        cout<<t<<endl;
//    }
//    return 0;
//}
//
//隐瞒成绩
//#include<bits/stdc++.h>
//using namespace std;
//long long a,b,c,d,p;
//int main() {
//    cin>>a>>b>>c>>d>>p;
//    cout<<((p+d+1)*c-b)/a;
//    return 0;
//}
//
//光亮
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,q,qu,u,v,maxx,a[10000005],c[10000005];
//int main() {
//    scanf("%d%d%d",&n,&m,&q);
//    for (int i=1; i<=m; i++) {
//        scanf("%d%d",&u,&v);
//        c[u]=v;
//    }
//    for (int i=1; i<=n; i++) {
//        if (c[i]!=0) maxx=max(c[i],maxx);
//        a[i]=max(a[i],maxx);
//        maxx--;
//    }
//    maxx=0;
//    for (int i=n; i>=0; i--) {
//        if(c[i]!=0) maxx=max(c[i],maxx);
//        a[i]=max(a[i],maxx);
//        maxx--;
//    }
//    for(int i=1; i<=q; i++) {
//        scanf("%d",&qu);
//        if(a[qu]>0) printf("%d\n",a[qu]);
//        else printf("0\n");
//    }
//    return 0;
//}
//
//
//
//虚实桥梁
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//struct A{
//    int end;
//    int w;
//    int cnt;
//};
//vector<A> q[1000002];
//queue<A> Q;
//int ans=1e8;
//int vis[10000002];
//void bfs(int k){
//    vis[k]=1;
//    for(int i=0;i<q[1].size();i++){
//        if(q[1][i].w==1)
//        Q.push((A){q[1][i].end,q[1][i].w,2});
//        if(q[1][i].w==0)
//        Q.push((A){q[1][i].end,q[1][i].w,1});
//    }
//    int flag=1;
//    while(!Q.empty()){
//        A U=Q.front();
//        Q.pop();
//        if(U.end==n){                                                
//            ans=min(ans,U.cnt);
//        }
//        for(int i=0;i<q[U.end].size();i++){
//            A d=q[U.end][i];
//            if(vis[d.end]) continue;
//            vis[d.end]=1;
//            if(d.w==U.w) Q.push((A){d.end,d.w,U.cnt+1});
//            else Q.push((A){d.end,d.w,U.cnt+2});
//        }
//    }
//    if(ans!=1e8) cout<<ans;
//    else cout<<"no more run";
//    return ;
//}
//int main() {
//    cin>>n>>m;
//    for(int i=1;i<=m;i++){
//        int u,v,w;
//        scanf("%d%d%d",&u,&v,&w);
//        q[u].push_back((A){v,w,0});
//        q[v].push_back((A){u,w,0});
//    }
//    bfs(1);
//    return 0;
//}
//
//国际象棋的挑战
//#include<bits/stdc++.h>
//using namespace std;
//string s1,s2;
//int a,b,cc;
//char c[34]= {0,43,45,45,45,43,45,45,45,43,45,45,45,43,45,45,45,43,45,45,45,43,45,45,45,43,45,45,45,43,45,45,45,43};
//char c1[34]= {0,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124};
//char c2[34]= {0,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124};
//char c3[34]= {0,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124};
//char c4[34]= {0,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124};
//char c5[34]= {0,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124};
//char c6[34]= {0,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124};
//char c7[34]= {0,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124};
//char c8[34]= {0,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124,58,58,58,124,46,46,46,124};
//int main() {
//    getline(cin,s1);
//    int len=s1.size();
//    for(int i=7; i<len; i++) {
//        if(s1[i]>='a'&&s1[i]<='z') {
//            a=s1[i]-'a'+1;
//            b=s1[i+1]-'0';
//            if(s1[i-1]!=',') cc=int(s1[i-1]);
//            if(s1[i-1]==',') cc=80;
//            if(b==1) {
//                c8[4*a-1]=cc;
//            }
//            if(b==2) {
//                c7[4*a-1]=cc;
//            }
//            if(b==3) {
//                c6[4*a-1]=cc;
//            }
//            if(b==4) {
//                c5[4*a-1]=cc;
//            }
//            if(b==5) {
//                c4[4*a-1]=cc;
//            }
//            if(b==6) {
//                c3[4*a-1]=cc;
//            }
//            if(b==7) {
//                c2[4*a-1]=cc;
//            }
//            if(b==8) {
//                c1[4*a-1]=cc;
//            }
//        }
//    }
//    getline(cin,s2);
//    int lens2=s2.size();
//    for(int i=7; i<lens2; i++) {
//        if(s2[i]>='a'&&s2[i]<='z') {
//            a=s2[i]-'a'+1;
//            b=s2[i+1]-'0';
//            if(s2[i-1]!=',') cc=int(s2[i-1])+32;
//            if(s2[i-1]==',') cc=112;
//            if(b==1) {
//                c8[4*a-1]=cc;
//            }
//            if(b==2) {
//                c7[4*a-1]=cc;
//            }
//            if(b==3) {
//                c6[4*a-1]=cc;
//            }
//            if(b==4) {
//                c5[4*a-1]=cc;
//            }
//            if(b==5) {
//                c4[4*a-1]=cc;
//            }
//            if(b==6) {
//                c3[4*a-1]=cc;
//            }
//            if(b==7) {
//                c2[4*a-1]=cc;
//            }
//            if(b==8) {
//                c1[4*a-1]=cc;
//            }
//        }
//    }
//    for(int i=1; i<=33; i++) cout<<char(c[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c1[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c2[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c3[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c4[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c5[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c6[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c7[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c8[i]);
//    cout<<endl;
//    for(int i=1; i<=33; i++) cout<<char(c[i]);
//    return 0;
//}
//
//
//统计子序列
//#include<bits/stdc++.h>
//using namespace std;
//string s;
//int n,ans=0;
//string t;
//int main() {
//    cin>>s;
//    int lens=s.size();
//    cin>>n;
//    for(int i=1; i<=n; i++) {
//        cin>>t;
//        int lent=t.size();
//        int l=0;
//        bool flag=false;
//        for(int j=0; j<lens; j++) {
//            if(s[j]==t[l]) l++;
//            if(l>=lent) {
//                flag=true;
//                break;
//            }
//        }
//        if(flag==true) ans++;
//        else continue;
//    }
//    cout<<ans;
//    return 0;
//}
//
//
//三角形
//#include<bits/stdc++.h>
//using namespace std;
//long long a,b,c,l,ans;
//long long cnt(long long x,long long y,long long z,long long w) {
//    long long s=y+z+w,t=0;
//    long long ans=0;
//    for(int i=0; i<=w; i++) {
//        t=min(s-i,i+x);
//        if(y+z<=t) ans+=(t-y-z+1)*(t-y-z+2)/2;
//    }
//    return ans;
//}
//int main() {
//    scanf("%lld%lld%lld%lld",&a,&b,&c,&l);
//    ans=(l+1)*(l+2)*(l+3)/6;
//    ans-=cnt(a,b,c,l);
//    ans-=cnt(b,a,c,l);
//    ans-=cnt(c,b,a,l);
//    printf("%lld",ans);
//}
//
//
//选取子序列
//#include<bits/stdc++.h>
//using namespace std;
//int t,n,a[114514],flag,s1[114514],s2[114514],l1,l2;
//inline int read() {
//    int ans=0,f=1;
//    char chr=getchar();
//    while(!isdigit(chr)) {
//        if(chr=='-')
//            f=-1;
//        chr=getchar();
//    }
//    while(isdigit(chr)) {
//        ans=(ans<<1)+(ans<<3)+chr-48;
//        chr=getchar();
//    }
//    return ans*f;
//}
//bool dfs(int stp) {
//    if(stp>n)
//        return 1;
//    if(l1<=(n>>1)&&(l1<l2&&a[stp]==s2[l1]||l1>=l2)) {
//        s1[l1++]=a[stp];
//        if(dfs(stp+1))
//            return 1;
//        --l1;
//    }
//    if(l2<=(n>>1)&&(l1>l2&&a[stp]==s1[l2]||l2>=l1)) {
//        s2[l2++]=a[stp];
//        if(dfs(stp+1))
//            return 1;
//        --l2;
//    }
//    return 0;
//}
//int main() {
//    t=read();
//    while(t--) {
//        n=read();
//        for(int i=1; i<=n; i++) a[i]=read();
//        l1=l2=1;
//        if(dfs(1)) printf("Good job!!\n");
//        else printf("What a pity!\n");
//    }
//    return 0;
//}
//
//
//长途旅行
//#include<bits/stdc++.h>
//using namespace std;
//double ans=0,n,k,i;
//int main() {
//    scanf("%lf%lf",&n,&k);
//    for( i=1;n>k/i;i+=2)
//        ans+=k,n-=k/i;
//        ans+=i*n;
//        printf("%d",int(ceil(ans)));
//    return 0;
//}
//
//
//交换
//#include<bits/stdc++.h>
//using namespace std;
//string s,t;
//int ans=0;
//int main() {
//    cin>>s>>t;
//    int lens=s.size();
//    int lent=t.size();
//    for(int i=0;i<lens;i++){
//        for(int j=0;j<lent;j++){
//            swap(s[i],t[j]);
//            if((s[i]==s[i-1]&&s[i-1]==s[i+1]&&s[i]==s[i+1])&&(t[j]==t[j-1]&&t[j-1]==t[j+1]&&t[j]==t[j+1])) {
////              cout<<s<<" "<<t<<" "<<i<<" "<<j;
//                ans++;
////              cout<<endl;
//                swap(s[i],t[j]);
//            }
//            else swap(s[i],t[j]);
//        }
//    }
////  swap(s[3],t[1]);
////  cout<<s<<" "<<t;
//    cout<<ans;
//    return 0;
//}
//
//
//
//代数式运算
//#include<bits/stdc++.h>
//using namespace std;
//string a;
//inline double suan(int st,int ed,int step) {
//    int k=0,nst=st;
//    double ans=0;
//    bool f=1,ng=0;
//    if(st>ed) return 0;
//    if(step==1) {
//        for(int i=st; i<=ed; i++) {
//            if(a[i]=='(') k++;
//            if(a[i]==')') k--;
//            if(a[i]=='+'&&k==0) {
//                ng=1;
//                if(f==1) ans+=suan(nst,i-1,2);
//                else ans-=suan(nst,i-1,2);
//                nst=i+1;
//                f=1;
//            }
//            if(a[i]=='-'&&k==0) {
//                ng=1;
//                if(f==1) ans+=suan(nst,i-1,2);
//                else ans-=suan(nst,i-1,2);
//                nst=i+1;
//                f=0;
//            }
//        }
//        if(ng==0) step++;
//        else {
//            if(f==1) ans+=suan(nst,ed,2);
//            else ans-=suan(nst,ed,2);
//        }
//    }//加减运算
//    if(step==2) {
//        ans=1;
//        for(int i=st; i<=ed; i++) {
//            if(a[i]=='(') k++;
//            if(a[i]==')') k--;
//            if(a[i]=='*'&&k==0) {
//                ng=1;
//                if(f==1) ans*=suan(nst,i-1,3);
//                else ans/=suan(nst,i-1,3);
//                nst=i+1;
//                f=1;
//            }
//            if(a[i]=='/'&&k==0) {
//                ng=1;
//                if(f==1) ans*=suan(nst,i-1,3);
//                else ans/=suan(nst,i-1,3);
//                nst=i+1;
//                f=0;
//            }
//        }
//        if(ng==0) step++;
//        else {
//            if(f==1) ans*=suan(nst,ed,3);
//            else ans/=suan(nst,ed,3);
//        }
//    }//乘除运算
//    if(step==3) {
//        ans=0;
//        for(int i=st; i<=ed; i++) {
//            if(a[i]=='(') k++;
//            if(a[i]==')') k--;
//            if(a[i]=='^'&&k==0) {
//                ng=1;
//                if(f==1) {
//                    f=0;
//                    ans+=suan(nst,i-1,4);
//                } else ans=pow(ans,suan(nst,i-1,4));
//                nst=i+1;
//            }
//        }
//        if(ng==0) step++;
//        else ans=pow(ans,suan(nst,ed,4));
//    }//乘方运算
//    if(step==4) {
//        if(a[st]=='('&&a[ed]==')') {
//            ng=1;
//            return suan(st+1,ed-1,1);
//        }
//        if(ng==0) step++;
//    }//括号判断
//    if(step==5) {
//        nst=ed+1;
//        for(int i=st; i<=ed; i++) {
//            if(a[i]=='.') {
//                nst=i;
//                f=0;
//                break;
//            }
//        }
//        for(int i=st; i<nst; i++) {
//            ans*=10;
//            ans+=a[i]-'0';
//        }
//        for(int i=nst+1; i<=ed; i++) {
//            ans+=(a[i]-'0')/pow(10,i-nst);
//        }
//    }
//    return ans;
//}
//int main() {
//    cin>>a;
//    printf("%.2lf",suan(0,a.length()-1,1));
//    return 0;
//}
//
//楼梯
//#include<bits/stdc++.h>
//using namespace std;
//int n,a[55],dp[55];
//int main() {
//    cin>>n;
//    memset(dp,0x3f,sizeof(dp));
//    for(int i=1; i<=n; i++) {
//        cin>>a[i];
//    }
//    if(a[2]-a[1]>1) {
//        cout<<-1;
//        return 0;
//    }
//    dp[1]=0;
//    for(int i=2; i<=n; i++) {
//        if(a[i]-a[i-1]==1) dp[i]=min(dp[i],dp[i-1]+1);
//        for(int j=i-1; j>=1; j--) {
//            for(int l=i+1; l<=n; l++) {
//                if(a[l]-a[j]<=pow(2,i-j)) dp[l]=min(dp[l],dp[i]+i-j+1);
//            }
//        }
//    }
//    if(dp[n]!=1061109567)
//        cout<<dp[n];
//    else cout<<-1;
//    return 0;
//}
//
//
//好数
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//ll F[125][2][2];//F[i][j][k]表示有i位，第i位是j，第i+1位是k
//ll Ans,Sum,len,k,n,m;
//string sm;
//ll Change(ll t) {
//    if(t<=0)return 0;
//    Ans=0,k=t,len=0;
//    sm="";
//    while(k) { //求t的二进制
//        char s=k%2+48;
//        sm=s+sm,k/=2;
//    }
//    //cout<<"sm="<<sm<<endl;
//    len=sm.length();
//    for(int i=2; i<len; ++i) //求t的二进制长度-1位的坏数
//        Ans+=F[i][1][0]+F[i][1][1];  //从全0到全1的坏数总数
//    if(t>0)Ans++;//0也是坏数
//    //cout<<"Ans="<<Ans<<endl;
//    k=0;//求t的二进制长度位的坏数
//    while(++k<=len)
//        if(sm[k]=='1') {
//            sm[k]='0';
//            int l=1;
//            char r=sm[0];
//            bool B=0;
//            for(int i=1; i<=k; ++i)
//                if(sm[i]==r) {
//                    l++;
//                    if(l==3) {
//                        B=1;
//                        break;
//                    };
//                } else l=1,r=sm[i];
//            if(B==0)
//                Ans+=F[len-k+1][sm[k-1]-48][0];
//            //printf("F[%d][%d][0]=%d\n",len-k+1,sm[k-1]-48,F[len-k+1][sm[k-1]-48][0]);
//            sm[k]='1';//记得变回来
//        }
//    int l=1;
//    char r=sm[1];
//    bool B=0;
//    for(int i=2; i<=len; ++i) //判断m是否为坏数
//        if(sm[i]==r) {
//            l++;
//            if(l==3) {
//                B=1;
//                break;
//            };
//        } else l=1,r=sm[i];
//    if(!B)Ans++;
//    return t-Ans;
//}
//int main() {
//    scanf("%d%d",&n,&m);
//    F[2][1][0]=F[2][1][1]=F[2][0][0]=F[2][0][1]=1;//初值
//    for(int i=3; i<=31; ++i) {
//        F[i][0][0]=F[i-1][0][1];
//        F[i][1][0]=F[i-1][0][0]+F[i-1][0][1];
//        F[i][1][1]=F[i-1][1][0];
//        F[i][0][1]=F[i-1][1][1]+F[i-1][1][0];
//    }
//    Sum=Change(m)-Change(n-1);//前缀和
//    printf("%d",Sum);
//    return 0;
//}
///*
//0 22
//sm=10110
//Ans=11   表示0~10000的坏数个数
//那么还有10000~10110这一段的坏数没算
//如何计算呢？可以以1为标识，逐段计算（问题规模更小的子问题） ，代码中把1变0思想
//例如10000~10100，然后是10100~10110
//将第一个1变0（除去最高位）
//计算10000~10011之间的坏数个数  若101前k位没有好数，等价于00XX，F[4][0][0]=2
//将第二个1变0（除去最高位）
//计算10100~10101之间的坏数个数  若1011前k位没有好数，等价于10X，F[3][1][0]=2
//最后单算10110是否为坏数，+1
//F数组第三位一定是0，因为sm[k]被置为0
//0~22坏数的个数为11+2+2+1=16
//好数为22-16=6
//*/
//
//
//不定方程
//#include<bits/stdc++.h>
//using namespace std;
//long long c,xx,yy,x,y;
//int main(){
//    cin>>c;
//    cin>>x>>y;
//    cin>>xx>>yy;
//    if(x*yy-xx*y==0||y*xx-x*yy==0) {
//        cout<<"No Solution";
//        return 0;
//    }
//    long long a=c*(yy-y)/(x*yy-xx*y);
//    long long b=(c*xx-c*x)/(y*xx-x*yy);
//    if(a>0&&b>0) cout<<a<<" "<<b;
//    else cout<<"No Solution";
//    return 0;
//}
//
//临冬城外
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,l,v[305];
//double dp[305][305];
//bool cmp1(int a,int b) {
//    return a>b;
//}
//int main() {
//    cin>>n>>m>>l;
//    for(int i=1; i<=n; i++) cin>>v[i];
//    sort(v+1,v+n+1,cmp1);
//    for(int i=1; i<=n; i++)
//        for(int j=1; j<=n; j++)
//            dp[i][j]=1e12;
//    for(int i=1; i<=n; i++) dp[1][i]=(l*1.00/v[i])*i;
//    for(int k=1; k<=n; k++)
//        for(int i=2; i<=min(k,m); i++)
//            for(int j=i-1; j<k; j++)
//                dp[i][k]=min(dp[i][k],dp[i-1][j]+(l*1.00/v[k])*(double)(k-j));
//    printf("%.2lf",dp[m][n]);
//    return 0;
//}
//
//
//
//
//资源分配
//#include <bits/stdc++.h>
//const int maxn=1000+5;
//int sol[maxn]; //目前的方案
//int num[maxn]; //整数n
//char S[maxn];
//int m,k,i,j,len,siz,left,st,ed,mx;
//bool fail=false,zero;
//void print_ans() {
//    zero=true;
//    for(i=1;i<=m;i++) {
//        if(zero && num[sol[i]]!=0) zero=false;
//        if(!zero) printf("%d",num[sol[i]]);
//    }
//    printf("\n");
//}
//void getMax() {//最大值，不下降子序列的最后m位
//    siz=0;
//    left=len-m;//可能的最大取值的左位置
//    for(int i=0;i<len;i++)
//        num[i]=S[i]-'0';
//    for(int i=0;i<len;i++) {
//        //sol[] //最大取数中保留的原数下标
//        while(siz>0 && num[sol[siz]]<num[i] && left>0) {
//            //
//            siz--;
//            left--;
//        }
//        sol[++siz]=i;
//    }
//}
//void upd() {
//    if(i==1) st=0;
//    else st=sol[i-1]+1;
//    ed=len-1-m+i;
//    mx=len+1;
//}
//bool getNext() {
//    //print_ans();
//    num[len+1]=-1;
//    for(i=m;i>=1;i--) {//从最后一位开始找可以替换的数
//        upd();
//        for(j=st;j<=ed;j++) if(j!=sol[i] && num[sol[i]]>num[j] && num[j]>num[mx]) mx=j;
//        if(mx!=len+1) {
//            sol[i]=mx;
//            break;
//        }
//    }
//    if(i==0) return false;
//    if(i<m) for(i=i+1;i<=m;i++) {
//        upd();
//        for(j=st;j<=ed;j++)
//            if(num[j]>num[mx]) mx=j;
//        if(mx!=len+1) sol[i]=mx;
//    }
//    return true;
//}
//int main() {
//    scanf("%s",S);
//    len=strlen(S);
//    scanf("%d%d",&m,&k);
//    getMax();
//    while(--k)
//        if(!getNext()) {
//            fail=true;
//            break;
//        }
//    if(!fail) print_ans();
//    else printf("0\n");
//    return 0;
//}
//
//
//
//长城之北
//#include <bits/stdc++.h>
//using namespace std;
//int n, m, q, x[5000006], y[5000006], v[5000006], f[5000006], s[5000006];
//bool p[5000006];
//int find(int x) {
//    return f[x]==x?x:f[x]=find(f[x]);
//}
//inline void merge(int x, int y) {
//    x = find(x);
//    y = find(y);
//    if (x != y) {
//        --n;
//        if (s[x] < s[y]) f[x] = y, s[y] += s[x];
//        else f[y] = x, s[x] += s[y];
//    }
//}
//inline void read(int& x) {
//    char c(getchar());
//    while (c < 48 || c > 57) c = getchar();
//    while (c > 47 && c < 58) x = (x << 3) + (x << 1) + c - 48, c = getchar();
//}
//int main() {
//    read(n);
//    read(m);
//    read(q);
//    for (int i(1); i <= n; ++i) f[i] = i, s[i] = 1;
//    for (int i(1); i <= m; ++i) read(x[i]), read(y[i]);
//    for (int i(1); i <= q; ++i) read(v[i]), p[v[i]] = true;
//    for (int i(1); i <= m; ++i) if (!p[i]) merge(x[i], y[i]);
//    for (int i(q); i; --i) {
//        int g(n);
//        merge(x[v[i]], y[v[i]]);
//        v[i] = g;
//    }
//    for (int i(1); i <= q; ++i) printf("%d\n", v[i]);
//    return 0;
//}
//
//小Biu的礼物
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,k,ans=0,v[100001];
//int main() {
//    scanf("%d%d%d",&n,&m,&k);
//    for(int i=1; i<=n; i++) scanf("%d",&v[i]);
//    int j=n;
//    for(int q=1; q<=m; q++) {
//        int sum=0;
//        for(int i=j; i>=1; i--) {
//            if(v[i]>k) break;
//            sum+=v[i];
//            if(sum>k){
//                j=i;
//                ans++;
//                break;
//            }
//            if(sum==k){
//                ans+=j-i+1;
//                j=i;
//                break;
//            }
//        }
//    }
//    printf("%d",n-ans);
//    return 0;
//}
//
//
//小Biu的区间和
//#include<bits/stdc++.h>
//using namespace std;
//int n,a[2000],w,k,t,p,ans,lyx;
//int main() {
//    scanf("%d",&n);
//    for(int i=1; i<=n; i++) {
//        scanf("%d",&a[i]);
//        w+=a[i];
//    }
//    for(int i=1; i<=w; i++) {
//        t=0,p=0,ans=0;
//        for(int j=1; j<=n; j++) {
//            t=j,p=0;
//            while(t<=n&&p<i) {
//                p+=a[t];
//                t++;
//            }
//            if(p==i) {
//                ans++;
//                j=t-1;
//            }
//        }
//        lyx=max(lyx,ans);
//    }
//    printf("%d",lyx);
//}
//
//
//小Biu的骰子
//#include <bits/stdc++.h>
//using namespace std;
//int n;
//double x[100002];
//double p[100002];
//double dfs(int k){
//    if(p[k]) return p[k];
//    if(k==n) return p[k]=x[k];
//    double cnt=0;
//    cnt+=x[k];
//    for(int i=1;i<=min(6,n-k);i++) cnt+=dfs(k+i)/(double)min(6,n-k);
//    return p[k]=cnt;
//}
//int main(){
//    cin>>n;
//    for(int i=1;i<=n;i++) scanf("%lf",&x[i]);
//    printf("%.7lf",dfs(1));
//    return 0;
//}
//
//
//小Biu的树
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int maxn = 1e6 + 10;
//const ll INF = ll(1e18);
//int n;
//ll a[maxn];
//vector<int> e[maxn];
//ll ans =-INF;
//ll dp[maxn];
//ll sum[maxn];
//void dfs(int x,int fa) {
//    int siz = e[x].size();
//    sum[x]=a[x];
//    for(int i=0;i<=siz-1;i++) {
//        int y = e[x][i];
//        if(y==fa) continue;
//        dfs(y,x);
//        sum[x]+=sum[y];
//        if(dp[x]>-INF) ans=max(ans,dp[x]+dp[y]);
//        dp[x]=max(dp[x],dp[y]);
//    }
//    dp[x]=max(dp[x],sum[x]);
//}
//int main(){
//    cin>>n;
//    for(int i=1;i<=n;i++) cin>>a[i];
//    for(int i=1;i<=n-1;i++){
//        int x,y;
//        cin>>x>>y;
//        e[x].push_back(y);
//        e[y].push_back(x);
//    }
//    for(int i=1;i<=n;i++) dp[i]=-INF;
//    dfs(1,-1);
//    //if(ans==INF) puts("Impossible");
//     printf("%lld\n",ans);
//    return 0;
//}
//
//flowers
//#include<bits/stdc++.h>
//using namespace std;
//long long n,k,b[10000001];
//long long f(long long l,long long r){
//	long long p=ceil((l+r)/2);
//	long long c=b[p];
//	long long e=0;
//	for(int i=l;i<=r;i++) e+=(b[i]-b[p])*(b[i]-b[p]);
//	return e;
//}
//signed main(){
//	scanf("%lld%lld",&n,&k);
//	for(register long long i=1;i<=n;i++) scanf("%lld",&b[i]);
//	sort(b+1,b+n+1);
//	long long ans=1e18;
//	for(register long long i=0;i<=n-k;i++) ans=min(ans,f(1+i,k+i));
//	printf("%lld",ans);
//	return 0;
//}
//
//
//P8443 gcd
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main(){
//	int p;
//	cin>>p;
//	for(int i=1;i<=p;i++){
//		int l,r,x;
//		scanf("%lld%lld%lld",&l,&r,&x);
//		l/=x;
//		r/=x;
//		if(l==r) cout<<l<<endl;
//		else cout<<1<<endl;
//	}
//	return 0;
//}
//
//
//P1014 [NOIP1999 普及组] Cantor 表
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int main() {
//	cin>>n;
//	int p=1;
//	while(n>p) {
//		n-=p;
//		p++;
//	}
//	if(p%2==0) cout<<n<<"/"<<(p-n+1);
//	else cout<<(p-n+1)<<"/"<<n;
//	return 0;
//}
//
//
//CF1742A Sum
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int p;
//signed main(){
//	scanf("%lld",&p);
//	while(p--){
//		int a,b,c;
//		scanf("%lld%lld%lld",&a,&b,&c);
//		if(a+b==c||a+c==b||b+c==a) printf("Yes\n");
//		else printf("No\n");
//	}
//	return 0;
//}
//
//
//CF1742B Increasing
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int t,a[1000001],n;
//signed main(){
//	cin>>t;
//	for(int p=1;p<=t;p++){
//		bool flag=false;
//		scanf("%lld",&n);
//		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//		sort(a+1,a+n+1);
//		for(int i=0;i<=n-1;i++) {
//			if(a[i]>=a[i+1]) {
//				flag=true;
//				printf("NO\n");
//				break;
//			} 
//		}
//		if(flag==false) printf("YES\n");
//	}
//	return 0;
//}
//
//
//CF1742C Stripes
//#include<bits/stdc++.h>
//using namespace std;
//int t,h[10001],s[10001];
//char a;
//signed main(){
//	scanf("%d",&t);
//	while(t--){
//		memset(h,0,sizeof(h));
//		memset(s,0,sizeof(s));
//		for(int i=1;i<=8;i++)
//			for(int j=1;j<=8;j++){
//				cin>>a;
//				if(a=='R') h[i]++;
//				else s[j]++;
//			}
//		for(int i=1;i<=8;i++) {
//			if(h[i]==8) {
//				printf("R\n");
//				break;
//			}
//			if(s[i]==8) {
//				printf("B\n");
//				break;
//			}
//		}
//	}
//	return 0;
//}
//
//
//CF1742D Coprime
//#include<bits/stdc++.h>
//using namespace std;
//int t,n,a[1000001];
//signed main(){
//	scanf("%d",&t);
//	while(t--){
//		memset(a,0,sizeof(a));
//		int ans=0;
//		scanf("%d",&n);
//		for(int i=1;i<=n;i++) {
//			int x;
//			cin>>x;
//			a[x]=i;
//		}
//		for(int i=1;i<=1000;i++)
//			for(int j=i;j<=1000;j++)
//				if(__gcd(i,j)==1&&a[i]&&a[j]) ans=max(ans,a[i]+a[j]);
//		if(ans==0) printf("-1\n");
//		else printf("%d\n",ans);
//	}
//	return 0;
//}
//
//
//
//
//P1120 小木棍
//#include<bits/stdc++.h>
//using namespace std;
//inline int read() {
//	int x=0;
//	bool f=1;
//	char c=getchar();
//	for(; !isdigit(c); c=getchar()) if(c=='-') f=0;
//	for(; isdigit(c); c=getchar()) x=(x<<3)+(x<<1)+c-'0';
//	if(f) return x;
//	return 0-x;
//}
//int n,m,a[66],nxt[66],cnt,sum,len;
//bool used[66],ok;
//bool cmp(int a,int b) {
//	return a>b;
//}
//void dfs(int k,int last,int rest) {
//	int i;
//	if(!rest) { 
//		if(k==m) {
//			ok=1;    
//			return;
//		}
//		for(i=1; i<=cnt; i++) 
//			if(!used[i]) break;
//		used[i]=1;
//		dfs(k+1,i,len-a[i]);
//		used[i]=0;
//		if(ok) return; 
//	}
//	int l=last+1, r=cnt, mid;
//	while(l<r) {
//		mid=(l+r)>>1;
//		if(a[mid]<=rest) r=mid;
//		else l=mid+1;
//	}
//	for(i=l; i<=cnt; i++) {
//		if(!used[i]) {
//			used[i]=1;
//			dfs(k,i,rest-a[i]);
//			used[i]=0;
//			if(ok) return;
//			if(rest==a[i] || rest==len) return;
//			i=nxt[i];
//			if(i==cnt) return;
//		}
//	}
//}
//int main() {
//	n=read();
//	int d;
//	for(int i=1; i<=n; i++) {
//		d=read();
//		if(d>50) continue;
//		a[++cnt]=d;
//		sum+=d;
//	}
//	sort(a+1,a+cnt+1,cmp);
//	nxt[cnt]=cnt;
//	for(int i=cnt-1; i>0; i--) {
//		if(a[i]==a[i+1]) nxt[i]=nxt[i+1];
//		else nxt[i]=i;
//	}
//	for(len=a[1]; len<=sum/2; len++) {
//		if(sum%len!=0) continue; 
//		m=sum/len;
//		ok=0;
//		used[1]=1;
//		dfs(1,1,len-a[1]);
//		used[1]=0;
//		if(ok) {
//			printf("%d\n",len);
//			return 0;
//		}
//	}
//	printf("%d\n",sum);
//	return 0;
//}
//
//
//P2676 [USACO07DEC]Bookshelf B
//#include<bits/stdc++.h>
//using namespace std;
//int n,b;
//int a[100001];
//bool cmp(int x,int y){
//	return x>y;
//}
//int main(){
//	cin>>n>>b;
//	for(int i=1;i<=n;i++) cin>>a[i];
//	sort(a+1,a+n+1,cmp);
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		ans+=a[i];
//		if(ans>b) {
//			cout<<i;
//			return 0;
//		}
//		if(ans==b){
//			cout<<i;
//			return 0;
//		}
//	}
//	return 0;
//}
//
//
//
//
// CF1742E Scuza
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int t;
//int n,q,a[10000001],k;
//int p[10000001];
//int sum[10000001];
//signed main(){
//	scanf("%lld",&t);
//	while(t--){
//		memset(p,0,sizeof(p));
//		memset(sum,0,sizeof(sum));
//		scanf("%lld%lld",&n,&q);
//		for(int i=1;i<=n;i++) {
//			scanf("%lld",&a[i]);
//			p[i]=max(p[i-1],a[i]);
//			sum[i]=sum[i-1]+a[i];
//		}
//		for(int i=1;i<=q;i++){
//			scanf("%lld",&k);
//			int l=0,r=n;
//			while(l<r){
//				int mid=(l+r+1)/2;
//				if(p[mid]<=k) l=mid;
//				else r=mid-1; 
//			}
//			printf("%lld ",sum[l]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//
//
//CF1742F Smaller
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int t;
//signed main(){
//	scanf("%lld",&t);
//	while(t--){
//		int f=0,f1=0;
//		int s1=0,s2=0;
//		int q,d,k;
//		string x;
//		scanf("%lld",&q);
//		for(int i=1;i<=q;i++){
//			cin>>d>>k;
//			cin>>x;
//			for(int j=0;j<x.size();j++){
//				if(x[j]!='a'){
//					if(d==2) f=1;
//					else f1+=k;
//				} else{
//					if(d==1) s1+=k;
//					else s2+=k;
//				}
//			}
//			if(f||s1<s2&&!f1) cout<<"YES"<<endl;
//			else cout<<"NO"<<endl;
//		}
//	}
//	return 0;
//}
//
//
//P5594 【XR-4】模拟赛
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//bool p[1001][1001];
//int n,m,k;
//signed main(){
//	scanf("%lld%lld%lld",&n,&m,&k);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			int x;
//			cin>>x;
//			p[x][j]=true;
//		}
//	}
//	for(int i=1;i<=k;i++){
//		int ans=0;
//		for(int j=1;j<=m;j++) if(p[i][j]==true) ans++;
//		cout<<ans<<" ";
//	}
//	return 0;
//}
//
//P1141 01迷宫
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,ans[100002],x,y,f[1002][1002];
//char s[1002][1002];
//void dfs(int r,int c,int z,int lll) {
//    if (r<0 || r>=n || c<0 || c>=n || f[r][c]!=-1 || s[r][c]-'0'!=z)return;
//    f[r][c]=lll;
//    ans[lll]++;
//    dfs(r-1,c,!z,lll);
//    dfs(r+1,c,!z,lll);
//    dfs(r,c-1,!z,lll);
//    dfs(r,c+1,!z,lll);
//}
//int main() {
//    cin>>n>>m;
//    for (int i=0; i<n; i++)
//        scanf("%s",s[i]);
//    memset(f,-1,sizeof(f));
//    for (int i=0; i<m; i++) {
//        scanf("%d%d",&x,&y);
//        x--;
//        y--;
//        if (f[x][y]==-1)dfs(x,y,s[x][y]-'0',i);
//        else ans[i]=ans[f[x][y]];
//    }
//    for (int i=0; i<m; i++)
//        printf("%d\n",ans[i]);
//    return 0;
//}
//
//
//
//P1451 求细胞数量
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,tot=0;
//int a[101][101];
//char c[101][101];
//bool b[101][101];
//int dx[4]= {-1,1,0,0};
//int dy[4]= {0,0,-1,1};
//void f(int x,int y) {
//    for(int i=0; i<4; i++) {
//        int tx=x+dx[i];
//        int ty=y+dy[i];
//        if(tx>n||ty>m||tx<1||ty<1||a[tx][ty]==0||b[tx][ty]==true) continue;
//        b[tx][ty]=true;
//        f(tx,ty);
//    }
//}
//int main() {
//    cin>>n>>m;
//    memset(b,false,sizeof(b));
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            cin>>c[i][j];
//            a[i][j]=c[i][j]-'0';
//        }
//    }
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            if(a[i][j]!=0&&b[i][j]==false){
//                f(i,j);
//                tot++;
//            }
//        }
//    }
//    cout<<tot;
//    return 0;
//}
//
//
//
//P1332 血色先锋队
//#include<bits/stdc++.h>
//using namespace std;
//const int fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};//四个方向
//void read(int &x){//快读不解释
//     int f=1;x=0;
//     char ch=getchar();
//     while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
//     while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
//     x*=f;
//}
//int n,m,a,b,tot; //tot表示有几个感染源
//int Map[1502][1502];//Map存图，每个点的值表示这个位置在什么时候
//int q[10000002][2];//q为广搜队列
//int v[1502][1502];//v表示该点是否被感染
//void bfs(){//标准广搜
//    int x,y,head=tot,tail=0;//我这里的head和tail好像反了
//    while(tail<head){
//        tail++;
//        x=q[tail][0],y=q[tail][1];
//        v[x][y]=1;
//        for(int i=0;i<4;i++){
//            int x1=x+fx[i][0],y1=y+fx[i][1];
//            if(x1<1||y1<1||x1>n||y1>m) continue;//如果超出边界，跳出
//            if(v[x1][y1]) continue;//如果已经被感染，跳出
//            v[x1][y1]=1;//标记被感染
//            Map[x1][y1]=Map[x][y]+1;//被感染者的感染时间 = 感染者的感染时间 + 1
//            q[++head][0]=x1,q[head][1]=y1;
//        }
//         
//    }
//}
//int main(){
//    cin>>n>>m>>a>>b;//n,m,a,b如题中所示
//    for(int i=1;i<=a;i++){
//        int x,y;
//        read(x),read(y);
//        v[x][y]=1;//标记为已感染
//        q[++tot][0]=x,q[tot][1]=y;//入队
//    }
//    bfs();//广搜处理出每个点在什么时间被感染
//    for(int i=1;i<=b;i++){
//        int x,y;
//        read(x),read(y);
//        printf("%d\n",Map[x][y]);//直接输出这个点在什么时候被感染
//    }
//    return 0;
//}
//
//
//Problem ID: 1372 电子表格
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,s;
//struct node {
//	int a,b,x1,y1,x2,y2;
//	node() {
//		a=1;
//		b=0;
//	}
//} a[101][27];
//char c1[10],c2[10],c3[10],c4[10];
//int turn(char *c) {
//	int l=strlen(c);
//	int t=0;
//	for (int i=1; i<l; i++)
//		t=t*10+c[i]-48;
//	return t;
//}
//int js(int x, int y) {
//	if (a[x][y].a==1) return a[x][y].b;
//	int sum=0;
//	for (int i=a[x][y].x1; i<=a[x][y].x2; i++)
//		for (int j=a[x][y].y1; j<=a[x][y].y2; j++)
//			sum+=js(i,j);
//	if (a[x][y].a==2) return sum;
//	return sum/((a[x][y].x2-a[x][y].x1+1)*(a[x][y].y2-a[x][y].y1+1));
//}
//int main() {
//	scanf("%d%d%d",&m,&n,&s);
//	for (int i=1; i<=s; i++) {
//		scanf("%s%s",c1,c2);
//		int x=turn(c1),y=c1[0]-64;
//		if (c2[0]=='o') {
//			printf("%d\n",js(x,y));
//			continue;
//		}
//		if (c2[0]=='i') {
//			int k;
//			scanf("%d",&k);
//			a[x][y].a=1;
//			a[x][y].b=k;
//			continue;
//		}
//		scanf("%s%s",c3,c4);
//		a[x][y].x1=turn(c3);
//		a[x][y].x2=turn(c4);
//		a[x][y].y1=c3[0]-64;
//		a[x][y].y2=c4[0]-64;
//		if (c2[0]=='s') a[x][y].a=2;
//		else a[x][y].a=3;
//	}
//	return 0;
//}
//
//
//
//
//Problem ID 1304 天天做实验
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int c,g;
//int a[102];
//int z[102];
//int dp[102][10004];
//signed main() {
//	cin>>c>>g;
//	for(int i=1; i<=c; i++) cin>>a[i];
//	for(int i=1; i<=g; i++) cin>>z[i];
//	dp[0][3000]=1;
//	for(int i=1; i<=g; i++)
//		for(int j=1; j<=c; j++)
//			for(int k=-3000; k<=3000; k++)
//				dp[i][3000+k+z[i]*a[j]]+=dp[i-1][3000+k];
//	cout<<dp[g][3000];
//	return 0;
//}
//
//学生信息系统 Problem ID: 1216
//#include<bits/stdc++.h>
//using namespace std;
//struct ren {
//	string xm,dh,em,cs,jd,mph;
//}a[1000001];
//int main() {
//	string tmp;
//	int n,m;
//	cin>>n;
//	for(int i=1;i<=n;i++) cin>>a[i].xm>>a[i].dh>>a[i].em>>a[i].cs>>a[i].jd>>a[i].mph;
//	cin>>m;
//	for(int k=1; k<=m; k++) {
//		cin>>tmp;
//		bool b=true;
//		for(int i=1; i<=n; i++)
//			if(a[i].xm==tmp) {
//				cout<<a[i].xm<<" "<<a[i].dh<<" "<<a[i].em<<" "<<a[i].cs<<" "<<a[i].jd<<" "<<a[i].mph<<endl;
//				b=false;
//				break;
//			}
//		if(b) cout<<"not found"<<endl;;
//	}
//	return 0;
//}
//
//
//Problem ID: 1210 二项式展开
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//int n,p,q;
//int a[32][10002];
//signed main() {
//	cin>>n;
//	if(n==0) {
//		cout<<"(a+b)^0 = 1";
//		return 0;
//	} else if(n==1) {
//		cout<<"(a+b)^1 = a + b";
//		return 0;
//	}
//	a[1][1]=1;
//	for(int i=2; i<=n+1; i++) {
//		for(int j=2; j<=i-1; j++) {
//			a[i][j]=a[i-1][j-1]+a[i-1][j];
//		}
//		a[i][1]=a[i][i]=1;
//	}
//	p=n;
//	cout<<"(a+b)^"<<n<<" = ";
//	for(int i=1; i<=n+1; i++) {
//		if(a[n+1][i]!=0&&a[n+1][i]!=1) cout<<a[n+1][i]<<"*";
//		if(p!=1&&p!=0) {
//			cout<<"a^"<<p;
//			if(i!=1) cout<<"*";
//		} else if(p==1) cout<<"a*";
//		if(q!=1&&q!=0) cout<<"b^"<<q;
//		else if(q==1) cout<<"b";
//		if(i!=n+1)cout<<" + ";
//		p--,q++;
//	}
//	return 0;
//}
//
//
//Problem ID: 1324 阶乘和
//#include<bits/stdc++.h>
//using namespace std;
//int a[2000],b[2000],c[2000],sum[2000];
//void pplus(int *a,int *c) {
//	int jw=0;
//	for(int i=1; i<=1000; i++) {
//		c[i]+=a[i]+jw;
//		jw=c[i]/10;
//		c[i]%=10;
//	}
//}
//void cheng(int *a,int c) {
//	int jw=0;
//	for(int i=1; i<=1000; i++) {
//		a[i]=a[i]*c+jw;
//		jw=a[i]/10;
//		a[i]%=10;
//	}
//}
//int main() {
//	int n;
//	cin>>n;
//	a[1]=1;
//	for(int i=1; i<=n; i++) {
//		cheng(a,i);
//		pplus(a,c);
//	}
//	bool flag=0;
//	for(int i=1000; i>=1; i--) {
//		if(c[i]!=0) flag=1;
//		if(flag) cout<<c[i];
//	}
//	return 0;
//}
//
//
//
//
//
//
//[ABC023A] 加算王
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int main() {
//    cin>>n;
//    cout<<n/10%10+n%10<<endl;
//    return 0;
//}
//
//
//[ABC023B] 手芸王
//#include<bits/stdc++.h>
//using namespace std;
//string b="b",a;
//int n;
//int main() {
//    cin>>n>>a;
//    if(a=="b"&&n==1){
//    	cout<<0<<endl;
//    	return 0;
//	}
//	for(int i=1;i<=n;i++){
//		int p=i%3;
//		if(p==0) b='b'+b+'b';
//		if(p==1) b='a'+b+'c';
//		if(p==2) b='c'+b+'a';
//		if(b==a){
//			cout<<i<<endl;
//			return 0;
//		}
//	}
//	cout<<-1<<endl;
//    return 0;
//}
//
//
//
//
//AT_abc023_d	[ABC023D] 射撃王
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct p{
//	int h,s;
//}a[100001];
//int tim[1000001];
//int n;
//bool check(int mid){
//	for(int i=1;i<=n;i++) {
//		if(mid<a[i].h) return false;
//		tim[i-1]=(mid-a[i].h)/a[i].s;
//	}
//	sort(tim,tim+n);
//	for(int i=0;i<n;i++) if(tim[i]<i) return false;
//	return true;
//}
//signed main() {
//    scanf("%lld",&n);
//    for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].h,&a[i].s);
//    int ans=0,l=1,r=1e18;
//    while(l<r){
//    	int mid=(l+r)/2;
//    	if(check(mid)){
//    		r=mid;
//    		ans=mid;
//		}
//		else l=mid+1;
//	}
//	cout<<ans<<endl;
//    return 0;
//}
//
//
//
//AT_dp_a	Frog 1
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,a[10000001];
//int dp[10000001];
//int cost(int i,int j){
//	return abs(a[i]-a[j]);
//}
//signed main() {
//    scanf("%lld",&n);
//    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//    dp[2]=abs(a[1]-a[2]);
//    for(int i=3;i<=n;i++) dp[i]=min(dp[i-1]+cost(i,i-1),dp[i-2]+cost(i,i-2));
//    cout<<dp[n]<<endl;
//    return 0;
//}
//
//
//
//
//AT_dp_b	Frog 2
//#include<bits/stdc++.h>
//using namespace std;
//int n,k,a[100000001];
//int dp[100001];
//int main(){
//	memset(dp,0x3f3f3f,sizeof(dp));
//	scanf("%d%d",&n,&k);
//	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//	dp[1]=0;
//	for(int i=1;i<=n-1;i++)
//		for(int j=1;j<=k;j++)
//			dp[i+j]=min(dp[i+j],dp[i]+abs(a[i]-a[j+i]));
//	cout<<dp[n];
//	return 0;
//}
//
//
//
//Problem ID: 1328 单词游戏机
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//struct p{
//	int g;
//}zm[10000001];
//bool bj[1000001];
//int main(){
//	memset(bj,false,sizeof(bj));
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=26;i++) scanf("%d",&zm[i].g);
//	for(int i=1;i<=n;i++){
//		char c;
//		cin>>c;
//		bj[c-'A'+1]=true;
//	}
//	int ans=-1e9;
//	while(m--){
//		int sum=0;
//		string a;
//		cin>>a;
//		for(int i=0;i<a.size();i++) if(zm[a[i]-'A'+1].g!=0&&bj[a[i]-'A'+1]==true) sum+=zm[a[i]-'A'+1].g;
//		ans=max(sum,ans);
//	}
//	if(ans==0) cout<<-1;
//	else printf("%d",ans);
//	return 0;
//}
//
//
//
//
//Problem ID: 1245 做蛋糕
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a[10000001],b[10000001],ans=0,p=1e9,n,k,r[1000001];
//signed main(){
//	scanf("%lld%lld",&n,&k);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
//	for(int i=1;i<=n;i++) {
//		p=min(b[i]/a[i],p);
//		ans=max(b[i]/a[i],ans);
//	}
//	if(p==ans){
//		cout<<p;
//		return 0;
//	}
//	for(int i=1;i<=ans;i++) r[i]=k;
//	int q=1;
//	for(int i=ans;i>=p;i--){
//		for(int j=1;j<=n;j++){
//			int c=i*a[j]-b[j];
//			r[q]-=c;
//		}
//		if(r[q]>=0) {
//			printf("%d",i);
//			return 0;
//		}
//		q++;
//	}
//	return 0;
//}
//
//
//
//
//P2249 【深基13.例1】查找
//#include<bits/stdc++.h>
//using namespace std;
//long long n,m;
//long long a[1000001];
//long long solve(long long p){
//	long long l=1,r=n;
//	while(l<r){
//		long long mid=(l+r)/2;
//		if(p>a[mid]) l=mid+1;
//		else r=mid;
//	}
//	if(a[l]==p) return l;
//	else return -1;
//}
//int main(){
//	cin>>n>>m;
//	for(long long i=1;i<=n;i++) cin>>a[i];
//	while(m--){
//		long long p;
//		scanf("%lld",&p);
//		long long ans=solve(p);
//		cout<<ans<<" ";
//	}
//	return 0;
//}
//
//
//
//
//
//P3366 【模板】最小生成树
//#include<bits/stdc++.h>
//#define INF 0x7f7ff
//using namespace std;
//int n,m,dist[5010],head[5010],k,ans;
//bool vis[5010];
//struct node {
//	int to,next,w;
//} edge[400010];
//void add(int u,int v,int w) {
//	edge[++k].to=v;
//	edge[k].w=w;
//	edge[k].next=head[u];
//	head[u]=k;
//}
//void Prime() {
//	fill(dist+1,dist+n+1,INF);
//	dist[1]=0;
//	for(int j=1; j<=n; j++) {
//		int u=-1,ans=INF;
//		for(int i=1; i<=n; i++) 
//			if(dist[i]<ans&&!vis[i]) {
//				u=i;
//				ans=dist[i];
//			}
//		if(u==-1) {
//			ans=-1;
//			return;
//		}
//		vis[u]=1;
//		ans+=dist[u];
//		for(int i=head[u]; i; i=edge[i].next) {
//			int v=edge[i].to;
//			if(!vis[v]&&dist[v]>edge[i].w) dist[v]=edge[i].w;
//		}
//	}
//}
//int main() {
//	cin>>n>>m;
//	for(int i=1; i<=m; i++) {
//		int a,b,c;
//		cin>>a>>b>>c;
//		add(a,b,c);
//		add(b,a,c);
//	}
//	Prime();
//	if(ans==-1) cout<<"orz"<<endl;
//	else cout<<ans;
//}
//
//
//P1396 营救
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,s,t,a[20001];
//struct each {
//	int x,y,cost;
//} b[20001]; 
//bool com(each x,each y) {
//	return x.cost<y.cost;
//}
//int read() { 
//	char ch=getchar();
//	int x=0,f=1;
//	while(ch<'0'||ch>'9') {
//		if(ch=='-')
//			f=-1;
//		ch=getchar();
//	}
//	while(ch>='0'&&ch<='9') {
//		x=x*10+ch-'0';
//		ch=getchar();
//	}
//	return x*f;
//}
//int find(int x) {
//	if(a[x]==0) return x;
//	a[x]=find(a[x]);
//	return a[x];
//}
//int main() {
//	n=read();
//	m=read();
//	s=read();
//	t=read();
//	for(int i=1; i<=m; i++) { 
//		b[i].x=read();
//		b[i].y=read();
//		b[i].cost=read();
//	}
//	sort(b+1,b+m+1,com);
//	for(int i=1; i<=m; i++) {
//		int X=find(b[i].x),Y=find(b[i].y);
//		if(X!=Y)
//			a[X]=Y;
//		if(find(s)==find(t)) {
//			cout<<b[i].cost<<endl;
//			return 0;
//		}
//	}
//	return 0;
//}
//
//
//
//八连通
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,tot=0;
//char a[1001][1001];
//int dx[8]={0,0,1,-1,1,1,-1,-1};
//int dy[8]={1,-1,0,0,1,-1,1,-1};
//void dfs(int x,int y){
//	a[x][y]='.';
//	for(int i=0;i<8;i++){
//		int tx=x+dx[i];
//		int ty=y+dy[i];
//		if(tx<=0||ty<=0||tx>n||ty>m||a[tx][ty]=='.') continue;
//		tot++;
//		dfs(tx,ty);
//		a[tx][ty]='.';
//	}
//}
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cin>>a[i][j];
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			tot=0;
//			dfs(i,j);
//			if(tot!=0) ans++;
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//N皇后
//#include<bits/stdc++.h>
//using namespace std;
//int n,cnt=0;
//bool pc[1001],r[1001],c[1001];
//void dfs(int p) {
//	if(p==n+1) {
//		cnt++;
//		return ;
//	}
//	for(int i=1; i<=n; i++) {
//		if(pc[i]==false&&r[p-i+n]==false&&c[p+i]==false) {
//			pc[i]=true;
//			r[p-i+n]=true;
//			c[p+i]=true;
//			dfs(p+1);
//			pc[i]=false;
//			r[p-i+n]=false;
//			c[p+i]=false;
//		}
//	}
//}
//int main() {
//	memset(pc,false,sizeof(pc));
//	memset(c,false,sizeof(c));
//	memset(r,false,sizeof(r));
//	scanf("%d",&n);
//	dfs(1);
//	cout<<cnt;
//	return 0;
//}
//
//
//
//
//XJ的运动会
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,p[1001][1001],ans=0,c[1001];
//void dfs(int x,int y) {
//	if(x>n) {
//		ans=max(ans,y);
//		return ;
//	}
//	for(int i=1; i<=m; i++) {
//		if(c[i]>=2) continue;
//		dfs(x+1,y);
//		c[i]++;
//		dfs(x+1,y+p[x][i]);
//		c[i]--;
//		for(int j=i+1; j<=m; j++) {
//			if(c[j]>=2) continue;
//			c[i]++;
//			c[j]++;
//			dfs(x+1,y+p[x][i]+p[x][j]);
//			c[i]--;
//			c[j]--;
//		}
//	}
//}
//int main() {
//	scanf("%d%d",&n,&m);
//	for(int i=1; i<=n; i++)
//		for(int j=1; j<=m; j++)
//			scanf("%d",&p[i][j]);
//	dfs(1,0);
//	cout<<ans;
//	return 0;
//}
//
//
//
//升降问题
//#include<bits/stdc++.h>
//using namespace std;
//int p[10001],cr[1001],a,b,n;
//bool c[10001],flag=true;
//queue<int> pc;
//void bfs(int x){
//	c[x]=true;
//	cr[x]=0;
//	pc.push(x);
//	while(!pc.empty()){
//		int d=pc.front();
//		int cnt=0,i=1;
//		pc.pop();
//		if(d==b){
//			printf("%d\n",cr[d]);
//			return ;
//		}
//		for(;cnt<=1;cnt++,i*=-1){
//			int tx=d+i*p[d];
//			if(tx<1||tx>n||c[tx]==true) continue;
//			c[tx]=true;
//			cr[tx]=cr[d]+1;
//			pc.push(tx);
//		}
//	}
//	flag=false;
//}
//int main() {
//	while(1){
//		memset(c,false,sizeof(c));
//		scanf("%d",&n);
//		if(n==0) break;
//		scanf("%d%d",&a,&b);
//		for(int i=1;i<=n;i++) scanf("%d",&p[i]);
//		c[a]=true;
//		bfs(a);
//		if(flag==false) cout<<-1<<endl;
//	}
//	return 0;
//}
//
//
//
//
//血色先锋队
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,a,b;
//int dx[4]={0,0,-1,1};
//int dy[4]={1,-1,0,0};
//queue<int> pc;
//bool c[1001][1001];
//int p[1001][1001];
//void bfs(){
//	while(!pc.empty()){
//		int cx=pc.front();
//		pc.pop();
//		int cy=pc.front();
//		pc.pop();
//		for(int i=0;i<4;i++){
//			int tx=dx[i]+cx;
//			int ty=dy[i]+cy;
//			if(c[tx][ty]==true||tx<=0||ty<=0||tx>n||ty>m) continue;
//			c[tx][ty]=true;
//			p[tx][ty]=p[cx][cy]+1;
//			pc.push(tx);
//			pc.push(ty);
//		}
//	}
//}
//int main() {
//	memset(c,false,sizeof(c));
//	scanf("%d%d%d%d",&n,&m,&a,&b); 
//	for(int i=1;i<=a;i++){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		pc.push(x);
//		pc.push(y);
//		c[x][y]=true;
//		p[x][y]=0;
//	}
//	bfs();
//	for(int i=1;i<=b;i++){
//		int q,w;
//		cin>>q>>w;
//		cout<<p[q][w]<<endl;
//	}
//	return 0;
//}
//
//
//
//
//胜利大逃亡
//#include<bits/stdc++.h>
//using namespace std;
//int k,a,b,cc,t;
//int p[101][101][101];
//bool c[101][101][101];
//int r[101][101][101];
//int dx[6]= {1,-1,0,0,0,0};
//int dy[6]= {0,0,1,-1,0,0};
//int dz[6]= {0,0,0,0,1,-1};
//queue<int> pc;
//void bfs(){
//	pc.push(0);
//	pc.push(0);
//	pc.push(0);
//	c[0][0][0]=true;
//	r[0][0][0]=0;
//	while(!pc.empty()){
//		int cx=pc.front();
//		pc.pop();
//		int cy=pc.front();
//		pc.pop();
//		int cz=pc.front();
//		pc.pop();
//		for(int i=0;i<6;i++){
//			int tx=cx+dx[i];
//			int ty=cy+dy[i];
//			int tz=cz+dz[i];
//			if(tx>=0 && ty>=0 && tz>=0 && tz<a && tx<b && ty<cc && p[tz][tx][ty]==0 && c[tz][tx][ty]==false){
//				c[tz][tx][ty]=true;
//				r[tz][tx][ty]=r[cz][cx][cy]+1;
//              pc.push(tx);
//				pc.push(ty);
//				pc.push(tz);
//			}
//		}
//	}
//}
//int main(){
//	scanf("%d",&k);
//	while(k){
//		memset(c,false,sizeof(c));
//		memset(r,0,sizeof(r));
//		memset(p,0,sizeof(p));
//		scanf("%d%d%d%d",&a,&b,&cc,&t);
//		for(int i=0; i<a; i++)
//            for(int j=0; j<b; j++)
//                for(int o=0; o<cc; o++)
//                    cin>>p[i][j][o];
//        bfs();
//        if(r[a-1][b-1][cc-1]<=t && r[a-1][b-1][cc-1]>0) cout<<r[a-1][b-1][cc-1]<<endl;
//        else cout<<-1<<endl;
//        k--;
//	}
//	return 0;
//}
//
//
//
//
//P6566 [NOI Online #3 入门组] 观星
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,tot=0,sum=0,p[100001],ans=0,pc=0;
//char a[2001][2001];
//int dx[8]={0,0,1,-1,1,1,-1,-1};
//int dy[8]={1,-1,0,0,1,-1,1,-1};
//void dfs(int x,int y){
//	a[x][y]='.';
//	for(int i=0;i<8;i++){
//		int tx=x+dx[i];
//		int ty=y+dy[i];
//		if(tx<=0||ty<=0||tx>n||ty>m||a[tx][ty]=='.') continue;
//		tot++;
//		dfs(tx,ty);
//		a[tx][ty]='.';
//	}
//}
//bool cmp(int x,int y){
//	return x>y;
//}
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cin>>a[i][j];
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(a[i][j]=='*'){
//				tot=1;
//				dfs(i,j);
//				if(p[tot]==0) sum++;
//				p[tot]+=tot;
//				pc=max(pc,p[tot]);
//			}
//		}
//	}
//	cout<<sum<<" "<<pc;
//	return 0;
//}
//
//
//
//P6330 [COCI2007-2008#1] CETVRTA
//#include<bits/stdc++.h>
//using namespace std;
//struct aa{
//	int x,y;
//}a[10];
//bool cmp(aa p,aa c){
//	if(p.x<c.x) return p.x<c.x;
//	else if(p.x==c.x) return p.y<c.y;
//}
//int main(){
//	for(int i=1;i<=3;i++) cin>>a[i].x>>a[i].y;
//	sort(a+1,a+3+1,cmp);
////	for(int i=1;i<=3;i++) cout<<a[i].x<<" "<<a[i].y<<endl;
//	if(a[1].x==a[2].x&&a[1].y==a[3].y) cout<<a[3].x<<" "<<a[2].y;
//	if(a[1].y==a[2].y&&a[2].x==a[3].x) cout<<a[1].x<<" "<<a[3].y;
//	if(a[1].x==a[2].x&&a[2].y==a[3].y) cout<<a[3].x<<" "<<a[1].y;
//	if(a[1].y==a[3].y&&a[2].x==a[3].x) cout<<a[1].x<<" "<<a[2].y;
//	return 0;
//}
//
//
//
//
//一道有趣的题
/*
思路：把能够直接到的去掉，并标记为*，再把到不了的去掉
这道题有个细节，对于样例1：
6 7
...#.A.
.#B#.#.
.#.#.#.
.#.#.#.
.#b#.#.
a#...#*
连通块划分后：
111#2A*
1#B#2#*
1#2#2#*
1#2#2#*
1#b#2#*
a#222#*
连通块1不能搜到*，但是2能先到1拿到a钥匙，再去开(1,6)的A门，这样就能到*。
如果直接将搜索过程（拿钥匙开门）中能通达的部分都标记相同，每次标记都少一个.，
直到标记完所有.为止，那么1也会被标记为2，这样就不能排除1中的.了。
（这里其实还是可以排除，因为是先处理1，但是万一先处理的是2，
例如将样例1反序输入，那么就没有机会再处理1了，因为1都被标记了）
因此，正确的做法是先划分连通块（用#和门划分），之后不同连通块分开处理，分开搜索，
这样就能在保证搜索的正确性（搜索过程中肯定会从某个连通块搜索到另一个连通块）基础上，
区别不同的连通块
*/
//#include<bits/stdc++.h>
//using namespace std;
//char a[51][51];//输入
//bool b[51][51];//搜索过程中中标记某个点是否搜过
//int g[51][51];//划分连通块，相同连通块的点g值相同
//bool f[51][51];//标记门之前有没有搜过
//int c[27]; //统计对应的门是否可以开
//int n,m;
//int cx,cy; //出口坐标
//int t;//染色
//int k=0;
//bool flag0=true;//标记某个联通块是否已经跑过bfs
//bool flag=false; //记录是否能通达*
//int dx[4]= {1,-1,0,0},dy[4]= {0,0,-1,1};
//struct xy {
//    int x,y;
//} node,top,e[2501]; //e数组用来标记搜索过程中搜到的门的坐标
//queue<xy> Q;
//int total,total1; //total表示总.数，total1表示每个联通块的总.数
//void clear(queue<xy>& q) { //清空队列
//    queue<xy>empty;
//    swap(empty,q);
//}
//void bfs1() { //第一次搜索的目的是将所有*不经过门直接能通达的.都标记为*，
//             //因为最后计数这些肯定不算在内
//    while(!Q.empty()) {
//        top=Q.front();
//        Q.pop();
//        for(int i=0; i<4; i++) {
//            int t1=top.x+dx[i];
//            int t2=top.y+dy[i];
//            if(t1<1||t1>n||t2<1||t2>m||a[t1][t2]=='#'||(a[t1][t2]>='A'&&a[t1][t2]<='Z')) continue;
//            if(!b[t1][t2]) {
//                node.x=t1;
//                node.y=t2;
//                Q.push(node);
//                b[t1][t2]=true;
//                if(a[t1][t2]=='.') {//如果是.，将total--，并且将.替换成*
//                    total--;
//                    a[t1][t2]='*';
//                }
//            }
//        }
//    }
//    clear(Q);
//    memset(b,false,sizeof(b));
//}
//void bfs3() { //第二次搜索目的是将g数组划分为不同的连通块
//             //这里不能直接对a数组进行染色，因为如果连通块1可以通达连通块2，
//             //反过来连通块2无法通达连通块1，这两个连通块就无法区别开
//    while(!Q.empty()) {
//        top=Q.front();
//        if(a[top.x][top.y]=='.')
//            g[top.x][top.y]=t;
//        //若将这个判断写在入队，这样对某些只有一个.的连通块就没办法标记了，
//        //因为入队标记的都是邻接点，万一没有邻接点，就不会标记了
//        Q.pop();
//        for(int i=0; i<4; i++) {
//            int t1=top.x+dx[i];
//            int t2=top.y+dy[i];
//            if(t1<1||t1>n||t2<1||t2>m||a[t1][t2]=='#'||(a[t1][t2]>='A'&&a[t1][t2]<='Z')) continue;
//            //这里把大写字母也看成障碍
//            if(!b[t1][t2]) {
//                node.x=t1;
//                node.y=t2;
//                Q.push(node);
//                b[t1][t2]=true;
//            }
//        }
//    }
//    clear(Q);
//    memset(b,false,sizeof(b));
//}
//void bfs2(int i,int j) {
//第三次搜索，目的是判断从某个连通块开始，能否成功搜索到*
//做法是：一边搜钥匙，一边记录门的坐标，搜完一把钥匙，看看有没有对应的门，
//如果有，将门入队
//我第一次的做法是，先把所有钥匙搜到，再处理门，
//外层写一个循环，重复拿钥匙、开门这一过程，直到没有新钥匙产生，但是这种做法会超时
//门入队就可大大降低时间，因为搜过的区域就可以避免重复搜索
//    queue<xy> Q1;
//    node.x=i;
//    node.y=j;
//    Q1.push(node);
//    b[i][j]=true;
//    while(!Q1.empty()) {
//        top=Q1.front();
//        //cout<<"top="<<top.x<<" "<<top.y<<endl;
//        if(a[top.x][top.y]=='.') {
//            total1++;
//        }
//        Q1.pop();
//        for(int i=0; i<4; i++) {
//            int t1=top.x+dx[i];
//            int t2=top.y+dy[i];
//            if(t1<1||t1>n||t2<1||t2>m||a[t1][t2]=='#') continue;
//            if(!b[t1][t2]) {
//                if(a[t1][t2]>='A'&&a[t1][t2]<='Z') {
//                    if(f[t1][t2]) continue; //如果这个门已经标记过了，就不用再标记了
//                    e[++k].x=t1; //e数组记录门的坐标
//                    e[k].y=t2;
//                    continue; //暂时把门当障碍处理，等到后面再处理
//                }
//  
//                if(a[t1][t2]>='a'&&a[t1][t2]<='z') {
//                    c[a[t1][t2]-'a'+1]++; //搜到了钥匙，相应门的钥匙+1                
//                }
//                node.x=t1;
//                node.y=t2;
//                if(a[t1][t2]=='*') {
//                    flag=true; //如果搜索过程中可以搜到*，说明这个连通块可以经过门到达*
//                               //因为，不能经过门直接到*的一开始就被bfs1排除
//                }
//                Q1.push(node);
//                //cout<<"push="<<t1<<" "<<t2<<endl;
//                b[t1][t2]=true;
//            }
//        }
//        for(int i=1; i<=k; i++) {//对应钥匙的门入队
//            if(c[a[e[i].x][e[i].y]-'A'+1]) { //若有钥匙
//                if(f[e[i].x][e[i].y]) continue; //若这个门已经处理过了，跳过
//                node.x=e[i].x;
//                node.y=e[i].y;
//                Q1.push(node);
//                b[node.x][node.y]=true;
//                f[e[i].x][e[i].y]=true;
//                //cout<<"pushaaaaaa="<<node.x<<" "<<node.y<<endl;
//            }
//        }
//    }
//    clear(Q1);
//    memset(b,false,sizeof(b));
//}
//int main() {
//    cin>>n>>m;
//    memset(b,false,sizeof(b));
//    for(int i=1; i<=n; i++)
//        for(int j=1; j<=m; j++) {
//            cin>>a[i][j];
//            if(a[i][j]=='*') {
//                cx=i;
//                cy=j;
//            } else if(a[i][j]=='.')
//                total++;
//        }
//  
//    node.x=cx;
//    node.y=cy;
//    Q.push(node);
//    b[cx][cy]=true;
//    bfs1();
//    //cout<<total<<endl; //第一次bfs 记录除了*一步能到达的总数
//    t=1;
//    for(int i=1; i<=n; i++)
//        for(int j=1; j<=m; j++)
//            if(a[i][j]=='.'&&g[i][j]==0) { //第二次bfs是在染色，将不同联通块用不同数字表示
//                node.x=i;
//                node.y=j;
//                Q.push(node);
//                b[cx][cy]=true;
//                bfs3();
//                t++; //用不同数字染色
//            }
//    for(int i=1;i<=n;i++){  //用来显示联通块是否染色成功
//          for(int j=1;j<=m;j++)
//              if(g[i][j])
//            cout<<g[i][j];
//              else cout<<a[i][j];
//              cout<<endl;
//              }
//          cout<<endl;
//    int l=1;
//    while(l<t) { //枚举每种连通块的数字，保证同一个连通块只处理一个.
//        flag0=false;
//        for(int i=n; i>=1; i--) { //这里可以不用倒着搜，当初倒着搜会有反例：开门是有顺序的
//            for(int j=m; j>=1; j--) {
//                memset(c,0,sizeof(c));
//                memset(f,false,sizeof(f));
//                memset(e,0,sizeof(e));
//                if(a[i][j]=='.'&&g[i][j]==l) {
//                    if(flag0==true) break; //同一个联通块的点没必要再跑一遍
//                    flag0=true; //标记该联通块已经跑过了
//                    flag=false; //赋初值，用来记录是否能从这个联通块搜索到*
//                    total1=0;  //赋初值，记录从该联通块能搜到多少*
//                    bfs2(i,j);
//  
//                    if(!flag)  //若这个联通块不能通达*，则在总数减去其染色数
//                        total-=total1;
//                }
//            }
//        }
//        l++; //下一个连通块
//    }
//    cout<<total<<endl;
//    return 0;
//}
//
//
//
//外星生命
//#include<bits/stdc++.h>
//using namespace std;
//string s;
//int p[100],ans=1e9,len,cnt;
//int pc() {
//	long long a=0,b=0,c=0,d;
//	int sum=0;
//	for(int i=1; i<=6; i++) a=p[i]+a*10;
//	for(int i=7; i<=12; i++) b=p[i]+b*10;
//	for(int i=13; i<=18; i++) c=p[i]+c*10;
//	d=a*b;
//	d=d%1000000;
//	while(max(c,d)) {
//		if(d%10!=c%10) sum++;
//		d/=10;
//		c/=10;
//	}
//	return sum;
//}
//void dfs(int x,int step) {
//	if(step>=ans||pc()>ans) return ;
//	if(x==13) {
//		ans=min(ans,pc()+step);
//		return ;
//	}
//	dfs(x+1,step);
//	for(int j=0; j<=9; j++) {
//		int r=p[x];
//		p[x]=j;
//		dfs(x+1,step+1);
//		p[x]=r;
//	}
//}
//int main() {
//	cin>>s;
//	len=s.size();
//	cnt=0;
//	for(int i=0; i<len; i++)
//		if(s[i]>='0'&&s[i]<='9')
//			p[++cnt]=s[i]-'0';
//	ans=pc();
//	dfs(1,0);
//	printf("%d",ans);
//	return 0;
//}
//
//
//
//
//
//三角形计数
//#include<bits/stdc++.h>
//using namespace std;
//long long a1[100001],a2[100001],a3[100001],a4[100001],n;
//int main() {
//	memset(a1,0,sizeof(a1));
//	memset(a2,0,sizeof(a2));
//	memset(a3,0,sizeof(a3));
//	memset(a4,0,sizeof(a4));
//	a3[1]=a2[1]=4,a4[1]=1;
//	for(int i=1; i<=100001; i+=2) a1[i]=2,a1[i+1]=1;
//	for(int i=2; i<=100001; i++) a2[i]=a2[i-1]+a1[i-1];
//	for(int i=2; i<=100001; i++) a3[i]=a3[i-1]+a2[i-1];
//	for(int i=2; i<=100001; i++) a4[i]=a4[i-1]+a3[i-1];
//	scanf("%lld",&n);
//	printf("%lld",a4[n]);
//	return 0;
//}
//
//
//
//
//
//组合数取模
//#include<bits/stdc++.h>
//using namespace std;
//long long z,y,p;
//long long prime[100001],min_prime[100001],t;
//int b[100001];
//void els(long long n){
//	for(long long i=2;i<=n;i++){
//		if(b[i]==0){
//			prime[++t]=i;
//			min_prime[i]=t;
//		}
//		for(long long j=1;j<=t&&prime[j]*i<=n;j++){
//			b[prime[j]*i]=1;
//			min_prime[prime[j]*i]=j;
//			if(i%prime[j]==0) break;
//		}
//	}
//}
//long long c(long long n,long long m,long long q){
//	els(n);
//	int a[t+5];
//	for(long long i=1;i<=t;i++) a[i]=0;
//	for(long long i=n;i>=n-m+1;i--) {
//		int x=i;
//		while(x!=1){
//			a[min_prime[x]]++;
//			x/=prime[min_prime[x]];
//		}
//	}
//	for(long long i=1;i<=m;i++){
//		long long x=i;
//		while(x!=1){
//			a[min_prime[x]]--;
//			x/=prime[min_prime[x]];
//		}
//	}
//	long long ans=1;
//	for(long long i=1;i<=t;i++){
//		while(a[i]>0){
//			ans=ans*prime[i]%p;
//			a[i]--;
//		}
//	}
//	return ans;
//}
//int main(){
//	scanf("%lld%lld%lld",&z,&y,&p);
//	cout<<c(z,y,p);
//	return 0;
//} 
//
//
//
//
//
//放球同不同不空
//#include<bits/stdc++.h>
//using namespace std;
//int m,n;
//int main(){
//	scanf("%d%d",&m,&n);
//	unsigned long long jn=1,jm=1,jmn=1;
//	for(int i=1;i<=n-1;i++) jn*=i;
//	for(int i=1;i<=m-1;i++) jm*=i;
//	for(int i=1;i<=m-n;i++) jmn*=i;
//	cout<<jm/(jn*jmn);
//	return 0;
//} 
//
//
//
//
//#include<bits/stdc++.h>
//using namespace std;
//int m,n;
//inline void print(__int128 n){
//    if(n<0){
//        putchar('-');
//        n*=-1;
//    }
//    if(n>9) print(n/10);
//    putchar(n % 10 + '0');
//}
//int main(){
//	scanf("%d%d",&n,&m);
//	__int128 jn=1,jm=1,jmn=1;
//	for(int i=1;i<=n;i++) jn*=i;
//	for(int i=1;i<=m-1;i++) jm*=i;
//	for(int i=1;i<=m+n-1;i++) jmn*=i;
//	print(jmn/(jm*jn));
//	return 0;
//} 
//
//
//
//放球3不同不同空
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//long long p=1000000007;
//long long ans=1;
//int main() {
//    scanf("%d%d",&n,&m);
//    for(int i=1;i<=n;i++) ans=(ans%p*m%p)%p;
//    cout<<ans;
//    return 0;
//}
//
//
//
//
//
//放球6不同不同不空
//#include<bits/stdc++.h>
//using namespace std;
//long long dp[25][25],ans=0,p=1000000007;
//int main(){
//	int n,m;
//	cin>>m>>n;
//	for(int i=1;i<=m;i++) dp[i][1]=1; 
//	for(int i=2;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
//		}
//	}
//	ans = dp[m][n];
//    for(long long i=1;i<=n;i++){
//        ans = (ans%p*i%p)%p;
//    }
//	cout<<ans;
//	return 0;
//}
//
//
//
//放球4不同同不空
//#include<bits/stdc++.h>
//using namespace std;
//long long dp[25][25];
//int main(){
//    int n,m;
//    cin>>m>>n;
//    for(int i=1;i<=m;i++) dp[i][1]=1;
//    for(int i=2;i<=m;i++){
//        for(int j=1;j<=n;j++){
//            dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
//        }
//    }
//    cout<<dp[m][n];
//    return 0;
//}
//
//
//
//
//
//放球5不同同空
//#include<bits/stdc++.h>
//using namespace std;
//long long dp[25][25],ans=0;
//int main(){
//    int n,m;
//    cin>>m>>n;
//    for(int i=1;i<=m;i++) dp[i][1]=1;
//    for(int i=2;i<=m;i++){
//        for(int j=1;j<=n;j++){
//            dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
//        }
//    }
//    for(int i=1;i<=n;i++) ans+=dp[m][i];
//    cout<<ans;
//    return 0;
//}
//
//
//
//
//放球7同同空	
//#include<bits/stdc++.h>
//#define LL long long
//using namespace std;
//LL dp[105][105];//i个小球放到j个篮子方案总数
//int main(){
//    LL m,n;
//    cin >> m >> n;//m小球,n盒子
//    for(LL i=1;i<=m;i++) dp[i][1]=1;
//    for(LL i=1;i<=n;i++) dp[1][i]=dp[0][i]=1;
//    for(LL i=2;i<=m;i++)//球
//        for(LL j=2;j<=n;j++){//盒子
//            if(i >= j) dp[i][j]=dp[i][j-1]+dp[i-j][j];
//            else dp[i][j]=dp[i][i];
//        }
//    cout << dp[m][n];
//    return 0;
//}
//
//
//
//
//
//放球8同同不空
//#include<bits/stdc++.h>
//#define LL long long
//using namespace std;
//LL dp[105][105],res[105][105];//i个小球放到j个篮子方案总数
//int main(){
//    LL m,n;
//    cin >> m >> n;//m小球,n盒子
//    for(LL i=1;i<=m;i++) dp[i][1]=1;
//    for(LL i=1;i<=n;i++) dp[1][i]=dp[0][i]=1;
//    for(LL i=2;i<=m;i++){//球
//        for(LL j=2;j<=n;j++){//盒子
//            if(i >= j) dp[i][j]=dp[i][j-1]+dp[i-j][j];
//            else dp[i][j]=dp[i][i];
//        }
//    }
//    for(LL i=1;i<=m;i++){
//        for(LL j=2;j<=n;j++){
//            res[i][j] = dp[i][j];
//            res[i][j] -= dp[i][j-1];
//        }
//    }
//    cout << res[m][n];
//    return 0;
//}
//
//
//
//
//
//信封问题
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//long long dp[10001];
//int main(){
//    scanf("%d",&n);
//    dp[1]=0;
//    dp[2]=1;
//    for(int i=3;i<=n;i++) dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
//    cout<<dp[n];
//    return 0;
//}
//
//
//
//
//
//
//巨大的数
//#include<bits/stdc++.h>
//using namespace std;
//long long n,s;
//int main(){
//	scanf("%lld%lld",&n,&s);
//	long long ans=9*17+s,sum=0;
//	for(long long i=s;i<=min(ans,n);i++){
//		long long z=i;
//		long long p=0;
//		while(z){
//			p=p+z%10;
//			z/=10;
//		}
//		if(i-s>=p) sum++;
//	}
//	if(ans>=n) cout<<sum;
//	else cout<<sum+(n-ans);
//	return 0;
//} 
//
//
//
//
//
//
//最小差
//#include<bits/stdc++.h>
//using namespace std;
//long long n,k;
//long long a[100001],pc=1e9;
//int main(){
//	scanf("%lld%lld",&n,&k);
//	if(n==k+1){
//		cout<<0;
//		return 0;
//	}
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	sort(a+1,a+n+1);
//	for(int i=0;i<=k;i++) pc=min(pc,a[n-k+i]-a[1+i]);
//	cout<<pc;	
//	return 0;
//}
//
//
//
//
//
//
//虚实桥梁
//#include<bits/stdc++.h>
//using namespace std;
//struct a{
//	long long end,w,cnt;
//};
//vector <a> pc[300001];
//queue <a> P;
//long long n,m,ans=1e9;
//bool bj[300001];
//void bfs(){
//	bj[1]=true;
//	for(long long i=0;i<pc[1].size();i++){ 
//		if(pc[1][i].w==0) P.push((a){pc[1][i].end,pc[1][i].w,1});
//		if(pc[1][i].w==1) P.push((a){pc[1][i].end,pc[1][i].w,2});
//	}
//	while(!P.empty()){
//		a d=P.front();
//		P.pop();
//		if(d.end==n) ans=min(ans,d.cnt);
//		for(long long i=0;i<pc[d.end].size();i++){
//			a cr=pc[d.end][i];
//			if(bj[cr.end]==true) continue;
//			bj[cr.end]=true;
//			if(cr.w==d.w) P.push((a){cr.end,cr.w,d.cnt+1});
//			else  P.push((a){cr.end,cr.w,d.cnt+2});
//		}
//	}
//	if(ans!=1e9) printf("%lld",ans);
//	else printf("no more run");
//}
//int main(){
//	scanf("%lld%lld",&n,&m);
//	for(long long i=1;i<=m;i++){
//		long long u,v,w;
//		cin>>u>>v>>w;
//		pc[u].push_back((a){v,w,0});
//		pc[v].push_back((a){u,w,0});
//	}
//	bfs();
//	return 0;
//}
//
//
//
//
//
//P5690	[CSP-S2019 江西] 日期
//#include<bits/stdc++.h>
//using namespace std;
//int m,d,ans=1023456789,sum;
//int pd(int a,int b){
//	return 2-(a/10==b/10)-(a%10==b%10);
//}
//int date(int x){
//	if(x==2) return 28;
//	if(x==4||x==6||x==9||x==11) return 30;
//	return 31;
//}
//int main(){
//	scanf("%d-%d",&m,&d);
//	for(int i=1;i<=12;++i){
//		sum=pd(i,m);
//		if(d<=0||date(i)<d) ++sum;
//		ans=min(sum,ans);
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//P5736	【深基7.例2】质数筛
//#include<bits/stdc++.h>
//using namespace std;
//int n,a[100001];
//bool pd(int x){
//	if(x<2) return false;
//	if(x==3||x==2) return true;
//	for(int i=2;i<=sqrt(x);i++) {
//		if(x%i==0) return false;
//	}
//	return true;
//}
//int main(){
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//	for(int i=1;i<=n;i++){
//		if(pd(a[i])==true) cout<<a[i]<<" ";
//		else continue; 
//	}
//	return 0;
//}
//
//
//
//
//
//P5738	【深基7.例4】歌唱比赛
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//int a[100];
//double ans=0;
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++){
//		int a[101];
//		for(int j=1;j<=m;j++) scanf("%d",&a[j]);
//		sort(a+1,a+m+1);
//		double sum=0;
//		for(int i=2;i<m;i++) sum+=a[i];
//		ans=max(ans,sum/(m-2));
//	}
//	printf("%.2lf",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//P7866	「EVOI-RD1」小昕昕
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//char a[200][2];
//int p[1001][100];
//int main(){
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++) {
//		cin>>a[i][1]>>a[i][2];
//		if(a[i][1]=='S') a[i][1]=1;
//		if(a[i][1]=='H') a[i][1]=2;
//		if(a[i][1]=='C') a[i][1]=3;
//		if(a[i][1]=='D') a[i][1]=4;
//		if(a[i][2]=='A') p[a[i][1]][1]++;
//		else if(a[i][2]=='T') p[a[i][1]][10]++;
//		else if(a[i][2]=='J') p[a[i][1]][11]++;
//		else if(a[i][2]=='Q') p[a[i][1]][12]++;
//		else if(a[i][2]=='K') p[a[i][1]][13]++;
//		else p[a[i][1]][a[i][2]-'0']++;
//	}
//	int ans=0;
//	for(int i=1;i<=13;i++)
//		for(int j=1;j<=4;j++)
//			for(int k=1;k<=4;k++)
//				if(p[j][i]==2&&p[k][i]==1){
//					p[j][i]=0;
//					p[k][i]=0;
//					ans++;
//				}
//	for(int i=1;i<=13;i++)
//		for(int j=1;j<=4;j++)
//			for(int k=1;k<=4;k++)
//				if(p[j][i]==2&&p[k][i]!=0&&j!=k){
//					p[j][i]=0;
//					p[k][i]--;
//					ans++;
//				}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//P1044	[NOIP2003 普及组] 栈
//#include<bits/stdc++.h>
//using namespace std;
//int a[1001]={1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700};
//int main(){
//	int n;
//	cin>>n;
//	cout<<a[n-1];
//	return 0;
//}
//
//
//
//
//
//
//P5534	【XR-3】等差数列
//#include<bits/stdc++.h>
//using namespace std;
//long long a1,a2,n;
//long long a[1000001];
//int main(){
//	cin>>a1>>a2>>n;
//	a[1]=a1;
//	a[2]=a2;
//	long long ans=a1+a2;
//	long long gc=abs(a1-a2);
//	if(a1<=a2){
//		for(long long i=3;i<=n;i++) {
//			a[i]=a[i-1]+gc;
//			ans+=a[i];
//		}
//		 cout<<ans;
//		 return 0;
//	}
//	if(a1>a2){
//		for(long long i=3;i<=n;i++) {
//			a[i]=a[i-1]-gc;
//			ans+=a[i];
//		}
//		 cout<<ans;
//		 return 0;
//	}
//	return 0;
//}
//
//
//
//
//
//
//P1024	[NOIP2001 提高组] 一元三次方程求解
//#include<bits/stdc++.h>
//using namespace std;
//double a,b,c,d;
//double js(double x){
//	return a*x*x*x+b*x*x+c*x+d;
//}
//int main(){
//	cin>>a>>b>>c>>d;
//	int cnt=0;
//	for(int i=-100;i<100;i++){
//		double p,c,mid;
//		double l=i;
//		double r=i+1;
//		p=js(l);
//		c=js(r);
//		if(p==0){
//			printf("%.2lf ",l);
//			cnt++;
//		}
//		if(p*c<0){
//			while(r-l>=0.001){
//				mid=(l+r)/2;
//				if(js(mid)*js(r)<=0) l=mid;
//				else r=mid;
//			}
//			printf("%.2lf ",r);
//			cnt++;
//		}
//		if(cnt==3) break;
//	}
//	return 0;
//}
//
//
//
//
//
//
//P1571	眼红的Medusa
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//int kc[100001],kj[100001];
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%d",&kc[i]);
//	for(int i=1;i<=m;i++) scanf("%d",&kj[i]);
//	sort(kj+1,kj+m+1);
//	for(int i=1;i<=n;i++){
//		if(binary_search(kj+1,kj+m+1,kc[i])) cout<<kc[i]<<" ";
//	}
//	return 0;
//}
//
//
//
//
//
//
//P1883	函数
//#include<bits/stdc++.h>
//using namespace std;
//int T,n,a[100001],b[100001],c[100001];
//double js(double x){
//	double maxx=0;
//	for(int i=1;i<=n;i++) maxx=max(maxx,a[i]*x*x+b[i]*x+c[i]);
//	return maxx;
//}
//int main(){
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d",&n);
//		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
//		double l=0.0,r=1000.0;
//		while(r-l>1e-11){
//			double mid1=(l*2+r)/3,mid2=(l+r*2)/3;
//			if(js(mid1)>js(mid2)) l=mid1;
//			else r=mid2;
//		}
//		printf("%.4lf\n",js(l));
//	}
//	return 0;
//}
//
//
//
//
//
//
//树节点孩子数
//#include<bits/stdc++.h>
//using namespace std;
//string s[1001];
//int a[1001][1001],n;
//int ans[10001];
//bool bj[100001];
//vector <int> pc[10001];
//int main() {
//    cin>>n;
//    memset(ans,0,sizeof(ans));
//    for(int i=1; i<=n; i++) cin>>s[i];
//    for(int i=1; i<=n; i++) 
//        for(int j=1; j<=n; j++) 
//            a[i][j]=s[i][j-1]-'0';
//    for(int i=1;i<=n;i++){
//    	for(int j=1;j<=n;j++){
//    		if(a[i][j]==1){
//    			pc[i].push_back(j);
//    			pc[i].push_back(j);
//			}
//		}
//	}
//	cout<<(pc[1].size())/2<<" ";
//	for(int i=2;i<=n;i++){
//		for(int j=0;j<int(pc[i].size());j++){
//			if(pc[i][j]!=pc[i][j+1]&&bj[pc[i][j]]==false) {
//				bj[pc[i][j]]==true;
//				ans[i]++;
//			}
//		}
//		cout<<ans[i]-1<<" ";
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//树的宽度
//#include<bits/stdc++.h>
//using namespace std;
//
//int a[1001][1001],n,ans=0,cnt=1;
//bool bj[100001];
//queue <int> P;
//vector <int> C[100001];
//
//void bfs() {
//	bj[1]=1;
//	for(int i=0; i<int(C[1].size()); i++) P.push(C[1][i]);
//	while(!P.empty()) {
//		int lp=P.size();
//		ans=max(ans,int(lp));
//		for(int i=0; i<lp; i++) {
//			int pc=P.front();
//			P.pop();
//			bj[pc]=true;
//			for(int j=0; j<int(C[pc].size()); j++) {
//				if(bj[C[pc][j]]==false) P.push(C[pc][j]);
//			}
//		}
//		cnt++;
//	}
//	cout<<ans;
//}
//int main() {
//	cin>>n;
//	memset(bj,false,sizeof(bj));
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			char c;
//			cin>>c;
//			if(c=='1') a[i][j]=1;
//			else a[i][j]=0;
//		}
//	}
//	for(int i=1; i<=n; i++){
//		for(int j=i+1; j<=n; j++) {
//			if(a[i][j]==1){
//				C[i].push_back(j);
//				C[j].push_back(i);
//			}
//		}
//	}
//	bfs();
//	return 0;
//}
//
//
//
//
//
//
//找父亲
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//vector <int> P[1000001];
//bool bj[100001];
//int fa[100001];
//void dfs(int x){
//	bj[x]=true;
//	for(int i=0;i<int(P[x].size());i++){
//		int y=P[x][i];
//		if(bj[y]==true) continue;
//		else fa[y]=x;
//		dfs(y);
//	}
//}
//int main(){
//	memset(bj,false,sizeof(bj));
//	scanf("%d",&n);
//	for(int i=1;i<n;i++){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	dfs(1);
//	for(int i=2;i<=n;i++) cout<<fa[i]<<" ";
//	return 0;
//}
//
//
//
//
//
//
//
//树的重量
//#include<bits/stdc++.h>
//using namespace std;
//int n,x,y,h[100001];
//vector <int> P[100001];
//bool bj[100001];
//int dfs(int x){
//	bj[x]=true;
//	int pc=1;
//	for(int i=0;i<P[x].size();i++){
//		int y=P[x][i];
//		if(bj[y]==true) continue;
//		pc+=dfs(y);
//	}
//	h[x]=pc;
//	return pc;
//}
//int main(){
//	memset(bj,false,sizeof(bj));
//	scanf("%d",&n);
//	for(int i=1;i<n;i++){
//		scanf("%d%d",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	dfs(1);
//	for(int i=1;i<=n;i++) printf("%d\n",h[i]);
//	return 0;
//}
//
//
//
//
//
//
//二叉树
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int pc[10001];
//int main(){
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++){
//		int p;
//		scanf("%d",&p);
//		pc[p]++;
//	}
//	for(int i=1;i<=n;i++) 
//		if(pc[i]>2) {
//			cout<<"no";
//			return 0;
//		}
//	cout<<"yes";
//	return 0;
//}
//
//
//
//
//
//二叉树的中序遍历
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//struct aa{
//	int l,r;
//}P[1000001];
//void dfs(int x){
//	if(P[x].l!=-1) dfs(P[x].l);
//	cout<<x<<" ";
//	if(P[x].r!=-1) dfs(P[x].r);
//}
//int main(){
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++) scanf("%d%d",&P[i].l,&P[i].r);
//	dfs(1);
//	return 0;
//}
//
//
//
//
//
//
//
//
//FBI树
//#include<bits/stdc++.h>
//using namespace std;
//string s;
//int P[100001],n;
//void dfs(int x,int y){
//	if(x<y){
//		dfs(x,(x+y)/2);
//		dfs((x+y)/2+1,y);
//	}
//	bool B=1,I=1;
//	for(int i=0;i<=y-x;i++){
//		if(P[x+i]==0) I=0;
//		if(P[x+i]==1) B=0;
//	}
//	if(I==1) cout<<"I";
//	else if(B==1) cout<<"B";
//	else cout<<"F";
//}
//int main(){
//	cin>>n;
//	cin>>s;
//	for(int i=0;i<s.size();i++) P[i+1]=s[i]-'0';
//	dfs(1,(1<<n));
//	return 0;
//}
//
//
//
//
//
//
//
//求先序排列
//#include<bits/stdc++.h>
//using namespace std;
//char mid[1000],after[1000];
//void dfs(int ml,int mr,int al,int ar) {
//	if(ml>mr||al>ar) return ;
//	cout<<after[ar];
//	for(int i=ml; i<=mr; i++) {
//		if(mid[i]==after[ar]) {
//			dfs(ml,i-1,al,al+i-ml-1);
//			dfs(i+1,mr,al+i-ml,ar-1);
//			break;
//		}
//	}
//}
//int main() {
//	cin>>mid>>after;
//	int len=strlen(mid)-1;
//	dfs(0,len,0,len);
//	return 0;
//}
//
//
//
//
//
//
//
//
//遍历问题
//#include<bits/stdc++.h>
//using namespace std;
//int ans=0;
//string s1,s2;
//int main(){
//    cin>>s1>>s2;
//    for(int i=0;i<s1.size();i++)
//        for(int j=1;j<s2.size();j++)
//            if(s1[i]==s2[j]&&s1[i+1]==s2[j-1])
//                ans++;
//    printf("%d",(1<<ans));
//    return 0;
//} 
//
//
//
//
//
//
//
//树的遍历（升级版）
//#include<bits/stdc++.h>
//using namespace std;
//char s1[27],s2[27];
//int m,len;
//int C(int a,int b) {
//    long long int ans=1;
//    for (int i=a; i>=a-b+1; i--) ans*=i;
//    for (int i=b; i>=1; i--) ans/=i;
//    return (int)ans;
//}
//int f(int m,int l,char *s1,char* s2) {
//    if (l==0) return 1;
//    int now=0,count=0,ans=1;
//    while (now<l) {
//        for (int i=now; i<l; i++)
//            if (s2[i]==s1[now]) {
//                count++;
//                ans*=f(m,i-now,s1+now+1,s2+now);
//                now=i+1;
//                break;
//            }
//    }
//    return ans*C(m,count);
//}
//int main() {
//    cin>>m;
//    scanf(" %s %s",s1,s2);
//    len=strlen(s1);
//    printf("%d\n",f(m,len-1,s1+1,s2));
//    return 0;
//}
//
//
//
//
//
//
//树的深度	
//#include<bits/stdc++.h>
//using namespace std;
//  
//int a[1001][1001],n,ans=0,cnt=1;
//bool bj[100001];
//queue <int> P;
//vector <int> C[100001];
//  
//void bfs() {
//    int cnt=0;
//    bj[1]=1;
//    for(int i=0; i<int(C[1].size()); i++) P.push(C[1][i]);
//    while(!P.empty()) {
//        int lp=P.size();
//        ans=max(ans,int(lp));
//        for(int i=0; i<lp; i++) {
//            int pc=P.front();
//            P.pop();
//            bj[pc]=true;
//            for(int j=0; j<int(C[pc].size()); j++) {
//                if(bj[C[pc][j]]==false) P.push(C[pc][j]);
//            }
//        }
//        cnt++;
//    }
//    cout<<cnt;
//}
//int main() {
//    cin>>n;
//    memset(bj,false,sizeof(bj));
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            char c;
//            cin>>c;
//            if(c=='1') a[i][j]=1;
//            else a[i][j]=0;
//        }
//    }
//    for(int i=1; i<=n; i++){
//        for(int j=i+1; j<=n; j++) {
//            if(a[i][j]==1){
//                C[i].push_back(j);
//                C[j].push_back(i);
//            }
//        }
//    }
//    bfs();
//    return 0;
//}
//
//
//
//
//
//P1190 [NOIP2010 普及组] 接水问题
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,t=0;
//int w[100001];
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
//	int p=m;
//	while(p<=n){
//		for(int i=1;i<=m;i++) {
//			w[i]--;
//			if(w[i]==0) w[i]=w[++p];
//		}
//		t++;
//	}
//	for(int i=1;i<=m;i++) w[1]=max(w[1],w[i]);
//	cout<<t+w[1];
//	return 0;
//}
//
//
//
//
//
//
//
//P1029	[NOIP2001 普及组] 最大公约数和最小公倍数问题
//#include<bits/stdc++.h>
//using namespace std;
//long long x,y,ans=0,k=1;
//long long c[10000001];
//void pc(long long a,long long b){
//	long long p=a*b;
//	for(long long i=1;i<=sqrt(p);i++)
//		if(p%i==0) c[k++]=i;
//}
//int main(){
//	scanf("%lld%lld",&x,&y);
//	if(x==y){
//		cout<<1;
//		return 0;
//	}
//	pc(x,y);
//	for(long long i=1;i<k;i++){
//		if(__gcd(c[i],(x*y)/c[i])==x) 
//			ans++;
//	}	
//	printf("%lld",ans*2);
//	return 0;
//}
//
//
//
//
//
//
//
//P1088	[NOIP2004 普及组] 火星人
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//int a[100001];
//int main () {
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//	for(int i=1;i<=m;i++) next_permutation(a+1,a+n+1);
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//A - Monkey and Banana
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//struct aa {
//	int x,y,z;
//} a[100];
//struct bb {
//	int x,y,z;
//} bbb[100];
//int p[100],cnt=1,dp[1001][1001];
//int main() {
//	while(cin>>n) {
//		memset(dp,0,sizeof(dp));
//		memset(p,0,sizeof(p));
//		memset(bbb,0,sizeof(bbb));
//		int k=0;
//		if(n==0) break;
//		for(int i=1; i<=n; i++) {
//			cin>>a[i].x>>a[i].y>>a[i].z;
//			p[++k]=a[i].x;
//			p[++k]=a[i].y;
//			p[++k]=a[i].z;
//		}
//		sort(p+1,p+k+1);
//		k=unique(p+1,p+k+1)-p-1;
//		for(int i=1; i<=n; i++) {
//			bbb[i].x=lower_bound(p+1,p+k+1,a[i].x)-p;
//			bbb[i].y=lower_bound(p+1,p+k+1,a[i].y)-p;
//			bbb[i].z=lower_bound(p+1,p+k+1,a[i].z)-p;
//		}
//
//		for(int i=1; i<=k; i++)
//			for(int j=1; j<=k; j++)
//				for(int o=1; o<=n; o++) {
//					if(bbb[o].x<i&&bbb[o].y<j) dp[i][j]=max(dp[i][j],dp[bbb[o].x][bbb[o].y]+a[o].z);
//					if(bbb[o].y<i&&bbb[o].x<j) dp[i][j]=max(dp[i][j],dp[bbb[o].y][bbb[o].x]+a[o].z);
//					if(bbb[o].x<i&&bbb[o].z<j) dp[i][j]=max(dp[i][j],dp[bbb[o].x][bbb[o].z]+a[o].y);
//					if(bbb[o].z<i&&bbb[o].x<j) dp[i][j]=max(dp[i][j],dp[bbb[o].z][bbb[o].x]+a[o].y);
//					if(bbb[o].y<i&&bbb[o].z<j) dp[i][j]=max(dp[i][j],dp[bbb[o].y][bbb[o].z]+a[o].x);
//					if(bbb[o].z<i&&bbb[o].y<j) dp[i][j]=max(dp[i][j],dp[bbb[o].z][bbb[o].y]+a[o].x);
//				}
//		int w=0;
//		for(int i=1; i<=n; ++i){
//			w=max(w,dp[bbb[i].x][bbb[i].y]+a[i].z);
//			w=max(w,dp[bbb[i].y][bbb[i].x]+a[i].z);
//			w=max(w,dp[bbb[i].z][bbb[i].y]+a[i].x);
//			w=max(w,dp[bbb[i].y][bbb[i].z]+a[i].x);
//			w=max(w,dp[bbb[i].x][bbb[i].z]+a[i].y);
//			w=max(w,dp[bbb[i].z][bbb[i].x]+a[i].y);
//		}
//		cout<<"Case "<<cnt<<": maximum height = "<<w<<endl;
//		cnt++;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//Problem ID: 2856 文化差异
//#include<bits/stdc++.h>
//using namespace std;
//char a[1001][1001],o;
//int n,m;
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++){
//			cin>>o;
//			a[i][j]=o;
//		}
//	int ans=1e9;
//	int p=0;
//	for(int k=0;k<=n;k++){
//		int cnts=0,cntn=0;
//		for(int i=1;i<=k;i++)
//			for(int j=1;j<=m;j++)
//				if(a[i][j]=='S') cnts++;
//		for(int i=k+1;i<=n;i++)
//			for(int j=1;j<=m;j++)
//				if(a[i][j]=='N') cntn++;
//		if(ans>cnts+cntn) {
//			p=k;
//			ans=cnts+cntn;
//		}
//	}
//	cout<<p;
//	return 0;
//}
//
//
//
//
//
//
//
//
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//struct aa{
//	int u,v;
//}a[200001];
//vector <int> P[200001];
//int p[200001];
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=m;i++) {
//		scanf("%d%d",&a[i].u,&a[i].v);
//		if(a[i].u!=a[i].v){
//			P[a[i].u].push_back(a[i].v);
//			P[a[i].v].push_back(a[i].u);
//		}
//	}
//	for(int i=1;i<=n;i++){
//		if(P[i].size()==0)  {
//			cout<<endl;
//			continue;
//		}
//		else {
//			memset(p,0,sizeof(p));
//			for(int j=0;j<P[i].size();j++) p[j]=P[i][j];
//			sort(p,p+P[i].size());
//			for(int j=0;j<P[i].size();j++) 
//				if(p[j]!=p[j+1]) 
//					printf("%d ",p[j]);
//			cout<<endl;
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Problem ID: 8252 图1-图的度数
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//vector <int> P[1000001];
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=m;i++) {
//		int u,v;
//		scanf("%d%d",&u,&v);
//		if(u!=v){
//			P[u].push_back(v);
//			P[v].push_back(u);
//		}
//	}
//	for(int i=1;i<=n;i++) printf("%d\n",P[i].size());
//	return 0;
//}
//
//
//
//
//
//
//
//
//Problem ID: 12596 图1-图的类型
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,siz=0,cnt1=0,cnt2=0,ans[1000001],pc[1000001];
//vector <int> P[1000001];
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=m;i++) {
//		int u,v;
//		scanf("%d%d",&u,&v);
//		bool flag=false;
//		for(int j=0;j<min(P[v].size(),P[u].size());j++)
//			if(P[u][j]==v||P[v][j]==u) {
//				flag=true;
//				break;
//			}
//		if(u!=v&&flag==false){ 
//			P[u].push_back(v);
//			P[v].push_back(u);
//		}
//	}
//	for(int i=1;i<=n;i++) {
//		if(P[i].size()==1) cnt1++;
//		if(P[i].size()==2) cnt2++;
//		siz=max(siz,int(P[i].size()));
//	}
//	if(siz==n-1&&cnt1==n-1) {
//		printf("Flower");
//		return 0;
//	}
//	else if(cnt2==n-2&&cnt1==2){
//		printf("Chain");
//		return 0;
//	}
//	else if(cnt2==n){
//		printf("Ring");
//		return 0;
//	}
//	else printf("Neither");
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//Problem ID: 8254 图1-树和图
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//struct aa{
//	int u,v;
//}tre[10001];
//struct bb{
//	int u,v;
//}tu[10001];
//vector <int> P[10001];
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<n;i++) {
//		scanf("%d%d",&tre[i].u,&tre[i].v);
//		P[min(tre[i].u,tre[i].v)].push_back(max(tre[i].u,tre[i].v));
//	}
//	int cnt=n-1,ans=0;
//	for(int i=1;i<=m;i++) {
//		scanf("%d%d",&tu[i].u,&tu[i].v);
//		if(tu[i].u>tu[i].v) swap(tu[i].u,tu[i].v);
//		bool flag=0;
//		for(int j=0;j<P[tu[i].u].size();j++){
//			if(tu[i].v==P[tu[i].u][j]) {
//				flag=1;
//				cnt--;
//				break;
//			}
//		}
//		if(flag==0) ans++;
//	}
//	if(cnt>0) printf("impossible");
//	else printf("%d",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//Problem ID: 8256 图1-最小节点序列
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,r[10001],l;
//bool bj[10001];
//vector <int> P[10001];
//priority_queue <int , vector<int> , greater<int> > C;
//void bfs(){
//	C.push(1);
//	bj[1]=true;
//	while(!C.empty()){
//		int now=C.top();
//		C.pop();
//		cout<<now<<" ";
//		for(int i=0;i<P[now].size();i++){
//			if(bj[P[now][i]]==false){
//				bj[P[now][i]]=true;
//				C.push(P[now][i]);
//			}
//		}
//	}
//}
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=m;i++){
//		int u,v;
//		scanf("%d%d",&u,&v);
//		P[u].push_back(v);
//		P[v].push_back(u);
//	}
//	bfs();
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Problem ID: 12597 Problem ID: 12597
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//int ans[100001];
//vector <int> P[100001];
//void dfs(int d,int ma){
//	ans[d]=ma;
//	for(int i=0;i<P[d].size();i++){
//		if(ans[P[d][i]]==-1) 
//			dfs(P[d][i],ma);
//	}
//}
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=m;i++){
//		int u,v;
//		scanf("%d%d",&u,&v);
//		P[v].push_back(u);
//	}
//	memset(ans,-1,sizeof(ans));
//	for(int i=n;i>=1;i--) {
//		if(ans[i]==-1) dfs(i,i);
//	}
//	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
//	return 0;
//}
//
//
//
//
//
//Problem ID: 8260 信息传递
//#include<bits/stdc++.h>
//using namespace std;
//int n,ans=1e9,t[200002],id[200002];
//bool bj[200002];
//void f(int x){
//	if(bj[x]==true) return ;
//	bj[x]=true;
//	id[t[x]]--;
//	if(id[t[x]]==0) f(t[x]);
//}
//int dfs(int st,int x,int step){
//	if(st==t[x]) return step+1;
//	bj[x]=true;
//	dfs(st,t[x],step+1);
//}
//int main(){
//	memset(bj,false,sizeof(bj));
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++) {
//		scanf("%d",&t[i]);
//		id[t[i]]++;
//	}
//	for(int i=1;i<=n;i++) if(id[i]==0) f(i);
//	for(int i=1;i<=n;i++){
//		if(bj[i]==false) ans=min(ans,dfs(i,t[i],1));
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//Problem ID: 8253 图2-图的连通块个数
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//struct aa{
//	int u,v;
//}a[200001];
//vector <int> P[200001];
//int bj[200001],ans=0;
//void dfs(int x){
//	if(bj[x]!=-1) return ;
//	bj[x]=ans;
//	for(int i=0;i<P[x].size();i++) dfs(P[x][i]);
//}
//int main(){
//	memset(bj,-1,sizeof(bj));
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=m;i++) {
//		scanf("%d%d",&a[i].u,&a[i].v);
//		if(a[i].u!=a[i].v){
//			P[a[i].u].push_back(a[i].v);
//			P[a[i].v].push_back(a[i].u);
//		}
//	}
//	for(int i=1;i<=n;i++)
//		if(bj[i]==-1){
//			ans++;
//			dfs(i);
//		}
//	cout<<ans;
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//Problem ID: 8265 图2-杂务
//#include<bits/stdc++.h>
//using namespace std;
//int n,id[10001],ans[10001];
//struct aa{
//	int x,len;
//}a[10001];
//vector <int> P[10001];
//queue <int> C;
//int main(){
//	scanf("%d",&n);
//	for(int o=1;o<=n;o++){
//		scanf("%d%d",&a[o].x,&a[o].len);
//		int q;
//		while(cin>>q) {
//			if(q==0) break;
//			P[q].push_back(a[o].x);
//			id[a[o].x]++;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		if(id[i]==0) {
//			C.push(i);
//			ans[i]=a[i].len;	
//		}
//	}
//	while(!C.empty()){
//		int pc=C.front();
//		C.pop();
//		for(int i=0;i<P[pc].size();i++){
//			int e=P[pc][i];
//			id[e]--;
//			if(id[e]==0) C.push(e);
//			ans[e]=max(ans[e],ans[pc]+a[e].len);
//		}
//	}
//	int r=0;
//	for(int i=1;i<=n;i++) r=max(r,ans[i]);
//	printf("%d",r);
//	return 0;
//}
//
//
//
//
//
//
//
//
//Problem ID: 9561 朋友圈
//#include<bits/stdc++.h>
//using namespace std;
//int n,fa[10001];
//int find(int x){
//    if(fa[x]==x) return x;
//    else return fa[x]=find(fa[x]);
//}
//int main(){
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++) fa[i]=i;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            int a;
//            scanf("%d",&a);
//            int u=find(i),v=find(j);
//            if(a==1){
//                if(u!=v) fa[u]=v;
//            }
//        }
//    }
//    sort(fa+1,fa+n+1);
//    int ans=unique(fa+1,fa+n+1)-fa-1;
//    cout<<ans;
//    return 0;
//}
//
//
//
//
//
//
//Problem ID: 9324 亲戚
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,p;
//int fa[10001];
//int find(int x) {
//	if(fa[x]==x) return x;
//	return fa[x]=find(fa[x]);
//}
//int main() {
//	scanf("%d%d%d",&n,&m,&p);
//	for(int i=1; i<=n; i++) fa[i]=i;
//	for(int i=1; i<=m; i++) {
//		int m1,m2;
//		scanf("%d%d",&m1,&m2);
//		int u=find(m1);
//		int v=find(m2);
//		if(u!=v) fa[u]=v;
//	}
//	for(int i=1; i<=p; i++) {
//		int p1,p2;
//		scanf("%d%d",&p1,&p2);
//		int u=find(p1);
//		int v=find(p2);
//		if(u!=v)cout<<"No"<<endl;
//		else printf("Yes\n");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//Problem ID: 7265 Kruskal最小生成树
//#include<bits/stdc++.h>
//using namespace std;
//long long n,m,fa[200001];
//struct aa{
//	long long x,y,z;
//}a[200001];
//bool cmp(aa x,aa y){
//	return x.z<y.z;
//}
//long long find(long long x){
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//int main(){
//	scanf("%lld%lld",&n,&m);
//	for(long long i=1;i<=m;i++) fa[i]=i;
//	for(long long i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
//	sort(a+1,a+m+1,cmp);
//	long long ans=0;
//	for(long long i=1;i<=m;i++){
//		long long u=find(a[i].x);
//		long long v=find(a[i].y);
//		long long w=a[i].z;
//		if(u!=v){
//			fa[v]=u;
//			ans+=w;
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//Problem ID: 7266 Prim最小生成树
//#include<bits/stdc++.h>
//using namespace std;
//long long n,m;
//bool vis[200001];
//struct aa {
//	long long v,w;
//	bool operator<(const aa &q)const{
//		return w > q.w;
//	}
//};
//vector <aa> P[200001];
//priority_queue <aa> C;
//int main() {
//	scanf("%lld%lld",&n,&m);
//	for(long long i=1; i<=m; i++) {
//		long long x,y,z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		P[x].push_back((aa) {y,z});
//		P[y].push_back((aa) {x,z});
//	}
//	for(long long i=0; i<P[1].size(); i++) C.push(P[1][i]);
//	vis[1]=true;
//	long long ans=0;
//	while(!C.empty()) {
//		aa p=C.top();
//		C.pop();
//		if(vis[p.v]==true) continue;
//		vis[p.v]=true;
//		ans+=p.w;
//		for(long long i=0; i<P[p.v].size(); i++) {
//			aa pp=P[p.v][i];
//			if(!vis[pp.v]) C.push(pp);
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//Problem ID: 8209 修路
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,a[1001][1001];
//struct aa{
//	int v,w;
//	bool operator<(const aa &q)const{
//		return w > q.w;
//	}
//};
//vector <aa> P[10001];
//priority_queue <aa> C;
//bool vis[10001];
//int main(){
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			scanf("%d",&a[i][j]);
//	scanf("%d",&m);
//	for(int i=1;i<=m;i++){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		a[x][y]=0;
//		a[y][x]=0;
//	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			P[j].push_back((aa){i,a[i][j]});
//	for(int i=0;i<P[1].size();i++) C.push(P[1][i]);
//	vis[1]=1;
//	int ans=0;
//	while(!C.empty()){
//		aa p=C.top();
//		C.pop();
//		if(vis[p.v]==true) continue;
//		vis[p.v]=true;
//		ans+=p.w;
//		for(int i=0;i<P[p.v].size();i++){
//			aa pp=P[p.v][i];
//			if(!vis[pp.v]) C.push(pp);
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//Problem ID: 7500 [模板]Floyd算法 
//#include<bits/stdc++.h>
//#define mod 80112002
//using namespace std;
//int n,a[1001][1001];
//int ans[1001][1001];
//int main(){
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			scanf("%d",&a[i][j]);
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(a[i][j]>a[i][k]+a[k][j]){
//					if(i==j){
//						cout<<"No Solution";
//						return 0;
//					}
//					a[i][j]=a[i][k]+a[k][j];
//				}
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//Problem ID: 7511 [模板]Dijkstra算法
//#include<bits/stdc++.h>
//using namespace std;
//struct aa{
//	long long x;
//	long long w;
//	bool operator<(const aa &q)const{
//		return w > q.w;
//	}
//};
//long long n,m,ans[1000001];
//vector <aa> P[1000001];
//priority_queue <aa> C;
//bool vis[1000001];
//int main(){
//	scanf("%lld%lld",&n,&m);
//	for(long long i=1;i<=n;i++) ans[i]=1e9;
//	for(long long i=1;i<=m;i++){
//		long long x,y;
//		long long z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		P[x].push_back((aa){y,z});
//	}
//	C.push((aa){1,0});
//	while(!C.empty()){
//		aa pc=C.top();
//		C.pop();
//		if(vis[pc.x]==true) continue;
//		vis[pc.x]=true;
//		ans[pc.x]=pc.w;
//		for(long long i=0;i<P[pc.x].size();i++) {
//			aa r=P[pc.x][i];
//			if(!vis[r.x]) C.push((aa){r.x,pc.w+r.w});
//		}
//	}
//	for(long long i=1;i<=n;i++){
//		if(ans0[i]==1e9) cout<<"inf"<<" ";
//		else cout<<ans[i]<<" ";
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Problem ID: 1071 判断负环
//#include<bits/stdc++.h>
//using namespace std;
//#define maxn 10001
//struct edge {
//	int v, w;
//};
//vector<edge> e[maxn];
//int dis[maxn], cnt[maxn], vis[maxn];
//queue<int> q;
//bool spfa(int n, int s) {
//	memset(cnt,0,sizeof(cnt));
//	memset(vis,0,sizeof(vis));
//	memset(dis, 63, sizeof(dis));
//	dis[s] = 0, vis[s] = 1;
//	while (!q.empty()) q.pop();
//	q.push(s);
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop(), vis[u] = 0;
//		for (int i=0;i<e[u].size();i++) {
//			edge ed=e[u][i];
//			int v = ed.v, w = ed.w;
//			if (dis[v] > dis[u] + w) {
//				dis[v] = dis[u] + w;
//				cnt[v] = cnt[u] + 1;
//				if (cnt[v] >= n) return false;
//				if (!vis[v]) q.push(v), vis[v] = 1;
//			}
//		}
//	}
//	return true;
//}
//int main() {
//	int cas;
//	scanf("%d",&cas);
//	while(cas--) {
//		int a,b;
//		scanf("%d%d",&a,&b);
//		for (int i(1); i <= a; ++i) e[i].clear();
//		for(int i=1; i<=b; i++) {
//			int x,y,z;
//			scanf("%d%d%d",&x,&y,&z);
//			e[x].push_back((edge) {y,z});
//		}
//		bool k=0;
//		for(int i=1; i<=a; i++) {
//			if(spfa(b*3,i)==false) {
//				printf("YES\n");
//				k=1;
//				break;
//			}
//		}
//		if(k==0) printf("NO\n");
//	}
//	return 0;
//}
//
//
//
//
//
//
//Problem ID: 1063 SPFA or bellman_ford
//#include<bits/stdc++.h>
//#define maxn 10001
//using namespace std;
//struct edge {
//	int v, w;
//};
//vector<edge> e[maxn];
//int dis[maxn],cnt[maxn],vis[maxn],ans[maxn],pc[maxn];
//queue<int> q;
//const int inf = 0x3f3f3f3f;
//bool bellmanford(int n, int s) {
//	memset(dis, 63, sizeof(dis));
//	dis[s] = 0;
//	bool flag;
//	for (int i = 1; i <= n; i++) {
//		flag = false;
//		for (int u = 1; u <= n; u++) {
//			if (dis[u] == inf) continue;
//			for (int j=0;j<e[u].size();j++) {
//				edge ed=e[u][j];
//				int v = ed.v, w = ed.w;
//				if (dis[v] > dis[u] + w) {
//					pc[ed.v]=u;
//					dis[v] = dis[u] + w;
//					flag = true;
//				}
//			}
//		}
//		if (!flag) break;
//	}
//	return flag;
//}
//int main() {
//	int a,b,s,t;
//	scanf("%d%d",&s,&t);
//	scanf("%d%d",&a,&b);
//	for(int i=1; i<=b; i++) {
//		int x,y,z;
//		scanf("%d%d%d",&x,&y,&z);
//		e[x].push_back((edge) {y,z});
//	}
//	bool flag=bellmanford(b,s);
//	if(flag==true) {
//		cout<<"You show me the wrong map!";
//		return 0;
//	}
//	cout<<dis[t]<<endl;
//	int u=t,c=0;
//	ans[++c]=t;
//	while(pc[u]!=s){
//		ans[++c]=pc[u];
//		u=pc[u];
//	}
//	cout<<s<<" ";
//	for(int i=c;i>=1;i--) cout<<ans[i]<<" ";
//	return 0;
//}
//
//
//
//
//
//Problem ID: 7506 [模板]Bellman-Ford算法
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct aa {
//	int u,w;
//};
//vector <aa> P[20001];
//queue <int> C;
//int n,m,vis[20001],cnt[20001],dis[20001];
//bool spfa(int x,int s) {
//	for(int i=1;i<=x;i++) dis[i]=1e18;
//	dis[s]=0;
//	vis[s]=1;
//	C.push(s);
//	while(!C.empty()) {
//		int u=C.front();
//		C.pop();
//		vis[u]=0;
//		for(int i=0; i<P[u].size(); i++) {
//			aa pc=P[u][i];
//			if(dis[pc.u]>dis[u]+pc.w) {
//				dis[pc.u]=dis[u]+pc.w;
//				cnt[pc.u]=cnt[u]+1;
//				if(cnt[pc.u]>=x) return false;
//				if(!vis[pc.u]) {
//					C.push(pc.u);
//					vis[pc.u]=1;
//				}
//			}
//		}
//	}
//	return true;
//}
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1; i<=m; i++) {
//		int x,y,z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		P[x].push_back((aa) {y,z});
//	}
//	bool flag=spfa(n,1);
//	if(flag==false) {
//		cout<<"Error!";
//		return 0;
//	} else {
//		for(int i=1; i<=n; i++) {
//			if(dis[i]==1e18) cout<<"inf ";
//			else cout<<dis[i]<<" ";
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//Problem ID: 1062
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int s1,t1,s2,t2,n,m,cnt[40001],ans[40001],pc[40001],r[40001];
//struct aa {
//	int v,w;
//	bool operator<(const aa i) const { return v > i.v; }
//};
//vector <aa> P[40001];
//queue <int> C;
//bool vis[10001];
//bool spfa(int x,int s) {
//	for(int i=1; i<=n; i++) ans[i]=1e18;
//	memset(vis,0,sizeof(vis));
//	while(!C.empty()) C.pop();
//	memset(cnt,0,sizeof(cnt));
//	memset(pc,0,sizeof(pc));
//	ans[s]=0;
//	vis[s]=1;
//	C.push(s);
//	while(!C.empty()) {
//		int c=C.front();
//		C.pop();
//		vis[c]=0;
//		for(int i=0; i<P[c].size(); i++) {
//			aa p=P[c][i];
//			int v=p.v;
//			int w=p.w;
//			if(ans[v]>ans[c]+w) {
//				pc[v]=c;
//				ans[v]=ans[c]+w;
//				cnt[v]=cnt[c]+1;
//				if(cnt[v]>=x) return false;
//				if(!vis[v]) {
//					C.push(v);
//					vis[v]=1;
//				}
//			}
//		}
//	}
//	return true;
//}
//signed main() {
//	scanf("%lld%lld%lld%lld%lld%lld",&s1,&t1,&s2,&t2,&n,&m);
//	for(int i=1; i<=m; i++) {
//		int x,y,z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		P[x].push_back((aa) {y,z});
//		P[y].push_back((aa) {x,z});
//	}
//	spfa(n,s1);
//	printf("%lld\n",ans[t1]);
//	int u,c;
//	u=t1,c=0;
//	r[++c]=t1;
//	while(pc[u]!=s1){
//		r[++c]=pc[u];
//		u=pc[u];
//	}
//	cout<<s1<<" ";
//	for(int i=c;i>=1;i--) printf("%lld ",r[i]);
//	cout<<endl;
//	spfa(n,s2);
//	memset(r,0,sizeof(r));
//	cout<<ans[t2]<<endl;
//	u=t2,c=0;
//	r[++c]=t2;
//	while(pc[u]!=s2){
//		r[++c]=pc[u];
//		u=pc[u];
//	}
//	cout<<s2<<" ";
//	for(int i=c;i>=1;i--) printf("%lld ",r[i]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Problem ID: 7754 翻转链表
//Problem ID: 7760 数组模拟链表
//#include<bits/stdc++.h>
//using namespace std;
//int n,a[2000001];
//int nxt[2000001],pre[2000001];
//int main(){
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++) {
//		scanf("%d",&a[i]);
//		nxt[i]=i+1;
//		pre[i]=i-1;
//	}
//	int t=1;
//	while(a[nxt[t]]!=0) t=nxt[t];
//	while(a[t]!=0){
//		cout<<a[t]<<" ";
//		t=pre[t];
//	}
//	return 0;
//}
//
//
//
//
//
//
//Problem ID: 1468 乒乓球
//#include<bits/stdc++.h>
//using namespace std;
//char s[100001],c;
//int len=0;
//int main(){
//	while(c!='E'){
//		scanf("%c",&c);
//		s[++len]=c;
//	}
//	int sum1=0,sum2=0;
//	for(int i=1;i<len;i++){
//		if(s[i]=='W') sum1++;
//		if(s[i]=='L') sum2++;
//		if((sum1==11||sum2==11)&&abs(sum1-sum2)>1) {
//			printf("%d:%d\n",sum1,sum2);
//			sum1=0;
//			sum2=0;
//		}
//	}
//	printf("%d:%d\n",sum1,sum2);
//	sum1=0,sum2=0;
//	for(int i=0;i<len;i++){
//		if(s[i]=='W') sum1++;
//		if(s[i]=='L') sum2++;
//		if((sum1==21||sum2==21)&&abs(sum1-sum2)>1) {
//			printf("%d:%d\n",sum1,sum2);
//			sum1=0;
//			sum2=0;
//		}
//	}
//	printf("%d:%d",sum1,sum2);
//	return 0;
//}
//
//
//
//
//
//
//Problem ID: 3315 国际象棋的挑战
//#include<bits/stdc++.h>
//using namespace std;
//string s,s2;
//char c1[50]={"+---+---+---+---+---+---+---+---+"};
//char H[50]={"|...|:::|...|:::|...|:::|...|:::|"};//8
//char G[50]={"|:::|...|:::|...|:::|...|:::|...|"};//7
//char F[50]={"|...|:::|...|:::|...|:::|...|:::|"};//6
//char E[50]={"|:::|...|:::|...|:::|...|:::|...|"};//5
//char D[50]={"|...|:::|...|:::|...|:::|...|:::|"};//4
//char C[50]={"|:::|...|:::|...|:::|...|:::|...|"};//3
//char B[50]={"|...|:::|...|:::|...|:::|...|:::|"};//2
//char A[50]={"|:::|...|:::|...|:::|...|:::|...|"};//1
//int main(){
//    getline(cin,s);
//    if(s[0]=='W')
//    {
//        int len=s.size();
//        for(int i=7;i<len;i++){
//            if(s[i]=='K'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='K';
//                if(s[i+2]=='2') B[l]='K';
//                if(s[i+2]=='3') C[l]='K';
//                if(s[i+2]=='4') D[l]='K';
//                if(s[i+2]=='5') E[l]='K';
//                if(s[i+2]=='6') F[l]='K';
//                if(s[i+2]=='7') G[l]='K';
//                if(s[i+2]=='8') H[l]='K';
//            }
//            if(s[i]=='Q'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='Q';
//                if(s[i+2]=='2') B[l]='Q';
//                if(s[i+2]=='3') C[l]='Q';
//                if(s[i+2]=='4') D[l]='Q';
//                if(s[i+2]=='5') E[l]='Q';
//                if(s[i+2]=='6') F[l]='Q';
//                if(s[i+2]=='7') G[l]='Q';
//                if(s[i+2]=='8') H[l]='Q';
//            }
//            if(s[i]=='R'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='R';
//                if(s[i+2]=='2') B[l]='R';
//                if(s[i+2]=='3') C[l]='R';
//                if(s[i+2]=='4') D[l]='R';
//                if(s[i+2]=='5') E[l]='R';
//                if(s[i+2]=='6') F[l]='R';
//                if(s[i+2]=='7') G[l]='R';
//                if(s[i+2]=='8') H[l]='R';
//            }
//            if(s[i]=='B'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='B';
//                if(s[i+2]=='2') B[l]='B';
//                if(s[i+2]=='3') C[l]='B';
//                if(s[i+2]=='4') D[l]='B';
//                if(s[i+2]=='5') E[l]='B';
//                if(s[i+2]=='6') F[l]='B';
//                if(s[i+2]=='7') G[l]='B';
//                if(s[i+2]=='8') H[l]='B';
//            }
//            if(s[i]=='N'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='N';
//                if(s[i+2]=='2') B[l]='N';
//                if(s[i+2]=='3') C[l]='N';
//                if(s[i+2]=='4') D[l]='N';
//                if(s[i+2]=='5') E[l]='N';
//                if(s[i+2]=='6') F[l]='N';
//                if(s[i+2]=='7') G[l]='N';
//                if(s[i+2]=='8') H[l]='N';
//            }
//            if(s[i]==','&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='P';
//                if(s[i+2]=='2') B[l]='P';
//                if(s[i+2]=='3') C[l]='P';
//                if(s[i+2]=='4') D[l]='P';
//                if(s[i+2]=='5') E[l]='P';
//                if(s[i+2]=='6') F[l]='P';
//                if(s[i+2]=='7') G[l]='P';
//                if(s[i+2]=='8') H[l]='P';
//            }
//        }
//    }
//    else
//    {
//        int len=s.size();
//        for(int i=7;i<len;i++){
//            if(s[i]=='K'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='k';
//                if(s[i+2]=='2') B[l]='k';
//                if(s[i+2]=='3') C[l]='k';
//                if(s[i+2]=='4') D[l]='k';
//                if(s[i+2]=='5') E[l]='k';
//                if(s[i+2]=='6') F[l]='k';
//                if(s[i+2]=='7') G[l]='k';
//                if(s[i+2]=='8') H[l]='k';
//            }
//            if(s[i]=='Q'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='q';
//                if(s[i+2]=='2') B[l]='q';
//                if(s[i+2]=='3') C[l]='q';
//                if(s[i+2]=='4') D[l]='q';
//                if(s[i+2]=='5') E[l]='q';
//                if(s[i+2]=='6') F[l]='q';
//                if(s[i+2]=='7') G[l]='q';
//                if(s[i+2]=='8') H[l]='q';
//            }
//            if(s[i]=='R'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='r';
//                if(s[i+2]=='2') B[l]='r';
//                if(s[i+2]=='3') C[l]='r';
//                if(s[i+2]=='4') D[l]='r';
//                if(s[i+2]=='5') E[l]='r';
//                if(s[i+2]=='6') F[l]='r';
//                if(s[i+2]=='7') G[l]='r';
//                if(s[i+2]=='8') H[l]='r';
//            }
//            if(s[i]=='B'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='b';
//                if(s[i+2]=='2') B[l]='b';
//                if(s[i+2]=='3') C[l]='b';
//                if(s[i+2]=='4') D[l]='b';
//                if(s[i+2]=='5') E[l]='b';
//                if(s[i+2]=='6') F[l]='b';
//                if(s[i+2]=='7') G[l]='b';
//                if(s[i+2]=='8') H[l]='b';
//            }
//            if(s[i]=='N'&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='n';
//                if(s[i+2]=='2') B[l]='n';
//                if(s[i+2]=='3') C[l]='n';
//                if(s[i+2]=='4') D[l]='n';
//                if(s[i+2]=='5') E[l]='n';
//                if(s[i+2]=='6') F[l]='n';
//                if(s[i+2]=='7') G[l]='n';
//                if(s[i+2]=='8') H[l]='n';
//            }
//            if(s[i]==','&&'a'<=s[i+1]<='z') {
//                int l=2+int(s[i+1]-'a')*4;
//                if(s[i+2]=='1') A[l]='p';
//                if(s[i+2]=='2') B[l]='p';
//                if(s[i+2]=='3') C[l]='p';
//                if(s[i+2]=='4') D[l]='p';
//                if(s[i+2]=='5') E[l]='p';
//                if(s[i+2]=='6') F[l]='P';
//                if(s[i+2]=='7') G[l]='p';
//                if(s[i+2]=='8') H[l]='p';
//            }
//        }
//    }
//    getline(cin,s2);
//    if(s2[0]=='W'){
//        int len=s2.size();
//        for(int i=7;i<len;i++){
//            if(s2[i]=='K'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='K';
//                if(s2[i+2]=='2') B[l]='K';
//                if(s2[i+2]=='3') C[l]='K';
//                if(s2[i+2]=='4') D[l]='K';
//                if(s2[i+2]=='5') E[l]='K';
//                if(s2[i+2]=='6') F[l]='K';
//                if(s2[i+2]=='7') G[l]='K';
//                if(s2[i+2]=='8') H[l]='K';
//            }
//            if(s2[i]=='Q'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='Q';
//                if(s2[i+2]=='2') B[l]='Q';
//                if(s2[i+2]=='3') C[l]='Q';
//                if(s2[i+2]=='4') D[l]='Q';
//                if(s2[i+2]=='5') E[l]='Q';
//                if(s2[i+2]=='6') F[l]='Q';
//                if(s2[i+2]=='7') G[l]='Q';
//                if(s2[i+2]=='8') H[l]='Q';
//            }
//            if(s2[i]=='R'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='R';
//                if(s2[i+2]=='2') B[l]='R';
//                if(s2[i+2]=='3') C[l]='R';
//                if(s2[i+2]=='4') D[l]='R';
//                if(s2[i+2]=='5') E[l]='R';
//                if(s2[i+2]=='6') F[l]='R';
//                if(s2[i+2]=='7') G[l]='R';
//                if(s2[i+2]=='8') H[l]='R';
//            }
//            if(s2[i]=='B'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='B';
//                if(s2[i+2]=='2') B[l]='B';
//                if(s2[i+2]=='3') C[l]='B';
//                if(s2[i+2]=='4') D[l]='B';
//                if(s2[i+2]=='5') E[l]='B';
//                if(s2[i+2]=='6') F[l]='B';
//                if(s2[i+2]=='7') G[l]='B';
//                if(s2[i+2]=='8') H[l]='B';
//            }
//            if(s2[i]=='N'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='N';
//                if(s2[i+2]=='2') B[l]='N';
//                if(s2[i+2]=='3') C[l]='N';
//                if(s2[i+2]=='4') D[l]='N';
//                if(s2[i+2]=='5') E[l]='N';
//                if(s2[i+2]=='6') F[l]='N';
//                if(s2[i+2]=='7') G[l]='N';
//                if(s2[i+2]=='8') H[l]='N';
//            }
//            if(s2[i]==','&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='P';
//                if(s2[i+2]=='2') B[l]='P';
//                if(s2[i+2]=='3') C[l]='P';
//                if(s2[i+2]=='4') D[l]='P';
//                if(s2[i+2]=='5') E[l]='P';
//                if(s2[i+2]=='6') F[l]='P';
//                if(s2[i+2]=='7') G[l]='P';
//                if(s2[i+2]=='8') H[l]='P';
//            }
//        }
//    } else {
//        int len=s2.size();
//        for(int i=7;i<len;i++){
//            if(s2[i]=='K'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='k';
//                if(s2[i+2]=='2') B[l]='k';
//                if(s2[i+2]=='3') C[l]='k';
//                if(s2[i+2]=='4') D[l]='k';
//                if(s2[i+2]=='5') E[l]='k';
//                if(s2[i+2]=='6') F[l]='k';
//                if(s2[i+2]=='7') G[l]='k';
//                if(s2[i+2]=='8') H[l]='k';
//            }
//            if(s2[i]=='Q'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='q';
//                if(s2[i+2]=='2') B[l]='q';
//                if(s2[i+2]=='3') C[l]='q';
//                if(s2[i+2]=='4') D[l]='q';
//                if(s2[i+2]=='5') E[l]='q';
//                if(s2[i+2]=='6') F[l]='q';
//                if(s2[i+2]=='7') G[l]='q';
//                if(s2[i+2]=='8') H[l]='q';
//            }
//            if(s2[i]=='R'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='r';
//                if(s2[i+2]=='2') B[l]='r';
//                if(s2[i+2]=='3') C[l]='r';
//                if(s2[i+2]=='4') D[l]='r';
//                if(s2[i+2]=='5') E[l]='r';
//                if(s2[i+2]=='6') F[l]='r';
//                if(s2[i+2]=='7') G[l]='r';
//                if(s2[i+2]=='8') H[l]='r';
//            }
//            if(s2[i]=='B'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='b';
//                if(s2[i+2]=='2') B[l]='b';
//                if(s2[i+2]=='3') C[l]='b';
//                if(s2[i+2]=='4') D[l]='b';
//                if(s2[i+2]=='5') E[l]='b';
//                if(s2[i+2]=='6') F[l]='b';
//                if(s2[i+2]=='7') G[l]='b';
//                if(s2[i+2]=='8') H[l]='b';
//            }
//            if(s2[i]=='N'&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='n';
//                if(s2[i+2]=='2') B[l]='n';
//                if(s2[i+2]=='3') C[l]='n';
//                if(s2[i+2]=='4') D[l]='n';
//                if(s2[i+2]=='5') E[l]='n';
//                if(s2[i+2]=='6') F[l]='n';
//                if(s2[i+2]=='7') G[l]='n';
//                if(s2[i+2]=='8') H[l]='n';
//            }
//            if(s2[i]==','&&'a'<=s2[i+1]<='z') {
//                int l=2+int(s2[i+1]-'a')*4;
//                if(s2[i+2]=='1') A[l]='p';
//                if(s2[i+2]=='2') B[l]='p';
//                if(s2[i+2]=='3') C[l]='p';
//                if(s2[i+2]=='4') D[l]='p';
//                if(s2[i+2]=='5') E[l]='p';
//                if(s2[i+2]=='6') F[l]='P';
//                if(s2[i+2]=='7') G[l]='p';
//                if(s2[i+2]=='8') H[l]='p';
//            }
//        }
//    }
//    for(int i=0;i<=32;i++) cout<<c1[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<H[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<c1[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<G[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<c1[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<F[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<c1[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<E[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<c1[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<D[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<c1[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<C[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<c1[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<B[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<c1[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<A[i];
//    cout<<endl;
//    for(int i=0;i<=32;i++) cout<<c1[i];
//    cout<<endl;
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//P1144 最短路计数
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//vector <int> P[1000001];
//queue <int> C;
//int vis[100001],ans[100001],dep[100001];
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=m;i++){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		if(x==y) continue;
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	C.push(1);
//	vis[1]=1;
//	ans[1]=1;
//	dep[1]=0;
//	while(!C.empty()){
//		int p=C.front();
//		C.pop();
//		for(int i=0;i<P[p].size();i++){
//			int c=P[p][i];
//			if(vis[c]==0) {
//				vis[c]=1;
//				dep[c]=dep[p]+1;
//				C.push(c);
//			}
//			if(dep[c]==dep[p]+1) ans[c]=(ans[c]+ans[p])%100003;
//		}
//	}
//	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//P2626 斐波那契数列（升级版）
//#include<bits/stdc++.h>
//using namespace std;
//int n,k=0;
//long long a[10001],ans[100001];
//int main(){
//	scanf("%d",&n);
//	a[1]=1;
//	a[2]=1;
//	for(int i=3;i<=n;i++) a[i]=(a[i-1]+a[i-2])%2147483648;
//	cout<<a[n]<<"=";
//	long long p=a[n];
//	for(int i=2;i<=p;i++){
//		while(p%i==0){
//			ans[++k]=i;
//			p/=i;
//		}
//	}
//	for(int i=1;i<k;i++) cout<<ans[i]<<"*";
//	cout<<ans[k];
//	return 0;
//}
//
//
//
//
//
//
//
//P8218 【深进1.例1】求区间和
//#include<bits/stdc++.h>
//using namespace std;
//int n,a[100001],m;
//int sum[100001];
//signed main(){
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++){
//		scanf("%d",&a[i]);
//		sum[i]=sum[i-1]+a[i];
//	}
//	scanf("%d",&m);
//	for(int i=1;i<=m;i++){
//		int l,r;
//		scanf("%d%d",&l,&r);
//		printf("%d\n",sum[r]-sum[l-1]);
//	}
//	return 0;
//} 
//
//
//
//
//
//P3385 【模板】负环
//#include<bits/stdc++.h>
//using namespace std;
//#define maxn 10001
//struct edge {
//	int v, w;
//};
//vector<edge> e[maxn];
//int dis[maxn], cnt[maxn], vis[maxn];
//queue<int> q;
//bool spfa(int n, int s) {
//	memset(cnt,0,sizeof(cnt));
//	memset(vis,0,sizeof(vis));
//	memset(dis, 63, sizeof(dis));
//	dis[s] = 0, vis[s] = 1;
//	while (!q.empty()) q.pop();
//	q.push(s);
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop(), vis[u] = 0;
//		for (int i=0; i<e[u].size(); i++) {
//			edge ed=e[u][i];
//			int v = ed.v, w = ed.w;
//			if (dis[v] > dis[u] + w) {
//				dis[v] = dis[u] + w;
//				cnt[v] = cnt[u] + 1;
//				if (cnt[v] >= n) return false;
//				if (!vis[v]) q.push(v), vis[v] = 1;
//			}
//		}
//	}
//	return true;
//}
//int main() {
//	int cas;
//	scanf("%d",&cas);
//	while(cas--) {
//		int a,b;
//		scanf("%d%d",&a,&b);
//		for (int i(1); i <= a; ++i) e[i].clear();
//		for(int i=1; i<=b; i++) {
//			int x,y,z;
//			scanf("%d%d%d",&x,&y,&z);
//			if(z>=0){
//				e[x].push_back((edge) {y,z});
//				e[y].push_back((edge) {x,z});
//			}
//			else e[x].push_back((edge) {y,z});
//		}
//		bool k=0;
//		if(spfa(b*3,1)==false) {
//			printf("YES\n");
//			k=1;
//		}
//		if(k==0) printf("NO\n");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//B3647 【模板】Floyd 算法
//#include<bits/stdc++.h>
//using namespace std;
//int f[505][505];
//int main() {
//	int n,m;
//	cin>>n>>m;
//	memset(f,0x3f,sizeof(f));
//	for(int i=1; i<=m; i++) {
//		int x,y,z;
//		scanf("%d%d%d",&x,&y,&z);
//		f[x][y]=z;
//		f[y][x]=z;
//	}
//	for(int k=1; k<=n; k++)
//		for(int i=1; i<=n; i++)
//			for(int j=1; j<=n; j++){
//				if(i!=j) f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
//				else f[i][j]=0;
//			}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) cout<<f[i][j]<<' ';
//		cout<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//P3371	【模板】单源最短路径（弱化版）
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//struct aa {
//	int x,w;
//	bool operator<(const aa &q)const {
//		return w > q.w;
//	}
//};
//int n,m,ans[1000001],s;
//vector <aa> P[1000001];
//priority_queue <aa> C;
//bool vis[1000001];
//signed main() {
//	scanf("%lld%lld%lld",&n,&m,&s);
//	for(int i=1; i<=n; i++) ans[i]=1e9;
//	for(int i=1; i<=m; i++) {
//		int x,y,z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		P[x].push_back((aa){y,z});
//	}
//	ans[s]=0;
//	C.push((aa){s,0});
//	while(!C.empty()) {
//		int pc=C.top().x;
//		C.pop();
//		if(vis[pc]) continue;
//		vis[pc]=1;
//		for(int i=0; i<P[pc].size(); i++) {
//			aa r=P[pc][i];
//			if(!vis[r.x]&&ans[r.x]>ans[pc]+r.w){
//				ans[r.x]=ans[pc]+r.w;
//				C.push((aa) {r.x,ans[r.x]});
//			}
//		}
//	}
//	for(int i=1; i<=n; i++) {
//		if(ans[i]==1e9) cout<<2147483647<<" ";
//		else cout<<ans[i]<<" ";
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//Problem ID: 1757 四面楚歌
//#include<bits/stdc++.h>
//using namespace std;
//string n,m;
//int an[100001];
//int am[100001];
//int ans[100001];
//int main() {
//	cin>>n>>m;
//	int lenn=n.size();
//	int lenm=m.size();
//	for(int i=0; i<lenn; i++) an[i]=n[lenn-i-1]-'0';
//	for(int i=0; i<lenm; i++) am[i]=m[lenm-i-1]-'0';
//	an[0]++;
//	lenn++;
//	lenm++;
//	for(int i=0; i<lenn; i++) {
//		if(an[i]>=10) {
//			an[i]%=10;
//			an[i+1]++;
//		}
//	}
//	for(int i=0; i<max(lenn,lenm); i++) {
//		ans[i]+=an[i]+am[i];
//		if(ans[i]>=10) {
//			ans[i]%=10;
//			ans[i+1]++;
//		}
//	}
//	bool flag=true;
//	for(int i=max(lenn,lenm)-1; i>=0; i--) {
//		if(ans[i]!=0) flag=false;
//		if(flag==false) cout<<ans[i];
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//P4568 [JLOI2011] 飞行路线
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,k,s,t,W=0,ans[100001][12],vis[100001][12];
//struct aa {
//	int u,w,floor;
//	bool operator<(const aa &q)const {
//		return w > q.w;
//	}
//};
//vector <aa> P[100001][12];
//priority_queue <aa> C;
//void d(int x) {
//	C.push((aa){x,0,1});
//	ans[x][1]=0;
//	while(!C.empty()) {
//		aa pc=C.top();
//		C.pop();
//		if(vis[pc.u][pc.floor]==1) continue;
//		vis[pc.u][pc.floor]=1;
//		for(int i=0; i<P[pc.u][pc.floor].size(); i++) {
//			aa r=P[pc.u][pc.floor][i];
//			if(!vis[r.u][r.floor]&&ans[r.u][r.floor]>ans[pc.u][pc.floor]+r.w) {
//				ans[r.u][r.floor]=ans[pc.u][pc.floor]+r.w;
//				C.push((aa) {r.u,ans[r.u][r.floor],r.floor});
//			}
//		}
//	}
//}
//signed main() {
//	scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
//	s++,t++;
//	memset(vis,0,sizeof(vis));
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=k+1;j++)
//			ans[i][j]=1e9;
//	for(int i=1; i<=m; i++) {
//		int x,y,z;
//		scanf("%d%d%d",&x,&y,&z);
//		x++;
//		y++;
//		for(int j=1; j<=k+1; j++) {
//			P[x][j].push_back((aa) {y,z,j});
//			P[y][j].push_back((aa) {x,z,j});
//			P[x][j].push_back((aa) {x,0,j+1});
//			P[y][j].push_back((aa) {y,0,j+1});
//			P[x][j].push_back((aa) {y,0,j+1});
//			P[y][j].push_back((aa) {x,0,j+1});
//		}
//	}
//	d(s);
//	cout<<ans[t][k+1];
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Homework CF101A
//#include<bits/stdc++.h>
//using namespace std;
//string s;
//char ss[100001];
//int k,cnt=0,p;
//bool vis[10001];
//struct aa {
//	int x;
//	char y;
//} a[10001];
//bool cmp1(aa q,aa w) {return q.x>w.x;}
//bool cmp2(aa q,aa w) {return q.x<w.x;}
//signed main() {
//	cin>>s>>k;
//	memset(vis,false,sizeof(vis));
//	int len=s.size();
//	for(int i=0; i<len; i++) {
//		if(vis[s[i]-'0'+1]==false) {
//			vis[s[i]-'0'+1]=true;
//			cnt++;
//		}
//	}
//	if(k==0) {
//		cout<<cnt<<endl<<s;
//		return 0;
//	}
//	for(int i=0; i<len; i++) {
//		a[s[i]-'a'+1].y=s[i];
//		a[s[i]-'a'+1].x++;
//		p=max(p,int(s[i]-'a'+1));
//	}
//	sort(a+1,a+p+1,cmp1);
//	for(int i=1; i<=p; i++) {
//		if(a[i].x==0) {
//			p=i-1;
//			break;
//		}
//	}
//	memset(vis,false,sizeof(vis));
//	sort(a+1,a+p+1,cmp2);
//	for(int i=1; i<=p; i++) {
//		if(a[i].x<=k&&a[i].x>0) {
//			k-=a[i].x;
//			a[i].x=0;
//		}
//		else if(a[i].x>=k&&k>0){
//			a[i].x-=k;
//			k=0;
//			break;
//		}
//	}
//	sort(a+1,a+p+1,cmp1);
//	for(int i=1; i<=p; i++) {
//		if(a[i].x==0) {
//			p=i-1;
//			break;
//		}
//	}
//	int o=0;
//	for(int i=0;i<len;i++){
//		for(int j=1;j<=p;j++) {
//			if(a[j].y==s[i]&&a[j].x>0) {
//				ss[++o]=s[i];
//				a[j].x--;
//			}
//		}
//	}
//	cnt=0;
//	for(int i=1;i<=o;i++) {
//		if(vis[ss[i]]==false) {
//			cnt++;
//			vis[ss[i]]=true;
//		}
//	}
//	cout<<cnt<<endl;
//	for(int i=1;i<=o;i++) cout<<ss[i];
//	return 0;
//}
//
//
//
//
//
//
//
//
//Clothes CF102A
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//int a[100001],sum=0;
//int p[1001][1001];
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//	for(int i=1;i<=m;i++){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		p[x][y]=1;
//		p[y][x]=1;
//	}
//	int ans=1e9;
//	for(int k=1;k<=n;k++)
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
//				if(p[i][j]==1&&p[i][k]==1&&p[k][j]==1&&i!=k&&j!=i&&k!=i)
//					ans=min(ans,a[i]+a[j]+a[k]);
//	if(ans==1e9) cout<<-1;
//	else cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Testing Pants for Sadness CF103A
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,a[1001],ans[1001];
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<=n;i++) ans[i]=ans[i-1]+a[i];
//	int cnt=ans[n];
//	for(int i=1;i<n;i++) cnt+=ans[n]-ans[i]-(n-i);
//	cout<<cnt;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//Cthulhu CF103B
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m;
//int p[1001][1001];
//bool vis[10001];
//void dfs(int x){
//	vis[x]=true;
//	for(int i=1;i<=n;i++)
//		if(vis[i]==false&&p[x][i]==1) 
//			dfs(i);
//}
//signed main(){
//	memset(vis,false,sizeof(vis));
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=m;i++){
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		p[x][y]=1;
//		p[y][x]=1;
//	}
//	if(n!=m){
//		cout<<"NO";
//		return 0;
//	}
//	dfs(1);
//	for(int i=1;i<=n;i++) {
//		if(vis[i]==false) {
//			cout<<"NO";
//			return 0;
//		}
//	}
//	cout<<"FHTAGN!";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Problem ID: 1762 方程
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,sum=0,prime[1000001],cnt[1000001],ans[1000001];
//signed main() {
//	for(int i=2; i<=100000; i++) {
//		bool flag=true;
//		for(int j=2; j<=sqrt(i); j++) {
//			if(i%j==0) {
//				flag=false;
//				break;
//			}
//		}
//		if(flag==true) prime[++sum]=i;
//	}
//	while(1) {
//		int z=0,len=1;
//		memset(ans,0,sizeof(ans));
//		memset(cnt,0,sizeof(cnt));
//		ans[1]=1;
//		scanf("%lld",&n);
//		if(n==0) break;
//		for(int i=2; i<=n; i++) {
//			int ii=i;
//			for(int j=1; j<=sum; j++) {
//				if(prime[j]>n) break;
//				while(ii>=1) {
//					if(ii%prime[j]!=0) break;
//					ii/=prime[j];
//					cnt[prime[j]]++;
//				}
//			}
//		}
//		for(int i=1; i<=sum; i++)
//			if(prime[i]>n) {
//				z=i-1;
//				break;
//			}
//		for(int i=1; i<=z;i++) {
//			for(int j=0; j<=len; j++) 
//				ans[j]*=(cnt[prime[i]]*2+1);
//			for(int j=0; j<=len; j++) {
//				if(ans[j]>=10) {
//					ans[j+1]+=ans[j]/10;
//					ans[j]=ans[j]%10;
//					if(j==len) len++;
//				}
//			}
//		}
//		for(int i=0;i<len;i++) cout<<ans[len-i];
//		cout<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//SOLDIERS - SOLDIERS SP10334
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 1000;
//struct bigInt {
//	int d[maxn], len;
//	void clean() {
//		while(len > 1 && !d[len-1]) len--;
//	}
//	bigInt(){
//		memset(d, 0, sizeof(d));
//		len = 1;
//	}
//	bigInt(int num){
//		*this = num;
//	}
//	bigInt(char* num){
//		*this = num;
//	}
//	bigInt operator = (const char* num) {
//		memset(d, 0, sizeof(d));
//		len = strlen(num);
//		for(int i = 0; i < len; i++) d[i] = num[len-1-i] - '0';
//		clean();
//		return *this;
//	}
//	bigInt operator = (int num) {
//		char s[20];
//		sprintf(s, "%d", num);
//		*this = s;
//		return *this;
//	}
//	bigInt operator + (const bigInt& b) {
//		bigInt c = *this;
//		int i;
//		for (i = 0; i < b.len; i++) {
//			c.d[i] += b.d[i];
//			if (c.d[i] > 9) c.d[i]%=10, c.d[i+1]++;
//		}
//		while (c.d[i] > 9) c.d[i++]%=10, c.d[i]++;
//		c.len = max(len, b.len);
//		if (c.d[i] && c.len <= i) c.len = i+1;
//		return c;
//	}
//	bigInt operator - (const bigInt& b) {
//		bigInt c = *this;
//		int i;
//		for (i = 0; i < b.len; i++) {
//			c.d[i] -= b.d[i];
//			if (c.d[i] < 0) c.d[i]+=10, c.d[i+1]--;
//		}
//		while (c.d[i] < 0) c.d[i++]+=10, c.d[i]--;
//		c.clean();
//		return c;
//	}
//	bigInt operator * (const bigInt& b)const {
//		int i, j;
//		bigInt c;
//		c.len = len + b.len;
//		for(j = 0; j < b.len; j++) for(i = 0; i < len; i++)
//				c.d[i+j] += d[i] * b.d[j];
//		for(i = 0; i < c.len-1; i++)
//			c.d[i+1] += c.d[i]/10, c.d[i] %= 10;
//		c.clean();
//		return c;
//	}
//	bigInt operator / (const bigInt& b) {
//		int i, j;
//		bigInt c = *this, a = 0;
//		for (i = len - 1; i >= 0; i--) {
//			a = a*10 + d[i];
//			for (j = 0; j < 10; j++) if (a < b*(j+1)) break;
//			c.d[i] = j;
//			a = a - b*j;
//		}
//		c.clean();
//		return c;
//	}
//	bigInt operator % (const bigInt& b) {
//		int i, j;
//		bigInt a = 0;
//		for (i = len - 1; i >= 0; i--) {
//			a = a*10 + d[i];
//			for (j = 0; j < 10; j++) if (a < b*(j+1)) break;
//			a = a - b*j;
//		}
//		return a;
//	}
//	bigInt operator += (const bigInt& b) {
//		*this = *this + b;
//		return *this;
//	}
//	bool operator <(const bigInt& b) const {
//		if(len != b.len) return len < b.len;
//		for(int i = len-1; i >= 0; i--)
//			if(d[i] != b.d[i]) return d[i] < b.d[i];
//		return false;
//	}
//	bool operator >(const bigInt& b) const {
//		return b < *this;
//	}
//	bool operator<=(const bigInt& b) const {
//		return !(b < *this);
//	}
//	bool operator>=(const bigInt& b) const {
//		return !(*this < b);
//	}
//	bool operator!=(const bigInt& b) const {
//		return b < *this || *this < b;
//	}
//	bool operator==(const bigInt& b) const {
//		return !(b < *this) && !(b > *this);
//	}
//	string str() const {
//		char s[maxn]= {};
//		for(int i = 0; i < len; i++) s[len-1-i] = d[i]+'0';
//		return s;
//	}
//};
//istream& operator >> (istream& in, bigInt& x) {
//	string s;
//	in >> s;
//	x = s.c_str();
//	return in;
//}
//ostream& operator << (ostream& out, const bigInt& x) {
//	out << x.str();
//	return out;
//}
//int main() {
//	bigInt a,b,t;
//	cin>>t;
//	while(t>0){
//		cin>>a>>b;
//		cout<<max((a+1)/2*b,(b+1)/2*a);
//		t=t-1;
//		puts("");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//Problem ID: 8787 从NOIP到CSP
//#include<bits/stdc++.h>
//using namespace std;
//string a;
//int main() {
//	cin>>a;
//	int len=a.size();
//	for(int i=0; i<len; i++) {
//		if((a[i]=='N'||a[i]=='n')&&(a[i+1]=='O'||a[i+1]=='o')&&(a[i+2]=='I'||a[i+2]=='i')&&(a[i+3]=='P'||a[i+3]=='p')) {
//			a[i]='C';
//			a[i+1]='S';
//			a[i+2]='P';
//			a[i+3]=' ';
//		}
//	}
//	for(int i=0; i<len; i++) {
//		if(a[i]!=' ') cout<<a[i];
//		else continue;
//	}
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//
//
//Problem ID: 8788 可持久化变量
//#include<bits/stdc++.h>
//using namespace std;
//int T,a[100001];
//int main() {
//	scanf("%d",&T);
//	a[0]=0;
//	for(int i=1;i<=T;i++){
//		string c;
//		int x;
//		cin>>c;
//		scanf("%d",&x);
//		if(c[0]=='A') a[i]=a[i-1]+x;
//		if(c[0]=='S'&&c[1]=='U') a[i]=a[i-1]-x;
//		if(c[0]=='S'&&c[1]=='E') a[i]=x;
//		if(c[0]=='B') a[i]=a[i-x-1];
//	}
//	for(int i=1;i<=T;i++) printf("%d ",a[i]);
//	return 0;
//}
//
//
//
//
//
//
//
//Problem ID: 8790 Modulus
//#include <bits/stdc++.h>
//using namespace std;
//const int MAXN=200005;
//long long n,a[MAXN],b[MAXN],RMQ[MAXN][22],L,R,m,len;
//int main() {
//    scanf("%lld %d",&n,&m);
//    for(long long l=1,r; l<=n; l=r+1) {
//        r=n/(n/l);
//        a[++len]=n%l;
//        b[len]=l;
//    }
//    for(int i=1; i<=len; ++i) RMQ[i][0]=a[i];
//    for(int i=1; i<=21; ++i) 
//        for(int j=1; j<=len; ++j) {
//            if(j+(1<<(i-1))<=len) RMQ[j][i]=max(RMQ[j][i-1],RMQ[j+(1<<(i-1))][i-1]);
//            else RMQ[j][i]=RMQ[j][i-1];
//        }
//    while(m--) {
//        scanf("%lld %lld",&L,&R);
//        int pos=lower_bound(b+1,b+1+len,L)-(b+1);
//        long long ans=n%L;
//        for(int i=21; ~i; --i) if(pos+(1<<i)<=len&&b[pos+(1<<i)]<=R) ans=max(ans,RMQ[pos+1][i]),pos+=(1<<i);
//        printf("%lld\n",ans);
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//P1255 数楼梯 
//#include <bits/stdc++.h>
//using namespace std;
//char sum[1200];
//int s=0,m=0,n,a[1200],b[1200],he,i;
//string s1,s2;
//int main() {
//	cin>>n;
//	n++;
//	s1="0",s2="1";
//	for(m=2; m<n+1; m++) {
//		memset(a,0,sizeof a);
//		memset(b,0,sizeof b);
//		a[0]=s1.length();
//		for(i=1; i<=a[0]; i++) a[i]=s1[a[0]-i]-'0';
//		b[0]=s2.length();
//		for(i=1; i<=b[0]; i++) b[i]=s2[b[0]-i]-'0';
//		he=(a[0]>b[0]?a[0]:b[0]);
//		for(i=1; i<=he; i++) {
//			a[i]+=b[i];
//			a[i+1]+=a[i]/10;
//			a[i]%=10;
//		}
//		he++;
//		while((a[he]==0)&&(he>1)) he--;
//		for(i=he,s=0; i>=1; i--,s++) sum[s]=a[i]+'0';
//		s1=s2,s2=sum;
//	}
//	cout<<s2<<endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//P5960 【模板】差分约束算法 
//#include<bits/stdc++.h>
//using namespace std;
//#define maxn 10001
//struct edge {
//	int v, w;
//};
//vector<edge> e[maxn];
//int dis[maxn], cnt[maxn], vis[maxn];
//queue<int> q;
//bool spfa(int n, int s) {
//	memset(cnt,0,sizeof(cnt));
//	memset(vis,0,sizeof(vis));
//	memset(dis, 63, sizeof(dis));
//	dis[s] = 0, vis[s] = 1;
//	while (!q.empty()) q.pop();
//	q.push(s);
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop(), vis[u] = 0;
//		for (int i=0;i<e[u].size();i++) {
//			edge ed=e[u][i];
//			int v = ed.v, w = ed.w;
//			if (dis[v] > dis[u] + w) {
//				dis[v] = dis[u] + w;
//				cnt[v] = cnt[u] + 1;
//				if (cnt[v] >= n+1) return false;
//				if (!vis[v]) q.push(v), vis[v] = 1;
//			}
//		}
//	}
//	return true;
//}
//int main() {
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=m;i++) {
//		int x,y,z;
//		scanf("%d%d%d",&x,&y,&z);
//		e[y].push_back({x,z});
//	}
//	for(int i=1;i<=n;i++)
//		e[0].push_back({i,0});
//	if(spfa(n,0)==false) cout<<"NO";
//	else for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
//	return 0;
//}
//
//
//
//
//
//
//
//Problem ID: 7169 树的直径
//#include<bits/stdc++.h>
//using namespace std;
//int n,vis[100001],ans[10001],sum=0;
//struct aa{
//	int v,w;
//};
//vector <aa> P[1000001];
//void dp(int x){
//	vis[x]=1;
//	for(int i=0;i<P[x].size();i++){
//		int pc=P[x][i].v;
//		if(vis[pc]) continue;
//		dp(pc);
//		sum=max(sum,ans[x]+ans[pc]+P[x][i].w);
//		ans[x]=max(ans[x],ans[pc]+P[x][i].w);
//	}
//}
//int main() {
//	scanf("%d",&n);
//	for(int i=1;i<n;i++) {
//		int x,y,z;
//		scanf("%d%d%d",&x,&y,&z);
//		P[x].push_back((aa){y,z});
//		P[y].push_back((aa){x,z});
//	}
//	dp(1);
//	cout<<sum;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Problem ID: 7170 树的重心
//#include<bits/stdc++.h>
//using namespace std;
//int n,vis[200001],size[200001],pos=0,ans=1e9;
//vector <int> P[20001];
//void dfs(int x){
//	vis[x]=1;
//	size[x]=1;
//	int max_part=0;
//	for(int i=0;i<P[x].size();i++) {
//		int pc=P[x][i];
//		if(vis[pc]) continue;
//		dfs(pc);
//		size[x]+=size[pc];
//		max_part=max(max_part,size[pc]);
//	}
//	max_part=max(max_part,n-size[x]);
//	if(max_part<ans) {
//		ans=max_part;
//		pos=x;
//	}
//}
//int main(){
//	scanf("%d",&n);
//	for(int i=1;i<n;i++) {
//		int x,y;
//		scanf("%d%d",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	dfs(1);
//	cout<<pos;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//Problem ID: 9506 没有上司的舞会
//#include<bits/stdc++.h>
//using namespace std;
//int n,r[100001],f[100001][2],vis[100001];
//vector <int> P[100001];
//void dp(int x) {
//	f[x][1]=r[x];
//	for(int i=0; i<P[x].size(); i++) {
//		int pc=P[x][i];
//		dp(pc);
//		f[x][0]+=max(f[pc][0],f[pc][1]);
//		f[x][1]+=f[pc][0];
//	}
//}
//int main() {
//	scanf("%d",&n);
//	for(int i=1; i<=n; i++) scanf("%d",&r[i]);
//	memset(vis,false,sizeof(vis));
//	for(int i=1; i<n; i++) {
//		int L,K;
//		scanf("%d%d",&L,&K);
//		P[K].push_back(L);
//		vis[L]=true;
//	}
//	int id=0;
//	for(int i=1;i<=n;i++) 
//		if(vis[i]==false) {
//			id=i;
//			break;
//	}
//	dp(id);
//	cout<<max(f[id][0],f[id][1]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//Problem ID: 7189 选课
//#include<bits/stdc++.h>
//using namespace std;
//int m,n,dp[1001][1001];
//struct aa{ int y,w; };
//vector <aa> P[100001];
//void dfs(int u,int tot){
//	for(int i=0;i<P[u].size();i++){
//		int v=P[u][i].y;
//		dfs(v,tot-1);
//		for(int j=tot;j>=1;j--){
//			for(int k=0;k<j;k++){
//				dp[u][j]=max(dp[u][j],dp[v][k]+dp[u][j-k-1]+P[u][i].w);
//			}
//		}
//	}
//}
//int main(){
//	scanf("%d%d",&m,&n);
//	int anss=0;
//	for(int i=1;i<=m;i++) {
//		int x,y;
//		scanf("%d%d",&x,&y);
//		P[x].push_back((aa){i,y});
//	}
//	dfs(0,n);
//	cout<<dp[0][n];
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//Problem ID: 8795 隐瞒成绩
//#include<bits/stdc++.h>
//using namespace std;
//long long a,b,c,d,p;
//int main() {
//	cin>>a>>b>>c>>d>>p;
//	for(long long i=100;i>=0;i--) {
//		long long aa=i*a;
//		long long bb=aa+b;
//		long long cc=int(bb/c);
//		long long dd=cc-d;
//		if(dd==p) {
//			printf("%lld",i);
//			break;
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Caesar's Legions CF118D
//#include<bits/stdc++.h>
//#define int long long
//#define mod 100000000
//using namespace std;
//int n1,n2,k1,k2;
//int dp[1001][1001][2];
//signed main() {
//	scanf("%lld%lld%lld%lld",&n1,&n2,&k1,&k2);
//	dp[0][0][0]=dp[0][0][1]=1;
//	for(int i=0;i<=n1;i++) {
//		for(int j=0;j<=n2;j++) {
//			for(int k=1;k<=i&&k<=k1;k++) dp[i][j][0]=(dp[i-k][j][1]+dp[i][j][0])%mod;
//			for(int k=1;k<=j&&k<=k2;k++) dp[i][j][1]=(dp[i][j-k][0]+dp[i][j][1])%mod;
//		}
//	}
//	cout<<(dp[n1][n2][0]+dp[n1][n2][1])%mod;
//	return 0;
//}
//
//
//
//
//
//
//
//
//Prime Path  UVA12101
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int isprime[20000],vis[10001],cnt,ans[10001];
//queue<int> C;
//void makeprime() {
//	for(int i=1000;i<=9999;i++) {
//		bool flag=true;
//		for(int j=2;j<=sqrt(i);j++) 
//			if(i%j==0) {
//				flag=false;
//				break;
//			}
//		if(flag==true) isprime[i]=1;
//	}
//}
//void chu() {
//	while(!C.empty()) C.pop();
//	memset(ans,0,sizeof(ans));
//	memset(vis,0,sizeof(vis));
//}
//void BFS(int x,int b) {
//	chu();
//	ans[x]=0;
//	vis[x]=1;
//	C.push(x);
//	bool flag=false;
//	while(!C.empty()) {
//		int now=C.front();
//		C.pop();
//		if(now==b) {
//			flag=true;
//			cout<<ans[now]<<endl;
//			return ;
//		}
//		int qian=now/1000,bai=now/100%10,shi=now/10%10,ge=now%10;
//		for(int i=1; i<=4; i++) {
//			for(int j=0; j<=9; j++) {
//				int nq=qian,nb=bai,ns=shi,ng=ge,noww;
//				if(j == 0 && i == 1) continue;
//				if(i==1) nq=j;
//				if(i==2) nb=j;
//				if(i==3) ns=j;
//				if(i==4) ng=j;
//				noww=nq*1000+nb*100+ns*10+ng;
//				if(vis[noww]==0&&isprime[noww]==1) {
//					C.push(noww);
//					vis[noww]=1;
//					ans[noww]=ans[now]+1;
//				}
//			}
//		}
//	}
//	if(flag==false) cout<<"Impossible"<<endl;
//}
//signed main() {
//	makeprime();
//	int T;
//	scanf("%lld",&T);
//	while(T--) {
//		int p,c;
//		scanf("%lld%lld",&p,&c);
//		if(p==c) {
//			printf("0\n");
//			continue;
//		} else BFS(p,c);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//B - 生日蛋糕 P1731 [NOI1999] 生日蛋糕
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m,minv[200001],mins[200001],ans=1e18;
//void dfs(int now,int s,int v,int lasth,int lastr){
//	if(now==0) {
//		if(v==n) ans=min(ans,s);
//		return ;
//	}
//	if(s+2*(n-v)/lastr>ans) return ;
//	if(v+minv[now]>n) return ;
//	if(s+mins[now]>ans) return ;
//	for(int i=lastr-1;i>=now;i--) {
//		if(now==m) s=i*i;
//		int maxh=min(lasth-1,(n-v-minv[now-1])/(i*i));
//		for(int j=maxh;j>=now;j--) dfs(now-1,s+2*i*j,v+i*i*j,j,i);
//	}
//}
//signed main(){
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=m;i++) {
//		minv[i]=minv[i-1]+i*i*i;
//		mins[i]=mins[i-1]+2*i*i;
//	}
//	int maxr=sqrt(n);
//	dfs(m,0,0,n,maxr);
//	if(ans==1e18) cout<<0;
//	else cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//T345474 「SFCOI-3」进行一个拆的解
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int T,n,a[100001];
//signed main() {
//	scanf("%lld",&T);
//	while(T--) {
//		scanf("%lld",&n);
//		bool flag=true;
//		for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
//		if(n%2!=0) {
//			int mid=n/2+1;
//			int j=mid+1;
//			for(int i=1; i<=mid&&j<=n; i++) if(a[i]==a[j]) j++;
//			if(j==n+1) flag=false;
//			if(flag==true) printf("YES\n");
//			else {
//				flag=true;
//				j=1;
//				for(int i=mid; i<=n&&j<mid; i++) if(a[i]==a[j]) j++;
//				if(j==mid) flag=false;
//				if(flag==true) printf("YES\n");
//				else {
//					flag=true;
//					j=mid+2;
//					for(int i=1;i<=mid+1&&j<=n;i++) if(a[i]==a[j]) j++;
//					if(j==n+1) flag=false;
//					if(flag==true) printf("YES\n");
//					else printf("NO\n");
//				}
//			}
//		} else {
//			int mid=n/2;
//			int j=mid+1;
//			for(int i=1;i<=mid&&j<=n;i++) if(a[i]==a[j]) j++;
//			if(j==n+1) flag=false;
//			if(flag==true) printf("YES\n");
//			else {
//				j=1;
//				flag=true;
//				for(int i=mid;i<=n&&j<mid;i++) if(a[i]==a[j]) j++;
//				if(j==mid) flag=false;
//				if(flag==true) printf("YES\n");
//				else {
//					flag=true;
//					j=mid+2;
//					for(int i=1;i<=mid+1&&j<=n;i++) if(a[i]==a[j]) j++;
//					if(j==n+1) flag=false;
//					if(flag==true) printf("YES\n");
//					else printf("NO\n");
//				}
//			}
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//P2865 [USACO06NOV] Roadblocks G 
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,r,ans1[1000001],ans2[100001];
//struct aa{
//	int v,w;
//	bool operator<(const aa &b) const {
//		return w>b.w;
//	}
//};
//vector<aa> P[100001];
//priority_queue<aa> C;
//void dij(){
//	C.push({1,0});
//	ans1[1]=0;
//	while(!C.empty()){
//		aa pc=C.top();
//		C.pop();
//		for(int i=0;i<P[pc.v].size();i++) {
//			bool flag=false;
//			aa r=P[pc.v][i];
//			if(ans1[r.v]>ans1[pc.v]+r.w) ans1[r.v]=ans1[pc.v]+r.w,flag=true;
//			if(ans1[r.v]<ans1[pc.v]+r.w&&ans2[r.v]>ans1[pc.v]+r.w) ans2[r.v]=ans1[pc.v]+r.w,flag=true;
//			if (ans2[pc.v]+r.w<ans2[r.v]) ans2[r.v]=ans2[pc.v]+r.w,flag=1;
//			if(flag==true) C.push({r.v,ans1[r.v]});
//		}
//	}
//}
//signed main(){
//	scanf("%lld%lld",&n,&r);
//	for(int i=1;i<=n;i++) ans1[i]=1e18,ans2[i]=1e18;
//	for(int i=1;i<=r;i++) {
//		int x,y,z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		P[x].push_back({y,z});
//		P[y].push_back({x,z});
//	}
//	dij();
//	cout<<ans2[n];
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//P5908 猫猫和企鹅 
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,d,ans=0;
//vector <int> P[1000001];
//bool vis[1000001];
//void dfs(int s,int step){
//	vis[s]=true;
//	if(step==d) return ;
//	for(int i=0;i<P[s].size();i++) {
//		if(vis[P[s][i]]!=true){
//			vis[P[s][i]]=true;
//			dfs(P[s][i],step+1);
//			ans++;
//		}
//	}
//}
//signed main(){
//	scanf("%lld%lld",&n,&d);
//	memset(vis,false,sizeof(vis));
//	for(int i=1;i<n;i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	dfs(1,0);
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//Theatre Square CF1A
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m,a;
//signed main(){
//	cin>>n>>m>>a;
//	int aa=0,bb=0;
//	if(n%a==0) aa=n/a;
//	else aa=n/a+1;
//	if(m%a==0)bb=m/a;
//	else bb=m/a+1;
//	cout<<aa*bb;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//Problem ID: 8834 统计子序列
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//string s,a;
//int n;
//signed main() {
//	cin>>s;
//	int lens=s.size(),sum=0;
//	scanf("%lld",&n);
//	while(n--) {
//		cin>>a;
//		int lena=a.size();
//		int j=0;
//		for(int i=0;i<lens&&j<lena;i++) {
//			if(s[i]==a[j]) j++;
//		}
//		if(j==lena) sum++;
//	}
//	printf("%lld",sum);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//Problem ID: 7176 战略游戏
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m,dp[1001][1001];
//struct aa{
//	int u,w;
//};
//vector <aa> P[100001];
//void dfs(int x,int cnt) {
//	for(int i=0;i<P[x].size();i++) {
//		aa pc=P[x][i];
//		for(int j=0;j<cnt;j++) dp[pc.u][j]=dp[x][j]+pc.w;
//		dfs(pc.u,cnt-1);
//		for(int j=1;j<=cnt;j++) dp[x][j]=max(dp[x][j],dp[pc.u][j-1]);
//	}
//}
//signed main(){
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=n;i++) {
//		int a,b;
//		scanf("%lld%lld",&a,&b);
//		P[a].push_back({i,b});
//	}
//	dfs(0,m);
//	cout<<dp[0][m];
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//T353707 『MGOI』Simple Round I | A. 魔法数字
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n; 
//signed main(){
//    cin>>n;
//    if(n<=3) {
//    	cout<<0;
//    	return 0;
//	} 
//    for(int i=2;i<=50;i++) {
//    	if(pow(2,i)<n&&pow(2,i+1)>=n) {
//    		if(i%2==0) {
//    			cout<<i;
//    			return 0;
//			}
//			else {
//				cout<<i-1;
//				return 0;
//			}
//		}
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//T338335 『MGOI』Simple Round I | B. 魔法照相馆
//#include<bits/stdc++.h>
//using namespace std;
//int n,bj[5];
//char s;
//int main() {
//	scanf("%d",&n);
//	int sum=0;
//	bj[1]=1,bj[2]=1,bj[3]=1;
//	while(n--) {
//		cin>>s;
//		if(s=='W') {
//				 if(bj[1]==1&&bj[2]==1&&bj[3]==0) sum++,bj[3]=1;
//			else if(bj[1]==1&&bj[2]==0&&bj[3]==0) sum++,bj[3]=1;
//			else if(bj[1]==0&&bj[2]==1&&bj[3]==0) sum++,bj[3]=1;
//			else if(bj[1]==0&&bj[2]==0&&bj[3]==0) sum++,bj[3]=1;
//		}
//		if(s=='B') {
//				 if(bj[1]==1&&bj[2]==1&&bj[3]==1) sum++,bj[3]=0;
//			else if(bj[1]==1&&bj[2]==0&&bj[3]==1) sum+=2,bj[2]=1,bj[3]=0;
//			else if(bj[1]==1&&bj[2]==0&&bj[3]==0) sum++,bj[2]=1;
//			else if(bj[1]==0&&bj[2]==1&&bj[3]==1) sum++,bj[3]=0;
//			else if(bj[1]==0&&bj[2]==0&&bj[3]==1) sum+=2,bj[2]=1,bj[3]=0;
//			else if(bj[1]==0&&bj[2]==0&&bj[3]==0) bj[2]==1,sum++;
//		}
//		if(s=='R') {
//				 if(bj[1]==1&&bj[2]==1&&bj[3]==1) sum+=2,bj[2]=0,bj[3]=0;
//			else if(bj[1]==1&&bj[2]==1&&bj[3]==0) sum++,bj[2]=0;
//			else if(bj[1]==1&&bj[2]==0&&bj[3]==1) sum++,bj[3]=0;
//			else if(bj[1]==0&&bj[2]==1&&bj[3]==1) sum+=3,bj[1]=1,bj[2]=0,bj[3]=0;
//			else if(bj[1]==0&&bj[2]==1&&bj[3]==0) sum+=2,bj[1]=1,bj[2]=0;
//			else if(bj[1]==0&&bj[2]==0&&bj[3]==1) sum+=2,bj[1]=1,bj[3]=0;
//			else if(bj[1]==0&&bj[2]==0&&bj[3]==0) sum++,bj[1]=1;
//		}
//	}
//	cout<<sum;
//	return 0;
//}
//
//
//
//
//
//
//
//
//P9504 『MGOI』Simple Round I | C. 魔法禁林
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,s,t,dp[1000001][152]; 
//struct aa{
//	int v,w;
//};
//vector<aa> P[1000001];
//signed main(){
//	cin>>n>>m>>s>>t;
//	for(int i=1;i<=m;i++) {
//		int u,v,w;
//		cin>>u>>v>>w;
//		P[u].push_back({v,w});
//		P[v].push_back({u,w});
//	}
//	memset(dp,0x3f,sizeof(dp));
//	dp[t][0]=0;
//	for(int k=1;k<=102;k++) {
//		for(int i=1;i<=n;i++) {
//			for(int j=0;j<P[i].size();j++) {
//				dp[i][k]=min(dp[i][k],P[i][j].w/k+dp[P[i][j].v][k-1]);
//			}
//		}
//	}
//	int ans=1e9;
//	for(int i=1;i<=102;i++) ans=min(ans,dp[s][i]);
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//P3372 【模板】线段树 1
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000000+7
//#define lc rt << 1
//#define rc rt << 1 | 1
//using namespace std;
//int n,m,a[maxn],sum[maxn*4],tag[maxn<<2];
//void pushup(int rt) {
//	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
//}
//void build(int l,int r,int rt) {
//	if(l==r) {
//		sum[rt]=a[l];
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(l,mid,rt<<1);
//	build(mid+1,r,rt<<1|1);
//	pushup(rt);
//}
//void pushdown(int rt, int l, int r) {
//	if(tag[rt]) {
//		int mid(l + r >> 1);
//		sum[lc] += tag[rt] * (mid - l + 1);
//		sum[rc] += tag[rt] * (r - mid);
//		tag[lc] += tag[rt], tag[rc] += tag[rt];
//		tag[rt] = 0;
//	}
//}
//void update(int v, int L, int R, int l, int r, int rt) {
//	if (L <= l && r <= R) {
//		sum[rt] += v * (r - l + 1);
//		tag[rt] += v;
//		return ;
//	}
//	pushdown(rt, l, r);
//	int mid=(l+r)>>1;
//	if(L<=mid) update(v,L,R,l,mid,rt<<1);
//	if(R>mid)  update(v,L,R,mid+1,r,rt<<1|1);
//	pushup(rt);
//}
//int  Query(int L,int R,int l,int r,int rt) {
//	if(L<=l&&r<=R) return sum[rt];
//	pushdown(rt,l,r);
//	int mid=(l+r)>>1;
//	int ANS=0;
//	if(L<=mid) ANS+=Query(L,R,l,mid,rt<<1);
//	if(R>mid)  ANS+=Query(L,R,mid+1,r,rt<<1|1);
//	return ANS;
//}
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
//	build(1,n,1);
//	for(int i=1; i<=m; i++) {
//		int a;
//		scanf("%lld",&a);
//		if(a==1) {
//			int x,y,z;
//			scanf("%lld%lld%lld",&x,&y,&z);
//			update(z,x,y,1,n,1);
//		} else {
//			int x,y;
//			scanf("%lld%lld",&x,&y);
//			printf("%lld\n",Query(x,y,1,n,1));
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//P2846 [USACO08NOV] Light Switching G
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000000+7
//#define lc rt << 1
//#define rc rt << 1 | 1
//using namespace std;
//int n,m,sum[maxn*4],tag[maxn<<2];
//void pushup(int rt) {
//	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
//}
//void pushdown(int rt, int l, int r) {
//	if(tag[rt]) {
//		int mid=(l+r)>>1;
//		tag[lc]^=1,tag[rc]^=1;
//		sum[lc]=(mid-l+1)-sum[lc];
//		sum[rc]=(r-mid)-sum[rc];
//		tag[rt]=0;
//	}
//}
//void update(int L, int R, int l, int r, int rt) {
//	if (L <= l && r <= R) {
//		sum[rt]=(r-l+1)-sum[rt];
//		tag[rt]^=1;
//		return ;
//	}
//	pushdown(rt, l, r);
//	int mid=(l+r)>>1;
//	if(L<=mid) update(L,R,l,mid,rt<<1);
//	if(R>mid)  update(L,R,mid+1,r,rt<<1|1);
//	pushup(rt);
//}
//int  Query(int L,int R,int l,int r,int rt) {
//	if(L<=l&&r<=R) return sum[rt];
//	pushdown(rt,l,r);
//	int mid=(l+r)>>1;
//	int ANS=0;
//	if(L<=mid) ANS+=Query(L,R,l,mid,rt<<1);
//	if(R>mid)  ANS+=Query(L,R,mid+1,r,rt<<1|1);
//	return ANS;
//}
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1; i<=m; i++) {
//		int a;
//		scanf("%lld",&a);
//		if(a==0) {
//			int x,y,z;
//			scanf("%lld%lld",&x,&y);
//			update(x,y,1,n,1);
//		} else {
//			int x,y;
//			scanf("%lld%lld",&x,&y);
//			printf("%lld\n",Query(x,y,1,n,1));
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//P3373 【模板】线段树 2
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100007
//#define lc rt<<1
//#define rc rt<<1|1
//int n,m,q;
//int aa[maxn];
//struct tree{
//	int sum,add,mul;
//	int l,r;
//}a[maxn<<2];
//void pushup(int rt) {
//	a[rt].sum=(a[lc].sum+a[rc].sum)%m;
//}
//void build(int l,int r,int rt){
//	a[rt].l=l;
//	a[rt].r=r;
//	a[rt].mul=1;
//	if(l==r) {
//		a[rt].sum=aa[l];
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(l,mid,lc);
//	build(mid+1,r,rc);
//	pushup(rt);
//	return ;
//}
//void pushdown(int rt) {
//	a[lc].sum=(a[lc].sum*a[rt].mul+a[rt].add*(a[lc].r-a[lc].l+1))%m;
//	a[rc].sum=(a[rc].sum*a[rt].mul+a[rt].add*(a[rc].r-a[rc].l+1))%m;
//	
//	a[lc].mul=(a[lc].mul*a[rt].mul)%m;
//	a[rc].mul=(a[rc].mul*a[rt].mul)%m;
//	
//	a[lc].add=(a[lc].add*a[rt].mul+a[rt].add)%m;
//	a[rc].add=(a[rc].add*a[rt].mul+a[rt].add)%m;
//	
//	a[rt].add=0;
//	a[rt].mul=1;
//	
//	return ;
//}
//void updatecheng(int rt,int l,int r,int k) {
//	if(l<=a[rt].l&&a[rt].r<=r) {
//		a[rt].add=(a[rt].add*k)%m;
//		a[rt].mul=(a[rt].mul*k)%m;
//		a[rt].sum=(a[rt].sum*k)%m;
//		return ;
//	}
//	
//	pushdown(rt);
//	int mid=(a[rt].l+a[rt].r)>>1;
//	if(l<=mid) updatecheng(lc,l,r,k);
//	if(r>mid)  updatecheng(rc,l,r,k);
//	
//	pushup(rt);
//	return ;
//}
//void updatejia(int rt,int l,int r,int k) {
//	if(l<=a[rt].l&&a[rt].r<=r) {
//		a[rt].add=(a[rt].add+k)%m;
//		a[rt].sum=(a[rt].sum+k*(a[rt].r-a[rt].l+1))%m;
//		return ;
//	}
//	pushdown(rt);
//	int mid=(a[rt].r+a[rt].l)>>1;
//	if(l<=mid) updatejia(lc,l,r,k);
//	if(r>mid)  updatejia(rc,l,r,k);
//	
//	pushup(rt);
//	return ;
//}
//int  Query(int rt,int l,int r) {
//	if(l<=a[rt].l&&a[rt].r<=r) {
//		return a[rt].sum;
//	}
//	pushdown(rt);
//	int mid=(a[rt].l+a[rt].r)>>1;
//	int ANS=0;
//	if(l<=mid) ANS+=Query(lc,l,r)%m;
//	if(r>mid)  ANS+=Query(rc,l,r)%m;
//	return ANS;
//}
//signed main() {
//	scanf("%lld%lld%lld",&n,&q,&m);
//	for(int i=1; i<=n; i++) scanf("%lld",&aa[i]);
//	build(1,n,1);
//	for(int i=1; i<=q; i++) {
//		int opt;
//		scanf("%lld",&opt);
//		if(opt==1) {
//			int x,y,z;
//			scanf("%lld%lld%lld",&x,&y,&z);
//			updatecheng(1,x,y,z);
//		}
//		if(opt==2) {
//			int x,y,z;
//			scanf("%lld%lld%lld",&x,&y,&z);
//			updatejia(1,x,y,z);
//		}
//		if(opt==3) {
//			int x,y;
//			scanf("%lld%lld",&x,&y);
//			printf("%lld\n",Query(1,x,y)%m);
//		}
//	}
//	return 0;
//}
/*
5 5 38
1 5 4 2 3
2 1 4 1
3 2 5
1 2 4 2
2 3 5 5
3 1 4
*/
//
//
//
//
//
//
//
//
//
//
//P6812 「MCOI-02」Ancestor 先辈
//#include<bits/stdc++.h>
//#define int long long
//#define lc rt<<1
//#define rc rt<<1|1
//#define maxn 1000007
//using namespace std;
//int n,k;
//int o[maxn];
//struct aa {
//	int l,r;
//	int ans;
//} a[maxn<<2];
//void pushup(int rt) {
//	a[rt].ans=min(a[lc].ans,a[rc].ans);
//}
//void build(int rt,int l,int r) {
//	a[rt].l=l;
//	a[rt].r=r;
//	if(l==r) {
//		a[rt].ans=o[l+1]-o[l];
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(lc,l,mid);
//	build(rc,mid+1,r);
//	pushup(rt);
//}
//void update(int rt,int x,int p) {
//	if(a[rt].l==a[rt].r) {
//		a[rt].ans+=p;
//		return ;
//	}
//	int mid=(a[rt].l+a[rt].r)>>1;
//	if(x<=mid) update(lc,x,p);
//	else update(rc,x,p);
//	pushup(rt);
//}
//int Query(int rt,int l,int r) {
//	if(l<=a[rt].l&&a[rt].r<=r) return a[rt].ans;
//	int mid=(a[rt].l+a[rt].r)>>1;
//	int ans=1e18;
//	if(l<=mid) ans=min(ans,Query(lc,l,r));
//	if(r>mid)  ans=min(ans,Query(rc,l,r));
//	return ans;
//}
//signed main() {
//	scanf("%lld%lld",&n,&k);
//	for(int i=1; i<=n; i++) scanf("%lld",&o[i]);
//	build(1,1,n-1);
//	for(int i=1;i<=k;i++) {
//		int opt;
//		scanf("%lld",&opt);
//		if(opt==1) {
//			int x,y,z;
//			scanf("%lld%lld%lld",&x,&y,&z);
//			y=min(y,n);
//			if(x>1) update(1,x-1,z);
//			update(1,y,-z); 
//		}
//		if(opt==2) {
//			int x,y;
//			scanf("%lld%lld",&x,&y);
//			if(Query(1,x,y-1)>=0) printf("Yes\n");
//			else printf("No\n");
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//P1637 三元上升子序列 
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//#define lc rt<<1
//#define rc rt<<1|1
//using namespace std;
//int n,a[maxn],sm[maxn<<2],bg[maxn<<2];
//int sum[maxn<<2];
//void pushup(int rt) {
//	sum[rt]=sum[lc]+sum[rc];
//}
//void update(int rt,int l,int r,int x) {
//	if(l==r) {
//		sum[rt]++;
//		return ;
//	}
//	int mid=(l+r)>>1;
//	if(x<=mid) update(lc,l,mid,x);
//	if(x>mid)  update(rc,mid+1,r,x);
//	pushup(rt);
//}
//int  Query(int rt,int l,int r,int L,int R) {
//	if(L>R) return 0; 
//	if(L<=l&&r<=R) return sum[rt];
//	int mid=(l+r)>>1;
//	int ANS=0;
//	if(L<=mid) ANS+=Query(lc,l,mid,L,R);
//	if(R>mid)  ANS+=Query(rc,mid+1,r,L,R);
//	return ANS;
//}
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
//	for(int i=1; i<=n; i++) {
//		update(1,1,maxn,a[i]);
//		sm[i]=Query(1,1,maxn,1,a[i]-1);
//	}
//	memset(sum,0,sizeof(sum));
//	for(int i=n; i>=1; i--) {
//		update(1,1,maxn,a[i]);
//		bg[i]=Query(1,1,maxn,a[i]+1,maxn);
//	}
//	int ans=0;
//	for(int i=1; i<=n; i++) ans+=bg[i]*sm[i];
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//Problem ID: 1423 交换
//#include<bits/stdc++.h>
//using namespace std;
//string s,t;
//int main(){
//	cin>>s>>t;
//	int lens=s.size();
//	int lent=t.size();
//	int ans=0;
//	for(int i=1;i<lens-1;i++) {
//		for(int j=1;j<lent-1;j++) {
//			if(s[i]==t[j+1]&&s[i]==t[j-1]&&t[j]==s[i-1]&&t[j]==s[i+1]) 
//				ans++;
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//P1929 迷之阶梯
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,a[300],dp[300];
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1; i<=n; i++) dp[i]=1e18;
//	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
//	dp[1]=0;
//	for(int i=1; i<=n; i++) {
//		if(a[i]-a[i-1]<=1) dp[i]=min(dp[i],dp[i-1]+1);
//		for(int j=i; j>=1; j--) {
//			dp[j]=dp[i]+i-j;
//			for(int k=i; k<=n; k++) {
//				if(a[k]-a[j]<=pow(2,i-j)) dp[k]=min(dp[k],dp[j]+1);
//			}
//		}
//	}
//	if(dp[n]!=1e18) cout<<dp[n];
//	else cout<<-1;
//	return 0;
//}
/*
5
0 1 2 3 6
7

5
0 1 2 4 8
9

8
0 2 3 4 5 6 7 8
-1

7
0 1 2 3 5 10 100
-1

15
0 1 2 3 4 7 10 15 50 100 200 300 400 500 1000
36
*/
//
//
//
//
//
//
//
//
//
//
//F - 无聊的数列 洛谷 - P1438 
//#include<bits/stdc++.h>
//#define int long long
//#define lc rt<<1
//#define rc rt<<1|1
//#define maxn 200005
//using namespace std;
//
//int n,m;
//int a[maxn<<2];
//struct aa{
//	int tag,sum;
//	int l,r;
//}t[maxn<<2];
//void pushup(int rt) {
//	t[rt].sum=t[lc].sum+t[rc].sum;
//}
//void build(int rt,int l,int r) {
//	t[rt].l=l;
//	t[rt].r=r;
//	int mid=(l+r)>>1;
//	if(l==r) {
//		t[rt].sum=a[l];
//		return ;
//	}
//	build(lc,l,mid);
//	build(rc,mid+1,r);
//	pushup(rt);
//}
//void pushdown(int rt) {
//	int mid=(t[rt].l+t[rt].r)>>1;
//	t[lc].tag+=t[rt].tag;
//	t[rc].tag+=t[rt].tag;
//	t[lc].sum+=t[rt].tag*(mid-t[rt].l+1);
//	t[rc].sum+=t[rt].tag*(t[rt].r-mid);
//	t[rt].tag=0;
//}
//void update(int rt,int l,int r,int p) {
//	if(l<=t[rt].l&&t[rt].r<=r) {
//		t[rt].sum+=(t[rt].r-t[rt].l+1)*p;
//		t[rt].tag+=p;
//		return ;
//	}
//	pushdown(rt);
//	int mid=(t[rt].l+t[rt].r)>>1;
//	if(l<=mid) update(lc,l,r,p);
//	if(r>mid)  update(rc,l,r,p);
//	pushup(rt);
//}
//int Query(int rt,int l,int r) {
////	if(l>r||r>n) return 0; 
//	if(l<=t[rt].l&&t[rt].r<=r) return t[rt].sum;
//	int ANS=0;
//	int mid=(t[rt].l+t[rt].r)>>1;
//	pushdown(rt);
//	if(l<=mid) ANS+=Query(lc,l,r);
//	if(r>mid)  ANS+=Query(rc,l,r); 
//	return ANS;
//}
//signed main(){
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=n-1;i>=0;i--) a[i+1]=a[i+1]-a[i];
//	build(1,1,n+1);
//	for(int i=1;i<=m;i++) {
//		int opt;
//		scanf("%lld",&opt);
//		if(opt==1) {
//			int l,r,K,D;
//			scanf("%lld%lld%lld%lld",&l,&r,&K,&D);
//			update(1,l,l,K);
//			update(1,l+1,r,D);
//			update(1,r+1,r+1,-(K+D*(r-l)));
//		}
//		if(opt==2) {
//			int p;
//			scanf("%lld",&p);
//			printf("%lld\n",Query(1,1,p));
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//Problem ID: 1558 代数式运算
//#include <bits/stdc++.h>
//using namespace std;
//int n;
//char s[10000];
//double getnum(int l,int r)
//{
//    int f=1;
//    double d=1,x=0;
//    for (int i=l;i<=r;++i)
//    {
//        if (s[i]=='.') f=0;
//        else if (f) x=x*10+s[i]-'0';
//        else
//        {
//            d*=0.1;
//            x+=d*(s[i]-'0');
//        }
//    }
//    return x;
//}
//  
//int pro(char c)
//{
//    if (c=='+'||c=='-') return 1;
//    if (c=='*'||c=='/') return 2;
//    if (c=='^') return 3;
//    return 4;
//}
//  
//int find(int l,int r)
//{
//    int pos=-1,d=0,mi=3;
//    for (int i=l;i<=r;++i)
//    {
//        if (s[i]=='(') ++d;
//        else if (s[i]==')') --d;
//        if (!d)
//        {
//            if (pro(s[i])<=mi)
//            {
//                pos=i;
//                mi=pro(s[i]);
//            }
//        }
//    }
//    return pos;
//}
//  
//double solve(int l,int r)
//{
//    int pos=find(l,r);
//    if (pos==-1)
//    {
//        if (s[l]=='('&&s[r]==')')
//        {
//            return solve(l+1,r-1);
//        }
//        else
//        {
//            return getnum(l,r);
//        }
//    }
//    double p=solve(l,pos-1),q=solve(pos+1,r);
//    if (s[pos]=='+')
//    {
//        return p+q;
//    }
//    if (s[pos]=='-')
//    {
//        return p-q;
//    }
//    if (s[pos]=='*')
//    {
//        return p*q;
//    }
//    if (s[pos]=='/')
//    {
//        return p/q;
//    }
//    if (s[pos]=='^')
//    {
//        return pow(p,q);
//    }
//}
//  
//int main()
//{
//    scanf("%s",s+1);
//    n=strlen(s+1);
//    printf("%.2lf\n",solve(1,n));
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//G - 逆序对 洛谷 - P1908  	
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 500005
//#define lc rt<<1
//#define rc rt<<1|1
//using namespace std;
//int n,a[maxn],b[maxn],id[maxn],sum[maxn<<2],ans=0;
//void pushup(int rt) {
//	sum[rt]=sum[lc]+sum[rc];
//}
//void update(int rt,int l,int r,int x) {
//	if(l==r) {
//		sum[rt]++;
//		return ;
//	}
//	int mid=(l+r)>>1;
//	if(x<=mid) update(lc,l,mid,x);
//	else update(rc,mid+1,r,x);
//	pushup(rt);
//}
//int  Query(int rt,int l,int r,int L,int R) {
//	if(L<=l&&r<=R) return sum[rt];
//	int mid=(l+r)>>1,ANS=0;
//	if(L<=mid) ANS+=Query(lc,l,mid,L,R);
//	if(R>mid)  ANS+=Query(rc,mid+1,r,L,R);
//	return ANS;
//}
//signed main() {
//	memset(sum,0,sizeof(sum));
//	scanf("%lld",&n);
//	for(int i=1; i<=n; i++) {
//		scanf("%lld",&a[i]);
//		b[i]=a[i];
//	}
//	sort(b+1,b+n+1);
//	for(int i=1; i<=n; i++) id[i]=lower_bound(b+1,b+n+1,a[i])-b;
//	for(int i=1; i<=n; i++) {
//		int x=id[i];
//		ans+=Query(1,1,n,x+1,n);
//		update(1,1,n,x);
//	}
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//H - Can you answer these queries III SPOJ - GSS3 
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 50005
//#define lc rt<<1
//#define rc rt<<1|1
//using namespace std;
//int n,q;
//int a[maxn];
//struct Tree {
//	int sum;
//	int ans;
//	int maxsuml,maxsumr;
//} tree[maxn<<2];
//void push_up(int rt) {
//	tree[rt].sum=tree[lc].sum+tree[rc].sum;
//	tree[rt].maxsuml=max(tree[lc].maxsuml,tree[lc].sum+tree[rc].maxsuml);
//	tree[rt].maxsumr=max(tree[rc].maxsumr,tree[lc].maxsumr+tree[rc].sum);
//	tree[rt].ans=max(tree[lc].maxsumr+tree[rc].maxsuml,max(tree[lc].ans,tree[rc].ans));
//}
//void build(int rt,int l,int r) {
//	if(l==r) {
//		tree[rt].maxsuml=a[l];
//		tree[rt].maxsumr=a[l];
//		tree[rt].sum=a[l];
//		tree[rt].ans=a[l];
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(lc,l,mid);
//	build(rc,mid+1,r);
//	push_up(rt);
//}
//void update(int rt,int l,int r,int x,int p) {
//	if(l==r) {
//		tree[rt].ans=p;
//		tree[rt].maxsuml=p;
//		tree[rt].maxsumr=p;
//		tree[rt].sum=p;
//		return ;
//	}
//	int mid=(l+r)>>1;
//	if(x<=mid) update(lc,l,mid,x,p);
//	else update(rc,mid+1,r,x,p);
//	push_up(rt);
//}
//Tree Query(int rt,int L,int R,int l,int r) {
//	if(l<=L&&R<=r) return tree[rt];
//	int mid=(L+R)>>1;
//	if(r<=mid) return Query(lc,L,mid,l,r);
//	if(l>mid)  return Query(rc,mid+1,R,l,r);
//	Tree ll=Query(lc,L,mid,l,r);
//	Tree rr=Query(rc,mid+1,R,l,r);
//	Tree anss;
//	anss.sum=ll.sum+rr.sum;
//	anss.maxsuml=max(ll.maxsuml,ll.sum+rr.maxsuml);
//	anss.maxsumr=max(rr.maxsumr,ll.maxsumr+rr.sum);
//	anss.ans=max(ll.maxsumr+rr.maxsuml,max(ll.ans,rr.ans));
//	return anss;
//}
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
//	scanf("%lld",&q);
//	build(1,1,n);
//	for(int i=1; i<=q; i++) {
//		int opt;
//		scanf("%lld",&opt);
//		if(opt==0) {
//			int x,y;
//			scanf("%lld%lld",&x,&y);
//			update(1,1,n,x,y);
//		}
//		if(opt==1) {
//			int l,r;
//			scanf("%lld%lld",&l,&r);
//			printf("%lld\n",Query(1,1,n,l,r).ans);
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//T358970 『STA - R3』存在
//#include<bits/stdc++.h>
//using namespace std;
//int n,cnt=1;
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++) {
//		if(i%3==1) {
//			++cnt;
//			cout<<cnt<<" ";
//		}
//		else cout<<1<<" "; 
//	}
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//Problem ID: 7504 [JSOI2007]重要的城市
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m;
//int f[1005][1005],p[1005][1005];
//bool bj[100000];
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	memset(f,0x3f,sizeof(f));
//	for(int i=1; i<=m; i++) {
//		int u,v,w;
//		scanf("%lld%lld%lld",&u,&v,&w);
//		f[u][v]=f[v][u]=min(f[u][v],w);
//	}
//	for(int k=1; k<=n; k++) {
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=n; j++) {
//				if(i==j) continue;
//				if(f[i][j]>f[i][k]+f[k][j]) {
//					f[i][j]=f[i][k]+f[k][j];
//					p[i][j]=k;
//				} else if(f[i][j]==f[i][k]+f[k][j]) p[i][j]=-1;
//			}
//		}
//	}
//	bool flag=false;
//	for(int i=1;i<=n;i++) 
//		for(int j=1;j<=n;j++) {
//			if(i==j) continue;
//			if(p[i][j]!=-1) bj[p[i][j]]=1;
//		}
//	for(int i=1;i<=n;i++) {
//		if(bj[i]==1) {
//			flag=true;
//			printf("%lld ",i);
//		}
//	}
//	if(flag==false) printf("No important cities.\n");
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//P1177 【模板】排序
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 500005
//using namespace std;
//int n,a[maxn]; 
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++) printf("%lld ",a[i]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1226 【模板】快速幂
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int aa,bb,pp;
//long long binpow(long long a, long long b,long long p) {
//	if (b == 0) return 1;
//	long long res = binpow(a,b/2,p)%p;
//	if (b % 2) return res%p*res%p*a%p;
//	else return res%p*res%p;
//}
//signed main() {
//	scanf("%lld%lld%lld",&aa,&bb,&pp);
//	printf("%lld^%lld mod %lld=%lld",aa,bb,pp,binpow(aa,bb,pp));
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//P3374 【模板】树状数组 1
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 5000000+7
//#define lc rt << 1
//#define rc rt << 1 | 1
//using namespace std;
//int n,m,a[maxn],sum[maxn*4],tag[maxn<<2];
//void pushup(int rt) {
//	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
//}
//void build(int l,int r,int rt) {
//	if(l==r) {
//		sum[rt]=a[l];
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(l,mid,rt<<1);
//	build(mid+1,r,rt<<1|1);
//	pushup(rt);
//}
//void pushdown(int rt, int l, int r) {
//	if(tag[rt]) {
//		int mid(l + r >> 1);
//		sum[lc] += tag[rt] * (mid - l + 1);
//		sum[rc] += tag[rt] * (r - mid);
//		tag[lc] += tag[rt], tag[rc] += tag[rt];
//		tag[rt] = 0;
//	}
//}
//void update(int v, int L, int R, int l, int r, int rt) {
//	if (L <= l && r <= R) {
//		sum[rt] += v * (r - l + 1);
//		tag[rt] += v;
//		return ;
//	}
//	pushdown(rt, l, r);
//	int mid=(l+r)>>1;
//	if(L<=mid) update(v,L,R,l,mid,rt<<1);
//	if(R>mid)  update(v,L,R,mid+1,r,rt<<1|1);
//	pushup(rt);
//}
//int  Query(int L,int R,int l,int r,int rt) {
//	if(L<=l&&r<=R) return sum[rt];
//	pushdown(rt,l,r);
//	int mid=(l+r)>>1;
//	int ANS=0;
//	if(L<=mid) ANS+=Query(L,R,l,mid,rt<<1);
//	if(R>mid)  ANS+=Query(L,R,mid+1,r,rt<<1|1);
//	return ANS;
//}
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
//	build(1,n,1);
//	for(int i=1; i<=m; i++) {
//		int a;
//		scanf("%lld",&a);
//		if(a==1) {
//			int x,z;
//			scanf("%lld%lld",&x,&z);
//			update(z,x,x,1,n,1);
//		} else {
//			int x,y;
//			scanf("%lld%lld",&x,&y);
//			printf("%lld\n",Query(x,y,1,n,1));
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3368 【模板】树状数组 2
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 500005
//using namespace std;
//int n,q,a[maxn],tr[maxn];
//int  lowbit(int p) {
//	return p&-p;
//}
//void update(int s,int p) {
//	for(int i=s;i<=n;i+=lowbit(i)) tr[i]+=p;
//}
//int  Query(int p) {
//	int ans=0;
//	for(int i=p;i>=1;i-=lowbit(i)) ans+=tr[i];
//	return ans;
//}
//signed main(){
//	scanf("%lld%lld",&n,&q);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<=q;i++) {
//		int opt;
//		scanf("%lld",&opt);
//		if(opt==1) {
//			int x,y,s;
//			scanf("%lld%lld%lld",&x,&y,&s);
//			update(x,s);
//			update(y+1,-s);
//		}
//		else {
//			int x;
//			scanf("%lld",&x);
//			printf("%lld\n",a[x]+Query(x));
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1150 Peter 的烟
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,k,ans;
//signed main() {
//	cin>>n>>k;
//	cout<<n+(n-1)/(k-1);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1151 子数整数
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int k;
//signed main() {
//	cin>>k;
//	bool flag=false;
//	for(int i=10000;i<=30000;i++) {
//		int a1=i/10000*100+i%10000/1000*10+i%1000/100;
//		int a2=i%10000/1000*100+i%1000/100*10+i%100/10;
//		int a3=i%1000/100*100+i%100/10*10+i%10;
//		if(a1%k==0&&a2%k==0&&a3%k==0) {
//			cout<<i<<endl;
//			flag=true;
//		}
//	}
//	if(flag==false) cout<<"No";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1152 欢乐的跳
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,a[100001];
//bool bj[10001];
//signed main() {
//	scanf("%lld",&n);
//	memset(bj,false,sizeof(bj));
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<n;i++) if(abs(a[i]-a[i+1])<=n-1&&abs(a[i]-a[i+1])>=1)  bj[abs(a[i]-a[i+1])]=true;
//	for(int i=1;i<n;i++) {
//		if(bj[i]==false) {
//			cout<<"Not jolly";	
//			return 0;
//		}
//	}
//	cout<<"Jolly";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//P1161 开灯
//#include <bits/stdc++.h>
//using namespace std;
//int n,t[2000001];
//double a[2000001];
//int kg[2000001];
//signed main() {
//	scanf("%d",&n);
//	memset(kg,0,sizeof(kg));
//	for(int i=1; i<=n; i++) cin>>a[i]>>t[i];
//	for(int i=1; i<=n; i++)
//		for(int j=1; j<=t[i]; j++) {
//			kg[int(a[i]*j)]^=1;
//		}
//	for(int i=1;i<=100;i++) cout<<kg[i]<<" ";
//	for(int i=1; i<=2000001; i++)
//		if(kg[i]==1) {
//			cout<<i;
//			return 0;
//		}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1271 【深基9.例1】选举学生会
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m;
//int a[2000005];
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
//	sort(a+1,a+m+1);
//	for(int i=1;i<=m;i++) cout<<a[i]<<" "; 
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P5143 攀爬者
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n;
//struct aa{
//	double x,y,z;
//}a[500001];
//bool cmp(aa p,aa c) {
//	return p.z<c.z;
//}
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
//	sort(a+1,a+n+1,cmp);
//	double ans=0.000;
//	for(int i=1;i<n;i++) ans+=sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y)+(a[i].z-a[i+1].z)*(a[i].z-a[i+1].z));
//	printf("%.3lf",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1104 生日
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n;
//struct aa{
//	int id;
//	string s;
//	int y,m,d;
//}a[105];
//bool cmp(aa p,aa c) {
//	if(p.y!=c.y) return p.y<c.y;
//	else if(p.m!=c.m) return p.m<c.m;
//	else if(p.d!=c.d) return p.d<c.d;
//	else return p.id>c.id;
//}
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) {
//		cin>>a[i].s;
//		cin>>a[i].y>>a[i].m>>a[i].d;
//		a[i].id=i;
//	}
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++) cout<<a[i].s<<endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1012	[NOIP1998 提高组] 拼数
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n;
//bool cmp(string x,string y) {
//	return x+y>y+x;
//}
//signed main() {
//	cin>>n;
//	string a[n];
//	for(int i=0;i<n;i++) cin>>a[i];
//	sort(a,a+n,cmp);
//	for(int i=0;i<n;i++) cout<<a[i];
//	return 0;
//}
//6
//321 32 407 135 13 217
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1115 最大子段和
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,a,p,ans=-1e9;
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) {
//		scanf("%lld",&a);
//		if(i==1) p=a;
//		else p=max(a,a+p);
//		ans=max(ans,p);
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1742G Orray
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int res=0,n,T;
//bool cmp(int a,int b) {
//    return (res|a)>(res|b);
//}
//void solve() {
//    res=0;
//    cin>>n;
//    vector<int> a(n+1);
//    for (int i=1;i<=n;i++) cin>>a[i];
//    int cnt=min((long long)30,n);
//    for (int i=1;i<=cnt;i++){
//        sort(a.begin()+i,a.end(),cmp);
//        res|=a[i];
//    }
//    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//}
//signed main() {
//    cin>>T;
//    while(T--){
//    	solve();
//    	cout<<endl;
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//P1802 5 倍经验日
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 1005
//using namespace std;
//int n,x;
//int lose[maxn],win[maxn],use[maxn];
//int dp[maxn];
//signed main() {
//	scanf("%lld%lld",&n,&x);
//	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&lose[i],&win[i],&use[i]);
//	for(int i=1;i<=n;i++) {
//		for(int j=x;j>=use[i];j--) dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
//		for(int j=use[i]-1;j>=0;j--) dp[j]+=lose[i];
//	}
//	printf("%lld",5*dp[x]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P5737	【深基7.例3】闰年展示
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int x,y;
//bool check(int p) {
//	if((p%4==0&&p%100!=0)||p%400==0) return true;
//	else return false;
//}
//signed main() {
//	scanf("%lld%lld",&x,&y);
//	int sum=0;
//	for(int i=x;i<=y;i++) if(check(i)==true) sum++;
//	cout<<sum<<endl;
//	for(int i=x;i<=y;i++) if(check(i)==true) cout<<i<<" ";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P5739	【深基7.例7】计算阶乘
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a,ans=1;
//signed main(){
//	cin>>a;
//	for(int i=1;i<=a;i++) ans*=i;
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//P5461	赦免战俘
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n;
//int a[1100][1100];
//signed main() {
//	scanf("%lld",&n);
//	n=(1<<n);
//	a[0][n+1]=1;
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=n;j++) {
//			a[i][j]=a[i-1][j]^a[i-1][j+1];
//			printf("%lld ",a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3956 [NOIP2017 普及组] 棋盘
//#include <bits/stdc++.h>
//#define maxn 1100
//using namespace std;
//int m,n,ans=0x7fffffff;
//int a[maxn][maxn],dis[maxn][maxn],bj[maxn][maxn];
//int dx[4]= {0,0,1,-1};
//int dy[4]= {1,-1,0,0};
//void cr(int x,int y,int ansn,int color) {
//	if((x==n)&&(y==n)) {
//		ans=min(ansn,ans);
//		return ;
//	}
//	for(int i=0; i<4; i++) {
//		int tx=x+dx[i];
//		int ty=y+dy[i];
////		if(tx<=0||ty<=0||tx>n||ty>n||bj[tx][ty])
//		if(a[x][y]||a[tx][ty]) {
//			if(a[tx][ty]==0) {
//				if(ansn+2<dis[tx][ty]) {
//					bj[tx][ty]=0;
//					dis[tx][ty]=ansn+2,cr(tx,ty,ansn+2,color);
//					bj[tx][ty]=1;
//				}
//			} else {
//				if((color==a[tx][ty])&&(ansn<dis[tx][ty])) {
//					bj[tx][ty]=0;
//					dis[tx][ty]=ansn,cr(tx,ty,ansn,color);
//					bj[tx][ty]=1;
//				} else if((ansn+1<ans)&&(ansn+1<dis[tx][ty])) {
//					bj[tx][ty]=0;
//					dis[tx][ty]=ansn+1,cr(tx,ty,ansn+1,a[tx][ty]);
//					bj[tx][ty]=1;
//				}
//			}
//		}
//	}
//}
//signed main() {
//	scanf("%d%d",&n,&m);
//	for(int i=1; i<=n; i++)
//		for(int j=1; j<=n; j++)
//			dis[i][j]=0x7fffffff,a[i][j]=0,bj[i][j]=1;
//	for(int i=1; i<=m; i++) {
//		int x,y,z;
//		scanf("%d%d%d",&x,&y,&z);
//		a[x][y]=z+1;
//	}
//	bj[1][1]=0;
//	cr(1,1,0,a[1][1]);
//	if(ans==0x7fffffff) cout<<-1;
//	else cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//U329011 trie pi
//#include<bits/stdc++.h>
//using namespace std;
//bool vis[10000005];
//long long n,x,maxx=-1,len=0,num[5000000],v[10000005];
//inline long long read(){
//    char c=getchar();
//    long long x=0,f=1;
//    while(c<48){if(c=='-')f=-1;c=getchar();}
//    while(c>47)x=(x*10)+(c^48),c=getchar();
//    return x*f;
//}
//void solve(){
//    for(long long i=2;i<=10000000;i++){
//        if(vis[i]==false){
//            len++;
//            num[len]=i;
//        }
//        for(long long j=1;j<=len&&i*num[j]<=10000000;j++){
//            vis[i*num[j]]=true;
//            if(i%num[j]==0) break;
//        }
//    }
//}
//void dfs(long long from,long long sum){
//    v[sum]=num[from];
//    for(long long i=from;i<=len&&sum*num[i]<=10000000;i++){
//        dfs(i,sum*num[i]);
//    }
//}
//int main(){
//    solve();
//    dfs(1,1);
//    v[1]=1;
//    n=read();
//    for(long long i=1;i<=n;i++){
//        x=read();
//        maxx=max(maxx,v[x]);
//    }
//    cout<<maxx-1;
//
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3870	[TJOI2009] 开关
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000000+7
//#define lc rt << 1
//#define rc rt << 1 | 1
//using namespace std;
//int n,m,sum[maxn*4],tag[maxn<<2];
//void pushup(int rt) {
//    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
//}
//void pushdown(int rt, int l, int r) {
//    if(tag[rt]) {
//        int mid=(l+r)>>1;
//        tag[lc]^=1,tag[rc]^=1;
//        sum[lc]=(mid-l+1)-sum[lc];
//        sum[rc]=(r-mid)-sum[rc];
//        tag[rt]=0;
//    }
//}
//void update(int L, int R, int l, int r, int rt) {
//    if (L <= l && r <= R) {
//        sum[rt]=(r-l+1)-sum[rt];
//        tag[rt]^=1;
//        return ;
//    }
//    pushdown(rt, l, r);
//    int mid=(l+r)>>1;
//    if(L<=mid) update(L,R,l,mid,rt<<1);
//    if(R>mid)  update(L,R,mid+1,r,rt<<1|1);
//    pushup(rt);
//}
//int  Query(int L,int R,int l,int r,int rt) {
//    if(L<=l&&r<=R) return sum[rt];
//    pushdown(rt,l,r);
//    int mid=(l+r)>>1;
//    int ANS=0;
//    if(L<=mid) ANS+=Query(L,R,l,mid,rt<<1);
//    if(R>mid)  ANS+=Query(L,R,mid+1,r,rt<<1|1);
//    return ANS;
//}
//signed main() {
//    scanf("%lld%lld",&n,&m);
//    for(int i=1; i<=m; i++) {
//        int a;
//        scanf("%lld",&a);
//        if(a==0) {
//            int x,y,z;
//            scanf("%lld%lld",&x,&y);
//            update(x,y,1,n,1);
//        } else {
//            int x,y;
//            scanf("%lld%lld",&x,&y);
//            printf("%lld\n",Query(x,y,1,n,1));
//        }
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P5788 【模板】单调栈
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,a[3000001],f[3000001];
//stack<int> s;
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=n;i>=1;i--) {
//		while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
//		if(s.empty()) f[i]=0;
//		else f[i]=s.top();
//		s.push(i); 
//	}
//	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P8818 [CSP-S 2022] 策略游戏
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 100005
//#define mininf -1e18
//#define maxinf 1e18
//const int maxinf = LONG_LONG_MAX, mininf = LONG_LONG_MIN;
//#define lgn 25
//using namespace std;
//int n,m,q;
//int amax[maxn][lgn],amin[maxn][lgn];//amax表示a数组区间最大值,amin表示a数组区间最小值
//int afmx[maxn][lgn],azmn[maxn][lgn];//afmx表示a数组在负数中的最大值,azmn表示a数组在非负数中的最小值(因为有0)
//int bmax[maxn][lgn],bmin[maxn][lgn];//bmax表示b数组区间最大值,bmin表示b数组区间最小值
//int lg[maxn];
//inline bool gmx(int &a, int b) {
//	return b > a ? a = b, true : false;
//}
//signed main() {
//	scanf("%lld%lld%lld",&n,&m,&q);
//
//	for(int i=1; i<=n; ++i) {
//		int x;
//		scanf("%lld",&x);
//		amax[i][0]=amin[i][0]=x;
//      //afmx[i][0]=(x<0?x:mininf);
//      //azmn[i][0]=(x>=0?x:maxinf);
//		amax[i][0]=x;
//		amin[i][0]=x;
//		if(x<0) afmx[i][0]=x;
//		else afmx[i][0]=mininf;
//		if(x>=0) azmn[i][0]=x;
//		else azmn[i][0]=maxinf;
//	}
//
//	for(int i=1; i<=m; ++i) {
//		int x;
//		scanf("%lld",&x);
//		bmax[i][0]=bmin[i][0]=x;
//	}
//
//	for(int i=2; i<=max(m,n); ++i) lg[i]=lg[i>>1]+1;
//
//	for(int j=1; j<=lg[n]; ++j) {
//		for(int i=1; i+(1<<j)-1<=n; ++i) {
//			int pcr=i+(1<<(j-1));
//			amax[i][j]=max(amax[i][j-1],amax[pcr][j-1]);
//			afmx[i][j]=max(afmx[i][j-1],afmx[pcr][j-1]);
//			amin[i][j]=min(amin[i][j-1],amin[pcr][j-1]);
//			azmn[i][j]=min(azmn[i][j-1],azmn[pcr][j-1]);
//		}
//	}
//
//	for(int j=1; j<=lg[m]; ++j) {
//		for(int i=1; i+(1<<j)-1<=m; ++i) {
//			int pcr=i+(1<<(j-1));
//			bmax[i][j]=max(bmax[i][j-1],bmax[pcr][j-1]);
//			bmin[i][j]=min(bmin[i][j-1],bmin[pcr][j-1]);
//		}
//	}
//
//	while(q--) {
//		int l1,r1,l2,r2;
//		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
//
//		int sa=lg[r1-l1+1];
//		int sb=lg[r2-l2+1];
//
//		int pcr1=r1-(1<<sa)+1;
//		int pcr2=r2-(1<<sb)+1;
//		int sa = lg[r1 - l1 + 1], sb = lg[r2 - l2 + 1];
//        int pcr1 = r1 - (1 << sa) + 1, pcr2 = r2 - (1 << sb) + 1;
//
//		int amaxn=max(amax[l1][sa],amax[pcr1][sa]);
//		int aminn=min(amin[l1][sa],amin[pcr1][sa]);
//
//		int afmax=max(afmx[l1][sa],afmx[pcr1][sa]);
//		int azmin=min(azmn[l1][sa],azmn[pcr1][sa]);
//
//		int bmaxn=max(bmax[l2][sb],bmax[pcr2][sb]);
//		int bminn=min(bmin[l2][sb],bmin[pcr2][sb]);
//
//		int ans=mininf;
//
//		if(amaxn>=0) amaxn*=bminn;
//		else amaxn*=bmaxn;
//		ans=max(ans,amaxn);
//		
//		if(aminn>=0) aminn*=bminn;
//		else aminn*=bmaxn;
//		ans=max(ans,aminn);
//
//		gmx(ans,amaxn*(amaxn>=0?bminn:bmaxn));
//        gmx(ans,aminn*(aminn>=0?bminn:bmaxn));
//
//		if(afmax!=mininf) {
//			if(afmax>=0) afmax*=bminn;
//			else afmax*=bmaxn;
//			ans=max(ans,afmax);
//		}
//		
//		if(azmin!=maxinf) {
//			if(azmin>=0) azmin*=bminn;
//			else azmin*=bmaxn;
//			ans=max(ans,azmin);
//		}
//
//       if (afmax!=mininf) gmx(ans,afmax*(afmax>=0?bminn:bmaxn));
//       if (azmin!=maxinf) gmx(ans,azmin*(azmin>=0?bminn:bmaxn));
//
//		printf("%lld\n",ans);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P8818 [CSP-S 2022] 策略游戏(线段树) 
//#include<bits/stdc++.h>
//#define int long long
//#define Maxn (int)1e5 + 4
//#define inf (int)2e9
//#define L fa << 1
//#define R fa << 1 | 1
//#define mid (l+r >> 1)
//using namespace std;
//
//struct t {
//	bool neg,posi,zero;
//	int maxn,minn,maxneg,minnposi;
//};
//t a[Maxn << 2],b[Maxn << 2];
//
//int A[Maxn],B[Maxn];
//t merge(t a,t b) {
//	return (t) {
//		a.neg|b.neg, a.posi|b.posi, a.zero|b.zero,
//		max(a.maxn,b.maxn), min(a.minn,b.minn), max(a.maxneg,b.maxneg), min(a.minnposi,b.minnposi)
//	};
//}
//void build_a(int fa,int l,int r) {
//	a[fa].maxneg = -inf, a[fa].minnposi = inf;
//	if(l == r) {
//		if(A[l] < 0) {
//			a[fa].neg = 1;
//			a[fa].maxneg = A[l];
//		}
//		if(A[l] == 0) a[fa].zero = 1;
//		if(A[l] > 0) {
//			a[fa].posi = 1;
//			a[fa].minnposi = A[l];
//		}
//		a[fa].maxn = a[fa].minn = A[l];
//		return ;
//	}
//	build_a(L,l,mid), build_a(R,mid+1,r);
//	a[fa] = merge(a[L],a[R]);
//}
//void build_b(int fa,int l,int r) {
//	b[fa].maxneg = -inf, b[fa].minnposi = inf;
//	if(l == r) {
//		if(B[l] < 0) {
//			b[fa].neg = 1;
//			b[fa].maxneg = B[l];
//		}
//		if(B[l] == 0) b[fa].zero = 1;
//		if(B[l] > 0) {
//			b[fa].posi = 1;
//			b[fa].minnposi = B[l];
//		}
//		b[fa].maxn = b[fa].minn = B[l];
//		return ;
//	}
//	build_b(L,l,mid), build_b(R,mid+1,r);
//	b[fa] = merge(b[L],b[R]);
//}
//t query_a(int fa,int l,int r,int ql,int qr) {
//	if(ql <= l && r <= qr) return a[fa];
//
//	if(qr <= mid) return query_a(L,l,mid,ql,qr);
//	else if(ql > mid) return query_a(R,mid+1,r,ql,qr);
//	else {
//		t res;
//		t ls = query_a(L,l,mid,ql,qr);
//		t rs = query_a(R,mid+1,r,ql,qr);
//		res = merge(ls,rs);
//		return res;
//	}
//}
//t query_b(int fa,int l,int r,int ql,int qr) {
//	if(ql <= l && r <= qr) return b[fa];
//
//	if(qr <= mid) return query_b(L,l,mid,ql,qr);
//	else if(ql > mid) return query_b(R,mid+1,r,ql,qr);
//	else {
//		t res;
//		t ls = query_b(L,l,mid,ql,qr);
//		t rs = query_b(R,mid+1,r,ql,qr);
//		res = merge(ls,rs);
//		return res;
//	}
//}
//
//int judge(t a,t b) {
//
//	int res;
//	if(a.posi && !(a.neg | a.zero)) {
//		if(b.neg) res = a.minn * b.minn;
//		else res = a.maxn * b.minn;
//	} else if(a.neg && !(a.posi | a.zero)) {
//		if(b.posi) res = a.maxn * b.maxn;
//		else res = a.minn * b.maxn;
//	} else if(a.zero && !(a.posi | a.neg)) {
//		res = 0;
//	} else if(a.posi && a.zero && !a.neg) {
//		if(b.posi && !(b.neg | b.zero)) res = a.maxn * b.minn;
//		else res = 0;//
//	} else if(a.neg && a.posi && !a.zero) {
//		if(b.posi && !(b.neg | b.zero)) res = a.maxn * b.minn;
//		else if(!b.zero) {
//			if(b.posi) {
//				res = max(a.minnposi*b.minn, a.maxneg*b.maxn);
//			} else res = a.minn*b.maxn;
//		} else res = max(a.minnposi*b.minn, a.maxneg*b.maxn);
//	} else if(a.neg && a.zero && !a.posi) {
//		if(b.neg && !(b.posi | b.zero)) res = a.minn*b.maxn;
//		else res = 0;
//	} else if(a.neg && a.zero && a.posi) {
//		if(b.posi && !(b.neg | b.zero)) {
//			res = a.maxn*b.minn;
//		} else if(b.neg && !(b.posi | b.zero)) {
//			res = a.minn*b.maxn;
//		} else res = 0;
//	}
//	return res;
//}
//signed main() {
//
//	int n,m,q;
//	scanf("%lld %lld %lld",&n,&m,&q);
//	for(int i = 1; i <= n; i ++) scanf("%lld",&A[i]);
//	for(int i = 1; i <= m; i ++) scanf("%lld",&B[i]);
//	build_a(1,1,n), build_b(1,1,m);
//
//	for(int i = 1; i <= q; i ++) {
//		int l1,r1,l2,r2;
//		scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
//		t a = query_a(1,1,n,l1,r1);
//		t b = query_b(1,1,m,l2,r2);
//		printf("%lld\n",judge(a,b));
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2367 语文成绩
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 5000005
//using namespace std;
//int n,pp;
//int a[maxn],p[maxn],cr[maxn];
//signed main() {
//	scanf("%lld%lld",&n,&pp);
//	for(int i=1;i<=n;i++) {
//		scanf("%lld",&a[i]);
//		p[i]=a[i]-a[i-1];
//	}
//	for(int i=1;i<=pp;i++) {
//		int x,y,z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		p[x]+=z;
//		p[y+1]-=z;
//	}
//	int ans=1e18;
//	for(int i=1;i<=n;i++) {
//		cr[i]=p[i]+cr[i-1];
//		ans=min(ans,cr[i]);
//	}
//	cout<<ans;
//	for(int i=1;i<=n;i++) cout<<cr[i]<<" ";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF173A Rock-Paper-Scissors
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000005
//using namespace std;
//int ans,cnt,n,step;
//char first[maxn],last[maxn];
//void ck(char x,char y) {
//	if(x==y)return;
//	if(x=='R'&&y=='P') {
//		ans++;
//		return;
//	}
//	if(x=='R'&&y=='S') {
//		cnt++;
//		return;
//	}
//	if(x=='P'&&y=='R') {
//		cnt++;
//		return;
//	}
//	if(x=='P'&&y=='S') {
//		ans++;
//		return;
//	}
//	if(x=='S'&&y=='R') {
//		ans++;
//		return;
//	}
//	if(x=='S'&&y=='P') {
//		cnt++;
//		return;
//	}
//}
//int gcd(int x,int y) {
//	int maxnn=max(x,y);
//	for(int i=maxnn; i<=x*y; i+=maxnn)
//		if(i%x==0&&i%y==0)
//			return i;
//	return 0;
//}
//signed main() {
//	scanf("%lld",&n);
//	scanf("%s",first+1);
//	scanf("%s",last+1);
//	int len1=strlen(first+1);
//	int len2=strlen(last+1);
//	int m=gcd(len1,len2);
//	for(int i=len1+1; i<=m; i++) {
//		first[i]=first[++step];
//		if(step==len1)step=0;
//	}
//	step=0;
//	for(int i=len2+1; i<=m; i++) {
//		last[i]=last[++step];
//		if(step==len2)step=0;
//	}
//	for(int i=1; i<=m; i++) ck(first[i],last[i]);
//	int size=n/m;
//	n%=m;
//	ans*=size;
//	cnt*=size;
//	for(int i=1; i<=n; i++) ck(first[i],last[i]);
//	printf("%lld %lld\n",ans,cnt);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B - Problem About Equation CodeForces - 174A
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,b,maxn=-1e18,minn=1e18;
//int a[105];
//double d[105];
//signed main() {
//	scanf("%lld%lld",&n,&b);
//	for(int i=1;i<=n;i++) {
//		scanf("%lld",&a[i]);
//		maxn=max(maxn,a[i]);
//		minn=min(minn,a[i]);
//	}
//	for(int i=1;i<=n;i++) {
//		d[i]=maxn-a[i];
//		b-=d[i];
//		a[i]+=d[i];
//	}
//	if(b<0) {
//		cout<<-1;
//		return 0;
//	}
//	double sheng=b*1.0/n*1.0;
//	for(int i=1;i<=n;i++) d[i]+=sheng;
//	for(int i=1;i<=n;i++) {
//		printf("%.6lf\n",d[i]);
//	} 
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1083 [NOIP2012 提高组] 借教室(线段树)
//#include<bits/stdc++.h>
//#define maxn 1000005
//#define lc rt<<1
//#define rc rt<<1|1
//using namespace std;
//#define mid ((l+r)>>1)
//#define lson rt<<1,l,mid
//#define rson rt<<1|1,mid+1,r
//inline void read(int &x) {
//	char c=getchar();
//	int p=1;
//	x=0;
//	while(!isdigit(c)) {
//		if(c=='-')p=-1;
//		c=getchar();
//	}
//	while(isdigit(c)) {
//		x=(x<<1)+(x<<3)+(c^'0');
//		c=getchar();
//	}
//	x*=p;
//}
//int n,m;
//int minn[maxn<<2],tag[maxn<<2],a[maxn];
//void push_up(int rt) {
//	minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);
//	minn[rt]=min(minn[lc],minn[rc]);
//}
//void build(int rt,int l,int r) {
//	if(l==r) read(minn[rt]);
//	if(l==r) {
//		minn[rt]=a[l];
//		return ;
//	}
//	else {
//		build(lson);
//		build(rson);
//		int mid=(l+r)>>1;
//		build(lc,l,mid);
//		build(rc,mid+1,r);
//		push_up(rt);
//	}
//}
//void push_down(int rt) {
//	minn[rt<<1]-=tag[rt];
//	minn[rt<<1|1]-=tag[rt];
//	tag[rt<<1]+=tag[rt];
//	tag[rt<<1|1]+=tag[rt];
//	minn[lc]-=tag[rt];
//	minn[rc]-=tag[rt];
//	tag[lc]+=tag[rt];
//	tag[rc]+=tag[rt];
//	tag[rt]=0;
//}
//void update(int rt,int l,int r,int L,int R,int pcr) {
//	if(l>=L&&r<=R) {
//		minn[rt]-=pcr;
//		tag[rt]+=pcr;
//	} else {
//		if(tag[rt])push_down(rt);
//		if(L<=mid) update(lson,L,R,pcr);
//		if(R>mid) update(rson,L,R,pcr);
//		push_up(rt);
//	}
//}
//void update(int rt,int l,int r,int L,int R,int pcr) {
//	if(l<=L&&R<=r) {
//		minn[rt]-=pcr;
//		tag[rt]+=pcr;
//	} else {
//		if(tag[rt]) push_down(rt);
//		int mid=(L+R)>>1;
//		if(l<=mid) update(lc,l,r,L,mid,pcr);
//		if(r>mid)  update(rc,l,r,mid+1,R,pcr);
//		push_up(rt);
//	}
//}
//signed main() {
//	read(n);
//	read(m);
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	build(1,1,n);
//	for(int i=1;i<=m;i++) {
//		int d,s,t;
//		cin>>d>>s>>t;
//		cout<<i<<endl;
//		update(1,s,t,1,n,d);
//		if(minn[1]<0) {
//			cout<<-1<<endl<<i;
//			return 0;
//		}
//	}
//	cout<<0;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1083 [NOIP2012 提高组] 借教室(差分+二分)
//#include<bits/stdc++.h> 
//#define int long long
//using namespace std;
//int n,m;
//int diff[1000011],need[1000011],rest[1000011],r[1000011],l[1000011],d[1000011];
//bool isok(int x) {
//	memset(diff,0,sizeof(diff));
//	for(int i=1; i<=x; i++) {
//		diff[l[i]]+=d[i];
//		diff[r[i]+1]-=d[i];
//	}
//	for(int i=1; i<=n; i++) {
//		need[i]=need[i-1]+diff[i];
//		if(need[i]>rest[i])return 0;
//	}
//	return 1;
//}
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1; i<=n; i++)scanf("%lld",&rest[i]);
//	for(int i=1; i<=m; i++)scanf("%lld%lld%lld",&d[i],&l[i],&r[i]);
//	int begin=1,end=m;
//	if(isok(m)) {
//		cout<<"0";
//		return 0;
//	}
//	while(begin<end) {
//		int mid=(begin+end)/2;
//		if(isok(mid))begin=mid+1;
//		else end=mid;
//	}
//	cout<<"-1"<<endl<<begin;
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//A. Prime Deletion
//#include <bits/stdc++.h>
//using namespace std;
//int T,a[100]; 
//bool ifprime[100];
//string s;
//void pcr(){
//	ifprime[2]=true;
//	for(int i=3;i<=100;i++) {
//		bool flag=false;
//		for(int j=2;j<=sqrt(i);j++) {
//			if(i%j==0) {
//				flag=true;
//				continue;
//			}
//		}
//		if(flag==false) ifprime[i]=true;
//	}
//}
//signed main() {
//	scanf("%d",&T);
//	memset(ifprime,false,sizeof(ifprime));
//	pcr();
//	while(T--) {
//		bool flag=false;
//		cin>>s;
//		for(int i=0;i<s.size();i++) a[s[i]-'0']=i; 
//		for(int i=0;i<s.size()-1&&flag==false;i++) {
//			for(int j=i+1;j<s.size()&&flag==false;j++) {
//				int num=int(s[i]-'0')*10+int(s[j]-'0');
//				if(ifprime[num]==true) {
//					printf("%d\n",num);
//					flag=true;
//				}
//			}
//		}
//		if(flag=false) printf("-1\n");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B-Two Binary Strings
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int t;
//string a,b;
//signed main() {
//	scanf("%lld",&t);
//	while(t--) {
//		bool flag=false;
//		cin>>a;
//		cin>>b;
//		for(int i=0;i<a.size();i++) 
//			if(a[i]=='0'&&b[i]=='0'&&a[i+1]=='1'&&b[i+1]=='1') 
//				flag=true;
//		if(flag==true) cout<<"YES\n";
//		else cout<<"NO\n";
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//C. Queries for the Array
//#include<bits/stdc++.h>
//using namespace std;
//int T,L,R;
//int f[200005],fl;
//int main(){
//	scanf("%d",&T);
//	while(T--){
//		string a;
//		cin>>a;
//		memset(f,0,sizeof(f));
//		f[0]=f[1]=1;
//		fl=0;L=R=0;
//		for(int i=0;i<a.length()&&!fl;i++){
//			if(a[i]=='+'){
//				R++;
//				if(f[R-1]==2) f[R]=2;
//			}
//			else if(a[i]=='-'){
//				if(R==0) fl=1;
//				f[R--]=0;
//				L=min(L,R);
//			} 
//			else if(a[i]=='1') {
//				if(f[R]==2) fl=1;
//				L=R;
//			}
//			else if(a[i]=='0'){
//				if(R<2) fl=1;
//				else if(L>=R) fl=1;
//				f[R]=2;
//			}
//		}
//		if(fl) printf("NO\n");
//		else printf("YES\n");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[AGC013C] Ants on a Circle AT_agc013_c
//#include <bits/stdc++.h>
//#define maxn 1000010
//using namespace std;
//int n,l,t,sum;
//struct aa {
//	int x,d;
//} a[maxn];
//bool cmp(aa pc,aa y) {
//	return pc.x<y.x;
//}
//int main() {
//	scanf("%d%d%d",&n,&l,&t);
//	for(int i=1; i<=n; i++) {
//		scanf("%d%d",&a[i].x,&a[i].d);
//		a[i].d--;
//	}
//	for(int i=1; i<=n; i++) {
//		if(!a[i].d) a[i].x+=t;
//		else a[i].x-=t;
//		sum+=a[i].x/l;
//		if(a[i].x%l<0) sum--;
//		a[i].x=(a[i].x%l+l)%l;
//	}
//	sort(a+1,a+n+1,cmp);
//	sum=(sum%n+n)%n;
//	for(int i=sum+1; i<=n; i++) printf("%d\n",a[i].x);
//	for(int i=1; i<=sum; i++) printf("%d\n",a[i].x);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2052 [NOI2011] 道路修建 
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000007
//using namespace std;
//int n,cnt,ans;
//int siz[maxn];
//struct aa{
//	int u,w;
//};
//vector<aa> P[maxn];
//void dfs(int x,int fa){
//	siz[x]=1;
//	for(int i=0;i<P[x].size();i++) {
//		int to=P[x][i].u;
//		if(fa==to) continue;
//		dfs(to,x);
//		siz[x]+=siz[to];
//		ans+=P[x][i].w*abs(2*siz[to]-n);
//	}
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<n;i++) {
//		int x,y,z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		P[x].push_back((aa){y,z});
//		P[y].push_back((aa){x,z});
//	}
//	dfs(1,0);
//	printf("%lld\n",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF977E Cyclic Components
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int n,m;
//vector<int> P[maxn];
//bool vis[maxn];
//int ans=0;
//void dfs(int x){
//	ans++;
//	vis[x]=true;
//	for(int i=0;i<P[x].size();i++) 
//		if(vis[P[x][i]]==false) 
//			dfs(P[x][i]);
//}
//signed main(){
//	memset(vis,false,sizeof(vis));
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=m;i++) {
//		int u,w;
//		scanf("%lld%lld",&u,&w);
//		P[u].push_back(w);
//		P[w].push_back(u);
//	}
//	for(int i=1;i<=n;i++) 
//		if(P[i].size()!=2) 
//			dfs(i);
//	int sum=0;
//	for(int i=1;i<=n;i++) {
//		if(vis[i]==false) {
//			ans=0;
//			dfs(i);
//			if(ans>2) sum++;
//		}
//	}
//	cout<<sum;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A. Two Vessels
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int t,a,b,c;
//signed main() {
//	scanf("%lld",&t);
//	for(int i=1;i<=t;i++) {
//		scanf("%lld%lld%lld",&a,&b,&c);
//		if(a==b) {
//			printf("0\n");
//			continue;
//		} else {
//			int p=(a+b)/2;
//			int r=abs(p-max(a,b));
//			if(r%c==0) cout<<r/c<<endl;
//			else cout<<r/c+1<<endl; 
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2962 [USACO09NOV] Lights G
//#include<bits/stdc++.h>
//using namespace std;
//map<long long,int>mp;
//int n,m;
//int mid,flag,minn=0x7f7f7f7f;
//long long ed,q[41],p[41];
//void dfs(int x,long long now,int step) {
//	if(x==mid+1) {
//		if(now==ed)
//			minn=min(step,minn);
//		if(!flag) {
//			int tmp=mp[now];
//			if(!tmp||tmp>step)      
//				mp[now]=step;
//		} else {
//			int tmp=mp[ed-now];     
//			if(!tmp) return ;
//			minn=min(tmp+step ,minn);  
//		}
//		return ;
//	}
//	dfs(x+1,now,step);
//	dfs(x+1,now^q[x] ,step+1);      
//}
//int main() {
//	p[1]=1;
//	for(int i=2; i<=40; i++)
//		p[i]=p[i-1]<<1;       
//	scanf("%d%d",&n,&m);
//	ed=p[n+1]-1;
//	for(int i=1; i<=m; i++) {
//		int x,y;
//		scanf("%d%d",&x,&y);
//		q[x]+=p[y];
//		q[y]+=p[x];
//	}
//	for(int i=1; i<=n; i++)
//		q[i]^=p[i];    
//	mid=n/2;
//	dfs(1,0,0);
//	flag=1;
//	mid=n;
//	dfs(n/2+1,0,0);    
//	cout<<minn;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A - Kefa and Park
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 1000005
//using namespace std;
//int n,m,ans=0;
//int a[maxn];
//vector <int> P[maxn];
//void dfs(int now,int fa,int sum){
//	if(P[now].size()==1&&now!=1){
//		if(sum<=m) ans++;
//		return ;
//	} 
//	for(int i=0;i<P[now].size();i++) {
//		int v=P[now][i];
//		if(v==fa) continue;
//		if(a[v]==0) dfs(v,now,0);
//		else if(sum+1<=m) dfs(v,now,sum+1); 
//	}
//}
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<n;i++) {
//		int u,v;
//		scanf("%lld%lld",&u,&v);
//		P[u].push_back(v);
//		P[v].push_back(u);
//	}
//	dfs(1,0,a[1]);
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A. MEXanized Array
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int t;
//int a[201];
//signed main() {
//	scanf("%lld",&t);
//	while(t--) {
//		int n,k,x;
//		scanf("%lld%lld%lld",&n,&k,&x);
//		if(x+1<k||n<k) printf("-1\n");
//		else {
//			int sum=(k-1)*k/2;
//			int cnt=n-k;
//			int ans=sum+cnt*x;
//			if(k==x) {
//				printf("%lld\n",ans-cnt);
//			}
//			else printf("%lld\n",ans);
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B. Friendly Arrays
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int t,ans_max,ans_min;
//int a[maxn],b[maxn];
//signed main() {
//	scanf("%lld",&t);
//	while(t--) {
//		int n,m,bi=0;
//		scanf("%lld%lld",&n,&m);
//		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//		for(int i=1;i<=m;i++) scanf("%lld",&b[i]),bi|=b[i];
//		if(n%2!=0) {
//			ans_min=a[1];
//			for(int i=2;i<=n;i++) ans_min^=a[i];
//			for(int i=1;i<=n;i++) a[i]|=bi;
//			ans_max=a[1];
//			for(int i=2;i<=n;i++) ans_max^=a[i];
//			printf("%lld %lld\n",ans_min,ans_max);
//		}
//		if(n%2==0) {
//			ans_min=a[1];
//			for(int i=2;i<=n;i++) ans_min^=a[i];
//			for(int i=1;i<=n;i++) a[i]|=bi;
//			ans_max=a[1];
//			for(int i=2;i<=n;i++) ans_max^=a[i];
//			printf("%lld %lld\n",ans_max,ans_min);
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//C. Colorful Table
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int t;
//int a[maxn],c[maxn],used[maxn],used1[maxn];
//bool Used[maxn];
//signed main() {
//	scanf("%lld",&t);
//	while(t--) {
//		int n,k;
//		int top=1;
//		memset(used,0,sizeof(used));
//		memset(Used,false,sizeof(Used));
//		memset(used1,0,sizeof(used1));
//		scanf("%lld%lld",&n,&k);
//		for(int i=1; i<=n; i++) {
//			scanf("%lld",&a[i]);
//			Used[a[i]]=true;
//		}
//		for(int i=1; i<=n; i++) {
//			if(top<=a[i]) {
//				for(int j=top; j<=a[i]; j++) used[j]=i;
//				top=a[i]+1;
//			}
//		}
//		for(int i=1; i<=n; i++) {
//			if(used[a[i]]>=i) used[a[i]]=i;
//		}
//		top=1;
//		for(int i=n; i>=1; i--) {
//			if(top<=a[i]) {
//				for(int j=top; j<=a[i]; j++) {
//					used1[j]=i;
//				}
//				top=a[i]+1;
//			}
//		}
//		for(int i=n; i>=1; i--) {
//			if(used1[a[i]]<=i) used1[a[i]]=i;
//		}
//		for(int i=1; i<=k; i++) {
//			if(Used[i]==false) cout<<0<<" ";
//			else {
//				int ans=2*(used1[i]-used[i]+1);
//				printf("%lld ",ans);
//			}
//		}
//		if(n==3&&k==5) {
//			cout<<endl<<used1[3]<<" "<<used[3];
//		}
//		puts("");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1149 [NOIP2008 提高组] 火柴棒等式
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n;
//int a[2005]= {6};
//int gs[10]= {6,2,5,5,4,5,6,3,7,6};
//int ans=0;
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1; i<=2005; i++) {
//		int j=i;
//		while(j>=1) {
//			a[i]+=gs[j%10];
//			j/=10;
//		}
//	}
//	for(int i=0; i<=1000; i++) {
//		for(int j=0; j<=1000; j++)
//			if(a[i]+a[j]+a[i+j]+4==n) ans++;
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//G - Cthulhu
//#include<bits/stdc++.h>
//#define int long long 
//#define maxn 1005
//using namespace std;
//int n,m;
//int mp[maxn][maxn];
//bool vis[maxn];
//void dfs(int x){
//	vis[x]=true;
//	for(int i=1;i<=n;i++) {
//		if(mp[x][i]==1&&vis[i]==false) {
//			dfs(i);
//		}
//	}
//}
//signed main(){
//	memset(vis,false,sizeof(vis));
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=m;i++) {
//		int u,v;
//		scanf("%lld%lld",&u,&v);
//		mp[u][v]=1;
//		mp[v][u]=1;
//	}
//	if(m!=n) {
//		cout<<"NO";
//		return 0;
//	}
//	dfs(1);
//	for(int i=1;i<=n;i++) {
//		if(vis[i]==false) {
//			cout<<"NO";
//			return 0;
//		}
//	}
//	cout<<"FHTAGN!";
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF177C1 Party   CF177C2 Party
//#include<bits/stdc++.h>
//#define maxn 2005
//#define int long long
//using namespace std;
//int n,k,m;
//int fa[maxn];
//int vis[maxn];
//int ansn[maxn];
//int find(int x) {
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//signed main() {
//	scanf("%lld%lld",&n,&k);
//	for(int i=1; i<=n; i++) fa[i]=i;
//	for(int i=1; i<=k; i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		fa[find(x)]=find(y);
//	}
//	scanf("%lld",&m);
//	for(int i=1; i<=m; i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		if(find(x)!=find(y)) continue;
//		else vis[find(x)]=1,vis[find(y)]=1;
//	}
//	for(int i=1;i<=n;i++) ansn[find(i)]++;
//	int ans=0;
//	for(int i=1;i<=n;i++) {
//		if(vis[i]!=1||fa[i]!=i) ans=max(ans,ansn[i]);
//	}
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF977E Cyclic Components
//#include<bits/stdc++.h>
//#define maxn 200005
//#define int long long
//using namespace std;
//int n,m,ans=0;
//vector <int> P[maxn];
//bool vis[maxn];
//void dfs(int x){
//	ans++;
//	vis[x]=true;
//	for(int i=0;i<P[x].size();i++) 
//		if(vis[P[x][i]]==false) 
//			dfs(P[x][i]);
//}
//signed main(){
//	memset(vis,false,sizeof(vis));
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=m;i++) {
//		int u,v;
//		scanf("%lld%lld",&u,&v);
//		P[u].push_back(v);
//		P[v].push_back(u);
//	}
//	for(int i=1;i<=n;i++) 
//		if(P[i].size()!=2) 
//			dfs(i);
//	int sum=0;
//	for(int i=1;i<=n;i++) {
//		if(vis[i]==false) {
//			ans=0;
//			dfs(i);
//			if(ans>2) sum++;
//		}
//	}
//	cout<<sum;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF771A Bear and Friendship Condition
//#include<bits/stdc++.h>
//#define maxn 150005
//#define int long long
//using namespace std;
//int n,m;
//int fa[maxn];
//int sum[maxn];
//int find(int x){
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//signed main(){
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=n;i++) fa[i]=i,sum[i]=1;
//	for(int i=1;i<=m;i++) {
//		int u,v;
//		scanf("%lld%lld",&u,&v);
//		int fu=find(u);
//		int fv=find(v);
//		if(fu!=fv) fa[fu]=fv,sum[fv]+=sum[fu];
//	}
//	int ans=0;
//	for(int i=1;i<=n;i++) 
//		if(find(i)==i) 
//			ans+=sum[i]*(sum[i]-1)/2;
//	if(ans==m) cout<<"YES";
//	else cout<<"NO";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1263D Secret Passwords
//#include<bits/stdc++.h>
//#define maxn 1005
//#define int long long
//using namespace std;
//int n;
//int fa[maxn];
//int vis[maxn];
//string s;
//int find(int x){
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int k=1;k<=n;k++) {
//		cin>>s;
//		for(int i=0;i<s.size();i++){
//			if(fa[s[i]-'a'+1]==0) fa[s[i]-'a'+1]=s[i]-'a'+1;
//			if(i!=0) fa[find(s[i]-'a'+1)]=find(s[i-1]-'a'+1);
//		}
//	}
//	int ans=0;
//	for(int i=1;i<=26;i++) 
//		if(fa[i]==i) 
//			ans++;
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1851E Nastya and Potions
//#include<bits/stdc++.h>
//#define maxn 200005
//#define int long long
//using namespace std;
//int T;
//int c[maxn];
//int cost[maxn],ans[maxn];
//vector <int> P[maxn];
//int dfs(int x){
//	if(ans[x]<1e18) return ans[x];
//	ans[x]=min(ans[x],c[x]);
//	int sum=0;
//	for(int i=0;i<P[x].size();i++) sum+=dfs(P[x][i]);
//	if(P[x].size()==0) sum=1e18;
//	ans[x]=min(ans[x],sum);
//	return ans[x];
//}
//signed main(){
//	scanf("%lld",&T);
//	while(T--) {
//		int n,k;
//		scanf("%lld%lld",&n,&k);
//		for(int i=1;i<=n;i++) ans[i]=1e18;
//		memset(P,0,sizeof(P));
//		for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
//		for(int i=1;i<=k;i++) {
//			int p;
//			scanf("%lld",&p);
//			ans[p]=0;
//		}
//		for(int i=1;i<=n;i++) {
//			int m;
//			scanf("%lld",&m);
//			for(int j=1;j<=m;j++) {
//				int e;
//				scanf("%lld",&e);
//				P[i].push_back(e);
//			}
//		}
//		for(int i=1;i<=n;i++) cout<<dfs(i)<<" ";
//		puts("");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1139C Edgy Trees
//#include<bits/stdc++.h>
//#define maxn 500005
//#define mod 1000000007
//#define int long long
//using namespace std;
//int n,k;
//int fa[maxn];
//int sum[maxn];
//int find(int x) {
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//int qpow(int a,int b) {
//    int res = 1,base = a;
//    while(b) {
//        if(b & 1) (res *= base) %= mod;
//        (base *= base) %= mod;
//        b >>= 1;
//    }
//    return res;
//} // 快速幂
//signed main() {
//	scanf("%lld%lld",&n,&k);
//	for(int i=1; i<=n; i++) fa[i]=i;
//	for(int i=1; i<n; i++) {
//		int u,v,w;
//		scanf("%lld%lld%lld",&u,&v,&w);
//		if(w==0) {
//			if(find(u)!=find(v)) {
//				fa[find(u)]=find(v);
//			}
//		}
//	} 
//	for(int i=1; i<=n; i++) sum[find(i)]++;
//	int cnt=0;
//	for(int i=1; i<=n; i++) {
//		if(sum[i]>0) {
//			cnt=(cnt+qpow(sum[i],k))%mod;	
//		}
//	}
//	printf("%lld",(qpow(n,k)-cnt+mod)%mod);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1800E2 Unforgivable Curse (hard version)
//#include<bits/stdc++.h>
//#define maxn 100
//#define int long long
//using namespace std;
//int T; 
//int cnt1[maxn],cnt2[maxn];
//signed main(){
//	scanf("%lld",&T);
//	while(T--) {
//		memset(cnt1,0,sizeof(cnt1));
//		memset(cnt2,0,sizeof(cnt2));
//		bool flag=true,flagg=true;
//		int n,k;
//		scanf("%lld%lld",&n,&k);
//		string s,s1;
//		cin>>s>>s1;
//		for(int i=0;i<n;i++) cnt1[s[i]-'a'+1]++;
//		for(int i=0;i<n;i++) cnt2[s1[i]-'a'+1]++;
//		for(int i=1;i<=26;i++) {
//			if(cnt1[i]!=cnt2[i]) {
//				cout<<"NO"<<endl;
//				flag=false;
//				break;
//			}
//		}
//		for(int i=0;i<n&&flag==true;i++) {
//			if(i+k>=n&&i<k) {
//				if(s1[i]!=s[i]) {
//					cout<<"NO"<<endl;
//					flagg=false;
//					break;
//				}
//			}
//		}
//		if(flagg==true&&flag==true) cout<<"YES"<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF770C Online Courses In BSU
//#include<bits/stdc++.h>
//#define maxn 100005
//#define int long long
//using namespace std;
//int n,k,cnt=0;
//int t[maxn];
//vector <int> P[maxn];
//vector <int> ans;
//int vis[maxn];
//bool flag=false;
//void dfs(int x){
//	if(vis[x]==2) return ;
//	if(vis[x]==1) {
//		flag=true;
//		return ;
//	} 
//	vis[x]=1;
//	for(int i=0;i<P[x].size();i++) {
//		int t=P[x][i];
//		dfs(t);
//	}
//	if(x!=0) {
//		ans.push_back(x);
//		vis[x]=2;
//	}
//}
//signed main(){
//	memset(vis,0,sizeof(vis));
//	scanf("%lld%lld",&n,&k);
//	for(int i=1;i<=k;i++) {
//		scanf("%lld",&t[i]);
//		P[0].push_back(t[i]);
//	}
//	for(int i=1;i<=n;i++) {
//		int x;
//		scanf("%lld",&x);
//		for(int j=1;j<=x;j++) {
//			int p;
//			scanf("%lld",&p);
//			P[i].push_back(p);
//		}
//	}
//	dfs(0);
//	if(flag==true) {
//		cout<<-1;
//		return 0;
//	}
//	cout<<ans.size()<<endl;
//	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF744A Hongcow Builds A Nation
//#include<bits/stdc++.h>
//#define maxn 1005
//#define int long long
//using namespace std;
//int n,m,k;
//int fa[maxn];
//int police[maxn];
//int siz[maxn];
//int cnt[maxn];
//int find(int x){
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//signed main(){
//	scanf("%lld%lld%lld",&n,&m,&k);
//	for(int i=1;i<=k;i++) {
//		int p;
//		scanf("%lld",&p);
//		police[p]=1;
//	}
//	for(int i=1;i<=n;i++) fa[i]=i;
//	for(int i=1;i<=m;i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		int fx=find(x);
//		int fy=find(y);
//		fa[fx]=fy;
//	}
//	for(int i=1;i<=n;i++) {
//		int p=find(i);
//		siz[p]++;//联通块大小
//		if(police[i]==1) cnt[p]++;//统计该连通块中的警局数量。
//	}
//	int zs=0,ans=0,add=0,a=0,b=0;
//	for(int i=1;i<=n;i++) {
//		if(fa[i]==i) {
//			zs+=siz[i]*(siz[i]-1)/2;
//			if(cnt[i]==0) add+=a*siz[i],a+=siz[i];
//			else b=max(b,siz[i]);
//		}
//	} 
//	ans=zs-m+a*b+add;
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF574B Bear and Three Musketeers
//#include<bits/stdc++.h>
//#define maxn 5005
//#define int long long
//using namespace std;
//int n,m;
//int mp[maxn][maxn];
//int neb[maxn];
//signed main(){
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=m;i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		mp[x][y]=mp[y][x]=1;
//		neb[x]++;
//		neb[y]++;
//	}
//	int ans=1e18;
//	bool flag=false;
//	for(int k=1;k<=n;k++) {
//		for(int i=1;i<=n;i++) {
//			if(k==i||mp[i][k]==0) continue; 
//			for(int j=1;j<=n;j++) {
//				if(i==j||mp[i][j]==0) continue;
//				if(mp[i][j]==1&&mp[k][i]==1&&mp[j][k]==1) {
//					flag=true;
//					ans=min(ans,neb[i]+neb[j]+neb[k]-6);
//				}
//			}
//		}
//	}
//	if(flag==false) cout<<"-1";
//	else cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A.Increasing Sequence
//#include<bits/stdc++.h>
//#define maxn 1005
//#define int long long
//using namespace std;
//int T;
//int a[105];
//signed main(){
//	scanf("%lld",&T);
//	while(T--) {
//		int n;
//		scanf("%lld",&n);
//		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//		int ans=0;
//		for(int i=1;i<=n;i++) {
//			ans++;
//			if(a[i]==ans) ans++;
//		}
//		cout<<ans<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF320B Ping-Pong (Easy Version)
//#include <bits/stdc++.h>
//#define maxn 1005
//#define int long long
//using namespace std;
//int n;
//int cnt=0;
//struct aa{
//	int l,r;
//}a[maxn];
//bool vis[maxn];
//void dfs(int now){
//	vis[now]=true;
//	for(int i=1;i<=cnt;i++) {
//		aa pc=a[i];
//		if(vis[i]) continue;
//		if((pc.l<a[now].l&&a[now].l<pc.r)||(pc.l<a[now	].r&&a[now].r<pc.r)) dfs(i);
//	}
//}
//signed main() {
//	scanf("%lld",&n);
//	while(n--) {
//		int opt,x,y;
//		scanf("%lld%lld%lld",&opt,&x,&y);
//		if(opt==1) {
//			a[++cnt].l=x;
//			a[cnt].r=y;
//		} else {
//			memset(vis,false,sizeof(vis));	
//			dfs(x);
//			if(vis[y]) cout<<"YES\n";
//			else cout<<"NO\n";
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF954D Fight Against Traffic
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1005
//using namespace std;
//int n,m,s,t;
//int dis[maxn][2];
//bool bj[maxn][maxn],vis[maxn];
//vector<int> g[maxn];
//void bfs(int s,int k) {
//    queue<int> q;
//    memset(vis,0,sizeof(vis));
//    q.push(s);
//	vis[s] = 1;
//    while(!q.empty()) {
//        int fr = q.front(); 
//		q.pop();
//        for(int v : g[fr]) {
//            if(!vis[v]) {
//                vis[v] = 1;
//                q.push(v);
//                dis[v][k] = dis[fr][k] + 1;
//            }
//        }
//    } 
//}
//signed main() {
//    scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
//    memset(dis,0x3f,sizeof(dis)); // dis[u][0] 距起点， dis[u][1] 距终点
//    dis[s][0] = dis[t][1] = 0;
////    for(int i = 1; i <= n; i ++) bj[i][i] = 1;
//    for(int i = 1; i <= m; i ++) {
//        int a,b;
//        scanf("%lld%lld",&a,&b);
//        g[a].push_back(b);
//        g[b].push_back(a);
//        bj[a][b] = bj[b][a] = 1;
//    }
//    bfs(s,0);
//    bfs(t,1);
//    int ans = 0;
//    for(int i = 1; i <= n; i ++) {
//        for(int j = i+1; j <= n; j ++) {
//            if(bj[i][j]) continue;
//            int d1 = dis[i][0] + dis[j][1] + 1, d2 = dis[i][1] + dis[j][0] + 1;
//            if(min(d1,d2) >= dis[s][1]) ans ++;
//        }
//    }
//    cout << ans;
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1833E	Round Dance
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int T,n;
//int fa[maxn];
//map<pair<int,int>,bool> P;
//int find(int x) {
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//int cnt() {
//	int res=0;
//	for(int i=1; i<=n; i++) if(fa[i]==i) res++;
//	return res;
//}
//signed main() {
//	scanf("%lld",&T);
//	while(T--) {
//		P.clear();
//		scanf("%lld",&n);
//		for(int i=1; i<=n; i++) fa[i]=i;
//		int mn=0,mx=n;
//		for(int i=1; i<=n; i++) {
//			int u;
//			scanf("%lld",&u);
//			if(P[make_pair(u,i)]) continue;
//			P[make_pair(i,u)]=1;
//			int t1=find(u),t2=find(i);
//			if(t1==t2) mn++;
//			else fa[t1]=t2;
//		}
//		mx=cnt();
//		if(mx>mn) mn++;
//		printf("%lld %lld\n",mn,mx);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF659E	New Reform
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 100000
//using namespace std;
//int n,m;
//vector <int> P[maxn];
//int fa[maxn];
//bool vis[maxn];
//int find(int x) {
//	if(fa[x]==x) return fa[x];
//	else return fa[x]=find(fa[x]);
//}
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=n;i++) fa[i]=i;
//	for(int i=1;i<=m;i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		int fx=find(x),fy=find(y);
//		if(fx!=fy) {
//			fa[fx]=fy;
//			if(vis[x]||vis[y]||vis[fx]||vis[fy]) vis[x]=vis[y]=vis[fx]=vis[fy]=1;
//		}
//		else vis[x]=vis[y]=vis[fx]=vis[fy]=1;
//	}
//	int ans=0;
//	for(int i=1;i<=n;i++) if(find(i)==i&&!vis[i]) ans++;
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A-Weak Beats
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//string s;
//signed main() {
//	cin>>s;
//	for(int i=0;i<s.size();i++){
//		if(i%2==1&&s[i]=='1') {
//			cout<<"No";
//			return 0;
//		} 
//	}
//	cout<<"Yes";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B-Round-Robin Tournament
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n;
//struct aa{
//	int id;
//	int rk;
//}a[1005];
//bool cmp(aa x,aa y) {
//	if(x.rk!=y.rk) return x.rk>y.rk;
//	else return x.id<y.id;
//}
//signed main() {
//	cin>>n;
//	for(int i=1;i<=n;i++) {
//		a[i].id=i;
//		for(int j=1;j<=n;j++) {
//			char x;
//			cin>>x;
//			if(x=='o') a[i].rk++;
//		}
//	}
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++) cout<<a[i].id<<" ";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//C-World Tour Finals
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 1005
//using namespace std;
//int n,m;
//struct aa {
//	int id;
//	int q;
//} a[maxn],sum[maxn];
//int ans[maxn];
//bool used[maxn][maxn];
//bool cmp(aa x,aa y) {
//	return x.q>y.q;
//}
//signed main() {
//	memset(used,0,sizeof(used));
//	scanf("%lld%lld",&n,&m);
//	for(int i=1; i<=m; i++) {
//		a[i].id=i;
//		scanf("%lld",&a[i].q);
//	}
//	for(int i=1; i<=n; i++) {
//		sum[i].id=i;
//		for(int j=1; j<=m; j++) {
//			char t;
//			cin>>t;
//			if(t=='o') sum[i].q+=a[j].q,used[i][j]=1;
//		}
//		sum[i].q+=sum[i].id;
//	}
//	sort(sum+1,sum+1+n,cmp);
//	sort(a+1,a+1+m,cmp);
//	for(int i=1; i<=n; i++) {
//		if(i==1) ans[sum[1].id]=0;
//		else {
//			int tmp=sum[1].q-sum[i].q;
//			int t1=0;
//			for(int k=1; k<=m; k++) {
//				if(used[sum[i].id][a[k].id]==1) {
//					t1++;
//					continue;
//				}
//				tmp-=a[k].q;
//				if(tmp<=0) {
//					ans[sum[i].id]=k-t1;
//					break;
//				}
//			}
//		}
//	}
//	for(int i=1; i<=n; i++) cout<<ans[i]<<endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//D-Merge Slimes
//#include<bits/stdc++.h>
//using namespace std;
//#define MAXN 100005
//#define int long long
//struct Node{
//    int c,s;
//}node,top;
//bool operator <(Node a,Node b){return a.c<b.c;}
//int n,ans;
//priority_queue<Node> q;
//signed main(){
//    scanf("%lld",&n);
//    for(int i=0;i<n;i++){
//        scanf("%lld%lld",&node.c,&node.s);
//        q.push(node);
//    }
//    while(!q.empty()){
//        bool f=0;
//        top=q.top();
//        q.pop();
//        while(!q.empty()&&q.top().c==top.c){
//            node=q.top();
//            q.pop();
//            top.s+=node.s;
//        }
//        while(top.c%2==0){
//            f=1;
//            top.c>>=1;
//            top.s<<=1;
//        }
//        if(!f){
//            while(top.s){
//                if(top.s%2) ans++;
//                top.s>>=1;
//            }
//        }
//        else q.push(top);
//    }
//    printf("%lld\n",ans);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1133F1 Spanning Tree with Maximum Degree
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int n,m;
//int rt;
//int du[maxn],fa[maxn];
//int u[maxn],v[maxn];
//int find(int x) {
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1; i<=n; i++) fa[i]=i;
//	for(int i=1; i<=m; i++) {
//		scanf("%lld%lld",&u[i],&v[i]);
//		du[u[i]]++;
//		du[v[i]]++;
//	}
//	for(int i=1; i<=n; i++) if(du[i]>du[rt]) rt=i;
//	for(int i=1; i<=m; i++) {
//		if(u[i]==rt||v[i]==rt) {
//			int fu=find(u[i]);
//			int fv=find(v[i]);
//			fa[fu]=fv;
//			printf("%lld %lld\n",v[i],u[i]);
//		}
//	}
//	for(int i=1; i<=m; i++) {
//		if(find(u[i])!=find(v[i])) {
//			int fu=find(u[i]);
//			int fv=find(v[i]);
//			fa[fu]=fv;
//			printf("%lld %lld\n",u[i],v[i]);
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF731C Socks
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int n,m,k;
//int col[maxn],fa[maxn],siz[maxn];
//vector <int> P[maxn];
//int find(int x) {
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//signed main() {
//	scanf("%lld%lld%lld",&n,&m,&k);
//	int ans=0;
//	for(int i=1;i<=n;i++) fa[i]=i;
//	for(int i=1; i<=n; i++) scanf("%lld",&col[i]);
//	for(int i=1; i<=m; i++) {
//		int u,v;
//		scanf("%lld%lld",&u,&v);
//		int fu=find(u),fv=find(v);
//		if(fu!=fv) fa[fu]=fv;
//	}
//	for(int i=1; i<=n; i++) P[find(i)].push_back(i);
//	for(int i=1; i<=n; i++) {
//		int mx=0;
//		for(int j=0; j<P[i].size(); j++) siz[col[P[i][j]]]++;
//		for(int j=0; j<P[i].size(); j++) if(mx<siz[col[P[i][j]]]) mx=siz[col[P[i][j]]];
//		for(int j=0; j<P[i].size(); j++) siz[col[P[i][j]]]--;
//		ans+=P[i].size()-mx;
//	}
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A.鸭运会 
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//string s;
//int T,n;
//signed main() {
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
//	cin>>T;
//	while(T--) {
//		cin>>n>>s;
//		int res,sum;
//		res=sum=0;
//		for(int i=0;i<n;i++) {
//			sum+=i+1;
//			res+=sum;
//			if(~s[i]&1) res+=n-i;
//			if(i&&s[i]==s[i-1]) res+=i*(n-i);
//		}
//		cout<<res<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//CF986A.Fair
//#include<bits/stdc++.h>
//#define maxn (int)1e5 + 4
//#define int long long
//using namespace std;
//int val[maxn],n,m,s,k;
//vector<int> P[maxn],C[maxn];
//bool vis[maxn];
//struct aa {
//	int step,id;
//};
//queue<aa> Q;
//void bfs() {
//	while(!Q.empty()) {
//		int id=Q.front().id;
//		int step=Q.front().step;
//		Q.pop();
//		for(int i=0; i<P[id].size(); i++) {
//			int v=P[id][i];
//			if(vis[v]==false) {
//				vis[v]=true;
//				Q.push({step+1,v});
//				C[v].push_back(step+1);
//			}
//		}
//	}
//}
//signed main() {
//	scanf("%lld%lld%lld%lld",&n,&m,&k,&s);
//	for(int i=1; i<=n; i++) scanf("%lld",&val[i]);
//	for(int i=1; i<=m; i++) {
//		int a,b;
//		scanf("%lld%lld",&a,&b);
//		P[a].push_back(b);
//		P[b].push_back(a);
//	}
//	for(int i=1; i<=k; i++) {
//		while(!Q.empty()) Q.pop();
//		for(int j=1; j<=n; j++) {
//			vis[j]=false;
//			if(val[j]==i) {
//				Q.push({0,j});
//				C[j].push_back(0);
//				vis[j]=true;
//			}
//		}
//		bfs();
//	}
//	for(int i=1; i<=n; i++) {
//		sort(C[i].begin(),C[i].end());
//		int res=0;
//		for(int j=0; j<s; j++) res+=C[i][j];
//		printf("%lld ",res);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P7913 [CSP-S 2021] 廊桥分配
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,m1,m2;
//struct aa {
//	int x,y;
//} a[maxn],b[maxn];
//int res1[maxn],res2[maxn];
//bool cmp(aa x,aa y) {
//	return x.x<y.x;
//}
//void rainbow1() {
//	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> P;
//	priority_queue<int,vector<int>,greater<int >> C;
//	for(int i=1; i<=n; i++) C.push(i);
//	for(int i=1; i<=m1; i++) {
//		while(!P.empty()&&a[i].x>=P.top().first) {
//			C.push(P.top().second);
//			P.pop();
//		}
//		if(C.empty()) continue;
//		int now=C.top();
//		C.pop();
//		res1[now]++;
//		P.push(make_pair(a[i].y,now));
//	}
//	for(int i=1; i<=n; i++) res1[i]+=res1[i-1];
//}
//void rainbow2() {
//	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> P;
//	priority_queue<int,vector<int>,greater<int >> C;
//	for(int i=1; i<=n; i++) C.push(i);
//	for(int i=1; i<=m2; i++) {
//		while(!P.empty()&&b[i].x>=P.top().first) {
//			C.push(P.top().second);
//			P.pop();
//		}
//		if(C.empty()) continue;
//		int now=C.top();
//		C.pop();
//		res2[now]++;
//		P.push(make_pair(b[i].y,now));
//	}
//	for(int i=1; i<=n; i++) res2[i]+=res2[i-1];
//}
//signed main() {
//	scanf("%lld%lld%lld",&n,&m1,&m2);
//	for(int i=1; i<=m1; i++) scanf("%lld%lld",&a[i].x,&a[i].y);
//	for(int i=1; i<=m2; i++) scanf("%lld%lld",&b[i].x,&b[i].y);
//	sort(a+1,a+m1+1,cmp);
//	sort(b+1,b+m2+1,cmp);
//	rainbow1();
//	rainbow2();
//	int ans=0;
//	for(int i=0; i<=n; i++) ans=max(ans,res1[i]+res2[n-i]);
//	printf("%lld\n",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Problem ID: 19001]A.卡牌 
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 3000005
//using namespace std;
//int n,m,k;
//int a[maxn],b[maxn],c[maxn],d[maxn];
//int sum1,sum[maxn];
//signed main() {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	scanf("%lld%lld%lld",&n,&m,&k);
//	for(int i=1; i<=n; i++) scanf("%lld%lld",&a[i],&b[i]);
//	for(int i=1; i<=m; i++) scanf("%lld%lld",&d[i],&c[i]);
//	int kk=1;
//	for(int i=1; i<=m; i++) {
//		for(int j=d[i-1]+1; j<=d[i]; j++) sum1+=sum[j];
//		for(; sum1<c[i]&&kk<=n; kk++) {
//			int last;
//			sum1+=((b[kk]-1)/d[i]+1)*a[kk];
//			for(int j=d[i]; j<b[kk]; j=last+1) {
//				last=(b[kk]-1)/((b[kk]-1)/j);
//				sum[last+1]+=((b[kk]-1)/(last+1)-(b[kk]-1)/j)*a[kk];
//			}
//		}
//		if(sum1<c[i])printf("-1\n");
//		else printf("%lld\n",kk-1);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3388 【模板】割点（割顶）
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 300005
//using namespace std;
//int n,m;
//vector <int> P[maxn];
//int dfn[maxn],low[maxn];
//bool vis[maxn],flag[maxn];
//int cnt=0,tim=0;
//void Tarjan(int x,int fa) {
//	vis[x]=true;
//	dfn[x]=low[x]=++tim;
//	int chi=0;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(!vis[now]) {
//			chi++;
//			Tarjan(now,x);
//			low[x]=min(low[x],low[now]);
//			if(fa!=x&&!flag[x]&&low[now]>=dfn[x]) {
//				cnt++;
//				flag[x]=true;
//			}
//		} else if(now!=fa) low[x]=min(low[x],dfn[now]);
//	}
//	if(fa==x&&chi>=2) {
//		cnt++;
//		flag[x]=true;
//	} 
//}
//signed main(){
//	memset(vis,false,sizeof(vis));
//	memset(flag,false,sizeof(flag));
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=m;i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	for(int i=1;i<=n;i++) {
//		if(!vis[i]) {
//			tim=0;
//			Tarjan(i,i);
//		}
//	}
//	printf("%lld\n",cnt);
//	for(int i=1;i<=n;i++) if(flag[i]==true) printf("%lld ",i);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1656 炸铁路
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 10001
//using namespace std;
//int n,m,tim=0,cnt;
//int dfn[maxn],low[maxn];
//vector <int> P[maxn];
//struct aa{
//	int from,to;
//}ans[maxn];
//bool cmp(aa x,aa y) {
//	if(x.from!=y.from) return x.from<y.from;
//	else return x.to<y.to;
//}
//void Tarjan(int x,int fa) {
//	dfn[x]=low[x]=++tim;
//	bool flag=false;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(dfn[now] ) {
//			if(now==fa&&!flag) flag=true;
//			else low[x]=min(low[x],dfn[now]);
//		} 
//		if(!dfn[now]) {
//			Tarjan(now,x);
//			if(dfn[x]<low[now]) ans[++cnt].from=min(now,x),ans[cnt].to=max(now,x);
//			low[x]=min(low[x],low[now]);
//		}
//	}
//}
//signed main() {
//	scanf("%lld%lld",&n,&m);
//	for(int i=1; i<=m; i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,i);
//	sort(ans+1,ans+cnt+1,cmp);
//	for(int i=1;i<=cnt;i++) printf("%lld %lld\n",ans[i].from,ans[i].to); 
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1119 灾后重建 
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 310
//using namespace std;
//int n,m,q;
//int t[maxn];
//int mp[maxn][maxn];
//void flord(int k) {
//	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
//}
//signed main(){
//	for(int i=1;i<=305;i++) for(int j=1;j<=305;j++) mp[i][j]=1e18;
//	for(int i=1;i<=n;i++) mp[i][i]=0;
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&t[i]);
//	for(int i=1;i<=m;i++) {
//		int x,y,w;
//		scanf("%lld %lld %lld",&x,&y,&w);
//		x++;
//		y++;
//		mp[x][y]=w;
//		mp[y][x]=w;
//	}
//	scanf("%lld",&q);
//	int now=1;
//	while(q--) {
//		int x,y,p;
//		scanf("%lld %lld %lld",&x,&y,&p);
//		x++;
//		y++;
//		while(t[now]<=p&&now<=n) flord(now++);
//		if(t[x]>p||t[y]>p||mp[x][y]==1e18) cout<<-1<<endl;
//		else cout<<mp[x][y]<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1134 [USACO3.2] 阶乘问题
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a[]={6,6,2,6,4,4,4,8,4,6},b[]={6,8,4,2},r=1,n;
//signed main() {
//	scanf("%lld",&n);
//	while(n)r=r*a[n%10]*b[(n=n/5)%4]%10;
//	printf("%lld",r);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Problem ID: 19001]A.卡牌 
// what is matter? never mind.
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2")
//#include<bits/stdc++.h>
//#define For(i,a,b) for(int i=(a);i<=(b);++i)
//#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
//#define ll long long
//#define ull unsigned long long
//#define int __int128
//#define int long long
//using namespace std;
//inline int read() {
//	char c=getchar();
//	int x=0;
//	bool f=0;
//	for(; !isdigit(c); c=getchar())f^=!(c^45);
//	for(; isdigit(c); c=getchar())x=(x<<1)+(x<<3)+(c^48);
//	if(f)x=-x;
//	return x;
//}
//
//#define mod 998244353
//struct modint {
//	int x;
//	modint(int o=0) { x=o; }
//	modint &operator = (int o) { return x=o,*this; }
//	modint &operator +=(modint o) { return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this; }
//	modint &operator -=(modint o) { return x=x-o.x<0?x-o.x+mod:x-o.x,*this; }
//	modint &operator *=(modint o) { return x=1ll*x*o.x%mod,*this; }
//	modint &operator ^=(int b) {
//		modint a=*this,c=1;
//		for(; b; b>>=1,a*=a)if(b&1)c*=a;
//		return x=c.x,*this;
//	}
//	modint &operator /=(modint o) { return *this *=o^=mod-2; }
//	friend modint operator +(modint a,modint b) { return a+=b; }
//	friend modint operator -(modint a,modint b) { return a-=b; }
//	friend modint operator *(modint a,modint b) { return a*=b; }
//	friend modint operator /(modint a,modint b) { return a/=b; }
//	friend modint operator ^(modint a,int b) { return a^=b; }
//	friend bool operator ==(modint a,int b) { return a.x==b; }
//	friend bool operator !=(modint a,int b) { return a.x!=b; }
//	bool operator ! () { return !x; }
//	modint operator - () { return x?mod-x:0; }
//	bool operator <(const modint&b)const { return x<b.x; }
//};
//inline modint qpow(modint x,int y) { return x^y; }
//#define fi first
//#define se second
//#define pb push_back
//#define mkp make_pair
//typedef pair<int,int>pii;
//typedef vector<int>vi;
//#define maxn 1000005
//#define inf 0x3f3f3f3f
//int n,m,V;
//int a[maxn],b[maxn],a2[maxn],b2[maxn];
//int c[maxn];
//struct bit {
//	vector<int>tr;
//	int n;
//	void init(int N) { n=N,tr=vector<int>(N+1,0); }
//	void add(int x,int y) { for(; x; x-=x&-x)tr[x]+=y; }
//	int ask(int x) {
//		int s=0;
//		for(; x<=n; x+=x&-x)s+=tr[x];
//		return s;
//	}
//} tr;
//
//signed main() {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	n=read(),m=read(),V=read();
//	For(i,1,n) a[i] = read(), b[i] = read();
//	For(i,1,m) a2[i] = read(), b2[i] = read();
//	tr.init(300005);
//	int sum=0,k=0;
//	For(i,1,m) {
//		if(i == 1 || a2[i] != a2[i - 1]) {
//			sum=0;
//			for(int j = 1; j <= V; j += a2[i]) sum+=tr.ask(j);
//		}
//		while(sum < b2[i] && k < n) {
//			++k;
//			sum+=(b[k] + a2[i] - 1) / a2[i] * a[k];
//			tr.add(b[k],a[k]);
//		}
//		if(sum >= b2[i]) cout << k << "\n";
//		else cout << -1 << "\n";
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Problem ID: 19038] B.与 
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N=1e6+10;
//int n,m,l[N],r[N];
//ll x[N];
//bool fail[N];
//int pre[N],suf[N];
//int c[N],fir[N],las[N],b[N];
//namespace Solve {
//	void main() {
//		cin>>n>>m;
//		for(int i=1; i<=m; i++)cin>>l[i]>>r[i]>>x[i];
//		for(int z=60; ~z; z--) {
//			memset(pre,0,sizeof pre);
//			memset(suf,0,sizeof suf);
//			memset(c,0,sizeof c);
//			for(int i=1; i<=m; i++) if(x[i]>>z&1) c[l[i]]++,c[r[i]+1]--;
//			for(int i=2; i<=n; i++) c[i]+=c[i-1];
//			for(int i=1; i<=n; i++) b[i]=b[i-1]+(c[i]==0);
//			fir[n+1]=n+1;
//			for(int i=n; i; i--) fir[i]=(c[i]==1?i:fir[i+1]);
//			for(int i=1; i<=n; i++) las[i]=(c[i]==1?i:las[i-1]);
//			for(int i=1; i<=m; i++) {
//				if(!(x[i]>>z&1)) {
//					if(b[r[i]]-b[l[i]-1])continue;
//					if(fir[l[i]]<=las[r[i]]) {
//						suf[l[i]]++;
//						pre[r[i]]++;
//					} else pre[0]++;
//				}
//			}
//			for(int i=1; i<=n+1; i++) pre[i]+=pre[i-1];
//			for(int i=n; ~i; i--) suf[i]+=suf[i+1];
//			for(int i=1; i<=m; i++) {
//				if(fail[i])continue;
//				if(x[i]>>z&1) if((fir[l[i]]>las[r[i]]&&pre[n])||pre[fir[l[i]]-1]+suf[las[r[i]]+1]) fail[i]=1;
//					else if(pre[n]>(b[r[i]]-b[l[i]-1]==0)) fail[i]=1;
//			}
//		}
//		for(int i=1; i<=m; i++)cout<<(fail[i]?0:1);
//	}
//}
//signed main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
//	Solve::main();
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Problem ID: 19039] C.  graph 
//#include<bits/stdc++.h>
//#define Maxn 1000007
//const int L = 2700;
//using namespace std;
//int p, k, Q, s, f[407][407], from[Maxn], dis[Maxn], T, ans, cnt = -1;
//bool vis[Maxn];
//deque<int> q;
//void solve() {
//	cin >> p >> k >> Q;
//	if(k <= 1) {
//		for(int i = 1, u, v; i <= Q; i ++) {
//			cin >> u >> v;
//			cout << ((u == v) ? 0 : -1) << "\n";
//		}
//		return;
//	}
//	for(int i = 1, res = 1; ; i ++) {
//		res = 1ll * res * k % p;
//		if(res ^ 1) continue;
//		s = i;
//		break;
//	}
//	auto work1 = [&]() {
//		memset(vis, 0, sizeof vis);
//		memset(dis, 0x3f, sizeof dis);
//		dis[0] = 0;
//		q.push_front(0);
//		while(q.size()) {
//			int temp = q.front();
//			q.pop_front();
//			if(vis[temp]) continue;
//			vis[temp] = 1;
//			int nxt = 1ll * k * temp % p;
//			if(dis[nxt] > dis[temp]) {
//				dis[nxt] = dis[temp];
//				q.push_front(nxt);
//			}
//			nxt = (temp + 1) % p;
//			if(dis[nxt] > dis[temp] + 1) {
//				dis[nxt] = dis[temp] + 1;
//				q.push_back(nxt);
//			}
//		}
//		for(int i = 1, u, v; i <= Q; i ++) {
//			cin >> u >> v;
//			ans = p + 1;
//			int res = 1, temp;
//			for(int j = 0; j <= s; j ++) {
//				temp = 1ll * res * u % p;
//				temp = (v - temp + p) % p;
//				res = 1ll * res * k % p;
//				ans = min(ans, dis[temp]);
//			}
//			if(ans != p + 1) cout << ans << "\n";
//			else cout << "-1\n";
//		}
//	};
//	auto work2 = [&]() {
//		memset(from, 0x3f, sizeof from);
//		memset(f, 0x3f, sizeof f);
//		for(int i = 0; i < p; i ++) {
//			if(from[i] > p) from[i] = ++ cnt;
//			else continue;
//			for(int j = 1ll * i * k % p; from[j] > p; j = 1ll * j * k % p) from[j] = cnt;
//		}
//		for(int i = 0; i < p; i ++) f[from[i]][from[(i + 1) % p]] = 1;
//		for(int i = 0; i <= cnt; i ++) f[i][i] = 0;
//		for(int k = 0; k <= cnt; k ++) for(int i = 0; i <= cnt; i ++) for(int j = 0; j <= cnt; j ++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
//		for(int i = 1, u, v; i <= Q; i ++) {
//			cin >> u >> v;
//			if(f[from[u]][from[v]] < p + 1) cout << f[from[u]][from[v]] << "\n";
//			else cout << "-1\n";
//		}
//	};
//	if(s <= L) work1();
//	else work2();
//}
//int main() {
//	freopen("graph.in", "r", stdin);
//	freopen("graph.out", "w", stdout);
//	cin >> T;
//	while(T --) solve();
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Problem ID: 19040]  D.  track
//#include<bits/stdc++.h>
//using namespace std;
//namespace Solve {
//	typedef long long ll;
//	const int N=110,R=10010;
//	int T,n,r[N];
//	bool check(int*x) {
//		int sum=0;
//		for(int i=1; i<=n; i++)sum+=x[i];
//		if(sum&1)return false;
//		bitset<500001>f[2],g[2];
//		f[0][0]=1;
//		for(int i=2; i<=n; i++) {
//			auto t1=g[0]<<r[i];
//			g[0]|=g[1]<<r[i];
//			g[1]|=t1;
//			g[0]|=(f[1]<<r[i]&f[0]);
//			g[1]|=(f[0]<<r[i]&f[1]);
//			t1=f[0]<<r[i];
//			f[0]|=f[1]<<r[i];
//			f[1]|=t1;
//		}
//		return g[0][sum/2];
//	}
//	void main() {
//		cin>>T;
//		while(T--) {
//			cin>>n;
//			for(int i=1; i<=n; i++)cin>>r[i];
//			if(n&1) cout<<"No\n";
//			else {
//				if(check(r)) cout<<"Yes\n";
//				else cout<<"No\n";
//			}
//		}
//	}
//}
//signed main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	freopen("track.in","r",stdin);
//	freopen("track.out","w",stdout);
//	Solve::main();
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Promble ID 19061] A.number
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000001
//#define mod 998244353
//using namespace std;
//int a[maxn]={1};
//int power(int x) {
//	int y=1,i=mod-2;
//	while(i) {
//		if(i&1) y=x*y%mod;
//		x=x*x%mod;
//		i=i>>1;
//	}
//	return y;
//}
//int n,w=1;
//signed main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) a[i]=(a[i-1]<<1)%mod;
//	for(int i=0;i<n;i++) w=w*(mod+a[n]-a[i])%mod;
//	int s=1;
//	for(int i=2;i<=n;i++) s=s*i%mod;
//	printf("%lld\n",w*power(s)%mod);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1079	[NOIP2012 提高组] Vigenère 密码
//#include<bits/stdc++.h>
//using namespace std;
//int i,j,lenk;
//char k[1010],m[1010],kn[1010],ans[1010];
//char c[30][30];
//void passchart() {
//	int i,j;
//	for(i=1; i<=26; i++) c[i][1]=char('a'+i-1);
//	for(j=1; j<=26; j++) c[1][j]=char('a'+j-1);
//	for(i=2; i<=26; i++) for(j=2; j<=26; j++) c[i][j]=(int(c[1][j]-'a')+int(c[i][1]-'a'))%26+'a';
//}
//int main() {
//	scanf("%s%s",k,m);
//	passchart();
//	for(i=0; i<strlen(k); i++) if(k[i]<='Z'&&k[i]>='A') k[i]=char(k[i]+32);
//	lenk=0;
//	for(i=0; i<strlen(m); i++) {
//		kn[i]=k[lenk];
//		lenk=(lenk+1)%strlen(k);
//	}
//	for(i=0; i<strlen(m); i++) {
//		bool f=0;
//		if(m[i]>='A'&&m[i]<='Z') {
//			m[i]=char(m[i]+32);
//			f=1;
//		}
//		for(j=1; j<=26; j++) 
//			if(c[int(kn[i]-'a'+1)][j] == m[i]) {
//				if(f) ans[i]=char(c[1][j]-32);
//				else ans[i]=c[1][j];
//				break;
//			}
//	}
//	for(i=0; i<strlen(m); i++) cout<<ans[i];
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Problem ID 19017] A.necklace
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 500005
//using namespace std;
//struct LIST {
//	int front,next,n,a;
//	bool vis=false;
//} lis[maxn];
//struct aa {
//	int x,y;
//} pcr,rainbow;
//priority_queue<aa> P;
//bool operator<(aa a,aa b) {
//	return lis[a.x].a+lis[a.y].a<lis[b.x].a+lis[b.y].a;
//}
//int T,n,m;
//void delete_list(int x) {
//	lis[x].vis=true;
//	lis[lis[x].front].next=lis[x].next;
//	lis[lis[x].next].front=lis[x].front;
//}
//signed main() {
//	freopen("necklace.in","r",stdin);
//	freopen("necklace.out","w",stdout);
//	scanf("%lld%lld%lld",&T,&n,&m);
//	for(int i=1; i<=n; i++) {
//		scanf("%lld",&lis[i].a);
//		lis[i].front=i-1;
//		lis[i].next=i+1;
//		lis[i].n=i;
//		if(i==1) lis[i].front=n;
//		if(i==n) lis[i].next=1;
//	}
//	m=n-m;
//	for(int i=1; i<=n; i++) {
//		pcr.x=i;
//		pcr.y=lis[i].next;
//		P.push(pcr);
//	}
//	for(int i=1; i<=m; i++) {
//		pcr=P.top();
//		P.pop();
//		if(lis[pcr.x].vis==true||lis[pcr.y].vis==true) {
//			i--;
//			continue;
//		}
//		if(lis[pcr.x].a>lis[pcr.y].a) {
//			delete_list(pcr.x);
//			rainbow.x=lis[pcr.y].front;
//			rainbow.y=pcr.y;
//			P.push(rainbow);
//		} else {
//			delete_list(pcr.y);
//			rainbow.y=lis[pcr.x].next;
//			rainbow.x=pcr.x;
//			P.push(rainbow);
//		}
//	}
//	while(lis[P.top().x].vis==true||lis[P.top().y].vis==true) P.pop();
//	printf("%lld",lis[P.top().x].a+lis[P.top().y].a);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1080 [NOIP2012 提高组] 国王游戏(无高精)
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,p,c;
//struct aa {
//	int x,y,r,q;
//} a[100001];
//bool cmp(aa e,aa f) {
//	return e.r<f.r;
//}
//signed main() {
//	scanf("%lld",&n);
//	scanf("%lld%lld",&p,&c);
//	a[0].r=p*c;
//	a[0].q=p;
//	for(int i=1; i<=n; i++) {
//		scanf("%lld%lld",&a[i].x,&a[i].y);
//		a[i].r=a[i].x*a[i].y;
//	}
//	sort(a+1,a+n+1,cmp);
//	for(int i=1; i<=n; i++) a[i].q=a[i-1].q*a[i].x;
//	int ans=0;
//	for(int i=1; i<=n; i++) ans=max(ans,int(a[i-1].q/a[i].y));
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1328 [NOIP2014 提高组] 生活大爆炸版石头剪刀布
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 205
//using namespace std;
//int win[5][5]= {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
//int n,na,nb,suma,sumb; 
//int a[maxn],b[maxn];
//signed main(){
//	scanf("%lld%lld%lld",&n,&na,&nb);
//	for(int i=0;i<na;i++) scanf("%lld",&a[i]);
//	for(int i=0;i<nb;i++) scanf("%lld",&b[i]);
//	for(int i=0;i<=n-1;i++) suma+=win[a[i%na]][b[i%nb]];
//	for(int i=0;i<=n-1;i++) sumb+=win[b[i%nb]][a[i%na]];
//	printf("%lld %lld",suma,sumb);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1351	[NOIP2014 提高组] 联合权值
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200005
//#define mod 10007
//using namespace std;
//int n;
//int a[maxn];
//int sum=0,ans=0;
//vector <int> P[maxn];
//void rainbow(int x) {
//	int all=0,ma=0,mi=0,pc=0;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		all+=a[now];
//		pc+=a[now]*a[now];
//		if(a[now]>ma) mi=ma,ma=a[now];
//		else if(a[now]>mi) mi=a[now];
//	}
//	ans=max(ans,mi*ma);
//	sum=(sum%mod+(all*all-pc+mod)%mod)%mod;
//}
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1; i<n; i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
//	for(int i=1; i<=n; i++) rainbow(i); 
//	printf("%lld %lld",ans,sum);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Problem ID 19016] B.计树 
//#include<bits/stdc++.h>
//#define maxn 3005
//#define mod 1000000007
//#define int long long
//int tid,t,n;
//int gl[maxn],gr[maxn];
//int tot[2][maxn][maxn];
//void inc(int &x,int y) {
//	x=((x+=y)>=mod?x-mod:x);
//	return;
//}
//signed main() {
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
//	scanf("%d%d",&tid,&t);
//	for(int wc=1; wc<=t; wc++) {
//		scanf("%lld",&n);
//		for(int i=1; i<=n; i++) scanf("%lld%lld",gl+i,gr+i);
//		memset(tot[(n+1)&1],0,sizeof tot[(n+1)&1]);
//		tot[(n+1)&1][0][0]=1;
//		for(int i=n; i; i--) {
//			int now=i&1,oth=1-(i&1);
//			for(int j=0; j<=n-i+1; j++) for(int k=0; k<=n-i-j+1; k++) tot[now][j][k]=0;
//			for(int j=0; j<=n-i; j++)
//				for(int k=0; k<=n-i-j; k++) {
//					int nv=tot[oth][j][k];
//					if(!nv)continue;
//					if(gl[i]<=0&&gr[i]>=0) {
//						inc(tot[now][j+1][k],nv);
//						if(k)inc(tot[now][j][k-1],1ll*k*nv%mod);
//					}
//					if(gl[i]<=1&&gr[i]>=1) {
//						inc(tot[now][j][k],2ll*nv*j%mod);
//						if(j&&k)inc(tot[now][j-1][k-1],(2ll*nv*j%mod*k%mod+mod-2ll*nv*k%mod)%mod);
//					}
//					if(gl[i]<=2&&gr[i]>=2) {
//						inc(tot[now][j][k+1],2ll*nv*j%mod);
//						if(j) {
//							inc(tot[now][j-1][k],(2ll*nv*j%mod*k%mod+mod-2ll*nv*k%mod)%mod);
//							inc(tot[now][j-1][k],1ll*j*(j-1)%mod*nv%mod);
//						}
//						if(j>=2&&k) inc(tot[now][j-2][k-1],(1ll*j*(j-1)%mod*k%mod*nv%mod+mod-(2ll*k*(j-1)%mod*nv%mod))%mod);
//					}
//				}
//		}
//		printf("%lld\n",tot[1][1][0]);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2296	[NOIP2014 提高组] 寻找道路
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 10005
//using namespace std;
//int n,m,s,t;
//int deg[maxn];
//int dis[maxn];
//vector <int> P[maxn];
//vector <int> F[maxn];
//bool vis[maxn];
//queue<int> Q;
//void back(int x) {
//	memset(vis,false,sizeof(vis));
//	while(!Q.empty()) Q.pop();
//	Q.push(x);
//	vis[x]=true;
//	while(!Q.empty()) {
//		int pc=Q.front();
//		Q.pop();
//		for(int i=0;i<F[pc].size();i++) {
//			int cr=F[pc][i];
//			deg[cr]--;
//			if(vis[cr]) continue;
//			else {
//				vis[cr]=true;
//				Q.push(cr);
//			}
//		}
//	}
//}
//void bfs(int x) {
//	memset(vis,false,sizeof(vis));
//	while(!Q.empty()) Q.pop();
//	Q.push(x);
//	vis[x]=true;
//	while(!Q.empty()) {
//		int pc=Q.front();
//		cout<<pc<<endl<<dis[pc]<<endl;
//		Q.pop();
//		for(int i=0;i<P[pc].size();i++) {
//			int cr=P[pc][i];
//			if(deg[cr]!=0||vis[cr]==true) continue;
//			else {
//				vis[cr]=true;
//				Q.push(cr);
//				dis[cr]=dis[pc]+1;
//			}
//		}
//	}
//}
//signed main(){
//	memset(dis,0x3f,sizeof(dis));
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=m;i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		deg[x]++;
//		P[x].push_back(y);
//		F[y].push_back(x);
//	}
//	scanf("%lld%lld",&s,&t);
//	back(t);
//	dis[s]=0,deg[t]=0;
//	for(int i=1;i<=n;i++) cout<<deg[i]<<" ";
//	bfs(s);
//	if(dis[t]==dis[0]) printf("-1");
//	else printf("%lld",dis[t]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1941	[NOIP2014 提高组] 飞扬的小鸟
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 10005
//#define inf 0x3f3f3f3f
//using namespace std;
//int n,m,k;
//int cnt=1,ans=0;
//int x[maxn],y[maxn];
//struct aa {
//	int p,l,h;
//} a[maxn];
//bool cmp(aa x,aa y) {
//	return x.p<y.p;
//}
//int dp[2][maxn];
//signed main() {
//	memset(dp,inf,sizeof(dp));
//	scanf("%lld%lld%lld",&n,&m,&k);
//	for(int i=1; i<=n; i++) scanf("%lld%lld",&x[i],&y[i]);
//	for(int i=1; i<=k; i++) scanf("%lld%lld%lld",&a[i].p,&a[i].l,&a[i].h);
//	sort(a+1,a+k+1,cmp);
//	for(int i=1; i<=m; i++) dp[0][i]=0;
//	for(int i=1; i<=n; i++) {
//		for(int j=0; j<=m; j++) dp[i%2][j]=inf;
//		for(int j=x[i]+1; j<=x[i]+m; j++) dp[i%2][j]=min(dp[i%2^1][j-x[i]]+1,dp[i%2][j-x[i]]+1);//p=1,完全背包
//		for(int j=m+1; j<=x[i]+m; j++) dp[i%2][m]=min(dp[i%2][m],dp[i%2][j]);//比m大的都是m
//		for(int j=1; j<=m-y[i]; j++) dp[i%2][j]=min(dp[i%2][j],dp[i%2^1][j+y[i]]);//p=0,01背包
//		if(i==a[cnt].p) {//如果这个地方有管道
//			ans=inf;//主要每次都要初始化一次!
//			for(int j=0; j<=a[cnt].l; j++) dp[i%2][j]=inf;
//			for(int j=a[cnt].h; j<=m; j++) dp[i%2][j]=inf;
//			for(int j=1; j<=m; j++) ans=min(dp[i%2][j],ans);
//			if(ans==inf) {
//				printf("0\n%lld",cnt-1);
//				return 0;
//			}
//			cnt++;
//		}
//	}
//	ans=inf;
//	for(int i=1; i<=m; i++) ans=min(ans,dp[n%2][i]);
//	printf("1\n%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2038 [NOIP2014 提高组] 无线网络发射器选址
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200
//using namespace std;
//int d,n;
//int sum[maxn][maxn];
//signed main(){
//	scanf("%lld%lld",&d,&n);
//	for(int i=1;i<=n;i++) {
//		int x,y,k;
//		scanf("%lld%lld%lld",&x,&y,&k);
//		sum[x+30][y+30]+=k;
//	}	
//	int ans=0,cnt=0;
//	for(int i=1;i<=178;i++) for(int j=1;j<=178;j++) sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
//	for(int i=30;i<=158;i++) {
//		for(int j=30;j<=158;j++) {
//			int now=sum[i+d][j+d]-sum[i+d][j-d-1]-sum[i-d-1][j+d]+sum[i-d-1][j-d-1];
//			if(now>ans) ans=now,cnt=1;
//			else if(ans==now) cnt++;
//		}
//	}
//	printf("%lld %lld",cnt,ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2615	[NOIP2015 提高组] 神奇的幻方
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n;
//int a[39][39];
//signed main() {
//	scanf("%lld",&n);
//	memset(a,0,sizeof(a));
//	a[1][(n+1)/2]=1;
//	int li=1,lj=(n+1)/2;
//	for(int k=2; k<=n*n; k++) {
//		if(li==1&&lj!=n) a[n][lj+1]=k,li=n,lj++;
//		else if(lj==n&&li!=1) a[li-1][1]=k,li--,lj=1;
//		else if(li==1&&lj==n) a[2][lj]=k,li++;
//		else if(li!=1&&lj!=n) {
//			if(a[li-1][lj+1]==0) a[li-1][lj+1]=k,li--,lj++;
//			else a[li+1][lj]=k,li++;
//		}
//	}
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=n;j++) printf("%lld ",a[i][j]);
//		puts("");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2661	[NOIP2015 提高组] 信息传递
//#include<bits/stdc++.h>
//#define maxn 200005
//#define int long long
//using namespace std;
//int n,ans=1e9,t[maxn],id[maxn];
//bool vis[maxn];
//void f(int x) {
//	if(vis[x]==true) return ;
//	vis[x]=true;
//	id[t[x]]--;
//	if(id[t[x]]==0) f(t[x]);
//}
//int dfs(int st,int x,int step) {
//	if(st==t[x]) return step+1;
//	vis[x]=true;
//	dfs(st,t[x],step+1);
//}
//signed main() {
//	memset(vis,false,sizeof(vis));
//	scanf("%lld",&n);
//	for(int i=1; i<=n; i++) {
//		scanf("%lld",&t[i]);
//		id[t[i]]++;
//	}
//	for(int i=1; i<=n; i++) if(id[i]==0) f(i);
//	for(int i=1; i<=n; i++) if(vis[i]==false) ans=min(ans,dfs(i,t[i],1));
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2668	[NOIP2015 提高组] 斗地主
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int T,n,ans;
//int sum[20];
//void dfs(int x) {//x:出了几次牌
//	if(x>=ans) return ;
//	//顺子
//	int k=0;
//	for(int i=3; i<=14; i++) { //要排除2,大小王
//		if(sum[i]==0) k=0;//一个顺子
//		else {
//			k++;//每个顺子个数
//			if(k>=5) {//如果大于5个
//				for(int j=i; j>=i-k+1; j--) sum[j]--; //搜索
//				dfs(x+1);//次数+1
//				for(int j=i; j>=i-k+1; j--) sum[j]++; //回溯
//			}
//		}
//	}
//	k=0;//双顺子
//	for(int i=3; i<=14; i++) {
//		if(sum[i]<=1) k=0;
//		else {
//			k++;
//			if(k>=3) {
//				for(int j=i; j>=i-k+1; j--) sum[j]-=2;
//				dfs(x+1);
//				for(int j=i; j>=i-k+1; j--) sum[j]+=2;
//			}
//		}
//	}
//	k=0;//三顺子
//	for(int i=3; i<=14; i++) {
//		if(sum[i]<=2) k=0;
//		else {
//			k++;
//			if(k>=2) {
//				for(int j=i; j>=i-k+1; j--) sum[j]-=3;
//				dfs(x+1);
//				for(int j=i; j>=i-k+1; j--) sum[j]+=3;
//			}
//		}
//	}
//	//带牌
//	for(int i=2; i<=14; i++) {
//		if(sum[i]<=3) {
//			if(sum[i]<=2) continue;
//			sum[i]-=3;
//			for(int j=2; j<=15; j++) {
//				if(sum[j]<=0||i==j) continue;
//				sum[j]--;
//				dfs(x+1);
//				sum[j]++;
//			}
//			for(int j=2; j<=14; j++) {
//				if(sum[j]<=1||i==j) continue;
//				sum[j]-=2;
//				dfs(x+1);
//				sum[j]+=2;
//			}
//			sum[i]+=3;
//		} else {
//			sum[i]-=3;
//			for(int j=2; j<=15; j++) {
//				if(sum[j]<=0||i==j) continue;
//				sum[j]--;
//				dfs(x+1);
//				sum[j]++;
//			}
//			for(int j=2; j<=14; j++) {
//				if(sum[j]<=1||i==j) continue;
//				sum[j]-=2;
//				dfs(x+1);
//				sum[j]+=2;
//			}
//			sum[i]+=3;
//
//			sum[i]-=4;
//			for(int j=2; j<=15; j++) {
//				if(i==j||sum[j]<=0) continue;
//				sum[j]--;
//				for(int k=2; k<=15; k++) {
//					if(j==k||sum[k]<=0) continue;
//					sum[k]--;
//					dfs(x+1);
//					sum[k]++;
//				}
//				sum[j]++;
//			}
//			for(int j=2; j<=14; j++) {
//				if(i==j||sum[j]<=1) continue;
//				sum[j]-=2;
//				for(int k=2; k<=14; k++) {
//					if(j==k||sum[k]<=1) continue;
//					sum[k]-=2;
//					dfs(x+1);
//					sum[k]+=2;
//				}
//				sum[j]+=2;
//			}
//			sum[i]+=4;
//		}
//	}
//	for(int i=2; i<=15; i++) if(sum[i]) x++;
//	ans=min(ans,x);
//}
//signed main() {
//	scanf("%lld%lld",&T,&n);
//	while(T--) {
//		ans=0x7fffffff;
//		memset(sum,0,sizeof(sum));
//		for(int i=1; i<=n; i++) {
//			int x,y;
//			scanf("%lld %lld",&x,&y);
//			if(x==0) sum[15]++;
//			else if(x==1) sum[14]++;//将1进行特殊处理是为了再求顺子时方便处理
//			else sum[x]++;
//		}
//		dfs(0);
//		printf("%lld\n",ans);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2312	[NOIP2014 提高组] 解方程
//#include<bits/stdc++.h>
//#define int long long
//#define mod (int)1000000007
//#define maxn 105
//using namespace std;
//int n,m,a[maxn];
//vector<int> P;
//int read(){
//    int sum=0,fg=1;
//    char c=getchar();
//    while(c<'0'||c>'9'){
//        if(c=='-') fg=-1;
//        c=getchar();
//    }
//    while(c>='0'&&c<='9'){
//        sum=((sum*10)+c-'0')%mod;
//        c=getchar();
//    }
//    return sum*fg;
//}
//bool solve(int x) {
//	int sum=0;
//	for(int i=n+1;i>=1;i--) sum=(sum*x+a[i])%mod;
//	if(sum==0) return true;
//	else return false;
//}
//signed main(){
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=n+1;i++) a[i]=read();
//	for(int i=1;i<=m;i++) if(solve(i)==true) P.push_back(i);
//	printf("%lld\n",P.size());
//	for(int i=0;i<P.size();i++) printf("%lld\n",P[i]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2678	[NOIP2015 提高组] 跳石头
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 500005
//using namespace std;
//int l,n,m;
//int a[maxn];
//bool check(int x) {
//	int cnt=0,lst=0;
//	for(int i=1;i<=n+1;i++) {
//		if(a[i]-lst<x) cnt++;
//		else lst=a[i];
//	}
//	return cnt<=m;
//}
//signed main(){
//	scanf("%lld%lld%lld",&l,&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	a[n+1]=l;
//	int left=1,right=l,ans;
//	while(left<=right) {
//		int mid=(left+right)>>1;
//		if(check(mid)) {
//			ans=mid;
//			left=mid+1;
//		} else right=mid-1;
//	}
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1083	[NOIP2012 提高组] 借教室
//#include<bits/stdc++.h>
//#define maxn 1000005
//#define int long long
//#define lc rt<<1
//#define rc rt<<1|1 
//using namespace std;
//int n,m;
//int a[maxn],minn[maxn<<2],tag[maxn<<2]; 
//void push_up(int rt) {
//	minn[rt]=min(minn[lc],minn[rc]);
//}
//void build(int rt,int l,int r) {
//	int mid=(l+r)>>1;
//	if(l==r) {
//		minn[rt]=a[l];
//		return ;
//	} else {
//		build(lc,l,mid);
//		build(rc,mid+1,r);
//		push_up(rt);
//	}
//}
//void push_down(int rt) {
//	minn[lc]-=tag[rt];
//	minn[rc]-=tag[rt];
//	tag[lc]+=tag[rt];
//	tag[rc]+=tag[rt];
//	tag[rt]=0;
//} 
//void update(int rt,int l,int r,int L,int R,int rainbow) {
//	if(l<=L&&R<=r) {
//		minn[rt]-=rainbow;
//		tag[rt]+=rainbow;
//	} else {
//		if(tag[rt]) push_down(rt);
//		int mid=(L+R)>>1;
//		if(l<=mid) update(lc,l,r,L,mid,rainbow);
//		if(r>mid) update(rc,l,r,mid+1,R,rainbow);
//		push_up(rt);
//	}
//}
//signed main() {
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	build(1,1,n);
//	for(int i=1;i<=m;i++) {
//		int d,s,t;
//		scanf("%lld %lld %lld",&d,&s,&t);
//		update(1,s,t,1,n,d);
//		if(minn[1]<0) {
//			printf("-1\n%lld",i);
//			return 0;
//		}
//	}
//	printf("0");
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3379 【模板】最近公共祖先(LCA)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 500005
//using namespace std;
//int n,m,s;
//vector <int> P[maxn];
//int fa[maxn][40];
//int deep[maxn];
//void dfs(int x,int frt) {
//	fa[x][0]=frt;
//	deep[x]=deep[fa[x][0]]+1;
//	for(int i=1;i<=31;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
//	for(int i=0;i<P[x].size();i++) {
//		if(P[x][i]==frt) continue;
//		dfs(P[x][i],x);
//	}
//}
//int LCA(int x,int y) {
//	if(deep[x]>deep[y]) swap(x,y);
//	int tmp=deep[y]-deep[x],ans=0;
//	for(int i=0;tmp;i++,tmp>>=1) if(tmp&1) y=fa[y][i];
//	if(y==x) return x;
//	for(int i=30;i>=0;i--) {
//		if(fa[x][i]!=fa[y][i]) {
//			x=fa[x][i];
//			y=fa[y][i];
//		}
//	}
//	return fa[x][0];
//}
//signed main(){
//	
//	memset(fa,0,sizeof(fa));
//	memset(deep,0,sizeof(deep));
//	scanf("%lld %lld %lld",&n,&m,&s);
//	for(int i=1;i<n;i++) {
//		int x,y;
//		scanf("%lld %lld",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	dfs(s,0);
//	while(m--) {
//		int a,b;
//		scanf("%lld%lld",&a,&b);
//		printf("%lld\n",LCA(a,b));
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Problem ID 19028] D.  数立方体
//#include<bits/stdc++.h>
//#define int long long
//#define mod 998244353
//using namespace std;
//int n,m,op;
//signed main(){
//	freopen("robot.in","r",stdin);
//	freopen("robot.out","w",stdout);
//	scanf("%lld %lld %lld",&n,&m,&op);
//	printf("%lld",m%mod*n%mod-1);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Problem ID 19026] B.  机器人学算法 
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 300005
//using namespace std;
//int tid,n,m,b[maxn],c[maxn];
//map<int,int> P,Q;
//int maxb,maxc,sumb,sumc;
//signed main(){
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
//	scanf("%lld",&tid);
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&b[i]),P[b[i]]++,maxb=max(b[i],maxb),sumb+=b[i];
//	for(int i=1;i<=m;i++) scanf("%lld",&c[i]),Q[c[i]]++,maxc=max(maxc,c[i]),sumc+=c[i];
//	if(maxb!=maxc) {
//		printf("-1");
//		return 0;
//	}
//	int xx=0;
//	for(int i=1;i<=n;i++) {
//		if(P[b[i]]&&Q[b[i]]) P[b[i]]--,Q[b[i]]--,xx+=b[i];
//	}
//	cout<<sumb+sumc-xx;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2680	[NOIP2015 提高组] 运输计划
//#include<bits/stdc++.h>
//#define maxn 300005
//using namespace std;
//struct aa {
//	int to,w;
//};
//struct query {
//	int x,y,lca,d;
//} A[maxn];
//int n,m,tot,L,R;
//vector <aa> P[maxn];
//int fa[maxn][40],deep[maxn];
//int C[maxn],dis[maxn],val[maxn];
//int LCA(int x,int y) {
//	if(deep[x]>=deep[y]) swap(x,y);
//	int tmp=deep[y]-deep[x], ans=0;
//	for(int i = 0; tmp; i ++,tmp >>= 1) if(tmp&1) y=fa[y][i];
//	if(y == x) return x;
//	for(int i = 30; i >= 0; i --) {
//		if(fa[x][i] != fa[y][i]) {
//			x = fa[x][i];
//			y = fa[y][i];
//		}
//	}
//	return fa[x][0];
//}
//void dfs(int x,int frt) {
//	fa[x][0] = frt;
//	deep[x] = deep[fa[x][0]] + 1;
//	for(int i = 1; i <= 31; i ++) fa[x][i] = fa[fa[x][i-1]][i-1];
//	for(int i = 0; i < P[x].size(); i ++) {
//		aa now = P[x][i];
//		if(P[x][i].to == frt) continue;
//		val[now.to] = now.w;
//		dis[now.to] = dis[x] + now.w;
//		dfs(P[x][i].to,x);
//	}
//}
//void summ(int x,int front) {
//	for(int i = 0; i < P[x].size(); i ++) {
//		int y = P[x][i].to;
//		if(y == front) continue;
//		summ(y,x);
//		C[x] += C[y];
//	}
//}
//bool check(int mid) {
//	int sum = 0,maxx = -1;
//	memset(C,0,sizeof(C));
//	for(int i = 1; i <=m; i ++) if(A[i].d>mid) C[A[i].x]++,C[A[i].y]++,C[A[i].lca]-=2,sum++;
//	if(sum==0) return true;
//	summ(1,1);
//	for(int i=1; i<=n; i++) {
//		if(C[i] == sum&&dis[i]-dis[fa[i][0]]>=R-mid) return true;
//	}
//	return false;
//}
//int search(int l,int r) {
//	int res = 1e9 + 7;
//	while(l <= r) {
//		int mid = (l+r)>>1;
//		if(check(mid)) {
//			res = min(mid,res), r = mid - 1;
//		} else l = mid + 1;
//	}
//	return res;
//}
//signed main() {
//	scanf("%d %d",&n,&m);
//	for(int i=1; i<n; i++) {
//		int a,b,t;
//		scanf("%d %d %d",&a,&b,&t);
//		P[a].push_back({b,t});
//		P[b].push_back({a,t});
//	}
//	dfs(1,0);
//	for(int i=1; i<=m; i++) {
//		scanf("%d %d",&A[i].x,&A[i].y);
//		A[i].lca = LCA(A[i].x,A[i].y);
//		A[i].d = dis[A[i].x] + dis[A[i].y] - 2 * dis[A[i].lca];
//		R = max(R,A[i].d);
//	}
//	printf("%d\n",search(0,R));
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1563	[NOIP2016 提高组] 玩具谜题
//#include<bits/stdc++.h>
//#define maxn 100005
//#define int long long
//using namespace std;
//struct aa{
//	int head;
//	string name;
//} a[maxn];
//int n,m,x,y;
//signed main() {
//	cin>>n>>m;
//	for(int i=0; i<n; i++) cin>>a[i].head>>a[i].name;
//	int now=0;
//	for(int i=1; i<=m; i++) {
//		cin>>x>>y;
//		if(a[now].head==0&&x==0)now=(now+n-y)%n;
//		else if(a[now].head==0&&x==1)now=(now+y)%n;
//		else if(a[now].head==1&&x==0)now=(now+y)%n;
//		else if(a[now].head==1&&x==1)now=(now+n-y)%n;
//	}
//	cout<<a[now].name<<endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P4643 [国家集训队] 阿狸和桃子的游戏
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,m;
//int w[maxn];
//bool cmp(int x,int y) {
//	return x>y;
//}
//signed main(){
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&w[i]),w[i]*=2;
//	for(int i=1;i<=m;i++) {
//		int u,v,x;
//		scanf("%lld %lld %lld",&u,&v,&x);
//		w[u]+=x;
//		w[v]+=x;
//	}
//	sort(w+1,w+n+1,cmp);
//	int ans=0;
//	for(int i=1;i<n;i+=2) ans+=w[i]-w[i+1];
//	cout<<ans/2;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2827 [NOIP2016 提高组] 蚯蚓
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,m,q,u,v,t;
//int a[maxn];
//queue<int> P1,P2,P3;
//bool cmp(int x,int y) {
//	return x>y;
//}
//int get() {
//	int P_max=-1e18,id;
//	if(P1.front()>P_max&&P1.size()) id=1,P_max=P1.front();
//	if(P2.front()>P_max&&P2.size()) id=2,P_max=P2.front();
//	if(P3.front()>P_max&&P3.size()) id=3,P_max=P3.front();
//	if(id==1) P1.pop();
//	if(id==2) P2.pop();
//	if(id==3) P3.pop();
//	return P_max;
//}
//signed main(){
//	scanf("%lld %lld %lld %lld %lld %lld",&n,&m,&q,&u,&v,&t);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++) P1.push(a[i]);
//	for(int i=1;i<=m;i++) {
//		int x=get()+(i-1)*q;
//		if(i%t==0) printf("%lld ",x);
//		int l1=u*1.0/v*1.0*x,l2=x-l1;
//		P2.push(l1-i*q);
//		P3.push(l2-i*q);
//	}
//	puts("");
//	int cnt=0,x;
//	while((x=get()+m*q)>=0) if((++cnt)%t==0) printf("%lld ",x);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P8817 [CSP-S 2022] 假期计划
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 2505
//using namespace std;
//int n,m,k,ans=-1e9;
//int a[maxn];
//int dis[maxn][maxn];
//bool vis[maxn];
//vector <int> P[maxn];
//struct aa { int u,v,w; } c[maxn*maxn];
//bool cmp(aa x,aa y) { return x.w>y.w; }
//inline void bfs(int x) {
//	memset(vis,false,sizeof(vis));
//	queue<int> Q;
//	Q.push(x);
//	dis[x][x]=-1;
//	vis[x]=true;
//	while(!Q.empty()) {
//		int fro=Q.front();
//		Q.pop();
//		for(int i=0; i<P[fro].size(); i++) {
//			int now=P[fro][i];
//			if(vis[now]==true) continue;
//			vis[now]=true;
//			dis[x][now]=dis[x][fro]+1;
//			Q.push(now);
//		}
//	}
//}
//signed main() {
//	freopen("holiday.in","r",stdin);
//	freopen("holiday.out","w",stdout);
//	scanf("%lld %lld %lld",&n,&m,&k);
//	for(int i=2; i<=n; i++) scanf("%lld",&a[i]);
//	for(int i=1; i<=m; i++) {
//		int x,y;
//		scanf("%lld %lld",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) dis[i][j]=1e9;
//	for(int i=1; i<=n; i++) bfs(i);
//	int cnt=0;
//	for(int i=1; i<=n; i++) {
//		if(dis[1][i]>k||i==1) continue;
//		for(int j=1; j<=n; j++) {
//			if(dis[i][j]>k||j==1||i==j) continue;
//			c[++cnt]= {i,j,a[i]+a[j]};
//		}
//	}
//	sort(c+1,c+cnt+1,cmp);
//	for(int i=1; i<=cnt; i++) {
//		for(int j=i+1; j<=cnt; j++) {
//			if(c[i].u==c[j].u||c[i].v==c[j].v||dis[c[i].v][c[j].v]>k||c[i].u==c[j].v||c[i].v==c[j].u) continue;
//			ans=max(ans,c[i].w+c[j].w);
//			break; 
//		}
//	}
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P5019	[NOIP2018 提高组] 铺设道路
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,d[maxn];
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
//	int ans=0;
//	for(int i=1;i<=n;i++) if(d[i]>d[i-1]) ans+=d[i]-d[i-1];
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P5657 [CSP-S2019] 格雷码
//#include<bits/stdc++.h>
//#define int unsigned long long
//using namespace std;
//int n,k;
//int t[100];
//int qpow(int x,int y) {
//	int ans=1;
//	while(y) {
//		if(y%2==1) ans*=x;
//		x*=x;
//		y>>=1;
//	}
//	return ans;
//}
//signed main(){
//	cin>>n>>k;
//	int l=0,tot=qpow(2,n)-1,r=tot;
//	int cnt=0;
//	while(l<r) {
//		int mid=(l+r)>>1;
//		if(k>mid) {
//			t[++cnt]=1;
//			k=tot-k;
//		} else t[++cnt]=0; 
//		r=mid;
//		tot>>=1;
//	}
//	for(int i=1;i<=n;i++) cout<<t[i];
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3951 [NOIP2017 提高组] 小凯的疑惑 / [蓝桥杯 2013 省] 买不到的数目
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a,b;
//signed main(){
//	scanf("%lld %lld",&a,&b);
//	cout<<a*b-a-b;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3958 [NOIP2017 提高组] 奶酪
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1005
//using namespace std;
//int T;
//struct aa{
//	int x,y,z;
//}a[maxn];
//bool vis[maxn];
//int n,h,r;
//bool flag=false;
//double dis(aa cr,int i){
//    double dis;
//    dis=sqrt((cr.x-a[i].x)*(cr.x-a[i].x)+(cr.y-a[i].y)*(cr.y-a[i].y)+(cr.z-a[i].z)*(cr.z-a[i].z));
//    return dis;
//}
//queue <aa> Q;
//void bfs() {
//	memset(vis,false,sizeof(vis));
//	flag=false;	
//	while(!Q.empty()){
//		aa pc=Q.front();
//		Q.pop();
//		if(pc.z+r>=h) {
//			cout<<"Yes"<<endl;
//			flag=true;
//			break;
//		}
//		for(int i=1;i<=n;i++) {
//			if(!vis[i]) {
//				if(dis(pc,i)<=2*r) {
//					vis[i]=1;
//					Q.push(a[i]);
//				}
//			}
//		}
//	}
//}
//signed main(){
//	scanf("%lld",&T);
//	while(T--) {
//		while(!Q.empty()) Q.pop();
//		scanf("%lld %lld %lld",&n,&h,&r);
//		for(int i=1;i<=n;i++) {
//			scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
//			if(abs(a[i].z)<=r) Q.push(a[i]);
//		}
//		bfs();
//		if(!flag) cout<<"No"<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3367	【模板】并查集
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 10005
//using namespace std;
//int n,m;
//int fa[maxn];
//int find(int x) {
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//signed main(){
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++) fa[i]=i;
//	for(int i=1;i<=m;i++) {
//		int z,x,y;
//		scanf("%lld %lld %lld",&z,&x,&y);
//		if(z==1) {
//			int fx=find(x);
//			int fy=find(y);
//			fa[fx]=fy;
//		}
//		if(z==2) {
//			if(find(x)==find(y)) cout<<"Y"<<endl;
//			else cout<<"N"<<endl;
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1082 [NOIP2012 提高组] 同余方程
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a,b,x,y;
//int exgcd(int a,int b) {
//	int d;
//	if(b==0) {
//		x=1,y=0;
//		return a;
//	}
//	d=exgcd(b,a%b);
//	int t=x;
//	x=y;
//	y=t-(a/b)*y;
//	return d;
//}
//signed main(){
//	scanf("%lld %lld",&a,&b);
//	exgcd(a,b);
//	printf("%lld",(x+b)%b);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3545 [POI2012] HUR-Warehouse Store
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 250005
//using namespace std;
//int n;
//int a[maxn],b[maxn];
//bool vis[maxn];
//struct aa {
//	int a,id;
//	bool operator <(const aa &x) const {
//		if(x.a!=a) return x.a>a;
//		else return x.id>id; 
//	}
//};
//priority_queue <aa> C;
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
//	for(int i=1; i<=n; i++) scanf("%lld",&b[i]);
//	int tot=0,cnt=0;
//	for(int i=1; i<=n; i++) {
//		tot+=a[i];
//		if(tot<b[i]&&!C.empty()&&C.top().a>b[i]) {
//			vis[C.top().id]=false;
//			tot+=C.top().a;
//			C.pop();
//			cnt--;
//		}
//		if(tot>=b[i]) {
//			tot-=b[i];
//			C.push({b[i],i});
//			vis[i]=true;
//			cnt++;
//		}
//	}
//	printf("%lld\n",cnt);
//	for(int i=1; i<=n; i++) if(vis[i]) printf("%lld ",i);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//A - 线性筛模板 洛谷 - P3383 
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 6000010
//#define X 100000005
//using namespace std;
//int n,q,k;
//int pri[maxn];
//bool vis[X];
//void init() {
//	int cnt=0;
//	vis[1]=1;
//	for (int i = 2 ; i < X; i++) {
//		if (!vis[i]) pri[++cnt] = i;
//		for (int j = 1; j <= cnt&&i*pri[j]<X; j++) {
//			vis[i * pri[j]] = 1;
//			if (i % pri[j] == 0) break;
//		}
//	}
//}
//signed main() {
//	freopen("P3383_1.in","r",stdin);
//	freopen("P3383.out","w",stdout); 
//	scanf("%lld %lld",&n,&q);
//	init();
//	while(q--) {
//		int k;
//		scanf("%lld",&k);
//		printf("%lld\n",pri[k]);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//B - gcd简单应用 洛谷 - P1029 
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 10000001
//using namespace std;
//int x,y,ans=0,k=1;
//int c[maxn];
//void pc(int a,int b){
//	int p=a*b;
//	for(int i=1;i<=sqrt(p);i++)
//		if(p%i==0) c[k++]=i;
//}
//signed main(){
//	scanf("%lld%lld",&x,&y);
//	if(x==y){
//		cout<<1;
//		return 0;
//	}
//	pc(x,y);
//	for(int i=1;i<k;i++) if(__gcd(c[i],(x*y)/c[i])==x) ans++;
//	printf("%lld",ans*2);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//D - 最大约数和 洛谷 - P1734
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int i,j,n,a[1001],dp[1001];
//signed main() {
//	scanf("%lld",&n);
//	for(i=1; i<=n/2; i++) for(j=2; i*j<=n; j++) a[i*j]+=i;
//	for(i=1; i<=n; i++) for(j=i; j<=n; j++) dp[j]=max(dp[j],dp[j-i]+a[i]);
//	printf("%lld",dp[n]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A - 矩阵快速幂 洛谷 - P3390 
//#include<bits/stdc++.h>
//#define int long long
//#define mod 1000000007
//#define maxn 205
//using namespace std;
//int n,k;
//struct Mar {
//	int a[maxn][maxn];
//
//} A,P;
//Mar operator *(Mar x,Mar y) {
//	Mar p;
//	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) p.a[i][j]=0;
//	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) for(int k=1; k<=n; k++) p.a[i][j]+=x.a[i][k]*y.a[k][j]%mod,p.a[i][j]%=mod;
//	return p;
//}
//signed main() {
//	scanf("%lld %lld",&n,&k);
//	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%lld",&A.a[i][j]);
//	for(int i=1; i<=n; i++) P.a[i][i]=1;
//	while(k) {
//		if(k&1) P=P*A;
//		A=A*A;
//		k>>=1;
//	}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) cout<<P.a[i][j]<<" ";
//		cout<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF678D Iterated Linear Function
//#include<bits/stdc++.h>
//#define int long long
//#define double long double
//#define maxn 105
//#define mod 1000000007
//using namespace std;
//int m,a,c,x0,n,g;
//struct Mar{
//	int c[maxn][maxn];
//}A,T;
//int mul(int a,int b) {
//	return (a*b-(int)((double)a/mod*b)*mod+mod)%mod;
//}
//Mar operator * (Mar x,Mar y) {
//	Mar p;
//	for(int i=1;i<maxn;i++) for(int j=1;j<maxn;j++) p.c[i][j]=0;
//	for(int i=1; i<=2; i++) for(int j=1; j<=2; j++) for(int k=1; k<=2; k++) p.c[i][j]+=mul(x.c[i][k],y.c[k][j]),p.c[i][j]%=mod;
//	return p;
//}
//signed main(){
//	scanf("%lld %lld %lld %lld",&a,&c,&n,&x0);
//	A.c[1][1]=a,A.c[1][2]=c;
//	A.c[2][1]=0,A.c[2][2]=1;
//	T.c[1][1]=x0,T.c[2][1]=1;
//	while(n) {
//		if(n&1) T=A*T;
//		A=A*A;
//		n>>=1;
//	}
//	cout<<T.c[1][1]%mod;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2044 [NOI2012] 随机数生成器
//#include<bits/stdc++.h>
//#define int long long
//#define double long double
//#define maxn 105
//using namespace std;
//int m,a,c,x0,n,g;
//struct Mar{
//	int c[maxn][maxn];
//}A,T;
//int mul(int a,int b) {
//	return (a*b-(int)((double)a/m*b)*m+m)%m;
//}
//Mar operator * (Mar x,Mar y) {
//	Mar p;
//	for(int i=1;i<maxn;i++) for(int j=1;j<maxn;j++) p.c[i][j]=0;
//	for(int i=1; i<=2; i++) for(int j=1; j<=2; j++) for(int k=1; k<=2; k++) p.c[i][j]+=mul(x.c[i][k],y.c[k][j]),p.c[i][j]%=m;
//	return p;
//}
//signed main(){
//	scanf("%lld %lld %lld %lld %lld %lld",&m,&a,&c,&x0,&n,&g);
//	A.c[1][1]=a,A.c[1][2]=c;
//	A.c[2][1]=0,A.c[2][2]=1;
//	T.c[1][1]=x0,T.c[2][1]=1;
//	while(n) {
//		if(n&1) T=A*T;
//		A=A*A;
//		n>>=1;
//	}
//	cout<<T.c[1][1]%g;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3389 【模板】高斯消元法
//#include<bits/stdc++.h>
//#define int  long long
//#define maxn 105
//using namespace std;
//int n;
//double a[maxn][maxn];
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1; i<=n; i++) for(int j=1; j<=n+1; j++) scanf("%lf",&a[i][j]);
//	for(int i=1; i<=n; i ++) {
//		int f=i;
//		while(a[f][i]==0&&f<=n) f++;
//		if(f==n+1) {
//			printf("No Solution");
//			return 0;
//		}
//		for(int j=1; j<=n+1; j++) swap(a[i][j],a[f][j]);
//		for(int j=n+1; j>=i; j--) a[i][j]/=a[i][i];
//		for(int j=1; j<=n; j++) {
//			if(i==j) continue;
//			for(int k=n+1; k>=i; k--) a[j][k]-=a[i][k]*a[j][i];
//		}
//	}
//	for(int i=1; i<=n; i++) printf("%.2lf\n",a[i][n+1]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P9755 [CSP-S 2023] 种树
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,l,r,ott,ans;
//int fa[maxn],nxt[maxn],p[maxn],cs[maxn],vis[maxn];
//__int128 a[maxn],b[maxn],c[maxn];
//struct aa {
//	int id,dat;
//} t[maxn];
//vector<int> v[maxn];
//bool cmp1(aa x,aa y) {
//	return x.dat<y.dat;
//}
//bool cmp2(aa x,aa y) {
//	return x.id<y.id;
//}
//__int128 check1(__int128 gb,__int128 gc,__int128 gx,__int128 x) {
//	if(gc<0) {
//		if(gb+gc*gx<=0) return (x-gx+1);
//		else {
//			__int128 hh,t1,t2;
//			t1=gb+gc*gx;
//			hh=gb/(-gc);
//			if(gb%(-gc)==0) hh--;
//			t2=gb+gc*hh;
//			if(hh<=x) return (x-hh+(t1+t2)*(hh-gx+1)/2);
//			else {
//				t2=gb+gc*x;
//				return ((x-gx+1)*(t1+t2)/2);
//			}
//		}
//	} else if(gc==0) {
//		if(gb<=0) return (x-gx+1);
//		else return (x-gx+1)*gb;
//	} else {
//		if(gb+gc*gx>0) {
//			__int128 t1,t2;
//			t1=gb+gc*gx;
//			t2=gb+gc*x;
//			return ((t1+t2)*(x-gx+1)/2);
//		} else {
//			__int128 t1,t2;
//			__int128 hh=(-gb)/gc;
//			hh++;
//			t1=gb+gc*hh;
//			t2=gb+gc*x;
//			if(hh<=x) return (hh-gx+(x-hh+1)*(t1+t2)/2);
//			else return (x-gx+1);
//		}
//	}
//}
//void dfs(int now,int last) {
//	fa[now]=last;
//	for(int i=0; i<v[now].size(); i++) {
//		int yyy=v[now][i];
//		if(yyy==last) continue;
//		dfs(yyy,now);
//	}
//	return;
//}
//bool check(int x) {
//	for(int i=1; i<=n; i++) t[i].dat=0;
//	for(int i=1; i<=n; i++) {
//		int gl=1,gr=n;
//		while(gl<=gr) {
//			int midd=(gl+gr)>>1;
//			if(check1(b[i],c[i],midd,x)>=a[i]) {
//				t[i].dat=midd;
//				gl=midd+1;
//			} else gr=midd-1;
//		}
//		if(check1(b[i],c[i],t[i].dat,x)<a[i]) return false;
//	}
//	for(int i=1; i<=n; i++) {
//		vis[i]=0;
//		nxt[i]=0;
//		t[i].id=i;
//	}
//	sort(t+1,t+n+1,cmp1);
//	int dy=1;
//	vis[1]=1;
//	for(int i=1; i<=n; i++) {
//		int now=t[i].id;
//		while(vis[now]==0&&now!=0) {
//			vis[now]=-1;
//			nxt[fa[now]]=now;
//			now=fa[now];
//		}
//		now=nxt[now];
//		while(vis[now]==-1&&now!=0) {
//			vis[now]=dy+1;
//			dy++;
//			now=nxt[now];
//		}
//	}
//	sort(t+1,t+n+1,cmp2);
//	for(int i=1; i<=n; i++) if(vis[i]>t[i].dat) return false;
//	return true;
//}
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1; i<=n; i++) {
//		int x,y,z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		a[i]=x,b[i]=y,c[i]=z;
//	}
//	for(int i=1; i<n; i++) {
//		int x,y;
//		scanf("%lld%lld",&x,&y);
//		v[x].push_back(y);
//		v[y].push_back(x);
//	}
//	dfs(1,0);
//	l=1,r=1000000000;
//	while(l<=r) {
//		int mid=(l+r)>>1;
//		if(check(mid)) {
//			ans=mid;
//			r=mid-1;
//		} else l=mid+1;
//	}
//	printf("%lld\n",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P4035 [JSOI2008] 球形空间产生器
//#include<bits/stdc++.h>
//#define int long long
//#define N 120
//#define eps 1e-8 
//using namespace std;
//int n;
//double a[N][N],b[N],pos[N][N];
//signed main() {
//	scanf("%lld",&n);
//	for (int i=1; i<=n+1; i++) for (int j=1; j<=n; j++) scanf("%lf",&pos[i][j]);
//	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) a[i][j]=2*(pos[i][j]-pos[i+1][j]),b[i]+=pos[i][j]*pos[i][j]-pos[i+1][j]*pos[i+1][j];
//	for (int i=1; i<=n; i++) {
//		int row=i;
//		for (int j=i+1; j<=n; j++) if (fabs(a[j][i])>fabs(a[row][i])) row=j;
//		if (fabs(a[row][i])<eps) break;
//		if (row^i) swap(a[i],a[row]),swap(b[i],b[row]);
//		for (int j=1; j<=n; j++) {
//			if(i==j) continue;
//			double rate=a[j][i]/a[i][i];
//			for(int k=i; k<=n; k++) a[j][k]-=a[i][k]*rate;
//			b[j]-=b[i]*rate;
//		}
//	}
//	for (int i=1; i<n; i++) printf("%.3lf ",b[i]/a[i][i]);
//	printf("%.3lf\n",b[n]/a[n][n]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[XJOI Promble ID 19051] A.硬币机
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000005
//using namespace std;
//int n,m,Ans,pa=1,pc=0;
//int a[maxn],b[maxn],c[maxn],ans[maxn];
//bool cmp(int x,int y) {
//	return x>y;
//}
//signed main() {
//	freopen("coin.in","r",stdin);
//	freopen("coin.out","w",stdout);
//	scanf("%lld %lld",&n,&m);
//	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
//	for(int i=0; i<n; i++) {
//		scanf("%lld",&b[i]);
//		c[i]=a[i]+b[i];
//	}
//	sort(a,a+n,cmp),sort(c,c+n,cmp);
//	ans[1]=a[0];
//	for(int i=3; i<=m; i+=2) {
//		ans[i]=ans[i-2];
//		ans[i]+=a[pa]+a[pa+1];
//		pa+=2;
//		while(pa>1&&pc<n&&a[pa-2]+a[pa-1]<c[pc]) {
//			ans[i]-=a[pa-2]+a[pa-1];
//			ans[i]+=c[pc];
//			pa-=2;
//			pc++;
//		}
//	}
//	pa=0,pc=0;
//	for(int i=2; i<=m; i+=2) {
//		ans[i]=ans[i-2];
//		ans[i]+=a[pa]+a[pa+1];
//		pa+=2;
//		while(pa>1 && pc<n && a[pa-2]+a[pa-1]<c[pc]) {
//			ans[i]-=a[pa-2]+a[pa-1];
//			ans[i]+=c[pc];
//			pa-=2;
//			pc++;
//		}
//	}
//	for(int i=1;i<=m;i++) Ans^=ans[i];
//	printf("%lld",Ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P7113 [NOIP2020] 排水系统
//#include <bits/stdc++.h>
//#define up(i,a,b) for(int i=a;i<=b;i++)
//#define down(i,a,b) for(int i=a;i>=b;i--)
//#define mem(a,v) memset(a,v,sizeof(a))
//#define i128 __int128
//using namespace std;
//const int INF = 0x7f7f7f7f;
//const int MAXN = 1e5+7;
//const int MOD = 1e9+7;
//inline int read() {
//    int x=0, f=1;
//    char ch=getchar();
//    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
//    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
//    return x*f;
//}
//inline void write(i128 x){
//	if(x>9)write(x/10);
//	putchar(x%10+'0');
//}
//inline i128 gcd(i128 x,i128 y){
//	if(y==0)return x;
//	return gcd(y,x%y);
//}
//int n,m;
//struct Edge{
//	int next,to;
//}edge[MAXN*2];
//struct N{
//	i128 p,q;
//	N operator +(const N& b){
//		N c;
//		if(p==0)return b;
//		if(b.p==0)return *this;
//		c.p=p*b.q+b.p*q;
//		c.q=q*b.q;
//		i128 g=gcd(c.p,c.q);
//		c.p/=g,c.q/=g;
//		return c;
//	}
//};
//void print(N a){
//	write(a.p);putchar(' ');
//	write(a.q);putchar('\n');
//}
//struct node{
//	int ind,oud;
//	N val;
//}v[MAXN];
//int head[MAXN],cnt;
//void add(int x,int y){
//	edge[++cnt].to=y;
//	edge[cnt].next=head[x];
//	head[x]=cnt;
//}
//void dfs(int x){
//	N qs=v[x].val;
//	qs.q*=v[x].oud;
//	for(int i=head[x];i;i=edge[i].next){
//		int y=edge[i].to;
//		v[y].val=v[y].val+qs;
//		dfs(y);
//	}
//	if(v[x].oud!=0)v[x].val={0,0};
//}
//signed main() {
//	n=read(),m=read();
//	up(i,1,n){
//		int d=read();
//		v[i].oud=d;
//		up(j,1,d){
//			int y=read();
//			v[y].ind++;
//			add(i,y);
//		}
//	}
//	up(i,1,n){
//		if(v[i].ind==0){
//			v[i].val={1,1};
//			dfs(i);
//		}
//	}
//	up(i,1,n) if(v[i].oud==0) print(v[i].val);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B. Deja Vu
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int a[maxn],x[maxn],vis[maxn];
//int lg[31];
//int n,q,ans[maxn],t;
//int solve(int t) {
//	int p=0,k=0;
//	for(int i=1; i<=q; i++) {
//		if(p==0&&x[i]<=t) k=x[i]-1,p+=lg[x[i]-1];
//		if(x[i]<=k) {
//			p+=lg[x[i]-1];
//			k=x[i]-1;
//		}
//	}
//	return p;
//}
//signed main() {
//	scanf("%lld",&t);
//	lg[0]=1;
//	for(int i=1; i<=30; ++i) lg[i]=lg[i-1]*2;
//	while(t--) {
//		memset(vis,0,sizeof(vis));
//		scanf("%lld %lld",&n,&q);
//		for(int i=1; i<=n; i++) {
//			scanf("%lld",&a[i]);
//			for(int j=0; j<=30; ++j) if(a[i]%lg[j]==0) vis[i]=j;
//		}
//		for(int i=1; i<=q; i++) scanf("%lld",&x[i]);
//		for(int i=0; i<=30; i++) ans[i]=solve(i);
//		for(int i=1; i<=n; i++) printf("%lld ",a[i]+ans[vis[i]]);
//		puts("");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A. Sorting with Twos
//#include <bits/stdc++.h>
//using namespace std;
//int t,n;
//int a[10000001];
//signed main() {
//	cin>>t;
//	while(t--) {
//		int f=0;
//		cin>>n;
//		for(int i=1; i<=n; i++) {
//			cin>>a[i];
//			if(f) continue;
//			if(i==2||i==3||i==5||i==9||i==17) continue;
//			if(a[i-1]>a[i]) f=1;
//		}
//		if(f==1) cout<<"NO"<<endl;
//		else cout<<"YES"<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B3644 【模板】拓扑排序 / 家谱树
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 105
//using namespace std;
//int n,cnt;
//int indeg[maxn],ans[maxn];
//vector <int> P[maxn];
//void tosort() {
//	queue <int> C;
//	for(int i=1;i<=n;i++) if(indeg[i]==0) C.push(i);
//	while(!C.empty()){
//		int fro=C.front();
//		ans[++cnt]=fro;
//		C.pop();
//		for(int i=0;i<P[fro].size();i++) {
//			int now=P[fro][i];
//			indeg[now]--;
//			if(indeg[now]==0) C.push(now);
//		}
//	}
//}
//signed main() {
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) {
//		while(1) {
//			int x;
//			scanf("%lld",&x);
//			if(x==0) break;
//			else P[i].push_back(x),indeg[x]++;
//		}
//	}
//	tosort();
//	for(int i=1;i<=cnt;i++) printf("%lld ",ans[i]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1507	NASA的食物计划
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 1005
//using namespace std;
//int hh,tt,n;
//struct aa {
//	int h,t,k;
//} a[maxn];
//int dp[maxn][maxn];
//signed main() {
//	scanf("%lld %lld %lld",&hh,&tt,&n);
//	for(int i=1; i<=n; i++) scanf("%lld %lld %lld",&a[i].h,&a[i].t,&a[i].k);
//	for(int i=1; i<=n; i++) for(int j=hh; j>=a[i].h; j--) for(int ttt=tt; ttt>=a[i].t; ttt--) dp[j][ttt]=max(dp[j][ttt],dp[j-a[i].h][ttt-a[i].t]+a[i].k);
//	printf("%lld",dp[hh][tt]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1164 小A点菜
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 10005
//using namespace std;
//int n,m;
//int a[maxn],dp[101][maxn];
//signed main() {
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=m;j++) {
//			if(j==a[i]) dp[i][j]=dp[i-1][j]+1;
//			if(j>a[i]) dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
//			if(j<a[i]) dp[i][j]=dp[i-1][j];
//		}
//	}
//	cout<<dp[n][m];
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1832	A+B Problem（再升级）
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 1007
//using namespace std;
//int n;
//int b[maxn],cnt=1;
//int dp[maxn];
//void prime(){
//	for(int i=2;i<=500;i++) if(!b[i]) for(int j=2;i*j<=1000;j++) b[i*j]=1;
//}
//signed main() {
//	prime();
//	scanf("%lld",&n);
//	dp[0]=1;
//	for(int i=2;i<=n;i++) if(!b[i]) for(int j=i;j<=n;j++) dp[j]+=dp[j-i];
//	printf("%lld",dp[n]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B.  颜色限制（restriction）
//#include<bits/stdc++.h>
//#define maxn 100005
//#define int long long
//#define lc rt<<1
//#define rc rt<<1|1
//using namespace std;
//struct edge {
//	int x,y;
//};
//struct node {
//	int l,r;
//	vector <edge> apr;
//} tree[maxn<<2];
//void build(int rt,int l,int r) {
//	tree[rt].l=l;
//	tree[rt].r=r;
//	if(l==r) return;
//	int mid=(l+r)>>1;
//	build(lc,l,mid),build(rc,mid+1,r);
//	return;
//}
//void update(int rt,int l,int r,edge v) {
//	if(l>r) return ;
//	if(tree[rt].l>=l&&tree[rt].r<=r) {
//		tree[rt].apr.push_back(v);
//		return;
//	}
//	if(tree[lc].r>=l) update(lc,l,r,v);
//	if(tree[rc].l<=r) update(rc,l,r,v);
//	return;
//}
//int fa[maxn],siz[maxn],mx[maxn],my[maxn],mcnt,cou;
//int find(int x) {
//	return fa[x]==x?x:find(fa[x]);
//}
//void merge(int x,int y) {
//	x=find(x),y=find(y);
//	if(siz[x]<siz[y]) swap(x,y);
//	mcnt++,mx[mcnt]=x,my[mcnt]=y,fa[y]=x,siz[x]+=siz[y],cou--;
//	return;
//}
//bool linked[maxn];
//void query(int rt) {
//	int mem=mcnt;
//	for(edge now:tree[rt].apr) if(find(now.x)!=find(now.y)) merge(now.x,now.y);
//	if(tree[rt].l==tree[rt].r) linked[tree[rt].l]=(cou==1);
//	else query(lc),query(rc);
//	while(mcnt>mem) fa[my[mcnt]]=my[mcnt],siz[mx[mcnt]]-=siz[my[mcnt]],cou++,mcnt--;
//	return;
//}
//int n,m,k;
//int icou[maxn];
//signed main() {
//	freopen("restriction.in","r",stdin);
//	freopen("restriction.out","w",stdout);
//	scanf("%lld %lld %lld",&n,&m,&k);
//	build(1,1,k),cou=n;
//	for(int i=1; i<=n; i++) fa[i]=i,siz[i]=1;
//	for(int i=1; i<=m; i++) {
//		int x,y,c;
//		scanf("%lld %lld %lld",&x,&y,&c),c++,icou[c]++;
//		update(1,1,c-1,{x,y});
//		update(1,c+1,k,{x,y});
//	}
//	query(1);
//	int fans=0,sans=0;
//	for(int i=1; i<=k; i++) if(linked[i]) fans++,sans+=(m-icou[i]==n-1);
//	printf("%lld %lld",fans,sans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//C.  wap
//#include<bits/stdc++.h>
//#define int long long
//#define inl inline
//#define maxn 500005
//using namespace std;
//int n,m,x,y,ma,a[maxn],b[maxn],c[maxn],ans;
//signed main() {
//	freopen("wap.in","r",stdin);
//	freopen("wap.out","w",stdout);
//	scanf("%lld %lld",&n,&m);
//	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
//	for(int i=1,t; i<=n; ++i) scanf("%lld",&t),ans+=abs(a[i]-t),b[i]=min(a[i],t),c[i]=max(a[i],t);
//	sort(b+1,b+n+1,greater<int>());
//	sort(c+1,c+n+1);
//	for(int i=1; i<=m&&b[i]>c[i]; ++i) ans+=2*(b[i]-c[i]);
//	printf("%lld\n",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//#define lc rt<<1
//#define rc rt<<1|1
//using namespace std;
//int n,m,r,p,id;
//int w[maxn];
//struct aa {
//	int tag,sum;
//} a[maxn<<2];
//vector <int> P[maxn];
//int rk[maxn],dfn[maxn],top[maxn];
//int deep[maxn],siz[maxn],hson[maxn],fa[maxn];
//void dfs1(int x) { //维护每个子树的大小,每个节点的深度,每个重儿子的编号,每个节点的父亲
//	siz[x]=1,hson[x]=0;
//	for(int i=0; i<P[x].size(); i++) {
//		int now=P[x][i];
//		if(now==fa[x]) continue;
//		deep[now]=deep[x]+1;
//		fa[now]=x;
//		dfs1(now);
//		siz[x]+=siz[now];
//		if(siz[now]>siz[hson[x]]) hson[x]=now;
//	}
//}
//void dfs2(int x,int tp) {// 维护dfn序,每条链的顶端节点,在dfn序上的点编号
//	top[x]=tp;
//	dfn[x]=++id;
//	rk[id]=x;
//	if(hson[x]) dfs2(hson[x],tp);
//	for(int i=0; i<P[x].size(); i++) {
//		int now=P[x][i];
//		if(now==hson[x]||now==fa[x]) continue;
//		dfs2(now,now);
//	}
//}
//void push_up(int rt) {
//	a[rt].sum=(a[lc].sum+a[rc].sum)%p;
//}
//void build(int rt,int l,int r) {
//	if(l==r) {
//		a[rt].sum=w[rk[l]]%p;
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(lc,l,mid);
//	build(rc,mid+1,r);
//	push_up(rt);
//}
//void push_down(int rt,int l,int r) {
//	int mid=(l+r)>>1;
//	a[lc].sum=(a[lc].sum%p+(mid-l+1)*a[rt].tag%p)%p;
//	a[rc].sum=(a[rc].sum%p+(r-mid)*a[rt].tag%p)%p;
//	a[lc].tag=(a[lc].tag%p+a[rt].tag%p)%p;
//	a[rc].tag=(a[rc].tag%p+a[rt].tag%p)%p;
//	a[rt].tag=0;
//}
//void update(int rt,int l,int r,int L,int R,int x) {
//	if(L<=l&&r<=R) {
//		a[rt].tag=(a[rt].tag%p+x%p)%p;
//		a[rt].sum=(a[rt].sum%p+(r-l+1)*x%p)%p;
//		return ;
//	}
//	push_down(rt,l,r);
//	int mid=(l+r)>>1;
//	if(L<=mid) update(lc,l,mid,L,R,x);
//	if(R>mid) update(rc,mid+1,r,L,R,x);
//	push_up(rt);
//}
//int query(int rt,int l,int r,int L,int R) {
//	if(L<=l&&r<=R) return a[rt].sum;
//	push_down(rt,l,r);
//	int ans=0,mid=(l+r)>>1;
//	if(L<=mid) ans=(ans%p+query(lc,l,mid,L,R)%p)%p;
//	if(R> mid) ans=(ans%p+query(rc,mid+1,r,L,R)%p)%p;//
//	return ans;
//}
//void Qup(int x,int y,int z) {
//	while(top[x]!=top[y]) {
//		if(deep[top[x]]<deep[top[y]]) swap(x,y);
//		update(1,1,n,dfn[top[x]],dfn[x],z);
//		x=fa[top[x]];
//	}
//	if(deep[x]>deep[y]) swap(x,y);
//	update(1,1,n,dfn[x],dfn[y],z);
//	return ;
//}
//int Qsum(int x,int y) {
//	int tot=0;
//	while(top[x]!=top[y]) {
//		if(deep[top[x]]<deep[top[y]]) swap(x,y);
//		tot=(tot%p+query(1,1,n,dfn[top[x]],dfn[x])%p)%p;
//		x=fa[top[x]];//
//	}
//	if(deep[x]>deep[y]) swap(x,y);//
//	tot=(tot%p+query(1,1,n,dfn[x],dfn[y])%p)%p;//
//	return tot;
//}
//signed main() {
//	scanf("%lld %lld %lld %lld",&n,&m,&r,&p);
//	for(int i=1; i<=n; i++) scanf("%lld",&w[i]);
//	for(int i=1; i<n; i++) {
//		int u,v;
//		scanf("%lld %lld",&u,&v);
//		P[u].push_back(v);
//		P[v].push_back(u);
//	}
//	deep[r]=1,fa[r]=r;//
//	dfs1(r),dfs2(r,r);//
//	build(1,1,n);//
//	while(m--) {
//		int opt;
//		scanf("%lld",&opt);
//		if(opt==1) {
//			int x,y,z;
//			scanf("%lld %lld %lld",&x,&y,&z);
//			Qup(x,y,z);
//		}
//		if(opt==2) {
//			int x,y;
//			scanf("%lld %lld",&x,&y);
//			int ans=Qsum(x,y);
//			printf("%lld\n",ans);
//		}
//		if(opt==3) {
//			int x,z;
//			scanf("%lld %lld",&x,&z);
//			update(1,1,n,dfn[x],dfn[x]+siz[x]-1,z);
//		}
//		if(opt==4) {
//			int x;
//			scanf("%lld",&x);
//			int ans=query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
//			printf("%lld\n",ans);
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2590	[ZJOI2008] 树的统计
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 30004
//#define lc rt<<1
//#define rc rt<<1|1
//using namespace std;
//int n,q,id;
//int w[maxn],fa[maxn],siz[maxn],deep[maxn];
//int rk[maxn],dfn[maxn],hson[maxn],top[maxn];
//vector <int> P[maxn];
//struct aa{
//	int maxx,sum;
//}a[maxn<<2];
//void dfs1(int x) {
//	siz[x]=1,hson[x]=0;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(now==fa[x]) continue;
//		deep[now]=deep[x]+1;
//		fa[now]=x;
//		dfs1(now);
//		siz[x]+=siz[now];
//		if(siz[now]>siz[hson[x]]) hson[x]=now;
//	}
//}
//void dfs2(int x,int tp) {
//	top[x]=tp,dfn[x]=++id,rk[id]=x;
//	if(hson[x]) dfs2(hson[x],tp);
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(now==fa[x]||now==hson[x]) continue;
//		dfs2(now,now);
//	}
//}
//void push_up(int rt) {
//	a[rt].maxx=max(a[lc].maxx,a[rc].maxx);
//	a[rt].sum=a[lc].sum+a[rc].sum;
//}
//void build(int rt,int l,int r) {
//	if(l==r) {
//		a[rt].sum=w[rk[l]];
//		a[rt].maxx=w[rk[l]];
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(lc,l,mid);
//	build(rc,mid+1,r);
//	push_up(rt);
//}
//void update(int rt,int l,int r,int pos,int x) {
//	if(l==r) {
//		a[rt].maxx=a[rt].sum=x;
//		return ;
//	}
//	int mid=(l+r)>>1;
//	if(pos<=mid) update(lc,l,mid,pos,x);
//	else update(rc,mid+1,r,pos,x);
//	push_up(rt);
//}
//int query_max(int rt,int l,int r,int L,int R) {
//	if(L>R) return 0;
//	if(L<=l&&r<=R) return a[rt].maxx;
//	int mid=(l+r)>>1;
//	if(L>mid) return query_max(rc,mid+1,r,L,R);
//	if(R<=mid) return query_max(lc,l,mid,L,R);
//	return max(query_max(lc,l,mid,L,R),query_max(rc,mid+1,r,L,R));
//}
//int query_sum(int rt,int l,int r,int L,int R) {
//	if(L>R) return 0;
//	if(L<=l&&r<=R) return a[rt].sum;
//	int mid=(l+r)>>1,sum=0;
//	if(L<=mid) sum+=query_sum(lc,l,mid,L,R);
//	if(R>mid) sum+=query_sum(rc,mid+1,r,L,R);
//	return sum;
//}
//int Q_max(int x,int y) {
//   int Maxn=-1e18;
//   while(top[x]!=top[y]) {
//      if(deep[top[x]]<deep[top[y]]) swap(x,y);
//      Maxn=max(Maxn,query_max(1,1,n,dfn[top[x]],dfn[x]));
//      x=fa[top[x]];
//   }
//   if(deep[x]>deep[y]) swap(x,y);
//   Maxn=max(Maxn,query_max(1,1,n,dfn[x],dfn[y]));
//   return Maxn;
//}
//int Q_sum(int x,int y) {
//   int tot=0;
//   while(top[x]!=top[y]) {
//      if(deep[top[x]]<deep[top[y]]) swap(x,y);
//      tot+=query_sum(1,1,n,dfn[top[x]],dfn[x]);
//      x=fa[top[x]];
//   }
//   if(deep[x]>deep[y])swap(x,y);
//   tot+=query_sum(1,1,n,dfn[x],dfn[y]);
//   return tot;
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<n;i++) {
//		int x,y;
//		scanf("%lld %lld",&x,&y);
//		P[x].push_back(y);
//		P[y].push_back(x);
//	}
//	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
//	fa[1]=deep[1]=1;
//	dfs1(1);dfs2(1,1);
//	build(1,1,n);
//	scanf("%lld",&q);
//	while(q--) {
//		string s;
//		cin>>s;
//		if(s[0]=='C') {
//			int x,y;
//			scanf("%lld %lld",&x,&y);
//			update(1,1,n,dfn[x],y);
//		}
//		if(s[1]=='M') {
//			int x,y;
//			scanf("%lld %lld",&x,&y);
//			printf("%lld\n",Q_max(x,y));
//		}
//		if(s[1]=='S') {
//			int x,y;
//			scanf("%lld %lld",&x,&y);
//			printf("%lld\n",Q_sum(x,y));
//		}
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF839C Journey
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n;
//double dp[maxn];
//vector <int> P[maxn];
//void dfs(int x,int fa) {
//	int cnt=0;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(now==fa) continue;
//		dfs(now,x);
//		dp[x]+=(dp[now]+1.0);
//		cnt++;
//	}
//	if(cnt) dp[x]/=(double)cnt;
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<n;i++) {
//		int u,v;
//		scanf("%lld %lld",&u,&v);
//		P[u].push_back(v);
//		P[v].push_back(u);
//	}
//	dfs(1,0);
//	printf("%.15lf",dp[1]);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1056D
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int n;
//int siz[maxn];
//vector <int> P[maxn];
//void dfs(int x) {
//	if(!P[x].size()) {
//		siz[x]=1;
//		return ;
//	}
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		dfs(now);
//		siz[x]+=siz[now];
//	}
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int i=2;i<=n;i++) {
//		int fa;
//		scanf("%lld",&fa);
//		P[fa].push_back(i);
//	}
//	dfs(1);
//	sort(siz+1,siz+n+1);
//	for(int i=1;i<=n;i++) printf("%lld ",siz[i]);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF431C	k-Tree
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 105
//#define mod 1000000007
//using namespace std;
//int n,k,d;
//int f[maxn][2];
//signed main(){
//	scanf("%lld %lld %lld",&n,&k,&d);
//	f[0][0]=1;
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=min(i,k);j++) {
//			if(j<d) f[i][0]+=f[i-j][0],f[i][1]+=f[i-j][1];
//			else f[i][1]+=f[i-j][1]+f[i-j][0];
//			f[i][0]%=mod,f[i][1]%=mod;
//		}
//	}
//	printf("%lld\n",f[n][1]);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1336A Linova and Kingdom
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int n,k;
//int deep[maxn],fa[maxn],siz[maxn],val[maxn];
//vector <int> P[maxn];
//void dfs(int x){
//	siz[x]=1;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(fa[x]==now) continue;
//		fa[now]=x;
//		deep[now]=deep[x]+1;
//		dfs(now);
//		siz[x]+=siz[now];
//	}
//	val[x]=deep[x]-siz[x];
//}
//signed main(){
//	scanf("%lld %lld",&n,&k);
//	for(int i=1;i<n;i++) {
//		int u,v;
//		scanf("%lld %lld",&u,&v);
//		P[u].push_back(v);
//		P[v].push_back(u);
//	}
//	deep[1]=1,fa[1]=1;
//	dfs(1);
//	sort(val+1,val+n+1);
//	int ans=0;
//	for(int i=n-k+1;i<=n;i++) ans+=val[i];
//	printf("%lld",ans); 
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1528A Parsa's Humongous Tree
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int T,n;
//int l[maxn],r[maxn],dp[maxn][10];
//vector <int> P[maxn];
//void dfs(int x,int fa) {
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(now==fa) continue;
//		dfs(now,x);
//		dp[x][0]+=max(dp[now][1]+abs(r[now]-l[x]),dp[now][0]+abs(l[now]-l[x]));
//        dp[x][1]+=max(dp[now][0]+abs(l[now]-r[x]),dp[now][1]+abs(r[now]-r[x]));
//	}
//}
//signed main(){
//	scanf("%lld",&T);
//	while(T--) {
//		memset(P,0,sizeof(P));
//		memset(l,0,sizeof(l));
//		memset(r,0,sizeof(r));
//		memset(dp,0,sizeof(dp));
//		scanf("%lld",&n);
//		for(int i=1;i<=n;i++) {
//			scanf("%lld %lld",&l[i],&r[i]);
//			dp[i][0]=dp[i][1]=0;
//		}
//		for(int i=1;i<n;i++) {
//			int u,v;
//			scanf("%lld %lld",&u,&v);
//			P[u].push_back(v);
//			P[v].push_back(u);
//		}
//		dfs(1,0);
//		printf("%lld\n",max(dp[1][0],dp[1][1]));
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF763A Timofey and a tree
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,c[maxn],num[maxn],sum;
//int a[maxn],b[maxn];
//bool flag=false;
//signed main() {
//	cin>>n;
//	for(int i=1; i<n; i++) scanf("%lld %lld",&a[i],&b[i]);
//	for(int i=1; i<=n; i++) scanf("%lld",&c[i]);
//	for(int i=1; i<n; i++) if(c[a[i]]!=c[b[i]]) sum++,num[a[i]]++,num[b[i]]++;
//	for(int i=1; i<=n&&flag==false; i++) if(sum==num[i])  printf("YES\n%lld\n",i),flag=true;
//	if(!flag) puts("NO");
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000007
//using namespace std;
//int n,T,L,R,cnt;
//int a[maxn];
//struct aa{
//	int x,y,z;
//}t[maxn];
//signed main() {
//	freopen("star.in", "r", stdin);
//	freopen("star.out", "w", stdout);
//	scanf("%lld %lld",&n,&T);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<=T;i++) scanf("%lld %lld %lld",&t[i].x,&t[i].y,&t[i].z);
//	scanf("%lld %lld",&L,&R);
//	for(int i=T;i>=1;i--) {
//		if(t[i].z==1) {
//			if((L-1)%t[i].x==t[i].y)L--;
//			if(R%t[i].x==t[i].y)R--;
//		} else if(t[i].z==-1) {
//			if(L%t[i].x==t[i].y)L++;
//			if((R+1)%t[i].x==t[i].y)R++;
//		}
//	}
//	for(int i=1;i<=n;i++) if(a[i]>=L&&a[i]<=R) cnt++;
//	printf("%lld\n",cnt);
//	for(int i=1;i<=n;i++) if(a[i]>=L&&a[i]<=R) printf("%lld ",i);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include<bits/stdc++.h>
//#define RI int
//#define err puts("asd")
//#define ll long long
//#define ull unsigned long long
//#define LL __int128
//#define db long double
//#define mk make_pair
//#define FL fflush(stdout)
//#define eb emplace_back
//#define FR(u,v) for(int i=h[u],v=a[i].t;i;i=a[i].n,v=a[i].t)
//#define FB(x,z,y) for(int y=__lg(x&-x)+1,z=x;z;z^=z&-z,y=__lg(z&-z)+1)
//#define FS(x,y) for(int y=x;y;y=(y-1)&x)
//#define mem(a,b) memset(a,b,sizeof a)
//#define yes puts("Yes")
//#define no puts("No")
//#define gg puts("-1")
//#define vc vector
//#define ex exit(0)
//#define fi first
//#define se second
//#define int long long
//using namespace std;
//const db eps=1e-15;
//const db inf=1e12+5;
//const db INF=1e18;
//const int mod=1e9+7;
//inline ll power(ll x,int y) {
//	ll t=1;
//	while(y) {
//		if(y&1) t=t*x%mod;
//		x=x*x%mod;
//		y>>=1;
//	}
//	return t;
//}
//inline void gt(int &x,int &y) {
//	if(x>y) swap(x,y);
//}
//inline void cmax(int &x,int y) {
//	x<y?x=y:0;
//}
//inline void cmin(db &x,db y) {
//	x>y?x=y:0;
//}
//inline void AD(int &x,int y) {
//	x+=y;
//	if(x>mod) x-=mod;
//}
//inline ll read() {
//	ll s=0;
//	char c=getchar();
//	bool f=0;
//	while(c<'0'||c>'9') {
//		if(c=='-') f=1;
//		c=getchar();
//	}
//	while(c>='0'&&c<='9') s=(s<<1)+(s<<3)+c-48,c=getchar();
//	return f?-s:s;
//}
//const int N=4e5+5;
//struct wu {
//	int n,t;
//} a[N<<1];
//int n,m,K,rt[N],tot,L[N],R[N],C[N],X[N];
//int siz[N],pri[N],lc[N],rc[N],cnt,k;
//db f[N],val[N],tag[N],sum[N];
//int tong[N],stk[N],topf,h[N],p,fa[N],si[N],son[N],D;
//pair<int,pair<int,int> >g[N];
//vc<int>q[N],V[N];
//inline void add(int u,int v) {
//	a[++p].t=v;
//	a[p].n=h[u];
//	h[u]=p;
//}
//inline int New(db x,int y=0) {
//	if(!y) y=++tot;
//	else lc[y]=rc[y]=0;
//	val[y]=x;
//	f[y]=x;
//	tag[y]=inf;
//	siz[y]=1;
//	pri[y]=rand();
//	return y;
//}
//inline void up(int x) {
//	if(!x) return;
//	siz[x]=siz[lc[x]]+siz[rc[x]]+1;
//	f[x]=f[lc[x]]+f[rc[x]]+val[x];
//}
//inline void calc(int x,db v) {
//	f[x]=siz[x]*v;
//	cmin(val[x],v);
//	cmin(tag[x],v);
//}
//inline void down(int x) {
//	if(tag[x]!=inf) {
//		if(lc[x]) calc(lc[x],tag[x]);
//		if(rc[x]) calc(rc[x],tag[x]);
//		tag[x]=inf;
//	}
//}
//inline void split(int rt,db k,int &x,int &y) {
//	if(!rt) {
//		x=y=0;
//		return;
//	}
//	down(rt);
//	if(val[rt]<=k) x=rt,split(rc[rt],k,rc[x],y);
//	else y=rt,split(lc[rt],k,x,lc[y]);
//	up(rt);
//}
//inline int merge(int x,int y) {
//	if(!x||!y) return x^y;
//	if(pri[x]>pri[y]) {
//		down(x);
//		rc[x]=merge(rc[x],y);
//		return up(x),x;
//	} else {
//		down(y);
//		lc[y]=merge(x,lc[y]);
//		return up(y),y;
//	}
//}
//ll res;
//int now;
//db vv,S,F;
//inline void Do(int x,int &H) {
//	if(!x) return;
//	down(x);
//	Do(lc[x],H);
//	Do(rc[x],H);
//	RI u,v;
//	split(H,val[x],u,v);
//	H=merge(merge(u,New(val[x],x)),v);
//}
//inline void ask(int x) {
//	if(!x) return;
//	down(x);
//	if(now!=siz[lc[x]]+1&&vv-f[lc[x]]-val[x]>=val[x]*(now-siz[lc[x]]-1)) {
//		vv-=f[lc[x]]+val[x];
//		now-=siz[lc[x]]+1;
//		S=val[x];
//		ask(rc[x]);
//	} else ask(lc[x]);
//}
//inline void solve(int u) {
//	si[u]=V[u].size();
//	FR(u,v) {
//		solve(v);
//		si[u]+=si[v];
//		if(si[v]>si[son[u]]) son[u]=v;
//	}
//	if(son[u]) rt[u]=rt[son[u]];
//	FR(u,v) if(v!=son[u]) Do(rt[v],rt[u]);
//	RI x,y;
//	for(RI v:V[u]) {
//		split(rt[u],v,x,y);
//		rt[u]=merge(merge(x,New(v)),y);
//	}
//	if(!X[u]) return;
//	S=0;
//	now=siz[rt[u]];
//	vv=f[rt[u]]-X[u];
//	if(vv<0) {
//		if(rt[u]) calc(rt[u],0);
//		res+=vv;
//		return;
//	}
//	ask(rt[u]);
//	split(rt[u],S,x,y);
//	calc(y,vv/now);
//	rt[u]=merge(x,y);
//}
//inline void getans(int x) {
//	if(!x) return;
//	down(x);
//	getans(lc[x]);
//	sum[++cnt]=val[x];
//	getans(rc[x]);
//}
//ll P,Q,W;
//db ans;
//inline db get(int x) {
//	if(x<W) return INF;
//	return sum[x]+P-(x-W)*Q;
//}
//inline void work(int l,int r) {
//	if(l>r) return;
//	l=n-l;
//	r=n-r;
//	gt(l,r);
//	W=l;
//	RI mid,pos;
//	while(l<=r) {
//		mid=l+r>>1;
//		if(get(mid)<=get(mid-1)) l=mid+1,pos=mid;
//		else r=mid-1;
//	}
//	ans=min(ans,get(pos));
//}
//signed main() {
//	ll x=0,y=0,z=0,u=0,v=0,SS=0;
//	freopen("12.in","r",stdin);
//	freopen("12.out","w",stdout);
//	n=read();
//	m=read();
//	K=read();
//	srand(time(0));
//	for(RI i=1; i<=n; ++i) C[i]=read(),SS+=C[i];
//	for(RI i=1; i<=m; ++i) L[i]=read(),R[i]=read(),X[i]=read(),res+=X[i],q[L[i]].eb(i);
//	R[++m]=n;
//	q[1].eb(m);
//	for(RI i=1; i<=n; ++i) {
//		topf-=tong[i];
//		sort(q[i].begin(),q[i].end(),[](int x,int y) {return R[x]>R[y];});
//		for(RI x:q[i]) {
//			++tong[R[x]+1];
//			if(stk[topf]) add(stk[topf],x);
//			else D=x;
//			stk[++topf]=x;
//		}
//		V[stk[topf]].eb(C[i]);
//	}
//	solve(D);
//	getans(rt[D]);
//	for(RI i=1; i<=cnt; ++i) sum[i]+=sum[i-1];
//	while(K--) {
//		k=read();
//		z=0;
//		P=Q=0;
//		ans=INF;
//		for(RI i=1; i<=k; ++i) {
//			x=read();
//			y=read();
//			if(y/x<=n) g[++z]=mk(y/x,mk(y-y/x*x,x)),P+=y;
//			else P+=x*n,Q+=x;
//		}
//		sort(g+1,g+z+1);
//		g[z+1].fi=n;
//		y=z+1;
//		for(RI i=z; i>0; --i) {
//			if(g[i].fi==g[i-1].fi) {
//				g[i-1].se.fi+=g[i].se.fi;
//				g[i-1].se.se+=g[i].se.se;
//				continue;
//			}
//			work(g[i].fi+1,g[y].fi);
//			P-=g[i].se.fi+Q*(g[y].fi-g[i].fi);
//			Q+=g[i].se.se;
//			y=i;
//		}
//		work(0,g[1].fi);
//		printf("%.0Lf\n",ans+res);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1689C Infected Tree
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 300005
//using namespace std;
//int t,n;
//vector <int> P[maxn];
//int siz[maxn],dp[maxn];
//void dfs(int x,int fa) {
//	siz[x]=1,dp[x]=0;
//	int sum=0;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(now==fa) continue;
//		dfs(now,x);
//		sum+=dp[now];
//		siz[x]+=siz[now];
//	}
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(now!=fa) dp[x]=max(dp[x],sum-dp[now]+siz[now]-1);
//	}
//}
//signed main(){
//	scanf("%lld",&t);
//	while(t--) {
//		memset(P,0,sizeof(P));
//		scanf("%lld",&n);
//		for(int i=1;i<n;i++) {
//			int u,v;
//			scanf("%lld %lld",&u,&v);
//			P[u].push_back(v);
//			P[v].push_back(u);
//		}
//		dfs(1,0);
//		printf("%lld\n",dp[1]);
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF682C Alyona and the Tree
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//struct aa{
//	int u,w;
//};
//int n,cnt=0;
//int a[maxn],vis[maxn];
//vector <aa> P[maxn];
//void dfs(int x,int sum) {
//	if(vis[maxn]||sum>a[x]) return ;
//	cnt++,vis[x]=1;
//	for(int i=0;i<P[x].size();i++) {
//		aa now=P[x][i];
//		dfs(now.u,max(sum+now.w,now.w));
//	}
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=2;i<=n;i++) {
//		int p,c;
//		scanf("%lld %lld",&p,&c);
//		P[p].push_back({i,c});
//	}
//	dfs(1,0);
//	printf("%lld",n-cnt);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF219D Choosing Capital for Treeland
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int n;
//struct aa{
//	int to,flag;
//};
//vector <aa> P[maxn];
//int dp[maxn];
//void dfs1(int x,int fa) {
//	for(int i=0;i<P[x].size();i++) {
//		aa now=P[x][i];
//		if(now.to==fa) continue;
//		dfs1(now.to,x);
//		dp[x]+=dp[now.to]+now.flag;
//	}
//}
//void dfs2(int x,int fa) {
//	for(int i=0;i<P[x].size();i++) {
//		aa now=P[x][i];
//		if(now.to==fa) continue;
//		dp[now.to]=dp[x]+(now.flag?-1:1);
//		dfs2(now.to,x);
//	}
//}
//signed main() {
//	while(scanf("%lld",&n)!=EOF) {
//		int ans=1e18;
//		memset(P,0,sizeof(P));
//		memset(dp,0,sizeof(dp));
//		for(int i=1; i<n; i++) {
//			int a,b;
//			scanf("%lld %lld",&a,&b);
//			P[a].push_back({b,0});
//			P[b].push_back({a,1});
//		}
//		dfs1(1,-1),dfs2(1,-1);
//		for(int i=1;i<=n;i++) ans=min(ans,dp[i]);
//		printf("%lld\n",ans);
//		for(int i=1;i<=n;i++) if(ans==dp[i]) printf("%lld ",i);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1693B Fake Plastic Trees
//#include<bits/stdc++.h>
//#define maxn 200005
//#define int long long
//using namespace std;
//int n,T;
//vector<int> P[maxn];
//int l[maxn],r[maxn],val[maxn],ans;
//void dfs(int x) {
//    int add=0;
//    for(int i=0;i<P[x].size();i++) {
//        int now=P[x][i];
//		dfs(now);
//        add+=val[now];
//    }
//    if(add>=l[x]) val[x]=min(add,r[x]);
//    else {
//        val[x]=r[x];
//        ans++;
//    }
//}
//signed main() {
//    scanf("%lld",&T);
//    while(T--) {
//    	memset(P,0,sizeof(P));
//    	memset(val,0,sizeof(val));
//		ans=0;
//        scanf("%lld",&n);
//        for(int i=2; i<=n; i++) {
//            int fa; 
//            scanf("%lld",&fa);
//            P[fa].push_back(i);
//        }
//        for(int i=1; i<=n; i++) scanf("%lld %lld",&l[i],&r[i]);
//        dfs(1);
//        printf("%lld\n",ans);
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1592C Bakry and Partitioning
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int t,n,k,sum,cnt;
//int a[maxn];
//vector <int> P[maxn];
//int dfs(int x,int fa) {
//	int noww=a[x],ans;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(fa==now) continue;
//		ans=dfs(now,x);
//		if(ans==sum) cnt++;
//		else noww^=ans;
//	}
//	return noww;
//}
//signed main(){
//	scanf("%lld",&t);
//	while(t--) {
//		memset(P,0,sizeof(P));
//		sum=0,cnt=0;
//		scanf("%lld %lld",&n,&k);
//		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum^=a[i];
//		for(int i=1;i<n;i++) {
//			int u,v;
//			scanf("%lld %lld",&u,&v);
//			P[u].push_back(v);
//			P[v].push_back(u);
//		}
//		if(!sum) printf("YES\n");
//		else if(k>=3){
//			dfs(1,0);
//			if(cnt>=2) printf("YES\n");
//			else printf("NO\n");
//		} else printf("NO\n");
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1822F Gardening Friends
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int t,n,k,c,ans;
//vector <int> P[maxn];
//int dfs(int x,int fa,int deep) {
//	int max1=0,max2=0;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(now==fa) continue;
//		int de=dfs(now,x,deep+1)+1;
//		if(de>max1) max2=max1,max1=de;
//		else max2=max(max2,de); 
//	}
//	ans=max(ans,max1*k+max(0ll,max2*(k-c)-deep*c));
//	return max1;
//}
//signed main(){
//	scanf("%lld",&t);
//	while(t--) {
//		ans=0;
//		memset(P,0,sizeof(P));
//		scanf("%lld %lld %lld",&n,&k,&c);
//		for(int i=1;i<n;i++) {
//			int u,v;
//			scanf("%lld %lld",&u,&v);
//			P[u].push_back(v);
//			P[v].push_back(u);
//		}
//		dfs(1,-1,0);
//		printf("%lld\n",ans);
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P5019	[NOIP2018 提高组] 铺设道路
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,ans;
//int h[maxn];
//signed main() {
//    scanf("%lld",&n);
//    for(int i=1; i<=n; i++) scanf("%lld",&h[i]);
//    for(int i=1; i<=n; i ++) if(h[i]>h[i-1]) ans+=(h[i]-h[i-1]); 
//    printf("%lld",ans);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1965 [NOIP2013 提高组] 转圈游戏
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m,k,x;
//int qpow(int x,int k) {
//	int ans=1;
//    while(k) {
//        if(k&1) ans=((ans%n)*(x%n))%n;
//        x=((x%n)*(x%n))%n;
//        k>>=1;
//    }
//    return ans;
//}
//signed main(){
//	int ans=0;
//	scanf("%lld %lld %lld %lld",&n,&m,&k,&x);
//	ans=((m%n)*(qpow(10,k)%n)+x%n)%n;
//	printf("%lld",ans);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//B.  远古题
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 40004
//using namespace std;
//int n,cnt=0;
//int vis[maxn],prime[maxn];
//double ln[maxn],dp[maxn];
//void get_prime(int n) {
//	for(int i=2; i<=n; i++) {
//		if(vis[i]==0) prime[++cnt]=i,ln[cnt]=log(i);
//		for(int j=1; prime[j]*i<=n&&j<=cnt; j++) {
//			vis[prime[j]*i]=1;
//			if(i%prime[j]==0)break;
//		}
//	}
//}
//signed main() {
//	freopen("icecream.in","r",stdin);
//	freopen("icecream.out","w",stdout);
//	scanf("%lld",&n);
//	get_prime(n);
//	for(int i=1; i<=cnt; i++) {
//		for(int j=n; j>=prime[i]; j--) {
//			int pp=prime[i],k=1;
//			while(pp<=j) {
//				dp[j]=max(dp[j-pp]+ln[i]*k,dp[j]);
//				pp*=prime[i]; k++;
//			}
//		}
//	}
//	printf("%.7lf", dp[n]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A.多树 
//#include <bits/stdc++.h>
//#define maxn 505
//#define int long long
//using namespace std;
//int n,k;
//vector<int> P[maxn];
//int dis[maxn][maxn],cnt[maxn][maxn];
//void dfs(int st,int x,int fa,int d) {
//	dis[st][x]+=d;
//	for(int i=0;i<P[x].size();i++) {
//		int now=P[x][i];
//		if(now==fa) continue;
//		dfs(st,now,x,d+1);
//	}
//}
//signed main() {
//	freopen("trees.in", "r", stdin);
//	freopen("trees.out", "w", stdout);
//	scanf("%lld%lld", &n, &k);
//	for(int i=1; i<=k; i++) {
//		memset(P,0,sizeof(P));
//		for(int j=1; j<n; j++) {
//			int u,v;
//			scanf("%lld%lld",&u,&v);
//			P[u].push_back(v);
//			P[v].push_back(u);
//		}
//		for(int j=1;j<=n;j++) dfs(j,j,0,0);
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) {
//			for(int k=1;k<=n;k++) if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]++;
//			printf("%lld ",cnt[i][j]);
//		}
//		puts("");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1970 [NOIP2013 提高组] 花匠
//#include<bits/stdc++.h>
//#define maxn 100010
//#define int long long
//using namespace std;
//int a[maxn],f[maxn][2];
//int n,tmp=0;
//signed main(){
//    scanf("%lld",&n);
//    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
//    f[1][0]=f[1][1]=1;
//    for(int i=2;i<=n;i++){
//        if(a[i]>a[i-1]) f[i][0]=f[i-1][1]+1;
//        else f[i][0]=f[i-1][0];
//        if(a[i]<a[i-1]) f[i][1]=f[i-1][0]+1;
//        else f[i][1]=f[i-1][1];
//    }
//    printf("%lld",max(f[n][0],f[n][1]));
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P7960 [NOIP2021] 报数
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 10000100
//using namespace std;
//int T;
//int vis[maxn],ans[maxn];
//bool check(int x) {
//	while(x) {
//		if(x%10==7) return 1;
//		x/=10;
//	}
//	return 0;
//}
//void init() {
//	int x;
//	for (int i=1; i<=maxn-10; i++) {
//		if(vis[i]) continue;
//		if(check(i)) {
//			for (int j=i; j<=maxn-10; j+=i) vis[j]=1;
//			continue;
//		}
//		ans[x]=i;
//		x=i;
//	}
//}
//signed main() {
//	init();
//	scanf("%lld",&T);
//	while (T--) {
//		int x;
//		scanf("%lld",&x);
//		if(vis[x])  printf("-1\n");
//		else printf("%lld\n",ans[x]);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3952 [NOIP2017 提高组] 时间复杂度
//#include<bits/stdc++.h>
//#define maxn 110
//#define int  long long
//using namespace std;
//string a,b;
//int c,d,e,f[27],g[27],h,k,l[100],m,n,T;
//c是有几个句子，d是题目给的复杂度是多少
//e是当前在几重循环，f[]是判断变量是否使用过
//g[]是存下每个循环的变量，h是当前复杂度是多少(与e不同)
//k是判断下面程序是否进行，l[]是存下哪几个循环加了复杂度
//m是当前最大复杂度，n是存下k=1时的循环数
//signed main() {
//	scanf("%lld",&T);
//	while(T--) {
//		c=0,d=0,m=0,n=0,e=0,h=0,k=0;
//		memset(f,0,sizeof(f));
//		memset(l,0,sizeof(l));
//		do {
//			a=b;
//			cin>>b;
//		} while(b[0]!='O');     //读入，当b[0]='O'时停下，保证ERR时下一个继续运行
//		for(int i=0; i<a.length(); i++) c=c*10+a[i]-'0'; //取出题目给的句子数量
//		for(int i=4; i<b.length()-1; i++) d=d*10+b[i]-'0'; //取出题目给的时间复杂度 O(1)不影响
//		while(c>0) {
//			c--;
//			cin>>a;   //读入F 或 E ,句子数-1
//			if(a[0]=='F') { //如果是F
//				e++;
//				cin>>a;   //当前循环数+1，读入变量
//				if(f[a[0]-96]) e=-1;    //如果被用过，标记ERR
//				else f[a[0]-96]=1,g[e]=a[0]-96;    //没用过就标记用过，并存起来
//				cin>>a>>b;      //读入变量初值和末值
//				if(a[0]!='n'&&b[0]=='n'&&k==0) h++,l[e]=1;   //如果a是数字，b是n，而且可以运行，那么当前复杂度+1，记下循环数
//				else if(((a.length()==b.length()&&a>b)||(a.length()>b.length())||(a[0]=='n'&&b[0]!='n'))&&k==0) k=1,n=e;
				//如果a>b(n 4,45 12,24 9),而且可以运行，那么标记下面的都不能运行，记下当前循环
				//像5 8，76 78, n n 之类的不影响，不需要处理
//			} else {
				//如果是E
//				m=max(m,h);
//				f[g[e]]=0;     //将最大复杂度更改 ，变量标记没用过
//				if(l[e]==1) h--,l[e]=0;    //如果当前循环加了复杂度，当前复杂度-1，标记清空
//				e--;    //当前循环数-1
//				if(n>0&&e<n) k=0,n=0;   //如果跳出了n标记的那个循环，那么接下来的循环可以运行，标记清空
//			}
//			if(e==-1) printf("ERR\n"),c=-1;   //如果e<0(变量用过或者E过多)，那么输出ERR，跳出循环
//		}
//		if(e>0) printf("ERR\n");    //如果e>0(F过量)，那么输出ERR，跳出循环
//		if(e==0&&m==d) printf("Yes\n");   //如果F,E相同而且最大复杂度等于题目给的复杂度，输出Yes
//		if(e==0&&m!=d) printf("No\n");    //如果F,E相同而且最大复杂度不等于题目给的复杂度，输出No
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2822	[NOIP2016 提高组] 组合数问题
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 2004
//using namespace std;
//int t,k;
//int C[maxn][maxn],ans[maxn][maxn];
//void init(int n){
//	C[0][0]=1;
//	C[1][0]=C[1][1]=1;
//	for(int i=1;i<=n;i++){
//		C[i][0]=1;
//		for(int j=1;j<=i;j++){
//			C[i][j]=(C[i-1][j-1]+C[i-1][j])%k;
//			ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
//			if(C[i][j]==0)ans[i][j]++;
//		}
//		ans[i][i+1]=ans[i][i];
//	}
//}
//signed main() {
//	scanf("%lld %lld",&t,&k);
//	init(2000);
//	while(t--){
//		int n,m;
//		scanf("%lld %lld",&n,&m);
//		if(m>n) printf("%lld\n",ans[n][n]);
//		else printf("%lld\n",ans[n][m]);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P5020 [NOIP2018 提高组] 货币系统
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 250007
//using namespace std;
//int T,n;
//int a[maxn],dp[maxn];
//signed main() {
//	scanf("%lld",&T);
//	while(T--) {
//		memset(dp,0xcf,sizeof(dp));
//		scanf("%lld",&n);
//		int ans=n;
//		dp[0]=0;
//		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//		for(int i=1;i<=n;i++) for(int j=a[i];j<=maxn;j++) dp[j]=max(dp[j],dp[j-a[i]]+1);
//		for(int i=1;i<=n;i++) if(dp[a[i]]>=2) ans--;
//		printf("%lld\n",ans);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P8865	[NOIP2022] 种花
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1005
//#define mod 998244353
//using namespace std;
//int T,id;
//int sum[maxn][maxn];
//char Map[maxn][maxn];
//signed main() {
//	scanf("%lld %lld",&T,&id);
//	while(T--) {
//		memset(sum,0,sizeof(sum));
//		int n,m,c,f,ansc=0,ansf=0;
//		scanf("%lld %lld %lld %lld",&n,&m,&c,&f);
//		for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>Map[i][j];
//		for(int i=1; i<=n; i++) {
//			for(int j=m-1; j>=1; j--) {
//				if(Map[i][j]=='1') sum[i][j]=-1;
//				else if(Map[i][j+1]=='0') sum[i][j]=sum[i][j+1]+1;
//			}
//		}
//		//预处理:能种花的区域的个数. 
//		for(int j=1; j<m; j++) {
//			int jis=0,jil=0,jilf=0;
//			for(int i=1; i<=n; i++) {
//				if(sum[i][j]==-1) {
//					jilf=jis=jil=0;
//					continue;
//				}
//				ansc=ansc%mod+(sum[i][j]*(jil%mod))%mod;//乘法原理 
//				ansf=(ansf%mod+jilf%mod)%mod;
//				jilf=(jilf+(sum[i][j]*(jil%mod))%mod)%mod;
//				jil+=max(0ll,sum[i-1][j]);
//			}
//		}
//		printf("%lld %lld\n",(c*ansc)%mod,(f*ansf)%mod);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A.  辉下辨真
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 5010
//#define pmod 998244353
//using namespace std;
//int n,m,f[maxn],g[maxn],ff[maxn];
//signed main() {
//	freopen("true.in","r",stdin);
//	freopen("true.out","w",stdout);
//	scanf("%lld %lld",&n,&m);
//	swap(n,m);
//	for(int i=1; i<=n; i++)f[i]=(i*(i+1)/2)%pmod;
//	for(int i=1; i<=n; i++) g[i]=f[n+1-i];
//	int s=f[n];
//	for(int k=2; k<=m; k++ ) {
//		for(int i=1; i<=n; i++) ff[i]=(ff[i-1]+f[i])%pmod;
//		for(int i=1; i<=n; i++) f[i]=i*(s-g[i+1])%pmod,f[i]-=ff[i-1];
//		for(int i=1; i<=n; i++) f[i]=(f[i-1]+f[i])%pmod;
//		for(int i=1; i<=n; i++) g[i]=f[n+1-i];
//		s=f[n];
//	}
//	printf("%lld\n",(s+pmod)%pmod);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1967 [NOIP2013 提高组] 货车运输
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100004
//using namespace std;
//int n,m;
//int faa[maxn],fa[maxn][31],deep[maxn],w[maxn][31];
//bool vis[maxn];
//struct A { int to,w; };
//vector <A> P[maxn],Pp[maxn];
//struct Acin { int x,y,z; } a[maxn];
//bool cmp(Acin p,Acin pp) { return p.z>pp.z; }
//int find(int x) {
//	if(faa[x]==x) return faa[x];
//	return faa[x]=find(faa[x]);
//}
//void dfs(int x) {
//	vis[x]=true;
//	for(int i=0; i<Pp[x].size(); i++) {
//		A now=Pp[x][i];
//		if(vis[now.to]) continue;
//		deep[now.to]=deep[x]+1;
//		w[now.to][0]=now.w;
//		fa[now.to][0]=x;
//		dfs(now.to);
//	}
//}
//int LCA(int x, int y) {
//	if(find(x)!=find(y)) return -1;
//	int ans=1e18;
//	if(deep[x]>deep[y]) swap(x,y);
//	for(int i=20; i>=0; i--) if(deep[fa[y][i]]>=deep[x]) ans=min(ans, w[y][i]),y=fa[y][i];
//	if(x==y) return ans;
//	for(int i=20; i>=0; i--)
//		if(fa[x][i]!=fa[y][i]) {
//			ans=min(ans, min(w[x][i],w[y][i]));
//			x=fa[x][i],y=fa[y][i];
//		}
//	ans=min(ans,min(w[x][0], w[y][0]));
//	return ans;
//}
//signed main() {
//	scanf("%lld %lld",&n,&m);
//	for(int i=1; i<=m; i++) {
//		scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
//		P[a[i].x].push_back({a[i].y,a[i].z});
//		P[a[i].y].push_back({a[i].x,a[i].z});
//	}
//	sort(a+1,a+m+1,cmp);
//	for(int i=1; i<=n; i++) faa[i]=i;
//	for(int i=1; i<=m; i++) {
//		if(find(a[i].x)!=find(a[i].y)) {
//			int fx=find(a[i].x),fy=find(a[i].y);
//			faa[fx]=fy;
//			Pp[a[i].x].push_back({a[i].y,a[i].z});
//			Pp[a[i].y].push_back({a[i].x,a[i].z});
//		}
//	}
//	for(int i=1; i<=n; i++) {
//		if(!vis[i]) {
//			deep[i]=1;
//			dfs(i);
//			fa[i][0]=i,w[i][0]=1e18;
//		}
//	}
//	for(int i=1; i<=20; i++)
//		for(int j=1; j<=n; j++) {
//			fa[j][i]=fa[fa[j][i-1]][i-1];
//			w[j][i]=min(w[j][i-1], w[fa[j][i-1]][i-1]);
//		}
//	int q;
//	scanf("%lld",&q);
//	while(q--) {
//		int x,y;
//		scanf("%lld %lld",&x,&y);
//		printf("%lld",LCA(x,y));
//		if(q!=0) puts(""); 
//	}
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF652F Ants on a Circle
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 300005
//using namespace std;
//int n,m,t,ans[maxn],eid;
//char ch;
//struct ant { int x,d,id; } a[maxn],e[maxn];
//bool cmp(ant a,ant b) { return a.x<b.x; }
//signed main() {
//	scanf("%lld %lld %lld",&n,&m,&t);
//	for(int i=1; i<=n; i++) {
//		scanf("%lld %c",&a[i].x,&ch);
//		a[i].id=i;
//		if(ch=='L') {
//			a[i].d=e[i].d=-1;
//			eid=((eid-(t+m-a[i].x)/m)%n+n)%n;
//			e[i].x=((a[i].x-t)%m+m-1)%m+1;
//		} else {
//			a[i].d=e[i].d=1;
//			eid=(eid+(t+a[i].x-1)/m)%n;
//			e[i].x=((a[i].x+t)%m+m-1)%m+1;
//		}
//	}
//	sort(a+1,a+n+1,cmp);
//	sort(e+1,e+n+1,cmp);
//	for(int i=1; i<=n; i++) ans[a[i].id]=e[(i+eid-1)%n+1].x;
//	for(int i=1; i<=n; i++) printf("%lld ",ans[i]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1966	[NOIP2013 提高组] 火柴排队
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//#define mod (int)(1e8-3)
//using namespace std;
//int n,ans=0;
//int t[maxn],re[maxn],tp[maxn];
//struct aa{ int h,id,st; }a[maxn],b[maxn];
//bool cmp(aa x,aa y) { return x.h<y.h; }
//inline void msort(int l, int r) { 
//	int mid=(l+r)/2;
//	if(l==r)  return ; 
//	else msort(l, mid),msort(mid+1,r);
//	int i=l,j=mid+1,cnt=l;
//	while(i<=mid&&j<=r) {
//		if(t[i]>t[j]) {
//			ans+=mid-i+1;
//			tp[cnt++]=t[j++];
//		} else tp[cnt++]=t[i++];
//	}
//	while(i<=mid) tp[cnt++]=t[i++];
//	while(j<=r) tp[cnt++]=t[j++];
//	for(register int i=l;i<=r;++i) t[i]=tp[i];
//	return;
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i].h),a[i].id=i;
//	for(int i=1;i<=n;i++) scanf("%lld",&b[i].h),b[i].id=i;
//	sort(a+1,a+n+1,cmp),sort(b+1,b+n+1,cmp);
//	for(int i=1;i<=n;i++) a[a[i].id].st=i,b[b[i].id].st=i;
//	for(int i=1;i<=n;i++) re[b[i].st]=i;
//	for(int i=1;i<=n;i++) t[i]=re[a[i].st];
//	msort(1,n);
//	printf("%lld",ans%mod);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//Splay (lyc)
//#include <bits/stdc++.h>
//#define maxn 1100006
//#define l(p) Child[p][0]
//#define r(p) Child[p][1]
//#define cp(z) Child[p][z]
//#define cu(z) Child[u][z]
//#define Sret(z) { Splay(u); return (z); }
//int Root,t,n,m,o,l,y,z,
//int f[maxn],Child[maxn][2],v[maxn],c[maxn],s[maxn];
//inline void ChangeSize(int p) {
//	s[p] = s[l(p)] + s[r(p)] + c[p];
//}
//inline bool ChildSide(int p) {
//	return p == r(f[p]);
//}
//inline void Clear(int p) {
//	l(p) = r(p) = f[p] = v[p] = c[p] = s[p] = 0;
//}
//inline void Rotate(int p) {
//	int u = f[p], x = f[u], q = ChildSide(p);
//	cu(q) = cp(q ^ 1);
//	if (cp(q ^ 1)) f[cp(q ^ 1)] = u;
//	cp(q ^ 1) = u;
//	f[u] = p;
//	f[p] = x;
//	if (x) Child[x][u == r(x)] = p;
//	ChangeSize(p);
//	ChangeSize(u);
//}
//inline void Splay(int p) {
//	for (int q = f[p]; q = f[p], q; Rotate(p))
//		if (f[q]) Rotate(ChildSide(p) == ChildSide(q) ? q : p);
//	Root = p;
//}
//inline void Insert(int p) {
//	if (!Root) {
//		v[++t] = p;
//		++c[Root = t];
//		++s[t];
//		return;
//	}
//	int u = Root, x = 0;
//	while (true) {
//		if (v[u] == p) {
//			++c[u];
//			ChangeSize(u);
//			ChangeSize(x);
//			Splay(u);
//			return;
//		}
//		x = u;
//		u = cu(v[u] < p);
//		if (!u) {
//			v[++t] = p;
//			++c[t];
//			f[t] = x;
//			Child[x][v[x] < p] = t;
//			++s[t];
//			ChangeSize(x);
//			Splay(t);
//			return;
//		}
//	}
//}
//inline int Rank(int p) {
//	int u = Root, x = 0;
//	while (true)
//		if (p < v[u]) u = l(u);
//		else {
//			x += s[l(u)];
//			if (p == v[u]) Sret(x + 1);
//			x += c[u];
//			u = r(u);
//		}
//}
//inline int Pth(int p) {
//	int u = Root;
//	while (true)
//		if (l(u) && p <= s[l(u)]) u = l(u);
//		else {
//			p -= c[u] + s[l(u)];
//			if (p < 1) Sret(v[u]);
//			u = r(u);
//		}
//}
//inline int PreSuc(bool p) {
//	int u = p ? r(Root) : l(Root);
//	while (p ? l(u) : r(u)) u = p ? l(u) : r(u);
//	Sret(u);
//}
//inline void Delete(int p) {
//	Rank(p);
//	int u = Root, x;
//	if (c[u] > 1) {
//		--c[u];
//		--s[u];
//		return;
//	}
//	if (!l(u) && !r(u)) {
//		Clear(u);
//		Root = 0;
//		return;
//	}
//	if (!l(u)) {
//		f[Root = r(u)] = 0;
//		Clear(u);
//		return;
//	}
//	if (!r(u)) {
//		f[Root = l(u)] = 0;
//		Clear(u);
//		return;
//	}
//	f[r(u)] = x = PreSuc(false);
//	r(x) = r(u);
//	Clear(u);
//}
//inline int Read() {
//	char c = getchar();
//	int p = 0;
//	while (c < '0' || c > '9') c = getchar();
//	while (c > 47 && c < 58) p = (p << 3) + (p << 1) + c - 48, c = getchar();
//	return p;
//}
//int main() {
//	n = Read(), m = Read();
//	for (int i = 1; i <= n; ++i) y = Read(), Insert(y);
//	while (m--) {
//		o = Read(), y = Read() ^ l;
//		if (o < 2) Insert(y);
//		else if (o < 3) Delete(y);
//		else if (o < 4) {
//			Insert(y);
//			l = Rank(y);
//			Delete(y);
//		} else if (o < 5) l = Pth(y);
//		else {
//			Insert(y);
//			l = v[PreSuc(o - 5)];
//			Delete(y);
//		}
//		if (o > 2 && l) z ^= l;
//	}
//	printf("%d\n", z);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include <cstdio>
//const int N = 100005;
//int rt, tot, fa[N], ch[N][2], val[N], cnt[N], sz[N];
//struct Splay {
//	void maintain(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x]; }
//	bool get(int x) { return x == ch[fa[x]][1]; }
//	void clear(int x) { ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0; }
//	void rotate(int x) {
//		int y = fa[x], z = fa[y], chk = get(x);
//		ch[y][chk] = ch[x][chk ^ 1];
//		if (ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
//		ch[x][chk ^ 1] = y;
//		fa[y] = x;
//		fa[x] = z;
//		if (z) ch[z][y == ch[z][1]] = x;
//		maintain(y);
//		maintain(x);
//	}
//	void splay(int x) {
//		for (int f = fa[x]; f = fa[x], f; rotate(x)) if (fa[f]) rotate(get(x) == get(f) ? f : x);
//		rt = x;
//	}
//	void ins(int k) {
//		if (!rt) {
//			val[++tot] = k;
//			cnt[tot]++;
//			rt = tot;
//			maintain(rt);
//			return;
//		}
//		int cur = rt, f = 0;
//		while (1) {
//			if (val[cur] == k) {
//				cnt[cur]++;
//				maintain(cur);
//				maintain(f);
//				splay(cur);
//				break;
//			}
//			f = cur;
//			cur = ch[cur][val[cur] < k];
//			if (!cur) {
//				val[++tot] = k;
//				cnt[tot]++;
//				fa[tot] = f;
//				ch[f][val[f] < k] = tot;
//				maintain(tot);
//				maintain(f);
//				splay(tot);
//				break;
//			}
//		}
//	}
//	int rk(int k) {
//		int res = 0, cur = rt;
//		while (1) {
//			if (k < val[cur]) {
//				cur = ch[cur][0];
//			} else {
//				res += sz[ch[cur][0]];
//				if (k == val[cur]) {
//					splay(cur);
//					return res + 1;
//				}
//				res += cnt[cur];
//				cur = ch[cur][1];
//			}
//		}
//	}
//	int kth(int k) {
//		int cur = rt;
//		while (1) {
//			if (ch[cur][0] && k <= sz[ch[cur][0]]) {
//				cur = ch[cur][0];
//			} else {
//				k -= cnt[cur] + sz[ch[cur][0]];
//				if (k <= 0) {
//					splay(cur);
//					return val[cur];
//				}
//				cur = ch[cur][1];
//			}
//		}
//	}
//	int pre() {
//		int cur = ch[rt][0];
//		if (!cur) return cur;
//		while (ch[cur][1]) cur = ch[cur][1];
//		splay(cur);
//		return cur;
//	}
//	int nxt() {
//		int cur = ch[rt][1];
//		if (!cur) return cur;
//		while (ch[cur][0]) cur = ch[cur][0];
//		splay(cur);
//		return cur;
//	}
//
//	void del(int k) {
//		rk(k);
//		if (cnt[rt] > 1) {
//			cnt[rt]--;
//			maintain(rt);
//			return;
//		}
//		if (!ch[rt][0] && !ch[rt][1]) {
//			clear(rt);
//			rt = 0;
//			return;
//		}
//		if (!ch[rt][0]) {
//			int cur = rt;
//			rt = ch[rt][1];
//			fa[rt] = 0;
//			clear(cur);
//			return;
//		}
//		if (!ch[rt][1]) {
//			int cur = rt;
//			rt = ch[rt][0];
//			fa[rt] = 0;
//			clear(cur);
//			return;
//		}
//		int cur = rt;
//		int x = pre();
//		fa[ch[cur][1]] = x;
//		ch[x][1] = ch[cur][1];
//		clear(cur);
//		maintain(rt);
//	}
//} tree;
//int main() {
//	int n, opt, x;
//	for (scanf("%d", &n); n; --n) {
//		scanf("%d%d", &opt, &x);
//		if (opt == 1) tree.ins(x);
//		else if (opt == 2) tree.del(x);
//		else if (opt == 3) printf("%d\n", tree.rk(x));
//		else if (opt == 4) printf("%d\n", tree.kth(x));
//		else if (opt == 5) tree.ins(x), printf("%d\n", val[tree.pre()]), tree.del(x);
//		else tree.ins(x), printf("%d\n", val[tree.nxt()]), tree.del(x);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P6136	【模板】普通平衡树(数据加强版) (my)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1100005
//#define l(p) child[p][0]
//#define r(p) child[p][1]
//#define cp(z) child[p][z]
//#define cu(z) child[u][z]
//#define Sret(z) { Splay(u); return (z); }
//using namespace std;
//int root,t,las,ans;
//int fa[maxn],siz[maxn],cnt[maxn],val[maxn];
//int child[maxn][2];
//struct Sp {
//	void change_size(int p) {
//		siz[p]=siz[l(p)]+siz[r(p)]+cnt[p];
//	}
//	bool child_side(int p) {
//		return p==r(fa[p]);
//	}
//	void clear(int p) {
//		l(p)=r(p)=fa[p]=val[p]=cnt[p]=siz[p]=0;
//	}
//	void rotate(int p) {
//		int u=fa[p],x=fa[u],q=child_side(p);
//		cu(q)=cp(q^1);
//		if(cp(q^1)) fa[(cp(q^1))]=u;
//		cp(q^1)=u;
//		fa[u]=p,fa[p]=x;
//		if(x) child[x][u==r(x)]=p;
//		change_size(p);
//		change_size(u);
//	}
//	void Splay(int p) {
//		for(int q=fa[p]; q=fa[p],q; rotate(p)) if(fa[q]) rotate(child_side(p)==child_side(q)?q:p);
//		root=p;
//	}
//	void Insert(int p) {
//		if(!root) {
//			val[++t] = p;
//			++cnt[root=t];
//			++siz[t];
//			return;
//		}
//		int u=root,x=0;
//		while(true) {
//			if (val[u]==p) {
//				++cnt[u];
//				change_size(u);
//				change_size(x);
//				Splay(u);
//				return;
//			}
//			x=u;
//			u=cu(val[u]<p);
//			if(!u) {
//				val[++t]=p;
//				++cnt[t];
//				fa[t]=x;
//				child[x][val[x]<p]=t;
//				++siz[t];
//				change_size(x);
//				Splay(t);
//				return;
//			}
//		}
//	}
//	int Rank(int p) {
//		int u=root,x=0;
//		while (true) {
//			if(p<val[u]) u=l(u);
//			else {
//				x+=siz[l(u)];
//				if(p==val[u]) Sret(x+1);
//				x+=cnt[u];
//				u=r(u);
//			}
//		}
//	}
//	int Pth(int p) {
//		int u=root;
//		while (true) {
//			if (l(u)&&p<=siz[l(u)]) u=l(u);
//			else {
//				p-=cnt[u]+siz[l(u)];
//				if(p<1) Sret(val[u]);
//				u=r(u);
//			}
//		}
//	}
//	int PreSuc(bool p) {
//		int u=p?r(root):l(root);
//		while (p?l(u):r(u)) u=p?l(u):r(u);
//		Sret(u);
//	}
//	void Delete(int p) {
//		Rank(p);
//		int u=root,x;
//		if (cnt[u]>1) {
//			--cnt[u];
//			--siz[u];
//			return;
//		}
//		if (!l(u)&&!r(u)) {
//			clear(u);
//			root=0;
//			return;
//		}
//		if (!l(u)) {
//		    root=r(u);
//			fa[root]=0;
//			clear(u);
//			return;
//		}
//		if (!r(u)) {
//		    root=l(u);
//			fa[root] = 0;
//			clear(u);
//			return;
//		}
//		fa[r(u)]=x=PreSuc(false);
//		r(x)=r(u);
//		clear(u);
//	}
//} Tree;
//inline int Read() {
//	char c=getchar();
//	int p=0;
//	while (c<'0'||c>'9') c=getchar();
//	while (c>47&&c<58) p=(p<<3)+(p<<1)+c-48,c=getchar();
//	return p;
//}
//signed main() {
//	int n=Read(), m=Read();
//	for(int i=1; i<=n; i++) {
//		int a=Read();
//		Tree.Insert(a);
//	}
//	while(m--) {
//		int opt=Read(),x=Read()^las;
//		if(opt==1) Tree.Insert(x);
//		if(opt==2) Tree.Delete(x);
//		if(opt==3) Tree.Insert(x),las=Tree.Rank(x),Tree.Delete(x);
//		if(opt==4) las=Tree.Pth(x);
//		if(opt>=5) Tree.Insert(x),las=val[Tree.PreSuc((opt-5))],Tree.Delete(x);
//		if(opt>2&&las) ans^=las;
//	}
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P6136	【模板】普通平衡树(数据加强版)(lyc)
//#include <bits/stdc++.h>
//#define maxn 1100006
//#define l(p) Child[p][0]
//#define r(p) Child[p][1]
//#define cp(z) Child[p][z]
//#define cu(z) Child[u][z]
//#define Sret(z) { Splay(u); return (z); }
//using namespace std;
//int Root,t,n,m,o,l,y,z;
//int f[maxn],Child[maxn][2],v[maxn],c[maxn],s[maxn];
//inline void ChangeSize(int p) {
//	s[p] = s[l(p)] + s[r(p)] + c[p];
//}
//inline bool ChildSide(int p) {
//	return p == r(f[p]);
//}
//inline void Clear(int p) {
//	l(p) = r(p) = f[p] = v[p] = c[p] = s[p] = 0;
//}
//inline void Rotate(int p) {
//	int u = f[p], x = f[u], q = ChildSide(p);
//	cu(q) = cp(q ^ 1);
//	if (cp(q ^ 1)) f[cp(q ^ 1)] = u;
//	cp(q ^ 1) = u;
//	f[u] = p;
//	f[p] = x;
//	if (x) Child[x][u == r(x)] = p;
//	ChangeSize(p);
//	ChangeSize(u);
//}
//inline void Splay(int p) {
//	for (int q = f[p]; q = f[p], q; Rotate(p))
//		if (f[q]) Rotate(ChildSide(p) == ChildSide(q) ? q : p);
//	Root = p;
//}
//inline void Insert(int p) {
//	if (!Root) {
//		v[++t] = p;
//		++c[Root = t];
//		++s[t];
//		return;
//	}
//	int u = Root, x = 0;
//	while (true) {
//		if (v[u] == p) {
//			++c[u];
//			ChangeSize(u);
//			ChangeSize(x);
//			Splay(u);
//			return;
//		}
//		x = u;
//		u = cu(v[u] < p);
//		if (!u) {
//			v[++t] = p;
//			++c[t];
//			f[t] = x;
//			Child[x][v[x] < p] = t;
//			++s[t];
//			ChangeSize(x);
//			Splay(t);
//			return;
//		}
//	}
//}
//inline int Rank(int p) {
//	int u = Root, x = 0;
//	while (true)
//		if (p < v[u]) u = l(u);
//		else {
//			x += s[l(u)];
//			if (p == v[u]) Sret(x + 1);
//			x += c[u];
//			u = r(u);
//		}
//}
//inline int Pth(int p) {
//	int u = Root;
//	while (true)
//		if (l(u) && p <= s[l(u)]) u = l(u);
//		else {
//			p -= c[u] + s[l(u)];
//			if (p < 1) Sret(v[u]);
//			u = r(u);
//		}
//}
//inline int PreSuc(bool p) {
//	int u = p ? r(Root) : l(Root);
//	while (p ? l(u) : r(u)) u = p ? l(u) : r(u);
//	Sret(u);
//}
//inline void Delete(int p) {
//	Rank(p);
//	int u = Root, x;
//	if (c[u] > 1) {
//		--c[u];
//		--s[u];
//		return;
//	}
//	if (!l(u) && !r(u)) {
//		Clear(u);
//		Root = 0;
//		return;
//	}
//	if (!l(u)) {
//		f[Root = r(u)] = 0;
//		Clear(u);
//		return;
//	}
//	if (!r(u)) {
//		f[Root = l(u)] = 0;
//		Clear(u);
//		return;
//	}
//	f[r(u)] = x = PreSuc(false);
//	r(x) = r(u);
//	Clear(u);
//}
//inline int Read() {
//	char c = getchar();
//	int p = 0;
//	while (c < '0' || c > '9') c = getchar();
//	while (c > 47 && c < 58) p = (p << 3) + (p << 1) + c - 48, c = getchar();
//	return p;
//}
//int main() {
//	n = Read(), m = Read();
//	for (int i = 1; i <= n; ++i) y = Read(), Insert(y);
//	while (m--) {
//		o = Read(), y = Read() ^ l;
//		if (o < 2) Insert(y);
//		else if (o < 3) Delete(y);
//		else if (o < 4) {
//			Insert(y);
//			l = Rank(y);
//			Delete(y);
//		} else if (o < 5) l = Pth(y);
//		else {
//			Insert(y);
//			l = v[PreSuc(o - 5)];
//			Delete(y);
//		}
//		if (o > 2 && l) z ^= l;
//	}
//	printf("%d\n", z);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3369	【模板】普通平衡树
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//#define l(p) child[p][0]
//#define r(p) child[p][1]
//#define cp(z) child[p][z]
//#define cu(z) child[u][z]
//#define Sret(z) { Splay(u); return (z); }
//using namespace std;
//int root,t,las,ans;
//int fa[maxn],siz[maxn],cnt[maxn],val[maxn];
//int child[maxn][2];
//struct Sp {
//	void change_size(int p) {
//		siz[p]=siz[l(p)]+siz[r(p)]+cnt[p];
//	}
//	bool child_side(int p) {
//		return p==r(fa[p]);
//	}
//	void clear(int p) {
//		l(p)=r(p)=fa[p]=val[p]=cnt[p]=siz[p]=0;
//	}
//	void rotate(int p) {
//		int u=fa[p],x=fa[u],q=child_side(p);
//		cu(q)=cp(q^1);
//		if(cp(q^1)) fa[(cp(q^1))]=u;
//		cp(q^1)=u;
//		fa[u]=p,fa[p]=x;
//		if(x) child[x][u==r(x)]=p;
//		change_size(u);
//		change_size(p);
//	}
//	void Splay(int p) {
//		for(int q=fa[p]; q=fa[p],q; rotate(p)) if(fa[q]) rotate(child_side(p)==child_side(q)?q:p);
//		root=p;
//	}
//	void Insert(int p) {
//		if(!root) {
//			val[++t] = p;
//			++cnt[root=t];
//			++siz[t];
//			return;
//		}
//		int u=root,x=0;
//		while(true) {
//			if (val[u]==p) {
//				++cnt[u];
//				change_size(u);
//				change_size(x);
//				Splay(u);
//				return;
//			}
//			x=u;
//			u=cu(val[u]<p);
//			if(!u) {
//				val[++t]=p;
//				++cnt[t];
//				fa[t]=x;
//				child[x][val[x]<p]=t;
//				++siz[t];
//				change_size(x);
//				Splay(t);
//				return;
//			}
//		}
//	}
//	int Rank(int p) {
//		int u=root,x=0,i=0;
//		while (++i) {
//			if(p<val[u]) u=l(u);
//			else {
//				x+=siz[l(u)];
//				if(i>100) Sret(x+1);
//				if(p==val[u]) Sret(x+1);
//				x+=cnt[u];
//				u=r(u);
//			}
//		}
//	}
//	int Pth(int p) {
//		int u=root;
//		while (true) {
//			if (l(u)&&p<=siz[l(u)]) u=l(u);
//			else {
//				p-=cnt[u]+siz[l(u)];
//				if(p<1) Sret(val[u]);
//				u=r(u);
//			}
//		}
//	}
//	int PreSuc(bool p) {
//		int u=p?r(root):l(root);
//		while (p?l(u):r(u)) u=p?l(u):r(u);
//		Sret(u);
//	}
//	void Delete(int p) {
//		Rank(p);
//		int u=root,x;
//		if (cnt[u]>1) {
//			--cnt[u];
//			--siz[u];
//			return;
//		}
//		if (!l(u)&&!r(u)) {
//			clear(u);
//			root=0,t=0;
//			return;
//		}
//		if (!l(u)) {
//		    root=r(u);
//			fa[root]=0;
//			clear(u);
//			return;
//		}
//		if (!r(u)) {
//		    root=l(u);
//			fa[root] = 0;
//			clear(u);
//			return;
//		}
//		fa[r(u)]=x=PreSuc(false);
//		r(x)=r(u);
//		clear(u);
//	}
//} Tree;
//signed main() {
//	freopen("P3369_8.in","r",stdin);
//	freopen("test.txt","w",stdout);
//	int n;
//	scanf("%lld",&n);
//	while(n--) {
//		int opt,x;
//		scanf("%lld %lld",&opt,&x);
//		if(opt==1) Tree.Insert(x);
//		if(opt==2) Tree.Delete(x);
//		if(opt==3) Tree.Insert(x),printf("%lld\n",Tree.Rank(x)),Tree.Delete(x);
//		if(opt==4) printf("%lld\n",Tree.Pth(x));
//		if(opt>=5) Tree.Insert(x),printf("%lld\n",val[Tree.PreSuc((opt-5))]),Tree.Delete(x);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A.  动态仙人掌
//#include<bits/stdc++.h>
//using namespace std;
//char s[200];
//int tong[10];
//vector <int> mp[200],nmp[200];
//bool vis[200];
//struct point {
//	int x;
//	string s;
//};
//int main() {
//	int n;
//	cin>>n;
//	scanf("%s",s+1);
//	for(int i=n; i>=0; --i) {
//		for(int j=0; j<=9; ++j) {
//			if(!tong[j]) nmp[i].push_back(j);
//			if(tong[j]) mp[i].push_back(tong[j]);
//		}
//		tong[s[i]-'0']=i;
//	}
//	queue <point> q;
//	point node;
//	node.s="",node.x=0;
//	q.push(node);
//	while(!q.empty()) {
//		node=q.front();
//		q.pop();
//		if(vis[node.x]) continue;
//		vis[node.x]=1;
//		for(int i=0; i<nmp[node.x].size(); ++i) {
//			int to=nmp[node.x][i];
//			cout<<node.s+char(to+'0');
//			exit(0);
//		}
//		for(int i=0; i<mp[node.x].size(); ++i) {
//			int to=mp[node.x][i];
//			if(s[to]=='0'&&node.x==0) continue;
//			point newnode;
//			newnode.x=to;
//			newnode.s=node.s+s[to];
//			q.push(newnode);
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3370 【模板】字符串哈希
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//#define mod 9223372036854775783
//using namespace std;
//int n,a[maxn];
//string s;
//int get_hash(string x) {
//	int len=x.size();
//	int ans=0;
//	for(int i=0;i<len;i++) ans=(ans*129+(int)s[i])%mod;
//	return ans;
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) {
//		cin>>s;
//		a[i]=get_hash(s);
//	}
//	int sum=1;
//	sort(a+1,a+n+1);
//	for(int i=2;i<=n;i++) if(a[i-1]!=a[i]) sum++;
//	printf("%lld",sum);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P8306 【模板】字典树
// #pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 3000005
//using namespace std;
//int T;
//int get_num(char x) {
//	if(x<='Z'&&x>='A') return x-'A';
//	if(x<='9'&&x>='0') return x-'0'+52;
//	if(x<='z'&&x>='a') return x-'a'+26;
//}
//struct Trie {
//	int ans[maxn];
//	int nxt[maxn][70],cnt;
//	void init() {
//		for(int i=0;i<=cnt;++i){
//			ans[i]=0;
//			for(int j=0;j<=69;++j) nxt[i][j]=0;
//		}
//		cnt=0;
//	}
//	void insert(string s) {
//		int p=0,len=s.size();
//		for(int i=0; i<len; i++) {
//			int now=get_num(s[i]);
//			if(!nxt[p][now]) nxt[p][now]=++cnt;
//			p=nxt[p][now];
//			ans[p]++;
//		}
//	}
//	int find(string s) {
//		int p=0,len=s.size();
//		for(int i=0; i<len; i++) {
//			int now=get_num(s[i]);
//			if(!nxt[p][now]) return 0;
//			p=nxt[p][now];
//		}
//		return ans[p];
//	}
//}Tre;
//signed main() {
//	scanf("%lld",&T);
//	while(T--) {
//		int n,q;
//		scanf("%lld %lld",&n,&q);
//		Tre.init();
//		for(int i=1; i<=n; i++) {
//			string s;
//			cin>>s;
//			Tre.insert(s);
//		}
//		for(int i=1; i<=q; i++) {
//			string s;
//			cin>>s;
//			printf("%lld\n",Tre.find(s));
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3375 【模板】KMP
//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//char a[1000100],b[1000100];
//int p[1000100];
//int main() {
//	scanf("%s%s",a+1,b+1);
//	int la=strlen(a+1),lb=strlen(b+1);
//	int j=0;
//	p[1]=0;
//	//先处理出p数组，无非是b和自己匹配，与b和a匹配一样，故代码差不多
//	for(int i=2; i<=lb; i++) {
//		while(j>0 && b[i]!=b[j+1]) j=p[j];//往前翻记录了有相同前缀的j
//		if(b[i]==b[j+1]) j++;//i匹配成功了，i继续往后
//		p[i]=j;
//	}
//	j=0;
//	for(int i=1; i<=la; i++) {
//		while(j>0 && a[i]!=b[j+1]) j=p[j];
//		if(a[i]==b[j+1]) j++;
//		if(j==lb) printf("%d\n",i-lb+1),j=p[j];
//	}
//	for(int i=1; i<lb; i++) printf("%d ",p[i]);
//	printf("%d",p[lb]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//UVA1344 Tian Ji -- The Horse Racing
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 2050
//using namespace std;
//int n;
//int a[maxn],b[maxn];
//signed main() {
//	while(1) {
//		scanf("%lld",&n);
//		if(n==0) return 0;
//		for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
//		for(int i=1; i<=n; i++) scanf("%lld",&b[i]);
//		sort(a+1,a+n+1),sort(b+1,b+n+1);
//		int ans=0,la=1,lb=1,ra=n,rb=n;
//		for(int i=1; i<=n; i++) {
//			if (a[ra]>b[rb]) ans+=200,--ra,--rb;
//			else if (a[ra]<b[rb]) ans-=200,++la,--rb;
//			else if (a[la]>b[lb]) ans+=200,++la,++lb;
//			else {
//				if (a[la]<b[rb]) ans-=200;
//				++la,--rb;
//			}
//		}
//		printf("%lld\n",ans);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,d,h;
//signed main(){
//	scanf("%d %d %d",&n,&d,&h);
//	if(h*2<d) {
//		cout<<-1;
//		return 0;
//	}
//	if(d==1&&h==1&&n>2) {
//		cout<<-1;
//		return 0;
//	}
//	for(int i=2;i<=h+1;i++) printf("%d %d\n",i-1,i);
//	for(int i=h+2;i<=d+1;i++) {
//		if(i==h+2) printf("%d %d\n",1,i);
//		else printf("%d %d\n",i-1,i);
//	}
//	for(int i=d+2;i<=n;i++) {
//		if(d==h) printf("%d %d\n",2,i);
//		else printf("%d %d\n",1,i);
//	}
//    return 0;
//}
//10 3 3
//3  1 1
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1288C Two Arrays
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1005 
//using namespace std;
//const int mod=1e9+7;
//int n,m;
//int dp[maxn][maxn];
//signed main(){
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++) dp[0][i]=1;
//	m*=2;
//	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) for(int k=1;k<=j;k++) dp[i][j]=(dp[i-1][k]+dp[i][j])%mod;
//	printf("%lld",dp[m][n]);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B - T2
//#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <stdio.h>
//#include <string>
//#include <cstring>
//#include <istream>
//#include <ostream>
//#include <map>
//#include <vector>
//#include <queue>
//#include <cmath>
//#include <algorithm>
//#include <time.h>
//#include <ctime>
//#include <stdlib.h>
//#include <cstdlib>
//#include <stddef.h>
//#include <stdint.h>
//#include <stdbool.h>
//#include <math.h>
////#define int long long
//#define maxn 10005
//using namespace std;
//int T;
//int a[maxn];
//priority_queue <int> C;
//signed main() {
//	scanf("%d",&T);
//	while(T--) {
//		int m,n;
//		scanf("%d %d",&m,&n);
//		for(int i=1; i<=n; i++) {
//			scanf("%d",&a[i]);
//			C.push(a[i]);
//		}
//		for(int i=1; i<m; i++) {
//			for(int j=1; j<=n; j++) a[j]=C.top(),C.pop();
//			for(int j=1; j<=n; j++) {
//				int x;
//				scanf("%d",&x);
//				for(int k=1; k<=n; k++) {
//					if(C.size()>=n) {
//						if(C.top()>a[k]+x) C.pop(),C.push(a[k]+x);
//					}
//					else C.push(a[k]+x);
//				}
//			}
//		}
//		for(int i=1; i<=n; i++) a[i]=C.top(),C.pop();
//		for(int i=n; i>=1; i--) printf("%d ",a[i]);
//		puts("");
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T351995 「RiOI-03」water problem
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int T;
//signed main(){
//	scanf("%lld",&T);
//	while(T--) {
//		int n;
//		scanf("%lld",&n);
//		if(n==2||n==3||n==5) printf("No\n");
//		else printf("Yes\n");
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T351996 「RiOI-03」匀速相遇
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m;
//unordered_map <int,int> p;
//signed main(){
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++) {
//		int x;
//		scanf("%lld",&x);
//		p[x*i]++;
//	}
//	int ans=0;
//	for(int i=1;i<=m;i++) {
//		int x;
//		scanf("%lld",&x);
//		if(x==0) continue;
//		ans+=p[x*i];
//	}
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 105
//using namespace std;
//int n,m;
//char a[maxn][maxn];
//int dp[maxn][maxn];
//signed main(){
//	scanf("%d %d",&n,&m);
//	for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
//	dp[1][1]=(a[1][1]=='#');
//	for(int i=2;i<=m;i++) dp[1][i]=dp[1][i-1]+(a[1][i-1]=='.'&&a[1][i]=='#');
//	for(int i=2;i<=n;i++) dp[i][1]=dp[i-1][1]+(a[i-1][1]=='.'&&a[i][1]=='#');
//    for(int i=2;i<=n;i++) for(int j=2;j<=m;j++) dp[i][j]=min(dp[i-1][j]+(a[i-1][j]=='.'&&a[i][j]=='#'),dp[i][j-1]+(a[i][j-1]=='.'&&a[i][j]=='#'));
//	printf("%d",dp[n][m]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P9117	[春季测试 2023] 涂色游戏
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int T;
//struct aa{
//	int col,pri;
//}h[maxn],l[maxn];
//signed main(){
//	scanf("%lld",&T);
//	while(T--) {
//		memset(h,0,sizeof(h));
//		memset(l,0,sizeof(l));
//		int n,m,q;
//		scanf("%lld %lld %lld",&n,&m,&q);
//		for(int i=1;i<=q;i++) {
//			int opt,x,c;
//			scanf("%lld %lld %lld",&opt,&x,&c);
//			if(opt==0) {
//				h[x].col=c;
//				h[x].pri=i;
//			} else {
//				l[x].col=c;
//				l[x].pri=i;
//			}
//		}
//		for(int i=1;i<=n;i++) {
//			for(int j=1;j<=m;j++) {
//				if(h[i].pri<l[j].pri) printf("%lld ",l[j].col);
//				else printf("%lld ",h[i].col);
//			}
//			puts("");
//		}
//	}
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P9118	[春季测试 2023] 幂次
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define ll long long
//#define maxn 100005
//using namespace std;
//ll n,k,p,cnt,ans;
//map<ll,bool> mp;
//signed main(){
//	scanf("%lld %lld",&n,&k);
//	for(ll i=2;i*i*i<=n;i++) {
//		ll t=i*i,m=2;
//		while(t<=n/i) {
//			t*=i,m++;
//			if(m<k||mp[t]) continue;
//			if((ll)sqrtl(t)*sqrtl(t)==t) cnt++;
//			mp[t]=1,ans++;
//		}
//	}
//	if(k==1) printf("%lld",n);
//	else if(k>=3) printf("%lld",ans+1);
//	else printf("%lld",(ll)sqrtl(n)+ans-cnt);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P9869 [NOIP2023] 三值逻辑
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//#define T  100001
//#define F -100001
//#define U 0
//using namespace std;
//int n,m,c,t;
//int fa[maxn];
//bool vis[maxn*3];
//int find(int x) {
//	int val;
//	if(x==T||x==F) val=x;
//	else if(x==U||vis[n-x]) val=U;
//	else if(vis[n+x]) val=T;
//	else if(x<0) {
//		if(x==-fa[-x]) val=x;
//		else {
//			vis[n+x]=1;
//			val=find(-fa[-x]);
//			vis[n+x]=0;
//		}
//	} else {
//		if(x==fa[x]) val=x;
//		else {
//			vis[n+x]=1;
//			val=fa[x]=find(fa[x]);
//			vis[n+x]=0;
//		}
//	}
//	return val;
//}
//signed main(){
//	scanf("%lld %lld",&c,&t);
//	while(t--) {
//		scanf("%lld %lld",&n,&m);
//		for(int i=1;i<=n;i++) fa[i]=i,vis[i]=0;
//		for(int x=1;x<=m;x++) {
//			char opt;
//			cin>>opt;
//			if(opt=='T') {
//				int a;
//				scanf("%lld",&a);
//				fa[a]=T;
//			}
//			if(opt=='F') {
//				int a;
//				scanf("%lld",&a);
//				fa[a]=F;
//			}
//			if(opt=='U') {
//				int a;
//				scanf("%lld",&a);
//				fa[a]=U;
//			}
//			if(opt=='+') {
//				int a,b;
//				scanf("%lld %lld",&a,&b);
//				fa[a]=fa[b];
//			}
//			if(opt=='-') {
//				int a,b;
//				scanf("%lld %lld",&a,&b);
//				fa[a]=-fa[b];
//			}
//		}
//		int ans=0;
//		for(int i=1;i<=n;i++) if(find(i)==U) ans++;
//		printf("%lld\n",ans);
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//[ABC003C] AtCoderプログラミング講座
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 105
//using namespace std;
//int n,k;
//int a[maxn];
//double ans=0.0;
//signed main() {
//	scanf("%lld %lld",&n,&k);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	sort(a+1,a+n+1);
//	for(int i=n-k+1;i<=n;i++) ans=(ans+(double)a[i])*1.0/2.0;
//	printf("%.6lf",ans); 
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1582 倒水
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 500005
//using namespace std;
//int n,k,ans=0;
//signed main() {
//	scanf("%lld %lld",&n,&k);
//	while(1) {
//		int cnt1=0;
//		for(int i=0; i<64; i++) if((n&(long long)1<<i)>0) cnt1++;
//		if(cnt1<=k) break;
//		ans+=(-n)&(n);
//		n+=(-n)&n;
//	}
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2158 [SDOI2008] 仪仗队
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 400005
//using namespace std;
//int n,f[maxn],ans;
//signed main(){
//	scanf("%lld",&n);
//	if(n==1) {printf("0"); return 0;}
//	for(int i=1;i<=n;i++) f[i]=i;
//	for(int i=2;i<=n;i++) if(f[i]==i) for(int j=i;j<=n;j+=i) f[j]=f[j]*(i-1)/i;
//	for(int i=1;i<n ;i++) ans+=f[i];
//	printf("%lld",ans*2+1);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2024 [NOI2001] 食物链
//#include<bits/stdc++.h>
//#define maxn 500005
//using namespace std;
//int n,k,ans,cnt=0;
//int fa[maxn*3];
//int find(int x) {
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//struct aa { int opt,x,y; } a[maxn*3];
//signed main() {
//	freopen("P2024_in.in","r",stdin);
//	scanf("%d %d",&n,&k);
//	for(int i=1; i<=n*3; i++) fa[i]=i;
//	for(int i=1; i<=k; i++) {
//		scanf("%d %d %d",&a[i].opt,&a[i].x,&a[i].y);
//		if(a[i].x>n||a[i].y>n) { ans++; continue; }
//		if(a[i].opt==2&&a[i].x==a[i].y) { ans++; continue; }
//		if(a[i].opt==1) {
//			if(find(a[i].x)==find(a[i].y+n)||find(a[i].y)==find(a[i].x+n)) ans++;
//			else fa[find(a[i].x)]=find(a[i].y),fa[find(a[i].x+n)]=find(a[i].y+n),fa[find(a[i].x+n+n)]=find(a[i].y+n+n);
//		}
//		if(a[i].opt==2) {
//			if(find(a[i].x)==find(a[i].y)||find(a[i].x+n)==find(a[i].y)) ans++;
//			else fa[find(a[i].x)]=find(a[i].y+n),fa[find(a[i].x+n)]=find(a[i].y+n+n),fa[find(a[i].x+n+n)]=find(a[i].y);
//		}
//	}
//	printf("%d",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2430	严酷的训练
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 10005
//using namespace std;
//int a1,a2,n,m,lim;
//int t[maxn],p[maxn],q[maxn];
//int dp[maxn];
//signed main(){
//	scanf("%lld %lld %lld %lld",&a1,&a2,&m,&n);
//	for(int i=1;i<=n;i++) {
//		int tt;
//		scanf("%lld",&tt);
//		t[i]=tt*(a2/a1);
//	} 
//	for(int i=1;i<=m;i++) scanf("%lld %lld",&p[i],&q[i]);
//	scanf("%lld",&lim);
//	for(int i=1;i<=m;i++) for(int j=lim;j>=t[p[i]];j--) dp[j]=max(dp[j],dp[j-t[p[i]]]+q[i]);
//    printf("%lld",dp[lim]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2722 [USACO3.1] 总分 Score Inflation
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 10005
//using namespace std;
//int n,m;
//int p[maxn],t[maxn],dp[maxn];
//signed main(){
//	scanf("%lld %lld",&m,&n);
//	for(int i=1;i<=n;i++) scanf("%lld %lld",&p[i],&t[i]);
//	for(int i=1;i<=n;i++) {
//		for(int j=t[i];j<=m;j++) {
//			dp[j]=max(dp[j],dp[j-t[i]]+p[i]);
//		}
//	}
//	printf("%lld",dp[m]);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//SP1043	GSS1 - Can you answer these queries I
//#include <bits/stdc++.h>
//#define up(i,a,b) for(int i=a;i<=b;i++)
//#define down(i,a,b) for(int i=a;i>=b;i--)
//#define mem(a,v) memset(a,v,sizeof(a))
//#define Mid(l,r) (l+r)>>1
//#define int long long
//using namespace std;
//const int INF = 0x7f7f7f7f;
//const int MAXN = 1e5+7;
//const int MOD = 1e9+7;
//inline int read() {
//	int x=0, f=1;
//	char ch=getchar();
//	while(ch<'0'||ch>'9') {
//		if(ch=='-')f=-1;
//		ch=getchar();
//	}
//	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
//	return x*f;
//}
//struct node {
//	int l,r;
//	int sum,lsum,rsum;
//	int res;
//} tr[MAXN<<2];
//int a[MAXN];
//node pushup(node L,node R) {
//	node Nd;
//	Nd.l=L.l,Nd.r=R.r;
//	Nd.sum=L.sum+R.sum;
//	Nd.lsum=max(L.lsum,L.sum+R.lsum);
//	Nd.rsum=max(R.rsum,R.sum+L.rsum);
//	Nd.res=max(max(L.res,R.res),L.rsum+R.lsum);
//	return Nd;
//}
//void build(int x,int l,int r) {
//	tr[x].l=l;
//	tr[x].r=r;
//	if(l==r) {
//		tr[x].sum=a[l];
//		tr[x].lsum=a[l];
//		tr[x].rsum=a[l];
//		tr[x].res=a[l];
//		return ;
//	}
//	int mid=Mid(l,r);
//	build(x<<1,l,mid);
//	build(x<<1|1,mid+1,r);
//	tr[x]=pushup(tr[x<<1],tr[x<<1|1]);
//}
//void query(int x,int l,int r,node& ans) {
//	if(tr[x].l>=l&&tr[x].r<=r) {
//		if(ans.l!=0)ans=pushup(ans,tr[x]);
//		else ans=tr[x];
//		return ;
//	}
//	int mid=Mid(tr[x].l,tr[x].r);
//	if(l<=mid)query(x<<1,l,r,ans);
//	if(r>mid)query(x<<1|1,l,r,ans);
//}
//int n;
//signed main() {
//	n=read();
//	up(i,1,n)a[i]=read();
//	build(1,1,n);
//	int q=read();
//	while(q--) {
//		int l=read();
//		int r=read();
//		node ans= {};
//		query(1,l,r,ans);
//		printf("%lld\n",ans.res);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P5021 [NOIP2018 提高组] 赛道修建
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 500005
//using namespace std;
//int n,m;
//int l=1,r,val,ans=0;
//struct aa{ int v,w; };
//vector <aa> P[maxn];
//multiset<int> C[maxn];
//multiset<int>::iterator it;
//int dfs(int x,int fa) {
//	int sum1=0,sum2=0;
//	for(int i=0;i<P[x].size();i++) {
//		aa now=P[x][i];
//		if(now.v==fa) continue;
//		sum2=max(sum2,dfs(now.v,x)+now.w);
//		if(sum1<sum2) swap(sum1,sum2);
//	}
//	r=max(r,sum1+sum2);
//	return sum1;
//}
//int dfs1(int x,int fa,int k) {
//	C[x].clear();
//	for(int i=0;i<P[x].size();i++) {
//		aa now=P[x][i];
//		if(now.v==fa) continue;
//		val=dfs1(now.v,x,k)+now.w;
//		if(val>=k) ans++;
//		else C[x].insert(val);
//	}
//	int maxx=0;
//	while(!C[x].empty()) {
//		if(C[x].size()==1) return max(maxx,*C[x].begin());
//		it=C[x].lower_bound(k-*C[x].begin());
//		if(it==C[x].begin()&&C[x].count(*it)==1) it++;
//		if(it==C[x].end()) {
//			maxx=max(maxx,*C[x].begin());
//			C[x].erase(C[x].find(*C[x].begin()));
//		} else {
//			ans++;
//			C[x].erase(C[x].find(*it));
//			C[x].erase(C[x].find(*C[x].begin()));
//		}
//	}
//	return maxx;
//}
//bool check(int x) {
//	ans=0;
//	dfs1(1,0,x);
//	if(ans>=m) return true;
//	else return false;
//}
//signed main(){
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<n;i++) {
//		int x,y,w;
//		scanf("%lld %lld %lld",&x,&y,&w);
//		P[x].push_back({y,w});
//		P[y].push_back({x,w});
//	}
//	dfs(1,0);
//	while(l<r) {
//		int mid=(l+r+1)>>1;
//		if(check(mid)) l=mid;
//		else r=mid-1;
//	}
//	printf("%lld",l);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//AT_abc305_f [ABC305F] Dungeon Explore
//#include<bits/stdc++.h>
//#define maxn 100005
//using namespace std;
//int n,m,k,last;
//int fa[maxn];
//bool vis[maxn];
//vector <int> P[maxn];
//signed main(){
//	cin>>n>>m>>k;
//	for(int i=1;i<=k;i++) {
//		int x;
//		cin>>x;
//		P[1].push_back(x);
//	}
//	for(int i=0;i<P[1].size();i++) {
//		int now=P[1][i];
//		if(!vis[now]) {
//			vis[now]=true;
//			last=now;
//			fa[last]=1;
//			cout<<now<<endl;
//			break;
//		}
//	}
//	while(1) {
//		cin>>k;
//		for(int i=1;i<=k;i++) {
//			int x;
//			cin>>x;
//			P[last].push_back(x);
//			if(x==n) {
//				cout<<n;
//				return 0;
//			}
//		}
//		bool flag=false;
//		for(int i=0;i<P[last].size();i++) {
//			int now=P[last][i];
//			if(!vis[now]) {
//				vis[now]=true;
//				fa[now]=last;
//				last=now;
//				flag=true;
//				cout<<last<<endl;
//				break;
//			}
// 		}	
// 		if(!flag) {
//			cout<<fa[last]<<endl;
//			last=fa[last];
//		}
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3386	【模板】二分图最大匹配
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1005
//using namespace std;
//int n,m,t,ans=0;
//int mch[maxn],vistime[maxn];
//vector<int> e[maxn];
//bool dfs(int u,int tag) {
//	if (vistime[u] == tag) return false;
//	vistime[u] = tag;
//	for (auto v:e[u]) if ((mch[v]==0) || dfs(mch[v],tag)) { mch[v]=u; return true; }
//	return false;
//}
//signed main() {
//	scanf("%lld %lld %lld", &n, &m, &t);
//	for(int i=1;i<=t;i++) {
//		int u,v;
//		scanf("%lld %lld", &u, &v);
//		e[u].push_back(v);
//	}
//	for (int i = 1; i <= n; ++i) if (dfs(i, i)) ++ans;
//	printf("%lld\n", ans);
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF243A The Brand New Function
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//set<int> P;
//int n;
//int a[maxn];
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<=n;i++) {
//		int now=a[i],p=0;
//		P.insert(now);
//		for(int j=i+1;j<=n;j++) {
//			now|=a[j],p|=a[j];
//			if(now==p) break;
//			P.insert(now);
//		}
//	}
//	printf("%lld",P.size());
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1525 [NOIP2010 提高组] 关押罪犯
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,m;
//struct aa {
//	int a,b,c;
//	bool operator < (const aa& x) const {
//		return x.c>c;
//	}
//};
//priority_queue <aa> C;
//int fa[maxn];
//int find(int x) {
//	if(x==fa[x]) return x;
//	else return fa[x]=find(fa[x]);
//}
//signed main() {
//	scanf("%lld %lld",&n,&m);
//	for(int i=1; i<=n*2; i++) fa[i]=i;
//	for(int i=1; i<=m; i++) {
//		int a,b,c;
//		scanf("%lld %lld %lld",&a,&b,&c);
//		C.push({a,b,c});
//	}
//	while(!C.empty()) {
//		aa now=C.top();
//		if(find(now.a)==find(now.b)) {
//			printf("%lld",now.c);
//			return 0;
//		}
//		fa[find(now.a)]=fa[find(now.b+n)];
//		fa[find(now.b)]=fa[find(now.a+n)];
//		C.pop();
//	}
//	cout<<0;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF815C Karen and Supermarket
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 5005
//using namespace std;
//int n,b;
//struct aa{
//	int c,d;
//	int x;
//}a[maxn];
//int dp[maxn][maxn][2],siz[maxn];
//vector <int> P[maxn]; 
//void dfs(int x,int fa) {
//	siz[x]=1;
//	dp[x][0][1]=dp[x][0][0]=0;
//	dp[x][1][0]=a[x].c;
//	for(int p=0;p<P[x].size();p++) {
//		int now=P[x][p];
//		if(now==fa) continue;
//		dfs(now,x);
//		for(int i=siz[x];i>=0;i--) {
//			for(int j=siz[now];j>=0;j--) {
//				dp[x][i+j][0]=min(dp[x][i+j][0],dp[x][i][0]+dp[now][j][0]);
//				dp[x][i+j][1]=min(dp[x][i+j][1],min(dp[x][i][1]+dp[now][j][0],dp[x][i][1]+dp[now][j][1]));
//			}
//		}
//		siz[x]+=siz[now];
//	}
//	for(int i=siz[x];i>=1;i--) dp[x][i][1]=dp[x][i-1][1]+a[x].c-a[x].d;
//}
//signed main(){
//	memset(dp,0x7f,sizeof(dp));
//	scanf("%lld %lld",&n,&b);
//	for(int i=1;i<=n;i++) {
//		scanf("%lld %lld",&a[i].c,&a[i].d);
//		if(i>=2) scanf("%lld",&a[i].x);
//		P[a[i].x].push_back(i);
//	}
//	dfs(1,0);
//	for(int i=1;i<=n+1;i++) if(min(dp[1][i][1],dp[1][i][0])>b) { cout<<i-1; return 0; }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF776D The Door Problem
//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,m;
//int a[maxn],fa[maxn*2];
//vector <int> P[maxn];
//int find(int x) {
//	if(x==fa[x]) return x;
//	else return fa[x]=find(fa[x]);
//}
//signed main(){
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<=m;i++) {
//		int q,l; scanf("%lld",&q);
//		for(int j=1;j<=q;j++) {
//			scanf("%lld",&l);
//			P[l].push_back(i);
//		}
//	}
//	for(int i=1;i<=2*m;i++) fa[i]=i;
//	for(int i=1;i<=n;i++) {
//		if(a[i]==1) {
//			fa[find(P[i][0])]=find(P[i][1]);
//			fa[find(P[i][1]+m)]=find(P[i][0]+m);
//		} else {
//			fa[find(P[i][0]+m)]=find(P[i][1]);
//			fa[find(P[i][1]+m)]=find(P[i][0]);
//		}
//	}
//	for(int i=1;i<=m;i++) if(find(i+m)==find(i)) { cout<<"NO"; return 0; }
//	cout<<"YES";
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3455 [POI2007] ZAP-Queries
//#include<bits/stdc++.h>
//#define int long long
//#define maxn (int)(5e4+10)
//using namespace std;
//int n,cnt=0;
//int prm[maxn],prs[maxn],miu[maxn],mis[maxn],vis[maxn];
//void init(){
//	mis[1]=miu[1]=1;
//	for(int i=2;i<maxn;i++){
//		if(!prm[i]) prs[++cnt]=i,miu[i]=-1; 
//		for(int j=1;j<=cnt;j++){
//			if(i*prs[j]>maxn-1) break;
//			prm[i*prs[j]]=1;
//			if(i%prs[j]==0){
//				miu[i*prs[j]]=0;
//				break;
//			}else miu[i*prs[j]]=-1*miu[i];
//		}
//		mis[i]=mis[i-1]+miu[i];
//	}
//}
//signed main(){
//	freopen("P3455_1.in","r",stdin);
//	freopen("t.txt","w",stdout);
//	scanf("%lld",&n);
//	init();
//	while(n--){
//		int a,b,d,aa,bb,res=0,l=1,r;
//		scanf("%lld %lld %lld",&a,&b,&d);
//		aa=a/d,bb=b/d;		
//		if(aa<bb) swap(aa,bb);
//		while(l<=bb){
//			r=min(aa/(aa/l),bb/(bb/l));
//			res+=(mis[r]-mis[l-1])*(aa/l)*(bb/l);
//			l=r+1;
//		}
//		printf("%lld\n",res);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//2024.2.16 B - T2
//#include<bits/stdc++.h>
//#define maxn 1000005
//using namespace std;
//int dp[maxn], a[maxn], na[maxn];
//signed main(){
//	while(1) {
//		int n,m,ans=0,cnt=0;
//		scanf("%d %d",&n,&m);
//		if(n==0&&m==0) return 0;		
//		for(int i=1;i<=m;i++) dp[i]=0;
//		dp[0]=1;
//		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//		for(int i=1;i<=n;i++) {
//			int x,k=1;
//			scanf("%d",&x);
//			while(x>=k) {
//				na[++cnt] = a[i]*k;
//				x-=k,k*=2;
//			}
//			if(x>0) na[++cnt] = a[i]*x; 
//		}
//		for(int i=1;i<=cnt;i++) for(int j=m;j>=na[i];j--) dp[j]=max(dp[j],dp[j-na[i]]);
//		for(int i=1;i<=m;i++) if(dp[i]>0) ans++;
//		printf("%d\n",ans);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF601B Lipshitz Sequence
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000005
//using namespace std;
//int n,q,l,r;
//int pre[maxn],las[maxn];
//int h[maxn],a[maxn];
//int stk[maxn];
//signed main(){
//	scanf("%lld %lld",&n,&q);
//	for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
//	for(int i=1;i< n;i++) a[i]=abs(h[i]-h[i+1]);
//	while(q--) {
//		scanf("%lld %lld",&l,&r);r--;
//		memset(pre,0,sizeof(pre)),memset(las,0,sizeof(las));
//		int top=0,ans=0,len=r-l+1;
//		for(int i=l,j=1;i<=r;j++,i++) a[j]=abs(h[i]-h[i+1]);
//		for(int i=1;i<=len;i++) {
//			while(top&&a[stk[top]]<a[i]) las[stk[top]]=i-stk[top],top--;
//			pre[i]=i-stk[top],stk[++top]=i;
//		}
//		while(top) las[stk[top]]=len+1-stk[top],top--;
//		for(int i=1;i<=len;i++) ans+=a[i]*pre[i]*las[i];
//		printf("%lld\n",ans); 
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1390 公约数的和
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 2000010
//using namespace std;
//int n,cnt=0,l,r,res,maxx,ans;
//int prm[maxn],prs[maxn],miu[maxn],mis[maxn],vis[maxn];
//void init() {
//	mis[1]=miu[1]=1;
//	for(int i=2; i<=n; i++) {
//		if(!prm[i]) prs[++cnt]=i,miu[i]=-1;
//		for(int j=1; j<=cnt; j++) {
//			if(i*prs[j]>n) break;
//			prm[i*prs[j]]=1;
//			if(i%prs[j]==0) {
//				miu[i*prs[j]]=0;
//				break;
//			} else miu[i*prs[j]]=-1*miu[i];
//		}
//		mis[i]=mis[i-1]+miu[i];
//	}
//}
//signed main() {
//	scanf("%lld",&n);init();
//	for(int i=1; i<=n; i++) {
//		res=0,l=1,maxx=n/i;
//		while(l<=maxx) {
//			r=maxx/(maxx/l);
//			res+=(mis[r]-mis[l-1])*(maxx/l)*(maxx/l);
//			l=r+1;
//		}
//		ans+=res*i;
//	}
//	cout<<((ans-((n+1)*n>>1))>>1);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T426129 射箭
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//signed main(){
//	int x,y,z,cnt=0;
//	scanf("%lld %lld %lld",&x,&y,&z);
//	if(x+y<z) cnt++;
//	if(x+z<y) cnt++;
//	if(y+z<x) cnt++;
//	cout<<cnt;
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T426130 酒
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//double a,b,c,d,e,x,y;
//signed main(){
//	cin>>a>>b>>c>>d>>e>>x>>y;
//	double ans1=a*x+b*y;
//	double ans2=c*y;
//	double ans3=d*y+e;
//	if(ans1>=max(ans2,ans3)) printf("1 %.2lf",ans1);
//	if(ans2>max(ans1,ans3)) printf("2 %.2lf",ans2);
//	if(ans3>max(ans2,ans1)) printf("3 %.2lf",ans3);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T426131 分配工资
//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, m, v=0, w=0;
//	scanf("%d%d", &n, &m);
//	while (n--) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		if (a & 1) v += b;
//		w += b;
//	}
//	printf("%.3f\n", (double)m * v / w);
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T426132 三位数
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int k;
//bool flag=false;
//signed main(){
//	scanf("%lld",&k);
//	for(int i=100;i<=999;i++) {
//		int bw=i/100,sw=i%100/10,gw=i%10;
//		if((bw*10+sw)%k==0&&(sw*10+gw)%k==0&&i%k==0) flag=true,cout<<i<<endl;   
//	}
//	if(!flag) cout<<"None!";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T426134 小朋友的身高
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1005
//using namespace std;
//int n,m,q;
//int a[maxn];
//int b[maxn][maxn];
//signed main(){
//	scanf("%lld %lld %lld",&n,&m,&q);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%lld",&b[i][j]);
//	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) b[i][j]+=b[i-1][j]; 
//	while(q--) {
//		int x,y,z;
//		scanf("%lld %lld %lld",&x,&y,&z);
//		cout<<(a[y]+b[x][y]-a[z]-b[x][z])<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T426136 翻转和反转
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,q,cnt1=0,cnt2=0;
//string s1,s2;
//signed main(){
//	cin>>n>>q>>s1>>s2;
//	for(int i=0;i<s2.size();i++) if(s2[i]=='1') cnt1^=1; else cnt2^=1; 
//	if(cnt1) reverse(s1.begin(),s1.end());
//	if(cnt2) for(int i=0;i<s1.size();i++) {
//		if(s1[i]=='1') s1[i]='0';
//		else s1[i]='1';
//	}
//	cout<<s1;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T426139 陨石
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 5001
//using namespace std;
//int b,a[maxn];
//signed main() {
//	scanf("%lld",&b);
//	while (b--) {
//		int n,t,m,w=0;
//		scanf("%lld%lld%lld", &n, &t, &m);
//		for (int i=1; i<=n; i++) scanf("%lld", &a[i]);
//		while (m--) {
//			int i,j;
//			scanf("%lld",&i);
//			a[i]-=2;
//		}
//		priority_queue<int> q;
//		for (int i(1); i<=n; i++) if (a[i]<1) q.emplace(a[i]); else ++w;
//		while (!q.empty()) {
//			const int p(q.top());
//			q.pop();
//			t-=1-p;
//			if (t<0) break;
//			else ++w;
//		}
//		printf("%lld\n",w);
//	}
//	return 0;
//} 
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1429 平面最近点对（加强版）
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int n;
//double ans=(double)(2e9+7);
//struct aa{ int x,y; }a[maxn];
//bool cmp(aa xx,aa y) {
//	return xx.x<y.x;
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i].x,&a[i].y);
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++) {
//		for(int j=i+1;j<=n;j++) {
//			double dx=abs(a[i].x-a[j].x),dy=abs(a[i].y-a[j].y);
//			if(ans<dx) break;
//			ans=min(ans,sqrt(dx*dx+dy*dy));
//		}
//	}
//	printf("%.4lf",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF11A Increasing Sequence
//#include<bits/stdc++.h>
//using namespace std;
//signed main() {
//	int n,s,ans=0,a[10001];
//	cin>>n>>s;
//	for(register int i=1; i<=n; i++) cin>>a[i];
//	for(register int i=1; i<=n-1; i++) {
//		if(a[i]>=a[i+1]) {
//			ans+=(a[i]-a[i+1])/s+1;
//			a[i+1]+=((a[i]-a[i+1])/s+1)*s;
//		}
//	}
//	cout<<ans<<endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P7883 平面最近点对（加强加强版）
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 400005
//using namespace std;
//int n;
//struct aa{ int x,y; }a[maxn],tp[maxn];
//bool cmp1(aa x,aa y) { return x.x<y.x; }
//bool cmp2(aa x,aa y) { return x.y<y.y; }
//int  p(int x) { return x*x; }
//int  calc(aa x,aa y) { return p(x.x-y.x)+p(x.y-y.y); }
//int solve(int l,int r) {
//	if(l>=r) return 1e18+4;
//	if(r-l==1) return calc(a[l],a[r]);
//	int mid=(l+r)>>1,cnt=0;
//	int ans=min(solve(l,mid),solve(mid,r));
//	for(int i=l;i<=r;i++) if(p(a[i].x-a[mid].x)<ans) tp[++cnt]=a[i];
//	sort(tp+1,tp+cnt+1,cmp2);
//	for(int i=1;i<=cnt;i++) for(int j=i+1;j<=cnt&&p(tp[i].y-tp[j].y)<ans;j++) ans=min(ans,calc(tp[i],tp[j]));
//	return ans;
//}
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i].x,&a[i].y);
//	sort(a+1,a+n+1,cmp1);
//	printf("%lld",solve(1,n));
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P3810 【模板】三维偏序（陌上花开）
//#include <bits/stdc++.h>
//#define maxn 100005
//#define lc rt<<1
//#define rc rt<<1|1
//using namespace std;
//int n,k,tot,m,sum[maxn<<5],f[maxn];
//struct aa { int x,y,z,cnt,ans; } a[maxn],w[maxn];
//bool cmp1(aa x,aa y) {
//	if(x.x!=y.x) return x.x<y.x;
//	if(x.y!=y.y) return x.y<y.y;
//	return x.z<y.z;
//}
//bool cmp2(aa x,aa y) {
//	if(x.y!=y.y) return x.y<y.y;
//	return x.z<y.z;
//}
//void push_up(int rt) { sum[rt]=sum[lc]+sum[rc]; }
//void update(int l,int r,int rt,int pos,int x) {
//	if(l==r) return (void)(sum[rt]+=x);
//	int mid=(l+r)>>1;
//	if(pos<=mid) update(l,mid,lc,pos,x);
//	else update(mid+1,r,rc,pos,x);
//	push_up(rt);
//}
//int get_num(int l,int r,int rt,int s,int t,int ans=0){
//	if(s>t) return 0;
//	if(s<=l&&r<=t) return sum[rt];
//	int mid=(l+r)>>1;
//	if(s<=mid) ans+=get_num(l,mid,lc,s,t);
//	if(t>mid) ans+=get_num(mid+1,r,rc,s,t);
//	return ans;
//}
//void solve(int l,int r) {
//	if(l==r) return ;
//	int mid=(l+r)>>1;
//	solve(l,mid),solve(mid+1,r);
//	sort(w+l,w+mid+1,cmp2),sort(w+mid+1,w+r+1,cmp2);
//	int i=l,j=mid+1;
//	while(j<=r) {
//		while(i<=mid&&w[i].y<=w[j].y) update(1,k,1,w[i].z,w[i].cnt),i++;
//		w[j++].ans+=get_num(1,k,1,1,w[j].z);
//	}
//	for(int t=l;t<i;t++) update(1,k,1,w[t].z,-w[t].cnt);
//}
//signed main(){
//	scanf("%d %d",&n,&k);
//	for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
//	sort(a+1,a+n+1,cmp1);
//	for(int i=1; i<=n; i++) {
//		tot++;
//		if(i==n||a[i].x!=a[i+1].x||a[i].y!=a[i+1].y||a[i].z!=a[i+1].z)  w[++m]=a[i],w[m].cnt=tot,tot=0;
//	}
//	solve(1,m);
//	for(int i=1;i<=m;i++) f[w[i].ans+w[i].cnt-1]+=w[i].cnt;
//	for(int i=0;i<n;i++) printf("%d\n",f[i]);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P4148 简单题
//#include<bits/stdc++.h>
//#define maxn 200005
//#define lc t[p].c[0]
//#define rc t[p].c[1]
//#define __ int x1, int y1, int x2, int y2
//using namespace std;
//int n,e,g,y,q[maxn];
//struct Point { int a[2],v; }P[maxn];
//struct KDT{ int w,s,c[2],bin[2],bax[2];Point d; }t[maxn];
//bool cmp0(Point i,Point j) { return i.a[0]<j.a[0]; }
//bool cmp1(Point i,Point j) { return i.a[1]<j.a[1]; }
//int newnode() {
//	if (e) return q[e--];
//	return ++y;
//}
//void update(int p) {
//	for(int i=0;i<2;i++) {
//		t[p].bin[i]=t[p].bax[i]=t[p].d.a[i];
//		if(lc) {
//			t[p].bin[i]=min(t[p].bin[i],t[lc].bin[i]);
//			t[p].bax[i]=max(t[p].bax[i],t[lc].bax[i]);
//		}
//		if (rc) {
//			t[p].bin[i]=min(t[p].bin[i],t[rc].bin[i]);
//			t[p].bax[i]=max(t[p].bax[i],t[rc].bax[i]);
//		}
//	}
//	t[p].w=t[lc].w+t[p].d.v+t[rc].w;
//	t[p].s=t[lc].s+t[rc].s+1;
//}
//void slap(int p) {
//	if(!p) return ;
//	P[++g]=t[p].d;
//	q[++e]=p;
//	slap(lc),slap(rc);
//}
//int rebuild(int l,int r,bool k) {
//	if(l>r) return 0;
//	int mid=(l+r)>>1,p=newnode();
//    nth_element(P+l,P+mid,P+r+1,k?cmp1:cmp0);
//	t[p].d=P[mid];
//	lc=rebuild(l,mid-1,!k),rc=rebuild(mid+1,r,!k);
//	update(p);
//	return p;
//}
//void check(int &p,bool k) {
//	if (t[lc].s>2*t[rc].s||t[rc].s>2*t[lc].s) {
//		g=0;
//		slap(p);
//		p=rebuild(1,t[p].s,k);
//	}
//}
//void insert(int &p, Point x,bool k) {
//	if(!p) {
//		p=newnode();
//		lc=rc=0;
//		t[p].d=x;
//        update(p);
//		return ;
//	}
//	if(x.a[k]<=t[p].d.a[k]) insert(lc,x,!k);
//	else insert(rc,x,!k);
//	update(p);
//	check(p,k);
//} 
//bool checkin (__,int X1,int Y1,int X2,int Y2) { return x1<=X1&&x2>=X2&&y1<=Y1&&y2>=Y2; }
//bool checkout(__,int X1,int Y1,int X2,int Y2) { return x1>X2||x2<X1||y1>Y2||y2<Y1; }
//int query(int p, __) {
//	if (!p) return 0;
//	int x=0;
//	if (checkin (x1,y1,x2,y2,t[p].bin[0],t[p].bin[1],t[p].bax[0],t[p].bax[1])) return t[p].w;
//	if (checkout(x1,y1,x2,y2,t[p].bin[0],t[p].bin[1],t[p].bax[0],t[p].bax[1])) return 0;
//	if (checkin (x1,y1,x2,y2,t[p].d.a[0],t[p].d.a[1],t[p].d.a[0],t[p].d.a[1])) x=t[p].d.v;
//	return x+query(lc,x1,y1,x2,y2)+query(rc,x1,y1,x2,y2);
//}
//signed main(){
//	scanf("%d",&n);
//	int rt=0,las=0;
//	while(1) {
//		int opt;
//		scanf("%d",&opt); 
//		if(opt==1) {
//			Point i;
//			scanf("%d %d %d",&i.a[0],&i.a[1],&i.v);
//			i.a[0]^=las,i.a[1]^=las,i.v^=las;
//			insert(rt,i,0);
//		}
//		if(opt==2) {
//			int x1,y1,x2,y2;
//			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
//			x1^=las,y1^=las,x2^=las,y2^=las;
//			printf("%d\n",las=query(rt,x1,y1,x2,y2));
//		}
//		if(opt==3) break;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF896C Willem, Chtholly and Seniorious
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,m,sed,vm,a[maxn],mod=1000000007;
//struct Mag {
//	int op,l,r,x,y;
//} mag[maxn];
//struct Node {
//	int l,r;
//	mutable int v;
//	Node(int l=0,int r=0,int v=0):l(l),r(r),v(v) {}
//	bool operator < (const Node &rhs) const {
//		return l<rhs.l;
//	}
//} node;
//struct RankList {
//	int l,r,v;
//	RankList(int l=0,int r=0,int v=0):l(l),r(r),v(v){}
//	bool operator < (const RankList &rhs) const {
//		return v<rhs.v;
//	}
//} rkl;
//set<Node> s;
//inline int quick_pow(int a,int b) {
//	int res=1;
//	while(b) {
//		if(b&1) res=res*a%mod;
//		a=a*a%mod;
//		b>>=1;
//	}
//	return res;
//}
//namespace data_produce {
//	inline int rnd() {
//		int ret=sed;
//		sed=(sed*7+13)%1000000007;
//		return ret;
//	}
//	inline void data() {
//		for(int i=1; i<=n; i++) a[i]=(rnd()%vm)+1;
//		for(int i=1; i<=m; i++) {
//			mag[i].op=(rnd()%4)+1;
//			mag[i].l=(rnd()%n)+1;
//			mag[i].r=(rnd()%n)+1;
//			if(mag[i].l>mag[i].r) swap(mag[i].l,mag[i].r);
//			if(mag[i].op==3) mag[i].x=(rnd()%(mag[i].r-mag[i].l+1))+1;
//			else mag[i].x=(rnd()%vm)+1;
//			if(mag[i].op==4) mag[i].y=(rnd()%vm)+1;
//		}
//		return;
//	}
//}
//using namespace data_produce;
//namespace CT {
//	inline set<Node>::iterator split(int x) {
//		set<Node>::iterator it=s.lower_bound(Node(x));
//		if(it!=s.end()&&it->l==x) return it;
//		it--;
//		if(it->r<x) return s.end();
//		node.l=it->l,node.r=it->r,node.v=it->v;
//		s.erase(it);
//		s.insert(Node {node.l,x-1,node.v});
//		it=s.insert(Node {x,node.r,node.v}).first;
//		return it;
//	}
//	inline void assign(int l,int r,int v) {
//		set<Node>::iterator to=split(r+1),it=split(l);
//		s.erase(it,to);
//		s.insert(Node {l,r,v});
//		return;
//	}
//	inline void add(int l,int r,int v) {
//		set<Node>::iterator to=split(r+1),it=split(l);
//		for(; it!=to; it++) it->v+=v;
//		return;
//	}
//	inline int rank_search(int l,int r,int x) {
//		set<Node>::iterator to=split(r+1),it=split(l);
//		vector<RankList>v;
//		v.clear();
//		for(; it!=to; it++) v.push_back(RankList {it->l,it->r,it->v});
//		sort(v.begin(),v.end());
//		for(int i=0; i<(int)v.size(); i++) {
//			if(v[i].r-v[i].l+1<x) x-=v[i].r-v[i].l+1;
//			else return v[i].v;
//		}
//		return 0;
//	}
//	inline int query(int l,int r,int x,int y) {
//		int res=0;
//		mod=y;
//		set<Node>::iterator to=split(r+1),it=split(l);
//		for(; it!=to; it++) res=(res+(quick_pow(it->v%mod,x)%mod*(it->r-it->l+1)%mod)%mod)%mod;
//		return res%mod;
//	}
//}
//using namespace CT;
//signed main() {
//	scanf("%lld %lld %lld %lld",&n,&m,&sed,&vm);
//	data();
//	for(int i=1; i<=n; i++) s.insert(Node{i,i,a[i]});
//	for(int i=1; i<=m; i++) {
//		if(mag[i].op==1) add(mag[i].l,mag[i].r,mag[i].x);
//		else if(mag[i].op==2) assign(mag[i].l,mag[i].r,mag[i].x);
//		else if(mag[i].op==3) printf("%lld\n",rank_search(mag[i].l,mag[i].r,mag[i].x));
//		else printf("%lld\n",query(mag[i].l,mag[i].r,mag[i].x,mag[i].y));
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF915E Physical Education Lessons
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,q,ans;
//struct Node {
//	int l,r;
//	mutable int v;
//	Node(int l=0,int r=0,int v=0):l(l),r(r),v(v) {}
//	bool operator < (const Node &rhs) const { return l<rhs.l; }
//} node;
//set<Node>s;
//inline auto split(int x) {
//	auto it=s.lower_bound(Node(x));
//	if(it!=s.end()&&it->l==x) return it; it--;
//	if(it->r<x) return s.end();
//	node.l=it->l,node.r=it->r,node.v=it->v;
//	s.erase(it);
//	s.insert(Node {node.l,x-1,node.v});
//	it=s.insert(Node {x,node.r,node.v}).first;
//	return it;
//}
//inline void assign(int l,int r,int v) {
//	auto to=split(r+1),fm=split(l);
//	for(auto it=fm; it!=to; it++) ans-=(it->r-it->l+1)*(it->v);
//	s.erase(fm,to);
//	s.insert(Node {l,r,v});
//	ans+=(r-l+1)*v;
//	return;
//}
//signed main() {
//	scanf("%lld %lld",&n,&q);
//	ans=n;
//	s.insert(Node{1,n,1});
//	while(q--) {
//		int opt,l,r;
//		scanf("%lld %lld %lld",&l,&r,&opt);
//		assign(l,r,opt-1);
//		printf("%lld\n",ans);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P4979 矿洞：坍塌
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 500005
//using namespace std;
//int n,k;
//string a;
//struct Node {
//	int l,r;
//	mutable int x;
//	Node(int l=0,int r=0,int x=0) : l(l),r(r),x(x) {}
//	bool operator < (const Node &p) const { return l<p.l; }
//} node;
//set<Node>s;
//auto split(int x) {
//	auto it=s.lower_bound(Node(x));
//	if(it!=s.end()&&it->l==x) return it; it--;
//	if(it->r<x) return s.end();
//	node.l=it->l,node.r=it->r,node.x=it->x;
//	s.erase(it),s.insert(Node{node.l,x-1,node.x});
//	it=s.insert(Node {x,node.r,node.x}).first;
//	return it;
//}
//void assign(int l,int r,int x) {
//	auto to=split(r+1),it=split(l);
//	s.erase(it,to),s.insert(Node {l,r,x});
//	return ;
//}
//inline bool query(int l,int r) {
//	auto to=split(r+1),fm=split(l);
//	bool res=0;
//	for(auto it=fm; it!=to; it++) {
//		if(it->x!=fm->x) {
//			it--;
//			assign(fm->l,it->r,fm->x);
//			return 0;
//		}
//	}
//	if(fm==s.begin()||to==s.end()) res=1;
//	else {
//		auto pre=fm;
//		pre--;
//		if(pre->x==to->x) res=0;
//		else res=1;
//	}
//	assign(l,r,fm->x);
//	return res;
//}
//signed main() {
//	scanf("%lld",&n);
//	cin>>a;
//	node.l=node.r=1,node.x=a[0]-'A';
//	for(int i=1;i<n;i++) {
//		if(a[i]-'A'!=node.x) {
//			node.r=i,s.insert(node);
//			node.l=i+1,node.x=a[i]-'A';
//		}
//	}
//	node.r=n,s.insert(node);
//	scanf("%lld",&k);
//	while(k--) {
//		char opt,op;
//		int x,y;
//		cin>>opt;
//		if(opt=='B') {
//			scanf("%lld %lld",&x,&y);
//			if(query(x,y)) printf("Yes\n");
//			else printf("No\n");
//		}
//		if(opt=='A') {
//			scanf("%lld %lld %c",&x,&y,&op);
//			assign(x,y,op-'A');
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//AT_abc255_h [ABC255Ex] Range Harvest Query
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 300005
//#define mod 998244353
//using namespace std;
//int m,n,q;
//int a[maxn];
//struct Node{
//	int l,r; mutable int v;
//	Node(int l=0,int r=0,int v=0) : l(l),r(r),v(v) {};
//	bool operator < (const Node &x) const{ return l<x.l; }
//}node; set<Node>s;
//auto split(int x) {
//	auto it=s.lower_bound(Node(x));
//	if(it!=s.end()&&it->l==x) return it; it--;
//	if(it->r<x) return s.end();
//	node.l=it->l,node.r=it->r,node.v=it->v;
//	s.erase(it);s.insert(Node{node.l,x-1,node.v});
//	it=s.insert(Node{x,node.r,node.v}).first;
//	return it;
//}
//int assign(int l,int r,int d) {
//	auto to=split(r+1),fm=split(l);
//	int ans=0;
//	for(auto it=fm;it!=to;it++) {
//		ans+=(d-it->v)%mod*((it->l+it->r)%mod)%mod*((it->r-it->l+1)%mod)%mod*499122177%mod;
//		ans%=mod;
//	}
//	s.erase(fm,to),s.insert(Node{l,r,d});
//	return ans;
//}
//signed main(){
//	scanf("%lld %lld",&n,&q);
//	s.insert(Node{1,n,0});
//	while(q--) {
//		int l,r,d;
//		scanf("%lld %lld %lld",&d,&l,&r);
//		printf("%lld\n",assign(l,r,d));
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF75C Modified GCD
//#include<bits/stdc++.h>
////#define int long long
//using namespace std;
//int a,b,T,l,r,maxx=-1;
//signed main(){
//	scanf("%d %d",&a,&b);
//	int gcd=__gcd(a,b);
//	cin>>T;
//	while(T--){
//		maxx=-1;
//		scanf("%d %d",&l,&r);
//		for(int i=1;i*i<=gcd;i++){
//			if(gcd%i==0){
//				if(i>=l&&i<=r) maxx=max(maxx,i);
//				if(gcd/i>=l&&gcd/i<=r) maxx=max(maxx,gcd/i);
//			}
//		}
//		printf("%d\n",maxx);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//CF1928C Physical Education Lesson
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int t,n,x;
//set<int> s;
//signed main() {
//	scanf("%lld",&t);
//	while(t--) {
//		s.clear();
//		scanf("%lld %lld",&n,&x);
//		int g1=n-x,g2=n+x-2;
//		for(int i=1; i*i<=g1; i++) {
//			if(g1%i==0) {
//				if(i%2==0&&(i+2)/2>=x) s.insert((i+2)/2);
//				if((g1/i)%2==0&&(g1/i+2)/2>=x) s.insert((g1/i+2)/2);
//			}
//		}
//		for(int i=1; i*i<=g2; i++) {
//			if(g2%i==0) {
//				if(i%2==0&&(i+2)/2>=x) s.insert((i+2)/2);
//				if((g2/i)%2==0&&(g2/i+2)/2>=x) s.insert((g2/i+2)/2);
//			}
//		}
//		printf("%lld\n",s.size());
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//T424949 似巨龙高歌
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 1000005
//using namespace std;
//int n,ans=-1e18;
//int a[maxn];
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	sort(a+1,a+n+1);
//	for(int i=1;i<n;i++) {
//		ans=max(ans,a[i]-a[i+1]);
//	}
//	cout<<ans;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P2114 [NOI2014] 起床困难综合症
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n,m;
//int cnt;
//int t[maxn];
//int ans[40],num[40],opt[maxn];
//int solve(int x) {
//	for(int i=1;i<=n;i++) {
//		if(opt[i]==0) x&=t[i];
//		else if(opt[i]==1) x^=t[i];
//		else x|=t[i];
//	}
//	return x;
//}
//signed main() {
//	scanf("%d %d",&n,&m);
//	for(int i=1;i<=n;i++) {
//		string s;
//		cin>>s>>t[i];
//		if(s=="AND") opt[i]=0;
//		else if(s=="XOR") opt[i]=1;
//		else opt[i]=2;
//	}
//	while(m) {
//		num[++cnt]=m%2;
//		m/=2;
//	}
//	bool top=true;
//	for(int i=cnt; i>=1; i--) {
//		if(top==true) {
//			if(num[i]==1) {
//				int g1=solve(1<<(i-1)),g2=solve(0);
//				g1&=(1<<(i-1)),g2&=(1<<(i-1));
//				if(g1>g2) ans[i]=true;
//				else top=false,ans[i]=false;
//			} else ans[i]=false;
//		} else {
//			int g1=solve(1<<(i-1)),g2=solve(0);
//			g1&=(1<<(i-1)),g2&=(1<<(i-1));
//			if(g1>g2) ans[i]=true;
//			else ans[i]=false;
//		}
//	}
//	int tot=0;
//	for(int i=1;i<=cnt;i++) if(ans[i]) tot+=(1<<(i-1));
//	printf("%lld",solve(tot));
//	return 0; 
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P8453 「SWTR-8」美元巨大
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 25005
//#define maxm 65540
//using namespace std;
//int S,T,n,x,y,beg,cnt=0;
//int a[maxn],b[maxn],tot[maxm];
//bool ans[maxm];
//int txor[maxm],tor[maxm];
//bool cmp(int x,int y) { return x>y; }
//signed main(){
//    scanf("%lld %lld",&S,&T);
//    while(T--) {
//        memset(ans,0,sizeof(ans));
//        memset(tot,0,sizeof(tot));
//        memset(txor,0,sizeof(txor));
//        memset(tor,0,sizeof(tor));
//        cnt=0;
//        scanf("%lld %lld %lld",&n,&x,&y);
//        for(int i=1;i<=n;i++) {
//            scanf("%lld",&a[i]);
//            if(i==1) beg=a[i];
//            tot[a[i]]++;
//            if(tot[a[i]]==1) cnt++,b[cnt]=a[i];
//        }
//        sort(b+1,b+cnt+1,cmp);
//        for(int i=1;i<=cnt;i++) {
//            if(b[i]==beg) {
//                if(tot[b[i]]%2==1) {
//                    if(x>=(tot[b[i]]-1)) x-=(tot[b[i]]-1),txor[b[i]]+=(tot[b[i]]-1);
//                    else {
//                        txor[b[i]]+=x,x=0;
//                        tor[b[i]]=tot[b[i]]-x-1,y-=(tot[b[i]]-x-1);
//                    }
//                    ans[b[i]]=true;
//                } else {
//                    if(y>=1) {
//                        if(x>=(tot[b[i]]-2)) {
//                            x-=(tot[b[i]]-2),txor[b[i]]=(tot[b[i]]-2);
//							y--,tor[b[i]]=1;
//                        } else {
//							txor[b[i]]=x,tor[b[i]]=(tot[b[i]]-x-1);
//							x=0,y-=(tor[b[i]]);
//						}
//                        ans[b[i]]=true;
//                    } else {
//						txor[b[i]]=tot[b[i]]-1;
//						x-=(tot[b[i]]-1);
//					}
//                }
//            } else {
//				if(tot[b[i]]%2==1) {
//					if(x>=tot[b[i]]) {
//						x-=tot[b[i]];
//						txor[b[i]]+=tot[b[i]];
//					} else {
//						txor[b[i]]+=x;
//						x=0;
//						tor[b[i]]=tot[b[i]]-x;
//						y-=(tot[b[i]]-x);
//					}
//					ans[b[i]]=true;
//				} else {
//					if(y>=1) {
//						if(x>=tot[b[i]]-1) {
//							x-=(tot[b[i]]-1);
//							txor[b[i]]=(tot[b[i]]-1);
//							y--;
//							tor[b[i]]=1;
//						} else {
//							txor[b[i]]=x;
//							tor[b[i]]=tot[b[i]]-x;
//							x=0;
//							y-=(tor[b[i]]);
//						}
//						ans[b[i]]=true;
//					} else txor[b[i]]=tot[b[i]],x-=tot[b[i]];
//				}
//			}
//        }
//        bool flag=false;
//		for(int i=65537; i>=0; i--) {
//			if(ans[i]==true) flag=true;
//			if(flag==true) cout<<ans[i];
//		}
//		if(flag==false) cout<<0<<endl;
//		else cout<<endl;
//		for(int i=2; i<=n; i++) {
//			if(txor[a[i]]>=1) cout<<"^",txor[a[i]]--;
//			else cout<<"|",tor[a[i]]--;
//		}
//		cout<<endl;
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P4551 最长异或路径
//#include <bits/stdc++.h>
//#define int long long
//#define maxn 100005
//using namespace std;
//int n;
//int tr[4000005][2],cnt=0,ans=-1;
//struct aa{int v,w;};
//vector<aa> P[maxn];
//void insert(int x) {
//    int u=0;
//    for(int i=30;i>=0;i--) {
//        if(x&(1<<i)) {
//            if(tr[u][1]) u=tr[u][1];
//            else cnt++,tr[u][1]=cnt,u=cnt;
//        } else {
//            if(tr[u][0]) u=tr[u][0];
//            else cnt++,tr[u][0]=cnt,u=cnt;
//        }
//    }
//}
//void dfs(int x,int fa,int sum) {
//    insert(sum);
//    for(int i=0;i<P[x].size();i++) {
//        aa to=P[x][i];
//        if(to.v!=fa) dfs(to.v,x,sum^to.w);
//    }
//}
//void get(int u1,int u2,int sum,int deep) {
//    if(deep==-1) {
//    	ans=max(ans,sum);
//    	return ;
//	}
//    if((tr[u1][0]&&tr[u2][1])||(tr[u1][1]&&tr[u2][0])) {
//        if(tr[u1][0]&&tr[u2][1]) get(tr[u1][0],tr[u2][1],sum|(1<<deep),deep-1);
//        if(tr[u1][1]&&tr[u2][0]) get(tr[u1][1],tr[u2][0],sum|(1<<deep),deep-1);
//    } else {
//		if(tr[u1][0]&&tr[u2][0]) get(tr[u1][0],tr[u2][0],sum,deep-1);
//		if(tr[u1][1]&&tr[u2][1]) get(tr[u1][1],tr[u2][1],sum,deep-1);
//	}
//}
//signed main(){
//    scanf("%d",&n);
//    for(int i=1;i<n;i++) {
//        int u,v,w;
//        scanf("%d %d %d",&u,&v,&w);
//        P[u].push_back({v,w});
//        P[v].push_back({u,w});
//    }
//    dfs(1,0,0);
//    get(0,0,0,30);
//    printf("%d",ans);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1168 中位数
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define maxn 100005
//int n;
//vector <int> P;
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) {
//		int x;
//		scanf("%lld",&x);
//		P.insert(upper_bound(P.begin(),P.end(),x),x);
//		if(i%2==1) printf("%lld\n",P[(i-1)/2]);
//	}
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//P1801 黑匣子
//#include<cstdio>
//#include<queue>
//using namespace std;
//int a[200005];
//int main(){    
//    priority_queue<int>A;
//    priority_queue<int,vector<int>,greater<int>>B;
//    int n,m,r=1,q;scanf("%d%d",&n,&m);
//    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//    for(int i=1;i<=m;i++){
//        scanf("%d",&q);
//        for(int j=r;j<=q;j++){
//            A.push(a[j]);
//            if(A.size()==i)B.push(A.top()),A.pop();
//        }
//        r=q+1;
//        printf("%d\n",B.top());
//        A.push(B.top()),B.pop();
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A-A Multiply
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,a,p,ans=-1e9,anss=1e9,pp,c;
//int sum=0;
//signed main() {
//	scanf("%lld %lld",&n,&c);
//	for(int i=1;i<=n;i++) {
//		scanf("%lld",&a);
//		if(i==1) p=a,pp=a;
//		else p=max(a,a+p),pp=min(pp+a,a);
//		ans=max(ans,p),anss=min(anss,pp);
//		sum+=a;
//	}
//	if(c>0) {
//		if(ans>0) printf("%lld",sum-ans+ans*c);
//		else printf("%lld",sum);
//	} else {
//		if(anss>0) printf("%lld",sum);
//		else printf("%lld",sum-anss+anss*c);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B	Bought Review
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int T;
//int a[10],p[10];
//signed main() {
//	scanf("%lld",&T);
//	while(T-- ) {
//		int sum=0,cnt=0,ans=0;
//		for(int i=1; i<=5; i++) scanf("%lld",&a[i]),sum+=a[i]*i,cnt+=a[i];
//		for(int i=1; i<=5; i++) scanf("%lld",&p[i]);
//		double max4=p[4]*1.0,max5=p[5]*1.0/2;
//		int t=3*cnt-sum;
//		if(t<=0) ans=0;
//		else if(max5<max4) {
//			if(t%2==0) ans=t/2*p[5];
//			else ans=min((t/2+1)*p[5],t/2*p[5]+p[4]);
//		} else ans=t*p[4];
//		printf("%lld\n",ans);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//A. Setting up Camp
//#include <bits/stdc++.h>
//#define int long long
//#define maxn (int)(2e5+7)
//using namespace std;
//int T;
//signed main() {
//	scanf("%lld",&T);
//	while(T--) {
//		int a,b,c;
//		scanf("%lld %lld %lld",&a,&b,&c);
//		if(c<(3-b%3)&&b%3!=0)  printf("-1\n");
//		else {
//			if((b+c)%3==0) cout<<a+(b+c)/3<<endl;
//			else cout<<a+(b+c)/3+1<<endl;
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//B. Fireworks
//#include <bits/stdc++.h>
//#define int long long
//#define maxn (int)(1e5+7)
//using namespace std;
//int T;
//signed main() {
//	scanf("%lld",&T);
//	while(T--) {
//		int a,b,m;
//		scanf("%lld %lld %lld",&a,&b,&m);
//		cout<<m/a+m/b+2<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//C. Left and Right Houses
//#include <bits/stdc++.h>
//#define int long long
//#define maxn (int)(4e5+7)
//using namespace std;
//int T;
//vector<int> x;
//int a[maxn];
//signed main() {
//    cin>>T;
//    while(T--) {
//        int n;
//        string s;
//        cin>>n>>s;
//        int ans0=0,ans1=0;
//        x.clear();
//        for(int i=0; i<s.size(); i++) a[i+1]=s[i]-'0';
//        for(int i=1; i<=n; i++) {
//            if(a[i]==0) ans0++;
//            else ans1++;
//        }
//        int xx=-1,y=0;
//        for(int i=0; i<=n; i++) {
//            if(a[i]==0) xx++;
//            else y++;
//            if(xx*2>=i&&(ans1-y)*2>=n-i) x.push_back(i);
//        }
//        double ans=1e9;
//        int ansi=0;
//        for(int i=0; i<x.size(); i++) {
//            if(fabs(1.0*n/2.0-1.0*x[i])<ans){
//                ans=fabs(1.0*n/2.0-1.0*x[i]);
//                ansi=x[i];
//            }
//        }
//        cout<<ansi<<endl;
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//D. Seraphim the Owl
//#include <bits/stdc++.h>
//#define int long long
//#define maxn (int)(2e5+7)
//using namespace std;
//int T;
//struct aa {
//	int a,b;
//} P[maxn];
//int sum[maxn];
//signed main() {
//	scanf("%lld",&T);
//	while(T--) {
//		int n,m;
//		scanf("%lld %lld",&n,&m);
//		memset(sum,0,sizeof(sum));
//		for(int i=1; i<=n; i++) scanf("%lld",&P[i].a);
//		for(int i=1; i<=n; i++) scanf("%lld",&P[i].b);
//		for(int i=1; i<=m; i++) sum[i]=sum[i-1]+P[i].b;
//		int ans=0,las=0;
//		for(int i=m+1; i<=n; i++) ans+=min(P[i].a,P[i].b);
//		int cnt=1e9;
//		for(int i=m;i>=1;i--) {
//			cnt=min(cnt,P[i].a+sum[m]-sum[i]);
//		}
//		cout<<ans+cnt<<endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//AT_arc158_c [ARC158C] All Pair Digit Sums
//#include<bits/stdc++.h>
//#define int long long
//#define maxn 200005
//using namespace std;
//int n,mod=1,x,ans;
//int p[20][maxn];
//signed main(){
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++) {
//		scanf("%lld",&x); mod=10;
//		for(int k=1;k<=16;k++) p[k][i]=x%mod,mod*=10;
//		while(x) ans+=n*2*(x%10),x/=10;
//	} mod=1;
//	for(int i=1;i<=16;i++) {
//		mod*=10;
//		sort(p[i]+1,p[i]+1+n);
//		for(int j=1;j<=n;j++) ans-=9*(p[i]+n+1-lower_bound(p[i]+1,p[i]+n+1,mod-p[i][j]));
//	}
//	printf("%lld",ans);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
