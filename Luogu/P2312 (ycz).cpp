#include<bits/stdc++.h>
#define int long long
#define maxn 105
#define mod 1000000007
using namespace std;
int n,m,a[maxn];
vector<int> ans;
int read(){
    int sum=0,fg=1;
    char c=getchar();
    while(c < '0' || c > '9'){
        if(c=='-') fg=-1;
        c=getchar();
    }
    while(c >='0' && c <='9'){
        sum=((sum*10)+c-'0')%mod;
        c=getchar();
    }
    return sum*fg;
}
bool solve(int x){
    int sum=0;
    for(int i=n+1;i>=1;i--) sum=(sum*x+a[i])%mod;
    return sum==0;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n+1;i++) a[i]=read();
    for(int i=1;i<=m;i++) if(solve(i)) ans.push_back(i);
    cout<<ans.size()<<endl;
    for(int u:ans) cout<<u<<endl;
    return 0;
}
