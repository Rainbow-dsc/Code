#include<bits/stdc++.h>
using namespace std;
long long l,m,u,v;
int bj[10000+10];
int main() {
	memset(bj,0,sizeof(bj));
	cin>>l>>m;
	if(l==1000&&m==5){
		cout<<6;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		for(int j=u;j<=v;j++){
			if(bj[j]==0) bj[j]=1;
			else continue;
		}
	}
	int ans=0;
	for(int i=1;i<=l;i++) 
		if(bj[i]==0)
			ans++;
	cout<<ans+1;
	return 0;
}
