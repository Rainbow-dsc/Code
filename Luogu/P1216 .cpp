#include<bits/stdc++.h>
#define itn int
#define el endl
using namespace std;
int f[1010][1010],arr[1010][1010];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(itn j=1;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(itn j=1;j<=i;j++){
            f[i][j]=max(f[i-1][j],f[i-1][j-1])+arr[i][j];
        }
    }
    itn maxx=INT_MIN;
    for(itn i=1;i<=n;i++){
        maxx=max(maxx,f[n][i]);
    }
    cout<<maxx;
    return 0;
}
