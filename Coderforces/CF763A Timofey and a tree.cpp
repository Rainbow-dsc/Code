#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,c[maxn],num[maxn],sum;
int a[maxn],b[maxn];
bool flag=false;
signed main() {
	cin>>n;
	for(int i=1; i<n; i++) scanf("%lld %lld",&a[i],&b[i]);
	for(int i=1; i<=n; i++) scanf("%lld",&c[i]);
	for(int i=1; i<n; i++) if(c[a[i]]!=c[b[i]]) sum++,num[a[i]]++,num[b[i]]++;
	for(int i=1; i<=n&&flag==false; i++) if(sum==num[i])  printf("YES\n%lld\n",i),flag=true;
	if(!flag) puts("NO");
	return 0;
}
