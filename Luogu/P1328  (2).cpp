#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int s[102];
int v[102];
signed main() {
    cin>>n>>m;
    for(int i=0;i<26;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        char k;
        cin>>k;
        v[k-'A']++;
    }
    int maxn=-1;
    for(int i=1;i<=m;i++){
        string u;
        int num[30],flag=0;
        memset(num,0,sizeof(num));
        cin>>u;
        int ans=0;
        for(int i=0;i<u.size();i++){
            num[u[i]-'A']++;
            ans+=s[u[i]-'A'];
        }
        for(int i=0;i<26;i++){
            if(num[i]>v[i]){
                flag=1;
                break;
            }
        }
        if(flag==0) maxn=max(ans,maxn);
    }
    cout<<maxn;
    return 0;
}
