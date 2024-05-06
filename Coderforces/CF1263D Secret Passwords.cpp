#include<bits/stdc++.h>
#define maxn 1005
#define int long long
using namespace std;
int n;
int fa[maxn];
int vis[maxn];
string s;
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main(){
	scanf("%lld",&n);
	for(int k=1;k<=n;k++) {
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(fa[s[i]-'a'+1]==0) fa[s[i]-'a'+1]=s[i]-'a'+1;
			if(i!=0) fa[find(s[i]-'a'+1)]=find(s[i-1]-'a'+1);
		}
	}
	int ans=0;
	for(int i=1;i<=26;i++) 
		if(fa[i]==i) 
			ans++;
	cout<<ans;
	return 0;
}

