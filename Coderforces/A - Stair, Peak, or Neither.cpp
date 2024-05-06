#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
signed main(){
    cin>>T;
    while(T--) {
        int a,b,c;
        cin>>a>>b>>c;
        if(a<b&&b<c) cout<<"STAIR"<<endl;
        else if(a<b&&b>c) cout<<"PEAK"<<endl;
        else cout<<"NONE"<<endl;
    }
    return 0;
}