#include<bits/stdc++.h>
using namespace std;
int n,a[2000],w,t,s,ans,kkk;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        w+=a[i];
    }
    for(int i=1;i<=w;i++){
        t=0,s=0,ans=0;
        for(int j=1;j<=n;j++){
            t=j,s=0;
            while(t<=n&&s<i){
                s+=a[t];
                t++;
            }
            if(s==i){
                ans++;
                j=t-1;
            }
        }
        kkk=max(kkk,ans);
    }
    printf("%d\n",kkk);
    return 0;
}
