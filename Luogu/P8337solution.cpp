#include<bits/stdc++.h>
using namespace std;
int n,a[2000],w,k,t,p,ans,lyx;
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        w+=a[i];
    }
    for(int i=1; i<=w; i++) {
        t=0,p=0,ans=0;
        for(int j=1; j<=n; j++) {
            t=j,p=0;
            while(t<=n&&p<i) {
                p+=a[t];
                t++;
            }
            if(p==i) {
                ans++;
                j=t-1;
            }
        }
        lyx=max(lyx,ans);
    }
    printf("%d",lyx);
}
