#include<bits/stdc++.h>
using namespace std;
int n,q,w[505],v[505],f[505][505],be[505];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&w[i],&be[i],&v[i]);
    for(int i=1;i<=n;i++){
        for(int j=500;j>=w[i];j--){
            for(int k=500;k>=0;k--){
                if(be[i]>=k) f[j][k]=max(f[j][k],f[j-w[i]][0]+v[i]);
                else if(f[j-w[i]][k-be[i]]) f[j][k]=max(f[j][k],f[j-w[i]][k-be[i]]+v[i]);

            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",f[x][y]);
    }
    return 0;
}
