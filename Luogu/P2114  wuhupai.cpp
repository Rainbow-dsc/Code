#include <bits/stdc++.h>
using namespace std;
long long n,m,op[100005],t[100005],num[40],cnt=0;
bool ans[40];
string y;
long long solve(long long x){
	for(long long i=1;i<=n;i++){
		if(op[i]==0) x=x&t[i];
		else if(op[i]==1) 	x=x^t[i];
		else x=x|t[i];
	}
	return x;
}
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>y>>t[i];
		if(y=="AND") op[i]=0;
		else if(y=="XOR") op[i]=1;
		else op[i]=2;
	}
	while(m){
		cnt++;
		num[cnt]=m%2;
		m/=2;
	}
	bool top=true;
	for(long long i=cnt;i>=1;i--){
		if(top==true){
			if(num[i]==1){
				long long g1=solve(1<<(i-1)),g2=solve(0);
				g1=g1&(1<<(i-1)),g2=g2&(1<<(i-1));
				if(g1>g2) ans[i]=true;
				else top=false,ans[i]=false;
			}else ans[i]=false;
		}else{
			long long g1=solve(1<<(i-1)),g2=solve(0);
			g1=g1&(1<<(i-1)),g2=g2&(1<<(i-1));
			if(g1>g2)ans[i]=true;
			else ans[i]=false;
		}
	}
	long long tot=0;
	for(long long i=1;i<=cnt;i++)if(ans[i]==1)tot+=(1<<(i-1));
	cout<<solve(tot)<<endl;
	return 0;
}
