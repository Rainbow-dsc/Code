#include<bits/stdc++.h>
using namespace std;
int t,n,a[42],s1[22],s2[22],l1,l2,sum[42];
bool dfs(int l,int now){
    if(now>l) return 1;
    if(l1<=n/2&&(l1<l2&&a[now]==s2[l1]||l1>=l2)){
        s1[l1++]=a[now];
        if(dfs(l,now+1)) return 1;
        l1--;
    }
    if(l2<=n/2&&(l1>l2&&a[now]==s1[l2]||l2>=l1)){
        s2[l2++]=a[now];
        if(dfs(l,now+1)) return 1;
        l2--;
    }
    return 0;
}
signed main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        l1=l2=1;
        int u=dfs(n,1);
        if(u==1) cout<<"Good job!! "<<endl;
        else cout<<"What a pity!"<<endl;
    }
    return 0;
}
