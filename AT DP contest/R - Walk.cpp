#include<bits/stdc++.h>
#define int long long
#define maxn 55
#define mod (int)(1e9+7)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int n,k;
int a[maxn][maxn];
vector<int> P[maxn];
signed main(){
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%lld",&a[i][j]);
            if(a[i][j]==1) P[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) 
    }
    return 0;
}