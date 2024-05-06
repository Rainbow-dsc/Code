#include<bits/stdc++.h>
using namespace std;
int n,m,f[50001][501];
int main() {
    f[0][0]=1;
    scanf("%d%d",&n,&m);
    for(register int i=0; i<=n; i++) {
        for(register int j=0; j<m; j++) {
            for(register int k=1; k<=9; k++) {
                f[i+k][(j*10+k)%m]+=f[i][j];
                f[i+k][(j*10+k)%m]%=1000000007;
            }
        }
    }
    printf("%d\n",f[n][0]);
    return 0;
}
