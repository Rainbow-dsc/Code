#include<bits/stdc++.h>
using namespace std;
int n,m,ans=INT_MIN;
int arr[205][205],sum[205][205];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&arr[i][j]);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
    }  
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=i;k++)
                for(int p=1;p<=j;p++)
                    ans=max(ans,sum[i][j]-sum[i][p-1]-sum[k-1][j]+sum[k-1][p-1]);
    printf("%d\n",ans);
    return 0;
}
