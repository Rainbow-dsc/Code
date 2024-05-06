#include<bits/stdc++.h>
//#define int long long
#define maxn 100005
using namespace std;
signed main(){
    int t; cin>>t;
    while (t--) {
        int n,l;string s;vector<int> v;
        cin>>n>>l>>s;
        for (int i=0;i<l;++i) if(int(s[i]-'0')&1) v.emplace_back(i);
        int t=0; if(v.size()>1) t=v[1]-v[0]-1;
        for (int i=2; i<v.size(); ++i) if (v[i]-v[i-1]-1!=t) { t=-1;break; }
        if (t==-1||t>n) { puts("No"); continue; }
        if (v.empty()) puts(l<=n?"Yes":"No");
        else puts(v.front()<=t&&l-v.back()<=t?"Yes":"No");
    } return 0;
}
