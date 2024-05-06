#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int k;
bool flag=false;
signed main(){
	scanf("%lld",&k);
	for(int i=100;i<=999;i++) {
		int bw=i/100,sw=i%100/10,gw=i%10;
		if((bw*10+sw)%k==0&&(sw*10+gw)%k==0&&i%k==0) flag=true,cout<<i<<endl;   
	}
	if(!flag) cout<<"None!";
	return 0;
}

