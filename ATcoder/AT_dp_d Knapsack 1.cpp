#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,w[1001],c[1001];
int f[1001][1000];
signed main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++) cin>>w[i]>>c[i];
    for(int i=1;i<=m;i++)
        for(int j=n;j>=0;j--){
            if(j>=w[i])f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+c[i]);
            else f[i][j]=f[i-1][j];
        }
    cout<<f[m][n];
    return 0;
}
