#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n;
const int mod=1e9+7;
signed main(){
	scanf("%lld",&n);
	int ans=0;
	if(n%2==1) ans=n-2;
	else ans=n-1;
	printf("%lld",n+ans+(n+1)/2); 
	return 0;
}

