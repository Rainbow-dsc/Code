#include<bits/stdc++.h>
#define int long long
#define maxn 105
using namespace std;
string s1,s2;
int n;
int a[maxn],b[maxn];
bool check(int *num,int len) {
    for(int i=1;i<=len;i++) {
        if(num[i]!=1&&num[i]&&num[i]!=8) return 0;
        if(num[i]!=num[len-i+1]) return 0;
    }
    return 1;
}
int cnt[10]={1,2,2,2,2,2,2,2,3,3};
int f[maxn],g[maxn];
int solve(int *num,int len) {
    bool flag=0;
    int ans=0,mid=(len+1)/2;
    for(int i=1;i<=mid;i++) {
        int lim=num[i];
        // printf("num[i]: %lld\n",num[i]);
        if(lim>0) {
            if(i>1) ans+=cnt[lim-1]*f[mid-i];
            else ans+=(cnt[lim-1]-1)*f[mid-i];
        }
        if(num[i]!=0&&num[i]!=1&&num[i]!=8) { flag=1;break;}
        if(num[i]>num[len-i+1]) flag=1;
        if(num[i]<num[len-i+1]) flag=0;
    }
    if(!flag) ans++;
    for(int i=1;i<=len;i++) ans+=g[(len-i+1)/2];
    return ans;
}
signed main(){
    scanf("%lld",&n);
    f[0]=g[0]=1;
    for(int i=1;i<=25;i++) f[i]=3*f[i-1],g[i]=2*f[i-1];
    while(n--) {
        cin>>s1>>s2;
        int sum1=0,sum2=0;
        int len1=s1.size(),len2=s2.size();
        for(int i=0;i<len1;i++) if(i>0||s1[i]!='0') a[++sum1]=s1[i]-'0';
        for(int i=0;i<len2;i++) if(i>0||s2[i]!='0') b[++sum2]=s2[i]-'0';
        printf("%lld\n",solve(b,sum2)+check(a,sum1)-solve(a,sum1));    
    }
    return 0;
}