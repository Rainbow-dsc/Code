#include<bits/stdc++.h>
#define for1(i,a,b) for( int i=(a);i<=(b);i++)
#define for2(i,a,b) for( int i=(a);i<(b);i++)
#define for3(i,a,b) for( int i=(a);i>=(b);i--)
#define for4(i,a,b) for( int i=(a);i>(b);i--)
#define puba push_back
#define mem(a,b) memset((a),(b),sizeof((a)))
#define int long long
using namespace std;
int n,a[200005],b[200005],vis[500005],cnt,tot;
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for1(i,1,n){
        cin>>a[i];
        vis[a[i]]++;
    }
    sort(a+1,a+n+1);
    cnt=unique(a+1,a+n+1)-a-1;
    for1(i,1,cnt){
        int ans=0;
        for(int j=a[i];j<=500000;j+=a[i]) ans+=vis[j];
        ans--;
        ans*=vis[a[i]];
        tot+=ans;
    }
    cout<<tot<<endl;
    return 0;
}