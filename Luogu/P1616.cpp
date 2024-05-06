#include <bits/stdc++.h>
using namespace std;
const int maxm=10010,maxt=10000010;
long long v[maxm],t[maxm],f[maxt];
int main(){
    int T,m;
    cin>>T>>m;
    for(int i=1;i<=m;i++) cin>>t[i]>>v[i];
    for(int i=1;i<=m;i++)
        for(int j=t[i];j<=T;j++)
            f[j]=max(f[j],f[j-t[i]]+v[i]);
    cout<<f[T];
}
