#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct A{
    int z,j,s;
}a[100002];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].z,&a[i].j,&a[i].s);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i].z==0){
            ans+=a[i].j;
            for(int k=i;k<=n;k++){
                if(a[k].z==1&&a[k].s-a[i].s<=45&&a[k].j<=a[i].j){
                    a[k].z=3;
                    break;
                }
                else if(a[k].s-a[i].s>45) break;
            }
        }
        else if(a[i].z==1) ans+=a[i].j;
    }
    cout<<ans;
    return 0;
}
