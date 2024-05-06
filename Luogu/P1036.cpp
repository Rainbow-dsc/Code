#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[10001],ans;
bool isprime(int a){
    for(int i=2;i*i<=a;i++) if(a%i==0) return false;
    return true;
}
void dfs(int m, int sum, int startx){
    if(m==k){
        if(isprime(sum)) ans++;
        return ;
    }
    for(int i=startx;i<n;i++) dfs(m+1,sum+a[i],i+1);
    return ;
}
signed main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    dfs(0,0,0);
    printf("%d",ans);
    return 0;
}
