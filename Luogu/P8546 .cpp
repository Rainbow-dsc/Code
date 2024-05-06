#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool martix[1005][1005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%1d",&martix[i][j]);
    for(int t=2;t<=n;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(martix[i][j]){
                    bool f=true;
                    int l=i,r=i+t-1;
                    for(int x=j;x<=j+t-1;x++){
                        if(martix[l][x]!=1||martix[r][x]!=1){
                            f=false;
                            break;
                        }
                        l++,r--;
                    }
                    if(f) ans++;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
