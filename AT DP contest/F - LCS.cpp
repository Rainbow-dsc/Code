#include<bits/stdc++.h>
#define int long long
#define maxn 3005
using namespace std;
char s1[maxn],s2[maxn],ans[maxn];
int dp[maxn][maxn];
signed main(){
    scanf("%s%s", s1+1, s2+1);
	int len1=strlen(s1+1), len2=strlen(s2+1);
    for(int i=1;i<=len1;i++) {
        for(int j=1;j<=len2;j++) {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s1[i]==s2[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    } 
    int i=len1,j=len2;  
    while(dp[i][j]>0) {
        if(s1[i]==s2[j]) ans[dp[i][j]]=s1[i],i--,j--;
        else {
            if(dp[i][j]==dp[i-1][j]) i--;
            else j--;
        }
    }
    printf("%s",ans+1);
    return 0;
}