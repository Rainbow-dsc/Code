#include <bits/stdc++.h>
#define int long long
#define maxn (int)(4e5+7)
using namespace std;
int T;
vector<int> x;
int a[maxn];
signed main() {
    cin>>T;
    while(T--) {
        int n;
        string s;
        cin>>n>>s;
        int ans0=0,ans1=0;
        x.clear();
        for(int i=0; i<s.size(); i++) a[i+1]=s[i]-'0';
        for(int i=1; i<=n; i++) {
            if(a[i]==0) ans0++;
            else ans1++;
        }
        int xx=-1,y=0;
        for(int i=0; i<=n; i++) {
            if(a[i]==0) xx++;
            else y++;
            if(xx*2>=i&&(ans1-y)*2>=n-i) x.push_back(i);
        }
        double ans=1e9;
        int ansi=0;
        for(int i=0; i<x.size(); i++) {
            if(fabs(1.0*n/2.0-1.0*x[i])<ans){
                ans=fabs(1.0*n/2.0-1.0*x[i]);
                ansi=x[i];
            }
        }
        cout<<ansi<<endl;
    }
    return 0;
}
