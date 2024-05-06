#include<bits/stdc++.h>
#define maxn 1000010
#define ll long long
using namespace std;
ll a[maxn],n=1,dp1[maxn],dp2[maxn],len1,len2;
int main(){
	while(cin>>a[n]) n++;
	n--,len1=1,len2=1;
	dp1[1]=a[1],dp2[1]=a[1];
	for(ll i=2;i<=n;i++){
		if(a[i]<=dp1[len1]) dp1[++len1]=a[i];
		else{
			ll k1=upper_bound(dp1+1,dp1+len1+1,a[i],greater<ll>())-dp1;
			dp1[k1]=a[i]; 
		}
		if(a[i]>dp2[len2]){
			dp2[++len2]=a[i];
		}
		else{
			ll k2=lower_bound(dp2+1,dp2+len2+1,a[i])-dp2;
			dp2[k2]=a[i];
		}
	}
	cout<<len1<<endl<<len2;
	return 0;
}
