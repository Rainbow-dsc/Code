#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,nd[100005],hv[100005],ans,ad=100000000;
bool check(int x){
    int ndk=0;
    for(int i=0;i<n;i++){
        if(nd[i]*x<=hv[i]) continue;
        ndk+=nd[i]*x-hv[i];
        if(ndk>k) return 0;
    }
    return 1;
}
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++) scanf("%lld",&nd[i]);
    for(int i=0;i<n;i++) scanf("%lld",&hv[i]);
    while(ad>0){
        ans+=ad;
        if(!check(ans)){
            ans-=ad;
            ad/=10;
        }
    }
    printf("%lld",ans);
    return 0;
}
